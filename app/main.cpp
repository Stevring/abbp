
// #include <emscripten.h>
#include <sys/stat.h>

#include "hevc_parser.h"

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Usage: parser <filename>\n");
    exit(0);
  }
  // EM_ASM(FS.mount(NODEFS, {root : "~/Downloads"}, '/hevc_files'););
  printf("opening file %s\n", argv[1]);
  struct stat s;
  int ret_code = stat(argv[1], &s);
  if (ret_code != 0) {
    printf("invalid file, ret %d\n", ret_code);
    exit(0);
  }
  std::shared_ptr<uint8_t> byte_stream(
      static_cast<uint8_t *>(malloc(s.st_size)), free);
  FILE *f = fopen(argv[1], "r");
  fread(byte_stream.get(), s.st_size, 1, f);
  fclose(f);
  auto parser = parser::hevc::Parser(
      reinterpret_cast<intptr_t>(byte_stream.get()), s.st_size);
  parser.parse();
  printf("NAL count %ld\n", parser.getNALCount());
}
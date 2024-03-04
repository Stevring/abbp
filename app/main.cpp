
#include "hevc_parser.h"
#include <sys/stat.h>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Usage: parser <path>\n");
    exit(0);
  }
  struct stat s;
  if (stat(argv[1], &s) != 0) {
    printf("invalid file\n");
    exit(0);
  }
  std::shared_ptr<uint8_t> byte_stream =
      std::make_shared<uint8_t>(malloc(s.st_size), free);
  FILE *f = fopen(argv[1], "r");
  fread(byte_stream.get(), s.st_size, 1, f);
  fclose(f);
  auto parser = parser::hevc::Parser(byte_stream, s.st_size);
  parser.parse();
  printf("NAL count %ld\n", parser.getNALCount());
}
#include <emscripten/bind.h>

#include "../hevc_parser.h"

using namespace emscripten;
using namespace parser::hevc;

EMSCRIPTEN_BINDINGS(hevc_parser) {
  class_<Parser>("HEVCParser")
      .constructor<uintptr_t, const size_t>(allow_raw_pointers())
      .function("parse", &Parser::parse);
}
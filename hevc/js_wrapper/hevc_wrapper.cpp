#include <emscripten/bind.h>

#include "../hevc_parser.h"

using namespace emscripten;
using namespace parser::hevc;

EMSCRIPTEN_BINDINGS(hevc_parser) {
  class_<Parser>("HEVCParser")
      .constructor<std::shared_ptr<uint8_t>, const size_t>()
      .function("parse", &Parser::parse);
}
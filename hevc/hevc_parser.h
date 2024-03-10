
#ifndef HEVC_HEVC_PARSER_H
#define HEVC_HEVC_PARSER_H

#include "reader.h"
#include <inttypes.h>
#include <stddef.h>
namespace parser {
namespace hevc {
class Parser {
public:
  // Parser(const char *file_path);
  Parser(intptr_t byte_stream, const size_t size);
  ~Parser();

  bool parse();
  size_t getNALCount();

private:
  common::NALUReader *reader;
  size_t nalu_cnt;
};

} // namespace hevc
} // namespace parser

#endif


#include "hevc_parser.h"
#include "abbp.h"
#include "byte_stream_reader.h"

#include <utility>

namespace parser {
namespace hevc {
Parser::Parser(std::shared_ptr<uint8_t> byte_stream, const size_t size)
    : nalu_cnt(0) { // TODO: maybe js does not support shared_ptr
  auto _reader = new common::ByteStreamReader(byte_stream.get(), size);
  reader = static_cast<common::Reader *>(_reader);
}

Parser::~Parser() { delete reader; }

size_t Parser::getNALCount() { return nalu_cnt; }

bool Parser::parse() {
  std::vector<uint8_t> nal(std::move(reader->getNextNAL()));
  while (nal.size() > 0) {
    ++nalu_cnt;
    nal = std::move(reader->getNextNAL());
  }
  return true;
}
} // namespace hevc
} // namespace parser

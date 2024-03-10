

#include "hevc_parser.h"

#include <utility>

#include "abbp.h"
#include "byte_stream_reader.h"
#include "hevc_nal_unit.h"
#include "vector_subbyte_reader.h"

namespace parser {
namespace hevc {
Parser::Parser(intptr_t byte_stream, const size_t size)
    : nalu_cnt(0) { // TODO: maybe js does not support shared_ptr
  printf("Parser constructed\n");
  auto _reader = new common::ByteStreamReader(
      reinterpret_cast<uint8_t *>(byte_stream), size);
  reader = static_cast<common::NALUReader *>(_reader);
}

Parser::~Parser() { delete reader; }

size_t Parser::getNALCount() { return nalu_cnt; }

bool Parser::parse() {
  std::vector<uint8_t> nal_rb; // nal raw byte
  std::vector<NalUnit> nalus;
  printf("calling parse\n");
  while (!reader->eos()) {
    nal_rb = std::move(reader->getNextNAL());
    ++nalu_cnt;
    if (nalu_cnt % 1000 == 0)
      printf("parse nalu %d\n", nalu_cnt);
    uint64_t delimiter_size = 0;
    if (nal_rb[0] == 0 && nal_rb[1] == 0 && nal_rb[2] == 1) {
      delimiter_size = 24;
    } else {
      delimiter_size = 32;
    }
    auto bit_reader = common::VectorSubByteReader(std::move(nal_rb));
    bit_reader.readBits("", delimiter_size);
    NalUnit nal_unit;
    nal_unit.parse(bit_reader);
    nalus.push_back(std::move(nal_unit));
  }
  printf("finish parse\n");
  return true;
}
} // namespace hevc
} // namespace parser

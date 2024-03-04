
#pragma once

#include <vector>

#include "reader.h"

namespace parser {
namespace common {
class VectorSubByteReader : public BitReader {
 public:
  VectorSubByteReader(std::vector<uint8_t> &&data)
      : data(std::forward<std::vector<uint8_t>>(data)),
        data_rd_pos(0),
        bit_rd_pos(0){};
  VectorSubByteReader() : data_rd_pos(0), bit_rd_pos(0) {}
  void reinit(std::vector<uint8_t> &&data) {
    data = std::forward<std::vector<uint8_t>>(data);
    data_rd_pos = 0;
    bit_rd_pos = 0;
  }
  virtual std::tuple<uint64_t, size_t> readBits(const std::string &symbol_name,
                                                const size_t n) override;

 private:
  std::vector<uint8_t> data;
  uint64_t data_rd_pos;  // which byte are we reading in `data`
  uint64_t bit_rd_pos;   // which bit are we reading in `data[data_rd_pos]`
};
}  // namespace common
}  // namespace parser

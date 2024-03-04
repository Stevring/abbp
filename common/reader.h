

#pragma once

#include <inttypes.h>

#include <string>
#include <tuple>
#include <vector>

namespace parser {
namespace common {
class NALUReader {
 public:
  virtual uint8_t nextByte() = 0;
  virtual std::vector<uint8_t> getNextNAL() = 0;
  // end of service
  virtual bool eos() const = 0;
  virtual ~NALUReader() {}
};

class BitReader {
 public:
  virtual std::tuple<uint64_t, size_t> readBits(const std::string &symbol_name,
                                                const size_t n) = 0;
  virtual ~BitReader() {}
};
}  // namespace common
}  // namespace parser

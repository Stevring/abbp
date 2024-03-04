

#pragma once

#include <inttypes.h>
#include <vector>

namespace parser {
namespace common {
class NALUReader {
public:
  virtual uint8_t nextByte() = 0;
  virtual std::vector<uint8_t> getNextNAL() = 0;
  virtual ~NALUReader() {}
};

class BitReader {
public:
  virtual
};
} // namespace common
} // namespace parser

#include "hevc_nal_unit.h"

namespace parser::hevc {
bool NalUnit::parse(common::BitReader& reader) {
  uint64_t val;
  size_t nbits;
  std::tie(val, nbits) = reader.readBits("forbidden_zero_bit", 1);
  if (val != 0 || nbits != 1) {
    return false;
  }
  std::tie(val, nbits) = reader.readBits("nal_unit_type", 6);
}
}  // namespace parser::hevc
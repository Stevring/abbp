
#include <iostream>

#include "hevc_nal_unit.h"

namespace parser::hevc {
bool NalUnit::parse(common::BitReader &reader) {
  if (!nal_unit_header.parse(reader))
    return false;
  std::cout << nal_unit_header;
  size_t nbits;
  return true;
}
} // namespace parser::hevc
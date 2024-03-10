
#include <iostream>

#include "hevc_nal_unit.h"

namespace parser {
namespace hevc {
bool NalUnit::parse(common::BitReader &reader) {
  if (!nal_unit_header.parse(reader))
    return false;
  size_t nbits;
  return true;
}
} // namespace hevc
} // namespace parser
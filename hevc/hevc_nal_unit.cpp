
#include <iostream>
#include <memory>

#include "hevc_nal_unit.h"
#include "rbsp/video_parameter_set_rbsp.h"

namespace parser {
namespace hevc {
bool NalUnit::parse(common::BitReader &reader) {
  if (!nal_unit_header.parse(reader))
    return false;
  switch (nal_unit_header.nal_unit_type.v()) {
  case NalType::VPS_NUT: {
    auto v = std::make_shared<VideoParameterSetRBSP>();
    v->parse(reader);
    break;
  }
  default:
    break;
  }
  size_t nbits;
  return true;
}
} // namespace hevc
} // namespace parser
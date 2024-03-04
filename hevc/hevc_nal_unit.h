#pragma once

#include <memory>

#include "hevc_nal_unit_header.h"
#include "reader.h"
namespace parser {
namespace hevc {
class NalRBSP {};
class NalUnit {
 public:
  NALUnitHeader nal_unit_header;
  bool parse(common::BitReader &reader);
};
}  // namespace hevc
}  // namespace parser
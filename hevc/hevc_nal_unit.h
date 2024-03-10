#pragma once

#include <memory>

#include "hevc_nal_unit_header.h"
#include "reader.h"
namespace parser {
namespace hevc {
class NalRBSP {};
class NalUnit {
public:
  NalUnitHeader nal_unit_header;
  std::shared_ptr<NalRBSP> rbsp;
  bool parse(common::BitReader &reader);
};
} // namespace hevc
} // namespace parser
#pragma once
#include <inttypes.h>

#include "reader.h"

namespace parser::hevc {
struct NALUnitHeader {
  bool parse(common::BitReader &reader);
  uint8_t nal_unit_type;
  uint8_t nuh_layer_id;
  uint8_t nuh_temporal_id_plus1;
};
}  // namespace parser::hevc
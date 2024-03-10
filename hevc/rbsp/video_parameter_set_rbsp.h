
#pragma once

#include "../hevc_nal_unit.h"

namespace parser {
namespace hevc {
class VideoParameterSetRBSP : public NalRBSP {
public:
  uint8_t vps_video_parameter_set_id;
  bool vps_base_layer_internal_flag;
  bool vps_base_layer_available_flag;
  uint8_t vps_max_layers_minus1;
  uint8_t vps_max_sub_layers_minus1;
  bool vps_temporal_id_nesting_flag;
  uint16_t vps_reserved_0xffff_16bits;
  VideoParameterSetRBSP() = default;
  bool parse(common::BitReader &reader);
};
} // namespace hevc
} // namespace parser
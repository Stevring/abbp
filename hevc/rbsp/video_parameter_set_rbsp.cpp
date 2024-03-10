#include "video_parameter_set_rbsp.h"

namespace parser {
namespace hevc {
bool VideoParameterSetRBSP::parse(common::BitReader &reader) {
  uint64_t val;
  size_t nbits;
  std::tie(val, nbits) = reader.readBits("vps_video_parameter_set_id", 4);
  if (nbits != 4)
    return false;
  vps_video_parameter_set_id = val;
  std::tie(val, nbits) = reader.readBits("vps_base_layer_internal_flag", 1);
  if (nbits != 1)
    return false;
  vps_base_layer_internal_flag = val;
  std::tie(val, nbits) = reader.readBits("vps_base_layer_available_flag", 1);
  if (nbits != 1)
    return false;
  vps_base_layer_available_flag = val;
  std::tie(val, nbits) = reader.readBits("vps_max_layers_minus1", 6);
  if (nbits != 6)
    return false;
  vps_max_layers_minus1 = val;
  std::tie(val, nbits) = reader.readBits("vps_max_sub_layers_minus1", 3);
  if (nbits != 3)
    return false;
  vps_max_sub_layers_minus1 = val;
  std::tie(val, nbits) = reader.readBits("vps_temporal_id_nesting_flag", 1);
  if (nbits != 1)
    return false;
  vps_temporal_id_nesting_flag = val;
  std::tie(val, nbits) = reader.readBits("vps_reserved_0xffff_16bits", 16);
  if (nbits != 16)
    return false;
  vps_reserved_0xffff_16bits = val;
  return true;
}
} // namespace hevc
} // namespace parser
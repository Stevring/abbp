#pragma once

#include <inttypes.h>
#include <iostream>
#include <map>

#include "reader.h"

namespace parser::hevc {
struct NalType {
  enum V : uint8_t {
    TRAIL_N,
    TRAIL_R,
    TSA_N,
    TSA_R,
    STSA_N,
    STSA_R,
    RADL_N,
    RADL_R,
    RASL_N,
    RASL_R,
    RSV_VCL_N10,
    RSV_VCL_N12,
    RSV_VCL_N14,
    RSV_VCL_R11,
    RSV_VCL_R13,
    RSV_VCL_R15,
    BLA_W_LP,
    BLA_W_RADL,
    BLA_N_LP,
    IDR_W_RADL,
    IDR_N_LP,
    CRA_NUT,
    RSV_IRAP_VCL22,
    RSV_IRAP_VCL23,
    RSV_VCL24,
    RSV_VCL25,
    RSV_VCL26,
    RSV_VCL27,
    RSV_VCL28,
    RSV_VCL29,
    RSV_VCL30,
    RSV_VCL31,
    VPS_NUT,
    SPS_NUT,
    PPS_NUT,
    AUD_NUT,
    EOS_NUT,
    EOB_NUT,
    FD_NUT,
    PREFIX_SEI_NUT,
    SUFFIX_SEI_NUT,
    RSV_NVCL41,
    RSV_NVCL42,
    RSV_NVCL43,
    RSV_NVCL44,
    RSV_NVCL45,
    RSV_NVCL46,
    RSV_NVCL47,
    UNSPEC48,
    UNSPEC49,
    UNSPEC50,
    UNSPEC51,
    UNSPEC52,
    UNSPEC53,
    UNSPEC54,
    UNSPEC55,
    UNSPEC56,
    UNSPEC57,
    UNSPEC58,
    UNSPEC69,
    UNSPEC60,
    UNSPEC61,
    UNSPEC62,
    UNSPEC63,
    UNSPECIFIED
  };
  NalType() : _v(UNSPECIFIED) {}
  NalType(V v) : _v(v) {}
  NalType(uint8_t u) : _v(static_cast<V>(u)){};
  std::string stringify() const { return _m[_v]; }
  bool operator==(const NalType &t) const { return _v == t._v; }

private:
  V _v;
  static std::unordered_map<NalType::V, std::string> _m;
};

struct NalUnitHeader {
  bool parse(common::BitReader &reader);
  NalType nal_unit_type;
  uint8_t nuh_layer_id;
  uint8_t nuh_temporal_id_plus1;
  friend std::ostream &operator<<(std::ostream &os, const NalUnitHeader &h);
};
} // namespace parser::hevc
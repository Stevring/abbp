#include "hevc_nal_unit_header.h"

// namespace std {
// template <> struct hash<parser::hevc::NalType> {
//   std::size_t operator()(const parser::hevc::NalType &k) const {
//     using std::hash;

//     // Compute individual hash values for first,
//     // second and third and combine them using XOR
//     // and bit shifting:
//     return hash<uint8_t>()(k._v);
//   }
// };

// } // namespace std

namespace parser {
namespace hevc {
std::unordered_map<NalType::V, std::string> NalType::_m = {
    {NalType::TRAIL_N, "TRAIL_N"},
    {NalType::TRAIL_R, "TRAIL_R"},
    {NalType::TSA_N, "TSA_N"},
    {NalType::TSA_R, "TSA_R"},
    {NalType::STSA_N, "STSA_N"},
    {NalType::STSA_R, "STSA_R"},
    {NalType::RADL_N, "RADL_N"},
    {NalType::RADL_R, "RADL_R"},
    {NalType::RASL_N, "RASL_N"},
    {NalType::RASL_R, "RASL_R"},
    {NalType::RSV_VCL_N10, "RSV_VCL_N10"},
    {NalType::RSV_VCL_N12, "RSV_VCL_N12"},
    {NalType::RSV_VCL_N14, "RSV_VCL_N14"},
    {NalType::RSV_VCL_R11, "RSV_VCL_R11"},
    {NalType::RSV_VCL_R13, "RSV_VCL_R13"},
    {NalType::RSV_VCL_R15, "RSV_VCL_R15"},
    {NalType::BLA_W_LP, "BLA_W_LP"},
    {NalType::BLA_W_RADL, "BLA_W_RADL"},
    {NalType::BLA_N_LP, "BLA_N_LP"},
    {NalType::IDR_W_RADL, "IDR_W_RADL"},
    {NalType::IDR_N_LP, "IDR_N_LP"},
    {NalType::CRA_NUT, "CRA_NUT"},
    {NalType::RSV_IRAP_VCL22, "RSV_IRAP_VCL22"},
    {NalType::RSV_IRAP_VCL23, "RSV_IRAP_VCL23"},
    {NalType::RSV_VCL24, "RSV_VCL24"},
    {NalType::RSV_VCL25, "RSV_VCL25"},
    {NalType::RSV_VCL26, "RSV_VCL26"},
    {NalType::RSV_VCL27, "RSV_VCL27"},
    {NalType::RSV_VCL28, "RSV_VCL28"},
    {NalType::RSV_VCL29, "RSV_VCL29"},
    {NalType::RSV_VCL30, "RSV_VCL30"},
    {NalType::RSV_VCL31, "RSV_VCL31"},
    {NalType::VPS_NUT, "VPS_NUT"},
    {NalType::SPS_NUT, "SPS_NUT"},
    {NalType::PPS_NUT, "PPS_NUT"},
    {NalType::AUD_NUT, "AUD_NUT"},
    {NalType::EOS_NUT, "EOS_NUT"},
    {NalType::EOB_NUT, "EOB_NUT"},
    {NalType::FD_NUT, "FD_NUT"},
    {NalType::PREFIX_SEI_NUT, "PREFIX_SEI_NUT"},
    {NalType::SUFFIX_SEI_NUT, "SUFFIX_SEI_NUT"},
    {NalType::RSV_NVCL41, "RSV_NVCL41"},
    {NalType::RSV_NVCL42, "RSV_NVCL42"},
    {NalType::RSV_NVCL43, "RSV_NVCL43"},
    {NalType::RSV_NVCL44, "RSV_NVCL44"},
    {NalType::RSV_NVCL45, "RSV_NVCL45"},
    {NalType::RSV_NVCL46, "RSV_NVCL46"},
    {NalType::RSV_NVCL47, "RSV_NVCL47"},
    {NalType::UNSPEC48, "UNSPEC48"},
    {NalType::UNSPEC49, "UNSPEC49"},
    {NalType::UNSPEC50, "UNSPEC50"},
    {NalType::UNSPEC51, "UNSPEC51"},
    {NalType::UNSPEC52, "UNSPEC52"},
    {NalType::UNSPEC53, "UNSPEC53"},
    {NalType::UNSPEC54, "UNSPEC54"},
    {NalType::UNSPEC55, "UNSPEC55"},
    {NalType::UNSPEC56, "UNSPEC56"},
    {NalType::UNSPEC57, "UNSPEC57"},
    {NalType::UNSPEC58, "UNSPEC58"},
    {NalType::UNSPEC69, "UNSPEC69"},
    {NalType::UNSPEC60, "UNSPEC60"},
    {NalType::UNSPEC61, "UNSPEC61"},
    {NalType::UNSPEC62, "UNSPEC62"},
    {NalType::UNSPEC63, "UNSPEC63"},
    {NalType::UNSPECIFIED, "UNSPECIFIED"},
};

bool NalUnitHeader::parse(common::BitReader &reader) {
  uint64_t val;
  size_t nbits;
  std::tie(val, nbits) = reader.readBits("forbidden_zero_bit", 1);
  if (val != 0 || nbits != 1) {
    return false;
  }
  std::tie(val, nbits) = reader.readBits("nal_unit_type", 6);
  if (nbits != 6) {
    return false;
  }
  this->nal_unit_type = NalType(val);
  std::tie(val, nbits) = reader.readBits("nuh_layer_id", 6);
  if (nbits != 6) {
    return false;
  }
  this->nuh_layer_id = val;
  std::tie(val, nbits) = reader.readBits("nuh_temporal_id_plus1", 3);
  if (nbits != 3) {
    return false;
  }
  this->nuh_temporal_id_plus1 = val;
  return true;
}

std::ostream &operator<<(std::ostream &os,
                         const parser::hevc::NalUnitHeader &h) {
  os << "nal_unit_type: " << h.nal_unit_type.stringify()
     << " nuh_layer_id: " << static_cast<int>(h.nuh_layer_id)
     << " nuh_temporal_id_plus1: " << static_cast<int>(h.nuh_temporal_id_plus1)
     << std::endl;
  return os;
}
} // namespace hevc
} // namespace parser
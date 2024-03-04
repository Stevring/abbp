#include "vector_subbyte_reader.h"

#include <assert.h>

namespace parser {
namespace common {
std::tuple<uint64_t, size_t> VectorSubByteReader::readBits(
    const std::string &symbol_name, const size_t n) {
  uint64_t val = 0;
  size_t n_bits_read = 0;
  size_t n_bits_to_read = n;
  while (n_bits_to_read > 0) {
    if (bit_rd_pos >= 8) {
      // finished this byte, move to next
      bit_rd_pos = 0;
      ++data_rd_pos;
      continue;
    }
    if (data_rd_pos >= data.size()) {
      return std::make_tuple(val, n_bits_read);  // no more data left
    }

    if (n_bits_to_read > (8 - bit_rd_pos)) {
      val = (val << (8 - bit_rd_pos)) |
            (data[data_rd_pos] & ((1 << (8 - bit_rd_pos)) - 1));
      n_bits_to_read -= (8 - bit_rd_pos);
      n_bits_read += (8 - bit_rd_pos);
      bit_rd_pos = 8;  // finished this byte
    } else {
      val = (val << n_bits_to_read) |
            ((data[data_rd_pos] >> (8 - bit_rd_pos - n_bits_to_read)) &
             ((1 << n_bits_to_read) - 1));
      bit_rd_pos += n_bits_to_read;
      n_bits_read += n_bits_to_read;
      n_bits_to_read = 0;
      assert(n_bits_read == n);
    }
  }
  return std::make_tuple(val, n_bits_read);
}

}  // namespace common
}  // namespace parser
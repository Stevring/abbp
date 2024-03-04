
#include "byte_stream_reader.h"

namespace parser {
namespace common {

const static uint32_t START_CODE = 0x000001;
const static size_t START_CODE_LEN = 3;

ByteStreamReader::ByteStreamReader(const uint8_t *byte_stream, size_t size)
    : data(byte_stream), data_size(size), rd_pos(0) {
  seekToFirstNAL();
}

std::vector<uint8_t> ByteStreamReader::getNextNAL() {
  int64_t start_pos = indexOfNextStartCode();
  if (start_pos < 0) {
    rd_pos = data_size;
    return {};
  }
  int64_t offset = 0;
  if (start_pos > 0 && data[start_pos - 1] == 0) {
    --start_pos;  // 0x00_000001
    offset = 1;
  }
  rd_pos = start_pos + START_CODE_LEN + offset;

  int64_t end_pos = indexOfNextStartCode();
  if (end_pos < 0) {
    // out of file
    end_pos = data_size;
  } else {
    if (end_pos > 0 && data[end_pos - 1] == 0) {
      --end_pos;  // 0x00_000001
    }
  }
  rd_pos = end_pos;

  printf("NAL %llx\n", start_pos);
  return std::vector<uint8_t>(data + start_pos, data + end_pos);
}

uint8_t ByteStreamReader::nextByte() { return data[rd_pos++]; }

bool ByteStreamReader::eos() const { return rd_pos >= data_size; }

bool ByteStreamReader::seekToFirstNAL() {
  rd_pos = 0;
  int64_t idx = indexOfNextStartCode();
  if (idx < 0) return false;
  if (idx > 0 && data[idx - 1] == 0) {
    --idx;  // 0x00_000001
  }
  rd_pos = idx;
  return true;
}

int64_t ByteStreamReader::indexOfNextStartCode() const {
  uint32_t val = 0;
  int64_t pos = rd_pos;
  if (pos + 3 > data_size) return -1;
  val = (data[pos] << 8) | (data[pos + 1]);
  pos += 2;
  while (pos < data_size) {
    val = ((val & 0x0000FFFF) << 8) | (data[pos]);
    if (val == START_CODE) return pos - 2;
    ++pos;
  }
  return -1;
}

}  // namespace common
}  // namespace parser
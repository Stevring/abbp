

#pragma once

#include <stddef.h>

#include "reader.h"

namespace parser {
namespace common {
class ByteStreamReader : public NALUReader {
 public:
  ByteStreamReader(const uint8_t *byte_stream, size_t size);
  virtual uint8_t nextByte() override;
  virtual std::vector<uint8_t> getNextNAL() override;
  virtual bool eos() const override;

 private:
  const uint8_t *data;
  const int64_t data_size;
  int64_t rd_pos;
  bool seekToFirstNAL();
  int64_t indexOfNextStartCode() const;
};
}  // namespace common
}  // namespace parser
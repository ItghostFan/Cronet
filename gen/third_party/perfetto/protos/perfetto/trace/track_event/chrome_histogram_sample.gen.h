// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_HISTOGRAM_SAMPLE_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_HISTOGRAM_SAMPLE_PROTO_CPP_H_

#include <stdint.h>
#include <bitset>
#include <vector>
#include <string>
#include <type_traits>

#include "perfetto/protozero/cpp_message_obj.h"
#include "perfetto/protozero/copyable_ptr.h"
#include "perfetto/base/export.h"

namespace perfetto {
namespace protos {
namespace gen {
class ChromeHistogramSample;
class HistogramName;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {

class PERFETTO_EXPORT_COMPONENT ChromeHistogramSample : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kNameHashFieldNumber = 1,
    kNameFieldNumber = 2,
    kSampleFieldNumber = 3,
    kNameIidFieldNumber = 4,
  };

  ChromeHistogramSample();
  ~ChromeHistogramSample() override;
  ChromeHistogramSample(ChromeHistogramSample&&) noexcept;
  ChromeHistogramSample& operator=(ChromeHistogramSample&&);
  ChromeHistogramSample(const ChromeHistogramSample&);
  ChromeHistogramSample& operator=(const ChromeHistogramSample&);
  bool operator==(const ChromeHistogramSample&) const;
  bool operator!=(const ChromeHistogramSample& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_name_hash() const { return _has_field_[1]; }
  uint64_t name_hash() const { return name_hash_; }
  void set_name_hash(uint64_t value) { name_hash_ = value; _has_field_.set(1); }

  bool has_name() const { return _has_field_[2]; }
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; _has_field_.set(2); }

  bool has_sample() const { return _has_field_[3]; }
  int64_t sample() const { return sample_; }
  void set_sample(int64_t value) { sample_ = value; _has_field_.set(3); }

  bool has_name_iid() const { return _has_field_[4]; }
  uint64_t name_iid() const { return name_iid_; }
  void set_name_iid(uint64_t value) { name_iid_ = value; _has_field_.set(4); }

 private:
  uint64_t name_hash_{};
  std::string name_{};
  int64_t sample_{};
  uint64_t name_iid_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<5> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT HistogramName : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kIidFieldNumber = 1,
    kNameFieldNumber = 2,
  };

  HistogramName();
  ~HistogramName() override;
  HistogramName(HistogramName&&) noexcept;
  HistogramName& operator=(HistogramName&&);
  HistogramName(const HistogramName&);
  HistogramName& operator=(const HistogramName&);
  bool operator==(const HistogramName&) const;
  bool operator!=(const HistogramName& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_iid() const { return _has_field_[1]; }
  uint64_t iid() const { return iid_; }
  void set_iid(uint64_t value) { iid_ = value; _has_field_.set(1); }

  bool has_name() const { return _has_field_[2]; }
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; _has_field_.set(2); }

 private:
  uint64_t iid_{};
  std::string name_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<3> _has_field_{};
};

}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_HISTOGRAM_SAMPLE_PROTO_CPP_H_

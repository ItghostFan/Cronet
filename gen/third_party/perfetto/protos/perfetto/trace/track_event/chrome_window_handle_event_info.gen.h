// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_WINDOW_HANDLE_EVENT_INFO_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_WINDOW_HANDLE_EVENT_INFO_PROTO_CPP_H_

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
class ChromeWindowHandleEventInfo;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {

class PERFETTO_EXPORT_COMPONENT ChromeWindowHandleEventInfo : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kDpiFieldNumber = 1,
    kMessageIdFieldNumber = 2,
    kHwndPtrFieldNumber = 3,
  };

  ChromeWindowHandleEventInfo();
  ~ChromeWindowHandleEventInfo() override;
  ChromeWindowHandleEventInfo(ChromeWindowHandleEventInfo&&) noexcept;
  ChromeWindowHandleEventInfo& operator=(ChromeWindowHandleEventInfo&&);
  ChromeWindowHandleEventInfo(const ChromeWindowHandleEventInfo&);
  ChromeWindowHandleEventInfo& operator=(const ChromeWindowHandleEventInfo&);
  bool operator==(const ChromeWindowHandleEventInfo&) const;
  bool operator!=(const ChromeWindowHandleEventInfo& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_dpi() const { return _has_field_[1]; }
  uint32_t dpi() const { return dpi_; }
  void set_dpi(uint32_t value) { dpi_ = value; _has_field_.set(1); }

  bool has_message_id() const { return _has_field_[2]; }
  uint32_t message_id() const { return message_id_; }
  void set_message_id(uint32_t value) { message_id_ = value; _has_field_.set(2); }

  bool has_hwnd_ptr() const { return _has_field_[3]; }
  uint64_t hwnd_ptr() const { return hwnd_ptr_; }
  void set_hwnd_ptr(uint64_t value) { hwnd_ptr_ = value; _has_field_.set(3); }

 private:
  uint32_t dpi_{};
  uint32_t message_id_{};
  uint64_t hwnd_ptr_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<4> _has_field_{};
};

}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_WINDOW_HANDLE_EVENT_INFO_PROTO_CPP_H_
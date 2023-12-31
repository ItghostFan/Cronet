// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_PROTO_CPP_H_

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
class InterceptorConfig;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {

class PERFETTO_EXPORT_COMPONENT InterceptorConfig : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kNameFieldNumber = 1,
    kConsoleConfigFieldNumber = 100,
  };

  InterceptorConfig();
  ~InterceptorConfig() override;
  InterceptorConfig(InterceptorConfig&&) noexcept;
  InterceptorConfig& operator=(InterceptorConfig&&);
  InterceptorConfig(const InterceptorConfig&);
  InterceptorConfig& operator=(const InterceptorConfig&);
  bool operator==(const InterceptorConfig&) const;
  bool operator!=(const InterceptorConfig& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_name() const { return _has_field_[1]; }
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; _has_field_.set(1); }

  const std::string& console_config_raw() const { return console_config_; }
  void set_console_config_raw(const std::string& raw) { console_config_ = raw; _has_field_.set(100); }

 private:
  std::string name_{};
  std::string console_config_;  // [lazy=true]

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<101> _has_field_{};
};

}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_PROTO_CPP_H_

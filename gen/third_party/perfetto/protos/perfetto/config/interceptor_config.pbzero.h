// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_PROTO_H_

#include <stddef.h>
#include <stdint.h>

#include "perfetto/protozero/field_writer.h"
#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/proto_utils.h"

namespace perfetto {
namespace protos {
namespace pbzero {

class ConsoleConfig;

class InterceptorConfig_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/100, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  InterceptorConfig_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit InterceptorConfig_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit InterceptorConfig_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_name() const { return at<1>().valid(); }
  ::protozero::ConstChars name() const { return at<1>().as_string(); }
  bool has_console_config() const { return at<100>().valid(); }
  ::protozero::ConstBytes console_config() const { return at<100>().as_bytes(); }
};

class InterceptorConfig : public ::protozero::Message {
 public:
  using Decoder = InterceptorConfig_Decoder;
  enum : int32_t {
    kNameFieldNumber = 1,
    kConsoleConfigFieldNumber = 100,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.InterceptorConfig"; }


  using FieldMetadata_Name =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      InterceptorConfig>;

  static constexpr FieldMetadata_Name kName{};
  void set_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Name::kFieldId, data, size);
  }
  void set_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Name::kFieldId, chars.data, chars.size);
  }
  void set_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Name::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ConsoleConfig =
    ::protozero::proto_utils::FieldMetadata<
      100,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      ConsoleConfig,
      InterceptorConfig>;

  static constexpr FieldMetadata_ConsoleConfig kConsoleConfig{};
  template <typename T = ConsoleConfig> T* set_console_config() {
    return BeginNestedMessage<T>(100);
  }

  void set_console_config_raw(const std::string& raw) {
    return AppendBytes(100, raw.data(), raw.size());
  }

};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
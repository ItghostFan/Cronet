// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_CHROME_CHROME_CONFIG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_CHROME_CHROME_CONFIG_PROTO_H_

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

namespace perfetto_pbzero_enum_ChromeConfig {
enum ClientPriority : int32_t;
}  // namespace perfetto_pbzero_enum_ChromeConfig
using ChromeConfig_ClientPriority = perfetto_pbzero_enum_ChromeConfig::ClientPriority;

namespace perfetto_pbzero_enum_ChromeConfig {
enum ClientPriority : int32_t {
  UNKNOWN = 0,
  BACKGROUND = 1,
  USER_INITIATED = 2,
};
} // namespace perfetto_pbzero_enum_ChromeConfig
using ChromeConfig_ClientPriority = perfetto_pbzero_enum_ChromeConfig::ClientPriority;


constexpr ChromeConfig_ClientPriority ChromeConfig_ClientPriority_MIN = ChromeConfig_ClientPriority::UNKNOWN;
constexpr ChromeConfig_ClientPriority ChromeConfig_ClientPriority_MAX = ChromeConfig_ClientPriority::USER_INITIATED;


PERFETTO_PROTOZERO_CONSTEXPR14_OR_INLINE
const char* ChromeConfig_ClientPriority_Name(::perfetto::protos::pbzero::ChromeConfig_ClientPriority value) {
  switch (value) {
  case ::perfetto::protos::pbzero::ChromeConfig_ClientPriority::UNKNOWN:
    return "UNKNOWN";

  case ::perfetto::protos::pbzero::ChromeConfig_ClientPriority::BACKGROUND:
    return "BACKGROUND";

  case ::perfetto::protos::pbzero::ChromeConfig_ClientPriority::USER_INITIATED:
    return "USER_INITIATED";
  }
  return "PBZERO_UNKNOWN_ENUM_VALUE";
}

class ChromeConfig_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/5, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  ChromeConfig_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit ChromeConfig_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit ChromeConfig_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_trace_config() const { return at<1>().valid(); }
  ::protozero::ConstChars trace_config() const { return at<1>().as_string(); }
  bool has_privacy_filtering_enabled() const { return at<2>().valid(); }
  bool privacy_filtering_enabled() const { return at<2>().as_bool(); }
  bool has_convert_to_legacy_json() const { return at<3>().valid(); }
  bool convert_to_legacy_json() const { return at<3>().as_bool(); }
  bool has_client_priority() const { return at<4>().valid(); }
  int32_t client_priority() const { return at<4>().as_int32(); }
  bool has_json_agent_label_filter() const { return at<5>().valid(); }
  ::protozero::ConstChars json_agent_label_filter() const { return at<5>().as_string(); }
};

class ChromeConfig : public ::protozero::Message {
 public:
  using Decoder = ChromeConfig_Decoder;
  enum : int32_t {
    kTraceConfigFieldNumber = 1,
    kPrivacyFilteringEnabledFieldNumber = 2,
    kConvertToLegacyJsonFieldNumber = 3,
    kClientPriorityFieldNumber = 4,
    kJsonAgentLabelFilterFieldNumber = 5,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.ChromeConfig"; }


  using ClientPriority = ::perfetto::protos::pbzero::ChromeConfig_ClientPriority;
  static inline const char* ClientPriority_Name(ClientPriority value) {
    return ::perfetto::protos::pbzero::ChromeConfig_ClientPriority_Name(value);
  }
  static inline const ClientPriority UNKNOWN = ClientPriority::UNKNOWN;
  static inline const ClientPriority BACKGROUND = ClientPriority::BACKGROUND;
  static inline const ClientPriority USER_INITIATED = ClientPriority::USER_INITIATED;

  using FieldMetadata_TraceConfig =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      ChromeConfig>;

  static constexpr FieldMetadata_TraceConfig kTraceConfig{};
  void set_trace_config(const char* data, size_t size) {
    AppendBytes(FieldMetadata_TraceConfig::kFieldId, data, size);
  }
  void set_trace_config(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_TraceConfig::kFieldId, chars.data, chars.size);
  }
  void set_trace_config(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_TraceConfig::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_PrivacyFilteringEnabled =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      ChromeConfig>;

  static constexpr FieldMetadata_PrivacyFilteringEnabled kPrivacyFilteringEnabled{};
  void set_privacy_filtering_enabled(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_PrivacyFilteringEnabled::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ConvertToLegacyJson =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      ChromeConfig>;

  static constexpr FieldMetadata_ConvertToLegacyJson kConvertToLegacyJson{};
  void set_convert_to_legacy_json(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_ConvertToLegacyJson::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ClientPriority =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::ChromeConfig_ClientPriority,
      ChromeConfig>;

  static constexpr FieldMetadata_ClientPriority kClientPriority{};
  void set_client_priority(::perfetto::protos::pbzero::ChromeConfig_ClientPriority value) {
    static constexpr uint32_t field_id = FieldMetadata_ClientPriority::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_JsonAgentLabelFilter =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      ChromeConfig>;

  static constexpr FieldMetadata_JsonAgentLabelFilter kJsonAgentLabelFilter{};
  void set_json_agent_label_filter(const char* data, size_t size) {
    AppendBytes(FieldMetadata_JsonAgentLabelFilter::kFieldId, data, size);
  }
  void set_json_agent_label_filter(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_JsonAgentLabelFilter::kFieldId, chars.data, chars.size);
  }
  void set_json_agent_label_filter(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_JsonAgentLabelFilter::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
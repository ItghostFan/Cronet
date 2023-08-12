// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_ANDROID_ANDROID_SYSTEM_PROPERTY_CONFIG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_ANDROID_ANDROID_SYSTEM_PROPERTY_CONFIG_PROTO_H_

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


class AndroidSystemPropertyConfig_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  AndroidSystemPropertyConfig_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit AndroidSystemPropertyConfig_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit AndroidSystemPropertyConfig_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_poll_ms() const { return at<1>().valid(); }
  uint32_t poll_ms() const { return at<1>().as_uint32(); }
  bool has_property_name() const { return at<2>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstChars> property_name() const { return GetRepeated<::protozero::ConstChars>(2); }
};

class AndroidSystemPropertyConfig : public ::protozero::Message {
 public:
  using Decoder = AndroidSystemPropertyConfig_Decoder;
  enum : int32_t {
    kPollMsFieldNumber = 1,
    kPropertyNameFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.AndroidSystemPropertyConfig"; }


  using FieldMetadata_PollMs =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      AndroidSystemPropertyConfig>;

  static constexpr FieldMetadata_PollMs kPollMs{};
  void set_poll_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_PollMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_PropertyName =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      AndroidSystemPropertyConfig>;

  static constexpr FieldMetadata_PropertyName kPropertyName{};
  void add_property_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_PropertyName::kFieldId, data, size);
  }
  void add_property_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_PropertyName::kFieldId, chars.data, chars.size);
  }
  void add_property_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_PropertyName::kFieldId;
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

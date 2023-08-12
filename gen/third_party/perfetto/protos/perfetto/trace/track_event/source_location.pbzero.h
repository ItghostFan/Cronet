// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PROTO_H_

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


class SourceLocation_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/4, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  SourceLocation_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit SourceLocation_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit SourceLocation_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_iid() const { return at<1>().valid(); }
  uint64_t iid() const { return at<1>().as_uint64(); }
  bool has_file_name() const { return at<2>().valid(); }
  ::protozero::ConstChars file_name() const { return at<2>().as_string(); }
  bool has_function_name() const { return at<3>().valid(); }
  ::protozero::ConstChars function_name() const { return at<3>().as_string(); }
  bool has_line_number() const { return at<4>().valid(); }
  uint32_t line_number() const { return at<4>().as_uint32(); }
};

class SourceLocation : public ::protozero::Message {
 public:
  using Decoder = SourceLocation_Decoder;
  enum : int32_t {
    kIidFieldNumber = 1,
    kFileNameFieldNumber = 2,
    kFunctionNameFieldNumber = 3,
    kLineNumberFieldNumber = 4,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.SourceLocation"; }


  using FieldMetadata_Iid =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      SourceLocation>;

  static constexpr FieldMetadata_Iid kIid{};
  void set_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Iid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_FileName =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      SourceLocation>;

  static constexpr FieldMetadata_FileName kFileName{};
  void set_file_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_FileName::kFieldId, data, size);
  }
  void set_file_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_FileName::kFieldId, chars.data, chars.size);
  }
  void set_file_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_FileName::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_FunctionName =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      SourceLocation>;

  static constexpr FieldMetadata_FunctionName kFunctionName{};
  void set_function_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_FunctionName::kFieldId, data, size);
  }
  void set_function_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_FunctionName::kFieldId, chars.data, chars.size);
  }
  void set_function_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_FunctionName::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_LineNumber =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SourceLocation>;

  static constexpr FieldMetadata_LineNumber kLineNumber{};
  void set_line_number(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_LineNumber::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }
};

class UnsymbolizedSourceLocation_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/3, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  UnsymbolizedSourceLocation_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit UnsymbolizedSourceLocation_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit UnsymbolizedSourceLocation_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_iid() const { return at<1>().valid(); }
  uint64_t iid() const { return at<1>().as_uint64(); }
  bool has_mapping_id() const { return at<2>().valid(); }
  uint64_t mapping_id() const { return at<2>().as_uint64(); }
  bool has_rel_pc() const { return at<3>().valid(); }
  uint64_t rel_pc() const { return at<3>().as_uint64(); }
};

class UnsymbolizedSourceLocation : public ::protozero::Message {
 public:
  using Decoder = UnsymbolizedSourceLocation_Decoder;
  enum : int32_t {
    kIidFieldNumber = 1,
    kMappingIdFieldNumber = 2,
    kRelPcFieldNumber = 3,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.UnsymbolizedSourceLocation"; }


  using FieldMetadata_Iid =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      UnsymbolizedSourceLocation>;

  static constexpr FieldMetadata_Iid kIid{};
  void set_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Iid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_MappingId =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      UnsymbolizedSourceLocation>;

  static constexpr FieldMetadata_MappingId kMappingId{};
  void set_mapping_id(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_MappingId::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_RelPc =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      UnsymbolizedSourceLocation>;

  static constexpr FieldMetadata_RelPc kRelPc{};
  void set_rel_pc(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_RelPc::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.

// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_PROCESSOR_METRICS_IMPL_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_PROCESSOR_METRICS_IMPL_PROTO_H_

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

class RepeatedBuilderResult;
class RepeatedBuilderResult_Value;
class SingleBuilderResult;

class SingleBuilderResult_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/3, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  SingleBuilderResult_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit SingleBuilderResult_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit SingleBuilderResult_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_type() const { return at<1>().valid(); }
  uint32_t type() const { return at<1>().as_uint32(); }
  bool has_type_name() const { return at<2>().valid(); }
  ::protozero::ConstChars type_name() const { return at<2>().as_string(); }
  bool has_protobuf() const { return at<3>().valid(); }
  ::protozero::ConstBytes protobuf() const { return at<3>().as_bytes(); }
};

class SingleBuilderResult : public ::protozero::Message {
 public:
  using Decoder = SingleBuilderResult_Decoder;
  enum : int32_t {
    kTypeFieldNumber = 1,
    kTypeNameFieldNumber = 2,
    kProtobufFieldNumber = 3,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.SingleBuilderResult"; }


  using FieldMetadata_Type =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SingleBuilderResult>;

  static constexpr FieldMetadata_Type kType{};
  void set_type(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Type::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TypeName =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      SingleBuilderResult>;

  static constexpr FieldMetadata_TypeName kTypeName{};
  void set_type_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_TypeName::kFieldId, data, size);
  }
  void set_type_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_TypeName::kFieldId, chars.data, chars.size);
  }
  void set_type_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_TypeName::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Protobuf =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBytes,
      std::string,
      SingleBuilderResult>;

  static constexpr FieldMetadata_Protobuf kProtobuf{};
  void set_protobuf(const uint8_t* data, size_t size) {
    AppendBytes(FieldMetadata_Protobuf::kFieldId, data, size);
  }
  void set_protobuf(::protozero::ConstBytes bytes) {
    AppendBytes(FieldMetadata_Protobuf::kFieldId, bytes.data, bytes.size);
  }
  void set_protobuf(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Protobuf::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBytes>
        ::Append(*this, field_id, value);
  }
};

class RepeatedBuilderResult_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/1, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  RepeatedBuilderResult_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit RepeatedBuilderResult_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit RepeatedBuilderResult_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_value() const { return at<1>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> value() const { return GetRepeated<::protozero::ConstBytes>(1); }
};

class RepeatedBuilderResult : public ::protozero::Message {
 public:
  using Decoder = RepeatedBuilderResult_Decoder;
  enum : int32_t {
    kValueFieldNumber = 1,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.RepeatedBuilderResult"; }

  using Value = ::perfetto::protos::pbzero::RepeatedBuilderResult_Value;

  using FieldMetadata_Value =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      RepeatedBuilderResult_Value,
      RepeatedBuilderResult>;

  static constexpr FieldMetadata_Value kValue{};
  template <typename T = RepeatedBuilderResult_Value> T* add_value() {
    return BeginNestedMessage<T>(1);
  }

};

class RepeatedBuilderResult_Value_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/4, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  RepeatedBuilderResult_Value_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit RepeatedBuilderResult_Value_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit RepeatedBuilderResult_Value_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_int_value() const { return at<1>().valid(); }
  int64_t int_value() const { return at<1>().as_int64(); }
  bool has_string_value() const { return at<2>().valid(); }
  ::protozero::ConstChars string_value() const { return at<2>().as_string(); }
  bool has_double_value() const { return at<3>().valid(); }
  double double_value() const { return at<3>().as_double(); }
  bool has_bytes_value() const { return at<4>().valid(); }
  ::protozero::ConstBytes bytes_value() const { return at<4>().as_bytes(); }
};

class RepeatedBuilderResult_Value : public ::protozero::Message {
 public:
  using Decoder = RepeatedBuilderResult_Value_Decoder;
  enum : int32_t {
    kIntValueFieldNumber = 1,
    kStringValueFieldNumber = 2,
    kDoubleValueFieldNumber = 3,
    kBytesValueFieldNumber = 4,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.RepeatedBuilderResult.Value"; }


  using FieldMetadata_IntValue =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      RepeatedBuilderResult_Value>;

  static constexpr FieldMetadata_IntValue kIntValue{};
  void set_int_value(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_IntValue::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_StringValue =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      RepeatedBuilderResult_Value>;

  static constexpr FieldMetadata_StringValue kStringValue{};
  void set_string_value(const char* data, size_t size) {
    AppendBytes(FieldMetadata_StringValue::kFieldId, data, size);
  }
  void set_string_value(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_StringValue::kFieldId, chars.data, chars.size);
  }
  void set_string_value(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_StringValue::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_DoubleValue =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kDouble,
      double,
      RepeatedBuilderResult_Value>;

  static constexpr FieldMetadata_DoubleValue kDoubleValue{};
  void set_double_value(double value) {
    static constexpr uint32_t field_id = FieldMetadata_DoubleValue::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kDouble>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_BytesValue =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBytes,
      std::string,
      RepeatedBuilderResult_Value>;

  static constexpr FieldMetadata_BytesValue kBytesValue{};
  void set_bytes_value(const uint8_t* data, size_t size) {
    AppendBytes(FieldMetadata_BytesValue::kFieldId, data, size);
  }
  void set_bytes_value(::protozero::ConstBytes bytes) {
    AppendBytes(FieldMetadata_BytesValue::kFieldId, bytes.data, bytes.size);
  }
  void set_bytes_value(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_BytesValue::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBytes>
        ::Append(*this, field_id, value);
  }
};

class ProtoBuilderResult_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/3, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  ProtoBuilderResult_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit ProtoBuilderResult_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit ProtoBuilderResult_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_is_repeated() const { return at<1>().valid(); }
  bool is_repeated() const { return at<1>().as_bool(); }
  bool has_single() const { return at<2>().valid(); }
  ::protozero::ConstBytes single() const { return at<2>().as_bytes(); }
  bool has_repeated() const { return at<3>().valid(); }
  ::protozero::ConstBytes repeated() const { return at<3>().as_bytes(); }
};

class ProtoBuilderResult : public ::protozero::Message {
 public:
  using Decoder = ProtoBuilderResult_Decoder;
  enum : int32_t {
    kIsRepeatedFieldNumber = 1,
    kSingleFieldNumber = 2,
    kRepeatedFieldNumber = 3,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.ProtoBuilderResult"; }


  using FieldMetadata_IsRepeated =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      ProtoBuilderResult>;

  static constexpr FieldMetadata_IsRepeated kIsRepeated{};
  void set_is_repeated(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_IsRepeated::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Single =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      SingleBuilderResult,
      ProtoBuilderResult>;

  static constexpr FieldMetadata_Single kSingle{};
  template <typename T = SingleBuilderResult> T* set_single() {
    return BeginNestedMessage<T>(2);
  }


  using FieldMetadata_Repeated =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      RepeatedBuilderResult,
      ProtoBuilderResult>;

  static constexpr FieldMetadata_Repeated kRepeated{};
  template <typename T = RepeatedBuilderResult> T* set_repeated() {
    return BeginNestedMessage<T>(3);
  }

};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
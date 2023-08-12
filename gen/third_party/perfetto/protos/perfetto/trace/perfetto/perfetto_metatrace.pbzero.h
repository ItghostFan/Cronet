// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_PERFETTO_PERFETTO_METATRACE_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_PERFETTO_PERFETTO_METATRACE_PROTO_H_

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

class PerfettoMetatrace_Arg;
class PerfettoMetatrace_InternedString;

class PerfettoMetatrace_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/11, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  PerfettoMetatrace_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit PerfettoMetatrace_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit PerfettoMetatrace_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_event_id() const { return at<1>().valid(); }
  uint32_t event_id() const { return at<1>().as_uint32(); }
  bool has_counter_id() const { return at<2>().valid(); }
  uint32_t counter_id() const { return at<2>().as_uint32(); }
  bool has_event_name() const { return at<8>().valid(); }
  ::protozero::ConstChars event_name() const { return at<8>().as_string(); }
  bool has_event_name_iid() const { return at<11>().valid(); }
  uint64_t event_name_iid() const { return at<11>().as_uint64(); }
  bool has_counter_name() const { return at<9>().valid(); }
  ::protozero::ConstChars counter_name() const { return at<9>().as_string(); }
  bool has_event_duration_ns() const { return at<3>().valid(); }
  uint64_t event_duration_ns() const { return at<3>().as_uint64(); }
  bool has_counter_value() const { return at<4>().valid(); }
  int32_t counter_value() const { return at<4>().as_int32(); }
  bool has_thread_id() const { return at<5>().valid(); }
  uint32_t thread_id() const { return at<5>().as_uint32(); }
  bool has_has_overruns() const { return at<6>().valid(); }
  bool has_overruns() const { return at<6>().as_bool(); }
  bool has_args() const { return at<7>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> args() const { return GetRepeated<::protozero::ConstBytes>(7); }
  bool has_interned_strings() const { return at<10>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> interned_strings() const { return GetRepeated<::protozero::ConstBytes>(10); }
};

class PerfettoMetatrace : public ::protozero::Message {
 public:
  using Decoder = PerfettoMetatrace_Decoder;
  enum : int32_t {
    kEventIdFieldNumber = 1,
    kCounterIdFieldNumber = 2,
    kEventNameFieldNumber = 8,
    kEventNameIidFieldNumber = 11,
    kCounterNameFieldNumber = 9,
    kEventDurationNsFieldNumber = 3,
    kCounterValueFieldNumber = 4,
    kThreadIdFieldNumber = 5,
    kHasOverrunsFieldNumber = 6,
    kArgsFieldNumber = 7,
    kInternedStringsFieldNumber = 10,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.PerfettoMetatrace"; }

  using Arg = ::perfetto::protos::pbzero::PerfettoMetatrace_Arg;
  using InternedString = ::perfetto::protos::pbzero::PerfettoMetatrace_InternedString;

  using FieldMetadata_EventId =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_EventId kEventId{};
  void set_event_id(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_EventId::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_CounterId =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_CounterId kCounterId{};
  void set_counter_id(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_CounterId::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_EventName =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_EventName kEventName{};
  void set_event_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_EventName::kFieldId, data, size);
  }
  void set_event_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_EventName::kFieldId, chars.data, chars.size);
  }
  void set_event_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_EventName::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_EventNameIid =
    ::protozero::proto_utils::FieldMetadata<
      11,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_EventNameIid kEventNameIid{};
  void set_event_name_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_EventNameIid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_CounterName =
    ::protozero::proto_utils::FieldMetadata<
      9,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_CounterName kCounterName{};
  void set_counter_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_CounterName::kFieldId, data, size);
  }
  void set_counter_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_CounterName::kFieldId, chars.data, chars.size);
  }
  void set_counter_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_CounterName::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_EventDurationNs =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_EventDurationNs kEventDurationNs{};
  void set_event_duration_ns(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_EventDurationNs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_CounterValue =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_CounterValue kCounterValue{};
  void set_counter_value(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_CounterValue::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ThreadId =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_ThreadId kThreadId{};
  void set_thread_id(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_ThreadId::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_HasOverruns =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_HasOverruns kHasOverruns{};
  void set_has_overruns(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_HasOverruns::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Args =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      PerfettoMetatrace_Arg,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_Args kArgs{};
  template <typename T = PerfettoMetatrace_Arg> T* add_args() {
    return BeginNestedMessage<T>(7);
  }


  using FieldMetadata_InternedStrings =
    ::protozero::proto_utils::FieldMetadata<
      10,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      PerfettoMetatrace_InternedString,
      PerfettoMetatrace>;

  static constexpr FieldMetadata_InternedStrings kInternedStrings{};
  template <typename T = PerfettoMetatrace_InternedString> T* add_interned_strings() {
    return BeginNestedMessage<T>(10);
  }

};

class PerfettoMetatrace_InternedString_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  PerfettoMetatrace_InternedString_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit PerfettoMetatrace_InternedString_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit PerfettoMetatrace_InternedString_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_iid() const { return at<1>().valid(); }
  uint64_t iid() const { return at<1>().as_uint64(); }
  bool has_value() const { return at<2>().valid(); }
  ::protozero::ConstChars value() const { return at<2>().as_string(); }
};

class PerfettoMetatrace_InternedString : public ::protozero::Message {
 public:
  using Decoder = PerfettoMetatrace_InternedString_Decoder;
  enum : int32_t {
    kIidFieldNumber = 1,
    kValueFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.PerfettoMetatrace.InternedString"; }


  using FieldMetadata_Iid =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      PerfettoMetatrace_InternedString>;

  static constexpr FieldMetadata_Iid kIid{};
  void set_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Iid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Value =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfettoMetatrace_InternedString>;

  static constexpr FieldMetadata_Value kValue{};
  void set_value(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Value::kFieldId, data, size);
  }
  void set_value(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Value::kFieldId, chars.data, chars.size);
  }
  void set_value(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Value::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }
};

class PerfettoMetatrace_Arg_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/4, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  PerfettoMetatrace_Arg_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit PerfettoMetatrace_Arg_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit PerfettoMetatrace_Arg_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_key() const { return at<1>().valid(); }
  ::protozero::ConstChars key() const { return at<1>().as_string(); }
  bool has_key_iid() const { return at<3>().valid(); }
  uint64_t key_iid() const { return at<3>().as_uint64(); }
  bool has_value() const { return at<2>().valid(); }
  ::protozero::ConstChars value() const { return at<2>().as_string(); }
  bool has_value_iid() const { return at<4>().valid(); }
  uint64_t value_iid() const { return at<4>().as_uint64(); }
};

class PerfettoMetatrace_Arg : public ::protozero::Message {
 public:
  using Decoder = PerfettoMetatrace_Arg_Decoder;
  enum : int32_t {
    kKeyFieldNumber = 1,
    kKeyIidFieldNumber = 3,
    kValueFieldNumber = 2,
    kValueIidFieldNumber = 4,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.PerfettoMetatrace.Arg"; }


  using FieldMetadata_Key =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfettoMetatrace_Arg>;

  static constexpr FieldMetadata_Key kKey{};
  void set_key(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Key::kFieldId, data, size);
  }
  void set_key(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Key::kFieldId, chars.data, chars.size);
  }
  void set_key(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Key::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_KeyIid =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      PerfettoMetatrace_Arg>;

  static constexpr FieldMetadata_KeyIid kKeyIid{};
  void set_key_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_KeyIid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Value =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfettoMetatrace_Arg>;

  static constexpr FieldMetadata_Value kValue{};
  void set_value(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Value::kFieldId, data, size);
  }
  void set_value(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Value::kFieldId, chars.data, chars.size);
  }
  void set_value(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Value::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ValueIid =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      PerfettoMetatrace_Arg>;

  static constexpr FieldMetadata_ValueIid kValueIid{};
  void set_value_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_ValueIid::kFieldId;
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

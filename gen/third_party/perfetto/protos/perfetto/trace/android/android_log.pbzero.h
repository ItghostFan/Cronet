// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_ANDROID_ANDROID_LOG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_ANDROID_ANDROID_LOG_PROTO_H_

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

class AndroidLogPacket_LogEvent;
class AndroidLogPacket_LogEvent_Arg;
class AndroidLogPacket_Stats;
enum AndroidLogId : int32_t;
enum AndroidLogPriority : int32_t;

class AndroidLogPacket_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  AndroidLogPacket_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit AndroidLogPacket_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit AndroidLogPacket_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_events() const { return at<1>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> events() const { return GetRepeated<::protozero::ConstBytes>(1); }
  bool has_stats() const { return at<2>().valid(); }
  ::protozero::ConstBytes stats() const { return at<2>().as_bytes(); }
};

class AndroidLogPacket : public ::protozero::Message {
 public:
  using Decoder = AndroidLogPacket_Decoder;
  enum : int32_t {
    kEventsFieldNumber = 1,
    kStatsFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.AndroidLogPacket"; }

  using LogEvent = ::perfetto::protos::pbzero::AndroidLogPacket_LogEvent;
  using Stats = ::perfetto::protos::pbzero::AndroidLogPacket_Stats;

  using FieldMetadata_Events =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      AndroidLogPacket_LogEvent,
      AndroidLogPacket>;

  static constexpr FieldMetadata_Events kEvents{};
  template <typename T = AndroidLogPacket_LogEvent> T* add_events() {
    return BeginNestedMessage<T>(1);
  }


  using FieldMetadata_Stats =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      AndroidLogPacket_Stats,
      AndroidLogPacket>;

  static constexpr FieldMetadata_Stats kStats{};
  template <typename T = AndroidLogPacket_Stats> T* set_stats() {
    return BeginNestedMessage<T>(2);
  }

};

class AndroidLogPacket_Stats_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/3, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  AndroidLogPacket_Stats_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit AndroidLogPacket_Stats_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit AndroidLogPacket_Stats_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_num_total() const { return at<1>().valid(); }
  uint64_t num_total() const { return at<1>().as_uint64(); }
  bool has_num_failed() const { return at<2>().valid(); }
  uint64_t num_failed() const { return at<2>().as_uint64(); }
  bool has_num_skipped() const { return at<3>().valid(); }
  uint64_t num_skipped() const { return at<3>().as_uint64(); }
};

class AndroidLogPacket_Stats : public ::protozero::Message {
 public:
  using Decoder = AndroidLogPacket_Stats_Decoder;
  enum : int32_t {
    kNumTotalFieldNumber = 1,
    kNumFailedFieldNumber = 2,
    kNumSkippedFieldNumber = 3,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.AndroidLogPacket.Stats"; }


  using FieldMetadata_NumTotal =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      AndroidLogPacket_Stats>;

  static constexpr FieldMetadata_NumTotal kNumTotal{};
  void set_num_total(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_NumTotal::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_NumFailed =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      AndroidLogPacket_Stats>;

  static constexpr FieldMetadata_NumFailed kNumFailed{};
  void set_num_failed(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_NumFailed::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_NumSkipped =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      AndroidLogPacket_Stats>;

  static constexpr FieldMetadata_NumSkipped kNumSkipped{};
  void set_num_skipped(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_NumSkipped::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }
};

class AndroidLogPacket_LogEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/9, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  AndroidLogPacket_LogEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit AndroidLogPacket_LogEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit AndroidLogPacket_LogEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_log_id() const { return at<1>().valid(); }
  int32_t log_id() const { return at<1>().as_int32(); }
  bool has_pid() const { return at<2>().valid(); }
  int32_t pid() const { return at<2>().as_int32(); }
  bool has_tid() const { return at<3>().valid(); }
  int32_t tid() const { return at<3>().as_int32(); }
  bool has_uid() const { return at<4>().valid(); }
  int32_t uid() const { return at<4>().as_int32(); }
  bool has_timestamp() const { return at<5>().valid(); }
  uint64_t timestamp() const { return at<5>().as_uint64(); }
  bool has_tag() const { return at<6>().valid(); }
  ::protozero::ConstChars tag() const { return at<6>().as_string(); }
  bool has_prio() const { return at<7>().valid(); }
  int32_t prio() const { return at<7>().as_int32(); }
  bool has_message() const { return at<8>().valid(); }
  ::protozero::ConstChars message() const { return at<8>().as_string(); }
  bool has_args() const { return at<9>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> args() const { return GetRepeated<::protozero::ConstBytes>(9); }
};

class AndroidLogPacket_LogEvent : public ::protozero::Message {
 public:
  using Decoder = AndroidLogPacket_LogEvent_Decoder;
  enum : int32_t {
    kLogIdFieldNumber = 1,
    kPidFieldNumber = 2,
    kTidFieldNumber = 3,
    kUidFieldNumber = 4,
    kTimestampFieldNumber = 5,
    kTagFieldNumber = 6,
    kPrioFieldNumber = 7,
    kMessageFieldNumber = 8,
    kArgsFieldNumber = 9,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.AndroidLogPacket.LogEvent"; }

  using Arg = ::perfetto::protos::pbzero::AndroidLogPacket_LogEvent_Arg;

  using FieldMetadata_LogId =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::AndroidLogId,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_LogId kLogId{};
  void set_log_id(::perfetto::protos::pbzero::AndroidLogId value) {
    static constexpr uint32_t field_id = FieldMetadata_LogId::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Pid =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Pid kPid{};
  void set_pid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Pid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Tid =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Tid kTid{};
  void set_tid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Tid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Uid =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Uid kUid{};
  void set_uid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Uid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Timestamp =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Timestamp kTimestamp{};
  void set_timestamp(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Timestamp::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Tag =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Tag kTag{};
  void set_tag(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Tag::kFieldId, data, size);
  }
  void set_tag(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Tag::kFieldId, chars.data, chars.size);
  }
  void set_tag(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Tag::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Prio =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::AndroidLogPriority,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Prio kPrio{};
  void set_prio(::perfetto::protos::pbzero::AndroidLogPriority value) {
    static constexpr uint32_t field_id = FieldMetadata_Prio::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Message =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Message kMessage{};
  void set_message(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Message::kFieldId, data, size);
  }
  void set_message(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Message::kFieldId, chars.data, chars.size);
  }
  void set_message(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Message::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Args =
    ::protozero::proto_utils::FieldMetadata<
      9,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      AndroidLogPacket_LogEvent_Arg,
      AndroidLogPacket_LogEvent>;

  static constexpr FieldMetadata_Args kArgs{};
  template <typename T = AndroidLogPacket_LogEvent_Arg> T* add_args() {
    return BeginNestedMessage<T>(9);
  }

};

class AndroidLogPacket_LogEvent_Arg_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/4, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  AndroidLogPacket_LogEvent_Arg_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit AndroidLogPacket_LogEvent_Arg_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit AndroidLogPacket_LogEvent_Arg_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_name() const { return at<1>().valid(); }
  ::protozero::ConstChars name() const { return at<1>().as_string(); }
  bool has_int_value() const { return at<2>().valid(); }
  int64_t int_value() const { return at<2>().as_int64(); }
  bool has_float_value() const { return at<3>().valid(); }
  float float_value() const { return at<3>().as_float(); }
  bool has_string_value() const { return at<4>().valid(); }
  ::protozero::ConstChars string_value() const { return at<4>().as_string(); }
};

class AndroidLogPacket_LogEvent_Arg : public ::protozero::Message {
 public:
  using Decoder = AndroidLogPacket_LogEvent_Arg_Decoder;
  enum : int32_t {
    kNameFieldNumber = 1,
    kIntValueFieldNumber = 2,
    kFloatValueFieldNumber = 3,
    kStringValueFieldNumber = 4,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.AndroidLogPacket.LogEvent.Arg"; }


  using FieldMetadata_Name =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      AndroidLogPacket_LogEvent_Arg>;

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

  using FieldMetadata_IntValue =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      AndroidLogPacket_LogEvent_Arg>;

  static constexpr FieldMetadata_IntValue kIntValue{};
  void set_int_value(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_IntValue::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_FloatValue =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kFloat,
      float,
      AndroidLogPacket_LogEvent_Arg>;

  static constexpr FieldMetadata_FloatValue kFloatValue{};
  void set_float_value(float value) {
    static constexpr uint32_t field_id = FieldMetadata_FloatValue::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kFloat>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_StringValue =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      AndroidLogPacket_LogEvent_Arg>;

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
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.

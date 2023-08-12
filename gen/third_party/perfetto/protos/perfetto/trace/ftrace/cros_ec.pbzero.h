// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_CROS_EC_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_CROS_EC_PROTO_H_

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


class CrosEcSensorhubDataFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/6, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  CrosEcSensorhubDataFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit CrosEcSensorhubDataFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit CrosEcSensorhubDataFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_current_time() const { return at<1>().valid(); }
  int64_t current_time() const { return at<1>().as_int64(); }
  bool has_current_timestamp() const { return at<2>().valid(); }
  int64_t current_timestamp() const { return at<2>().as_int64(); }
  bool has_delta() const { return at<3>().valid(); }
  int64_t delta() const { return at<3>().as_int64(); }
  bool has_ec_fifo_timestamp() const { return at<4>().valid(); }
  uint32_t ec_fifo_timestamp() const { return at<4>().as_uint32(); }
  bool has_ec_sensor_num() const { return at<5>().valid(); }
  uint32_t ec_sensor_num() const { return at<5>().as_uint32(); }
  bool has_fifo_timestamp() const { return at<6>().valid(); }
  int64_t fifo_timestamp() const { return at<6>().as_int64(); }
};

class CrosEcSensorhubDataFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = CrosEcSensorhubDataFtraceEvent_Decoder;
  enum : int32_t {
    kCurrentTimeFieldNumber = 1,
    kCurrentTimestampFieldNumber = 2,
    kDeltaFieldNumber = 3,
    kEcFifoTimestampFieldNumber = 4,
    kEcSensorNumFieldNumber = 5,
    kFifoTimestampFieldNumber = 6,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.CrosEcSensorhubDataFtraceEvent"; }


  using FieldMetadata_CurrentTime =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      CrosEcSensorhubDataFtraceEvent>;

  static constexpr FieldMetadata_CurrentTime kCurrentTime{};
  void set_current_time(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_CurrentTime::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_CurrentTimestamp =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      CrosEcSensorhubDataFtraceEvent>;

  static constexpr FieldMetadata_CurrentTimestamp kCurrentTimestamp{};
  void set_current_timestamp(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_CurrentTimestamp::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Delta =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      CrosEcSensorhubDataFtraceEvent>;

  static constexpr FieldMetadata_Delta kDelta{};
  void set_delta(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Delta::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_EcFifoTimestamp =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      CrosEcSensorhubDataFtraceEvent>;

  static constexpr FieldMetadata_EcFifoTimestamp kEcFifoTimestamp{};
  void set_ec_fifo_timestamp(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_EcFifoTimestamp::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_EcSensorNum =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      CrosEcSensorhubDataFtraceEvent>;

  static constexpr FieldMetadata_EcSensorNum kEcSensorNum{};
  void set_ec_sensor_num(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_EcSensorNum::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_FifoTimestamp =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      CrosEcSensorhubDataFtraceEvent>;

  static constexpr FieldMetadata_FifoTimestamp kFifoTimestamp{};
  void set_fifo_timestamp(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_FifoTimestamp::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.

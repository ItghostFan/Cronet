// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_GPU_GPU_COUNTER_CONFIG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_GPU_GPU_COUNTER_CONFIG_PROTO_H_

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


class GpuCounterConfig_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/4, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  GpuCounterConfig_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit GpuCounterConfig_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit GpuCounterConfig_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_counter_period_ns() const { return at<1>().valid(); }
  uint64_t counter_period_ns() const { return at<1>().as_uint64(); }
  bool has_counter_ids() const { return at<2>().valid(); }
  ::protozero::RepeatedFieldIterator<uint32_t> counter_ids() const { return GetRepeated<uint32_t>(2); }
  bool has_instrumented_sampling() const { return at<3>().valid(); }
  bool instrumented_sampling() const { return at<3>().as_bool(); }
  bool has_fix_gpu_clock() const { return at<4>().valid(); }
  bool fix_gpu_clock() const { return at<4>().as_bool(); }
};

class GpuCounterConfig : public ::protozero::Message {
 public:
  using Decoder = GpuCounterConfig_Decoder;
  enum : int32_t {
    kCounterPeriodNsFieldNumber = 1,
    kCounterIdsFieldNumber = 2,
    kInstrumentedSamplingFieldNumber = 3,
    kFixGpuClockFieldNumber = 4,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.GpuCounterConfig"; }


  using FieldMetadata_CounterPeriodNs =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      GpuCounterConfig>;

  static constexpr FieldMetadata_CounterPeriodNs kCounterPeriodNs{};
  void set_counter_period_ns(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_CounterPeriodNs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_CounterIds =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      GpuCounterConfig>;

  static constexpr FieldMetadata_CounterIds kCounterIds{};
  void add_counter_ids(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_CounterIds::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_InstrumentedSampling =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      GpuCounterConfig>;

  static constexpr FieldMetadata_InstrumentedSampling kInstrumentedSampling{};
  void set_instrumented_sampling(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_InstrumentedSampling::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_FixGpuClock =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      GpuCounterConfig>;

  static constexpr FieldMetadata_FixGpuClock kFixGpuClock{};
  void set_fix_gpu_clock(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_FixGpuClock::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.

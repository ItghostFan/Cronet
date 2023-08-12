// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_GPU_SCHEDULER_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_GPU_SCHEDULER_PROTO_H_

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


class DrmSchedProcessJobFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/1, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  DrmSchedProcessJobFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit DrmSchedProcessJobFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit DrmSchedProcessJobFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_fence() const { return at<1>().valid(); }
  uint64_t fence() const { return at<1>().as_uint64(); }
};

class DrmSchedProcessJobFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = DrmSchedProcessJobFtraceEvent_Decoder;
  enum : int32_t {
    kFenceFieldNumber = 1,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.DrmSchedProcessJobFtraceEvent"; }


  using FieldMetadata_Fence =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DrmSchedProcessJobFtraceEvent>;

  static constexpr FieldMetadata_Fence kFence{};
  void set_fence(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Fence::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }
};

class DrmRunJobFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/6, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  DrmRunJobFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit DrmRunJobFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit DrmRunJobFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_entity() const { return at<1>().valid(); }
  uint64_t entity() const { return at<1>().as_uint64(); }
  bool has_fence() const { return at<2>().valid(); }
  uint64_t fence() const { return at<2>().as_uint64(); }
  bool has_hw_job_count() const { return at<3>().valid(); }
  int32_t hw_job_count() const { return at<3>().as_int32(); }
  bool has_id() const { return at<4>().valid(); }
  uint64_t id() const { return at<4>().as_uint64(); }
  bool has_job_count() const { return at<5>().valid(); }
  uint32_t job_count() const { return at<5>().as_uint32(); }
  bool has_name() const { return at<6>().valid(); }
  ::protozero::ConstChars name() const { return at<6>().as_string(); }
};

class DrmRunJobFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = DrmRunJobFtraceEvent_Decoder;
  enum : int32_t {
    kEntityFieldNumber = 1,
    kFenceFieldNumber = 2,
    kHwJobCountFieldNumber = 3,
    kIdFieldNumber = 4,
    kJobCountFieldNumber = 5,
    kNameFieldNumber = 6,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.DrmRunJobFtraceEvent"; }


  using FieldMetadata_Entity =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DrmRunJobFtraceEvent>;

  static constexpr FieldMetadata_Entity kEntity{};
  void set_entity(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Entity::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Fence =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DrmRunJobFtraceEvent>;

  static constexpr FieldMetadata_Fence kFence{};
  void set_fence(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Fence::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_HwJobCount =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      DrmRunJobFtraceEvent>;

  static constexpr FieldMetadata_HwJobCount kHwJobCount{};
  void set_hw_job_count(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_HwJobCount::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Id =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DrmRunJobFtraceEvent>;

  static constexpr FieldMetadata_Id kId{};
  void set_id(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Id::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_JobCount =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      DrmRunJobFtraceEvent>;

  static constexpr FieldMetadata_JobCount kJobCount{};
  void set_job_count(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_JobCount::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Name =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      DrmRunJobFtraceEvent>;

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
};

class DrmSchedJobFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/6, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  DrmSchedJobFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit DrmSchedJobFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit DrmSchedJobFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_entity() const { return at<1>().valid(); }
  uint64_t entity() const { return at<1>().as_uint64(); }
  bool has_fence() const { return at<2>().valid(); }
  uint64_t fence() const { return at<2>().as_uint64(); }
  bool has_hw_job_count() const { return at<3>().valid(); }
  int32_t hw_job_count() const { return at<3>().as_int32(); }
  bool has_id() const { return at<4>().valid(); }
  uint64_t id() const { return at<4>().as_uint64(); }
  bool has_job_count() const { return at<5>().valid(); }
  uint32_t job_count() const { return at<5>().as_uint32(); }
  bool has_name() const { return at<6>().valid(); }
  ::protozero::ConstChars name() const { return at<6>().as_string(); }
};

class DrmSchedJobFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = DrmSchedJobFtraceEvent_Decoder;
  enum : int32_t {
    kEntityFieldNumber = 1,
    kFenceFieldNumber = 2,
    kHwJobCountFieldNumber = 3,
    kIdFieldNumber = 4,
    kJobCountFieldNumber = 5,
    kNameFieldNumber = 6,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.DrmSchedJobFtraceEvent"; }


  using FieldMetadata_Entity =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DrmSchedJobFtraceEvent>;

  static constexpr FieldMetadata_Entity kEntity{};
  void set_entity(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Entity::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Fence =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DrmSchedJobFtraceEvent>;

  static constexpr FieldMetadata_Fence kFence{};
  void set_fence(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Fence::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_HwJobCount =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      DrmSchedJobFtraceEvent>;

  static constexpr FieldMetadata_HwJobCount kHwJobCount{};
  void set_hw_job_count(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_HwJobCount::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Id =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DrmSchedJobFtraceEvent>;

  static constexpr FieldMetadata_Id kId{};
  void set_id(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Id::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_JobCount =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      DrmSchedJobFtraceEvent>;

  static constexpr FieldMetadata_JobCount kJobCount{};
  void set_job_count(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_JobCount::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Name =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      DrmSchedJobFtraceEvent>;

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
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
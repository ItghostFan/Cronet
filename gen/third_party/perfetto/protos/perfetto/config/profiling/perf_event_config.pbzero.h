// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_PROFILING_PERF_EVENT_CONFIG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_PROFILING_PERF_EVENT_CONFIG_PROTO_H_

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

class PerfEventConfig_CallstackSampling;
class PerfEventConfig_Scope;
class PerfEvents_Timebase;
namespace perfetto_pbzero_enum_PerfEventConfig {
enum UnwindMode : int32_t;
}  // namespace perfetto_pbzero_enum_PerfEventConfig
using PerfEventConfig_UnwindMode = perfetto_pbzero_enum_PerfEventConfig::UnwindMode;

namespace perfetto_pbzero_enum_PerfEventConfig {
enum UnwindMode : int32_t {
  UNWIND_UNKNOWN = 0,
  UNWIND_SKIP = 1,
  UNWIND_DWARF = 2,
};
} // namespace perfetto_pbzero_enum_PerfEventConfig
using PerfEventConfig_UnwindMode = perfetto_pbzero_enum_PerfEventConfig::UnwindMode;


constexpr PerfEventConfig_UnwindMode PerfEventConfig_UnwindMode_MIN = PerfEventConfig_UnwindMode::UNWIND_UNKNOWN;
constexpr PerfEventConfig_UnwindMode PerfEventConfig_UnwindMode_MAX = PerfEventConfig_UnwindMode::UNWIND_DWARF;


PERFETTO_PROTOZERO_CONSTEXPR14_OR_INLINE
const char* PerfEventConfig_UnwindMode_Name(::perfetto::protos::pbzero::PerfEventConfig_UnwindMode value) {
  switch (value) {
  case ::perfetto::protos::pbzero::PerfEventConfig_UnwindMode::UNWIND_UNKNOWN:
    return "UNWIND_UNKNOWN";

  case ::perfetto::protos::pbzero::PerfEventConfig_UnwindMode::UNWIND_SKIP:
    return "UNWIND_SKIP";

  case ::perfetto::protos::pbzero::PerfEventConfig_UnwindMode::UNWIND_DWARF:
    return "UNWIND_DWARF";
  }
  return "PBZERO_UNKNOWN_ENUM_VALUE";
}

class PerfEventConfig_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/18, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  PerfEventConfig_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit PerfEventConfig_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit PerfEventConfig_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_timebase() const { return at<15>().valid(); }
  ::protozero::ConstBytes timebase() const { return at<15>().as_bytes(); }
  bool has_callstack_sampling() const { return at<16>().valid(); }
  ::protozero::ConstBytes callstack_sampling() const { return at<16>().as_bytes(); }
  bool has_ring_buffer_read_period_ms() const { return at<8>().valid(); }
  uint32_t ring_buffer_read_period_ms() const { return at<8>().as_uint32(); }
  bool has_ring_buffer_pages() const { return at<3>().valid(); }
  uint32_t ring_buffer_pages() const { return at<3>().as_uint32(); }
  bool has_max_enqueued_footprint_kb() const { return at<17>().valid(); }
  uint64_t max_enqueued_footprint_kb() const { return at<17>().as_uint64(); }
  bool has_max_daemon_memory_kb() const { return at<13>().valid(); }
  uint32_t max_daemon_memory_kb() const { return at<13>().as_uint32(); }
  bool has_remote_descriptor_timeout_ms() const { return at<9>().valid(); }
  uint32_t remote_descriptor_timeout_ms() const { return at<9>().as_uint32(); }
  bool has_unwind_state_clear_period_ms() const { return at<10>().valid(); }
  uint32_t unwind_state_clear_period_ms() const { return at<10>().as_uint32(); }
  bool has_target_installed_by() const { return at<18>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstChars> target_installed_by() const { return GetRepeated<::protozero::ConstChars>(18); }
  bool has_all_cpus() const { return at<1>().valid(); }
  bool all_cpus() const { return at<1>().as_bool(); }
  bool has_sampling_frequency() const { return at<2>().valid(); }
  uint32_t sampling_frequency() const { return at<2>().as_uint32(); }
  bool has_kernel_frames() const { return at<12>().valid(); }
  bool kernel_frames() const { return at<12>().as_bool(); }
  bool has_target_pid() const { return at<4>().valid(); }
  ::protozero::RepeatedFieldIterator<int32_t> target_pid() const { return GetRepeated<int32_t>(4); }
  bool has_target_cmdline() const { return at<5>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstChars> target_cmdline() const { return GetRepeated<::protozero::ConstChars>(5); }
  bool has_exclude_pid() const { return at<6>().valid(); }
  ::protozero::RepeatedFieldIterator<int32_t> exclude_pid() const { return GetRepeated<int32_t>(6); }
  bool has_exclude_cmdline() const { return at<7>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstChars> exclude_cmdline() const { return GetRepeated<::protozero::ConstChars>(7); }
  bool has_additional_cmdline_count() const { return at<11>().valid(); }
  uint32_t additional_cmdline_count() const { return at<11>().as_uint32(); }
};

class PerfEventConfig : public ::protozero::Message {
 public:
  using Decoder = PerfEventConfig_Decoder;
  enum : int32_t {
    kTimebaseFieldNumber = 15,
    kCallstackSamplingFieldNumber = 16,
    kRingBufferReadPeriodMsFieldNumber = 8,
    kRingBufferPagesFieldNumber = 3,
    kMaxEnqueuedFootprintKbFieldNumber = 17,
    kMaxDaemonMemoryKbFieldNumber = 13,
    kRemoteDescriptorTimeoutMsFieldNumber = 9,
    kUnwindStateClearPeriodMsFieldNumber = 10,
    kTargetInstalledByFieldNumber = 18,
    kAllCpusFieldNumber = 1,
    kSamplingFrequencyFieldNumber = 2,
    kKernelFramesFieldNumber = 12,
    kTargetPidFieldNumber = 4,
    kTargetCmdlineFieldNumber = 5,
    kExcludePidFieldNumber = 6,
    kExcludeCmdlineFieldNumber = 7,
    kAdditionalCmdlineCountFieldNumber = 11,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.PerfEventConfig"; }

  using CallstackSampling = ::perfetto::protos::pbzero::PerfEventConfig_CallstackSampling;
  using Scope = ::perfetto::protos::pbzero::PerfEventConfig_Scope;

  using UnwindMode = ::perfetto::protos::pbzero::PerfEventConfig_UnwindMode;
  static inline const char* UnwindMode_Name(UnwindMode value) {
    return ::perfetto::protos::pbzero::PerfEventConfig_UnwindMode_Name(value);
  }
  static inline const UnwindMode UNWIND_UNKNOWN = UnwindMode::UNWIND_UNKNOWN;
  static inline const UnwindMode UNWIND_SKIP = UnwindMode::UNWIND_SKIP;
  static inline const UnwindMode UNWIND_DWARF = UnwindMode::UNWIND_DWARF;

  using FieldMetadata_Timebase =
    ::protozero::proto_utils::FieldMetadata<
      15,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      PerfEvents_Timebase,
      PerfEventConfig>;

  static constexpr FieldMetadata_Timebase kTimebase{};
  template <typename T = PerfEvents_Timebase> T* set_timebase() {
    return BeginNestedMessage<T>(15);
  }


  using FieldMetadata_CallstackSampling =
    ::protozero::proto_utils::FieldMetadata<
      16,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      PerfEventConfig_CallstackSampling,
      PerfEventConfig>;

  static constexpr FieldMetadata_CallstackSampling kCallstackSampling{};
  template <typename T = PerfEventConfig_CallstackSampling> T* set_callstack_sampling() {
    return BeginNestedMessage<T>(16);
  }


  using FieldMetadata_RingBufferReadPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_RingBufferReadPeriodMs kRingBufferReadPeriodMs{};
  void set_ring_buffer_read_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_RingBufferReadPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_RingBufferPages =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_RingBufferPages kRingBufferPages{};
  void set_ring_buffer_pages(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_RingBufferPages::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_MaxEnqueuedFootprintKb =
    ::protozero::proto_utils::FieldMetadata<
      17,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_MaxEnqueuedFootprintKb kMaxEnqueuedFootprintKb{};
  void set_max_enqueued_footprint_kb(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_MaxEnqueuedFootprintKb::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_MaxDaemonMemoryKb =
    ::protozero::proto_utils::FieldMetadata<
      13,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_MaxDaemonMemoryKb kMaxDaemonMemoryKb{};
  void set_max_daemon_memory_kb(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_MaxDaemonMemoryKb::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_RemoteDescriptorTimeoutMs =
    ::protozero::proto_utils::FieldMetadata<
      9,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_RemoteDescriptorTimeoutMs kRemoteDescriptorTimeoutMs{};
  void set_remote_descriptor_timeout_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_RemoteDescriptorTimeoutMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_UnwindStateClearPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      10,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_UnwindStateClearPeriodMs kUnwindStateClearPeriodMs{};
  void set_unwind_state_clear_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_UnwindStateClearPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TargetInstalledBy =
    ::protozero::proto_utils::FieldMetadata<
      18,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfEventConfig>;

  static constexpr FieldMetadata_TargetInstalledBy kTargetInstalledBy{};
  void add_target_installed_by(const char* data, size_t size) {
    AppendBytes(FieldMetadata_TargetInstalledBy::kFieldId, data, size);
  }
  void add_target_installed_by(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_TargetInstalledBy::kFieldId, chars.data, chars.size);
  }
  void add_target_installed_by(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_TargetInstalledBy::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_AllCpus =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      PerfEventConfig>;

  static constexpr FieldMetadata_AllCpus kAllCpus{};
  void set_all_cpus(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_AllCpus::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_SamplingFrequency =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_SamplingFrequency kSamplingFrequency{};
  void set_sampling_frequency(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_SamplingFrequency::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_KernelFrames =
    ::protozero::proto_utils::FieldMetadata<
      12,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      PerfEventConfig>;

  static constexpr FieldMetadata_KernelFrames kKernelFrames{};
  void set_kernel_frames(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_KernelFrames::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TargetPid =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_TargetPid kTargetPid{};
  void add_target_pid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TargetPid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TargetCmdline =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfEventConfig>;

  static constexpr FieldMetadata_TargetCmdline kTargetCmdline{};
  void add_target_cmdline(const char* data, size_t size) {
    AppendBytes(FieldMetadata_TargetCmdline::kFieldId, data, size);
  }
  void add_target_cmdline(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_TargetCmdline::kFieldId, chars.data, chars.size);
  }
  void add_target_cmdline(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_TargetCmdline::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ExcludePid =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_ExcludePid kExcludePid{};
  void add_exclude_pid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_ExcludePid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ExcludeCmdline =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfEventConfig>;

  static constexpr FieldMetadata_ExcludeCmdline kExcludeCmdline{};
  void add_exclude_cmdline(const char* data, size_t size) {
    AppendBytes(FieldMetadata_ExcludeCmdline::kFieldId, data, size);
  }
  void add_exclude_cmdline(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_ExcludeCmdline::kFieldId, chars.data, chars.size);
  }
  void add_exclude_cmdline(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_ExcludeCmdline::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_AdditionalCmdlineCount =
    ::protozero::proto_utils::FieldMetadata<
      11,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig>;

  static constexpr FieldMetadata_AdditionalCmdlineCount kAdditionalCmdlineCount{};
  void set_additional_cmdline_count(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_AdditionalCmdlineCount::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }
};

class PerfEventConfig_Scope_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/6, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  PerfEventConfig_Scope_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit PerfEventConfig_Scope_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit PerfEventConfig_Scope_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_target_pid() const { return at<1>().valid(); }
  ::protozero::RepeatedFieldIterator<int32_t> target_pid() const { return GetRepeated<int32_t>(1); }
  bool has_target_cmdline() const { return at<2>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstChars> target_cmdline() const { return GetRepeated<::protozero::ConstChars>(2); }
  bool has_exclude_pid() const { return at<3>().valid(); }
  ::protozero::RepeatedFieldIterator<int32_t> exclude_pid() const { return GetRepeated<int32_t>(3); }
  bool has_exclude_cmdline() const { return at<4>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstChars> exclude_cmdline() const { return GetRepeated<::protozero::ConstChars>(4); }
  bool has_additional_cmdline_count() const { return at<5>().valid(); }
  uint32_t additional_cmdline_count() const { return at<5>().as_uint32(); }
  bool has_process_shard_count() const { return at<6>().valid(); }
  uint32_t process_shard_count() const { return at<6>().as_uint32(); }
};

class PerfEventConfig_Scope : public ::protozero::Message {
 public:
  using Decoder = PerfEventConfig_Scope_Decoder;
  enum : int32_t {
    kTargetPidFieldNumber = 1,
    kTargetCmdlineFieldNumber = 2,
    kExcludePidFieldNumber = 3,
    kExcludeCmdlineFieldNumber = 4,
    kAdditionalCmdlineCountFieldNumber = 5,
    kProcessShardCountFieldNumber = 6,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.PerfEventConfig.Scope"; }


  using FieldMetadata_TargetPid =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      PerfEventConfig_Scope>;

  static constexpr FieldMetadata_TargetPid kTargetPid{};
  void add_target_pid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TargetPid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TargetCmdline =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfEventConfig_Scope>;

  static constexpr FieldMetadata_TargetCmdline kTargetCmdline{};
  void add_target_cmdline(const char* data, size_t size) {
    AppendBytes(FieldMetadata_TargetCmdline::kFieldId, data, size);
  }
  void add_target_cmdline(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_TargetCmdline::kFieldId, chars.data, chars.size);
  }
  void add_target_cmdline(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_TargetCmdline::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ExcludePid =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      PerfEventConfig_Scope>;

  static constexpr FieldMetadata_ExcludePid kExcludePid{};
  void add_exclude_pid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_ExcludePid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ExcludeCmdline =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      PerfEventConfig_Scope>;

  static constexpr FieldMetadata_ExcludeCmdline kExcludeCmdline{};
  void add_exclude_cmdline(const char* data, size_t size) {
    AppendBytes(FieldMetadata_ExcludeCmdline::kFieldId, data, size);
  }
  void add_exclude_cmdline(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_ExcludeCmdline::kFieldId, chars.data, chars.size);
  }
  void add_exclude_cmdline(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_ExcludeCmdline::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_AdditionalCmdlineCount =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig_Scope>;

  static constexpr FieldMetadata_AdditionalCmdlineCount kAdditionalCmdlineCount{};
  void set_additional_cmdline_count(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_AdditionalCmdlineCount::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ProcessShardCount =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      PerfEventConfig_Scope>;

  static constexpr FieldMetadata_ProcessShardCount kProcessShardCount{};
  void set_process_shard_count(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_ProcessShardCount::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }
};

class PerfEventConfig_CallstackSampling_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/3, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  PerfEventConfig_CallstackSampling_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit PerfEventConfig_CallstackSampling_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit PerfEventConfig_CallstackSampling_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_scope() const { return at<1>().valid(); }
  ::protozero::ConstBytes scope() const { return at<1>().as_bytes(); }
  bool has_kernel_frames() const { return at<2>().valid(); }
  bool kernel_frames() const { return at<2>().as_bool(); }
  bool has_user_frames() const { return at<3>().valid(); }
  int32_t user_frames() const { return at<3>().as_int32(); }
};

class PerfEventConfig_CallstackSampling : public ::protozero::Message {
 public:
  using Decoder = PerfEventConfig_CallstackSampling_Decoder;
  enum : int32_t {
    kScopeFieldNumber = 1,
    kKernelFramesFieldNumber = 2,
    kUserFramesFieldNumber = 3,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.PerfEventConfig.CallstackSampling"; }


  using FieldMetadata_Scope =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      PerfEventConfig_Scope,
      PerfEventConfig_CallstackSampling>;

  static constexpr FieldMetadata_Scope kScope{};
  template <typename T = PerfEventConfig_Scope> T* set_scope() {
    return BeginNestedMessage<T>(1);
  }


  using FieldMetadata_KernelFrames =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      PerfEventConfig_CallstackSampling>;

  static constexpr FieldMetadata_KernelFrames kKernelFrames{};
  void set_kernel_frames(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_KernelFrames::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_UserFrames =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::PerfEventConfig_UnwindMode,
      PerfEventConfig_CallstackSampling>;

  static constexpr FieldMetadata_UserFrames kUserFrames{};
  void set_user_frames(::perfetto::protos::pbzero::PerfEventConfig_UnwindMode value) {
    static constexpr uint32_t field_id = FieldMetadata_UserFrames::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.

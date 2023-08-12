// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_SYS_STATS_SYS_STATS_CONFIG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_SYS_STATS_SYS_STATS_CONFIG_PROTO_H_

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

enum MeminfoCounters : int32_t;
namespace perfetto_pbzero_enum_SysStatsConfig {
enum StatCounters : int32_t;
}  // namespace perfetto_pbzero_enum_SysStatsConfig
using SysStatsConfig_StatCounters = perfetto_pbzero_enum_SysStatsConfig::StatCounters;
enum VmstatCounters : int32_t;

namespace perfetto_pbzero_enum_SysStatsConfig {
enum StatCounters : int32_t {
  STAT_UNSPECIFIED = 0,
  STAT_CPU_TIMES = 1,
  STAT_IRQ_COUNTS = 2,
  STAT_SOFTIRQ_COUNTS = 3,
  STAT_FORK_COUNT = 4,
};
} // namespace perfetto_pbzero_enum_SysStatsConfig
using SysStatsConfig_StatCounters = perfetto_pbzero_enum_SysStatsConfig::StatCounters;


constexpr SysStatsConfig_StatCounters SysStatsConfig_StatCounters_MIN = SysStatsConfig_StatCounters::STAT_UNSPECIFIED;
constexpr SysStatsConfig_StatCounters SysStatsConfig_StatCounters_MAX = SysStatsConfig_StatCounters::STAT_FORK_COUNT;


PERFETTO_PROTOZERO_CONSTEXPR14_OR_INLINE
const char* SysStatsConfig_StatCounters_Name(::perfetto::protos::pbzero::SysStatsConfig_StatCounters value) {
  switch (value) {
  case ::perfetto::protos::pbzero::SysStatsConfig_StatCounters::STAT_UNSPECIFIED:
    return "STAT_UNSPECIFIED";

  case ::perfetto::protos::pbzero::SysStatsConfig_StatCounters::STAT_CPU_TIMES:
    return "STAT_CPU_TIMES";

  case ::perfetto::protos::pbzero::SysStatsConfig_StatCounters::STAT_IRQ_COUNTS:
    return "STAT_IRQ_COUNTS";

  case ::perfetto::protos::pbzero::SysStatsConfig_StatCounters::STAT_SOFTIRQ_COUNTS:
    return "STAT_SOFTIRQ_COUNTS";

  case ::perfetto::protos::pbzero::SysStatsConfig_StatCounters::STAT_FORK_COUNT:
    return "STAT_FORK_COUNT";
  }
  return "PBZERO_UNKNOWN_ENUM_VALUE";
}

class SysStatsConfig_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/10, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  SysStatsConfig_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit SysStatsConfig_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit SysStatsConfig_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_meminfo_period_ms() const { return at<1>().valid(); }
  uint32_t meminfo_period_ms() const { return at<1>().as_uint32(); }
  bool has_meminfo_counters() const { return at<2>().valid(); }
  ::protozero::RepeatedFieldIterator<int32_t> meminfo_counters() const { return GetRepeated<int32_t>(2); }
  bool has_vmstat_period_ms() const { return at<3>().valid(); }
  uint32_t vmstat_period_ms() const { return at<3>().as_uint32(); }
  bool has_vmstat_counters() const { return at<4>().valid(); }
  ::protozero::RepeatedFieldIterator<int32_t> vmstat_counters() const { return GetRepeated<int32_t>(4); }
  bool has_stat_period_ms() const { return at<5>().valid(); }
  uint32_t stat_period_ms() const { return at<5>().as_uint32(); }
  bool has_stat_counters() const { return at<6>().valid(); }
  ::protozero::RepeatedFieldIterator<int32_t> stat_counters() const { return GetRepeated<int32_t>(6); }
  bool has_devfreq_period_ms() const { return at<7>().valid(); }
  uint32_t devfreq_period_ms() const { return at<7>().as_uint32(); }
  bool has_cpufreq_period_ms() const { return at<8>().valid(); }
  uint32_t cpufreq_period_ms() const { return at<8>().as_uint32(); }
  bool has_buddyinfo_period_ms() const { return at<9>().valid(); }
  uint32_t buddyinfo_period_ms() const { return at<9>().as_uint32(); }
  bool has_diskstat_period_ms() const { return at<10>().valid(); }
  uint32_t diskstat_period_ms() const { return at<10>().as_uint32(); }
};

class SysStatsConfig : public ::protozero::Message {
 public:
  using Decoder = SysStatsConfig_Decoder;
  enum : int32_t {
    kMeminfoPeriodMsFieldNumber = 1,
    kMeminfoCountersFieldNumber = 2,
    kVmstatPeriodMsFieldNumber = 3,
    kVmstatCountersFieldNumber = 4,
    kStatPeriodMsFieldNumber = 5,
    kStatCountersFieldNumber = 6,
    kDevfreqPeriodMsFieldNumber = 7,
    kCpufreqPeriodMsFieldNumber = 8,
    kBuddyinfoPeriodMsFieldNumber = 9,
    kDiskstatPeriodMsFieldNumber = 10,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.SysStatsConfig"; }


  using StatCounters = ::perfetto::protos::pbzero::SysStatsConfig_StatCounters;
  static inline const char* StatCounters_Name(StatCounters value) {
    return ::perfetto::protos::pbzero::SysStatsConfig_StatCounters_Name(value);
  }
  static inline const StatCounters STAT_UNSPECIFIED = StatCounters::STAT_UNSPECIFIED;
  static inline const StatCounters STAT_CPU_TIMES = StatCounters::STAT_CPU_TIMES;
  static inline const StatCounters STAT_IRQ_COUNTS = StatCounters::STAT_IRQ_COUNTS;
  static inline const StatCounters STAT_SOFTIRQ_COUNTS = StatCounters::STAT_SOFTIRQ_COUNTS;
  static inline const StatCounters STAT_FORK_COUNT = StatCounters::STAT_FORK_COUNT;

  using FieldMetadata_MeminfoPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SysStatsConfig>;

  static constexpr FieldMetadata_MeminfoPeriodMs kMeminfoPeriodMs{};
  void set_meminfo_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_MeminfoPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_MeminfoCounters =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::MeminfoCounters,
      SysStatsConfig>;

  static constexpr FieldMetadata_MeminfoCounters kMeminfoCounters{};
  void add_meminfo_counters(::perfetto::protos::pbzero::MeminfoCounters value) {
    static constexpr uint32_t field_id = FieldMetadata_MeminfoCounters::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_VmstatPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SysStatsConfig>;

  static constexpr FieldMetadata_VmstatPeriodMs kVmstatPeriodMs{};
  void set_vmstat_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_VmstatPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_VmstatCounters =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::VmstatCounters,
      SysStatsConfig>;

  static constexpr FieldMetadata_VmstatCounters kVmstatCounters{};
  void add_vmstat_counters(::perfetto::protos::pbzero::VmstatCounters value) {
    static constexpr uint32_t field_id = FieldMetadata_VmstatCounters::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_StatPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SysStatsConfig>;

  static constexpr FieldMetadata_StatPeriodMs kStatPeriodMs{};
  void set_stat_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_StatPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_StatCounters =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::SysStatsConfig_StatCounters,
      SysStatsConfig>;

  static constexpr FieldMetadata_StatCounters kStatCounters{};
  void add_stat_counters(::perfetto::protos::pbzero::SysStatsConfig_StatCounters value) {
    static constexpr uint32_t field_id = FieldMetadata_StatCounters::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_DevfreqPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SysStatsConfig>;

  static constexpr FieldMetadata_DevfreqPeriodMs kDevfreqPeriodMs{};
  void set_devfreq_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_DevfreqPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_CpufreqPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SysStatsConfig>;

  static constexpr FieldMetadata_CpufreqPeriodMs kCpufreqPeriodMs{};
  void set_cpufreq_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_CpufreqPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_BuddyinfoPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      9,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SysStatsConfig>;

  static constexpr FieldMetadata_BuddyinfoPeriodMs kBuddyinfoPeriodMs{};
  void set_buddyinfo_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_BuddyinfoPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_DiskstatPeriodMs =
    ::protozero::proto_utils::FieldMetadata<
      10,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      SysStatsConfig>;

  static constexpr FieldMetadata_DiskstatPeriodMs kDiskstatPeriodMs{};
  void set_diskstat_period_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_DiskstatPeriodMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.

#include "perfetto/protozero/gen_field_helpers.h"
#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/scattered_heap_buffer.h"
// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif
#include "protos/perfetto/config/sys_stats/sys_stats_config.gen.h"
#include "protos/perfetto/common/sys_stats_counters.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

SysStatsConfig::SysStatsConfig() = default;
SysStatsConfig::~SysStatsConfig() = default;
SysStatsConfig::SysStatsConfig(const SysStatsConfig&) = default;
SysStatsConfig& SysStatsConfig::operator=(const SysStatsConfig&) = default;
SysStatsConfig::SysStatsConfig(SysStatsConfig&&) noexcept = default;
SysStatsConfig& SysStatsConfig::operator=(SysStatsConfig&&) = default;

bool SysStatsConfig::operator==(const SysStatsConfig& other) const {
  return unknown_fields_ == other.unknown_fields_
   && meminfo_period_ms_ == other.meminfo_period_ms_
   && meminfo_counters_ == other.meminfo_counters_
   && vmstat_period_ms_ == other.vmstat_period_ms_
   && vmstat_counters_ == other.vmstat_counters_
   && stat_period_ms_ == other.stat_period_ms_
   && stat_counters_ == other.stat_counters_
   && devfreq_period_ms_ == other.devfreq_period_ms_
   && cpufreq_period_ms_ == other.cpufreq_period_ms_
   && buddyinfo_period_ms_ == other.buddyinfo_period_ms_
   && diskstat_period_ms_ == other.diskstat_period_ms_;
}

bool SysStatsConfig::ParseFromArray(const void* raw, size_t size) {
  meminfo_counters_.clear();
  vmstat_counters_.clear();
  stat_counters_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* meminfo_period_ms */:
        field.get(&meminfo_period_ms_);
        break;
      case 2 /* meminfo_counters */:
        meminfo_counters_.emplace_back();
        field.get(&meminfo_counters_.back());
        break;
      case 3 /* vmstat_period_ms */:
        field.get(&vmstat_period_ms_);
        break;
      case 4 /* vmstat_counters */:
        vmstat_counters_.emplace_back();
        field.get(&vmstat_counters_.back());
        break;
      case 5 /* stat_period_ms */:
        field.get(&stat_period_ms_);
        break;
      case 6 /* stat_counters */:
        stat_counters_.emplace_back();
        field.get(&stat_counters_.back());
        break;
      case 7 /* devfreq_period_ms */:
        field.get(&devfreq_period_ms_);
        break;
      case 8 /* cpufreq_period_ms */:
        field.get(&cpufreq_period_ms_);
        break;
      case 9 /* buddyinfo_period_ms */:
        field.get(&buddyinfo_period_ms_);
        break;
      case 10 /* diskstat_period_ms */:
        field.get(&diskstat_period_ms_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string SysStatsConfig::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> SysStatsConfig::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void SysStatsConfig::Serialize(::protozero::Message* msg) const {
  // Field 1: meminfo_period_ms
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, meminfo_period_ms_, msg);
  }

  // Field 2: meminfo_counters
  for (auto& it : meminfo_counters_) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, it, msg);
  }

  // Field 3: vmstat_period_ms
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(3, vmstat_period_ms_, msg);
  }

  // Field 4: vmstat_counters
  for (auto& it : vmstat_counters_) {
    ::protozero::internal::gen_helpers::SerializeVarInt(4, it, msg);
  }

  // Field 5: stat_period_ms
  if (_has_field_[5]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(5, stat_period_ms_, msg);
  }

  // Field 6: stat_counters
  for (auto& it : stat_counters_) {
    ::protozero::internal::gen_helpers::SerializeVarInt(6, it, msg);
  }

  // Field 7: devfreq_period_ms
  if (_has_field_[7]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(7, devfreq_period_ms_, msg);
  }

  // Field 8: cpufreq_period_ms
  if (_has_field_[8]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(8, cpufreq_period_ms_, msg);
  }

  // Field 9: buddyinfo_period_ms
  if (_has_field_[9]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(9, buddyinfo_period_ms_, msg);
  }

  // Field 10: diskstat_period_ms
  if (_has_field_[10]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(10, diskstat_period_ms_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
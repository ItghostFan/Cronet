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
#include "protos/perfetto/config/process_stats/process_stats_config.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

ProcessStatsConfig::ProcessStatsConfig() = default;
ProcessStatsConfig::~ProcessStatsConfig() = default;
ProcessStatsConfig::ProcessStatsConfig(const ProcessStatsConfig&) = default;
ProcessStatsConfig& ProcessStatsConfig::operator=(const ProcessStatsConfig&) = default;
ProcessStatsConfig::ProcessStatsConfig(ProcessStatsConfig&&) noexcept = default;
ProcessStatsConfig& ProcessStatsConfig::operator=(ProcessStatsConfig&&) = default;

bool ProcessStatsConfig::operator==(const ProcessStatsConfig& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(quirks_, other.quirks_)
   && ::protozero::internal::gen_helpers::EqualsField(scan_all_processes_on_start_, other.scan_all_processes_on_start_)
   && ::protozero::internal::gen_helpers::EqualsField(record_thread_names_, other.record_thread_names_)
   && ::protozero::internal::gen_helpers::EqualsField(proc_stats_poll_ms_, other.proc_stats_poll_ms_)
   && ::protozero::internal::gen_helpers::EqualsField(proc_stats_cache_ttl_ms_, other.proc_stats_cache_ttl_ms_)
   && ::protozero::internal::gen_helpers::EqualsField(resolve_process_fds_, other.resolve_process_fds_)
   && ::protozero::internal::gen_helpers::EqualsField(scan_smaps_rollup_, other.scan_smaps_rollup_);
}

bool ProcessStatsConfig::ParseFromArray(const void* raw, size_t size) {
  quirks_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* quirks */:
        quirks_.emplace_back();
        field.get(&quirks_.back());
        break;
      case 2 /* scan_all_processes_on_start */:
        field.get(&scan_all_processes_on_start_);
        break;
      case 3 /* record_thread_names */:
        field.get(&record_thread_names_);
        break;
      case 4 /* proc_stats_poll_ms */:
        field.get(&proc_stats_poll_ms_);
        break;
      case 6 /* proc_stats_cache_ttl_ms */:
        field.get(&proc_stats_cache_ttl_ms_);
        break;
      case 9 /* resolve_process_fds */:
        field.get(&resolve_process_fds_);
        break;
      case 10 /* scan_smaps_rollup */:
        field.get(&scan_smaps_rollup_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string ProcessStatsConfig::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> ProcessStatsConfig::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void ProcessStatsConfig::Serialize(::protozero::Message* msg) const {
  // Field 1: quirks
  for (auto& it : quirks_) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, it, msg);
  }

  // Field 2: scan_all_processes_on_start
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(2, scan_all_processes_on_start_, msg);
  }

  // Field 3: record_thread_names
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(3, record_thread_names_, msg);
  }

  // Field 4: proc_stats_poll_ms
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(4, proc_stats_poll_ms_, msg);
  }

  // Field 6: proc_stats_cache_ttl_ms
  if (_has_field_[6]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(6, proc_stats_cache_ttl_ms_, msg);
  }

  // Field 9: resolve_process_fds
  if (_has_field_[9]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(9, resolve_process_fds_, msg);
  }

  // Field 10: scan_smaps_rollup
  if (_has_field_[10]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(10, scan_smaps_rollup_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

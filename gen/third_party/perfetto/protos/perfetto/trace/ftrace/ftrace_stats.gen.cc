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
#include "protos/perfetto/trace/ftrace/ftrace_stats.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

FtraceStats::FtraceStats() = default;
FtraceStats::~FtraceStats() = default;
FtraceStats::FtraceStats(const FtraceStats&) = default;
FtraceStats& FtraceStats::operator=(const FtraceStats&) = default;
FtraceStats::FtraceStats(FtraceStats&&) noexcept = default;
FtraceStats& FtraceStats::operator=(FtraceStats&&) = default;

bool FtraceStats::operator==(const FtraceStats& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(phase_, other.phase_)
   && ::protozero::internal::gen_helpers::EqualsField(cpu_stats_, other.cpu_stats_)
   && ::protozero::internal::gen_helpers::EqualsField(kernel_symbols_parsed_, other.kernel_symbols_parsed_)
   && ::protozero::internal::gen_helpers::EqualsField(kernel_symbols_mem_kb_, other.kernel_symbols_mem_kb_)
   && ::protozero::internal::gen_helpers::EqualsField(atrace_errors_, other.atrace_errors_)
   && ::protozero::internal::gen_helpers::EqualsField(unknown_ftrace_events_, other.unknown_ftrace_events_)
   && ::protozero::internal::gen_helpers::EqualsField(failed_ftrace_events_, other.failed_ftrace_events_)
   && ::protozero::internal::gen_helpers::EqualsField(preserve_ftrace_buffer_, other.preserve_ftrace_buffer_);
}

int FtraceStats::cpu_stats_size() const { return static_cast<int>(cpu_stats_.size()); }
void FtraceStats::clear_cpu_stats() { cpu_stats_.clear(); }
FtraceCpuStats* FtraceStats::add_cpu_stats() { cpu_stats_.emplace_back(); return &cpu_stats_.back(); }
bool FtraceStats::ParseFromArray(const void* raw, size_t size) {
  cpu_stats_.clear();
  unknown_ftrace_events_.clear();
  failed_ftrace_events_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* phase */:
        field.get(&phase_);
        break;
      case 2 /* cpu_stats */:
        cpu_stats_.emplace_back();
        cpu_stats_.back().ParseFromArray(field.data(), field.size());
        break;
      case 3 /* kernel_symbols_parsed */:
        field.get(&kernel_symbols_parsed_);
        break;
      case 4 /* kernel_symbols_mem_kb */:
        field.get(&kernel_symbols_mem_kb_);
        break;
      case 5 /* atrace_errors */:
        ::protozero::internal::gen_helpers::DeserializeString(field, &atrace_errors_);
        break;
      case 6 /* unknown_ftrace_events */:
        unknown_ftrace_events_.emplace_back();
        ::protozero::internal::gen_helpers::DeserializeString(field, &unknown_ftrace_events_.back());
        break;
      case 7 /* failed_ftrace_events */:
        failed_ftrace_events_.emplace_back();
        ::protozero::internal::gen_helpers::DeserializeString(field, &failed_ftrace_events_.back());
        break;
      case 8 /* preserve_ftrace_buffer */:
        field.get(&preserve_ftrace_buffer_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string FtraceStats::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> FtraceStats::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void FtraceStats::Serialize(::protozero::Message* msg) const {
  // Field 1: phase
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, phase_, msg);
  }

  // Field 2: cpu_stats
  for (auto& it : cpu_stats_) {
    it.Serialize(msg->BeginNestedMessage<::protozero::Message>(2));
  }

  // Field 3: kernel_symbols_parsed
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(3, kernel_symbols_parsed_, msg);
  }

  // Field 4: kernel_symbols_mem_kb
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(4, kernel_symbols_mem_kb_, msg);
  }

  // Field 5: atrace_errors
  if (_has_field_[5]) {
    ::protozero::internal::gen_helpers::SerializeString(5, atrace_errors_, msg);
  }

  // Field 6: unknown_ftrace_events
  for (auto& it : unknown_ftrace_events_) {
    ::protozero::internal::gen_helpers::SerializeString(6, it, msg);
  }

  // Field 7: failed_ftrace_events
  for (auto& it : failed_ftrace_events_) {
    ::protozero::internal::gen_helpers::SerializeString(7, it, msg);
  }

  // Field 8: preserve_ftrace_buffer
  if (_has_field_[8]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(8, preserve_ftrace_buffer_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


FtraceCpuStats::FtraceCpuStats() = default;
FtraceCpuStats::~FtraceCpuStats() = default;
FtraceCpuStats::FtraceCpuStats(const FtraceCpuStats&) = default;
FtraceCpuStats& FtraceCpuStats::operator=(const FtraceCpuStats&) = default;
FtraceCpuStats::FtraceCpuStats(FtraceCpuStats&&) noexcept = default;
FtraceCpuStats& FtraceCpuStats::operator=(FtraceCpuStats&&) = default;

bool FtraceCpuStats::operator==(const FtraceCpuStats& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(cpu_, other.cpu_)
   && ::protozero::internal::gen_helpers::EqualsField(entries_, other.entries_)
   && ::protozero::internal::gen_helpers::EqualsField(overrun_, other.overrun_)
   && ::protozero::internal::gen_helpers::EqualsField(commit_overrun_, other.commit_overrun_)
   && ::protozero::internal::gen_helpers::EqualsField(bytes_read_, other.bytes_read_)
   && ::protozero::internal::gen_helpers::EqualsField(oldest_event_ts_, other.oldest_event_ts_)
   && ::protozero::internal::gen_helpers::EqualsField(now_ts_, other.now_ts_)
   && ::protozero::internal::gen_helpers::EqualsField(dropped_events_, other.dropped_events_)
   && ::protozero::internal::gen_helpers::EqualsField(read_events_, other.read_events_);
}

bool FtraceCpuStats::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* cpu */:
        field.get(&cpu_);
        break;
      case 2 /* entries */:
        field.get(&entries_);
        break;
      case 3 /* overrun */:
        field.get(&overrun_);
        break;
      case 4 /* commit_overrun */:
        field.get(&commit_overrun_);
        break;
      case 5 /* bytes_read */:
        field.get(&bytes_read_);
        break;
      case 6 /* oldest_event_ts */:
        field.get(&oldest_event_ts_);
        break;
      case 7 /* now_ts */:
        field.get(&now_ts_);
        break;
      case 8 /* dropped_events */:
        field.get(&dropped_events_);
        break;
      case 9 /* read_events */:
        field.get(&read_events_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string FtraceCpuStats::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> FtraceCpuStats::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void FtraceCpuStats::Serialize(::protozero::Message* msg) const {
  // Field 1: cpu
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, cpu_, msg);
  }

  // Field 2: entries
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, entries_, msg);
  }

  // Field 3: overrun
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(3, overrun_, msg);
  }

  // Field 4: commit_overrun
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(4, commit_overrun_, msg);
  }

  // Field 5: bytes_read
  if (_has_field_[5]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(5, bytes_read_, msg);
  }

  // Field 6: oldest_event_ts
  if (_has_field_[6]) {
    ::protozero::internal::gen_helpers::SerializeFixed(6, oldest_event_ts_, msg);
  }

  // Field 7: now_ts
  if (_has_field_[7]) {
    ::protozero::internal::gen_helpers::SerializeFixed(7, now_ts_, msg);
  }

  // Field 8: dropped_events
  if (_has_field_[8]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(8, dropped_events_, msg);
  }

  // Field 9: read_events
  if (_has_field_[9]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(9, read_events_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

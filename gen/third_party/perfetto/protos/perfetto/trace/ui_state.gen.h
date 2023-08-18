// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_UI_STATE_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_UI_STATE_PROTO_CPP_H_

#include <stdint.h>
#include <bitset>
#include <vector>
#include <string>
#include <type_traits>

#include "perfetto/protozero/cpp_message_obj.h"
#include "perfetto/protozero/copyable_ptr.h"
#include "perfetto/base/export.h"

namespace perfetto {
namespace protos {
namespace gen {
class UiState;
class UiState_HighlightProcess;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {

class PERFETTO_EXPORT_COMPONENT UiState : public ::protozero::CppMessageObj {
 public:
  using HighlightProcess = UiState_HighlightProcess;
  enum FieldNumbers {
    kTimelineStartTsFieldNumber = 1,
    kTimelineEndTsFieldNumber = 2,
    kHighlightProcessFieldNumber = 3,
  };

  UiState();
  ~UiState() override;
  UiState(UiState&&) noexcept;
  UiState& operator=(UiState&&);
  UiState(const UiState&);
  UiState& operator=(const UiState&);
  bool operator==(const UiState&) const;
  bool operator!=(const UiState& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_timeline_start_ts() const { return _has_field_[1]; }
  int64_t timeline_start_ts() const { return timeline_start_ts_; }
  void set_timeline_start_ts(int64_t value) { timeline_start_ts_ = value; _has_field_.set(1); }

  bool has_timeline_end_ts() const { return _has_field_[2]; }
  int64_t timeline_end_ts() const { return timeline_end_ts_; }
  void set_timeline_end_ts(int64_t value) { timeline_end_ts_ = value; _has_field_.set(2); }

  bool has_highlight_process() const { return _has_field_[3]; }
  const UiState_HighlightProcess& highlight_process() const { return *highlight_process_; }
  UiState_HighlightProcess* mutable_highlight_process() { _has_field_.set(3); return highlight_process_.get(); }

 private:
  int64_t timeline_start_ts_{};
  int64_t timeline_end_ts_{};
  ::protozero::CopyablePtr<UiState_HighlightProcess> highlight_process_;

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<4> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT UiState_HighlightProcess : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kPidFieldNumber = 1,
    kCmdlineFieldNumber = 2,
  };

  UiState_HighlightProcess();
  ~UiState_HighlightProcess() override;
  UiState_HighlightProcess(UiState_HighlightProcess&&) noexcept;
  UiState_HighlightProcess& operator=(UiState_HighlightProcess&&);
  UiState_HighlightProcess(const UiState_HighlightProcess&);
  UiState_HighlightProcess& operator=(const UiState_HighlightProcess&);
  bool operator==(const UiState_HighlightProcess&) const;
  bool operator!=(const UiState_HighlightProcess& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_pid() const { return _has_field_[1]; }
  uint32_t pid() const { return pid_; }
  void set_pid(uint32_t value) { pid_ = value; _has_field_.set(1); }

  bool has_cmdline() const { return _has_field_[2]; }
  const std::string& cmdline() const { return cmdline_; }
  void set_cmdline(const std::string& value) { cmdline_ = value; _has_field_.set(2); }

 private:
  uint32_t pid_{};
  std::string cmdline_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<3> _has_field_{};
};

}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_UI_STATE_PROTO_CPP_H_

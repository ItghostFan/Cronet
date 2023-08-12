// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_EVENT_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_EVENT_PROTO_CPP_H_

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
class EventName;
class EventCategory;
class TrackEventDefaults;
class TrackEvent;
class TrackEvent_LegacyEvent;
class ChromeMojoEventInfo;
class ChromeMessagePump;
class SourceLocation;
class ChromeActiveProcesses;
class ChromeContentSettingsEventInfo;
class ChromeWindowHandleEventInfo;
class ChromeRendererSchedulerState;
class ChromeApplicationStateInfo;
class ChromeFrameReporter;
class ChromeLatencyInfo;
class ChromeLatencyInfo_ComponentInfo;
class ChromeHistogramSample;
class ChromeLegacyIpc;
class ChromeKeyedService;
class ChromeUserEvent;
class ChromeCompositorSchedulerState;
class CompositorTimingHistory;
class BeginFrameSourceState;
class BeginFrameArgs;
class BeginFrameObserverState;
class BeginImplFrameArgs;
class BeginImplFrameArgs_TimestampsInUs;
class ChromeCompositorStateMachine;
class ChromeCompositorStateMachine_MinorState;
class ChromeCompositorStateMachine_MajorState;
class LogMessage;
class TaskExecution;
class DebugAnnotation;
class DebugAnnotation_NestedValue;
enum TrackEvent_Type : int;
enum TrackEvent_LegacyEvent_FlowDirection : int;
enum TrackEvent_LegacyEvent_InstantEventScope : int;
enum ChromeRAILMode : int;
enum ChromeApplicationStateInfo_ChromeApplicationState : int;
enum ChromeFrameReporter_State : int;
enum ChromeFrameReporter_FrameDropReason : int;
enum ChromeFrameReporter_ScrollState : int;
enum ChromeFrameReporter_FrameType : int;
enum ChromeLatencyInfo_Step : int;
enum ChromeLatencyInfo_LatencyComponentType : int;
enum ChromeLegacyIpc_MessageClass : int;
enum ChromeCompositorSchedulerState_BeginImplFrameDeadlineMode : int;
enum ChromeCompositorSchedulerAction : int;
enum BeginFrameArgs_BeginFrameArgsType : int;
enum BeginImplFrameArgs_State : int;
enum ChromeCompositorStateMachine_MinorState_TreePriority : int;
enum ChromeCompositorStateMachine_MinorState_ScrollHandlerState : int;
enum ChromeCompositorStateMachine_MajorState_BeginImplFrameState : int;
enum ChromeCompositorStateMachine_MajorState_BeginMainFrameState : int;
enum ChromeCompositorStateMachine_MajorState_LayerTreeFrameSinkState : int;
enum ChromeCompositorStateMachine_MajorState_ForcedRedrawOnTimeoutState : int;
enum LogMessage_Priority : int;
enum DebugAnnotation_NestedValue_NestedType : int;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {
enum TrackEvent_Type : int {
  TrackEvent_Type_TYPE_UNSPECIFIED = 0,
  TrackEvent_Type_TYPE_SLICE_BEGIN = 1,
  TrackEvent_Type_TYPE_SLICE_END = 2,
  TrackEvent_Type_TYPE_INSTANT = 3,
  TrackEvent_Type_TYPE_COUNTER = 4,
};
enum TrackEvent_LegacyEvent_FlowDirection : int {
  TrackEvent_LegacyEvent_FlowDirection_FLOW_UNSPECIFIED = 0,
  TrackEvent_LegacyEvent_FlowDirection_FLOW_IN = 1,
  TrackEvent_LegacyEvent_FlowDirection_FLOW_OUT = 2,
  TrackEvent_LegacyEvent_FlowDirection_FLOW_INOUT = 3,
};
enum TrackEvent_LegacyEvent_InstantEventScope : int {
  TrackEvent_LegacyEvent_InstantEventScope_SCOPE_UNSPECIFIED = 0,
  TrackEvent_LegacyEvent_InstantEventScope_SCOPE_GLOBAL = 1,
  TrackEvent_LegacyEvent_InstantEventScope_SCOPE_PROCESS = 2,
  TrackEvent_LegacyEvent_InstantEventScope_SCOPE_THREAD = 3,
};

class PERFETTO_EXPORT_COMPONENT EventName : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kIidFieldNumber = 1,
    kNameFieldNumber = 2,
  };

  EventName();
  ~EventName() override;
  EventName(EventName&&) noexcept;
  EventName& operator=(EventName&&);
  EventName(const EventName&);
  EventName& operator=(const EventName&);
  bool operator==(const EventName&) const;
  bool operator!=(const EventName& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_iid() const { return _has_field_[1]; }
  uint64_t iid() const { return iid_; }
  void set_iid(uint64_t value) { iid_ = value; _has_field_.set(1); }

  bool has_name() const { return _has_field_[2]; }
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; _has_field_.set(2); }

 private:
  uint64_t iid_{};
  std::string name_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<3> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT EventCategory : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kIidFieldNumber = 1,
    kNameFieldNumber = 2,
  };

  EventCategory();
  ~EventCategory() override;
  EventCategory(EventCategory&&) noexcept;
  EventCategory& operator=(EventCategory&&);
  EventCategory(const EventCategory&);
  EventCategory& operator=(const EventCategory&);
  bool operator==(const EventCategory&) const;
  bool operator!=(const EventCategory& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_iid() const { return _has_field_[1]; }
  uint64_t iid() const { return iid_; }
  void set_iid(uint64_t value) { iid_ = value; _has_field_.set(1); }

  bool has_name() const { return _has_field_[2]; }
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; _has_field_.set(2); }

 private:
  uint64_t iid_{};
  std::string name_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<3> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT TrackEventDefaults : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kTrackUuidFieldNumber = 11,
    kExtraCounterTrackUuidsFieldNumber = 31,
    kExtraDoubleCounterTrackUuidsFieldNumber = 45,
  };

  TrackEventDefaults();
  ~TrackEventDefaults() override;
  TrackEventDefaults(TrackEventDefaults&&) noexcept;
  TrackEventDefaults& operator=(TrackEventDefaults&&);
  TrackEventDefaults(const TrackEventDefaults&);
  TrackEventDefaults& operator=(const TrackEventDefaults&);
  bool operator==(const TrackEventDefaults&) const;
  bool operator!=(const TrackEventDefaults& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_track_uuid() const { return _has_field_[11]; }
  uint64_t track_uuid() const { return track_uuid_; }
  void set_track_uuid(uint64_t value) { track_uuid_ = value; _has_field_.set(11); }

  const std::vector<uint64_t>& extra_counter_track_uuids() const { return extra_counter_track_uuids_; }
  std::vector<uint64_t>* mutable_extra_counter_track_uuids() { return &extra_counter_track_uuids_; }
  int extra_counter_track_uuids_size() const { return static_cast<int>(extra_counter_track_uuids_.size()); }
  void clear_extra_counter_track_uuids() { extra_counter_track_uuids_.clear(); }
  void add_extra_counter_track_uuids(uint64_t value) { extra_counter_track_uuids_.emplace_back(value); }
  uint64_t* add_extra_counter_track_uuids() { extra_counter_track_uuids_.emplace_back(); return &extra_counter_track_uuids_.back(); }

  const std::vector<uint64_t>& extra_double_counter_track_uuids() const { return extra_double_counter_track_uuids_; }
  std::vector<uint64_t>* mutable_extra_double_counter_track_uuids() { return &extra_double_counter_track_uuids_; }
  int extra_double_counter_track_uuids_size() const { return static_cast<int>(extra_double_counter_track_uuids_.size()); }
  void clear_extra_double_counter_track_uuids() { extra_double_counter_track_uuids_.clear(); }
  void add_extra_double_counter_track_uuids(uint64_t value) { extra_double_counter_track_uuids_.emplace_back(value); }
  uint64_t* add_extra_double_counter_track_uuids() { extra_double_counter_track_uuids_.emplace_back(); return &extra_double_counter_track_uuids_.back(); }

 private:
  uint64_t track_uuid_{};
  std::vector<uint64_t> extra_counter_track_uuids_;
  std::vector<uint64_t> extra_double_counter_track_uuids_;

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<46> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT TrackEvent : public ::protozero::CppMessageObj {
 public:
  using LegacyEvent = TrackEvent_LegacyEvent;
  using Type = TrackEvent_Type;
  static constexpr auto TYPE_UNSPECIFIED = TrackEvent_Type_TYPE_UNSPECIFIED;
  static constexpr auto TYPE_SLICE_BEGIN = TrackEvent_Type_TYPE_SLICE_BEGIN;
  static constexpr auto TYPE_SLICE_END = TrackEvent_Type_TYPE_SLICE_END;
  static constexpr auto TYPE_INSTANT = TrackEvent_Type_TYPE_INSTANT;
  static constexpr auto TYPE_COUNTER = TrackEvent_Type_TYPE_COUNTER;
  static constexpr auto Type_MIN = TrackEvent_Type_TYPE_UNSPECIFIED;
  static constexpr auto Type_MAX = TrackEvent_Type_TYPE_COUNTER;
  enum FieldNumbers {
    kCategoryIidsFieldNumber = 3,
    kCategoriesFieldNumber = 22,
    kNameIidFieldNumber = 10,
    kNameFieldNumber = 23,
    kTypeFieldNumber = 9,
    kTrackUuidFieldNumber = 11,
    kCounterValueFieldNumber = 30,
    kDoubleCounterValueFieldNumber = 44,
    kExtraCounterTrackUuidsFieldNumber = 31,
    kExtraCounterValuesFieldNumber = 12,
    kExtraDoubleCounterTrackUuidsFieldNumber = 45,
    kExtraDoubleCounterValuesFieldNumber = 46,
    kFlowIdsOldFieldNumber = 36,
    kFlowIdsFieldNumber = 47,
    kTerminatingFlowIdsOldFieldNumber = 42,
    kTerminatingFlowIdsFieldNumber = 48,
    kDebugAnnotationsFieldNumber = 4,
    kTaskExecutionFieldNumber = 5,
    kLogMessageFieldNumber = 21,
    kCcSchedulerStateFieldNumber = 24,
    kChromeUserEventFieldNumber = 25,
    kChromeKeyedServiceFieldNumber = 26,
    kChromeLegacyIpcFieldNumber = 27,
    kChromeHistogramSampleFieldNumber = 28,
    kChromeLatencyInfoFieldNumber = 29,
    kChromeFrameReporterFieldNumber = 32,
    kChromeApplicationStateInfoFieldNumber = 39,
    kChromeRendererSchedulerStateFieldNumber = 40,
    kChromeWindowHandleEventInfoFieldNumber = 41,
    kChromeContentSettingsEventInfoFieldNumber = 43,
    kChromeActiveProcessesFieldNumber = 49,
    kSourceLocationFieldNumber = 33,
    kSourceLocationIidFieldNumber = 34,
    kChromeMessagePumpFieldNumber = 35,
    kChromeMojoEventInfoFieldNumber = 38,
    kTimestampDeltaUsFieldNumber = 1,
    kTimestampAbsoluteUsFieldNumber = 16,
    kThreadTimeDeltaUsFieldNumber = 2,
    kThreadTimeAbsoluteUsFieldNumber = 17,
    kThreadInstructionCountDeltaFieldNumber = 8,
    kThreadInstructionCountAbsoluteFieldNumber = 20,
    kLegacyEventFieldNumber = 6,
  };

  TrackEvent();
  ~TrackEvent() override;
  TrackEvent(TrackEvent&&) noexcept;
  TrackEvent& operator=(TrackEvent&&);
  TrackEvent(const TrackEvent&);
  TrackEvent& operator=(const TrackEvent&);
  bool operator==(const TrackEvent&) const;
  bool operator!=(const TrackEvent& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  const std::vector<uint64_t>& category_iids() const { return category_iids_; }
  std::vector<uint64_t>* mutable_category_iids() { return &category_iids_; }
  int category_iids_size() const { return static_cast<int>(category_iids_.size()); }
  void clear_category_iids() { category_iids_.clear(); }
  void add_category_iids(uint64_t value) { category_iids_.emplace_back(value); }
  uint64_t* add_category_iids() { category_iids_.emplace_back(); return &category_iids_.back(); }

  const std::vector<std::string>& categories() const { return categories_; }
  std::vector<std::string>* mutable_categories() { return &categories_; }
  int categories_size() const { return static_cast<int>(categories_.size()); }
  void clear_categories() { categories_.clear(); }
  void add_categories(std::string value) { categories_.emplace_back(value); }
  std::string* add_categories() { categories_.emplace_back(); return &categories_.back(); }

  bool has_name_iid() const { return _has_field_[10]; }
  uint64_t name_iid() const { return name_iid_; }
  void set_name_iid(uint64_t value) { name_iid_ = value; _has_field_.set(10); }

  bool has_name() const { return _has_field_[23]; }
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; _has_field_.set(23); }

  bool has_type() const { return _has_field_[9]; }
  TrackEvent_Type type() const { return type_; }
  void set_type(TrackEvent_Type value) { type_ = value; _has_field_.set(9); }

  bool has_track_uuid() const { return _has_field_[11]; }
  uint64_t track_uuid() const { return track_uuid_; }
  void set_track_uuid(uint64_t value) { track_uuid_ = value; _has_field_.set(11); }

  bool has_counter_value() const { return _has_field_[30]; }
  int64_t counter_value() const { return counter_value_; }
  void set_counter_value(int64_t value) { counter_value_ = value; _has_field_.set(30); }

  bool has_double_counter_value() const { return _has_field_[44]; }
  double double_counter_value() const { return double_counter_value_; }
  void set_double_counter_value(double value) { double_counter_value_ = value; _has_field_.set(44); }

  const std::vector<uint64_t>& extra_counter_track_uuids() const { return extra_counter_track_uuids_; }
  std::vector<uint64_t>* mutable_extra_counter_track_uuids() { return &extra_counter_track_uuids_; }
  int extra_counter_track_uuids_size() const { return static_cast<int>(extra_counter_track_uuids_.size()); }
  void clear_extra_counter_track_uuids() { extra_counter_track_uuids_.clear(); }
  void add_extra_counter_track_uuids(uint64_t value) { extra_counter_track_uuids_.emplace_back(value); }
  uint64_t* add_extra_counter_track_uuids() { extra_counter_track_uuids_.emplace_back(); return &extra_counter_track_uuids_.back(); }

  const std::vector<int64_t>& extra_counter_values() const { return extra_counter_values_; }
  std::vector<int64_t>* mutable_extra_counter_values() { return &extra_counter_values_; }
  int extra_counter_values_size() const { return static_cast<int>(extra_counter_values_.size()); }
  void clear_extra_counter_values() { extra_counter_values_.clear(); }
  void add_extra_counter_values(int64_t value) { extra_counter_values_.emplace_back(value); }
  int64_t* add_extra_counter_values() { extra_counter_values_.emplace_back(); return &extra_counter_values_.back(); }

  const std::vector<uint64_t>& extra_double_counter_track_uuids() const { return extra_double_counter_track_uuids_; }
  std::vector<uint64_t>* mutable_extra_double_counter_track_uuids() { return &extra_double_counter_track_uuids_; }
  int extra_double_counter_track_uuids_size() const { return static_cast<int>(extra_double_counter_track_uuids_.size()); }
  void clear_extra_double_counter_track_uuids() { extra_double_counter_track_uuids_.clear(); }
  void add_extra_double_counter_track_uuids(uint64_t value) { extra_double_counter_track_uuids_.emplace_back(value); }
  uint64_t* add_extra_double_counter_track_uuids() { extra_double_counter_track_uuids_.emplace_back(); return &extra_double_counter_track_uuids_.back(); }

  const std::vector<double>& extra_double_counter_values() const { return extra_double_counter_values_; }
  std::vector<double>* mutable_extra_double_counter_values() { return &extra_double_counter_values_; }
  int extra_double_counter_values_size() const { return static_cast<int>(extra_double_counter_values_.size()); }
  void clear_extra_double_counter_values() { extra_double_counter_values_.clear(); }
  void add_extra_double_counter_values(double value) { extra_double_counter_values_.emplace_back(value); }
  double* add_extra_double_counter_values() { extra_double_counter_values_.emplace_back(); return &extra_double_counter_values_.back(); }

  const std::vector<uint64_t>& flow_ids_old() const { return flow_ids_old_; }
  std::vector<uint64_t>* mutable_flow_ids_old() { return &flow_ids_old_; }
  int flow_ids_old_size() const { return static_cast<int>(flow_ids_old_.size()); }
  void clear_flow_ids_old() { flow_ids_old_.clear(); }
  void add_flow_ids_old(uint64_t value) { flow_ids_old_.emplace_back(value); }
  uint64_t* add_flow_ids_old() { flow_ids_old_.emplace_back(); return &flow_ids_old_.back(); }

  const std::vector<uint64_t>& flow_ids() const { return flow_ids_; }
  std::vector<uint64_t>* mutable_flow_ids() { return &flow_ids_; }
  int flow_ids_size() const { return static_cast<int>(flow_ids_.size()); }
  void clear_flow_ids() { flow_ids_.clear(); }
  void add_flow_ids(uint64_t value) { flow_ids_.emplace_back(value); }
  uint64_t* add_flow_ids() { flow_ids_.emplace_back(); return &flow_ids_.back(); }

  const std::vector<uint64_t>& terminating_flow_ids_old() const { return terminating_flow_ids_old_; }
  std::vector<uint64_t>* mutable_terminating_flow_ids_old() { return &terminating_flow_ids_old_; }
  int terminating_flow_ids_old_size() const { return static_cast<int>(terminating_flow_ids_old_.size()); }
  void clear_terminating_flow_ids_old() { terminating_flow_ids_old_.clear(); }
  void add_terminating_flow_ids_old(uint64_t value) { terminating_flow_ids_old_.emplace_back(value); }
  uint64_t* add_terminating_flow_ids_old() { terminating_flow_ids_old_.emplace_back(); return &terminating_flow_ids_old_.back(); }

  const std::vector<uint64_t>& terminating_flow_ids() const { return terminating_flow_ids_; }
  std::vector<uint64_t>* mutable_terminating_flow_ids() { return &terminating_flow_ids_; }
  int terminating_flow_ids_size() const { return static_cast<int>(terminating_flow_ids_.size()); }
  void clear_terminating_flow_ids() { terminating_flow_ids_.clear(); }
  void add_terminating_flow_ids(uint64_t value) { terminating_flow_ids_.emplace_back(value); }
  uint64_t* add_terminating_flow_ids() { terminating_flow_ids_.emplace_back(); return &terminating_flow_ids_.back(); }

  const std::vector<DebugAnnotation>& debug_annotations() const { return debug_annotations_; }
  std::vector<DebugAnnotation>* mutable_debug_annotations() { return &debug_annotations_; }
  int debug_annotations_size() const;
  void clear_debug_annotations();
  DebugAnnotation* add_debug_annotations();

  bool has_task_execution() const { return _has_field_[5]; }
  const TaskExecution& task_execution() const { return *task_execution_; }
  TaskExecution* mutable_task_execution() { _has_field_.set(5); return task_execution_.get(); }

  bool has_log_message() const { return _has_field_[21]; }
  const LogMessage& log_message() const { return *log_message_; }
  LogMessage* mutable_log_message() { _has_field_.set(21); return log_message_.get(); }

  bool has_cc_scheduler_state() const { return _has_field_[24]; }
  const ChromeCompositorSchedulerState& cc_scheduler_state() const { return *cc_scheduler_state_; }
  ChromeCompositorSchedulerState* mutable_cc_scheduler_state() { _has_field_.set(24); return cc_scheduler_state_.get(); }

  bool has_chrome_user_event() const { return _has_field_[25]; }
  const ChromeUserEvent& chrome_user_event() const { return *chrome_user_event_; }
  ChromeUserEvent* mutable_chrome_user_event() { _has_field_.set(25); return chrome_user_event_.get(); }

  bool has_chrome_keyed_service() const { return _has_field_[26]; }
  const ChromeKeyedService& chrome_keyed_service() const { return *chrome_keyed_service_; }
  ChromeKeyedService* mutable_chrome_keyed_service() { _has_field_.set(26); return chrome_keyed_service_.get(); }

  bool has_chrome_legacy_ipc() const { return _has_field_[27]; }
  const ChromeLegacyIpc& chrome_legacy_ipc() const { return *chrome_legacy_ipc_; }
  ChromeLegacyIpc* mutable_chrome_legacy_ipc() { _has_field_.set(27); return chrome_legacy_ipc_.get(); }

  bool has_chrome_histogram_sample() const { return _has_field_[28]; }
  const ChromeHistogramSample& chrome_histogram_sample() const { return *chrome_histogram_sample_; }
  ChromeHistogramSample* mutable_chrome_histogram_sample() { _has_field_.set(28); return chrome_histogram_sample_.get(); }

  bool has_chrome_latency_info() const { return _has_field_[29]; }
  const ChromeLatencyInfo& chrome_latency_info() const { return *chrome_latency_info_; }
  ChromeLatencyInfo* mutable_chrome_latency_info() { _has_field_.set(29); return chrome_latency_info_.get(); }

  bool has_chrome_frame_reporter() const { return _has_field_[32]; }
  const ChromeFrameReporter& chrome_frame_reporter() const { return *chrome_frame_reporter_; }
  ChromeFrameReporter* mutable_chrome_frame_reporter() { _has_field_.set(32); return chrome_frame_reporter_.get(); }

  bool has_chrome_application_state_info() const { return _has_field_[39]; }
  const ChromeApplicationStateInfo& chrome_application_state_info() const { return *chrome_application_state_info_; }
  ChromeApplicationStateInfo* mutable_chrome_application_state_info() { _has_field_.set(39); return chrome_application_state_info_.get(); }

  bool has_chrome_renderer_scheduler_state() const { return _has_field_[40]; }
  const ChromeRendererSchedulerState& chrome_renderer_scheduler_state() const { return *chrome_renderer_scheduler_state_; }
  ChromeRendererSchedulerState* mutable_chrome_renderer_scheduler_state() { _has_field_.set(40); return chrome_renderer_scheduler_state_.get(); }

  bool has_chrome_window_handle_event_info() const { return _has_field_[41]; }
  const ChromeWindowHandleEventInfo& chrome_window_handle_event_info() const { return *chrome_window_handle_event_info_; }
  ChromeWindowHandleEventInfo* mutable_chrome_window_handle_event_info() { _has_field_.set(41); return chrome_window_handle_event_info_.get(); }

  bool has_chrome_content_settings_event_info() const { return _has_field_[43]; }
  const ChromeContentSettingsEventInfo& chrome_content_settings_event_info() const { return *chrome_content_settings_event_info_; }
  ChromeContentSettingsEventInfo* mutable_chrome_content_settings_event_info() { _has_field_.set(43); return chrome_content_settings_event_info_.get(); }

  bool has_chrome_active_processes() const { return _has_field_[49]; }
  const ChromeActiveProcesses& chrome_active_processes() const { return *chrome_active_processes_; }
  ChromeActiveProcesses* mutable_chrome_active_processes() { _has_field_.set(49); return chrome_active_processes_.get(); }

  bool has_source_location() const { return _has_field_[33]; }
  const SourceLocation& source_location() const { return *source_location_; }
  SourceLocation* mutable_source_location() { _has_field_.set(33); return source_location_.get(); }

  bool has_source_location_iid() const { return _has_field_[34]; }
  uint64_t source_location_iid() const { return source_location_iid_; }
  void set_source_location_iid(uint64_t value) { source_location_iid_ = value; _has_field_.set(34); }

  bool has_chrome_message_pump() const { return _has_field_[35]; }
  const ChromeMessagePump& chrome_message_pump() const { return *chrome_message_pump_; }
  ChromeMessagePump* mutable_chrome_message_pump() { _has_field_.set(35); return chrome_message_pump_.get(); }

  bool has_chrome_mojo_event_info() const { return _has_field_[38]; }
  const ChromeMojoEventInfo& chrome_mojo_event_info() const { return *chrome_mojo_event_info_; }
  ChromeMojoEventInfo* mutable_chrome_mojo_event_info() { _has_field_.set(38); return chrome_mojo_event_info_.get(); }

  bool has_timestamp_delta_us() const { return _has_field_[1]; }
  int64_t timestamp_delta_us() const { return timestamp_delta_us_; }
  void set_timestamp_delta_us(int64_t value) { timestamp_delta_us_ = value; _has_field_.set(1); }

  bool has_timestamp_absolute_us() const { return _has_field_[16]; }
  int64_t timestamp_absolute_us() const { return timestamp_absolute_us_; }
  void set_timestamp_absolute_us(int64_t value) { timestamp_absolute_us_ = value; _has_field_.set(16); }

  bool has_thread_time_delta_us() const { return _has_field_[2]; }
  int64_t thread_time_delta_us() const { return thread_time_delta_us_; }
  void set_thread_time_delta_us(int64_t value) { thread_time_delta_us_ = value; _has_field_.set(2); }

  bool has_thread_time_absolute_us() const { return _has_field_[17]; }
  int64_t thread_time_absolute_us() const { return thread_time_absolute_us_; }
  void set_thread_time_absolute_us(int64_t value) { thread_time_absolute_us_ = value; _has_field_.set(17); }

  bool has_thread_instruction_count_delta() const { return _has_field_[8]; }
  int64_t thread_instruction_count_delta() const { return thread_instruction_count_delta_; }
  void set_thread_instruction_count_delta(int64_t value) { thread_instruction_count_delta_ = value; _has_field_.set(8); }

  bool has_thread_instruction_count_absolute() const { return _has_field_[20]; }
  int64_t thread_instruction_count_absolute() const { return thread_instruction_count_absolute_; }
  void set_thread_instruction_count_absolute(int64_t value) { thread_instruction_count_absolute_ = value; _has_field_.set(20); }

  bool has_legacy_event() const { return _has_field_[6]; }
  const TrackEvent_LegacyEvent& legacy_event() const { return *legacy_event_; }
  TrackEvent_LegacyEvent* mutable_legacy_event() { _has_field_.set(6); return legacy_event_.get(); }

 private:
  std::vector<uint64_t> category_iids_;
  std::vector<std::string> categories_;
  uint64_t name_iid_{};
  std::string name_{};
  TrackEvent_Type type_{};
  uint64_t track_uuid_{};
  int64_t counter_value_{};
  double double_counter_value_{};
  std::vector<uint64_t> extra_counter_track_uuids_;
  std::vector<int64_t> extra_counter_values_;
  std::vector<uint64_t> extra_double_counter_track_uuids_;
  std::vector<double> extra_double_counter_values_;
  std::vector<uint64_t> flow_ids_old_;
  std::vector<uint64_t> flow_ids_;
  std::vector<uint64_t> terminating_flow_ids_old_;
  std::vector<uint64_t> terminating_flow_ids_;
  std::vector<DebugAnnotation> debug_annotations_;
  ::protozero::CopyablePtr<TaskExecution> task_execution_;
  ::protozero::CopyablePtr<LogMessage> log_message_;
  ::protozero::CopyablePtr<ChromeCompositorSchedulerState> cc_scheduler_state_;
  ::protozero::CopyablePtr<ChromeUserEvent> chrome_user_event_;
  ::protozero::CopyablePtr<ChromeKeyedService> chrome_keyed_service_;
  ::protozero::CopyablePtr<ChromeLegacyIpc> chrome_legacy_ipc_;
  ::protozero::CopyablePtr<ChromeHistogramSample> chrome_histogram_sample_;
  ::protozero::CopyablePtr<ChromeLatencyInfo> chrome_latency_info_;
  ::protozero::CopyablePtr<ChromeFrameReporter> chrome_frame_reporter_;
  ::protozero::CopyablePtr<ChromeApplicationStateInfo> chrome_application_state_info_;
  ::protozero::CopyablePtr<ChromeRendererSchedulerState> chrome_renderer_scheduler_state_;
  ::protozero::CopyablePtr<ChromeWindowHandleEventInfo> chrome_window_handle_event_info_;
  ::protozero::CopyablePtr<ChromeContentSettingsEventInfo> chrome_content_settings_event_info_;
  ::protozero::CopyablePtr<ChromeActiveProcesses> chrome_active_processes_;
  ::protozero::CopyablePtr<SourceLocation> source_location_;
  uint64_t source_location_iid_{};
  ::protozero::CopyablePtr<ChromeMessagePump> chrome_message_pump_;
  ::protozero::CopyablePtr<ChromeMojoEventInfo> chrome_mojo_event_info_;
  int64_t timestamp_delta_us_{};
  int64_t timestamp_absolute_us_{};
  int64_t thread_time_delta_us_{};
  int64_t thread_time_absolute_us_{};
  int64_t thread_instruction_count_delta_{};
  int64_t thread_instruction_count_absolute_{};
  ::protozero::CopyablePtr<TrackEvent_LegacyEvent> legacy_event_;

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<50> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT TrackEvent_LegacyEvent : public ::protozero::CppMessageObj {
 public:
  using FlowDirection = TrackEvent_LegacyEvent_FlowDirection;
  static constexpr auto FLOW_UNSPECIFIED = TrackEvent_LegacyEvent_FlowDirection_FLOW_UNSPECIFIED;
  static constexpr auto FLOW_IN = TrackEvent_LegacyEvent_FlowDirection_FLOW_IN;
  static constexpr auto FLOW_OUT = TrackEvent_LegacyEvent_FlowDirection_FLOW_OUT;
  static constexpr auto FLOW_INOUT = TrackEvent_LegacyEvent_FlowDirection_FLOW_INOUT;
  static constexpr auto FlowDirection_MIN = TrackEvent_LegacyEvent_FlowDirection_FLOW_UNSPECIFIED;
  static constexpr auto FlowDirection_MAX = TrackEvent_LegacyEvent_FlowDirection_FLOW_INOUT;
  using InstantEventScope = TrackEvent_LegacyEvent_InstantEventScope;
  static constexpr auto SCOPE_UNSPECIFIED = TrackEvent_LegacyEvent_InstantEventScope_SCOPE_UNSPECIFIED;
  static constexpr auto SCOPE_GLOBAL = TrackEvent_LegacyEvent_InstantEventScope_SCOPE_GLOBAL;
  static constexpr auto SCOPE_PROCESS = TrackEvent_LegacyEvent_InstantEventScope_SCOPE_PROCESS;
  static constexpr auto SCOPE_THREAD = TrackEvent_LegacyEvent_InstantEventScope_SCOPE_THREAD;
  static constexpr auto InstantEventScope_MIN = TrackEvent_LegacyEvent_InstantEventScope_SCOPE_UNSPECIFIED;
  static constexpr auto InstantEventScope_MAX = TrackEvent_LegacyEvent_InstantEventScope_SCOPE_THREAD;
  enum FieldNumbers {
    kNameIidFieldNumber = 1,
    kPhaseFieldNumber = 2,
    kDurationUsFieldNumber = 3,
    kThreadDurationUsFieldNumber = 4,
    kThreadInstructionDeltaFieldNumber = 15,
    kUnscopedIdFieldNumber = 6,
    kLocalIdFieldNumber = 10,
    kGlobalIdFieldNumber = 11,
    kIdScopeFieldNumber = 7,
    kUseAsyncTtsFieldNumber = 9,
    kBindIdFieldNumber = 8,
    kBindToEnclosingFieldNumber = 12,
    kFlowDirectionFieldNumber = 13,
    kInstantEventScopeFieldNumber = 14,
    kPidOverrideFieldNumber = 18,
    kTidOverrideFieldNumber = 19,
  };

  TrackEvent_LegacyEvent();
  ~TrackEvent_LegacyEvent() override;
  TrackEvent_LegacyEvent(TrackEvent_LegacyEvent&&) noexcept;
  TrackEvent_LegacyEvent& operator=(TrackEvent_LegacyEvent&&);
  TrackEvent_LegacyEvent(const TrackEvent_LegacyEvent&);
  TrackEvent_LegacyEvent& operator=(const TrackEvent_LegacyEvent&);
  bool operator==(const TrackEvent_LegacyEvent&) const;
  bool operator!=(const TrackEvent_LegacyEvent& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_name_iid() const { return _has_field_[1]; }
  uint64_t name_iid() const { return name_iid_; }
  void set_name_iid(uint64_t value) { name_iid_ = value; _has_field_.set(1); }

  bool has_phase() const { return _has_field_[2]; }
  int32_t phase() const { return phase_; }
  void set_phase(int32_t value) { phase_ = value; _has_field_.set(2); }

  bool has_duration_us() const { return _has_field_[3]; }
  int64_t duration_us() const { return duration_us_; }
  void set_duration_us(int64_t value) { duration_us_ = value; _has_field_.set(3); }

  bool has_thread_duration_us() const { return _has_field_[4]; }
  int64_t thread_duration_us() const { return thread_duration_us_; }
  void set_thread_duration_us(int64_t value) { thread_duration_us_ = value; _has_field_.set(4); }

  bool has_thread_instruction_delta() const { return _has_field_[15]; }
  int64_t thread_instruction_delta() const { return thread_instruction_delta_; }
  void set_thread_instruction_delta(int64_t value) { thread_instruction_delta_ = value; _has_field_.set(15); }

  bool has_unscoped_id() const { return _has_field_[6]; }
  uint64_t unscoped_id() const { return unscoped_id_; }
  void set_unscoped_id(uint64_t value) { unscoped_id_ = value; _has_field_.set(6); }

  bool has_local_id() const { return _has_field_[10]; }
  uint64_t local_id() const { return local_id_; }
  void set_local_id(uint64_t value) { local_id_ = value; _has_field_.set(10); }

  bool has_global_id() const { return _has_field_[11]; }
  uint64_t global_id() const { return global_id_; }
  void set_global_id(uint64_t value) { global_id_ = value; _has_field_.set(11); }

  bool has_id_scope() const { return _has_field_[7]; }
  const std::string& id_scope() const { return id_scope_; }
  void set_id_scope(const std::string& value) { id_scope_ = value; _has_field_.set(7); }

  bool has_use_async_tts() const { return _has_field_[9]; }
  bool use_async_tts() const { return use_async_tts_; }
  void set_use_async_tts(bool value) { use_async_tts_ = value; _has_field_.set(9); }

  bool has_bind_id() const { return _has_field_[8]; }
  uint64_t bind_id() const { return bind_id_; }
  void set_bind_id(uint64_t value) { bind_id_ = value; _has_field_.set(8); }

  bool has_bind_to_enclosing() const { return _has_field_[12]; }
  bool bind_to_enclosing() const { return bind_to_enclosing_; }
  void set_bind_to_enclosing(bool value) { bind_to_enclosing_ = value; _has_field_.set(12); }

  bool has_flow_direction() const { return _has_field_[13]; }
  TrackEvent_LegacyEvent_FlowDirection flow_direction() const { return flow_direction_; }
  void set_flow_direction(TrackEvent_LegacyEvent_FlowDirection value) { flow_direction_ = value; _has_field_.set(13); }

  bool has_instant_event_scope() const { return _has_field_[14]; }
  TrackEvent_LegacyEvent_InstantEventScope instant_event_scope() const { return instant_event_scope_; }
  void set_instant_event_scope(TrackEvent_LegacyEvent_InstantEventScope value) { instant_event_scope_ = value; _has_field_.set(14); }

  bool has_pid_override() const { return _has_field_[18]; }
  int32_t pid_override() const { return pid_override_; }
  void set_pid_override(int32_t value) { pid_override_ = value; _has_field_.set(18); }

  bool has_tid_override() const { return _has_field_[19]; }
  int32_t tid_override() const { return tid_override_; }
  void set_tid_override(int32_t value) { tid_override_ = value; _has_field_.set(19); }

 private:
  uint64_t name_iid_{};
  int32_t phase_{};
  int64_t duration_us_{};
  int64_t thread_duration_us_{};
  int64_t thread_instruction_delta_{};
  uint64_t unscoped_id_{};
  uint64_t local_id_{};
  uint64_t global_id_{};
  std::string id_scope_{};
  bool use_async_tts_{};
  uint64_t bind_id_{};
  bool bind_to_enclosing_{};
  TrackEvent_LegacyEvent_FlowDirection flow_direction_{};
  TrackEvent_LegacyEvent_InstantEventScope instant_event_scope_{};
  int32_t pid_override_{};
  int32_t tid_override_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<20> _has_field_{};
};

}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_EVENT_PROTO_CPP_H_

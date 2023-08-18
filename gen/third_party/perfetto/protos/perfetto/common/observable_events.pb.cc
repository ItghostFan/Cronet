// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/common/observable_events.proto

#include "protos/perfetto/common/observable_events.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace perfetto {
namespace protos {
PROTOBUF_CONSTEXPR ObservableEvents_DataSourceInstanceStateChange::ObservableEvents_DataSourceInstanceStateChange(
    ::_pbi::ConstantInitialized)
  : producer_name_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , data_source_name_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , state_(1)
{}
struct ObservableEvents_DataSourceInstanceStateChangeDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ObservableEvents_DataSourceInstanceStateChangeDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ObservableEvents_DataSourceInstanceStateChangeDefaultTypeInternal() {}
  union {
    ObservableEvents_DataSourceInstanceStateChange _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT_WITH_PTR PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ObservableEvents_DataSourceInstanceStateChangeDefaultTypeInternal _ObservableEvents_DataSourceInstanceStateChange_default_instance_;
PROTOBUF_CONSTEXPR ObservableEvents_CloneTriggerHit::ObservableEvents_CloneTriggerHit(
    ::_pbi::ConstantInitialized)
  : tracing_session_id_(int64_t{0}){}
struct ObservableEvents_CloneTriggerHitDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ObservableEvents_CloneTriggerHitDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ObservableEvents_CloneTriggerHitDefaultTypeInternal() {}
  union {
    ObservableEvents_CloneTriggerHit _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT_WITH_PTR PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ObservableEvents_CloneTriggerHitDefaultTypeInternal _ObservableEvents_CloneTriggerHit_default_instance_;
PROTOBUF_CONSTEXPR ObservableEvents::ObservableEvents(
    ::_pbi::ConstantInitialized)
  : instance_state_changes_()
  , clone_trigger_hit_(nullptr)
  , all_data_sources_started_(false){}
struct ObservableEventsDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ObservableEventsDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ObservableEventsDefaultTypeInternal() {}
  union {
    ObservableEvents _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT_WITH_PTR PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ObservableEventsDefaultTypeInternal _ObservableEvents_default_instance_;
}  // namespace protos
}  // namespace perfetto
namespace perfetto {
namespace protos {
bool ObservableEvents_Type_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 4:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> ObservableEvents_Type_strings[4] = {};

static const char ObservableEvents_Type_names[] =
  "TYPE_ALL_DATA_SOURCES_STARTED"
  "TYPE_CLONE_TRIGGER_HIT"
  "TYPE_DATA_SOURCES_INSTANCES"
  "TYPE_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry ObservableEvents_Type_entries[] = {
  { {ObservableEvents_Type_names + 0, 29}, 2 },
  { {ObservableEvents_Type_names + 29, 22}, 4 },
  { {ObservableEvents_Type_names + 51, 27}, 1 },
  { {ObservableEvents_Type_names + 78, 16}, 0 },
};

static const int ObservableEvents_Type_entries_by_number[] = {
  3, // 0 -> TYPE_UNSPECIFIED
  2, // 1 -> TYPE_DATA_SOURCES_INSTANCES
  0, // 2 -> TYPE_ALL_DATA_SOURCES_STARTED
  1, // 4 -> TYPE_CLONE_TRIGGER_HIT
};

const std::string& ObservableEvents_Type_Name(
    ObservableEvents_Type value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          ObservableEvents_Type_entries,
          ObservableEvents_Type_entries_by_number,
          4, ObservableEvents_Type_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      ObservableEvents_Type_entries,
      ObservableEvents_Type_entries_by_number,
      4, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     ObservableEvents_Type_strings[idx].get();
}
bool ObservableEvents_Type_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ObservableEvents_Type* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      ObservableEvents_Type_entries, 4, name, &int_value);
  if (success) {
    *value = static_cast<ObservableEvents_Type>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr ObservableEvents_Type ObservableEvents::TYPE_UNSPECIFIED;
constexpr ObservableEvents_Type ObservableEvents::TYPE_DATA_SOURCES_INSTANCES;
constexpr ObservableEvents_Type ObservableEvents::TYPE_ALL_DATA_SOURCES_STARTED;
constexpr ObservableEvents_Type ObservableEvents::TYPE_CLONE_TRIGGER_HIT;
constexpr ObservableEvents_Type ObservableEvents::Type_MIN;
constexpr ObservableEvents_Type ObservableEvents::Type_MAX;
constexpr int ObservableEvents::Type_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
bool ObservableEvents_DataSourceInstanceState_IsValid(int value) {
  switch (value) {
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> ObservableEvents_DataSourceInstanceState_strings[2] = {};

static const char ObservableEvents_DataSourceInstanceState_names[] =
  "DATA_SOURCE_INSTANCE_STATE_STARTED"
  "DATA_SOURCE_INSTANCE_STATE_STOPPED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry ObservableEvents_DataSourceInstanceState_entries[] = {
  { {ObservableEvents_DataSourceInstanceState_names + 0, 34}, 2 },
  { {ObservableEvents_DataSourceInstanceState_names + 34, 34}, 1 },
};

static const int ObservableEvents_DataSourceInstanceState_entries_by_number[] = {
  1, // 1 -> DATA_SOURCE_INSTANCE_STATE_STOPPED
  0, // 2 -> DATA_SOURCE_INSTANCE_STATE_STARTED
};

const std::string& ObservableEvents_DataSourceInstanceState_Name(
    ObservableEvents_DataSourceInstanceState value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          ObservableEvents_DataSourceInstanceState_entries,
          ObservableEvents_DataSourceInstanceState_entries_by_number,
          2, ObservableEvents_DataSourceInstanceState_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      ObservableEvents_DataSourceInstanceState_entries,
      ObservableEvents_DataSourceInstanceState_entries_by_number,
      2, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     ObservableEvents_DataSourceInstanceState_strings[idx].get();
}
bool ObservableEvents_DataSourceInstanceState_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ObservableEvents_DataSourceInstanceState* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      ObservableEvents_DataSourceInstanceState_entries, 2, name, &int_value);
  if (success) {
    *value = static_cast<ObservableEvents_DataSourceInstanceState>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DATA_SOURCE_INSTANCE_STATE_STOPPED;
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DATA_SOURCE_INSTANCE_STATE_STARTED;
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DataSourceInstanceState_MIN;
constexpr ObservableEvents_DataSourceInstanceState ObservableEvents::DataSourceInstanceState_MAX;
constexpr int ObservableEvents::DataSourceInstanceState_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class ObservableEvents_DataSourceInstanceStateChange::_Internal {
 public:
  using HasBits = decltype(std::declval<ObservableEvents_DataSourceInstanceStateChange>()._has_bits_);
  static void set_has_producer_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_data_source_name(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_state(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

ObservableEvents_DataSourceInstanceStateChange::ObservableEvents_DataSourceInstanceStateChange(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
}
ObservableEvents_DataSourceInstanceStateChange::ObservableEvents_DataSourceInstanceStateChange(const ObservableEvents_DataSourceInstanceStateChange& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  producer_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    producer_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_producer_name()) {
    producer_name_.Set(from._internal_producer_name(), 
      GetArenaForAllocation());
  }
  data_source_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    data_source_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_data_source_name()) {
    data_source_name_.Set(from._internal_data_source_name(), 
      GetArenaForAllocation());
  }
  state_ = from.state_;
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
}

inline void ObservableEvents_DataSourceInstanceStateChange::SharedCtor() {
producer_name_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  producer_name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
data_source_name_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  data_source_name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
state_ = 1;
}

ObservableEvents_DataSourceInstanceStateChange::~ObservableEvents_DataSourceInstanceStateChange() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<std::string>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ObservableEvents_DataSourceInstanceStateChange::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  producer_name_.Destroy();
  data_source_name_.Destroy();
}

void ObservableEvents_DataSourceInstanceStateChange::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ObservableEvents_DataSourceInstanceStateChange::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      producer_name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      data_source_name_.ClearNonDefaultToEmpty();
    }
    state_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* ObservableEvents_DataSourceInstanceStateChange::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional string producer_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_producer_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional string data_source_name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_data_source_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional .perfetto.protos.ObservableEvents.DataSourceInstanceState state = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::perfetto::protos::ObservableEvents_DataSourceInstanceState_IsValid(val))) {
            _internal_set_state(static_cast<::perfetto::protos::ObservableEvents_DataSourceInstanceState>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(3, val, mutable_unknown_fields());
          }
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<std::string>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ObservableEvents_DataSourceInstanceStateChange::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string producer_name = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_producer_name(), target);
  }

  // optional string data_source_name = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_data_source_name(), target);
  }

  // optional .perfetto.protos.ObservableEvents.DataSourceInstanceState state = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      3, this->_internal_state(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  return target;
}

size_t ObservableEvents_DataSourceInstanceStateChange::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional string producer_name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_producer_name());
    }

    // optional string data_source_name = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_data_source_name());
    }

    // optional .perfetto.protos.ObservableEvents.DataSourceInstanceState state = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::_pbi::WireFormatLite::EnumSize(this->_internal_state());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::_pbi::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObservableEvents_DataSourceInstanceStateChange::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::_pbi::DownCast<const ObservableEvents_DataSourceInstanceStateChange*>(
      &from));
}

void ObservableEvents_DataSourceInstanceStateChange::MergeFrom(const ObservableEvents_DataSourceInstanceStateChange& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_producer_name(from._internal_producer_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_data_source_name(from._internal_data_source_name());
    }
    if (cached_has_bits & 0x00000004u) {
      state_ = from.state_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void ObservableEvents_DataSourceInstanceStateChange::CopyFrom(const ObservableEvents_DataSourceInstanceStateChange& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ObservableEvents.DataSourceInstanceStateChange)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObservableEvents_DataSourceInstanceStateChange::IsInitialized() const {
  return true;
}

void ObservableEvents_DataSourceInstanceStateChange::InternalSwap(ObservableEvents_DataSourceInstanceStateChange* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &producer_name_, lhs_arena,
      &other->producer_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &data_source_name_, lhs_arena,
      &other->data_source_name_, rhs_arena
  );
  swap(state_, other->state_);
}

std::string ObservableEvents_DataSourceInstanceStateChange::GetTypeName() const {
  return "perfetto.protos.ObservableEvents.DataSourceInstanceStateChange";
}


// ===================================================================

class ObservableEvents_CloneTriggerHit::_Internal {
 public:
  using HasBits = decltype(std::declval<ObservableEvents_CloneTriggerHit>()._has_bits_);
  static void set_has_tracing_session_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

ObservableEvents_CloneTriggerHit::ObservableEvents_CloneTriggerHit(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.ObservableEvents.CloneTriggerHit)
}
ObservableEvents_CloneTriggerHit::ObservableEvents_CloneTriggerHit(const ObservableEvents_CloneTriggerHit& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  tracing_session_id_ = from.tracing_session_id_;
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ObservableEvents.CloneTriggerHit)
}

inline void ObservableEvents_CloneTriggerHit::SharedCtor() {
tracing_session_id_ = int64_t{0};
}

ObservableEvents_CloneTriggerHit::~ObservableEvents_CloneTriggerHit() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ObservableEvents.CloneTriggerHit)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<std::string>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ObservableEvents_CloneTriggerHit::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ObservableEvents_CloneTriggerHit::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ObservableEvents_CloneTriggerHit::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ObservableEvents.CloneTriggerHit)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  tracing_session_id_ = int64_t{0};
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* ObservableEvents_CloneTriggerHit::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional int64 tracing_session_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _Internal::set_has_tracing_session_id(&has_bits);
          tracing_session_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<std::string>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ObservableEvents_CloneTriggerHit::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.ObservableEvents.CloneTriggerHit)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int64 tracing_session_id = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_tracing_session_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.ObservableEvents.CloneTriggerHit)
  return target;
}

size_t ObservableEvents_CloneTriggerHit::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ObservableEvents.CloneTriggerHit)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional int64 tracing_session_id = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_tracing_session_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::_pbi::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObservableEvents_CloneTriggerHit::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::_pbi::DownCast<const ObservableEvents_CloneTriggerHit*>(
      &from));
}

void ObservableEvents_CloneTriggerHit::MergeFrom(const ObservableEvents_CloneTriggerHit& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ObservableEvents.CloneTriggerHit)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_tracing_session_id()) {
    _internal_set_tracing_session_id(from._internal_tracing_session_id());
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void ObservableEvents_CloneTriggerHit::CopyFrom(const ObservableEvents_CloneTriggerHit& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ObservableEvents.CloneTriggerHit)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObservableEvents_CloneTriggerHit::IsInitialized() const {
  return true;
}

void ObservableEvents_CloneTriggerHit::InternalSwap(ObservableEvents_CloneTriggerHit* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(tracing_session_id_, other->tracing_session_id_);
}

std::string ObservableEvents_CloneTriggerHit::GetTypeName() const {
  return "perfetto.protos.ObservableEvents.CloneTriggerHit";
}


// ===================================================================

class ObservableEvents::_Internal {
 public:
  using HasBits = decltype(std::declval<ObservableEvents>()._has_bits_);
  static void set_has_all_data_sources_started(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static const ::perfetto::protos::ObservableEvents_CloneTriggerHit& clone_trigger_hit(const ObservableEvents* msg);
  static void set_has_clone_trigger_hit(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::perfetto::protos::ObservableEvents_CloneTriggerHit&
ObservableEvents::_Internal::clone_trigger_hit(const ObservableEvents* msg) {
  return *msg->clone_trigger_hit_;
}
ObservableEvents::ObservableEvents(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned),
  instance_state_changes_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.ObservableEvents)
}
ObservableEvents::ObservableEvents(const ObservableEvents& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_),
      instance_state_changes_(from.instance_state_changes_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  if (from._internal_has_clone_trigger_hit()) {
    clone_trigger_hit_ = new ::perfetto::protos::ObservableEvents_CloneTriggerHit(*from.clone_trigger_hit_);
  } else {
    clone_trigger_hit_ = nullptr;
  }
  all_data_sources_started_ = from.all_data_sources_started_;
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ObservableEvents)
}

inline void ObservableEvents::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&clone_trigger_hit_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&all_data_sources_started_) -
    reinterpret_cast<char*>(&clone_trigger_hit_)) + sizeof(all_data_sources_started_));
}

ObservableEvents::~ObservableEvents() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ObservableEvents)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<std::string>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ObservableEvents::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete clone_trigger_hit_;
}

void ObservableEvents::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ObservableEvents::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ObservableEvents)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  instance_state_changes_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(clone_trigger_hit_ != nullptr);
    clone_trigger_hit_->Clear();
  }
  all_data_sources_started_ = false;
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* ObservableEvents::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .perfetto.protos.ObservableEvents.DataSourceInstanceStateChange instance_state_changes = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_instance_state_changes(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      // optional bool all_data_sources_started = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _Internal::set_has_all_data_sources_started(&has_bits);
          all_data_sources_started_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional .perfetto.protos.ObservableEvents.CloneTriggerHit clone_trigger_hit = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_clone_trigger_hit(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<std::string>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ObservableEvents::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.ObservableEvents)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .perfetto.protos.ObservableEvents.DataSourceInstanceStateChange instance_state_changes = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_instance_state_changes_size()); i < n; i++) {
    const auto& repfield = this->_internal_instance_state_changes(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  cached_has_bits = _has_bits_[0];
  // optional bool all_data_sources_started = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(2, this->_internal_all_data_sources_started(), target);
  }

  // optional .perfetto.protos.ObservableEvents.CloneTriggerHit clone_trigger_hit = 3;
  if (cached_has_bits & 0x00000001u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::clone_trigger_hit(this),
        _Internal::clone_trigger_hit(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.ObservableEvents)
  return target;
}

size_t ObservableEvents::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ObservableEvents)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .perfetto.protos.ObservableEvents.DataSourceInstanceStateChange instance_state_changes = 1;
  total_size += 1UL * this->_internal_instance_state_changes_size();
  for (const auto& msg : this->instance_state_changes_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional .perfetto.protos.ObservableEvents.CloneTriggerHit clone_trigger_hit = 3;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *clone_trigger_hit_);
    }

    // optional bool all_data_sources_started = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + 1;
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::_pbi::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObservableEvents::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::_pbi::DownCast<const ObservableEvents*>(
      &from));
}

void ObservableEvents::MergeFrom(const ObservableEvents& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ObservableEvents)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  instance_state_changes_.MergeFrom(from.instance_state_changes_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_clone_trigger_hit()->::perfetto::protos::ObservableEvents_CloneTriggerHit::MergeFrom(from._internal_clone_trigger_hit());
    }
    if (cached_has_bits & 0x00000002u) {
      all_data_sources_started_ = from.all_data_sources_started_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void ObservableEvents::CopyFrom(const ObservableEvents& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ObservableEvents)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObservableEvents::IsInitialized() const {
  return true;
}

void ObservableEvents::InternalSwap(ObservableEvents* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  instance_state_changes_.InternalSwap(&other->instance_state_changes_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ObservableEvents, all_data_sources_started_)
      + sizeof(ObservableEvents::all_data_sources_started_)
      - PROTOBUF_FIELD_OFFSET(ObservableEvents, clone_trigger_hit_)>(
          reinterpret_cast<char*>(&clone_trigger_hit_),
          reinterpret_cast<char*>(&other->clone_trigger_hit_));
}

std::string ObservableEvents::GetTypeName() const {
  return "perfetto.protos.ObservableEvents";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange*
Arena::CreateMaybeMessage< ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::ObservableEvents_DataSourceInstanceStateChange >(arena);
}
template<> PROTOBUF_NOINLINE ::perfetto::protos::ObservableEvents_CloneTriggerHit*
Arena::CreateMaybeMessage< ::perfetto::protos::ObservableEvents_CloneTriggerHit >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::ObservableEvents_CloneTriggerHit >(arena);
}
template<> PROTOBUF_NOINLINE ::perfetto::protos::ObservableEvents*
Arena::CreateMaybeMessage< ::perfetto::protos::ObservableEvents >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::ObservableEvents >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
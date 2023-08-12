// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ukm/report.proto

#include "ukm/report.pb.h"

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

namespace ukm {
PROTOBUF_CONSTEXPR Report_SourceCounts::Report_SourceCounts(
    ::_pbi::ConstantInitialized)
  : observed_(0)
  , navigation_sources_(0)
  , unmatched_sources_(0)
  , carryover_sources_(0)
  , deferred_sources_(0)
  , entryless_sources_(0)
  , pruned_sources_age_seconds_(0){}
struct Report_SourceCountsDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Report_SourceCountsDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~Report_SourceCountsDefaultTypeInternal() {}
  union {
    Report_SourceCounts _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT_WITH_PTR PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Report_SourceCountsDefaultTypeInternal _Report_SourceCounts_default_instance_;
PROTOBUF_CONSTEXPR Report::Report(
    ::_pbi::ConstantInitialized)
  : sources_()
  , entries_()
  , aggregates_()
  , system_profile_(nullptr)
  , source_counts_(nullptr)
  , user_demographics_(nullptr)
  , client_id_(uint64_t{0u})
  , session_id_(0)
  , report_id_(0)
  , is_continuous_(false)
  , log_rotation_reason_(0)

  , product_(0)
{}
struct ReportDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ReportDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ReportDefaultTypeInternal() {}
  union {
    Report _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT_WITH_PTR PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ReportDefaultTypeInternal _Report_default_instance_;
}  // namespace ukm
namespace ukm {
bool Report_LogRotationReason_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> Report_LogRotationReason_strings[4] = {};

static const char Report_LogRotationReason_names[] =
  "BACKGROUNDED"
  "SCHEDULED_ROTATION"
  "SHUTDOWN"
  "UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry Report_LogRotationReason_entries[] = {
  { {Report_LogRotationReason_names + 0, 12}, 2 },
  { {Report_LogRotationReason_names + 12, 18}, 1 },
  { {Report_LogRotationReason_names + 30, 8}, 3 },
  { {Report_LogRotationReason_names + 38, 7}, 0 },
};

static const int Report_LogRotationReason_entries_by_number[] = {
  3, // 0 -> UNKNOWN
  1, // 1 -> SCHEDULED_ROTATION
  0, // 2 -> BACKGROUNDED
  2, // 3 -> SHUTDOWN
};

const std::string& Report_LogRotationReason_Name(
    Report_LogRotationReason value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          Report_LogRotationReason_entries,
          Report_LogRotationReason_entries_by_number,
          4, Report_LogRotationReason_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      Report_LogRotationReason_entries,
      Report_LogRotationReason_entries_by_number,
      4, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     Report_LogRotationReason_strings[idx].get();
}
bool Report_LogRotationReason_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Report_LogRotationReason* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      Report_LogRotationReason_entries, 4, name, &int_value);
  if (success) {
    *value = static_cast<Report_LogRotationReason>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Report_LogRotationReason Report::UNKNOWN;
constexpr Report_LogRotationReason Report::SCHEDULED_ROTATION;
constexpr Report_LogRotationReason Report::BACKGROUNDED;
constexpr Report_LogRotationReason Report::SHUTDOWN;
constexpr Report_LogRotationReason Report::LogRotationReason_MIN;
constexpr Report_LogRotationReason Report::LogRotationReason_MAX;
constexpr int Report::LogRotationReason_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class Report_SourceCounts::_Internal {
 public:
  using HasBits = decltype(std::declval<Report_SourceCounts>()._has_bits_);
  static void set_has_observed(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_navigation_sources(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_unmatched_sources(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_carryover_sources(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_deferred_sources(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_entryless_sources(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_pruned_sources_age_seconds(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
};

Report_SourceCounts::Report_SourceCounts(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:ukm.Report.SourceCounts)
}
Report_SourceCounts::Report_SourceCounts(const Report_SourceCounts& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::memcpy(&observed_, &from.observed_,
    static_cast<size_t>(reinterpret_cast<char*>(&pruned_sources_age_seconds_) -
    reinterpret_cast<char*>(&observed_)) + sizeof(pruned_sources_age_seconds_));
  // @@protoc_insertion_point(copy_constructor:ukm.Report.SourceCounts)
}

inline void Report_SourceCounts::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&observed_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&pruned_sources_age_seconds_) -
    reinterpret_cast<char*>(&observed_)) + sizeof(pruned_sources_age_seconds_));
}

Report_SourceCounts::~Report_SourceCounts() {
  // @@protoc_insertion_point(destructor:ukm.Report.SourceCounts)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<std::string>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Report_SourceCounts::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Report_SourceCounts::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Report_SourceCounts::Clear() {
// @@protoc_insertion_point(message_clear_start:ukm.Report.SourceCounts)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000007fu) {
    ::memset(&observed_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&pruned_sources_age_seconds_) -
        reinterpret_cast<char*>(&observed_)) + sizeof(pruned_sources_age_seconds_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* Report_SourceCounts::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional int32 observed = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _Internal::set_has_observed(&has_bits);
          observed_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 navigation_sources = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _Internal::set_has_navigation_sources(&has_bits);
          navigation_sources_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 unmatched_sources = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _Internal::set_has_unmatched_sources(&has_bits);
          unmatched_sources_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 carryover_sources = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _Internal::set_has_carryover_sources(&has_bits);
          carryover_sources_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 deferred_sources = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _Internal::set_has_deferred_sources(&has_bits);
          deferred_sources_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 entryless_sources = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          _Internal::set_has_entryless_sources(&has_bits);
          entryless_sources_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 pruned_sources_age_seconds = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 56)) {
          _Internal::set_has_pruned_sources_age_seconds(&has_bits);
          pruned_sources_age_seconds_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

uint8_t* Report_SourceCounts::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ukm.Report.SourceCounts)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 observed = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_observed(), target);
  }

  // optional int32 navigation_sources = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_navigation_sources(), target);
  }

  // optional int32 unmatched_sources = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_unmatched_sources(), target);
  }

  // optional int32 carryover_sources = 4;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(4, this->_internal_carryover_sources(), target);
  }

  // optional int32 deferred_sources = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(5, this->_internal_deferred_sources(), target);
  }

  // optional int32 entryless_sources = 6;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(6, this->_internal_entryless_sources(), target);
  }

  // optional int32 pruned_sources_age_seconds = 7;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(7, this->_internal_pruned_sources_age_seconds(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ukm.Report.SourceCounts)
  return target;
}

size_t Report_SourceCounts::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ukm.Report.SourceCounts)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000007fu) {
    // optional int32 observed = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_observed());
    }

    // optional int32 navigation_sources = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_navigation_sources());
    }

    // optional int32 unmatched_sources = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_unmatched_sources());
    }

    // optional int32 carryover_sources = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_carryover_sources());
    }

    // optional int32 deferred_sources = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_deferred_sources());
    }

    // optional int32 entryless_sources = 6;
    if (cached_has_bits & 0x00000020u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_entryless_sources());
    }

    // optional int32 pruned_sources_age_seconds = 7;
    if (cached_has_bits & 0x00000040u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_pruned_sources_age_seconds());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::_pbi::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Report_SourceCounts::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::_pbi::DownCast<const Report_SourceCounts*>(
      &from));
}

void Report_SourceCounts::MergeFrom(const Report_SourceCounts& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ukm.Report.SourceCounts)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000007fu) {
    if (cached_has_bits & 0x00000001u) {
      observed_ = from.observed_;
    }
    if (cached_has_bits & 0x00000002u) {
      navigation_sources_ = from.navigation_sources_;
    }
    if (cached_has_bits & 0x00000004u) {
      unmatched_sources_ = from.unmatched_sources_;
    }
    if (cached_has_bits & 0x00000008u) {
      carryover_sources_ = from.carryover_sources_;
    }
    if (cached_has_bits & 0x00000010u) {
      deferred_sources_ = from.deferred_sources_;
    }
    if (cached_has_bits & 0x00000020u) {
      entryless_sources_ = from.entryless_sources_;
    }
    if (cached_has_bits & 0x00000040u) {
      pruned_sources_age_seconds_ = from.pruned_sources_age_seconds_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void Report_SourceCounts::CopyFrom(const Report_SourceCounts& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ukm.Report.SourceCounts)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Report_SourceCounts::IsInitialized() const {
  return true;
}

void Report_SourceCounts::InternalSwap(Report_SourceCounts* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Report_SourceCounts, pruned_sources_age_seconds_)
      + sizeof(Report_SourceCounts::pruned_sources_age_seconds_)
      - PROTOBUF_FIELD_OFFSET(Report_SourceCounts, observed_)>(
          reinterpret_cast<char*>(&observed_),
          reinterpret_cast<char*>(&other->observed_));
}

std::string Report_SourceCounts::GetTypeName() const {
  return "ukm.Report.SourceCounts";
}


// ===================================================================

class Report::_Internal {
 public:
  using HasBits = decltype(std::declval<Report>()._has_bits_);
  static void set_has_client_id(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_product(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_session_id(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_report_id(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_is_continuous(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_log_rotation_reason(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static const ::metrics::SystemProfileProto& system_profile(const Report* msg);
  static void set_has_system_profile(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::metrics::UserDemographicsProto& user_demographics(const Report* msg);
  static void set_has_user_demographics(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static const ::ukm::Report_SourceCounts& source_counts(const Report* msg);
  static void set_has_source_counts(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::metrics::SystemProfileProto&
Report::_Internal::system_profile(const Report* msg) {
  return *msg->system_profile_;
}
const ::metrics::UserDemographicsProto&
Report::_Internal::user_demographics(const Report* msg) {
  return *msg->user_demographics_;
}
const ::ukm::Report_SourceCounts&
Report::_Internal::source_counts(const Report* msg) {
  return *msg->source_counts_;
}
void Report::clear_system_profile() {
  if (system_profile_ != nullptr) system_profile_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
void Report::clear_user_demographics() {
  if (user_demographics_ != nullptr) user_demographics_->Clear();
  _has_bits_[0] &= ~0x00000004u;
}
void Report::clear_sources() {
  sources_.Clear();
}
void Report::clear_entries() {
  entries_.Clear();
}
void Report::clear_aggregates() {
  aggregates_.Clear();
}
Report::Report(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned),
  sources_(arena),
  entries_(arena),
  aggregates_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:ukm.Report)
}
Report::Report(const Report& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_),
      sources_(from.sources_),
      entries_(from.entries_),
      aggregates_(from.aggregates_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  if (from._internal_has_system_profile()) {
    system_profile_ = new ::metrics::SystemProfileProto(*from.system_profile_);
  } else {
    system_profile_ = nullptr;
  }
  if (from._internal_has_source_counts()) {
    source_counts_ = new ::ukm::Report_SourceCounts(*from.source_counts_);
  } else {
    source_counts_ = nullptr;
  }
  if (from._internal_has_user_demographics()) {
    user_demographics_ = new ::metrics::UserDemographicsProto(*from.user_demographics_);
  } else {
    user_demographics_ = nullptr;
  }
  ::memcpy(&client_id_, &from.client_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&product_) -
    reinterpret_cast<char*>(&client_id_)) + sizeof(product_));
  // @@protoc_insertion_point(copy_constructor:ukm.Report)
}

inline void Report::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&system_profile_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&product_) -
    reinterpret_cast<char*>(&system_profile_)) + sizeof(product_));
}

Report::~Report() {
  // @@protoc_insertion_point(destructor:ukm.Report)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<std::string>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Report::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete system_profile_;
  if (this != internal_default_instance()) delete source_counts_;
  if (this != internal_default_instance()) delete user_demographics_;
}

void Report::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Report::Clear() {
// @@protoc_insertion_point(message_clear_start:ukm.Report)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sources_.Clear();
  entries_.Clear();
  aggregates_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(system_profile_ != nullptr);
      system_profile_->Clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(source_counts_ != nullptr);
      source_counts_->Clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(user_demographics_ != nullptr);
      user_demographics_->Clear();
    }
  }
  if (cached_has_bits & 0x000000f8u) {
    ::memset(&client_id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&log_rotation_reason_) -
        reinterpret_cast<char*>(&client_id_)) + sizeof(log_rotation_reason_));
  }
  product_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* Report::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional fixed64 client_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          _Internal::set_has_client_id(&has_bits);
          client_id_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<uint64_t>(ptr);
          ptr += sizeof(uint64_t);
        } else
          goto handle_unusual;
        continue;
      // optional .metrics.SystemProfileProto system_profile = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_system_profile(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .ukm.Source sources = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_sources(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated .ukm.Entry entries = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_entries(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else
          goto handle_unusual;
        continue;
      // optional int32 session_id = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _Internal::set_has_session_id(&has_bits);
          session_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 report_id = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          _Internal::set_has_report_id(&has_bits);
          report_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .ukm.Aggregate aggregates = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_aggregates(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
        } else
          goto handle_unusual;
        continue;
      // optional bool is_continuous = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 64)) {
          _Internal::set_has_is_continuous(&has_bits);
          is_continuous_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional .ukm.Report.LogRotationReason log_rotation_reason = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 72)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::ukm::Report_LogRotationReason_IsValid(val))) {
            _internal_set_log_rotation_reason(static_cast<::ukm::Report_LogRotationReason>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(9, val, mutable_unknown_fields());
          }
        } else
          goto handle_unusual;
        continue;
      // optional .ukm.Report.SourceCounts source_counts = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 82)) {
          ptr = ctx->ParseMessage(_internal_mutable_source_counts(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional .metrics.UserDemographicsProto user_demographics = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 90)) {
          ptr = ctx->ParseMessage(_internal_mutable_user_demographics(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional .metrics.ChromeUserMetricsExtension.Product product = 12 [default = CHROME];
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 96)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::metrics::ChromeUserMetricsExtension_Product_IsValid(val))) {
            _internal_set_product(static_cast<::metrics::ChromeUserMetricsExtension_Product>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(12, val, mutable_unknown_fields());
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

uint8_t* Report::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ukm.Report)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional fixed64 client_id = 1;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFixed64ToArray(1, this->_internal_client_id(), target);
  }

  // optional .metrics.SystemProfileProto system_profile = 2;
  if (cached_has_bits & 0x00000001u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::system_profile(this),
        _Internal::system_profile(this).GetCachedSize(), target, stream);
  }

  // repeated .ukm.Source sources = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_sources_size()); i < n; i++) {
    const auto& repfield = this->_internal_sources(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  // repeated .ukm.Entry entries = 4;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_entries_size()); i < n; i++) {
    const auto& repfield = this->_internal_entries(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(4, repfield, repfield.GetCachedSize(), target, stream);
  }

  // optional int32 session_id = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(5, this->_internal_session_id(), target);
  }

  // optional int32 report_id = 6;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(6, this->_internal_report_id(), target);
  }

  // repeated .ukm.Aggregate aggregates = 7;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_aggregates_size()); i < n; i++) {
    const auto& repfield = this->_internal_aggregates(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(7, repfield, repfield.GetCachedSize(), target, stream);
  }

  // optional bool is_continuous = 8;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(8, this->_internal_is_continuous(), target);
  }

  // optional .ukm.Report.LogRotationReason log_rotation_reason = 9;
  if (cached_has_bits & 0x00000080u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      9, this->_internal_log_rotation_reason(), target);
  }

  // optional .ukm.Report.SourceCounts source_counts = 10;
  if (cached_has_bits & 0x00000002u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(10, _Internal::source_counts(this),
        _Internal::source_counts(this).GetCachedSize(), target, stream);
  }

  // optional .metrics.UserDemographicsProto user_demographics = 11;
  if (cached_has_bits & 0x00000004u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(11, _Internal::user_demographics(this),
        _Internal::user_demographics(this).GetCachedSize(), target, stream);
  }

  // optional .metrics.ChromeUserMetricsExtension.Product product = 12 [default = CHROME];
  if (cached_has_bits & 0x00000100u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      12, this->_internal_product(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ukm.Report)
  return target;
}

size_t Report::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ukm.Report)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .ukm.Source sources = 3;
  total_size += 1UL * this->_internal_sources_size();
  for (const auto& msg : this->sources_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .ukm.Entry entries = 4;
  total_size += 1UL * this->_internal_entries_size();
  for (const auto& msg : this->entries_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .ukm.Aggregate aggregates = 7;
  total_size += 1UL * this->_internal_aggregates_size();
  for (const auto& msg : this->aggregates_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    // optional .metrics.SystemProfileProto system_profile = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *system_profile_);
    }

    // optional .ukm.Report.SourceCounts source_counts = 10;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *source_counts_);
    }

    // optional .metrics.UserDemographicsProto user_demographics = 11;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *user_demographics_);
    }

    // optional fixed64 client_id = 1;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 + 8;
    }

    // optional int32 session_id = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_session_id());
    }

    // optional int32 report_id = 6;
    if (cached_has_bits & 0x00000020u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_report_id());
    }

    // optional bool is_continuous = 8;
    if (cached_has_bits & 0x00000040u) {
      total_size += 1 + 1;
    }

    // optional .ukm.Report.LogRotationReason log_rotation_reason = 9;
    if (cached_has_bits & 0x00000080u) {
      total_size += 1 +
        ::_pbi::WireFormatLite::EnumSize(this->_internal_log_rotation_reason());
    }

  }
  // optional .metrics.ChromeUserMetricsExtension.Product product = 12 [default = CHROME];
  if (cached_has_bits & 0x00000100u) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_product());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::_pbi::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Report::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::_pbi::DownCast<const Report*>(
      &from));
}

void Report::MergeFrom(const Report& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ukm.Report)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  sources_.MergeFrom(from.sources_);
  entries_.MergeFrom(from.entries_);
  aggregates_.MergeFrom(from.aggregates_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_system_profile()->::metrics::SystemProfileProto::MergeFrom(from._internal_system_profile());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_mutable_source_counts()->::ukm::Report_SourceCounts::MergeFrom(from._internal_source_counts());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_mutable_user_demographics()->::metrics::UserDemographicsProto::MergeFrom(from._internal_user_demographics());
    }
    if (cached_has_bits & 0x00000008u) {
      client_id_ = from.client_id_;
    }
    if (cached_has_bits & 0x00000010u) {
      session_id_ = from.session_id_;
    }
    if (cached_has_bits & 0x00000020u) {
      report_id_ = from.report_id_;
    }
    if (cached_has_bits & 0x00000040u) {
      is_continuous_ = from.is_continuous_;
    }
    if (cached_has_bits & 0x00000080u) {
      log_rotation_reason_ = from.log_rotation_reason_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x00000100u) {
    _internal_set_product(from._internal_product());
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void Report::CopyFrom(const Report& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ukm.Report)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Report::IsInitialized() const {
  return true;
}

void Report::InternalSwap(Report* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  sources_.InternalSwap(&other->sources_);
  entries_.InternalSwap(&other->entries_);
  aggregates_.InternalSwap(&other->aggregates_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Report, product_)
      + sizeof(Report::product_)
      - PROTOBUF_FIELD_OFFSET(Report, system_profile_)>(
          reinterpret_cast<char*>(&system_profile_),
          reinterpret_cast<char*>(&other->system_profile_));
}

std::string Report::GetTypeName() const {
  return "ukm.Report";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace ukm
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ukm::Report_SourceCounts*
Arena::CreateMaybeMessage< ::ukm::Report_SourceCounts >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ukm::Report_SourceCounts >(arena);
}
template<> PROTOBUF_NOINLINE ::ukm::Report*
Arena::CreateMaybeMessage< ::ukm::Report >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ukm::Report >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
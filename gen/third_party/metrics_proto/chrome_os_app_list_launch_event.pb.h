// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chrome_os_app_list_launch_event.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_chrome_5fos_5fapp_5flist_5flaunch_5fevent_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_chrome_5fos_5fapp_5flist_5flaunch_5fevent_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_chrome_5fos_5fapp_5flist_5flaunch_5fevent_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_chrome_5fos_5fapp_5flist_5flaunch_5fevent_2eproto {
  static const uint32_t offsets[];
};
namespace metrics {
class ChromeOSAppListLaunchEventProto;
struct ChromeOSAppListLaunchEventProtoDefaultTypeInternal;
extern ChromeOSAppListLaunchEventProtoDefaultTypeInternal _ChromeOSAppListLaunchEventProto_default_instance_;
}  // namespace metrics
PROTOBUF_NAMESPACE_OPEN
template<> ::metrics::ChromeOSAppListLaunchEventProto* Arena::CreateMaybeMessage<::metrics::ChromeOSAppListLaunchEventProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace metrics {

enum ChromeOSAppListLaunchEventProto_LaunchType : int {
  ChromeOSAppListLaunchEventProto_LaunchType_LAUNCH_TYPE_UNSPECIFIED = 0,
  ChromeOSAppListLaunchEventProto_LaunchType_APP_TILES = 1,
  ChromeOSAppListLaunchEventProto_LaunchType_RESULTS_LIST = 2
};
bool ChromeOSAppListLaunchEventProto_LaunchType_IsValid(int value);
constexpr ChromeOSAppListLaunchEventProto_LaunchType ChromeOSAppListLaunchEventProto_LaunchType_LaunchType_MIN = ChromeOSAppListLaunchEventProto_LaunchType_LAUNCH_TYPE_UNSPECIFIED;
constexpr ChromeOSAppListLaunchEventProto_LaunchType ChromeOSAppListLaunchEventProto_LaunchType_LaunchType_MAX = ChromeOSAppListLaunchEventProto_LaunchType_RESULTS_LIST;
constexpr int ChromeOSAppListLaunchEventProto_LaunchType_LaunchType_ARRAYSIZE = ChromeOSAppListLaunchEventProto_LaunchType_LaunchType_MAX + 1;

const std::string& ChromeOSAppListLaunchEventProto_LaunchType_Name(ChromeOSAppListLaunchEventProto_LaunchType value);
template<typename T>
inline const std::string& ChromeOSAppListLaunchEventProto_LaunchType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ChromeOSAppListLaunchEventProto_LaunchType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ChromeOSAppListLaunchEventProto_LaunchType_Name.");
  return ChromeOSAppListLaunchEventProto_LaunchType_Name(static_cast<ChromeOSAppListLaunchEventProto_LaunchType>(enum_t_value));
}
bool ChromeOSAppListLaunchEventProto_LaunchType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ChromeOSAppListLaunchEventProto_LaunchType* value);
enum ChromeOSAppListLaunchEventProto_SearchProviderType : int {
  ChromeOSAppListLaunchEventProto_SearchProviderType_PROVIDER_UNSPECIFIED = 0,
  ChromeOSAppListLaunchEventProto_SearchProviderType_OMNIBOX = 1,
  ChromeOSAppListLaunchEventProto_SearchProviderType_ZERO_STATE_FILE = 2,
  ChromeOSAppListLaunchEventProto_SearchProviderType_DRIVE_QUICK_ACCESS = 3
};
bool ChromeOSAppListLaunchEventProto_SearchProviderType_IsValid(int value);
constexpr ChromeOSAppListLaunchEventProto_SearchProviderType ChromeOSAppListLaunchEventProto_SearchProviderType_SearchProviderType_MIN = ChromeOSAppListLaunchEventProto_SearchProviderType_PROVIDER_UNSPECIFIED;
constexpr ChromeOSAppListLaunchEventProto_SearchProviderType ChromeOSAppListLaunchEventProto_SearchProviderType_SearchProviderType_MAX = ChromeOSAppListLaunchEventProto_SearchProviderType_DRIVE_QUICK_ACCESS;
constexpr int ChromeOSAppListLaunchEventProto_SearchProviderType_SearchProviderType_ARRAYSIZE = ChromeOSAppListLaunchEventProto_SearchProviderType_SearchProviderType_MAX + 1;

const std::string& ChromeOSAppListLaunchEventProto_SearchProviderType_Name(ChromeOSAppListLaunchEventProto_SearchProviderType value);
template<typename T>
inline const std::string& ChromeOSAppListLaunchEventProto_SearchProviderType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ChromeOSAppListLaunchEventProto_SearchProviderType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ChromeOSAppListLaunchEventProto_SearchProviderType_Name.");
  return ChromeOSAppListLaunchEventProto_SearchProviderType_Name(static_cast<ChromeOSAppListLaunchEventProto_SearchProviderType>(enum_t_value));
}
bool ChromeOSAppListLaunchEventProto_SearchProviderType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ChromeOSAppListLaunchEventProto_SearchProviderType* value);
// ===================================================================

class ChromeOSAppListLaunchEventProto final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:metrics.ChromeOSAppListLaunchEventProto) */ {
 public:
  inline ChromeOSAppListLaunchEventProto() : ChromeOSAppListLaunchEventProto(nullptr) {}
  ~ChromeOSAppListLaunchEventProto() override;
  explicit PROTOBUF_CONSTEXPR ChromeOSAppListLaunchEventProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ChromeOSAppListLaunchEventProto(const ChromeOSAppListLaunchEventProto& from);
  ChromeOSAppListLaunchEventProto(ChromeOSAppListLaunchEventProto&& from) noexcept
    : ChromeOSAppListLaunchEventProto() {
    *this = ::std::move(from);
  }

  inline ChromeOSAppListLaunchEventProto& operator=(const ChromeOSAppListLaunchEventProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline ChromeOSAppListLaunchEventProto& operator=(ChromeOSAppListLaunchEventProto&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString);
  }
  inline std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<std::string>();
  }

  static const ChromeOSAppListLaunchEventProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const ChromeOSAppListLaunchEventProto* internal_default_instance() {
    return reinterpret_cast<const ChromeOSAppListLaunchEventProto*>(
               &_ChromeOSAppListLaunchEventProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ChromeOSAppListLaunchEventProto& a, ChromeOSAppListLaunchEventProto& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(ChromeOSAppListLaunchEventProto* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ChromeOSAppListLaunchEventProto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ChromeOSAppListLaunchEventProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ChromeOSAppListLaunchEventProto>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const ChromeOSAppListLaunchEventProto& from);
  void MergeFrom(const ChromeOSAppListLaunchEventProto& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ChromeOSAppListLaunchEventProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "metrics.ChromeOSAppListLaunchEventProto";
  }
  protected:
  explicit ChromeOSAppListLaunchEventProto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  typedef ChromeOSAppListLaunchEventProto_LaunchType LaunchType;
  static constexpr LaunchType LAUNCH_TYPE_UNSPECIFIED =
    ChromeOSAppListLaunchEventProto_LaunchType_LAUNCH_TYPE_UNSPECIFIED;
  static constexpr LaunchType APP_TILES =
    ChromeOSAppListLaunchEventProto_LaunchType_APP_TILES;
  static constexpr LaunchType RESULTS_LIST =
    ChromeOSAppListLaunchEventProto_LaunchType_RESULTS_LIST;
  static inline bool LaunchType_IsValid(int value) {
    return ChromeOSAppListLaunchEventProto_LaunchType_IsValid(value);
  }
  static constexpr LaunchType LaunchType_MIN =
    ChromeOSAppListLaunchEventProto_LaunchType_LaunchType_MIN;
  static constexpr LaunchType LaunchType_MAX =
    ChromeOSAppListLaunchEventProto_LaunchType_LaunchType_MAX;
  static constexpr int LaunchType_ARRAYSIZE =
    ChromeOSAppListLaunchEventProto_LaunchType_LaunchType_ARRAYSIZE;
  template<typename T>
  static inline const std::string& LaunchType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, LaunchType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function LaunchType_Name.");
    return ChromeOSAppListLaunchEventProto_LaunchType_Name(enum_t_value);
  }
  static inline bool LaunchType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      LaunchType* value) {
    return ChromeOSAppListLaunchEventProto_LaunchType_Parse(name, value);
  }

  typedef ChromeOSAppListLaunchEventProto_SearchProviderType SearchProviderType;
  static constexpr SearchProviderType PROVIDER_UNSPECIFIED =
    ChromeOSAppListLaunchEventProto_SearchProviderType_PROVIDER_UNSPECIFIED;
  static constexpr SearchProviderType OMNIBOX =
    ChromeOSAppListLaunchEventProto_SearchProviderType_OMNIBOX;
  static constexpr SearchProviderType ZERO_STATE_FILE =
    ChromeOSAppListLaunchEventProto_SearchProviderType_ZERO_STATE_FILE;
  static constexpr SearchProviderType DRIVE_QUICK_ACCESS =
    ChromeOSAppListLaunchEventProto_SearchProviderType_DRIVE_QUICK_ACCESS;
  static inline bool SearchProviderType_IsValid(int value) {
    return ChromeOSAppListLaunchEventProto_SearchProviderType_IsValid(value);
  }
  static constexpr SearchProviderType SearchProviderType_MIN =
    ChromeOSAppListLaunchEventProto_SearchProviderType_SearchProviderType_MIN;
  static constexpr SearchProviderType SearchProviderType_MAX =
    ChromeOSAppListLaunchEventProto_SearchProviderType_SearchProviderType_MAX;
  static constexpr int SearchProviderType_ARRAYSIZE =
    ChromeOSAppListLaunchEventProto_SearchProviderType_SearchProviderType_ARRAYSIZE;
  template<typename T>
  static inline const std::string& SearchProviderType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, SearchProviderType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function SearchProviderType_Name.");
    return ChromeOSAppListLaunchEventProto_SearchProviderType_Name(enum_t_value);
  }
  static inline bool SearchProviderType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      SearchProviderType* value) {
    return ChromeOSAppListLaunchEventProto_SearchProviderType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kRecurrenceRankerUserIdFieldNumber = 1,
    kLaunchTypeFieldNumber = 2,
    kHourFieldNumber = 3,
    kHashedTargetFieldNumber = 5,
    kHashedQueryFieldNumber = 6,
    kSearchQueryLengthFieldNumber = 4,
    kSearchProviderTypeFieldNumber = 9,
    kHashedDomainFieldNumber = 7,
    kHashedAppFieldNumber = 8,
  };
  // optional fixed64 recurrence_ranker_user_id = 1;
  bool has_recurrence_ranker_user_id() const;
  private:
  bool _internal_has_recurrence_ranker_user_id() const;
  public:
  void clear_recurrence_ranker_user_id();
  uint64_t recurrence_ranker_user_id() const;
  void set_recurrence_ranker_user_id(uint64_t value);
  private:
  uint64_t _internal_recurrence_ranker_user_id() const;
  void _internal_set_recurrence_ranker_user_id(uint64_t value);
  public:

  // optional .metrics.ChromeOSAppListLaunchEventProto.LaunchType launch_type = 2;
  bool has_launch_type() const;
  private:
  bool _internal_has_launch_type() const;
  public:
  void clear_launch_type();
  ::metrics::ChromeOSAppListLaunchEventProto_LaunchType launch_type() const;
  void set_launch_type(::metrics::ChromeOSAppListLaunchEventProto_LaunchType value);
  private:
  ::metrics::ChromeOSAppListLaunchEventProto_LaunchType _internal_launch_type() const;
  void _internal_set_launch_type(::metrics::ChromeOSAppListLaunchEventProto_LaunchType value);
  public:

  // optional int32 hour = 3;
  bool has_hour() const;
  private:
  bool _internal_has_hour() const;
  public:
  void clear_hour();
  int32_t hour() const;
  void set_hour(int32_t value);
  private:
  int32_t _internal_hour() const;
  void _internal_set_hour(int32_t value);
  public:

  // optional fixed64 hashed_target = 5;
  bool has_hashed_target() const;
  private:
  bool _internal_has_hashed_target() const;
  public:
  void clear_hashed_target();
  uint64_t hashed_target() const;
  void set_hashed_target(uint64_t value);
  private:
  uint64_t _internal_hashed_target() const;
  void _internal_set_hashed_target(uint64_t value);
  public:

  // optional fixed64 hashed_query = 6;
  bool has_hashed_query() const;
  private:
  bool _internal_has_hashed_query() const;
  public:
  void clear_hashed_query();
  uint64_t hashed_query() const;
  void set_hashed_query(uint64_t value);
  private:
  uint64_t _internal_hashed_query() const;
  void _internal_set_hashed_query(uint64_t value);
  public:

  // optional int32 search_query_length = 4;
  bool has_search_query_length() const;
  private:
  bool _internal_has_search_query_length() const;
  public:
  void clear_search_query_length();
  int32_t search_query_length() const;
  void set_search_query_length(int32_t value);
  private:
  int32_t _internal_search_query_length() const;
  void _internal_set_search_query_length(int32_t value);
  public:

  // optional .metrics.ChromeOSAppListLaunchEventProto.SearchProviderType search_provider_type = 9;
  bool has_search_provider_type() const;
  private:
  bool _internal_has_search_provider_type() const;
  public:
  void clear_search_provider_type();
  ::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType search_provider_type() const;
  void set_search_provider_type(::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType value);
  private:
  ::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType _internal_search_provider_type() const;
  void _internal_set_search_provider_type(::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType value);
  public:

  // optional fixed64 hashed_domain = 7;
  bool has_hashed_domain() const;
  private:
  bool _internal_has_hashed_domain() const;
  public:
  void clear_hashed_domain();
  uint64_t hashed_domain() const;
  void set_hashed_domain(uint64_t value);
  private:
  uint64_t _internal_hashed_domain() const;
  void _internal_set_hashed_domain(uint64_t value);
  public:

  // optional fixed64 hashed_app = 8;
  bool has_hashed_app() const;
  private:
  bool _internal_has_hashed_app() const;
  public:
  void clear_hashed_app();
  uint64_t hashed_app() const;
  void set_hashed_app(uint64_t value);
  private:
  uint64_t _internal_hashed_app() const;
  void _internal_set_hashed_app(uint64_t value);
  public:

  // @@protoc_insertion_point(class_scope:metrics.ChromeOSAppListLaunchEventProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  uint64_t recurrence_ranker_user_id_;
  int launch_type_;
  int32_t hour_;
  uint64_t hashed_target_;
  uint64_t hashed_query_;
  int32_t search_query_length_;
  int search_provider_type_;
  uint64_t hashed_domain_;
  uint64_t hashed_app_;
  friend struct ::TableStruct_chrome_5fos_5fapp_5flist_5flaunch_5fevent_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChromeOSAppListLaunchEventProto

// optional fixed64 recurrence_ranker_user_id = 1;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_recurrence_ranker_user_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_recurrence_ranker_user_id() const {
  return _internal_has_recurrence_ranker_user_id();
}
inline void ChromeOSAppListLaunchEventProto::clear_recurrence_ranker_user_id() {
  recurrence_ranker_user_id_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000001u;
}
inline uint64_t ChromeOSAppListLaunchEventProto::_internal_recurrence_ranker_user_id() const {
  return recurrence_ranker_user_id_;
}
inline uint64_t ChromeOSAppListLaunchEventProto::recurrence_ranker_user_id() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.recurrence_ranker_user_id)
  return _internal_recurrence_ranker_user_id();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_recurrence_ranker_user_id(uint64_t value) {
  _has_bits_[0] |= 0x00000001u;
  recurrence_ranker_user_id_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_recurrence_ranker_user_id(uint64_t value) {
  _internal_set_recurrence_ranker_user_id(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.recurrence_ranker_user_id)
}

// optional .metrics.ChromeOSAppListLaunchEventProto.LaunchType launch_type = 2;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_launch_type() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_launch_type() const {
  return _internal_has_launch_type();
}
inline void ChromeOSAppListLaunchEventProto::clear_launch_type() {
  launch_type_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::metrics::ChromeOSAppListLaunchEventProto_LaunchType ChromeOSAppListLaunchEventProto::_internal_launch_type() const {
  return static_cast< ::metrics::ChromeOSAppListLaunchEventProto_LaunchType >(launch_type_);
}
inline ::metrics::ChromeOSAppListLaunchEventProto_LaunchType ChromeOSAppListLaunchEventProto::launch_type() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.launch_type)
  return _internal_launch_type();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_launch_type(::metrics::ChromeOSAppListLaunchEventProto_LaunchType value) {
  assert(::metrics::ChromeOSAppListLaunchEventProto_LaunchType_IsValid(value));
  _has_bits_[0] |= 0x00000002u;
  launch_type_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_launch_type(::metrics::ChromeOSAppListLaunchEventProto_LaunchType value) {
  _internal_set_launch_type(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.launch_type)
}

// optional int32 hour = 3;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_hour() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_hour() const {
  return _internal_has_hour();
}
inline void ChromeOSAppListLaunchEventProto::clear_hour() {
  hour_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline int32_t ChromeOSAppListLaunchEventProto::_internal_hour() const {
  return hour_;
}
inline int32_t ChromeOSAppListLaunchEventProto::hour() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.hour)
  return _internal_hour();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_hour(int32_t value) {
  _has_bits_[0] |= 0x00000004u;
  hour_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_hour(int32_t value) {
  _internal_set_hour(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.hour)
}

// optional int32 search_query_length = 4;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_search_query_length() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_search_query_length() const {
  return _internal_has_search_query_length();
}
inline void ChromeOSAppListLaunchEventProto::clear_search_query_length() {
  search_query_length_ = 0;
  _has_bits_[0] &= ~0x00000020u;
}
inline int32_t ChromeOSAppListLaunchEventProto::_internal_search_query_length() const {
  return search_query_length_;
}
inline int32_t ChromeOSAppListLaunchEventProto::search_query_length() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.search_query_length)
  return _internal_search_query_length();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_search_query_length(int32_t value) {
  _has_bits_[0] |= 0x00000020u;
  search_query_length_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_search_query_length(int32_t value) {
  _internal_set_search_query_length(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.search_query_length)
}

// optional fixed64 hashed_target = 5;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_hashed_target() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_hashed_target() const {
  return _internal_has_hashed_target();
}
inline void ChromeOSAppListLaunchEventProto::clear_hashed_target() {
  hashed_target_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000008u;
}
inline uint64_t ChromeOSAppListLaunchEventProto::_internal_hashed_target() const {
  return hashed_target_;
}
inline uint64_t ChromeOSAppListLaunchEventProto::hashed_target() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.hashed_target)
  return _internal_hashed_target();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_hashed_target(uint64_t value) {
  _has_bits_[0] |= 0x00000008u;
  hashed_target_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_hashed_target(uint64_t value) {
  _internal_set_hashed_target(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.hashed_target)
}

// optional fixed64 hashed_query = 6;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_hashed_query() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_hashed_query() const {
  return _internal_has_hashed_query();
}
inline void ChromeOSAppListLaunchEventProto::clear_hashed_query() {
  hashed_query_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000010u;
}
inline uint64_t ChromeOSAppListLaunchEventProto::_internal_hashed_query() const {
  return hashed_query_;
}
inline uint64_t ChromeOSAppListLaunchEventProto::hashed_query() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.hashed_query)
  return _internal_hashed_query();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_hashed_query(uint64_t value) {
  _has_bits_[0] |= 0x00000010u;
  hashed_query_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_hashed_query(uint64_t value) {
  _internal_set_hashed_query(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.hashed_query)
}

// optional fixed64 hashed_domain = 7;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_hashed_domain() const {
  bool value = (_has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_hashed_domain() const {
  return _internal_has_hashed_domain();
}
inline void ChromeOSAppListLaunchEventProto::clear_hashed_domain() {
  hashed_domain_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000080u;
}
inline uint64_t ChromeOSAppListLaunchEventProto::_internal_hashed_domain() const {
  return hashed_domain_;
}
inline uint64_t ChromeOSAppListLaunchEventProto::hashed_domain() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.hashed_domain)
  return _internal_hashed_domain();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_hashed_domain(uint64_t value) {
  _has_bits_[0] |= 0x00000080u;
  hashed_domain_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_hashed_domain(uint64_t value) {
  _internal_set_hashed_domain(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.hashed_domain)
}

// optional fixed64 hashed_app = 8;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_hashed_app() const {
  bool value = (_has_bits_[0] & 0x00000100u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_hashed_app() const {
  return _internal_has_hashed_app();
}
inline void ChromeOSAppListLaunchEventProto::clear_hashed_app() {
  hashed_app_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000100u;
}
inline uint64_t ChromeOSAppListLaunchEventProto::_internal_hashed_app() const {
  return hashed_app_;
}
inline uint64_t ChromeOSAppListLaunchEventProto::hashed_app() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.hashed_app)
  return _internal_hashed_app();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_hashed_app(uint64_t value) {
  _has_bits_[0] |= 0x00000100u;
  hashed_app_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_hashed_app(uint64_t value) {
  _internal_set_hashed_app(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.hashed_app)
}

// optional .metrics.ChromeOSAppListLaunchEventProto.SearchProviderType search_provider_type = 9;
inline bool ChromeOSAppListLaunchEventProto::_internal_has_search_provider_type() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool ChromeOSAppListLaunchEventProto::has_search_provider_type() const {
  return _internal_has_search_provider_type();
}
inline void ChromeOSAppListLaunchEventProto::clear_search_provider_type() {
  search_provider_type_ = 0;
  _has_bits_[0] &= ~0x00000040u;
}
inline ::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType ChromeOSAppListLaunchEventProto::_internal_search_provider_type() const {
  return static_cast< ::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType >(search_provider_type_);
}
inline ::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType ChromeOSAppListLaunchEventProto::search_provider_type() const {
  // @@protoc_insertion_point(field_get:metrics.ChromeOSAppListLaunchEventProto.search_provider_type)
  return _internal_search_provider_type();
}
inline void ChromeOSAppListLaunchEventProto::_internal_set_search_provider_type(::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType value) {
  assert(::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType_IsValid(value));
  _has_bits_[0] |= 0x00000040u;
  search_provider_type_ = value;
}
inline void ChromeOSAppListLaunchEventProto::set_search_provider_type(::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType value) {
  _internal_set_search_provider_type(value);
  // @@protoc_insertion_point(field_set:metrics.ChromeOSAppListLaunchEventProto.search_provider_type)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace metrics

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::metrics::ChromeOSAppListLaunchEventProto_LaunchType> : ::std::true_type {};
template <> struct is_proto_enum< ::metrics::ChromeOSAppListLaunchEventProto_SearchProviderType> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_chrome_5fos_5fapp_5flist_5flaunch_5fevent_2eproto
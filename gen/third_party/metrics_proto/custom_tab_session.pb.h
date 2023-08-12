// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: custom_tab_session.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_custom_5ftab_5fsession_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_custom_5ftab_5fsession_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_custom_5ftab_5fsession_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_custom_5ftab_5fsession_2eproto {
  static const uint32_t offsets[];
};
namespace metrics {
class CustomTabSessionProto;
struct CustomTabSessionProtoDefaultTypeInternal;
extern CustomTabSessionProtoDefaultTypeInternal _CustomTabSessionProto_default_instance_;
}  // namespace metrics
PROTOBUF_NAMESPACE_OPEN
template<> ::metrics::CustomTabSessionProto* Arena::CreateMaybeMessage<::metrics::CustomTabSessionProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace metrics {

// ===================================================================

class CustomTabSessionProto final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:metrics.CustomTabSessionProto) */ {
 public:
  inline CustomTabSessionProto() : CustomTabSessionProto(nullptr) {}
  ~CustomTabSessionProto() override;
  explicit PROTOBUF_CONSTEXPR CustomTabSessionProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CustomTabSessionProto(const CustomTabSessionProto& from);
  CustomTabSessionProto(CustomTabSessionProto&& from) noexcept
    : CustomTabSessionProto() {
    *this = ::std::move(from);
  }

  inline CustomTabSessionProto& operator=(const CustomTabSessionProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline CustomTabSessionProto& operator=(CustomTabSessionProto&& from) noexcept {
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

  static const CustomTabSessionProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const CustomTabSessionProto* internal_default_instance() {
    return reinterpret_cast<const CustomTabSessionProto*>(
               &_CustomTabSessionProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CustomTabSessionProto& a, CustomTabSessionProto& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(CustomTabSessionProto* other) {
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
  void UnsafeArenaSwap(CustomTabSessionProto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CustomTabSessionProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CustomTabSessionProto>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const CustomTabSessionProto& from);
  void MergeFrom(const CustomTabSessionProto& from);
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
  void InternalSwap(CustomTabSessionProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "metrics.CustomTabSessionProto";
  }
  protected:
  explicit CustomTabSessionProto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPackageNameFieldNumber = 2,
    kTimeSecFieldNumber = 1,
    kSessionDurationSecFieldNumber = 3,
    kDidUserInteractFieldNumber = 4,
    kWasUserClosedFieldNumber = 5,
    kIsPartialFieldNumber = 6,
  };
  // optional string package_name = 2;
  bool has_package_name() const;
  private:
  bool _internal_has_package_name() const;
  public:
  void clear_package_name();
  const std::string& package_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_package_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_package_name();
  PROTOBUF_NODISCARD std::string* release_package_name();
  void set_allocated_package_name(std::string* package_name);
  private:
  const std::string& _internal_package_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_package_name(const std::string& value);
  std::string* _internal_mutable_package_name();
  public:

  // optional int64 time_sec = 1;
  bool has_time_sec() const;
  private:
  bool _internal_has_time_sec() const;
  public:
  void clear_time_sec();
  int64_t time_sec() const;
  void set_time_sec(int64_t value);
  private:
  int64_t _internal_time_sec() const;
  void _internal_set_time_sec(int64_t value);
  public:

  // optional int32 session_duration_sec = 3;
  bool has_session_duration_sec() const;
  private:
  bool _internal_has_session_duration_sec() const;
  public:
  void clear_session_duration_sec();
  int32_t session_duration_sec() const;
  void set_session_duration_sec(int32_t value);
  private:
  int32_t _internal_session_duration_sec() const;
  void _internal_set_session_duration_sec(int32_t value);
  public:

  // optional bool did_user_interact = 4;
  bool has_did_user_interact() const;
  private:
  bool _internal_has_did_user_interact() const;
  public:
  void clear_did_user_interact();
  bool did_user_interact() const;
  void set_did_user_interact(bool value);
  private:
  bool _internal_did_user_interact() const;
  void _internal_set_did_user_interact(bool value);
  public:

  // optional bool was_user_closed = 5;
  bool has_was_user_closed() const;
  private:
  bool _internal_has_was_user_closed() const;
  public:
  void clear_was_user_closed();
  bool was_user_closed() const;
  void set_was_user_closed(bool value);
  private:
  bool _internal_was_user_closed() const;
  void _internal_set_was_user_closed(bool value);
  public:

  // optional bool is_partial = 6;
  bool has_is_partial() const;
  private:
  bool _internal_has_is_partial() const;
  public:
  void clear_is_partial();
  bool is_partial() const;
  void set_is_partial(bool value);
  private:
  bool _internal_is_partial() const;
  void _internal_set_is_partial(bool value);
  public:

  // @@protoc_insertion_point(class_scope:metrics.CustomTabSessionProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr package_name_;
  int64_t time_sec_;
  int32_t session_duration_sec_;
  bool did_user_interact_;
  bool was_user_closed_;
  bool is_partial_;
  friend struct ::TableStruct_custom_5ftab_5fsession_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CustomTabSessionProto

// optional int64 time_sec = 1;
inline bool CustomTabSessionProto::_internal_has_time_sec() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool CustomTabSessionProto::has_time_sec() const {
  return _internal_has_time_sec();
}
inline void CustomTabSessionProto::clear_time_sec() {
  time_sec_ = int64_t{0};
  _has_bits_[0] &= ~0x00000002u;
}
inline int64_t CustomTabSessionProto::_internal_time_sec() const {
  return time_sec_;
}
inline int64_t CustomTabSessionProto::time_sec() const {
  // @@protoc_insertion_point(field_get:metrics.CustomTabSessionProto.time_sec)
  return _internal_time_sec();
}
inline void CustomTabSessionProto::_internal_set_time_sec(int64_t value) {
  _has_bits_[0] |= 0x00000002u;
  time_sec_ = value;
}
inline void CustomTabSessionProto::set_time_sec(int64_t value) {
  _internal_set_time_sec(value);
  // @@protoc_insertion_point(field_set:metrics.CustomTabSessionProto.time_sec)
}

// optional string package_name = 2;
inline bool CustomTabSessionProto::_internal_has_package_name() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool CustomTabSessionProto::has_package_name() const {
  return _internal_has_package_name();
}
inline void CustomTabSessionProto::clear_package_name() {
  package_name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& CustomTabSessionProto::package_name() const {
  // @@protoc_insertion_point(field_get:metrics.CustomTabSessionProto.package_name)
  return _internal_package_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void CustomTabSessionProto::set_package_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 package_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:metrics.CustomTabSessionProto.package_name)
}
inline std::string* CustomTabSessionProto::mutable_package_name() {
  std::string* _s = _internal_mutable_package_name();
  // @@protoc_insertion_point(field_mutable:metrics.CustomTabSessionProto.package_name)
  return _s;
}
inline const std::string& CustomTabSessionProto::_internal_package_name() const {
  return package_name_.Get();
}
inline void CustomTabSessionProto::_internal_set_package_name(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  package_name_.Set(value, GetArenaForAllocation());
}
inline std::string* CustomTabSessionProto::_internal_mutable_package_name() {
  _has_bits_[0] |= 0x00000001u;
  return package_name_.Mutable(GetArenaForAllocation());
}
inline std::string* CustomTabSessionProto::release_package_name() {
  // @@protoc_insertion_point(field_release:metrics.CustomTabSessionProto.package_name)
  if (!_internal_has_package_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = package_name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (package_name_.IsDefault()) {
    package_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void CustomTabSessionProto::set_allocated_package_name(std::string* package_name) {
  if (package_name != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  package_name_.SetAllocated(package_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (package_name_.IsDefault()) {
    package_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:metrics.CustomTabSessionProto.package_name)
}

// optional int32 session_duration_sec = 3;
inline bool CustomTabSessionProto::_internal_has_session_duration_sec() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool CustomTabSessionProto::has_session_duration_sec() const {
  return _internal_has_session_duration_sec();
}
inline void CustomTabSessionProto::clear_session_duration_sec() {
  session_duration_sec_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline int32_t CustomTabSessionProto::_internal_session_duration_sec() const {
  return session_duration_sec_;
}
inline int32_t CustomTabSessionProto::session_duration_sec() const {
  // @@protoc_insertion_point(field_get:metrics.CustomTabSessionProto.session_duration_sec)
  return _internal_session_duration_sec();
}
inline void CustomTabSessionProto::_internal_set_session_duration_sec(int32_t value) {
  _has_bits_[0] |= 0x00000004u;
  session_duration_sec_ = value;
}
inline void CustomTabSessionProto::set_session_duration_sec(int32_t value) {
  _internal_set_session_duration_sec(value);
  // @@protoc_insertion_point(field_set:metrics.CustomTabSessionProto.session_duration_sec)
}

// optional bool did_user_interact = 4;
inline bool CustomTabSessionProto::_internal_has_did_user_interact() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool CustomTabSessionProto::has_did_user_interact() const {
  return _internal_has_did_user_interact();
}
inline void CustomTabSessionProto::clear_did_user_interact() {
  did_user_interact_ = false;
  _has_bits_[0] &= ~0x00000008u;
}
inline bool CustomTabSessionProto::_internal_did_user_interact() const {
  return did_user_interact_;
}
inline bool CustomTabSessionProto::did_user_interact() const {
  // @@protoc_insertion_point(field_get:metrics.CustomTabSessionProto.did_user_interact)
  return _internal_did_user_interact();
}
inline void CustomTabSessionProto::_internal_set_did_user_interact(bool value) {
  _has_bits_[0] |= 0x00000008u;
  did_user_interact_ = value;
}
inline void CustomTabSessionProto::set_did_user_interact(bool value) {
  _internal_set_did_user_interact(value);
  // @@protoc_insertion_point(field_set:metrics.CustomTabSessionProto.did_user_interact)
}

// optional bool was_user_closed = 5;
inline bool CustomTabSessionProto::_internal_has_was_user_closed() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool CustomTabSessionProto::has_was_user_closed() const {
  return _internal_has_was_user_closed();
}
inline void CustomTabSessionProto::clear_was_user_closed() {
  was_user_closed_ = false;
  _has_bits_[0] &= ~0x00000010u;
}
inline bool CustomTabSessionProto::_internal_was_user_closed() const {
  return was_user_closed_;
}
inline bool CustomTabSessionProto::was_user_closed() const {
  // @@protoc_insertion_point(field_get:metrics.CustomTabSessionProto.was_user_closed)
  return _internal_was_user_closed();
}
inline void CustomTabSessionProto::_internal_set_was_user_closed(bool value) {
  _has_bits_[0] |= 0x00000010u;
  was_user_closed_ = value;
}
inline void CustomTabSessionProto::set_was_user_closed(bool value) {
  _internal_set_was_user_closed(value);
  // @@protoc_insertion_point(field_set:metrics.CustomTabSessionProto.was_user_closed)
}

// optional bool is_partial = 6;
inline bool CustomTabSessionProto::_internal_has_is_partial() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool CustomTabSessionProto::has_is_partial() const {
  return _internal_has_is_partial();
}
inline void CustomTabSessionProto::clear_is_partial() {
  is_partial_ = false;
  _has_bits_[0] &= ~0x00000020u;
}
inline bool CustomTabSessionProto::_internal_is_partial() const {
  return is_partial_;
}
inline bool CustomTabSessionProto::is_partial() const {
  // @@protoc_insertion_point(field_get:metrics.CustomTabSessionProto.is_partial)
  return _internal_is_partial();
}
inline void CustomTabSessionProto::_internal_set_is_partial(bool value) {
  _has_bits_[0] |= 0x00000020u;
  is_partial_ = value;
}
inline void CustomTabSessionProto::set_is_partial(bool value) {
  _internal_set_is_partial(value);
  // @@protoc_insertion_point(field_set:metrics.CustomTabSessionProto.is_partial)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace metrics

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_custom_5ftab_5fsession_2eproto
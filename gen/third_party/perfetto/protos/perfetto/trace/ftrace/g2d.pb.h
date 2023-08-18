// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/ftrace/g2d.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fftrace_2fg2d_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fftrace_2fg2d_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fftrace_2fg2d_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protos_2fperfetto_2ftrace_2fftrace_2fg2d_2eproto {
  static const uint32_t offsets[];
};
namespace perfetto {
namespace protos {
class G2dTracingMarkWriteFtraceEvent;
struct G2dTracingMarkWriteFtraceEventDefaultTypeInternal;
extern G2dTracingMarkWriteFtraceEventDefaultTypeInternal _G2dTracingMarkWriteFtraceEvent_default_instance_;
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> ::perfetto::protos::G2dTracingMarkWriteFtraceEvent* Arena::CreateMaybeMessage<::perfetto::protos::G2dTracingMarkWriteFtraceEvent>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace perfetto {
namespace protos {

// ===================================================================

class G2dTracingMarkWriteFtraceEvent final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.G2dTracingMarkWriteFtraceEvent) */ {
 public:
  inline G2dTracingMarkWriteFtraceEvent() : G2dTracingMarkWriteFtraceEvent(nullptr) {}
  ~G2dTracingMarkWriteFtraceEvent() override;
  explicit PROTOBUF_CONSTEXPR G2dTracingMarkWriteFtraceEvent(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  G2dTracingMarkWriteFtraceEvent(const G2dTracingMarkWriteFtraceEvent& from);
  G2dTracingMarkWriteFtraceEvent(G2dTracingMarkWriteFtraceEvent&& from) noexcept
    : G2dTracingMarkWriteFtraceEvent() {
    *this = ::std::move(from);
  }

  inline G2dTracingMarkWriteFtraceEvent& operator=(const G2dTracingMarkWriteFtraceEvent& from) {
    CopyFrom(from);
    return *this;
  }
  inline G2dTracingMarkWriteFtraceEvent& operator=(G2dTracingMarkWriteFtraceEvent&& from) noexcept {
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

  static const G2dTracingMarkWriteFtraceEvent& default_instance() {
    return *internal_default_instance();
  }
  static inline const G2dTracingMarkWriteFtraceEvent* internal_default_instance() {
    return reinterpret_cast<const G2dTracingMarkWriteFtraceEvent*>(
               &_G2dTracingMarkWriteFtraceEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(G2dTracingMarkWriteFtraceEvent& a, G2dTracingMarkWriteFtraceEvent& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(G2dTracingMarkWriteFtraceEvent* other) {
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
  void UnsafeArenaSwap(G2dTracingMarkWriteFtraceEvent* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  G2dTracingMarkWriteFtraceEvent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<G2dTracingMarkWriteFtraceEvent>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const G2dTracingMarkWriteFtraceEvent& from);
  void MergeFrom(const G2dTracingMarkWriteFtraceEvent& from);
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
  void InternalSwap(G2dTracingMarkWriteFtraceEvent* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.G2dTracingMarkWriteFtraceEvent";
  }
  protected:
  explicit G2dTracingMarkWriteFtraceEvent(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 4,
    kPidFieldNumber = 1,
    kTypeFieldNumber = 5,
    kValueFieldNumber = 6,
  };
  // optional string name = 4;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional int32 pid = 1;
  bool has_pid() const;
  private:
  bool _internal_has_pid() const;
  public:
  void clear_pid();
  int32_t pid() const;
  void set_pid(int32_t value);
  private:
  int32_t _internal_pid() const;
  void _internal_set_pid(int32_t value);
  public:

  // optional uint32 type = 5;
  bool has_type() const;
  private:
  bool _internal_has_type() const;
  public:
  void clear_type();
  uint32_t type() const;
  void set_type(uint32_t value);
  private:
  uint32_t _internal_type() const;
  void _internal_set_type(uint32_t value);
  public:

  // optional int32 value = 6;
  bool has_value() const;
  private:
  bool _internal_has_value() const;
  public:
  void clear_value();
  int32_t value() const;
  void set_value(int32_t value);
  private:
  int32_t _internal_value() const;
  void _internal_set_value(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.G2dTracingMarkWriteFtraceEvent)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  int32_t pid_;
  uint32_t type_;
  int32_t value_;
  friend struct ::TableStruct_protos_2fperfetto_2ftrace_2fftrace_2fg2d_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// G2dTracingMarkWriteFtraceEvent

// optional int32 pid = 1;
inline bool G2dTracingMarkWriteFtraceEvent::_internal_has_pid() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool G2dTracingMarkWriteFtraceEvent::has_pid() const {
  return _internal_has_pid();
}
inline void G2dTracingMarkWriteFtraceEvent::clear_pid() {
  pid_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline int32_t G2dTracingMarkWriteFtraceEvent::_internal_pid() const {
  return pid_;
}
inline int32_t G2dTracingMarkWriteFtraceEvent::pid() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.G2dTracingMarkWriteFtraceEvent.pid)
  return _internal_pid();
}
inline void G2dTracingMarkWriteFtraceEvent::_internal_set_pid(int32_t value) {
  _has_bits_[0] |= 0x00000002u;
  pid_ = value;
}
inline void G2dTracingMarkWriteFtraceEvent::set_pid(int32_t value) {
  _internal_set_pid(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.G2dTracingMarkWriteFtraceEvent.pid)
}

// optional string name = 4;
inline bool G2dTracingMarkWriteFtraceEvent::_internal_has_name() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool G2dTracingMarkWriteFtraceEvent::has_name() const {
  return _internal_has_name();
}
inline void G2dTracingMarkWriteFtraceEvent::clear_name() {
  name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& G2dTracingMarkWriteFtraceEvent::name() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.G2dTracingMarkWriteFtraceEvent.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void G2dTracingMarkWriteFtraceEvent::set_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:perfetto.protos.G2dTracingMarkWriteFtraceEvent.name)
}
inline std::string* G2dTracingMarkWriteFtraceEvent::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:perfetto.protos.G2dTracingMarkWriteFtraceEvent.name)
  return _s;
}
inline const std::string& G2dTracingMarkWriteFtraceEvent::_internal_name() const {
  return name_.Get();
}
inline void G2dTracingMarkWriteFtraceEvent::_internal_set_name(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  name_.Set(value, GetArenaForAllocation());
}
inline std::string* G2dTracingMarkWriteFtraceEvent::_internal_mutable_name() {
  _has_bits_[0] |= 0x00000001u;
  return name_.Mutable(GetArenaForAllocation());
}
inline std::string* G2dTracingMarkWriteFtraceEvent::release_name() {
  // @@protoc_insertion_point(field_release:perfetto.protos.G2dTracingMarkWriteFtraceEvent.name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault()) {
    name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void G2dTracingMarkWriteFtraceEvent::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault()) {
    name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:perfetto.protos.G2dTracingMarkWriteFtraceEvent.name)
}

// optional uint32 type = 5;
inline bool G2dTracingMarkWriteFtraceEvent::_internal_has_type() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool G2dTracingMarkWriteFtraceEvent::has_type() const {
  return _internal_has_type();
}
inline void G2dTracingMarkWriteFtraceEvent::clear_type() {
  type_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline uint32_t G2dTracingMarkWriteFtraceEvent::_internal_type() const {
  return type_;
}
inline uint32_t G2dTracingMarkWriteFtraceEvent::type() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.G2dTracingMarkWriteFtraceEvent.type)
  return _internal_type();
}
inline void G2dTracingMarkWriteFtraceEvent::_internal_set_type(uint32_t value) {
  _has_bits_[0] |= 0x00000004u;
  type_ = value;
}
inline void G2dTracingMarkWriteFtraceEvent::set_type(uint32_t value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.G2dTracingMarkWriteFtraceEvent.type)
}

// optional int32 value = 6;
inline bool G2dTracingMarkWriteFtraceEvent::_internal_has_value() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool G2dTracingMarkWriteFtraceEvent::has_value() const {
  return _internal_has_value();
}
inline void G2dTracingMarkWriteFtraceEvent::clear_value() {
  value_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline int32_t G2dTracingMarkWriteFtraceEvent::_internal_value() const {
  return value_;
}
inline int32_t G2dTracingMarkWriteFtraceEvent::value() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.G2dTracingMarkWriteFtraceEvent.value)
  return _internal_value();
}
inline void G2dTracingMarkWriteFtraceEvent::_internal_set_value(int32_t value) {
  _has_bits_[0] |= 0x00000008u;
  value_ = value;
}
inline void G2dTracingMarkWriteFtraceEvent::set_value(int32_t value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.G2dTracingMarkWriteFtraceEvent.value)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace perfetto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fftrace_2fg2d_2eproto

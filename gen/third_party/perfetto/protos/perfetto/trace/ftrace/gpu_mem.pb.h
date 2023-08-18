// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/ftrace/gpu_mem.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fftrace_2fgpu_5fmem_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fftrace_2fgpu_5fmem_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fftrace_2fgpu_5fmem_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protos_2fperfetto_2ftrace_2fftrace_2fgpu_5fmem_2eproto {
  static const uint32_t offsets[];
};
namespace perfetto {
namespace protos {
class GpuMemTotalFtraceEvent;
struct GpuMemTotalFtraceEventDefaultTypeInternal;
extern GpuMemTotalFtraceEventDefaultTypeInternal _GpuMemTotalFtraceEvent_default_instance_;
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> ::perfetto::protos::GpuMemTotalFtraceEvent* Arena::CreateMaybeMessage<::perfetto::protos::GpuMemTotalFtraceEvent>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace perfetto {
namespace protos {

// ===================================================================

class GpuMemTotalFtraceEvent final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.GpuMemTotalFtraceEvent) */ {
 public:
  inline GpuMemTotalFtraceEvent() : GpuMemTotalFtraceEvent(nullptr) {}
  ~GpuMemTotalFtraceEvent() override;
  explicit PROTOBUF_CONSTEXPR GpuMemTotalFtraceEvent(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GpuMemTotalFtraceEvent(const GpuMemTotalFtraceEvent& from);
  GpuMemTotalFtraceEvent(GpuMemTotalFtraceEvent&& from) noexcept
    : GpuMemTotalFtraceEvent() {
    *this = ::std::move(from);
  }

  inline GpuMemTotalFtraceEvent& operator=(const GpuMemTotalFtraceEvent& from) {
    CopyFrom(from);
    return *this;
  }
  inline GpuMemTotalFtraceEvent& operator=(GpuMemTotalFtraceEvent&& from) noexcept {
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

  static const GpuMemTotalFtraceEvent& default_instance() {
    return *internal_default_instance();
  }
  static inline const GpuMemTotalFtraceEvent* internal_default_instance() {
    return reinterpret_cast<const GpuMemTotalFtraceEvent*>(
               &_GpuMemTotalFtraceEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GpuMemTotalFtraceEvent& a, GpuMemTotalFtraceEvent& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(GpuMemTotalFtraceEvent* other) {
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
  void UnsafeArenaSwap(GpuMemTotalFtraceEvent* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GpuMemTotalFtraceEvent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<GpuMemTotalFtraceEvent>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const GpuMemTotalFtraceEvent& from);
  void MergeFrom(const GpuMemTotalFtraceEvent& from);
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
  void InternalSwap(GpuMemTotalFtraceEvent* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.GpuMemTotalFtraceEvent";
  }
  protected:
  explicit GpuMemTotalFtraceEvent(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kGpuIdFieldNumber = 1,
    kPidFieldNumber = 2,
    kSizeFieldNumber = 3,
  };
  // optional uint32 gpu_id = 1;
  bool has_gpu_id() const;
  private:
  bool _internal_has_gpu_id() const;
  public:
  void clear_gpu_id();
  uint32_t gpu_id() const;
  void set_gpu_id(uint32_t value);
  private:
  uint32_t _internal_gpu_id() const;
  void _internal_set_gpu_id(uint32_t value);
  public:

  // optional uint32 pid = 2;
  bool has_pid() const;
  private:
  bool _internal_has_pid() const;
  public:
  void clear_pid();
  uint32_t pid() const;
  void set_pid(uint32_t value);
  private:
  uint32_t _internal_pid() const;
  void _internal_set_pid(uint32_t value);
  public:

  // optional uint64 size = 3;
  bool has_size() const;
  private:
  bool _internal_has_size() const;
  public:
  void clear_size();
  uint64_t size() const;
  void set_size(uint64_t value);
  private:
  uint64_t _internal_size() const;
  void _internal_set_size(uint64_t value);
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.GpuMemTotalFtraceEvent)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  uint32_t gpu_id_;
  uint32_t pid_;
  uint64_t size_;
  friend struct ::TableStruct_protos_2fperfetto_2ftrace_2fftrace_2fgpu_5fmem_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GpuMemTotalFtraceEvent

// optional uint32 gpu_id = 1;
inline bool GpuMemTotalFtraceEvent::_internal_has_gpu_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool GpuMemTotalFtraceEvent::has_gpu_id() const {
  return _internal_has_gpu_id();
}
inline void GpuMemTotalFtraceEvent::clear_gpu_id() {
  gpu_id_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline uint32_t GpuMemTotalFtraceEvent::_internal_gpu_id() const {
  return gpu_id_;
}
inline uint32_t GpuMemTotalFtraceEvent::gpu_id() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.GpuMemTotalFtraceEvent.gpu_id)
  return _internal_gpu_id();
}
inline void GpuMemTotalFtraceEvent::_internal_set_gpu_id(uint32_t value) {
  _has_bits_[0] |= 0x00000001u;
  gpu_id_ = value;
}
inline void GpuMemTotalFtraceEvent::set_gpu_id(uint32_t value) {
  _internal_set_gpu_id(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.GpuMemTotalFtraceEvent.gpu_id)
}

// optional uint32 pid = 2;
inline bool GpuMemTotalFtraceEvent::_internal_has_pid() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool GpuMemTotalFtraceEvent::has_pid() const {
  return _internal_has_pid();
}
inline void GpuMemTotalFtraceEvent::clear_pid() {
  pid_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline uint32_t GpuMemTotalFtraceEvent::_internal_pid() const {
  return pid_;
}
inline uint32_t GpuMemTotalFtraceEvent::pid() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.GpuMemTotalFtraceEvent.pid)
  return _internal_pid();
}
inline void GpuMemTotalFtraceEvent::_internal_set_pid(uint32_t value) {
  _has_bits_[0] |= 0x00000002u;
  pid_ = value;
}
inline void GpuMemTotalFtraceEvent::set_pid(uint32_t value) {
  _internal_set_pid(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.GpuMemTotalFtraceEvent.pid)
}

// optional uint64 size = 3;
inline bool GpuMemTotalFtraceEvent::_internal_has_size() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool GpuMemTotalFtraceEvent::has_size() const {
  return _internal_has_size();
}
inline void GpuMemTotalFtraceEvent::clear_size() {
  size_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000004u;
}
inline uint64_t GpuMemTotalFtraceEvent::_internal_size() const {
  return size_;
}
inline uint64_t GpuMemTotalFtraceEvent::size() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.GpuMemTotalFtraceEvent.size)
  return _internal_size();
}
inline void GpuMemTotalFtraceEvent::_internal_set_size(uint64_t value) {
  _has_bits_[0] |= 0x00000004u;
  size_ = value;
}
inline void GpuMemTotalFtraceEvent::set_size(uint64_t value) {
  _internal_set_size(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.GpuMemTotalFtraceEvent.size)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace perfetto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fftrace_2fgpu_5fmem_2eproto

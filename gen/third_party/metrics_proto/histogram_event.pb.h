// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: histogram_event.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_histogram_5fevent_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_histogram_5fevent_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_histogram_5fevent_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_histogram_5fevent_2eproto {
  static const uint32_t offsets[];
};
namespace metrics {
class HistogramEventProto;
struct HistogramEventProtoDefaultTypeInternal;
extern HistogramEventProtoDefaultTypeInternal _HistogramEventProto_default_instance_;
class HistogramEventProto_Bucket;
struct HistogramEventProto_BucketDefaultTypeInternal;
extern HistogramEventProto_BucketDefaultTypeInternal _HistogramEventProto_Bucket_default_instance_;
}  // namespace metrics
PROTOBUF_NAMESPACE_OPEN
template<> ::metrics::HistogramEventProto* Arena::CreateMaybeMessage<::metrics::HistogramEventProto>(Arena*);
template<> ::metrics::HistogramEventProto_Bucket* Arena::CreateMaybeMessage<::metrics::HistogramEventProto_Bucket>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace metrics {

// ===================================================================

class HistogramEventProto_Bucket final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:metrics.HistogramEventProto.Bucket) */ {
 public:
  inline HistogramEventProto_Bucket() : HistogramEventProto_Bucket(nullptr) {}
  ~HistogramEventProto_Bucket() override;
  explicit PROTOBUF_CONSTEXPR HistogramEventProto_Bucket(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  HistogramEventProto_Bucket(const HistogramEventProto_Bucket& from);
  HistogramEventProto_Bucket(HistogramEventProto_Bucket&& from) noexcept
    : HistogramEventProto_Bucket() {
    *this = ::std::move(from);
  }

  inline HistogramEventProto_Bucket& operator=(const HistogramEventProto_Bucket& from) {
    CopyFrom(from);
    return *this;
  }
  inline HistogramEventProto_Bucket& operator=(HistogramEventProto_Bucket&& from) noexcept {
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

  static const HistogramEventProto_Bucket& default_instance() {
    return *internal_default_instance();
  }
  static inline const HistogramEventProto_Bucket* internal_default_instance() {
    return reinterpret_cast<const HistogramEventProto_Bucket*>(
               &_HistogramEventProto_Bucket_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(HistogramEventProto_Bucket& a, HistogramEventProto_Bucket& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(HistogramEventProto_Bucket* other) {
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
  void UnsafeArenaSwap(HistogramEventProto_Bucket* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HistogramEventProto_Bucket* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<HistogramEventProto_Bucket>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const HistogramEventProto_Bucket& from);
  void MergeFrom(const HistogramEventProto_Bucket& from);
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
  void InternalSwap(HistogramEventProto_Bucket* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "metrics.HistogramEventProto.Bucket";
  }
  protected:
  explicit HistogramEventProto_Bucket(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMinFieldNumber = 1,
    kMaxFieldNumber = 2,
    kCountFieldNumber = 4,
  };
  // optional int64 min = 1;
  bool has_min() const;
  private:
  bool _internal_has_min() const;
  public:
  void clear_min();
  int64_t min() const;
  void set_min(int64_t value);
  private:
  int64_t _internal_min() const;
  void _internal_set_min(int64_t value);
  public:

  // optional int64 max = 2;
  bool has_max() const;
  private:
  bool _internal_has_max() const;
  public:
  void clear_max();
  int64_t max() const;
  void set_max(int64_t value);
  private:
  int64_t _internal_max() const;
  void _internal_set_max(int64_t value);
  public:

  // optional int64 count = 4 [default = 1];
  bool has_count() const;
  private:
  bool _internal_has_count() const;
  public:
  void clear_count();
  int64_t count() const;
  void set_count(int64_t value);
  private:
  int64_t _internal_count() const;
  void _internal_set_count(int64_t value);
  public:

  // @@protoc_insertion_point(class_scope:metrics.HistogramEventProto.Bucket)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  int64_t min_;
  int64_t max_;
  int64_t count_;
  friend struct ::TableStruct_histogram_5fevent_2eproto;
};
// -------------------------------------------------------------------

class HistogramEventProto final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:metrics.HistogramEventProto) */ {
 public:
  inline HistogramEventProto() : HistogramEventProto(nullptr) {}
  ~HistogramEventProto() override;
  explicit PROTOBUF_CONSTEXPR HistogramEventProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  HistogramEventProto(const HistogramEventProto& from);
  HistogramEventProto(HistogramEventProto&& from) noexcept
    : HistogramEventProto() {
    *this = ::std::move(from);
  }

  inline HistogramEventProto& operator=(const HistogramEventProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline HistogramEventProto& operator=(HistogramEventProto&& from) noexcept {
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

  static const HistogramEventProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const HistogramEventProto* internal_default_instance() {
    return reinterpret_cast<const HistogramEventProto*>(
               &_HistogramEventProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(HistogramEventProto& a, HistogramEventProto& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(HistogramEventProto* other) {
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
  void UnsafeArenaSwap(HistogramEventProto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HistogramEventProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<HistogramEventProto>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const HistogramEventProto& from);
  void MergeFrom(const HistogramEventProto& from);
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
  void InternalSwap(HistogramEventProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "metrics.HistogramEventProto";
  }
  protected:
  explicit HistogramEventProto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  typedef HistogramEventProto_Bucket Bucket;

  // accessors -------------------------------------------------------

  enum : int {
    kBucketFieldNumber = 3,
    kNameHashFieldNumber = 1,
    kSumFieldNumber = 2,
  };
  // repeated .metrics.HistogramEventProto.Bucket bucket = 3;
  int bucket_size() const;
  private:
  int _internal_bucket_size() const;
  public:
  void clear_bucket();
  ::metrics::HistogramEventProto_Bucket* mutable_bucket(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::metrics::HistogramEventProto_Bucket >*
      mutable_bucket();
  private:
  const ::metrics::HistogramEventProto_Bucket& _internal_bucket(int index) const;
  ::metrics::HistogramEventProto_Bucket* _internal_add_bucket();
  public:
  const ::metrics::HistogramEventProto_Bucket& bucket(int index) const;
  ::metrics::HistogramEventProto_Bucket* add_bucket();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::metrics::HistogramEventProto_Bucket >&
      bucket() const;

  // optional fixed64 name_hash = 1;
  bool has_name_hash() const;
  private:
  bool _internal_has_name_hash() const;
  public:
  void clear_name_hash();
  uint64_t name_hash() const;
  void set_name_hash(uint64_t value);
  private:
  uint64_t _internal_name_hash() const;
  void _internal_set_name_hash(uint64_t value);
  public:

  // optional int64 sum = 2;
  bool has_sum() const;
  private:
  bool _internal_has_sum() const;
  public:
  void clear_sum();
  int64_t sum() const;
  void set_sum(int64_t value);
  private:
  int64_t _internal_sum() const;
  void _internal_set_sum(int64_t value);
  public:

  // @@protoc_insertion_point(class_scope:metrics.HistogramEventProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::metrics::HistogramEventProto_Bucket > bucket_;
  uint64_t name_hash_;
  int64_t sum_;
  friend struct ::TableStruct_histogram_5fevent_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HistogramEventProto_Bucket

// optional int64 min = 1;
inline bool HistogramEventProto_Bucket::_internal_has_min() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool HistogramEventProto_Bucket::has_min() const {
  return _internal_has_min();
}
inline void HistogramEventProto_Bucket::clear_min() {
  min_ = int64_t{0};
  _has_bits_[0] &= ~0x00000001u;
}
inline int64_t HistogramEventProto_Bucket::_internal_min() const {
  return min_;
}
inline int64_t HistogramEventProto_Bucket::min() const {
  // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.Bucket.min)
  return _internal_min();
}
inline void HistogramEventProto_Bucket::_internal_set_min(int64_t value) {
  _has_bits_[0] |= 0x00000001u;
  min_ = value;
}
inline void HistogramEventProto_Bucket::set_min(int64_t value) {
  _internal_set_min(value);
  // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.Bucket.min)
}

// optional int64 max = 2;
inline bool HistogramEventProto_Bucket::_internal_has_max() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool HistogramEventProto_Bucket::has_max() const {
  return _internal_has_max();
}
inline void HistogramEventProto_Bucket::clear_max() {
  max_ = int64_t{0};
  _has_bits_[0] &= ~0x00000002u;
}
inline int64_t HistogramEventProto_Bucket::_internal_max() const {
  return max_;
}
inline int64_t HistogramEventProto_Bucket::max() const {
  // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.Bucket.max)
  return _internal_max();
}
inline void HistogramEventProto_Bucket::_internal_set_max(int64_t value) {
  _has_bits_[0] |= 0x00000002u;
  max_ = value;
}
inline void HistogramEventProto_Bucket::set_max(int64_t value) {
  _internal_set_max(value);
  // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.Bucket.max)
}

// optional int64 count = 4 [default = 1];
inline bool HistogramEventProto_Bucket::_internal_has_count() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool HistogramEventProto_Bucket::has_count() const {
  return _internal_has_count();
}
inline void HistogramEventProto_Bucket::clear_count() {
  count_ = int64_t{1};
  _has_bits_[0] &= ~0x00000004u;
}
inline int64_t HistogramEventProto_Bucket::_internal_count() const {
  return count_;
}
inline int64_t HistogramEventProto_Bucket::count() const {
  // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.Bucket.count)
  return _internal_count();
}
inline void HistogramEventProto_Bucket::_internal_set_count(int64_t value) {
  _has_bits_[0] |= 0x00000004u;
  count_ = value;
}
inline void HistogramEventProto_Bucket::set_count(int64_t value) {
  _internal_set_count(value);
  // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.Bucket.count)
}

// -------------------------------------------------------------------

// HistogramEventProto

// optional fixed64 name_hash = 1;
inline bool HistogramEventProto::_internal_has_name_hash() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool HistogramEventProto::has_name_hash() const {
  return _internal_has_name_hash();
}
inline void HistogramEventProto::clear_name_hash() {
  name_hash_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000001u;
}
inline uint64_t HistogramEventProto::_internal_name_hash() const {
  return name_hash_;
}
inline uint64_t HistogramEventProto::name_hash() const {
  // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.name_hash)
  return _internal_name_hash();
}
inline void HistogramEventProto::_internal_set_name_hash(uint64_t value) {
  _has_bits_[0] |= 0x00000001u;
  name_hash_ = value;
}
inline void HistogramEventProto::set_name_hash(uint64_t value) {
  _internal_set_name_hash(value);
  // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.name_hash)
}

// optional int64 sum = 2;
inline bool HistogramEventProto::_internal_has_sum() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool HistogramEventProto::has_sum() const {
  return _internal_has_sum();
}
inline void HistogramEventProto::clear_sum() {
  sum_ = int64_t{0};
  _has_bits_[0] &= ~0x00000002u;
}
inline int64_t HistogramEventProto::_internal_sum() const {
  return sum_;
}
inline int64_t HistogramEventProto::sum() const {
  // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.sum)
  return _internal_sum();
}
inline void HistogramEventProto::_internal_set_sum(int64_t value) {
  _has_bits_[0] |= 0x00000002u;
  sum_ = value;
}
inline void HistogramEventProto::set_sum(int64_t value) {
  _internal_set_sum(value);
  // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.sum)
}

// repeated .metrics.HistogramEventProto.Bucket bucket = 3;
inline int HistogramEventProto::_internal_bucket_size() const {
  return bucket_.size();
}
inline int HistogramEventProto::bucket_size() const {
  return _internal_bucket_size();
}
inline void HistogramEventProto::clear_bucket() {
  bucket_.Clear();
}
inline ::metrics::HistogramEventProto_Bucket* HistogramEventProto::mutable_bucket(int index) {
  // @@protoc_insertion_point(field_mutable:metrics.HistogramEventProto.bucket)
  return bucket_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::metrics::HistogramEventProto_Bucket >*
HistogramEventProto::mutable_bucket() {
  // @@protoc_insertion_point(field_mutable_list:metrics.HistogramEventProto.bucket)
  return &bucket_;
}
inline const ::metrics::HistogramEventProto_Bucket& HistogramEventProto::_internal_bucket(int index) const {
  return bucket_.Get(index);
}
inline const ::metrics::HistogramEventProto_Bucket& HistogramEventProto::bucket(int index) const {
  // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.bucket)
  return _internal_bucket(index);
}
inline ::metrics::HistogramEventProto_Bucket* HistogramEventProto::_internal_add_bucket() {
  return bucket_.Add();
}
inline ::metrics::HistogramEventProto_Bucket* HistogramEventProto::add_bucket() {
  ::metrics::HistogramEventProto_Bucket* _add = _internal_add_bucket();
  // @@protoc_insertion_point(field_add:metrics.HistogramEventProto.bucket)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::metrics::HistogramEventProto_Bucket >&
HistogramEventProto::bucket() const {
  // @@protoc_insertion_point(field_list:metrics.HistogramEventProto.bucket)
  return bucket_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace metrics

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_histogram_5fevent_2eproto

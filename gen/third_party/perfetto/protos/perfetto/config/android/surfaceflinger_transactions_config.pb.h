// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/config/android/surfaceflinger_transactions_config.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2fconfig_2fandroid_2fsurfaceflinger_5ftransactions_5fconfig_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2fconfig_2fandroid_2fsurfaceflinger_5ftransactions_5fconfig_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2fconfig_2fandroid_2fsurfaceflinger_5ftransactions_5fconfig_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protos_2fperfetto_2fconfig_2fandroid_2fsurfaceflinger_5ftransactions_5fconfig_2eproto {
  static const uint32_t offsets[];
};
namespace perfetto {
namespace protos {
class SurfaceFlingerTransactionsConfig;
struct SurfaceFlingerTransactionsConfigDefaultTypeInternal;
extern SurfaceFlingerTransactionsConfigDefaultTypeInternal _SurfaceFlingerTransactionsConfig_default_instance_;
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> ::perfetto::protos::SurfaceFlingerTransactionsConfig* Arena::CreateMaybeMessage<::perfetto::protos::SurfaceFlingerTransactionsConfig>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace perfetto {
namespace protos {

enum SurfaceFlingerTransactionsConfig_Mode : int {
  SurfaceFlingerTransactionsConfig_Mode_MODE_UNSPECIFIED = 0,
  SurfaceFlingerTransactionsConfig_Mode_MODE_CONTINUOUS = 1,
  SurfaceFlingerTransactionsConfig_Mode_MODE_ACTIVE = 2
};
bool SurfaceFlingerTransactionsConfig_Mode_IsValid(int value);
constexpr SurfaceFlingerTransactionsConfig_Mode SurfaceFlingerTransactionsConfig_Mode_Mode_MIN = SurfaceFlingerTransactionsConfig_Mode_MODE_UNSPECIFIED;
constexpr SurfaceFlingerTransactionsConfig_Mode SurfaceFlingerTransactionsConfig_Mode_Mode_MAX = SurfaceFlingerTransactionsConfig_Mode_MODE_ACTIVE;
constexpr int SurfaceFlingerTransactionsConfig_Mode_Mode_ARRAYSIZE = SurfaceFlingerTransactionsConfig_Mode_Mode_MAX + 1;

const std::string& SurfaceFlingerTransactionsConfig_Mode_Name(SurfaceFlingerTransactionsConfig_Mode value);
template<typename T>
inline const std::string& SurfaceFlingerTransactionsConfig_Mode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, SurfaceFlingerTransactionsConfig_Mode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function SurfaceFlingerTransactionsConfig_Mode_Name.");
  return SurfaceFlingerTransactionsConfig_Mode_Name(static_cast<SurfaceFlingerTransactionsConfig_Mode>(enum_t_value));
}
bool SurfaceFlingerTransactionsConfig_Mode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, SurfaceFlingerTransactionsConfig_Mode* value);
// ===================================================================

class SurfaceFlingerTransactionsConfig final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.SurfaceFlingerTransactionsConfig) */ {
 public:
  inline SurfaceFlingerTransactionsConfig() : SurfaceFlingerTransactionsConfig(nullptr) {}
  ~SurfaceFlingerTransactionsConfig() override;
  explicit PROTOBUF_CONSTEXPR SurfaceFlingerTransactionsConfig(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SurfaceFlingerTransactionsConfig(const SurfaceFlingerTransactionsConfig& from);
  SurfaceFlingerTransactionsConfig(SurfaceFlingerTransactionsConfig&& from) noexcept
    : SurfaceFlingerTransactionsConfig() {
    *this = ::std::move(from);
  }

  inline SurfaceFlingerTransactionsConfig& operator=(const SurfaceFlingerTransactionsConfig& from) {
    CopyFrom(from);
    return *this;
  }
  inline SurfaceFlingerTransactionsConfig& operator=(SurfaceFlingerTransactionsConfig&& from) noexcept {
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

  static const SurfaceFlingerTransactionsConfig& default_instance() {
    return *internal_default_instance();
  }
  static inline const SurfaceFlingerTransactionsConfig* internal_default_instance() {
    return reinterpret_cast<const SurfaceFlingerTransactionsConfig*>(
               &_SurfaceFlingerTransactionsConfig_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SurfaceFlingerTransactionsConfig& a, SurfaceFlingerTransactionsConfig& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(SurfaceFlingerTransactionsConfig* other) {
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
  void UnsafeArenaSwap(SurfaceFlingerTransactionsConfig* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SurfaceFlingerTransactionsConfig* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<SurfaceFlingerTransactionsConfig>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const SurfaceFlingerTransactionsConfig& from);
  void MergeFrom(const SurfaceFlingerTransactionsConfig& from);
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
  void InternalSwap(SurfaceFlingerTransactionsConfig* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.SurfaceFlingerTransactionsConfig";
  }
  protected:
  explicit SurfaceFlingerTransactionsConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  typedef SurfaceFlingerTransactionsConfig_Mode Mode;
  static constexpr Mode MODE_UNSPECIFIED =
    SurfaceFlingerTransactionsConfig_Mode_MODE_UNSPECIFIED;
  static constexpr Mode MODE_CONTINUOUS =
    SurfaceFlingerTransactionsConfig_Mode_MODE_CONTINUOUS;
  static constexpr Mode MODE_ACTIVE =
    SurfaceFlingerTransactionsConfig_Mode_MODE_ACTIVE;
  static inline bool Mode_IsValid(int value) {
    return SurfaceFlingerTransactionsConfig_Mode_IsValid(value);
  }
  static constexpr Mode Mode_MIN =
    SurfaceFlingerTransactionsConfig_Mode_Mode_MIN;
  static constexpr Mode Mode_MAX =
    SurfaceFlingerTransactionsConfig_Mode_Mode_MAX;
  static constexpr int Mode_ARRAYSIZE =
    SurfaceFlingerTransactionsConfig_Mode_Mode_ARRAYSIZE;
  template<typename T>
  static inline const std::string& Mode_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Mode>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Mode_Name.");
    return SurfaceFlingerTransactionsConfig_Mode_Name(enum_t_value);
  }
  static inline bool Mode_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      Mode* value) {
    return SurfaceFlingerTransactionsConfig_Mode_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kModeFieldNumber = 1,
  };
  // optional .perfetto.protos.SurfaceFlingerTransactionsConfig.Mode mode = 1;
  bool has_mode() const;
  private:
  bool _internal_has_mode() const;
  public:
  void clear_mode();
  ::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode mode() const;
  void set_mode(::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode value);
  private:
  ::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode _internal_mode() const;
  void _internal_set_mode(::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode value);
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.SurfaceFlingerTransactionsConfig)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  int mode_;
  friend struct ::TableStruct_protos_2fperfetto_2fconfig_2fandroid_2fsurfaceflinger_5ftransactions_5fconfig_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SurfaceFlingerTransactionsConfig

// optional .perfetto.protos.SurfaceFlingerTransactionsConfig.Mode mode = 1;
inline bool SurfaceFlingerTransactionsConfig::_internal_has_mode() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool SurfaceFlingerTransactionsConfig::has_mode() const {
  return _internal_has_mode();
}
inline void SurfaceFlingerTransactionsConfig::clear_mode() {
  mode_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode SurfaceFlingerTransactionsConfig::_internal_mode() const {
  return static_cast< ::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode >(mode_);
}
inline ::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode SurfaceFlingerTransactionsConfig::mode() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.SurfaceFlingerTransactionsConfig.mode)
  return _internal_mode();
}
inline void SurfaceFlingerTransactionsConfig::_internal_set_mode(::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode value) {
  assert(::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode_IsValid(value));
  _has_bits_[0] |= 0x00000001u;
  mode_ = value;
}
inline void SurfaceFlingerTransactionsConfig::set_mode(::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode value) {
  _internal_set_mode(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.SurfaceFlingerTransactionsConfig.mode)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace perfetto

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::perfetto::protos::SurfaceFlingerTransactionsConfig_Mode> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2fconfig_2fandroid_2fsurfaceflinger_5ftransactions_5fconfig_2eproto
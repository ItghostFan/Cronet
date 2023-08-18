// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/power/power_rails.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto {
  static const uint32_t offsets[];
};
namespace perfetto {
namespace protos {
class PowerRails;
struct PowerRailsDefaultTypeInternal;
extern PowerRailsDefaultTypeInternal _PowerRails_default_instance_;
class PowerRails_EnergyData;
struct PowerRails_EnergyDataDefaultTypeInternal;
extern PowerRails_EnergyDataDefaultTypeInternal _PowerRails_EnergyData_default_instance_;
class PowerRails_RailDescriptor;
struct PowerRails_RailDescriptorDefaultTypeInternal;
extern PowerRails_RailDescriptorDefaultTypeInternal _PowerRails_RailDescriptor_default_instance_;
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> ::perfetto::protos::PowerRails* Arena::CreateMaybeMessage<::perfetto::protos::PowerRails>(Arena*);
template<> ::perfetto::protos::PowerRails_EnergyData* Arena::CreateMaybeMessage<::perfetto::protos::PowerRails_EnergyData>(Arena*);
template<> ::perfetto::protos::PowerRails_RailDescriptor* Arena::CreateMaybeMessage<::perfetto::protos::PowerRails_RailDescriptor>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace perfetto {
namespace protos {

// ===================================================================

class PowerRails_RailDescriptor final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.PowerRails.RailDescriptor) */ {
 public:
  inline PowerRails_RailDescriptor() : PowerRails_RailDescriptor(nullptr) {}
  ~PowerRails_RailDescriptor() override;
  explicit PROTOBUF_CONSTEXPR PowerRails_RailDescriptor(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PowerRails_RailDescriptor(const PowerRails_RailDescriptor& from);
  PowerRails_RailDescriptor(PowerRails_RailDescriptor&& from) noexcept
    : PowerRails_RailDescriptor() {
    *this = ::std::move(from);
  }

  inline PowerRails_RailDescriptor& operator=(const PowerRails_RailDescriptor& from) {
    CopyFrom(from);
    return *this;
  }
  inline PowerRails_RailDescriptor& operator=(PowerRails_RailDescriptor&& from) noexcept {
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

  static const PowerRails_RailDescriptor& default_instance() {
    return *internal_default_instance();
  }
  static inline const PowerRails_RailDescriptor* internal_default_instance() {
    return reinterpret_cast<const PowerRails_RailDescriptor*>(
               &_PowerRails_RailDescriptor_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PowerRails_RailDescriptor& a, PowerRails_RailDescriptor& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(PowerRails_RailDescriptor* other) {
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
  void UnsafeArenaSwap(PowerRails_RailDescriptor* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PowerRails_RailDescriptor* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PowerRails_RailDescriptor>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const PowerRails_RailDescriptor& from);
  void MergeFrom(const PowerRails_RailDescriptor& from);
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
  void InternalSwap(PowerRails_RailDescriptor* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.PowerRails.RailDescriptor";
  }
  protected:
  explicit PowerRails_RailDescriptor(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRailNameFieldNumber = 2,
    kSubsysNameFieldNumber = 3,
    kIndexFieldNumber = 1,
    kSamplingRateFieldNumber = 4,
  };
  // optional string rail_name = 2;
  bool has_rail_name() const;
  private:
  bool _internal_has_rail_name() const;
  public:
  void clear_rail_name();
  const std::string& rail_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_rail_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_rail_name();
  PROTOBUF_NODISCARD std::string* release_rail_name();
  void set_allocated_rail_name(std::string* rail_name);
  private:
  const std::string& _internal_rail_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_rail_name(const std::string& value);
  std::string* _internal_mutable_rail_name();
  public:

  // optional string subsys_name = 3;
  bool has_subsys_name() const;
  private:
  bool _internal_has_subsys_name() const;
  public:
  void clear_subsys_name();
  const std::string& subsys_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_subsys_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_subsys_name();
  PROTOBUF_NODISCARD std::string* release_subsys_name();
  void set_allocated_subsys_name(std::string* subsys_name);
  private:
  const std::string& _internal_subsys_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_subsys_name(const std::string& value);
  std::string* _internal_mutable_subsys_name();
  public:

  // optional uint32 index = 1;
  bool has_index() const;
  private:
  bool _internal_has_index() const;
  public:
  void clear_index();
  uint32_t index() const;
  void set_index(uint32_t value);
  private:
  uint32_t _internal_index() const;
  void _internal_set_index(uint32_t value);
  public:

  // optional uint32 sampling_rate = 4;
  bool has_sampling_rate() const;
  private:
  bool _internal_has_sampling_rate() const;
  public:
  void clear_sampling_rate();
  uint32_t sampling_rate() const;
  void set_sampling_rate(uint32_t value);
  private:
  uint32_t _internal_sampling_rate() const;
  void _internal_set_sampling_rate(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.PowerRails.RailDescriptor)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr rail_name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr subsys_name_;
  uint32_t index_;
  uint32_t sampling_rate_;
  friend struct ::TableStruct_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto;
};
// -------------------------------------------------------------------

class PowerRails_EnergyData final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.PowerRails.EnergyData) */ {
 public:
  inline PowerRails_EnergyData() : PowerRails_EnergyData(nullptr) {}
  ~PowerRails_EnergyData() override;
  explicit PROTOBUF_CONSTEXPR PowerRails_EnergyData(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PowerRails_EnergyData(const PowerRails_EnergyData& from);
  PowerRails_EnergyData(PowerRails_EnergyData&& from) noexcept
    : PowerRails_EnergyData() {
    *this = ::std::move(from);
  }

  inline PowerRails_EnergyData& operator=(const PowerRails_EnergyData& from) {
    CopyFrom(from);
    return *this;
  }
  inline PowerRails_EnergyData& operator=(PowerRails_EnergyData&& from) noexcept {
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

  static const PowerRails_EnergyData& default_instance() {
    return *internal_default_instance();
  }
  static inline const PowerRails_EnergyData* internal_default_instance() {
    return reinterpret_cast<const PowerRails_EnergyData*>(
               &_PowerRails_EnergyData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PowerRails_EnergyData& a, PowerRails_EnergyData& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(PowerRails_EnergyData* other) {
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
  void UnsafeArenaSwap(PowerRails_EnergyData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PowerRails_EnergyData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PowerRails_EnergyData>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const PowerRails_EnergyData& from);
  void MergeFrom(const PowerRails_EnergyData& from);
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
  void InternalSwap(PowerRails_EnergyData* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.PowerRails.EnergyData";
  }
  protected:
  explicit PowerRails_EnergyData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTimestampMsFieldNumber = 2,
    kEnergyFieldNumber = 3,
    kIndexFieldNumber = 1,
  };
  // optional uint64 timestamp_ms = 2;
  bool has_timestamp_ms() const;
  private:
  bool _internal_has_timestamp_ms() const;
  public:
  void clear_timestamp_ms();
  uint64_t timestamp_ms() const;
  void set_timestamp_ms(uint64_t value);
  private:
  uint64_t _internal_timestamp_ms() const;
  void _internal_set_timestamp_ms(uint64_t value);
  public:

  // optional uint64 energy = 3;
  bool has_energy() const;
  private:
  bool _internal_has_energy() const;
  public:
  void clear_energy();
  uint64_t energy() const;
  void set_energy(uint64_t value);
  private:
  uint64_t _internal_energy() const;
  void _internal_set_energy(uint64_t value);
  public:

  // optional uint32 index = 1;
  bool has_index() const;
  private:
  bool _internal_has_index() const;
  public:
  void clear_index();
  uint32_t index() const;
  void set_index(uint32_t value);
  private:
  uint32_t _internal_index() const;
  void _internal_set_index(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.PowerRails.EnergyData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  uint64_t timestamp_ms_;
  uint64_t energy_;
  uint32_t index_;
  friend struct ::TableStruct_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto;
};
// -------------------------------------------------------------------

class PowerRails final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.PowerRails) */ {
 public:
  inline PowerRails() : PowerRails(nullptr) {}
  ~PowerRails() override;
  explicit PROTOBUF_CONSTEXPR PowerRails(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PowerRails(const PowerRails& from);
  PowerRails(PowerRails&& from) noexcept
    : PowerRails() {
    *this = ::std::move(from);
  }

  inline PowerRails& operator=(const PowerRails& from) {
    CopyFrom(from);
    return *this;
  }
  inline PowerRails& operator=(PowerRails&& from) noexcept {
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

  static const PowerRails& default_instance() {
    return *internal_default_instance();
  }
  static inline const PowerRails* internal_default_instance() {
    return reinterpret_cast<const PowerRails*>(
               &_PowerRails_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(PowerRails& a, PowerRails& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(PowerRails* other) {
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
  void UnsafeArenaSwap(PowerRails* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PowerRails* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PowerRails>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const PowerRails& from);
  void MergeFrom(const PowerRails& from);
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
  void InternalSwap(PowerRails* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.PowerRails";
  }
  protected:
  explicit PowerRails(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  typedef PowerRails_RailDescriptor RailDescriptor;
  typedef PowerRails_EnergyData EnergyData;

  // accessors -------------------------------------------------------

  enum : int {
    kRailDescriptorFieldNumber = 1,
    kEnergyDataFieldNumber = 2,
  };
  // repeated .perfetto.protos.PowerRails.RailDescriptor rail_descriptor = 1;
  int rail_descriptor_size() const;
  private:
  int _internal_rail_descriptor_size() const;
  public:
  void clear_rail_descriptor();
  ::perfetto::protos::PowerRails_RailDescriptor* mutable_rail_descriptor(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_RailDescriptor >*
      mutable_rail_descriptor();
  private:
  const ::perfetto::protos::PowerRails_RailDescriptor& _internal_rail_descriptor(int index) const;
  ::perfetto::protos::PowerRails_RailDescriptor* _internal_add_rail_descriptor();
  public:
  const ::perfetto::protos::PowerRails_RailDescriptor& rail_descriptor(int index) const;
  ::perfetto::protos::PowerRails_RailDescriptor* add_rail_descriptor();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_RailDescriptor >&
      rail_descriptor() const;

  // repeated .perfetto.protos.PowerRails.EnergyData energy_data = 2;
  int energy_data_size() const;
  private:
  int _internal_energy_data_size() const;
  public:
  void clear_energy_data();
  ::perfetto::protos::PowerRails_EnergyData* mutable_energy_data(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_EnergyData >*
      mutable_energy_data();
  private:
  const ::perfetto::protos::PowerRails_EnergyData& _internal_energy_data(int index) const;
  ::perfetto::protos::PowerRails_EnergyData* _internal_add_energy_data();
  public:
  const ::perfetto::protos::PowerRails_EnergyData& energy_data(int index) const;
  ::perfetto::protos::PowerRails_EnergyData* add_energy_data();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_EnergyData >&
      energy_data() const;

  // @@protoc_insertion_point(class_scope:perfetto.protos.PowerRails)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_RailDescriptor > rail_descriptor_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_EnergyData > energy_data_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PowerRails_RailDescriptor

// optional uint32 index = 1;
inline bool PowerRails_RailDescriptor::_internal_has_index() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool PowerRails_RailDescriptor::has_index() const {
  return _internal_has_index();
}
inline void PowerRails_RailDescriptor::clear_index() {
  index_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline uint32_t PowerRails_RailDescriptor::_internal_index() const {
  return index_;
}
inline uint32_t PowerRails_RailDescriptor::index() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.RailDescriptor.index)
  return _internal_index();
}
inline void PowerRails_RailDescriptor::_internal_set_index(uint32_t value) {
  _has_bits_[0] |= 0x00000004u;
  index_ = value;
}
inline void PowerRails_RailDescriptor::set_index(uint32_t value) {
  _internal_set_index(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.PowerRails.RailDescriptor.index)
}

// optional string rail_name = 2;
inline bool PowerRails_RailDescriptor::_internal_has_rail_name() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool PowerRails_RailDescriptor::has_rail_name() const {
  return _internal_has_rail_name();
}
inline void PowerRails_RailDescriptor::clear_rail_name() {
  rail_name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& PowerRails_RailDescriptor::rail_name() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.RailDescriptor.rail_name)
  return _internal_rail_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PowerRails_RailDescriptor::set_rail_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 rail_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:perfetto.protos.PowerRails.RailDescriptor.rail_name)
}
inline std::string* PowerRails_RailDescriptor::mutable_rail_name() {
  std::string* _s = _internal_mutable_rail_name();
  // @@protoc_insertion_point(field_mutable:perfetto.protos.PowerRails.RailDescriptor.rail_name)
  return _s;
}
inline const std::string& PowerRails_RailDescriptor::_internal_rail_name() const {
  return rail_name_.Get();
}
inline void PowerRails_RailDescriptor::_internal_set_rail_name(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  rail_name_.Set(value, GetArenaForAllocation());
}
inline std::string* PowerRails_RailDescriptor::_internal_mutable_rail_name() {
  _has_bits_[0] |= 0x00000001u;
  return rail_name_.Mutable(GetArenaForAllocation());
}
inline std::string* PowerRails_RailDescriptor::release_rail_name() {
  // @@protoc_insertion_point(field_release:perfetto.protos.PowerRails.RailDescriptor.rail_name)
  if (!_internal_has_rail_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = rail_name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (rail_name_.IsDefault()) {
    rail_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void PowerRails_RailDescriptor::set_allocated_rail_name(std::string* rail_name) {
  if (rail_name != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  rail_name_.SetAllocated(rail_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (rail_name_.IsDefault()) {
    rail_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:perfetto.protos.PowerRails.RailDescriptor.rail_name)
}

// optional string subsys_name = 3;
inline bool PowerRails_RailDescriptor::_internal_has_subsys_name() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool PowerRails_RailDescriptor::has_subsys_name() const {
  return _internal_has_subsys_name();
}
inline void PowerRails_RailDescriptor::clear_subsys_name() {
  subsys_name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& PowerRails_RailDescriptor::subsys_name() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.RailDescriptor.subsys_name)
  return _internal_subsys_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PowerRails_RailDescriptor::set_subsys_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 subsys_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:perfetto.protos.PowerRails.RailDescriptor.subsys_name)
}
inline std::string* PowerRails_RailDescriptor::mutable_subsys_name() {
  std::string* _s = _internal_mutable_subsys_name();
  // @@protoc_insertion_point(field_mutable:perfetto.protos.PowerRails.RailDescriptor.subsys_name)
  return _s;
}
inline const std::string& PowerRails_RailDescriptor::_internal_subsys_name() const {
  return subsys_name_.Get();
}
inline void PowerRails_RailDescriptor::_internal_set_subsys_name(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  subsys_name_.Set(value, GetArenaForAllocation());
}
inline std::string* PowerRails_RailDescriptor::_internal_mutable_subsys_name() {
  _has_bits_[0] |= 0x00000002u;
  return subsys_name_.Mutable(GetArenaForAllocation());
}
inline std::string* PowerRails_RailDescriptor::release_subsys_name() {
  // @@protoc_insertion_point(field_release:perfetto.protos.PowerRails.RailDescriptor.subsys_name)
  if (!_internal_has_subsys_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  auto* p = subsys_name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (subsys_name_.IsDefault()) {
    subsys_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void PowerRails_RailDescriptor::set_allocated_subsys_name(std::string* subsys_name) {
  if (subsys_name != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  subsys_name_.SetAllocated(subsys_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (subsys_name_.IsDefault()) {
    subsys_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:perfetto.protos.PowerRails.RailDescriptor.subsys_name)
}

// optional uint32 sampling_rate = 4;
inline bool PowerRails_RailDescriptor::_internal_has_sampling_rate() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool PowerRails_RailDescriptor::has_sampling_rate() const {
  return _internal_has_sampling_rate();
}
inline void PowerRails_RailDescriptor::clear_sampling_rate() {
  sampling_rate_ = 0u;
  _has_bits_[0] &= ~0x00000008u;
}
inline uint32_t PowerRails_RailDescriptor::_internal_sampling_rate() const {
  return sampling_rate_;
}
inline uint32_t PowerRails_RailDescriptor::sampling_rate() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.RailDescriptor.sampling_rate)
  return _internal_sampling_rate();
}
inline void PowerRails_RailDescriptor::_internal_set_sampling_rate(uint32_t value) {
  _has_bits_[0] |= 0x00000008u;
  sampling_rate_ = value;
}
inline void PowerRails_RailDescriptor::set_sampling_rate(uint32_t value) {
  _internal_set_sampling_rate(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.PowerRails.RailDescriptor.sampling_rate)
}

// -------------------------------------------------------------------

// PowerRails_EnergyData

// optional uint32 index = 1;
inline bool PowerRails_EnergyData::_internal_has_index() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool PowerRails_EnergyData::has_index() const {
  return _internal_has_index();
}
inline void PowerRails_EnergyData::clear_index() {
  index_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline uint32_t PowerRails_EnergyData::_internal_index() const {
  return index_;
}
inline uint32_t PowerRails_EnergyData::index() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.EnergyData.index)
  return _internal_index();
}
inline void PowerRails_EnergyData::_internal_set_index(uint32_t value) {
  _has_bits_[0] |= 0x00000004u;
  index_ = value;
}
inline void PowerRails_EnergyData::set_index(uint32_t value) {
  _internal_set_index(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.PowerRails.EnergyData.index)
}

// optional uint64 timestamp_ms = 2;
inline bool PowerRails_EnergyData::_internal_has_timestamp_ms() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool PowerRails_EnergyData::has_timestamp_ms() const {
  return _internal_has_timestamp_ms();
}
inline void PowerRails_EnergyData::clear_timestamp_ms() {
  timestamp_ms_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000001u;
}
inline uint64_t PowerRails_EnergyData::_internal_timestamp_ms() const {
  return timestamp_ms_;
}
inline uint64_t PowerRails_EnergyData::timestamp_ms() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.EnergyData.timestamp_ms)
  return _internal_timestamp_ms();
}
inline void PowerRails_EnergyData::_internal_set_timestamp_ms(uint64_t value) {
  _has_bits_[0] |= 0x00000001u;
  timestamp_ms_ = value;
}
inline void PowerRails_EnergyData::set_timestamp_ms(uint64_t value) {
  _internal_set_timestamp_ms(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.PowerRails.EnergyData.timestamp_ms)
}

// optional uint64 energy = 3;
inline bool PowerRails_EnergyData::_internal_has_energy() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool PowerRails_EnergyData::has_energy() const {
  return _internal_has_energy();
}
inline void PowerRails_EnergyData::clear_energy() {
  energy_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000002u;
}
inline uint64_t PowerRails_EnergyData::_internal_energy() const {
  return energy_;
}
inline uint64_t PowerRails_EnergyData::energy() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.EnergyData.energy)
  return _internal_energy();
}
inline void PowerRails_EnergyData::_internal_set_energy(uint64_t value) {
  _has_bits_[0] |= 0x00000002u;
  energy_ = value;
}
inline void PowerRails_EnergyData::set_energy(uint64_t value) {
  _internal_set_energy(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.PowerRails.EnergyData.energy)
}

// -------------------------------------------------------------------

// PowerRails

// repeated .perfetto.protos.PowerRails.RailDescriptor rail_descriptor = 1;
inline int PowerRails::_internal_rail_descriptor_size() const {
  return rail_descriptor_.size();
}
inline int PowerRails::rail_descriptor_size() const {
  return _internal_rail_descriptor_size();
}
inline void PowerRails::clear_rail_descriptor() {
  rail_descriptor_.Clear();
}
inline ::perfetto::protos::PowerRails_RailDescriptor* PowerRails::mutable_rail_descriptor(int index) {
  // @@protoc_insertion_point(field_mutable:perfetto.protos.PowerRails.rail_descriptor)
  return rail_descriptor_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_RailDescriptor >*
PowerRails::mutable_rail_descriptor() {
  // @@protoc_insertion_point(field_mutable_list:perfetto.protos.PowerRails.rail_descriptor)
  return &rail_descriptor_;
}
inline const ::perfetto::protos::PowerRails_RailDescriptor& PowerRails::_internal_rail_descriptor(int index) const {
  return rail_descriptor_.Get(index);
}
inline const ::perfetto::protos::PowerRails_RailDescriptor& PowerRails::rail_descriptor(int index) const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.rail_descriptor)
  return _internal_rail_descriptor(index);
}
inline ::perfetto::protos::PowerRails_RailDescriptor* PowerRails::_internal_add_rail_descriptor() {
  return rail_descriptor_.Add();
}
inline ::perfetto::protos::PowerRails_RailDescriptor* PowerRails::add_rail_descriptor() {
  ::perfetto::protos::PowerRails_RailDescriptor* _add = _internal_add_rail_descriptor();
  // @@protoc_insertion_point(field_add:perfetto.protos.PowerRails.rail_descriptor)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_RailDescriptor >&
PowerRails::rail_descriptor() const {
  // @@protoc_insertion_point(field_list:perfetto.protos.PowerRails.rail_descriptor)
  return rail_descriptor_;
}

// repeated .perfetto.protos.PowerRails.EnergyData energy_data = 2;
inline int PowerRails::_internal_energy_data_size() const {
  return energy_data_.size();
}
inline int PowerRails::energy_data_size() const {
  return _internal_energy_data_size();
}
inline void PowerRails::clear_energy_data() {
  energy_data_.Clear();
}
inline ::perfetto::protos::PowerRails_EnergyData* PowerRails::mutable_energy_data(int index) {
  // @@protoc_insertion_point(field_mutable:perfetto.protos.PowerRails.energy_data)
  return energy_data_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_EnergyData >*
PowerRails::mutable_energy_data() {
  // @@protoc_insertion_point(field_mutable_list:perfetto.protos.PowerRails.energy_data)
  return &energy_data_;
}
inline const ::perfetto::protos::PowerRails_EnergyData& PowerRails::_internal_energy_data(int index) const {
  return energy_data_.Get(index);
}
inline const ::perfetto::protos::PowerRails_EnergyData& PowerRails::energy_data(int index) const {
  // @@protoc_insertion_point(field_get:perfetto.protos.PowerRails.energy_data)
  return _internal_energy_data(index);
}
inline ::perfetto::protos::PowerRails_EnergyData* PowerRails::_internal_add_energy_data() {
  return energy_data_.Add();
}
inline ::perfetto::protos::PowerRails_EnergyData* PowerRails::add_energy_data() {
  ::perfetto::protos::PowerRails_EnergyData* _add = _internal_add_energy_data();
  // @@protoc_insertion_point(field_add:perfetto.protos.PowerRails.energy_data)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::PowerRails_EnergyData >&
PowerRails::energy_data() const {
  // @@protoc_insertion_point(field_list:perfetto.protos.PowerRails.energy_data)
  return energy_data_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace perfetto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2fpower_2fpower_5frails_2eproto

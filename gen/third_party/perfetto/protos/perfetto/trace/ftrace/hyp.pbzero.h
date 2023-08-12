// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_HYP_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_HYP_PROTO_H_

#include <stddef.h>
#include <stdint.h>

#include "perfetto/protozero/field_writer.h"
#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/proto_utils.h"

namespace perfetto {
namespace protos {
namespace pbzero {


class HostMemAbortFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  HostMemAbortFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit HostMemAbortFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit HostMemAbortFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_esr() const { return at<1>().valid(); }
  uint64_t esr() const { return at<1>().as_uint64(); }
  bool has_addr() const { return at<2>().valid(); }
  uint64_t addr() const { return at<2>().as_uint64(); }
};

class HostMemAbortFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = HostMemAbortFtraceEvent_Decoder;
  enum : int32_t {
    kEsrFieldNumber = 1,
    kAddrFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.HostMemAbortFtraceEvent"; }


  using FieldMetadata_Esr =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      HostMemAbortFtraceEvent>;

  static constexpr FieldMetadata_Esr kEsr{};
  void set_esr(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Esr::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Addr =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      HostMemAbortFtraceEvent>;

  static constexpr FieldMetadata_Addr kAddr{};
  void set_addr(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Addr::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }
};

class HostSmcFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  HostSmcFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit HostSmcFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit HostSmcFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_id() const { return at<1>().valid(); }
  uint64_t id() const { return at<1>().as_uint64(); }
  bool has_forwarded() const { return at<2>().valid(); }
  uint32_t forwarded() const { return at<2>().as_uint32(); }
};

class HostSmcFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = HostSmcFtraceEvent_Decoder;
  enum : int32_t {
    kIdFieldNumber = 1,
    kForwardedFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.HostSmcFtraceEvent"; }


  using FieldMetadata_Id =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      HostSmcFtraceEvent>;

  static constexpr FieldMetadata_Id kId{};
  void set_id(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Id::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Forwarded =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      HostSmcFtraceEvent>;

  static constexpr FieldMetadata_Forwarded kForwarded{};
  void set_forwarded(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Forwarded::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }
};

class HostHcallFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  HostHcallFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit HostHcallFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit HostHcallFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_id() const { return at<1>().valid(); }
  uint32_t id() const { return at<1>().as_uint32(); }
  bool has_invalid() const { return at<2>().valid(); }
  uint32_t invalid() const { return at<2>().as_uint32(); }
};

class HostHcallFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = HostHcallFtraceEvent_Decoder;
  enum : int32_t {
    kIdFieldNumber = 1,
    kInvalidFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.HostHcallFtraceEvent"; }


  using FieldMetadata_Id =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      HostHcallFtraceEvent>;

  static constexpr FieldMetadata_Id kId{};
  void set_id(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Id::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Invalid =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      HostHcallFtraceEvent>;

  static constexpr FieldMetadata_Invalid kInvalid{};
  void set_invalid(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Invalid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }
};

class HypExitFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/0, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  HypExitFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit HypExitFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit HypExitFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
};

class HypExitFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = HypExitFtraceEvent_Decoder;
  static constexpr const char* GetName() { return ".perfetto.protos.HypExitFtraceEvent"; }

};

class HypEnterFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/0, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  HypEnterFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit HypEnterFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit HypEnterFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
};

class HypEnterFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = HypEnterFtraceEvent_Decoder;
  static constexpr const char* GetName() { return ".perfetto.protos.HypEnterFtraceEvent"; }

};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_SOCK_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_FTRACE_SOCK_PROTO_H_

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


class InetSockSetStateFtraceEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/9, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  InetSockSetStateFtraceEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit InetSockSetStateFtraceEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit InetSockSetStateFtraceEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_daddr() const { return at<1>().valid(); }
  uint32_t daddr() const { return at<1>().as_uint32(); }
  bool has_dport() const { return at<2>().valid(); }
  uint32_t dport() const { return at<2>().as_uint32(); }
  bool has_family() const { return at<3>().valid(); }
  uint32_t family() const { return at<3>().as_uint32(); }
  bool has_newstate() const { return at<4>().valid(); }
  int32_t newstate() const { return at<4>().as_int32(); }
  bool has_oldstate() const { return at<5>().valid(); }
  int32_t oldstate() const { return at<5>().as_int32(); }
  bool has_protocol() const { return at<6>().valid(); }
  uint32_t protocol() const { return at<6>().as_uint32(); }
  bool has_saddr() const { return at<7>().valid(); }
  uint32_t saddr() const { return at<7>().as_uint32(); }
  bool has_skaddr() const { return at<8>().valid(); }
  uint64_t skaddr() const { return at<8>().as_uint64(); }
  bool has_sport() const { return at<9>().valid(); }
  uint32_t sport() const { return at<9>().as_uint32(); }
};

class InetSockSetStateFtraceEvent : public ::protozero::Message {
 public:
  using Decoder = InetSockSetStateFtraceEvent_Decoder;
  enum : int32_t {
    kDaddrFieldNumber = 1,
    kDportFieldNumber = 2,
    kFamilyFieldNumber = 3,
    kNewstateFieldNumber = 4,
    kOldstateFieldNumber = 5,
    kProtocolFieldNumber = 6,
    kSaddrFieldNumber = 7,
    kSkaddrFieldNumber = 8,
    kSportFieldNumber = 9,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.InetSockSetStateFtraceEvent"; }


  using FieldMetadata_Daddr =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Daddr kDaddr{};
  void set_daddr(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Daddr::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Dport =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Dport kDport{};
  void set_dport(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Dport::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Family =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Family kFamily{};
  void set_family(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Family::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Newstate =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Newstate kNewstate{};
  void set_newstate(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Newstate::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Oldstate =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Oldstate kOldstate{};
  void set_oldstate(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Oldstate::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Protocol =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Protocol kProtocol{};
  void set_protocol(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Protocol::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Saddr =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Saddr kSaddr{};
  void set_saddr(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Saddr::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Skaddr =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Skaddr kSkaddr{};
  void set_skaddr(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Skaddr::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Sport =
    ::protozero::proto_utils::FieldMetadata<
      9,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      InetSockSetStateFtraceEvent>;

  static constexpr FieldMetadata_Sport kSport{};
  void set_sport(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Sport::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
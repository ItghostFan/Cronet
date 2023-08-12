// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_ANDROID_NETWORK_TRACE_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_ANDROID_NETWORK_TRACE_PROTO_H_

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

class NetworkPacketEvent;
enum TrafficDirection : int32_t;

enum TrafficDirection : int32_t {
  DIR_UNSPECIFIED = 0,
  DIR_INGRESS = 1,
  DIR_EGRESS = 2,
};

constexpr TrafficDirection TrafficDirection_MIN = TrafficDirection::DIR_UNSPECIFIED;
constexpr TrafficDirection TrafficDirection_MAX = TrafficDirection::DIR_EGRESS;


PERFETTO_PROTOZERO_CONSTEXPR14_OR_INLINE
const char* TrafficDirection_Name(::perfetto::protos::pbzero::TrafficDirection value) {
  switch (value) {
  case ::perfetto::protos::pbzero::TrafficDirection::DIR_UNSPECIFIED:
    return "DIR_UNSPECIFIED";

  case ::perfetto::protos::pbzero::TrafficDirection::DIR_INGRESS:
    return "DIR_INGRESS";

  case ::perfetto::protos::pbzero::TrafficDirection::DIR_EGRESS:
    return "DIR_EGRESS";
  }
  return "PBZERO_UNKNOWN_ENUM_VALUE";
}

class NetworkPacketContext_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  NetworkPacketContext_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit NetworkPacketContext_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit NetworkPacketContext_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_iid() const { return at<1>().valid(); }
  uint64_t iid() const { return at<1>().as_uint64(); }
  bool has_ctx() const { return at<2>().valid(); }
  ::protozero::ConstBytes ctx() const { return at<2>().as_bytes(); }
};

class NetworkPacketContext : public ::protozero::Message {
 public:
  using Decoder = NetworkPacketContext_Decoder;
  enum : int32_t {
    kIidFieldNumber = 1,
    kCtxFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.NetworkPacketContext"; }


  using FieldMetadata_Iid =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      NetworkPacketContext>;

  static constexpr FieldMetadata_Iid kIid{};
  void set_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Iid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Ctx =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      NetworkPacketEvent,
      NetworkPacketContext>;

  static constexpr FieldMetadata_Ctx kCtx{};
  template <typename T = NetworkPacketEvent> T* set_ctx() {
    return BeginNestedMessage<T>(2);
  }

};

class NetworkPacketBundle_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/7, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  NetworkPacketBundle_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit NetworkPacketBundle_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit NetworkPacketBundle_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_iid() const { return at<1>().valid(); }
  uint64_t iid() const { return at<1>().as_uint64(); }
  bool has_ctx() const { return at<2>().valid(); }
  ::protozero::ConstBytes ctx() const { return at<2>().as_bytes(); }
  bool has_packet_timestamps() const { return at<3>().valid(); }
  ::protozero::PackedRepeatedFieldIterator<::protozero::proto_utils::ProtoWireType::kVarInt, uint64_t> packet_timestamps(bool* parse_error_ptr) const { return GetPackedRepeated<::protozero::proto_utils::ProtoWireType::kVarInt, uint64_t>(3, parse_error_ptr); }
  bool has_packet_lengths() const { return at<4>().valid(); }
  ::protozero::PackedRepeatedFieldIterator<::protozero::proto_utils::ProtoWireType::kVarInt, uint32_t> packet_lengths(bool* parse_error_ptr) const { return GetPackedRepeated<::protozero::proto_utils::ProtoWireType::kVarInt, uint32_t>(4, parse_error_ptr); }
  bool has_total_packets() const { return at<5>().valid(); }
  uint32_t total_packets() const { return at<5>().as_uint32(); }
  bool has_total_duration() const { return at<6>().valid(); }
  uint64_t total_duration() const { return at<6>().as_uint64(); }
  bool has_total_length() const { return at<7>().valid(); }
  uint64_t total_length() const { return at<7>().as_uint64(); }
};

class NetworkPacketBundle : public ::protozero::Message {
 public:
  using Decoder = NetworkPacketBundle_Decoder;
  enum : int32_t {
    kIidFieldNumber = 1,
    kCtxFieldNumber = 2,
    kPacketTimestampsFieldNumber = 3,
    kPacketLengthsFieldNumber = 4,
    kTotalPacketsFieldNumber = 5,
    kTotalDurationFieldNumber = 6,
    kTotalLengthFieldNumber = 7,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.NetworkPacketBundle"; }


  using FieldMetadata_Iid =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      NetworkPacketBundle>;

  static constexpr FieldMetadata_Iid kIid{};
  void set_iid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Iid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Ctx =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      NetworkPacketEvent,
      NetworkPacketBundle>;

  static constexpr FieldMetadata_Ctx kCtx{};
  template <typename T = NetworkPacketEvent> T* set_ctx() {
    return BeginNestedMessage<T>(2);
  }


  using FieldMetadata_PacketTimestamps =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kRepeatedPacked,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      NetworkPacketBundle>;

  static constexpr FieldMetadata_PacketTimestamps kPacketTimestamps{};
  void set_packet_timestamps(const ::protozero::PackedVarInt& packed_buffer) {
    AppendBytes(FieldMetadata_PacketTimestamps::kFieldId, packed_buffer.data(),
                packed_buffer.size());
  }

  using FieldMetadata_PacketLengths =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kRepeatedPacked,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketBundle>;

  static constexpr FieldMetadata_PacketLengths kPacketLengths{};
  void set_packet_lengths(const ::protozero::PackedVarInt& packed_buffer) {
    AppendBytes(FieldMetadata_PacketLengths::kFieldId, packed_buffer.data(),
                packed_buffer.size());
  }

  using FieldMetadata_TotalPackets =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketBundle>;

  static constexpr FieldMetadata_TotalPackets kTotalPackets{};
  void set_total_packets(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TotalPackets::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TotalDuration =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      NetworkPacketBundle>;

  static constexpr FieldMetadata_TotalDuration kTotalDuration{};
  void set_total_duration(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TotalDuration::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TotalLength =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      NetworkPacketBundle>;

  static constexpr FieldMetadata_TotalLength kTotalLength{};
  void set_total_length(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TotalLength::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }
};

class NetworkPacketEvent_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/9, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  NetworkPacketEvent_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit NetworkPacketEvent_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit NetworkPacketEvent_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_direction() const { return at<1>().valid(); }
  int32_t direction() const { return at<1>().as_int32(); }
  bool has_interface() const { return at<2>().valid(); }
  ::protozero::ConstChars interface() const { return at<2>().as_string(); }
  bool has_length() const { return at<3>().valid(); }
  uint32_t length() const { return at<3>().as_uint32(); }
  bool has_uid() const { return at<4>().valid(); }
  uint32_t uid() const { return at<4>().as_uint32(); }
  bool has_tag() const { return at<5>().valid(); }
  uint32_t tag() const { return at<5>().as_uint32(); }
  bool has_ip_proto() const { return at<6>().valid(); }
  uint32_t ip_proto() const { return at<6>().as_uint32(); }
  bool has_tcp_flags() const { return at<7>().valid(); }
  uint32_t tcp_flags() const { return at<7>().as_uint32(); }
  bool has_local_port() const { return at<8>().valid(); }
  uint32_t local_port() const { return at<8>().as_uint32(); }
  bool has_remote_port() const { return at<9>().valid(); }
  uint32_t remote_port() const { return at<9>().as_uint32(); }
};

class NetworkPacketEvent : public ::protozero::Message {
 public:
  using Decoder = NetworkPacketEvent_Decoder;
  enum : int32_t {
    kDirectionFieldNumber = 1,
    kInterfaceFieldNumber = 2,
    kLengthFieldNumber = 3,
    kUidFieldNumber = 4,
    kTagFieldNumber = 5,
    kIpProtoFieldNumber = 6,
    kTcpFlagsFieldNumber = 7,
    kLocalPortFieldNumber = 8,
    kRemotePortFieldNumber = 9,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.NetworkPacketEvent"; }


  using FieldMetadata_Direction =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::TrafficDirection,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_Direction kDirection{};
  void set_direction(::perfetto::protos::pbzero::TrafficDirection value) {
    static constexpr uint32_t field_id = FieldMetadata_Direction::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Interface =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_Interface kInterface{};
  void set_interface(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Interface::kFieldId, data, size);
  }
  void set_interface(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Interface::kFieldId, chars.data, chars.size);
  }
  void set_interface(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Interface::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Length =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_Length kLength{};
  void set_length(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Length::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Uid =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_Uid kUid{};
  void set_uid(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Uid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Tag =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_Tag kTag{};
  void set_tag(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Tag::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_IpProto =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_IpProto kIpProto{};
  void set_ip_proto(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_IpProto::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TcpFlags =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_TcpFlags kTcpFlags{};
  void set_tcp_flags(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TcpFlags::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_LocalPort =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_LocalPort kLocalPort{};
  void set_local_port(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_LocalPort::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_RemotePort =
    ::protozero::proto_utils::FieldMetadata<
      9,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      NetworkPacketEvent>;

  static constexpr FieldMetadata_RemotePort kRemotePort{};
  void set_remote_port(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_RemotePort::kFieldId;
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

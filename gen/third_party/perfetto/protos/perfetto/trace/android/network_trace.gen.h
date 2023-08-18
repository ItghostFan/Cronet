// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_ANDROID_NETWORK_TRACE_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_ANDROID_NETWORK_TRACE_PROTO_CPP_H_

#include <stdint.h>
#include <bitset>
#include <vector>
#include <string>
#include <type_traits>

#include "perfetto/protozero/cpp_message_obj.h"
#include "perfetto/protozero/copyable_ptr.h"
#include "perfetto/base/export.h"

namespace perfetto {
namespace protos {
namespace gen {
class NetworkPacketContext;
class NetworkPacketEvent;
class NetworkPacketBundle;
enum TrafficDirection : int;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {
enum TrafficDirection : int {
  DIR_UNSPECIFIED = 0,
  DIR_INGRESS = 1,
  DIR_EGRESS = 2,
};

class PERFETTO_EXPORT_COMPONENT NetworkPacketContext : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kIidFieldNumber = 1,
    kCtxFieldNumber = 2,
  };

  NetworkPacketContext();
  ~NetworkPacketContext() override;
  NetworkPacketContext(NetworkPacketContext&&) noexcept;
  NetworkPacketContext& operator=(NetworkPacketContext&&);
  NetworkPacketContext(const NetworkPacketContext&);
  NetworkPacketContext& operator=(const NetworkPacketContext&);
  bool operator==(const NetworkPacketContext&) const;
  bool operator!=(const NetworkPacketContext& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_iid() const { return _has_field_[1]; }
  uint64_t iid() const { return iid_; }
  void set_iid(uint64_t value) { iid_ = value; _has_field_.set(1); }

  bool has_ctx() const { return _has_field_[2]; }
  const NetworkPacketEvent& ctx() const { return *ctx_; }
  NetworkPacketEvent* mutable_ctx() { _has_field_.set(2); return ctx_.get(); }

 private:
  uint64_t iid_{};
  ::protozero::CopyablePtr<NetworkPacketEvent> ctx_;

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<3> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT NetworkPacketEvent : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
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

  NetworkPacketEvent();
  ~NetworkPacketEvent() override;
  NetworkPacketEvent(NetworkPacketEvent&&) noexcept;
  NetworkPacketEvent& operator=(NetworkPacketEvent&&);
  NetworkPacketEvent(const NetworkPacketEvent&);
  NetworkPacketEvent& operator=(const NetworkPacketEvent&);
  bool operator==(const NetworkPacketEvent&) const;
  bool operator!=(const NetworkPacketEvent& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_direction() const { return _has_field_[1]; }
  TrafficDirection direction() const { return direction_; }
  void set_direction(TrafficDirection value) { direction_ = value; _has_field_.set(1); }

  bool has_interface() const { return _has_field_[2]; }
  const std::string& interface() const { return interface_; }
  void set_interface(const std::string& value) { interface_ = value; _has_field_.set(2); }

  bool has_length() const { return _has_field_[3]; }
  uint32_t length() const { return length_; }
  void set_length(uint32_t value) { length_ = value; _has_field_.set(3); }

  bool has_uid() const { return _has_field_[4]; }
  uint32_t uid() const { return uid_; }
  void set_uid(uint32_t value) { uid_ = value; _has_field_.set(4); }

  bool has_tag() const { return _has_field_[5]; }
  uint32_t tag() const { return tag_; }
  void set_tag(uint32_t value) { tag_ = value; _has_field_.set(5); }

  bool has_ip_proto() const { return _has_field_[6]; }
  uint32_t ip_proto() const { return ip_proto_; }
  void set_ip_proto(uint32_t value) { ip_proto_ = value; _has_field_.set(6); }

  bool has_tcp_flags() const { return _has_field_[7]; }
  uint32_t tcp_flags() const { return tcp_flags_; }
  void set_tcp_flags(uint32_t value) { tcp_flags_ = value; _has_field_.set(7); }

  bool has_local_port() const { return _has_field_[8]; }
  uint32_t local_port() const { return local_port_; }
  void set_local_port(uint32_t value) { local_port_ = value; _has_field_.set(8); }

  bool has_remote_port() const { return _has_field_[9]; }
  uint32_t remote_port() const { return remote_port_; }
  void set_remote_port(uint32_t value) { remote_port_ = value; _has_field_.set(9); }

 private:
  TrafficDirection direction_{};
  std::string interface_{};
  uint32_t length_{};
  uint32_t uid_{};
  uint32_t tag_{};
  uint32_t ip_proto_{};
  uint32_t tcp_flags_{};
  uint32_t local_port_{};
  uint32_t remote_port_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<10> _has_field_{};
};


class PERFETTO_EXPORT_COMPONENT NetworkPacketBundle : public ::protozero::CppMessageObj {
 public:
  enum FieldNumbers {
    kIidFieldNumber = 1,
    kCtxFieldNumber = 2,
    kPacketTimestampsFieldNumber = 3,
    kPacketLengthsFieldNumber = 4,
    kTotalPacketsFieldNumber = 5,
    kTotalDurationFieldNumber = 6,
    kTotalLengthFieldNumber = 7,
  };

  NetworkPacketBundle();
  ~NetworkPacketBundle() override;
  NetworkPacketBundle(NetworkPacketBundle&&) noexcept;
  NetworkPacketBundle& operator=(NetworkPacketBundle&&);
  NetworkPacketBundle(const NetworkPacketBundle&);
  NetworkPacketBundle& operator=(const NetworkPacketBundle&);
  bool operator==(const NetworkPacketBundle&) const;
  bool operator!=(const NetworkPacketBundle& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_iid() const { return _has_field_[1]; }
  uint64_t iid() const { return iid_; }
  void set_iid(uint64_t value) { iid_ = value; _has_field_.set(1); }

  bool has_ctx() const { return _has_field_[2]; }
  const NetworkPacketEvent& ctx() const { return *ctx_; }
  NetworkPacketEvent* mutable_ctx() { _has_field_.set(2); return ctx_.get(); }

  const std::vector<uint64_t>& packet_timestamps() const { return packet_timestamps_; }
  std::vector<uint64_t>* mutable_packet_timestamps() { return &packet_timestamps_; }
  int packet_timestamps_size() const { return static_cast<int>(packet_timestamps_.size()); }
  void clear_packet_timestamps() { packet_timestamps_.clear(); }
  void add_packet_timestamps(uint64_t value) { packet_timestamps_.emplace_back(value); }
  uint64_t* add_packet_timestamps() { packet_timestamps_.emplace_back(); return &packet_timestamps_.back(); }

  const std::vector<uint32_t>& packet_lengths() const { return packet_lengths_; }
  std::vector<uint32_t>* mutable_packet_lengths() { return &packet_lengths_; }
  int packet_lengths_size() const { return static_cast<int>(packet_lengths_.size()); }
  void clear_packet_lengths() { packet_lengths_.clear(); }
  void add_packet_lengths(uint32_t value) { packet_lengths_.emplace_back(value); }
  uint32_t* add_packet_lengths() { packet_lengths_.emplace_back(); return &packet_lengths_.back(); }

  bool has_total_packets() const { return _has_field_[5]; }
  uint32_t total_packets() const { return total_packets_; }
  void set_total_packets(uint32_t value) { total_packets_ = value; _has_field_.set(5); }

  bool has_total_duration() const { return _has_field_[6]; }
  uint64_t total_duration() const { return total_duration_; }
  void set_total_duration(uint64_t value) { total_duration_ = value; _has_field_.set(6); }

  bool has_total_length() const { return _has_field_[7]; }
  uint64_t total_length() const { return total_length_; }
  void set_total_length(uint64_t value) { total_length_ = value; _has_field_.set(7); }

 private:
  uint64_t iid_{};
  ::protozero::CopyablePtr<NetworkPacketEvent> ctx_;
  std::vector<uint64_t> packet_timestamps_;
  std::vector<uint32_t> packet_lengths_;
  uint32_t total_packets_{};
  uint64_t total_duration_{};
  uint64_t total_length_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<8> _has_field_{};
};

}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_ANDROID_NETWORK_TRACE_PROTO_CPP_H_
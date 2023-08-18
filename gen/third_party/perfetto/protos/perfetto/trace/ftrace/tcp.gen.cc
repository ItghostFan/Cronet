#include "perfetto/protozero/gen_field_helpers.h"
#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/scattered_heap_buffer.h"
// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif
#include "protos/perfetto/trace/ftrace/tcp.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

TcpRetransmitSkbFtraceEvent::TcpRetransmitSkbFtraceEvent() = default;
TcpRetransmitSkbFtraceEvent::~TcpRetransmitSkbFtraceEvent() = default;
TcpRetransmitSkbFtraceEvent::TcpRetransmitSkbFtraceEvent(const TcpRetransmitSkbFtraceEvent&) = default;
TcpRetransmitSkbFtraceEvent& TcpRetransmitSkbFtraceEvent::operator=(const TcpRetransmitSkbFtraceEvent&) = default;
TcpRetransmitSkbFtraceEvent::TcpRetransmitSkbFtraceEvent(TcpRetransmitSkbFtraceEvent&&) noexcept = default;
TcpRetransmitSkbFtraceEvent& TcpRetransmitSkbFtraceEvent::operator=(TcpRetransmitSkbFtraceEvent&&) = default;

bool TcpRetransmitSkbFtraceEvent::operator==(const TcpRetransmitSkbFtraceEvent& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(daddr_, other.daddr_)
   && ::protozero::internal::gen_helpers::EqualsField(dport_, other.dport_)
   && ::protozero::internal::gen_helpers::EqualsField(saddr_, other.saddr_)
   && ::protozero::internal::gen_helpers::EqualsField(skaddr_, other.skaddr_)
   && ::protozero::internal::gen_helpers::EqualsField(skbaddr_, other.skbaddr_)
   && ::protozero::internal::gen_helpers::EqualsField(sport_, other.sport_)
   && ::protozero::internal::gen_helpers::EqualsField(state_, other.state_);
}

bool TcpRetransmitSkbFtraceEvent::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* daddr */:
        field.get(&daddr_);
        break;
      case 2 /* dport */:
        field.get(&dport_);
        break;
      case 3 /* saddr */:
        field.get(&saddr_);
        break;
      case 4 /* skaddr */:
        field.get(&skaddr_);
        break;
      case 5 /* skbaddr */:
        field.get(&skbaddr_);
        break;
      case 6 /* sport */:
        field.get(&sport_);
        break;
      case 7 /* state */:
        field.get(&state_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string TcpRetransmitSkbFtraceEvent::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> TcpRetransmitSkbFtraceEvent::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void TcpRetransmitSkbFtraceEvent::Serialize(::protozero::Message* msg) const {
  // Field 1: daddr
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, daddr_, msg);
  }

  // Field 2: dport
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, dport_, msg);
  }

  // Field 3: saddr
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(3, saddr_, msg);
  }

  // Field 4: skaddr
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(4, skaddr_, msg);
  }

  // Field 5: skbaddr
  if (_has_field_[5]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(5, skbaddr_, msg);
  }

  // Field 6: sport
  if (_has_field_[6]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(6, sport_, msg);
  }

  // Field 7: state
  if (_has_field_[7]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(7, state_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

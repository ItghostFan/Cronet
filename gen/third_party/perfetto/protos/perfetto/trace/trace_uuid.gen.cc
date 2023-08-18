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
#include "protos/perfetto/trace/trace_uuid.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

TraceUuid::TraceUuid() = default;
TraceUuid::~TraceUuid() = default;
TraceUuid::TraceUuid(const TraceUuid&) = default;
TraceUuid& TraceUuid::operator=(const TraceUuid&) = default;
TraceUuid::TraceUuid(TraceUuid&&) noexcept = default;
TraceUuid& TraceUuid::operator=(TraceUuid&&) = default;

bool TraceUuid::operator==(const TraceUuid& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(msb_, other.msb_)
   && ::protozero::internal::gen_helpers::EqualsField(lsb_, other.lsb_);
}

bool TraceUuid::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* msb */:
        field.get(&msb_);
        break;
      case 2 /* lsb */:
        field.get(&lsb_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string TraceUuid::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> TraceUuid::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void TraceUuid::Serialize(::protozero::Message* msg) const {
  // Field 1: msb
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, msb_, msg);
  }

  // Field 2: lsb
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, lsb_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
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
#include "protos/perfetto/trace/track_event/range_of_interest.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

TrackEventRangeOfInterest::TrackEventRangeOfInterest() = default;
TrackEventRangeOfInterest::~TrackEventRangeOfInterest() = default;
TrackEventRangeOfInterest::TrackEventRangeOfInterest(const TrackEventRangeOfInterest&) = default;
TrackEventRangeOfInterest& TrackEventRangeOfInterest::operator=(const TrackEventRangeOfInterest&) = default;
TrackEventRangeOfInterest::TrackEventRangeOfInterest(TrackEventRangeOfInterest&&) noexcept = default;
TrackEventRangeOfInterest& TrackEventRangeOfInterest::operator=(TrackEventRangeOfInterest&&) = default;

bool TrackEventRangeOfInterest::operator==(const TrackEventRangeOfInterest& other) const {
  return unknown_fields_ == other.unknown_fields_
   && start_us_ == other.start_us_;
}

bool TrackEventRangeOfInterest::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* start_us */:
        field.get(&start_us_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string TrackEventRangeOfInterest::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> TrackEventRangeOfInterest::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void TrackEventRangeOfInterest::Serialize(::protozero::Message* msg) const {
  // Field 1: start_us
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, start_us_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

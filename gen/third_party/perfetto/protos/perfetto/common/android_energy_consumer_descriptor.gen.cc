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
#include "protos/perfetto/common/android_energy_consumer_descriptor.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

AndroidEnergyConsumerDescriptor::AndroidEnergyConsumerDescriptor() = default;
AndroidEnergyConsumerDescriptor::~AndroidEnergyConsumerDescriptor() = default;
AndroidEnergyConsumerDescriptor::AndroidEnergyConsumerDescriptor(const AndroidEnergyConsumerDescriptor&) = default;
AndroidEnergyConsumerDescriptor& AndroidEnergyConsumerDescriptor::operator=(const AndroidEnergyConsumerDescriptor&) = default;
AndroidEnergyConsumerDescriptor::AndroidEnergyConsumerDescriptor(AndroidEnergyConsumerDescriptor&&) noexcept = default;
AndroidEnergyConsumerDescriptor& AndroidEnergyConsumerDescriptor::operator=(AndroidEnergyConsumerDescriptor&&) = default;

bool AndroidEnergyConsumerDescriptor::operator==(const AndroidEnergyConsumerDescriptor& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(energy_consumers_, other.energy_consumers_);
}

int AndroidEnergyConsumerDescriptor::energy_consumers_size() const { return static_cast<int>(energy_consumers_.size()); }
void AndroidEnergyConsumerDescriptor::clear_energy_consumers() { energy_consumers_.clear(); }
AndroidEnergyConsumer* AndroidEnergyConsumerDescriptor::add_energy_consumers() { energy_consumers_.emplace_back(); return &energy_consumers_.back(); }
bool AndroidEnergyConsumerDescriptor::ParseFromArray(const void* raw, size_t size) {
  energy_consumers_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* energy_consumers */:
        energy_consumers_.emplace_back();
        energy_consumers_.back().ParseFromArray(field.data(), field.size());
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string AndroidEnergyConsumerDescriptor::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> AndroidEnergyConsumerDescriptor::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void AndroidEnergyConsumerDescriptor::Serialize(::protozero::Message* msg) const {
  // Field 1: energy_consumers
  for (auto& it : energy_consumers_) {
    it.Serialize(msg->BeginNestedMessage<::protozero::Message>(1));
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


AndroidEnergyConsumer::AndroidEnergyConsumer() = default;
AndroidEnergyConsumer::~AndroidEnergyConsumer() = default;
AndroidEnergyConsumer::AndroidEnergyConsumer(const AndroidEnergyConsumer&) = default;
AndroidEnergyConsumer& AndroidEnergyConsumer::operator=(const AndroidEnergyConsumer&) = default;
AndroidEnergyConsumer::AndroidEnergyConsumer(AndroidEnergyConsumer&&) noexcept = default;
AndroidEnergyConsumer& AndroidEnergyConsumer::operator=(AndroidEnergyConsumer&&) = default;

bool AndroidEnergyConsumer::operator==(const AndroidEnergyConsumer& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(energy_consumer_id_, other.energy_consumer_id_)
   && ::protozero::internal::gen_helpers::EqualsField(ordinal_, other.ordinal_)
   && ::protozero::internal::gen_helpers::EqualsField(type_, other.type_)
   && ::protozero::internal::gen_helpers::EqualsField(name_, other.name_);
}

bool AndroidEnergyConsumer::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* energy_consumer_id */:
        field.get(&energy_consumer_id_);
        break;
      case 2 /* ordinal */:
        field.get(&ordinal_);
        break;
      case 3 /* type */:
        ::protozero::internal::gen_helpers::DeserializeString(field, &type_);
        break;
      case 4 /* name */:
        ::protozero::internal::gen_helpers::DeserializeString(field, &name_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string AndroidEnergyConsumer::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> AndroidEnergyConsumer::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void AndroidEnergyConsumer::Serialize(::protozero::Message* msg) const {
  // Field 1: energy_consumer_id
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, energy_consumer_id_, msg);
  }

  // Field 2: ordinal
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, ordinal_, msg);
  }

  // Field 3: type
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeString(3, type_, msg);
  }

  // Field 4: name
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeString(4, name_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

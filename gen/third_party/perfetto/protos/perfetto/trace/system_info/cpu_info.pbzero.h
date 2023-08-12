// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_SYSTEM_INFO_CPU_INFO_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_SYSTEM_INFO_CPU_INFO_PROTO_H_

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

class CpuInfo_Cpu;

class CpuInfo_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/1, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  CpuInfo_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit CpuInfo_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit CpuInfo_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_cpus() const { return at<1>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> cpus() const { return GetRepeated<::protozero::ConstBytes>(1); }
};

class CpuInfo : public ::protozero::Message {
 public:
  using Decoder = CpuInfo_Decoder;
  enum : int32_t {
    kCpusFieldNumber = 1,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.CpuInfo"; }

  using Cpu = ::perfetto::protos::pbzero::CpuInfo_Cpu;

  using FieldMetadata_Cpus =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      CpuInfo_Cpu,
      CpuInfo>;

  static constexpr FieldMetadata_Cpus kCpus{};
  template <typename T = CpuInfo_Cpu> T* add_cpus() {
    return BeginNestedMessage<T>(1);
  }

};

class CpuInfo_Cpu_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  CpuInfo_Cpu_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit CpuInfo_Cpu_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit CpuInfo_Cpu_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_processor() const { return at<1>().valid(); }
  ::protozero::ConstChars processor() const { return at<1>().as_string(); }
  bool has_frequencies() const { return at<2>().valid(); }
  ::protozero::RepeatedFieldIterator<uint32_t> frequencies() const { return GetRepeated<uint32_t>(2); }
};

class CpuInfo_Cpu : public ::protozero::Message {
 public:
  using Decoder = CpuInfo_Cpu_Decoder;
  enum : int32_t {
    kProcessorFieldNumber = 1,
    kFrequenciesFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.CpuInfo.Cpu"; }


  using FieldMetadata_Processor =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      CpuInfo_Cpu>;

  static constexpr FieldMetadata_Processor kProcessor{};
  void set_processor(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Processor::kFieldId, data, size);
  }
  void set_processor(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Processor::kFieldId, chars.data, chars.size);
  }
  void set_processor(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Processor::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Frequencies =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      CpuInfo_Cpu>;

  static constexpr FieldMetadata_Frequencies kFrequencies{};
  void add_frequencies(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Frequencies::kFieldId;
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

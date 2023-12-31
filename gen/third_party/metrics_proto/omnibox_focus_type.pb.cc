// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: omnibox_focus_type.proto

#include "omnibox_focus_type.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace metrics {
}  // namespace metrics
namespace metrics {
bool OmniboxFocusType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> OmniboxFocusType_strings[3] = {};

static const char OmniboxFocusType_names[] =
  "INTERACTION_CLOBBER"
  "INTERACTION_DEFAULT"
  "INTERACTION_FOCUS";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry OmniboxFocusType_entries[] = {
  { {OmniboxFocusType_names + 0, 19}, 2 },
  { {OmniboxFocusType_names + 19, 19}, 0 },
  { {OmniboxFocusType_names + 38, 17}, 1 },
};

static const int OmniboxFocusType_entries_by_number[] = {
  1, // 0 -> INTERACTION_DEFAULT
  2, // 1 -> INTERACTION_FOCUS
  0, // 2 -> INTERACTION_CLOBBER
};

const std::string& OmniboxFocusType_Name(
    OmniboxFocusType value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          OmniboxFocusType_entries,
          OmniboxFocusType_entries_by_number,
          3, OmniboxFocusType_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      OmniboxFocusType_entries,
      OmniboxFocusType_entries_by_number,
      3, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     OmniboxFocusType_strings[idx].get();
}
bool OmniboxFocusType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, OmniboxFocusType* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      OmniboxFocusType_entries, 3, name, &int_value);
  if (success) {
    *value = static_cast<OmniboxFocusType>(int_value);
  }
  return success;
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace metrics
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

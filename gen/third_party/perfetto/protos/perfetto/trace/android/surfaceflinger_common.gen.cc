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
#include "protos/perfetto/trace/android/surfaceflinger_common.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

ColorTransformProto::ColorTransformProto() = default;
ColorTransformProto::~ColorTransformProto() = default;
ColorTransformProto::ColorTransformProto(const ColorTransformProto&) = default;
ColorTransformProto& ColorTransformProto::operator=(const ColorTransformProto&) = default;
ColorTransformProto::ColorTransformProto(ColorTransformProto&&) noexcept = default;
ColorTransformProto& ColorTransformProto::operator=(ColorTransformProto&&) = default;

bool ColorTransformProto::operator==(const ColorTransformProto& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(val_, other.val_);
}

bool ColorTransformProto::ParseFromArray(const void* raw, size_t size) {
  val_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* val */:
        if (!::protozero::internal::gen_helpers::DeserializePackedRepeated<::protozero::proto_utils::ProtoWireType::kFixed32, float>(field, &val_)) {
          packed_error = true;}
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string ColorTransformProto::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> ColorTransformProto::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void ColorTransformProto::Serialize(::protozero::Message* msg) const {
  // Field 1: val
  {
    ::protozero::PackedFixedSizeInt<float> pack;
    for (auto& it : val_)
      pack.Append(it);
    msg->AppendBytes(1, pack.data(), pack.size());
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


BlurRegion::BlurRegion() = default;
BlurRegion::~BlurRegion() = default;
BlurRegion::BlurRegion(const BlurRegion&) = default;
BlurRegion& BlurRegion::operator=(const BlurRegion&) = default;
BlurRegion::BlurRegion(BlurRegion&&) noexcept = default;
BlurRegion& BlurRegion::operator=(BlurRegion&&) = default;

bool BlurRegion::operator==(const BlurRegion& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(blur_radius_, other.blur_radius_)
   && ::protozero::internal::gen_helpers::EqualsField(corner_radius_tl_, other.corner_radius_tl_)
   && ::protozero::internal::gen_helpers::EqualsField(corner_radius_tr_, other.corner_radius_tr_)
   && ::protozero::internal::gen_helpers::EqualsField(corner_radius_bl_, other.corner_radius_bl_)
   && ::protozero::internal::gen_helpers::EqualsField(corner_radius_br_, other.corner_radius_br_)
   && ::protozero::internal::gen_helpers::EqualsField(alpha_, other.alpha_)
   && ::protozero::internal::gen_helpers::EqualsField(left_, other.left_)
   && ::protozero::internal::gen_helpers::EqualsField(top_, other.top_)
   && ::protozero::internal::gen_helpers::EqualsField(right_, other.right_)
   && ::protozero::internal::gen_helpers::EqualsField(bottom_, other.bottom_);
}

bool BlurRegion::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* blur_radius */:
        field.get(&blur_radius_);
        break;
      case 2 /* corner_radius_tl */:
        field.get(&corner_radius_tl_);
        break;
      case 3 /* corner_radius_tr */:
        field.get(&corner_radius_tr_);
        break;
      case 4 /* corner_radius_bl */:
        field.get(&corner_radius_bl_);
        break;
      case 5 /* corner_radius_br */:
        field.get(&corner_radius_br_);
        break;
      case 6 /* alpha */:
        field.get(&alpha_);
        break;
      case 7 /* left */:
        field.get(&left_);
        break;
      case 8 /* top */:
        field.get(&top_);
        break;
      case 9 /* right */:
        field.get(&right_);
        break;
      case 10 /* bottom */:
        field.get(&bottom_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string BlurRegion::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> BlurRegion::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void BlurRegion::Serialize(::protozero::Message* msg) const {
  // Field 1: blur_radius
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, blur_radius_, msg);
  }

  // Field 2: corner_radius_tl
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, corner_radius_tl_, msg);
  }

  // Field 3: corner_radius_tr
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(3, corner_radius_tr_, msg);
  }

  // Field 4: corner_radius_bl
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(4, corner_radius_bl_, msg);
  }

  // Field 5: corner_radius_br
  if (_has_field_[5]) {
    ::protozero::internal::gen_helpers::SerializeFixed(5, corner_radius_br_, msg);
  }

  // Field 6: alpha
  if (_has_field_[6]) {
    ::protozero::internal::gen_helpers::SerializeFixed(6, alpha_, msg);
  }

  // Field 7: left
  if (_has_field_[7]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(7, left_, msg);
  }

  // Field 8: top
  if (_has_field_[8]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(8, top_, msg);
  }

  // Field 9: right
  if (_has_field_[9]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(9, right_, msg);
  }

  // Field 10: bottom
  if (_has_field_[10]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(10, bottom_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


InputWindowInfoProto::InputWindowInfoProto() = default;
InputWindowInfoProto::~InputWindowInfoProto() = default;
InputWindowInfoProto::InputWindowInfoProto(const InputWindowInfoProto&) = default;
InputWindowInfoProto& InputWindowInfoProto::operator=(const InputWindowInfoProto&) = default;
InputWindowInfoProto::InputWindowInfoProto(InputWindowInfoProto&&) noexcept = default;
InputWindowInfoProto& InputWindowInfoProto::operator=(InputWindowInfoProto&&) = default;

bool InputWindowInfoProto::operator==(const InputWindowInfoProto& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(layout_params_flags_, other.layout_params_flags_)
   && ::protozero::internal::gen_helpers::EqualsField(layout_params_type_, other.layout_params_type_)
   && ::protozero::internal::gen_helpers::EqualsField(frame_, other.frame_)
   && ::protozero::internal::gen_helpers::EqualsField(touchable_region_, other.touchable_region_)
   && ::protozero::internal::gen_helpers::EqualsField(surface_inset_, other.surface_inset_)
   && ::protozero::internal::gen_helpers::EqualsField(visible_, other.visible_)
   && ::protozero::internal::gen_helpers::EqualsField(can_receive_keys_, other.can_receive_keys_)
   && ::protozero::internal::gen_helpers::EqualsField(focusable_, other.focusable_)
   && ::protozero::internal::gen_helpers::EqualsField(has_wallpaper_, other.has_wallpaper_)
   && ::protozero::internal::gen_helpers::EqualsField(global_scale_factor_, other.global_scale_factor_)
   && ::protozero::internal::gen_helpers::EqualsField(window_x_scale_, other.window_x_scale_)
   && ::protozero::internal::gen_helpers::EqualsField(window_y_scale_, other.window_y_scale_)
   && ::protozero::internal::gen_helpers::EqualsField(crop_layer_id_, other.crop_layer_id_)
   && ::protozero::internal::gen_helpers::EqualsField(replace_touchable_region_with_crop_, other.replace_touchable_region_with_crop_)
   && ::protozero::internal::gen_helpers::EqualsField(touchable_region_crop_, other.touchable_region_crop_)
   && ::protozero::internal::gen_helpers::EqualsField(transform_, other.transform_)
   && ::protozero::internal::gen_helpers::EqualsField(input_config_, other.input_config_);
}

bool InputWindowInfoProto::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* layout_params_flags */:
        field.get(&layout_params_flags_);
        break;
      case 2 /* layout_params_type */:
        field.get(&layout_params_type_);
        break;
      case 3 /* frame */:
        (*frame_).ParseFromArray(field.data(), field.size());
        break;
      case 4 /* touchable_region */:
        (*touchable_region_).ParseFromArray(field.data(), field.size());
        break;
      case 5 /* surface_inset */:
        field.get(&surface_inset_);
        break;
      case 6 /* visible */:
        field.get(&visible_);
        break;
      case 7 /* can_receive_keys */:
        field.get(&can_receive_keys_);
        break;
      case 8 /* focusable */:
        field.get(&focusable_);
        break;
      case 9 /* has_wallpaper */:
        field.get(&has_wallpaper_);
        break;
      case 10 /* global_scale_factor */:
        field.get(&global_scale_factor_);
        break;
      case 11 /* window_x_scale */:
        field.get(&window_x_scale_);
        break;
      case 12 /* window_y_scale */:
        field.get(&window_y_scale_);
        break;
      case 13 /* crop_layer_id */:
        field.get(&crop_layer_id_);
        break;
      case 14 /* replace_touchable_region_with_crop */:
        field.get(&replace_touchable_region_with_crop_);
        break;
      case 15 /* touchable_region_crop */:
        (*touchable_region_crop_).ParseFromArray(field.data(), field.size());
        break;
      case 16 /* transform */:
        (*transform_).ParseFromArray(field.data(), field.size());
        break;
      case 17 /* input_config */:
        field.get(&input_config_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string InputWindowInfoProto::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> InputWindowInfoProto::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void InputWindowInfoProto::Serialize(::protozero::Message* msg) const {
  // Field 1: layout_params_flags
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, layout_params_flags_, msg);
  }

  // Field 2: layout_params_type
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, layout_params_type_, msg);
  }

  // Field 3: frame
  if (_has_field_[3]) {
    (*frame_).Serialize(msg->BeginNestedMessage<::protozero::Message>(3));
  }

  // Field 4: touchable_region
  if (_has_field_[4]) {
    (*touchable_region_).Serialize(msg->BeginNestedMessage<::protozero::Message>(4));
  }

  // Field 5: surface_inset
  if (_has_field_[5]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(5, surface_inset_, msg);
  }

  // Field 6: visible
  if (_has_field_[6]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(6, visible_, msg);
  }

  // Field 7: can_receive_keys
  if (_has_field_[7]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(7, can_receive_keys_, msg);
  }

  // Field 8: focusable
  if (_has_field_[8]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(8, focusable_, msg);
  }

  // Field 9: has_wallpaper
  if (_has_field_[9]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(9, has_wallpaper_, msg);
  }

  // Field 10: global_scale_factor
  if (_has_field_[10]) {
    ::protozero::internal::gen_helpers::SerializeFixed(10, global_scale_factor_, msg);
  }

  // Field 11: window_x_scale
  if (_has_field_[11]) {
    ::protozero::internal::gen_helpers::SerializeFixed(11, window_x_scale_, msg);
  }

  // Field 12: window_y_scale
  if (_has_field_[12]) {
    ::protozero::internal::gen_helpers::SerializeFixed(12, window_y_scale_, msg);
  }

  // Field 13: crop_layer_id
  if (_has_field_[13]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(13, crop_layer_id_, msg);
  }

  // Field 14: replace_touchable_region_with_crop
  if (_has_field_[14]) {
    ::protozero::internal::gen_helpers::SerializeTinyVarInt(14, replace_touchable_region_with_crop_, msg);
  }

  // Field 15: touchable_region_crop
  if (_has_field_[15]) {
    (*touchable_region_crop_).Serialize(msg->BeginNestedMessage<::protozero::Message>(15));
  }

  // Field 16: transform
  if (_has_field_[16]) {
    (*transform_).Serialize(msg->BeginNestedMessage<::protozero::Message>(16));
  }

  // Field 17: input_config
  if (_has_field_[17]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(17, input_config_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


TransformProto::TransformProto() = default;
TransformProto::~TransformProto() = default;
TransformProto::TransformProto(const TransformProto&) = default;
TransformProto& TransformProto::operator=(const TransformProto&) = default;
TransformProto::TransformProto(TransformProto&&) noexcept = default;
TransformProto& TransformProto::operator=(TransformProto&&) = default;

bool TransformProto::operator==(const TransformProto& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(dsdx_, other.dsdx_)
   && ::protozero::internal::gen_helpers::EqualsField(dtdx_, other.dtdx_)
   && ::protozero::internal::gen_helpers::EqualsField(dsdy_, other.dsdy_)
   && ::protozero::internal::gen_helpers::EqualsField(dtdy_, other.dtdy_)
   && ::protozero::internal::gen_helpers::EqualsField(type_, other.type_);
}

bool TransformProto::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* dsdx */:
        field.get(&dsdx_);
        break;
      case 2 /* dtdx */:
        field.get(&dtdx_);
        break;
      case 3 /* dsdy */:
        field.get(&dsdy_);
        break;
      case 4 /* dtdy */:
        field.get(&dtdy_);
        break;
      case 5 /* type */:
        field.get(&type_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string TransformProto::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> TransformProto::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void TransformProto::Serialize(::protozero::Message* msg) const {
  // Field 1: dsdx
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeFixed(1, dsdx_, msg);
  }

  // Field 2: dtdx
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeFixed(2, dtdx_, msg);
  }

  // Field 3: dsdy
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeFixed(3, dsdy_, msg);
  }

  // Field 4: dtdy
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeFixed(4, dtdy_, msg);
  }

  // Field 5: type
  if (_has_field_[5]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(5, type_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


RectProto::RectProto() = default;
RectProto::~RectProto() = default;
RectProto::RectProto(const RectProto&) = default;
RectProto& RectProto::operator=(const RectProto&) = default;
RectProto::RectProto(RectProto&&) noexcept = default;
RectProto& RectProto::operator=(RectProto&&) = default;

bool RectProto::operator==(const RectProto& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(left_, other.left_)
   && ::protozero::internal::gen_helpers::EqualsField(top_, other.top_)
   && ::protozero::internal::gen_helpers::EqualsField(right_, other.right_)
   && ::protozero::internal::gen_helpers::EqualsField(bottom_, other.bottom_);
}

bool RectProto::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* left */:
        field.get(&left_);
        break;
      case 2 /* top */:
        field.get(&top_);
        break;
      case 3 /* right */:
        field.get(&right_);
        break;
      case 4 /* bottom */:
        field.get(&bottom_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string RectProto::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> RectProto::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void RectProto::Serialize(::protozero::Message* msg) const {
  // Field 1: left
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, left_, msg);
  }

  // Field 2: top
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, top_, msg);
  }

  // Field 3: right
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(3, right_, msg);
  }

  // Field 4: bottom
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(4, bottom_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


RegionProto::RegionProto() = default;
RegionProto::~RegionProto() = default;
RegionProto::RegionProto(const RegionProto&) = default;
RegionProto& RegionProto::operator=(const RegionProto&) = default;
RegionProto::RegionProto(RegionProto&&) noexcept = default;
RegionProto& RegionProto::operator=(RegionProto&&) = default;

bool RegionProto::operator==(const RegionProto& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(rect_, other.rect_);
}

int RegionProto::rect_size() const { return static_cast<int>(rect_.size()); }
void RegionProto::clear_rect() { rect_.clear(); }
RectProto* RegionProto::add_rect() { rect_.emplace_back(); return &rect_.back(); }
bool RegionProto::ParseFromArray(const void* raw, size_t size) {
  rect_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 2 /* rect */:
        rect_.emplace_back();
        rect_.back().ParseFromArray(field.data(), field.size());
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string RegionProto::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> RegionProto::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void RegionProto::Serialize(::protozero::Message* msg) const {
  // Field 2: rect
  for (auto& it : rect_) {
    it.Serialize(msg->BeginNestedMessage<::protozero::Message>(2));
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


ColorProto::ColorProto() = default;
ColorProto::~ColorProto() = default;
ColorProto::ColorProto(const ColorProto&) = default;
ColorProto& ColorProto::operator=(const ColorProto&) = default;
ColorProto::ColorProto(ColorProto&&) noexcept = default;
ColorProto& ColorProto::operator=(ColorProto&&) = default;

bool ColorProto::operator==(const ColorProto& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(r_, other.r_)
   && ::protozero::internal::gen_helpers::EqualsField(g_, other.g_)
   && ::protozero::internal::gen_helpers::EqualsField(b_, other.b_)
   && ::protozero::internal::gen_helpers::EqualsField(a_, other.a_);
}

bool ColorProto::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* r */:
        field.get(&r_);
        break;
      case 2 /* g */:
        field.get(&g_);
        break;
      case 3 /* b */:
        field.get(&b_);
        break;
      case 4 /* a */:
        field.get(&a_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string ColorProto::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> ColorProto::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void ColorProto::Serialize(::protozero::Message* msg) const {
  // Field 1: r
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeFixed(1, r_, msg);
  }

  // Field 2: g
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeFixed(2, g_, msg);
  }

  // Field 3: b
  if (_has_field_[3]) {
    ::protozero::internal::gen_helpers::SerializeFixed(3, b_, msg);
  }

  // Field 4: a
  if (_has_field_[4]) {
    ::protozero::internal::gen_helpers::SerializeFixed(4, a_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}


SizeProto::SizeProto() = default;
SizeProto::~SizeProto() = default;
SizeProto::SizeProto(const SizeProto&) = default;
SizeProto& SizeProto::operator=(const SizeProto&) = default;
SizeProto::SizeProto(SizeProto&&) noexcept = default;
SizeProto& SizeProto::operator=(SizeProto&&) = default;

bool SizeProto::operator==(const SizeProto& other) const {
  return ::protozero::internal::gen_helpers::EqualsField(unknown_fields_, other.unknown_fields_)
   && ::protozero::internal::gen_helpers::EqualsField(w_, other.w_)
   && ::protozero::internal::gen_helpers::EqualsField(h_, other.h_);
}

bool SizeProto::ParseFromArray(const void* raw, size_t size) {
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* w */:
        field.get(&w_);
        break;
      case 2 /* h */:
        field.get(&h_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string SizeProto::SerializeAsString() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> SizeProto::SerializeAsArray() const {
  ::protozero::internal::gen_helpers::MessageSerializer msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void SizeProto::Serialize(::protozero::Message* msg) const {
  // Field 1: w
  if (_has_field_[1]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(1, w_, msg);
  }

  // Field 2: h
  if (_has_field_[2]) {
    ::protozero::internal::gen_helpers::SerializeVarInt(2, h_, msg);
  }

  protozero::internal::gen_helpers::SerializeUnknownFields(unknown_fields_, msg);
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DQMServices/Core/src/ROOTFilePB.proto

#include "DQMServices/Core/src/ROOTFilePB.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace dqmstorepb {
class ROOTFilePB_HistoDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ROOTFilePB_Histo>
      _instance;
} _ROOTFilePB_Histo_default_instance_;
class ROOTFilePBDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ROOTFilePB>
      _instance;
} _ROOTFilePB_default_instance_;
}  // namespace dqmstorepb
namespace protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto {
void InitDefaultsROOTFilePB_HistoImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::dqmstorepb::_ROOTFilePB_Histo_default_instance_;
    new (ptr) ::dqmstorepb::ROOTFilePB_Histo();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::dqmstorepb::ROOTFilePB_Histo::InitAsDefaultInstance();
}

void InitDefaultsROOTFilePB_Histo() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsROOTFilePB_HistoImpl);
}

void InitDefaultsROOTFilePBImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::InitDefaultsROOTFilePB_Histo();
  {
    void* ptr = &::dqmstorepb::_ROOTFilePB_default_instance_;
    new (ptr) ::dqmstorepb::ROOTFilePB();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::dqmstorepb::ROOTFilePB::InitAsDefaultInstance();
}

void InitDefaultsROOTFilePB() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsROOTFilePBImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB_Histo, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB_Histo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB_Histo, full_pathname_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB_Histo, size_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB_Histo, streamed_histo_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB_Histo, flags_),
  0,
  2,
  1,
  3,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::dqmstorepb::ROOTFilePB, histo_),
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::dqmstorepb::ROOTFilePB_Histo)},
  { 13, 19, sizeof(::dqmstorepb::ROOTFilePB)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::dqmstorepb::_ROOTFilePB_Histo_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::dqmstorepb::_ROOTFilePB_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = nullptr;
  AssignDescriptors(
      "DQMServices/Core/src/ROOTFilePB.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, nullptr, nullptr);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n%DQMServices/Core/src/ROOTFilePB.proto\022"
      "\ndqmstorepb\"\216\001\n\nROOTFilePB\022+\n\005histo\030\001 \003("
      "\0132\034.dqmstorepb.ROOTFilePB.Histo\032S\n\005Histo"
      "\022\025\n\rfull_pathname\030\001 \002(\t\022\014\n\004size\030\002 \002(\r\022\026\n"
      "\016streamed_histo\030\003 \002(\014\022\r\n\005flags\030\004 \002(\r"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 196);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "DQMServices/Core/src/ROOTFilePB.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto
namespace dqmstorepb {

// ===================================================================

void ROOTFilePB_Histo::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ROOTFilePB_Histo::kFullPathnameFieldNumber;
const int ROOTFilePB_Histo::kSizeFieldNumber;
const int ROOTFilePB_Histo::kStreamedHistoFieldNumber;
const int ROOTFilePB_Histo::kFlagsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ROOTFilePB_Histo::ROOTFilePB_Histo()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::InitDefaultsROOTFilePB_Histo();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:dqmstorepb.ROOTFilePB.Histo)
}
ROOTFilePB_Histo::ROOTFilePB_Histo(const ROOTFilePB_Histo& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  full_pathname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_full_pathname()) {
    full_pathname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.full_pathname_);
  }
  streamed_histo_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_streamed_histo()) {
    streamed_histo_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.streamed_histo_);
  }
  ::memcpy(&size_, &from.size_,
    static_cast<size_t>(reinterpret_cast<char*>(&flags_) -
    reinterpret_cast<char*>(&size_)) + sizeof(flags_));
  // @@protoc_insertion_point(copy_constructor:dqmstorepb.ROOTFilePB.Histo)
}

void ROOTFilePB_Histo::SharedCtor() {
  _cached_size_ = 0;
  full_pathname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  streamed_histo_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&size_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&flags_) -
      reinterpret_cast<char*>(&size_)) + sizeof(flags_));
}

ROOTFilePB_Histo::~ROOTFilePB_Histo() {
  // @@protoc_insertion_point(destructor:dqmstorepb.ROOTFilePB.Histo)
  SharedDtor();
}

void ROOTFilePB_Histo::SharedDtor() {
  full_pathname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  streamed_histo_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ROOTFilePB_Histo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ROOTFilePB_Histo::descriptor() {
  ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ROOTFilePB_Histo& ROOTFilePB_Histo::default_instance() {
  ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::InitDefaultsROOTFilePB_Histo();
  return *internal_default_instance();
}

ROOTFilePB_Histo* ROOTFilePB_Histo::New(::google::protobuf::Arena* arena) const {
  ROOTFilePB_Histo* n = new ROOTFilePB_Histo;
  if (arena != nullptr) {
    arena->Own(n);
  }
  return n;
}

void ROOTFilePB_Histo::Clear() {
// @@protoc_insertion_point(message_clear_start:dqmstorepb.ROOTFilePB.Histo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!full_pathname_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*full_pathname_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!streamed_histo_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*streamed_histo_.UnsafeRawStringPointer())->clear();
    }
  }
  if (cached_has_bits & 12u) {
    ::memset(&size_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&flags_) -
        reinterpret_cast<char*>(&size_)) + sizeof(flags_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ROOTFilePB_Histo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:dqmstorepb.ROOTFilePB.Histo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string full_pathname = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_full_pathname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->full_pathname().data(), static_cast<int>(this->full_pathname().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "dqmstorepb.ROOTFilePB.Histo.full_pathname");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint32 size = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_size();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &size_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes streamed_histo = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_streamed_histo()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint32 flags = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_flags();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &flags_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:dqmstorepb.ROOTFilePB.Histo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:dqmstorepb.ROOTFilePB.Histo)
  return false;
#undef DO_
}

void ROOTFilePB_Histo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:dqmstorepb.ROOTFilePB.Histo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string full_pathname = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_pathname().data(), static_cast<int>(this->full_pathname().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "dqmstorepb.ROOTFilePB.Histo.full_pathname");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->full_pathname(), output);
  }

  // required uint32 size = 2;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->size(), output);
  }

  // required bytes streamed_histo = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->streamed_histo(), output);
  }

  // required uint32 flags = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->flags(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:dqmstorepb.ROOTFilePB.Histo)
}

::google::protobuf::uint8* ROOTFilePB_Histo::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:dqmstorepb.ROOTFilePB.Histo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string full_pathname = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->full_pathname().data(), static_cast<int>(this->full_pathname().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "dqmstorepb.ROOTFilePB.Histo.full_pathname");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->full_pathname(), target);
  }

  // required uint32 size = 2;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->size(), target);
  }

  // required bytes streamed_histo = 3;
  if (cached_has_bits & 0x00000002u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->streamed_histo(), target);
  }

  // required uint32 flags = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->flags(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:dqmstorepb.ROOTFilePB.Histo)
  return target;
}

size_t ROOTFilePB_Histo::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:dqmstorepb.ROOTFilePB.Histo)
  size_t total_size = 0;

  if (has_full_pathname()) {
    // required string full_pathname = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->full_pathname());
  }

  if (has_streamed_histo()) {
    // required bytes streamed_histo = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->streamed_histo());
  }

  if (has_size()) {
    // required uint32 size = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->size());
  }

  if (has_flags()) {
    // required uint32 flags = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->flags());
  }

  return total_size;
}
size_t ROOTFilePB_Histo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:dqmstorepb.ROOTFilePB.Histo)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x0000000f) ^ 0x0000000f) == 0) {  // All required fields are present.
    // required string full_pathname = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->full_pathname());

    // required bytes streamed_histo = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->streamed_histo());

    // required uint32 size = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->size());

    // required uint32 flags = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->flags());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ROOTFilePB_Histo::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:dqmstorepb.ROOTFilePB.Histo)
  GOOGLE_DCHECK_NE(&from, this);
  const ROOTFilePB_Histo* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ROOTFilePB_Histo>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:dqmstorepb.ROOTFilePB.Histo)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:dqmstorepb.ROOTFilePB.Histo)
    MergeFrom(*source);
  }
}

void ROOTFilePB_Histo::MergeFrom(const ROOTFilePB_Histo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:dqmstorepb.ROOTFilePB.Histo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_full_pathname();
      full_pathname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.full_pathname_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_streamed_histo();
      streamed_histo_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.streamed_histo_);
    }
    if (cached_has_bits & 0x00000004u) {
      size_ = from.size_;
    }
    if (cached_has_bits & 0x00000008u) {
      flags_ = from.flags_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ROOTFilePB_Histo::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:dqmstorepb.ROOTFilePB.Histo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ROOTFilePB_Histo::CopyFrom(const ROOTFilePB_Histo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:dqmstorepb.ROOTFilePB.Histo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ROOTFilePB_Histo::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;
  return true;
}

void ROOTFilePB_Histo::Swap(ROOTFilePB_Histo* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ROOTFilePB_Histo::InternalSwap(ROOTFilePB_Histo* other) {
  using std::swap;
  full_pathname_.Swap(&other->full_pathname_);
  streamed_histo_.Swap(&other->streamed_histo_);
  swap(size_, other->size_);
  swap(flags_, other->flags_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ROOTFilePB_Histo::GetMetadata() const {
  protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void ROOTFilePB::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ROOTFilePB::kHistoFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ROOTFilePB::ROOTFilePB()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::InitDefaultsROOTFilePB();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:dqmstorepb.ROOTFilePB)
}
ROOTFilePB::ROOTFilePB(const ROOTFilePB& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      histo_(from.histo_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:dqmstorepb.ROOTFilePB)
}

void ROOTFilePB::SharedCtor() {
  _cached_size_ = 0;
}

ROOTFilePB::~ROOTFilePB() {
  // @@protoc_insertion_point(destructor:dqmstorepb.ROOTFilePB)
  SharedDtor();
}

void ROOTFilePB::SharedDtor() {
}

void ROOTFilePB::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ROOTFilePB::descriptor() {
  ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ROOTFilePB& ROOTFilePB::default_instance() {
  ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::InitDefaultsROOTFilePB();
  return *internal_default_instance();
}

ROOTFilePB* ROOTFilePB::New(::google::protobuf::Arena* arena) const {
  ROOTFilePB* n = new ROOTFilePB;
  if (arena != nullptr) {
    arena->Own(n);
  }
  return n;
}

void ROOTFilePB::Clear() {
// @@protoc_insertion_point(message_clear_start:dqmstorepb.ROOTFilePB)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  histo_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ROOTFilePB::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:dqmstorepb.ROOTFilePB)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .dqmstorepb.ROOTFilePB.Histo histo = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_histo()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:dqmstorepb.ROOTFilePB)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:dqmstorepb.ROOTFilePB)
  return false;
#undef DO_
}

void ROOTFilePB::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:dqmstorepb.ROOTFilePB)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .dqmstorepb.ROOTFilePB.Histo histo = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->histo_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->histo(static_cast<int>(i)), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:dqmstorepb.ROOTFilePB)
}

::google::protobuf::uint8* ROOTFilePB::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:dqmstorepb.ROOTFilePB)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .dqmstorepb.ROOTFilePB.Histo histo = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->histo_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->histo(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:dqmstorepb.ROOTFilePB)
  return target;
}

size_t ROOTFilePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:dqmstorepb.ROOTFilePB)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated .dqmstorepb.ROOTFilePB.Histo histo = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->histo_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->histo(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ROOTFilePB::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:dqmstorepb.ROOTFilePB)
  GOOGLE_DCHECK_NE(&from, this);
  const ROOTFilePB* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ROOTFilePB>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:dqmstorepb.ROOTFilePB)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:dqmstorepb.ROOTFilePB)
    MergeFrom(*source);
  }
}

void ROOTFilePB::MergeFrom(const ROOTFilePB& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:dqmstorepb.ROOTFilePB)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  histo_.MergeFrom(from.histo_);
}

void ROOTFilePB::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:dqmstorepb.ROOTFilePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ROOTFilePB::CopyFrom(const ROOTFilePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:dqmstorepb.ROOTFilePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ROOTFilePB::IsInitialized() const {
  if (!::google::protobuf::internal::AllAreInitialized(this->histo())) return false;
  return true;
}

void ROOTFilePB::Swap(ROOTFilePB* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ROOTFilePB::InternalSwap(ROOTFilePB* other) {
  using std::swap;
  histo_.InternalSwap(&other->histo_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ROOTFilePB::GetMetadata() const {
  protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DQMServices_2fCore_2fsrc_2fROOTFilePB_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace dqmstorepb

// @@protoc_insertion_point(global_scope)

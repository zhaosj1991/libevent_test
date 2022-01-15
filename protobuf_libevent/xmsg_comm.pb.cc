// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: xmsg_comm.proto

#include "xmsg_comm.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace xmsg {
constexpr XMsgHead::XMsgHead(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : token_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , service_name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , msg_size_(0)
  , msg_type_(0)
{}
struct XMsgHeadDefaultTypeInternal {
  constexpr XMsgHeadDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~XMsgHeadDefaultTypeInternal() {}
  union {
    XMsgHead _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT XMsgHeadDefaultTypeInternal _XMsgHead_default_instance_;
constexpr XLoginReq::XLoginReq(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : username_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , password_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct XLoginReqDefaultTypeInternal {
  constexpr XLoginReqDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~XLoginReqDefaultTypeInternal() {}
  union {
    XLoginReq _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT XLoginReqDefaultTypeInternal _XLoginReq_default_instance_;
constexpr XLoginRes::XLoginRes(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : token_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , res_(0)
{}
struct XLoginResDefaultTypeInternal {
  constexpr XLoginResDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~XLoginResDefaultTypeInternal() {}
  union {
    XLoginRes _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT XLoginResDefaultTypeInternal _XLoginRes_default_instance_;
}  // namespace xmsg
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_xmsg_5fcomm_2eproto[3];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_xmsg_5fcomm_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_xmsg_5fcomm_2eproto = nullptr;

const uint32_t TableStruct_xmsg_5fcomm_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::xmsg::XMsgHead, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::xmsg::XMsgHead, msg_size_),
  PROTOBUF_FIELD_OFFSET(::xmsg::XMsgHead, msg_type_),
  PROTOBUF_FIELD_OFFSET(::xmsg::XMsgHead, token_),
  PROTOBUF_FIELD_OFFSET(::xmsg::XMsgHead, service_name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::xmsg::XLoginReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::xmsg::XLoginReq, username_),
  PROTOBUF_FIELD_OFFSET(::xmsg::XLoginReq, password_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::xmsg::XLoginRes, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::xmsg::XLoginRes, res_),
  PROTOBUF_FIELD_OFFSET(::xmsg::XLoginRes, token_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::xmsg::XMsgHead)},
  { 10, -1, -1, sizeof(::xmsg::XLoginReq)},
  { 18, -1, -1, sizeof(::xmsg::XLoginRes)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::xmsg::_XMsgHead_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::xmsg::_XLoginReq_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::xmsg::_XLoginRes_default_instance_),
};

const char descriptor_table_protodef_xmsg_5fcomm_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017xmsg_comm.proto\022\004xmsg\032\017xmsg_type.proto"
  "\"b\n\010XMsgHead\022\020\n\010msg_size\030\001 \001(\005\022\037\n\010msg_ty"
  "pe\030\002 \001(\0162\r.xmsg.MsgType\022\r\n\005token\030\003 \001(\t\022\024"
  "\n\014service_name\030\004 \001(\t\"/\n\tXLoginReq\022\020\n\010use"
  "rname\030\001 \001(\t\022\020\n\010password\030\002 \001(\t\"v\n\tXLoginR"
  "es\022*\n\003res\030\001 \001(\0162\035.xmsg.XLoginRes.XLoginR"
  "esType\022\r\n\005token\030\002 \001(\t\".\n\rXLoginResType\022\006"
  "\n\002OK\020\000\022\t\n\005ERROR\020\001\022\n\n\006NOUSER\020\002b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_xmsg_5fcomm_2eproto_deps[1] = {
  &::descriptor_table_xmsg_5ftype_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_xmsg_5fcomm_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_xmsg_5fcomm_2eproto = {
  false, false, 317, descriptor_table_protodef_xmsg_5fcomm_2eproto, "xmsg_comm.proto", 
  &descriptor_table_xmsg_5fcomm_2eproto_once, descriptor_table_xmsg_5fcomm_2eproto_deps, 1, 3,
  schemas, file_default_instances, TableStruct_xmsg_5fcomm_2eproto::offsets,
  file_level_metadata_xmsg_5fcomm_2eproto, file_level_enum_descriptors_xmsg_5fcomm_2eproto, file_level_service_descriptors_xmsg_5fcomm_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_xmsg_5fcomm_2eproto_getter() {
  return &descriptor_table_xmsg_5fcomm_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_xmsg_5fcomm_2eproto(&descriptor_table_xmsg_5fcomm_2eproto);
namespace xmsg {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* XLoginRes_XLoginResType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_xmsg_5fcomm_2eproto);
  return file_level_enum_descriptors_xmsg_5fcomm_2eproto[0];
}
bool XLoginRes_XLoginResType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr XLoginRes_XLoginResType XLoginRes::OK;
constexpr XLoginRes_XLoginResType XLoginRes::ERROR;
constexpr XLoginRes_XLoginResType XLoginRes::NOUSER;
constexpr XLoginRes_XLoginResType XLoginRes::XLoginResType_MIN;
constexpr XLoginRes_XLoginResType XLoginRes::XLoginResType_MAX;
constexpr int XLoginRes::XLoginResType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class XMsgHead::_Internal {
 public:
};

XMsgHead::XMsgHead(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:xmsg.XMsgHead)
}
XMsgHead::XMsgHead(const XMsgHead& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_token().empty()) {
    token_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_token(), 
      GetArenaForAllocation());
  }
  service_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    service_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_service_name().empty()) {
    service_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_service_name(), 
      GetArenaForAllocation());
  }
  ::memcpy(&msg_size_, &from.msg_size_,
    static_cast<size_t>(reinterpret_cast<char*>(&msg_type_) -
    reinterpret_cast<char*>(&msg_size_)) + sizeof(msg_type_));
  // @@protoc_insertion_point(copy_constructor:xmsg.XMsgHead)
}

inline void XMsgHead::SharedCtor() {
token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
service_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  service_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&msg_size_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&msg_type_) -
    reinterpret_cast<char*>(&msg_size_)) + sizeof(msg_type_));
}

XMsgHead::~XMsgHead() {
  // @@protoc_insertion_point(destructor:xmsg.XMsgHead)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void XMsgHead::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  token_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  service_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void XMsgHead::ArenaDtor(void* object) {
  XMsgHead* _this = reinterpret_cast< XMsgHead* >(object);
  (void)_this;
}
void XMsgHead::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void XMsgHead::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void XMsgHead::Clear() {
// @@protoc_insertion_point(message_clear_start:xmsg.XMsgHead)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  token_.ClearToEmpty();
  service_name_.ClearToEmpty();
  ::memset(&msg_size_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&msg_type_) -
      reinterpret_cast<char*>(&msg_size_)) + sizeof(msg_type_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* XMsgHead::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 msg_size = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          msg_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .xmsg.MsgType msg_type = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_msg_type(static_cast<::xmsg::MsgType>(val));
        } else
          goto handle_unusual;
        continue;
      // string token = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_token();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "xmsg.XMsgHead.token"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string service_name = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_service_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "xmsg.XMsgHead.service_name"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* XMsgHead::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:xmsg.XMsgHead)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 msg_size = 1;
  if (this->_internal_msg_size() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_msg_size(), target);
  }

  // .xmsg.MsgType msg_type = 2;
  if (this->_internal_msg_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_msg_type(), target);
  }

  // string token = 3;
  if (!this->_internal_token().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_token().data(), static_cast<int>(this->_internal_token().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "xmsg.XMsgHead.token");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_token(), target);
  }

  // string service_name = 4;
  if (!this->_internal_service_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_service_name().data(), static_cast<int>(this->_internal_service_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "xmsg.XMsgHead.service_name");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_service_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:xmsg.XMsgHead)
  return target;
}

size_t XMsgHead::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:xmsg.XMsgHead)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string token = 3;
  if (!this->_internal_token().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_token());
  }

  // string service_name = 4;
  if (!this->_internal_service_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_service_name());
  }

  // int32 msg_size = 1;
  if (this->_internal_msg_size() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_msg_size());
  }

  // .xmsg.MsgType msg_type = 2;
  if (this->_internal_msg_type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_msg_type());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData XMsgHead::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    XMsgHead::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*XMsgHead::GetClassData() const { return &_class_data_; }

void XMsgHead::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<XMsgHead *>(to)->MergeFrom(
      static_cast<const XMsgHead &>(from));
}


void XMsgHead::MergeFrom(const XMsgHead& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xmsg.XMsgHead)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_token().empty()) {
    _internal_set_token(from._internal_token());
  }
  if (!from._internal_service_name().empty()) {
    _internal_set_service_name(from._internal_service_name());
  }
  if (from._internal_msg_size() != 0) {
    _internal_set_msg_size(from._internal_msg_size());
  }
  if (from._internal_msg_type() != 0) {
    _internal_set_msg_type(from._internal_msg_type());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void XMsgHead::CopyFrom(const XMsgHead& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xmsg.XMsgHead)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool XMsgHead::IsInitialized() const {
  return true;
}

void XMsgHead::InternalSwap(XMsgHead* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &token_, lhs_arena,
      &other->token_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &service_name_, lhs_arena,
      &other->service_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(XMsgHead, msg_type_)
      + sizeof(XMsgHead::msg_type_)
      - PROTOBUF_FIELD_OFFSET(XMsgHead, msg_size_)>(
          reinterpret_cast<char*>(&msg_size_),
          reinterpret_cast<char*>(&other->msg_size_));
}

::PROTOBUF_NAMESPACE_ID::Metadata XMsgHead::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_xmsg_5fcomm_2eproto_getter, &descriptor_table_xmsg_5fcomm_2eproto_once,
      file_level_metadata_xmsg_5fcomm_2eproto[0]);
}

// ===================================================================

class XLoginReq::_Internal {
 public:
};

XLoginReq::XLoginReq(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:xmsg.XLoginReq)
}
XLoginReq::XLoginReq(const XLoginReq& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  username_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    username_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_username().empty()) {
    username_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_username(), 
      GetArenaForAllocation());
  }
  password_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    password_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_password().empty()) {
    password_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_password(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:xmsg.XLoginReq)
}

inline void XLoginReq::SharedCtor() {
username_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  username_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
password_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  password_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

XLoginReq::~XLoginReq() {
  // @@protoc_insertion_point(destructor:xmsg.XLoginReq)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void XLoginReq::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  username_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  password_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void XLoginReq::ArenaDtor(void* object) {
  XLoginReq* _this = reinterpret_cast< XLoginReq* >(object);
  (void)_this;
}
void XLoginReq::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void XLoginReq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void XLoginReq::Clear() {
// @@protoc_insertion_point(message_clear_start:xmsg.XLoginReq)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  username_.ClearToEmpty();
  password_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* XLoginReq::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string username = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_username();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "xmsg.XLoginReq.username"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string password = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_password();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "xmsg.XLoginReq.password"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* XLoginReq::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:xmsg.XLoginReq)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string username = 1;
  if (!this->_internal_username().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_username().data(), static_cast<int>(this->_internal_username().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "xmsg.XLoginReq.username");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_username(), target);
  }

  // string password = 2;
  if (!this->_internal_password().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_password().data(), static_cast<int>(this->_internal_password().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "xmsg.XLoginReq.password");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_password(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:xmsg.XLoginReq)
  return target;
}

size_t XLoginReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:xmsg.XLoginReq)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string username = 1;
  if (!this->_internal_username().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_username());
  }

  // string password = 2;
  if (!this->_internal_password().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_password());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData XLoginReq::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    XLoginReq::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*XLoginReq::GetClassData() const { return &_class_data_; }

void XLoginReq::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<XLoginReq *>(to)->MergeFrom(
      static_cast<const XLoginReq &>(from));
}


void XLoginReq::MergeFrom(const XLoginReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xmsg.XLoginReq)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_username().empty()) {
    _internal_set_username(from._internal_username());
  }
  if (!from._internal_password().empty()) {
    _internal_set_password(from._internal_password());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void XLoginReq::CopyFrom(const XLoginReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xmsg.XLoginReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool XLoginReq::IsInitialized() const {
  return true;
}

void XLoginReq::InternalSwap(XLoginReq* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &username_, lhs_arena,
      &other->username_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &password_, lhs_arena,
      &other->password_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata XLoginReq::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_xmsg_5fcomm_2eproto_getter, &descriptor_table_xmsg_5fcomm_2eproto_once,
      file_level_metadata_xmsg_5fcomm_2eproto[1]);
}

// ===================================================================

class XLoginRes::_Internal {
 public:
};

XLoginRes::XLoginRes(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:xmsg.XLoginRes)
}
XLoginRes::XLoginRes(const XLoginRes& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_token().empty()) {
    token_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_token(), 
      GetArenaForAllocation());
  }
  res_ = from.res_;
  // @@protoc_insertion_point(copy_constructor:xmsg.XLoginRes)
}

inline void XLoginRes::SharedCtor() {
token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
res_ = 0;
}

XLoginRes::~XLoginRes() {
  // @@protoc_insertion_point(destructor:xmsg.XLoginRes)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void XLoginRes::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  token_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void XLoginRes::ArenaDtor(void* object) {
  XLoginRes* _this = reinterpret_cast< XLoginRes* >(object);
  (void)_this;
}
void XLoginRes::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void XLoginRes::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void XLoginRes::Clear() {
// @@protoc_insertion_point(message_clear_start:xmsg.XLoginRes)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  token_.ClearToEmpty();
  res_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* XLoginRes::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .xmsg.XLoginRes.XLoginResType res = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_res(static_cast<::xmsg::XLoginRes_XLoginResType>(val));
        } else
          goto handle_unusual;
        continue;
      // string token = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_token();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "xmsg.XLoginRes.token"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* XLoginRes::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:xmsg.XLoginRes)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .xmsg.XLoginRes.XLoginResType res = 1;
  if (this->_internal_res() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_res(), target);
  }

  // string token = 2;
  if (!this->_internal_token().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_token().data(), static_cast<int>(this->_internal_token().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "xmsg.XLoginRes.token");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_token(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:xmsg.XLoginRes)
  return target;
}

size_t XLoginRes::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:xmsg.XLoginRes)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string token = 2;
  if (!this->_internal_token().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_token());
  }

  // .xmsg.XLoginRes.XLoginResType res = 1;
  if (this->_internal_res() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_res());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData XLoginRes::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    XLoginRes::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*XLoginRes::GetClassData() const { return &_class_data_; }

void XLoginRes::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<XLoginRes *>(to)->MergeFrom(
      static_cast<const XLoginRes &>(from));
}


void XLoginRes::MergeFrom(const XLoginRes& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xmsg.XLoginRes)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_token().empty()) {
    _internal_set_token(from._internal_token());
  }
  if (from._internal_res() != 0) {
    _internal_set_res(from._internal_res());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void XLoginRes::CopyFrom(const XLoginRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xmsg.XLoginRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool XLoginRes::IsInitialized() const {
  return true;
}

void XLoginRes::InternalSwap(XLoginRes* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &token_, lhs_arena,
      &other->token_, rhs_arena
  );
  swap(res_, other->res_);
}

::PROTOBUF_NAMESPACE_ID::Metadata XLoginRes::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_xmsg_5fcomm_2eproto_getter, &descriptor_table_xmsg_5fcomm_2eproto_once,
      file_level_metadata_xmsg_5fcomm_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace xmsg
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::xmsg::XMsgHead* Arena::CreateMaybeMessage< ::xmsg::XMsgHead >(Arena* arena) {
  return Arena::CreateMessageInternal< ::xmsg::XMsgHead >(arena);
}
template<> PROTOBUF_NOINLINE ::xmsg::XLoginReq* Arena::CreateMaybeMessage< ::xmsg::XLoginReq >(Arena* arena) {
  return Arena::CreateMessageInternal< ::xmsg::XLoginReq >(arena);
}
template<> PROTOBUF_NOINLINE ::xmsg::XLoginRes* Arena::CreateMaybeMessage< ::xmsg::XLoginRes >(Arena* arena) {
  return Arena::CreateMessageInternal< ::xmsg::XLoginRes >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

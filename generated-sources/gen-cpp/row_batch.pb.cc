// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: row_batch.proto

#include "row_batch.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
#include "kudu/util/protobuf-annotations.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace impala {
class RowBatchHeaderPBDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RowBatchHeaderPB> _instance;
} _RowBatchHeaderPB_default_instance_;
}  // namespace impala
static void InitDefaultsscc_info_RowBatchHeaderPB_row_5fbatch_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::impala::_RowBatchHeaderPB_default_instance_;
    new (ptr) ::impala::RowBatchHeaderPB();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_RowBatchHeaderPB_row_5fbatch_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_RowBatchHeaderPB_row_5fbatch_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_row_5fbatch_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_row_5fbatch_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_row_5fbatch_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_row_5fbatch_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::impala::RowBatchHeaderPB, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::impala::RowBatchHeaderPB, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::impala::RowBatchHeaderPB, num_rows_),
  PROTOBUF_FIELD_OFFSET(::impala::RowBatchHeaderPB, num_tuples_per_row_),
  PROTOBUF_FIELD_OFFSET(::impala::RowBatchHeaderPB, uncompressed_size_),
  PROTOBUF_FIELD_OFFSET(::impala::RowBatchHeaderPB, compression_type_),
  0,
  1,
  2,
  3,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::impala::RowBatchHeaderPB)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::impala::_RowBatchHeaderPB_default_instance_),
};

const char descriptor_table_protodef_row_5fbatch_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017row_batch.proto\022\006impala\032\014common.proto\""
  "\220\001\n\020RowBatchHeaderPB\022\020\n\010num_rows\030\001 \001(\005\022\032"
  "\n\022num_tuples_per_row\030\002 \001(\005\022\031\n\021uncompress"
  "ed_size\030\003 \001(\003\0223\n\020compression_type\030\004 \001(\0162"
  "\031.impala.CompressionTypePB"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_row_5fbatch_2eproto_deps[1] = {
  &::descriptor_table_common_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_row_5fbatch_2eproto_sccs[1] = {
  &scc_info_RowBatchHeaderPB_row_5fbatch_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_row_5fbatch_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_row_5fbatch_2eproto = {
  false, false, descriptor_table_protodef_row_5fbatch_2eproto, "row_batch.proto", 186,
  &descriptor_table_row_5fbatch_2eproto_once, descriptor_table_row_5fbatch_2eproto_sccs, descriptor_table_row_5fbatch_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_row_5fbatch_2eproto::offsets,
  file_level_metadata_row_5fbatch_2eproto, 1, file_level_enum_descriptors_row_5fbatch_2eproto, file_level_service_descriptors_row_5fbatch_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_row_5fbatch_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_row_5fbatch_2eproto)), true);
namespace impala {

// ===================================================================

class RowBatchHeaderPB::_Internal {
 public:
  using HasBits = decltype(std::declval<RowBatchHeaderPB>()._has_bits_);
  static void set_has_num_rows(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_num_tuples_per_row(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_uncompressed_size(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_compression_type(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
};

RowBatchHeaderPB::RowBatchHeaderPB(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:impala.RowBatchHeaderPB)
}
RowBatchHeaderPB::RowBatchHeaderPB(const RowBatchHeaderPB& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&num_rows_, &from.num_rows_,
    static_cast<size_t>(reinterpret_cast<char*>(&compression_type_) -
    reinterpret_cast<char*>(&num_rows_)) + sizeof(compression_type_));
  // @@protoc_insertion_point(copy_constructor:impala.RowBatchHeaderPB)
}

void RowBatchHeaderPB::SharedCtor() {
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&num_rows_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&compression_type_) -
      reinterpret_cast<char*>(&num_rows_)) + sizeof(compression_type_));
}

RowBatchHeaderPB::~RowBatchHeaderPB() {
  // @@protoc_insertion_point(destructor:impala.RowBatchHeaderPB)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void RowBatchHeaderPB::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void RowBatchHeaderPB::ArenaDtor(void* object) {
  RowBatchHeaderPB* _this = reinterpret_cast< RowBatchHeaderPB* >(object);
  (void)_this;
}
void RowBatchHeaderPB::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RowBatchHeaderPB::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RowBatchHeaderPB& RowBatchHeaderPB::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RowBatchHeaderPB_row_5fbatch_2eproto.base);
  return *internal_default_instance();
}


void RowBatchHeaderPB::Clear() {
// @@protoc_insertion_point(message_clear_start:impala.RowBatchHeaderPB)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    ::memset(&num_rows_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&compression_type_) -
        reinterpret_cast<char*>(&num_rows_)) + sizeof(compression_type_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RowBatchHeaderPB::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 num_rows = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_num_rows(&has_bits);
          num_rows_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 num_tuples_per_row = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_num_tuples_per_row(&has_bits);
          num_tuples_per_row_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int64 uncompressed_size = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_uncompressed_size(&has_bits);
          uncompressed_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .impala.CompressionTypePB compression_type = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::impala::CompressionTypePB_IsValid(val))) {
            _internal_set_compression_type(static_cast<::impala::CompressionTypePB>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(4, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RowBatchHeaderPB::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:impala.RowBatchHeaderPB)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 num_rows = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_num_rows(), target);
  }

  // optional int32 num_tuples_per_row = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_num_tuples_per_row(), target);
  }

  // optional int64 uncompressed_size = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->_internal_uncompressed_size(), target);
  }

  // optional .impala.CompressionTypePB compression_type = 4;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      4, this->_internal_compression_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:impala.RowBatchHeaderPB)
  return target;
}

size_t RowBatchHeaderPB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:impala.RowBatchHeaderPB)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional int32 num_rows = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_num_rows());
    }

    // optional int32 num_tuples_per_row = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_num_tuples_per_row());
    }

    // optional int64 uncompressed_size = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_uncompressed_size());
    }

    // optional .impala.CompressionTypePB compression_type = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_compression_type());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RowBatchHeaderPB::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:impala.RowBatchHeaderPB)
  GOOGLE_DCHECK_NE(&from, this);
  const RowBatchHeaderPB* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RowBatchHeaderPB>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:impala.RowBatchHeaderPB)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:impala.RowBatchHeaderPB)
    MergeFrom(*source);
  }
}

void RowBatchHeaderPB::MergeFrom(const RowBatchHeaderPB& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:impala.RowBatchHeaderPB)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      num_rows_ = from.num_rows_;
    }
    if (cached_has_bits & 0x00000002u) {
      num_tuples_per_row_ = from.num_tuples_per_row_;
    }
    if (cached_has_bits & 0x00000004u) {
      uncompressed_size_ = from.uncompressed_size_;
    }
    if (cached_has_bits & 0x00000008u) {
      compression_type_ = from.compression_type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void RowBatchHeaderPB::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:impala.RowBatchHeaderPB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RowBatchHeaderPB::CopyFrom(const RowBatchHeaderPB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:impala.RowBatchHeaderPB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RowBatchHeaderPB::IsInitialized() const {
  return true;
}

void RowBatchHeaderPB::InternalSwap(RowBatchHeaderPB* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RowBatchHeaderPB, compression_type_)
      + sizeof(RowBatchHeaderPB::compression_type_)
      - PROTOBUF_FIELD_OFFSET(RowBatchHeaderPB, num_rows_)>(
          reinterpret_cast<char*>(&num_rows_),
          reinterpret_cast<char*>(&other->num_rows_));
}

::PROTOBUF_NAMESPACE_ID::Metadata RowBatchHeaderPB::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace impala
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::impala::RowBatchHeaderPB* Arena::CreateMaybeMessage< ::impala::RowBatchHeaderPB >(Arena* arena) {
  return Arena::CreateMessageInternal< ::impala::RowBatchHeaderPB >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

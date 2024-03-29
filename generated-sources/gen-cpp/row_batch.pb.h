// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: row_batch.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_row_5fbatch_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_row_5fbatch_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "common.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_row_5fbatch_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_row_5fbatch_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_row_5fbatch_2eproto;
namespace impala {
class RowBatchHeaderPB;
class RowBatchHeaderPBDefaultTypeInternal;
extern RowBatchHeaderPBDefaultTypeInternal _RowBatchHeaderPB_default_instance_;
}  // namespace impala
PROTOBUF_NAMESPACE_OPEN
template<> ::impala::RowBatchHeaderPB* Arena::CreateMaybeMessage<::impala::RowBatchHeaderPB>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace impala {

// ===================================================================

class RowBatchHeaderPB PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:impala.RowBatchHeaderPB) */ {
 public:
  inline RowBatchHeaderPB() : RowBatchHeaderPB(nullptr) {}
  virtual ~RowBatchHeaderPB();

  RowBatchHeaderPB(const RowBatchHeaderPB& from);
  RowBatchHeaderPB(RowBatchHeaderPB&& from) noexcept
    : RowBatchHeaderPB() {
    *this = ::std::move(from);
  }

  inline RowBatchHeaderPB& operator=(const RowBatchHeaderPB& from) {
    CopyFrom(from);
    return *this;
  }
  inline RowBatchHeaderPB& operator=(RowBatchHeaderPB&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const RowBatchHeaderPB& default_instance();

  static inline const RowBatchHeaderPB* internal_default_instance() {
    return reinterpret_cast<const RowBatchHeaderPB*>(
               &_RowBatchHeaderPB_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RowBatchHeaderPB& a, RowBatchHeaderPB& b) {
    a.Swap(&b);
  }
  inline void Swap(RowBatchHeaderPB* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RowBatchHeaderPB* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RowBatchHeaderPB* New() const final {
    return CreateMaybeMessage<RowBatchHeaderPB>(nullptr);
  }

  RowBatchHeaderPB* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RowBatchHeaderPB>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RowBatchHeaderPB& from);
  void MergeFrom(const RowBatchHeaderPB& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RowBatchHeaderPB* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "impala.RowBatchHeaderPB";
  }
  protected:
  explicit RowBatchHeaderPB(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_row_5fbatch_2eproto);
    return ::descriptor_table_row_5fbatch_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNumRowsFieldNumber = 1,
    kNumTuplesPerRowFieldNumber = 2,
    kUncompressedSizeFieldNumber = 3,
    kCompressionTypeFieldNumber = 4,
  };
  // optional int32 num_rows = 1;
  bool has_num_rows() const;
  private:
  bool _internal_has_num_rows() const;
  public:
  void clear_num_rows();
  ::PROTOBUF_NAMESPACE_ID::int32 num_rows() const;
  void set_num_rows(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_num_rows() const;
  void _internal_set_num_rows(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional int32 num_tuples_per_row = 2;
  bool has_num_tuples_per_row() const;
  private:
  bool _internal_has_num_tuples_per_row() const;
  public:
  void clear_num_tuples_per_row();
  ::PROTOBUF_NAMESPACE_ID::int32 num_tuples_per_row() const;
  void set_num_tuples_per_row(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_num_tuples_per_row() const;
  void _internal_set_num_tuples_per_row(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional int64 uncompressed_size = 3;
  bool has_uncompressed_size() const;
  private:
  bool _internal_has_uncompressed_size() const;
  public:
  void clear_uncompressed_size();
  ::PROTOBUF_NAMESPACE_ID::int64 uncompressed_size() const;
  void set_uncompressed_size(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_uncompressed_size() const;
  void _internal_set_uncompressed_size(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // optional .impala.CompressionTypePB compression_type = 4;
  bool has_compression_type() const;
  private:
  bool _internal_has_compression_type() const;
  public:
  void clear_compression_type();
  ::impala::CompressionTypePB compression_type() const;
  void set_compression_type(::impala::CompressionTypePB value);
  private:
  ::impala::CompressionTypePB _internal_compression_type() const;
  void _internal_set_compression_type(::impala::CompressionTypePB value);
  public:

  // @@protoc_insertion_point(class_scope:impala.RowBatchHeaderPB)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 num_rows_;
  ::PROTOBUF_NAMESPACE_ID::int32 num_tuples_per_row_;
  ::PROTOBUF_NAMESPACE_ID::int64 uncompressed_size_;
  int compression_type_;
  friend struct ::TableStruct_row_5fbatch_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RowBatchHeaderPB

// optional int32 num_rows = 1;
inline bool RowBatchHeaderPB::_internal_has_num_rows() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool RowBatchHeaderPB::has_num_rows() const {
  return _internal_has_num_rows();
}
inline void RowBatchHeaderPB::clear_num_rows() {
  num_rows_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RowBatchHeaderPB::_internal_num_rows() const {
  return num_rows_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RowBatchHeaderPB::num_rows() const {
  // @@protoc_insertion_point(field_get:impala.RowBatchHeaderPB.num_rows)
  return _internal_num_rows();
}
inline void RowBatchHeaderPB::_internal_set_num_rows(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  num_rows_ = value;
}
inline void RowBatchHeaderPB::set_num_rows(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_num_rows(value);
  // @@protoc_insertion_point(field_set:impala.RowBatchHeaderPB.num_rows)
}

// optional int32 num_tuples_per_row = 2;
inline bool RowBatchHeaderPB::_internal_has_num_tuples_per_row() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool RowBatchHeaderPB::has_num_tuples_per_row() const {
  return _internal_has_num_tuples_per_row();
}
inline void RowBatchHeaderPB::clear_num_tuples_per_row() {
  num_tuples_per_row_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RowBatchHeaderPB::_internal_num_tuples_per_row() const {
  return num_tuples_per_row_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RowBatchHeaderPB::num_tuples_per_row() const {
  // @@protoc_insertion_point(field_get:impala.RowBatchHeaderPB.num_tuples_per_row)
  return _internal_num_tuples_per_row();
}
inline void RowBatchHeaderPB::_internal_set_num_tuples_per_row(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  num_tuples_per_row_ = value;
}
inline void RowBatchHeaderPB::set_num_tuples_per_row(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_num_tuples_per_row(value);
  // @@protoc_insertion_point(field_set:impala.RowBatchHeaderPB.num_tuples_per_row)
}

// optional int64 uncompressed_size = 3;
inline bool RowBatchHeaderPB::_internal_has_uncompressed_size() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool RowBatchHeaderPB::has_uncompressed_size() const {
  return _internal_has_uncompressed_size();
}
inline void RowBatchHeaderPB::clear_uncompressed_size() {
  uncompressed_size_ = PROTOBUF_LONGLONG(0);
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 RowBatchHeaderPB::_internal_uncompressed_size() const {
  return uncompressed_size_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 RowBatchHeaderPB::uncompressed_size() const {
  // @@protoc_insertion_point(field_get:impala.RowBatchHeaderPB.uncompressed_size)
  return _internal_uncompressed_size();
}
inline void RowBatchHeaderPB::_internal_set_uncompressed_size(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _has_bits_[0] |= 0x00000004u;
  uncompressed_size_ = value;
}
inline void RowBatchHeaderPB::set_uncompressed_size(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_uncompressed_size(value);
  // @@protoc_insertion_point(field_set:impala.RowBatchHeaderPB.uncompressed_size)
}

// optional .impala.CompressionTypePB compression_type = 4;
inline bool RowBatchHeaderPB::_internal_has_compression_type() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool RowBatchHeaderPB::has_compression_type() const {
  return _internal_has_compression_type();
}
inline void RowBatchHeaderPB::clear_compression_type() {
  compression_type_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::impala::CompressionTypePB RowBatchHeaderPB::_internal_compression_type() const {
  return static_cast< ::impala::CompressionTypePB >(compression_type_);
}
inline ::impala::CompressionTypePB RowBatchHeaderPB::compression_type() const {
  // @@protoc_insertion_point(field_get:impala.RowBatchHeaderPB.compression_type)
  return _internal_compression_type();
}
inline void RowBatchHeaderPB::_internal_set_compression_type(::impala::CompressionTypePB value) {
  assert(::impala::CompressionTypePB_IsValid(value));
  _has_bits_[0] |= 0x00000008u;
  compression_type_ = value;
}
inline void RowBatchHeaderPB::set_compression_type(::impala::CompressionTypePB value) {
  _internal_set_compression_type(value);
  // @@protoc_insertion_point(field_set:impala.RowBatchHeaderPB.compression_type)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace impala

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_row_5fbatch_2eproto

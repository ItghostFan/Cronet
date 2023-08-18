#ifndef SRC_TRACE_PROCESSOR_TABLES_TRACE_PROTO_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_TRACE_PROTO_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"



namespace perfetto {
namespace trace_processor {
namespace tables {

class ExperimentalProtoPathTable : public macros_internal::MacroTable {
 public:
  struct Id : public BaseId {
    Id() = default;
    explicit constexpr Id(uint32_t v) : BaseId(v) {}
  };
  static_assert(std::is_trivially_destructible<Id>::value,
                "Inheritance used without trivial destruction");
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t parent_id = 2;
    static constexpr uint32_t field_type = 3;
    static constexpr uint32_t field_name = 4;
    static constexpr uint32_t arg_set_id = 5;
  };
  struct ColumnType {
    using id = IdColumn<ExperimentalProtoPathTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<ExperimentalProtoPathTable::Id>>;
    using field_type = TypedColumn<StringPool::Id>;
    using field_name = TypedColumn<std::optional<StringPool::Id>>;
    using arg_set_id = TypedColumn<std::optional<uint32_t>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(std::optional<ExperimentalProtoPathTable::Id> in_parent_id = {},
        StringPool::Id in_field_type = {},
        std::optional<StringPool::Id> in_field_name = {},
        std::optional<uint32_t> in_arg_set_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          parent_id(std::move(in_parent_id)),
          field_type(std::move(in_field_type)),
          field_name(std::move(in_field_name)),
          arg_set_id(std::move(in_arg_set_id)) {
      type_ = "experimental_proto_path";
    }
    std::optional<ExperimentalProtoPathTable::Id> parent_id;
    StringPool::Id field_type;
    std::optional<StringPool::Id> field_name;
    std::optional<uint32_t> arg_set_id;

    bool operator==(const ExperimentalProtoPathTable::Row& other) const {
      return type() == other.type() && ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::field_type::Equals(field_type, other.field_type) &&
       ColumnType::field_name::Equals(field_name, other.field_name) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t parent_id = ColumnType::parent_id::default_flags();
    static constexpr uint32_t field_type = ColumnType::field_type::default_flags();
    static constexpr uint32_t field_name = ColumnType::field_name::default_flags();
    static constexpr uint32_t arg_set_id = ColumnType::arg_set_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ExperimentalProtoPathTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExperimentalProtoPathTable, RowNumber> {
   public:
    ConstRowReference(const ExperimentalProtoPathTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::field_type::type field_type() const {
      return table_->field_type()[row_number_];
    }
    ColumnType::field_name::type field_name() const {
      return table_->field_name()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExperimentalProtoPathTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_field_type(
        ColumnType::field_type::non_optional_type v) {
      return mutable_table()->mutable_field_type()->Set(row_number_, v);
    }
    void set_field_name(
        ColumnType::field_name::non_optional_type v) {
      return mutable_table()->mutable_field_name()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }

   private:
    ExperimentalProtoPathTable* mutable_table() const {
      return const_cast<ExperimentalProtoPathTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExperimentalProtoPathTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::field_type::type field_type() const {
      const auto& col = table_->field_type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::field_name::type field_name() const {
      const auto& col = table_->field_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExperimentalProtoPathTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExperimentalProtoPathTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ExperimentalProtoPathTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_field_type(ColumnType::field_type::non_optional_type v) {
        auto* col = mutable_table_->mutable_field_type();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_field_name(ColumnType::field_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_field_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ExperimentalProtoPathTable;

    explicit Iterator(ExperimentalProtoPathTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExperimentalProtoPathTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExperimentalProtoPathTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        parent_id_(ColumnStorage<ColumnType::parent_id::stored_type>::Create<false>()),
        field_type_(ColumnStorage<ColumnType::field_type::stored_type>::Create<false>()),
        field_name_(ColumnStorage<ColumnType::field_name::stored_type>::Create<false>()),
        arg_set_id_(ColumnStorage<ColumnType::arg_set_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::parent_id::stored_type>(
          ColumnFlag::parent_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::field_type::stored_type>(
          ColumnFlag::field_type),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::field_name::stored_type>(
          ColumnFlag::field_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::arg_set_id::stored_type>(
          ColumnFlag::arg_set_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("parent_id", &parent_id_, ColumnFlag::parent_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("field_type", &field_type_, ColumnFlag::field_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("field_name", &field_name_, ColumnFlag::field_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("arg_set_id", &arg_set_id_, ColumnFlag::arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ExperimentalProtoPathTable() override;

  static const char* Name() { return "experimental_proto_path"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "field_type", ColumnType::field_type::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "field_name", ColumnType::field_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    return schema;
  }

  ConstIterator IterateRows() const {
    return ConstIterator(this, CopyOverlays());
  }

  Iterator IterateRows() { return Iterator(this, CopyOverlays()); }

  ConstIterator FilterToIterator(
      const std::vector<Constraint>& cs,
      RowMap::OptimizeFor opt = RowMap::OptimizeFor::kMemory) const {
    return ConstIterator(this, FilterAndApplyToOverlays(cs, opt));
  }

  Iterator FilterToIterator(
      const std::vector<Constraint>& cs,
      RowMap::OptimizeFor opt = RowMap::OptimizeFor::kMemory) {
    return Iterator(this, FilterAndApplyToOverlays(cs, opt));
  }

  void ShrinkToFit() {
    type_.ShrinkToFit();
    parent_id_.ShrinkToFit();
    field_type_.ShrinkToFit();
    field_name_.ShrinkToFit();
    arg_set_id_.ShrinkToFit();
  }

  std::optional<ConstRowReference> FindById(Id find_id) const {
    std::optional<uint32_t> row = id().IndexOf(find_id);
    return row ? std::make_optional(ConstRowReference(this, *row))
               : std::nullopt;
  }

  std::optional<RowReference> FindById(Id find_id) {
    std::optional<uint32_t> row = id().IndexOf(find_id);
    return row ? std::make_optional(RowReference(this, *row)) : std::nullopt;
  }

  IdAndRow Insert(const Row& row) {
    uint32_t row_number = row_count();
    Id id = Id{row_number};
    type_.Append(string_pool_->InternString(row.type()));
    mutable_parent_id()->Append(std::move(row.parent_id));
    mutable_field_type()->Append(std::move(row.field_type));
    mutable_field_name()->Append(std::move(row.field_name));
    mutable_arg_set_id()->Append(std::move(row.arg_set_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ExperimentalProtoPathTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<std::optional<ExperimentalProtoPathTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<StringPool::Id>& field_type() const {
    return static_cast<const ColumnType::field_type&>(columns_[ColumnIndex::field_type]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& field_name() const {
    return static_cast<const ColumnType::field_name&>(columns_[ColumnIndex::field_name]);
  }
  const TypedColumn<std::optional<uint32_t>>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }

  TypedColumn<std::optional<ExperimentalProtoPathTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<StringPool::Id>* mutable_field_type() {
    return static_cast<ColumnType::field_type*>(
        &columns_[ColumnIndex::field_type]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_field_name() {
    return static_cast<ColumnType::field_name*>(
        &columns_[ColumnIndex::field_name]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::parent_id::stored_type> parent_id_;
  ColumnStorage<ColumnType::field_type::stored_type> field_type_;
  ColumnStorage<ColumnType::field_name::stored_type> field_name_;
  ColumnStorage<ColumnType::arg_set_id::stored_type> arg_set_id_;
};
  

class ExperimentalProtoContentTable : public macros_internal::MacroTable {
 public:
  struct Id : public BaseId {
    Id() = default;
    explicit constexpr Id(uint32_t v) : BaseId(v) {}
  };
  static_assert(std::is_trivially_destructible<Id>::value,
                "Inheritance used without trivial destruction");
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t path = 2;
    static constexpr uint32_t path_id = 3;
    static constexpr uint32_t total_size = 4;
    static constexpr uint32_t size = 5;
    static constexpr uint32_t count = 6;
  };
  struct ColumnType {
    using id = IdColumn<ExperimentalProtoContentTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using path = TypedColumn<StringPool::Id>;
    using path_id = TypedColumn<ExperimentalProtoPathTable::Id>;
    using total_size = TypedColumn<int64_t>;
    using size = TypedColumn<int64_t>;
    using count = TypedColumn<int64_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_path = {},
        ExperimentalProtoPathTable::Id in_path_id = {},
        int64_t in_total_size = {},
        int64_t in_size = {},
        int64_t in_count = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          path(std::move(in_path)),
          path_id(std::move(in_path_id)),
          total_size(std::move(in_total_size)),
          size(std::move(in_size)),
          count(std::move(in_count)) {
      type_ = "experimental_proto_content";
    }
    StringPool::Id path;
    ExperimentalProtoPathTable::Id path_id;
    int64_t total_size;
    int64_t size;
    int64_t count;

    bool operator==(const ExperimentalProtoContentTable::Row& other) const {
      return type() == other.type() && ColumnType::path::Equals(path, other.path) &&
       ColumnType::path_id::Equals(path_id, other.path_id) &&
       ColumnType::total_size::Equals(total_size, other.total_size) &&
       ColumnType::size::Equals(size, other.size) &&
       ColumnType::count::Equals(count, other.count);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t path = ColumnType::path::default_flags();
    static constexpr uint32_t path_id = ColumnType::path_id::default_flags();
    static constexpr uint32_t total_size = ColumnType::total_size::default_flags();
    static constexpr uint32_t size = ColumnType::size::default_flags();
    static constexpr uint32_t count = ColumnType::count::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ExperimentalProtoContentTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExperimentalProtoContentTable, RowNumber> {
   public:
    ConstRowReference(const ExperimentalProtoContentTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::path::type path() const {
      return table_->path()[row_number_];
    }
    ColumnType::path_id::type path_id() const {
      return table_->path_id()[row_number_];
    }
    ColumnType::total_size::type total_size() const {
      return table_->total_size()[row_number_];
    }
    ColumnType::size::type size() const {
      return table_->size()[row_number_];
    }
    ColumnType::count::type count() const {
      return table_->count()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExperimentalProtoContentTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_path(
        ColumnType::path::non_optional_type v) {
      return mutable_table()->mutable_path()->Set(row_number_, v);
    }
    void set_path_id(
        ColumnType::path_id::non_optional_type v) {
      return mutable_table()->mutable_path_id()->Set(row_number_, v);
    }
    void set_total_size(
        ColumnType::total_size::non_optional_type v) {
      return mutable_table()->mutable_total_size()->Set(row_number_, v);
    }
    void set_size(
        ColumnType::size::non_optional_type v) {
      return mutable_table()->mutable_size()->Set(row_number_, v);
    }
    void set_count(
        ColumnType::count::non_optional_type v) {
      return mutable_table()->mutable_count()->Set(row_number_, v);
    }

   private:
    ExperimentalProtoContentTable* mutable_table() const {
      return const_cast<ExperimentalProtoContentTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExperimentalProtoContentTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::path::type path() const {
      const auto& col = table_->path();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::path_id::type path_id() const {
      const auto& col = table_->path_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::total_size::type total_size() const {
      const auto& col = table_->total_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::size::type size() const {
      const auto& col = table_->size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::count::type count() const {
      const auto& col = table_->count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExperimentalProtoContentTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExperimentalProtoContentTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ExperimentalProtoContentTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_path(ColumnType::path::non_optional_type v) {
        auto* col = mutable_table_->mutable_path();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_path_id(ColumnType::path_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_path_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_total_size(ColumnType::total_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_total_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_size(ColumnType::size::non_optional_type v) {
        auto* col = mutable_table_->mutable_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_count(ColumnType::count::non_optional_type v) {
        auto* col = mutable_table_->mutable_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ExperimentalProtoContentTable;

    explicit Iterator(ExperimentalProtoContentTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExperimentalProtoContentTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExperimentalProtoContentTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        path_(ColumnStorage<ColumnType::path::stored_type>::Create<false>()),
        path_id_(ColumnStorage<ColumnType::path_id::stored_type>::Create<false>()),
        total_size_(ColumnStorage<ColumnType::total_size::stored_type>::Create<false>()),
        size_(ColumnStorage<ColumnType::size::stored_type>::Create<false>()),
        count_(ColumnStorage<ColumnType::count::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::path::stored_type>(
          ColumnFlag::path),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::path_id::stored_type>(
          ColumnFlag::path_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::total_size::stored_type>(
          ColumnFlag::total_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::size::stored_type>(
          ColumnFlag::size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::count::stored_type>(
          ColumnFlag::count),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("path", &path_, ColumnFlag::path,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("path_id", &path_id_, ColumnFlag::path_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("total_size", &total_size_, ColumnFlag::total_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("size", &size_, ColumnFlag::size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("count", &count_, ColumnFlag::count,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ExperimentalProtoContentTable() override;

  static const char* Name() { return "experimental_proto_content"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "path", ColumnType::path::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "path_id", ColumnType::path_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "total_size", ColumnType::total_size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "size", ColumnType::size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "count", ColumnType::count::SqlValueType(), false,
        false,
        false,
        false});
    return schema;
  }

  ConstIterator IterateRows() const {
    return ConstIterator(this, CopyOverlays());
  }

  Iterator IterateRows() { return Iterator(this, CopyOverlays()); }

  ConstIterator FilterToIterator(
      const std::vector<Constraint>& cs,
      RowMap::OptimizeFor opt = RowMap::OptimizeFor::kMemory) const {
    return ConstIterator(this, FilterAndApplyToOverlays(cs, opt));
  }

  Iterator FilterToIterator(
      const std::vector<Constraint>& cs,
      RowMap::OptimizeFor opt = RowMap::OptimizeFor::kMemory) {
    return Iterator(this, FilterAndApplyToOverlays(cs, opt));
  }

  void ShrinkToFit() {
    type_.ShrinkToFit();
    path_.ShrinkToFit();
    path_id_.ShrinkToFit();
    total_size_.ShrinkToFit();
    size_.ShrinkToFit();
    count_.ShrinkToFit();
  }

  std::optional<ConstRowReference> FindById(Id find_id) const {
    std::optional<uint32_t> row = id().IndexOf(find_id);
    return row ? std::make_optional(ConstRowReference(this, *row))
               : std::nullopt;
  }

  std::optional<RowReference> FindById(Id find_id) {
    std::optional<uint32_t> row = id().IndexOf(find_id);
    return row ? std::make_optional(RowReference(this, *row)) : std::nullopt;
  }

  IdAndRow Insert(const Row& row) {
    uint32_t row_number = row_count();
    Id id = Id{row_number};
    type_.Append(string_pool_->InternString(row.type()));
    mutable_path()->Append(std::move(row.path));
    mutable_path_id()->Append(std::move(row.path_id));
    mutable_total_size()->Append(std::move(row.total_size));
    mutable_size()->Append(std::move(row.size));
    mutable_count()->Append(std::move(row.count));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ExperimentalProtoContentTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& path() const {
    return static_cast<const ColumnType::path&>(columns_[ColumnIndex::path]);
  }
  const TypedColumn<ExperimentalProtoPathTable::Id>& path_id() const {
    return static_cast<const ColumnType::path_id&>(columns_[ColumnIndex::path_id]);
  }
  const TypedColumn<int64_t>& total_size() const {
    return static_cast<const ColumnType::total_size&>(columns_[ColumnIndex::total_size]);
  }
  const TypedColumn<int64_t>& size() const {
    return static_cast<const ColumnType::size&>(columns_[ColumnIndex::size]);
  }
  const TypedColumn<int64_t>& count() const {
    return static_cast<const ColumnType::count&>(columns_[ColumnIndex::count]);
  }

  TypedColumn<StringPool::Id>* mutable_path() {
    return static_cast<ColumnType::path*>(
        &columns_[ColumnIndex::path]);
  }
  TypedColumn<ExperimentalProtoPathTable::Id>* mutable_path_id() {
    return static_cast<ColumnType::path_id*>(
        &columns_[ColumnIndex::path_id]);
  }
  TypedColumn<int64_t>* mutable_total_size() {
    return static_cast<ColumnType::total_size*>(
        &columns_[ColumnIndex::total_size]);
  }
  TypedColumn<int64_t>* mutable_size() {
    return static_cast<ColumnType::size*>(
        &columns_[ColumnIndex::size]);
  }
  TypedColumn<int64_t>* mutable_count() {
    return static_cast<ColumnType::count*>(
        &columns_[ColumnIndex::count]);
  }

 private:
  
  
  ColumnStorage<ColumnType::path::stored_type> path_;
  ColumnStorage<ColumnType::path_id::stored_type> path_id_;
  ColumnStorage<ColumnType::total_size::stored_type> total_size_;
  ColumnStorage<ColumnType::size::stored_type> size_;
  ColumnStorage<ColumnType::count::stored_type> count_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_TRACE_PROTO_TABLES_PY_H_

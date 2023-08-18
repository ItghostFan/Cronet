#ifndef SRC_TRACE_PROCESSOR_TABLES_TRACK_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_TRACK_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"



namespace perfetto {
namespace trace_processor {
namespace tables {

class TrackTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
  };
  struct ColumnType {
    using id = IdColumn<TrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<TrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<TrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          name(std::move(in_name)),
          parent_id(std::move(in_parent_id)),
          source_arg_set_id(std::move(in_source_arg_set_id)) {
      type_ = "track";
    }
    StringPool::Id name;
    std::optional<TrackTable::Id> parent_id;
    std::optional<uint32_t> source_arg_set_id;

    bool operator==(const TrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t parent_id = ColumnType::parent_id::default_flags();
    static constexpr uint32_t source_arg_set_id = ColumnType::source_arg_set_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      TrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    TrackTable, RowNumber> {
   public:
    ConstRowReference(const TrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const TrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }

   private:
    TrackTable* mutable_table() const {
      return const_cast<TrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, TrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const TrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class TrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, TrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class TrackTable;

    explicit Iterator(TrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    TrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit TrackTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        parent_id_(ColumnStorage<ColumnType::parent_id::stored_type>::Create<false>()),
        source_arg_set_id_(ColumnStorage<ColumnType::source_arg_set_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::parent_id::stored_type>(
          ColumnFlag::parent_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::source_arg_set_id::stored_type>(
          ColumnFlag::source_arg_set_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("parent_id", &parent_id_, ColumnFlag::parent_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("source_arg_set_id", &source_arg_set_id_, ColumnFlag::source_arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~TrackTable() override;

  static const char* Name() { return "track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
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
    name_.ShrinkToFit();
    parent_id_.ShrinkToFit();
    source_arg_set_id_.ShrinkToFit();
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
    mutable_name()->Append(std::move(row.name));
    mutable_parent_id()->Append(std::move(row.parent_id));
    mutable_source_arg_set_id()->Append(std::move(row.source_arg_set_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<TrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<TrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<TrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::parent_id::stored_type> parent_id_;
  ColumnStorage<ColumnType::source_arg_set_id::stored_type> source_arg_set_id_;
};
  

class CounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = TrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
  };
  struct ColumnType {
    using id = IdColumn<CounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<CounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
  };
  struct Row : public TrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<CounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        std::nullptr_t = nullptr)
        : TrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id)),
          unit(std::move(in_unit)),
          description(std::move(in_description)) {
      type_ = "counter_track";
    }
    StringPool::Id unit;
    StringPool::Id description;

    bool operator==(const CounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t unit = ColumnType::unit::default_flags();
    static constexpr uint32_t description = ColumnType::description::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      CounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    CounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const CounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const CounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }

   private:
    CounterTrackTable* mutable_table() const {
      return const_cast<CounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, CounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const CounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class CounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, CounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class CounterTrackTable;

    explicit Iterator(CounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    CounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit CounterTrackTable(StringPool* pool, TrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), unit_(ColumnStorage<ColumnType::unit::stored_type>::Create<false>()),
        description_(ColumnStorage<ColumnType::description::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::unit::stored_type>(
          ColumnFlag::unit),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::description::stored_type>(
          ColumnFlag::description),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("unit", &unit_, ColumnFlag::unit,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("description", &description_, ColumnFlag::description,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~CounterTrackTable() override;

  static const char* Name() { return "counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
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
    unit_.ShrinkToFit();
    description_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_unit()->Append(std::move(row.unit));
    mutable_description()->Append(std::move(row.description));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const TrackTable& parent,
      ColumnStorage<ColumnType::unit::stored_type> unit
, ColumnStorage<ColumnType::description::stored_type> description) {
    return std::unique_ptr<Table>(new CounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(unit), std::move(description)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const TrackTable& parent,
      std::vector<TrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::unit::stored_type> unit
, ColumnStorage<ColumnType::description::stored_type> description) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new CounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(unit), std::move(description)));
  }

  const IdColumn<CounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<CounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<CounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }

 private:
  CounterTrackTable(StringPool* pool,
            const TrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::unit::stored_type> unit
, ColumnStorage<ColumnType::description::stored_type> description)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::unit::stored_type>(
          ColumnFlag::unit),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::description::stored_type>(
          ColumnFlag::description),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(unit.size() == parent_overlay.size());
    unit_ = std::move(unit);
    PERFETTO_DCHECK(description.size() == parent_overlay.size());
    description_ = std::move(description);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("unit", &unit_, ColumnFlag::unit,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("description", &description_, ColumnFlag::description,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  TrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::unit::stored_type> unit_;
  ColumnStorage<ColumnType::description::stored_type> description_;
};
  

class CpuCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t cpu = 7;
  };
  struct ColumnType {
    using id = IdColumn<CpuCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<CpuCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using cpu = TypedColumn<uint32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<CpuCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        uint32_t in_cpu = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          cpu(std::move(in_cpu)) {
      type_ = "cpu_counter_track";
    }
    uint32_t cpu;

    bool operator==(const CpuCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::cpu::Equals(cpu, other.cpu);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t cpu = ColumnType::cpu::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      CpuCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    CpuCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const CpuCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::cpu::type cpu() const {
      return table_->cpu()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const CpuCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_cpu(
        ColumnType::cpu::non_optional_type v) {
      return mutable_table()->mutable_cpu()->Set(row_number_, v);
    }

   private:
    CpuCounterTrackTable* mutable_table() const {
      return const_cast<CpuCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, CpuCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cpu::type cpu() const {
      const auto& col = table_->cpu();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const CpuCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class CpuCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, CpuCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cpu(ColumnType::cpu::non_optional_type v) {
        auto* col = mutable_table_->mutable_cpu();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class CpuCounterTrackTable;

    explicit Iterator(CpuCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    CpuCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit CpuCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), cpu_(ColumnStorage<ColumnType::cpu::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~CpuCounterTrackTable() override;

  static const char* Name() { return "cpu_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cpu", ColumnType::cpu::SqlValueType(), false,
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
    cpu_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_cpu()->Append(std::move(row.cpu));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::cpu::stored_type> cpu) {
    return std::unique_ptr<Table>(new CpuCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(cpu)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::cpu::stored_type> cpu) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new CpuCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(cpu)));
  }

  const IdColumn<CpuCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<CpuCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<uint32_t>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<CpuCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<uint32_t>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }

 private:
  CpuCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::cpu::stored_type> cpu)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(cpu.size() == parent_overlay.size());
    cpu_ = std::move(cpu);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::cpu::stored_type> cpu_;
};
  

class CpuTrackTable : public macros_internal::MacroTable {
 public:
  using Id = TrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t cpu = 5;
  };
  struct ColumnType {
    using id = IdColumn<CpuTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<CpuTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using cpu = TypedColumn<uint32_t>;
  };
  struct Row : public TrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<CpuTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        uint32_t in_cpu = {},
        std::nullptr_t = nullptr)
        : TrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id)),
          cpu(std::move(in_cpu)) {
      type_ = "cpu_track";
    }
    uint32_t cpu;

    bool operator==(const CpuTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::cpu::Equals(cpu, other.cpu);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t cpu = ColumnType::cpu::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      CpuTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    CpuTrackTable, RowNumber> {
   public:
    ConstRowReference(const CpuTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::cpu::type cpu() const {
      return table_->cpu()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const CpuTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_cpu(
        ColumnType::cpu::non_optional_type v) {
      return mutable_table()->mutable_cpu()->Set(row_number_, v);
    }

   private:
    CpuTrackTable* mutable_table() const {
      return const_cast<CpuTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, CpuTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cpu::type cpu() const {
      const auto& col = table_->cpu();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const CpuTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class CpuTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, CpuTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cpu(ColumnType::cpu::non_optional_type v) {
        auto* col = mutable_table_->mutable_cpu();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class CpuTrackTable;

    explicit Iterator(CpuTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    CpuTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit CpuTrackTable(StringPool* pool, TrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), cpu_(ColumnStorage<ColumnType::cpu::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~CpuTrackTable() override;

  static const char* Name() { return "cpu_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cpu", ColumnType::cpu::SqlValueType(), false,
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
    cpu_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_cpu()->Append(std::move(row.cpu));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const TrackTable& parent,
      ColumnStorage<ColumnType::cpu::stored_type> cpu) {
    return std::unique_ptr<Table>(new CpuTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(cpu)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const TrackTable& parent,
      std::vector<TrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::cpu::stored_type> cpu) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new CpuTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(cpu)));
  }

  const IdColumn<CpuTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<CpuTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<uint32_t>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<CpuTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<uint32_t>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }

 private:
  CpuTrackTable(StringPool* pool,
            const TrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::cpu::stored_type> cpu)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(cpu.size() == parent_overlay.size());
    cpu_ = std::move(cpu);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  TrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::cpu::stored_type> cpu_;
};
  

class EnergyCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t consumer_id = 7;
    static constexpr uint32_t consumer_type = 8;
    static constexpr uint32_t ordinal = 9;
  };
  struct ColumnType {
    using id = IdColumn<EnergyCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<EnergyCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using consumer_id = TypedColumn<int32_t>;
    using consumer_type = TypedColumn<StringPool::Id>;
    using ordinal = TypedColumn<int32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<EnergyCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        int32_t in_consumer_id = {},
        StringPool::Id in_consumer_type = {},
        int32_t in_ordinal = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          consumer_id(std::move(in_consumer_id)),
          consumer_type(std::move(in_consumer_type)),
          ordinal(std::move(in_ordinal)) {
      type_ = "energy_counter_track";
    }
    int32_t consumer_id;
    StringPool::Id consumer_type;
    int32_t ordinal;

    bool operator==(const EnergyCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::consumer_id::Equals(consumer_id, other.consumer_id) &&
       ColumnType::consumer_type::Equals(consumer_type, other.consumer_type) &&
       ColumnType::ordinal::Equals(ordinal, other.ordinal);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t consumer_id = ColumnType::consumer_id::default_flags();
    static constexpr uint32_t consumer_type = ColumnType::consumer_type::default_flags();
    static constexpr uint32_t ordinal = ColumnType::ordinal::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      EnergyCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    EnergyCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const EnergyCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::consumer_id::type consumer_id() const {
      return table_->consumer_id()[row_number_];
    }
    ColumnType::consumer_type::type consumer_type() const {
      return table_->consumer_type()[row_number_];
    }
    ColumnType::ordinal::type ordinal() const {
      return table_->ordinal()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const EnergyCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_consumer_id(
        ColumnType::consumer_id::non_optional_type v) {
      return mutable_table()->mutable_consumer_id()->Set(row_number_, v);
    }
    void set_consumer_type(
        ColumnType::consumer_type::non_optional_type v) {
      return mutable_table()->mutable_consumer_type()->Set(row_number_, v);
    }
    void set_ordinal(
        ColumnType::ordinal::non_optional_type v) {
      return mutable_table()->mutable_ordinal()->Set(row_number_, v);
    }

   private:
    EnergyCounterTrackTable* mutable_table() const {
      return const_cast<EnergyCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, EnergyCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::consumer_id::type consumer_id() const {
      const auto& col = table_->consumer_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::consumer_type::type consumer_type() const {
      const auto& col = table_->consumer_type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::ordinal::type ordinal() const {
      const auto& col = table_->ordinal();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const EnergyCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class EnergyCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, EnergyCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_consumer_id(ColumnType::consumer_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_consumer_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_consumer_type(ColumnType::consumer_type::non_optional_type v) {
        auto* col = mutable_table_->mutable_consumer_type();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_ordinal(ColumnType::ordinal::non_optional_type v) {
        auto* col = mutable_table_->mutable_ordinal();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class EnergyCounterTrackTable;

    explicit Iterator(EnergyCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    EnergyCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit EnergyCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), consumer_id_(ColumnStorage<ColumnType::consumer_id::stored_type>::Create<false>()),
        consumer_type_(ColumnStorage<ColumnType::consumer_type::stored_type>::Create<false>()),
        ordinal_(ColumnStorage<ColumnType::ordinal::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::consumer_id::stored_type>(
          ColumnFlag::consumer_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::consumer_type::stored_type>(
          ColumnFlag::consumer_type),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ordinal::stored_type>(
          ColumnFlag::ordinal),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("consumer_id", &consumer_id_, ColumnFlag::consumer_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("consumer_type", &consumer_type_, ColumnFlag::consumer_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("ordinal", &ordinal_, ColumnFlag::ordinal,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~EnergyCounterTrackTable() override;

  static const char* Name() { return "energy_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "consumer_id", ColumnType::consumer_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "consumer_type", ColumnType::consumer_type::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "ordinal", ColumnType::ordinal::SqlValueType(), false,
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
    consumer_id_.ShrinkToFit();
    consumer_type_.ShrinkToFit();
    ordinal_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_consumer_id()->Append(std::move(row.consumer_id));
    mutable_consumer_type()->Append(std::move(row.consumer_type));
    mutable_ordinal()->Append(std::move(row.ordinal));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id
, ColumnStorage<ColumnType::consumer_type::stored_type> consumer_type
, ColumnStorage<ColumnType::ordinal::stored_type> ordinal) {
    return std::unique_ptr<Table>(new EnergyCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(consumer_id), std::move(consumer_type), std::move(ordinal)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id
, ColumnStorage<ColumnType::consumer_type::stored_type> consumer_type
, ColumnStorage<ColumnType::ordinal::stored_type> ordinal) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new EnergyCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(consumer_id), std::move(consumer_type), std::move(ordinal)));
  }

  const IdColumn<EnergyCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<EnergyCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<int32_t>& consumer_id() const {
    return static_cast<const ColumnType::consumer_id&>(columns_[ColumnIndex::consumer_id]);
  }
  const TypedColumn<StringPool::Id>& consumer_type() const {
    return static_cast<const ColumnType::consumer_type&>(columns_[ColumnIndex::consumer_type]);
  }
  const TypedColumn<int32_t>& ordinal() const {
    return static_cast<const ColumnType::ordinal&>(columns_[ColumnIndex::ordinal]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<EnergyCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<int32_t>* mutable_consumer_id() {
    return static_cast<ColumnType::consumer_id*>(
        &columns_[ColumnIndex::consumer_id]);
  }
  TypedColumn<StringPool::Id>* mutable_consumer_type() {
    return static_cast<ColumnType::consumer_type*>(
        &columns_[ColumnIndex::consumer_type]);
  }
  TypedColumn<int32_t>* mutable_ordinal() {
    return static_cast<ColumnType::ordinal*>(
        &columns_[ColumnIndex::ordinal]);
  }

 private:
  EnergyCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id
, ColumnStorage<ColumnType::consumer_type::stored_type> consumer_type
, ColumnStorage<ColumnType::ordinal::stored_type> ordinal)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::consumer_id::stored_type>(
          ColumnFlag::consumer_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::consumer_type::stored_type>(
          ColumnFlag::consumer_type),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ordinal::stored_type>(
          ColumnFlag::ordinal),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(consumer_id.size() == parent_overlay.size());
    consumer_id_ = std::move(consumer_id);
    PERFETTO_DCHECK(consumer_type.size() == parent_overlay.size());
    consumer_type_ = std::move(consumer_type);
    PERFETTO_DCHECK(ordinal.size() == parent_overlay.size());
    ordinal_ = std::move(ordinal);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("consumer_id", &consumer_id_, ColumnFlag::consumer_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("consumer_type", &consumer_type_, ColumnFlag::consumer_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("ordinal", &ordinal_, ColumnFlag::ordinal,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id_;
  ColumnStorage<ColumnType::consumer_type::stored_type> consumer_type_;
  ColumnStorage<ColumnType::ordinal::stored_type> ordinal_;
};
  

class UidCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t uid = 7;
  };
  struct ColumnType {
    using id = IdColumn<UidCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<UidCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using uid = TypedColumn<int32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<UidCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        int32_t in_uid = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          uid(std::move(in_uid)) {
      type_ = "uid_counter_track";
    }
    int32_t uid;

    bool operator==(const UidCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::uid::Equals(uid, other.uid);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t uid = ColumnType::uid::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      UidCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    UidCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const UidCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::uid::type uid() const {
      return table_->uid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const UidCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_uid(
        ColumnType::uid::non_optional_type v) {
      return mutable_table()->mutable_uid()->Set(row_number_, v);
    }

   private:
    UidCounterTrackTable* mutable_table() const {
      return const_cast<UidCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, UidCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::uid::type uid() const {
      const auto& col = table_->uid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const UidCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class UidCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, UidCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_uid(ColumnType::uid::non_optional_type v) {
        auto* col = mutable_table_->mutable_uid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class UidCounterTrackTable;

    explicit Iterator(UidCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    UidCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit UidCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), uid_(ColumnStorage<ColumnType::uid::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::uid::stored_type>(
          ColumnFlag::uid),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("uid", &uid_, ColumnFlag::uid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~UidCounterTrackTable() override;

  static const char* Name() { return "uid_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "uid", ColumnType::uid::SqlValueType(), false,
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
    uid_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_uid()->Append(std::move(row.uid));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::uid::stored_type> uid) {
    return std::unique_ptr<Table>(new UidCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(uid)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::uid::stored_type> uid) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new UidCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(uid)));
  }

  const IdColumn<UidCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<UidCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<int32_t>& uid() const {
    return static_cast<const ColumnType::uid&>(columns_[ColumnIndex::uid]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<UidCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<int32_t>* mutable_uid() {
    return static_cast<ColumnType::uid*>(
        &columns_[ColumnIndex::uid]);
  }

 private:
  UidCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::uid::stored_type> uid)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::uid::stored_type>(
          ColumnFlag::uid),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(uid.size() == parent_overlay.size());
    uid_ = std::move(uid);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("uid", &uid_, ColumnFlag::uid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::uid::stored_type> uid_;
};
  

class EnergyPerUidCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = UidCounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t uid = 7;
    static constexpr uint32_t consumer_id = 8;
  };
  struct ColumnType {
    using id = IdColumn<EnergyPerUidCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<EnergyPerUidCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using uid = TypedColumn<int32_t>;
    using consumer_id = TypedColumn<int32_t>;
  };
  struct Row : public UidCounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<EnergyPerUidCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        int32_t in_uid = {},
        int32_t in_consumer_id = {},
        std::nullptr_t = nullptr)
        : UidCounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description), std::move(in_uid)),
          consumer_id(std::move(in_consumer_id)) {
      type_ = "energy_per_uid_counter_track";
    }
    int32_t consumer_id;

    bool operator==(const EnergyPerUidCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::uid::Equals(uid, other.uid) &&
       ColumnType::consumer_id::Equals(consumer_id, other.consumer_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t consumer_id = ColumnType::consumer_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      EnergyPerUidCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    EnergyPerUidCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const EnergyPerUidCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::uid::type uid() const {
      return table_->uid()[row_number_];
    }
    ColumnType::consumer_id::type consumer_id() const {
      return table_->consumer_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const EnergyPerUidCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_uid(
        ColumnType::uid::non_optional_type v) {
      return mutable_table()->mutable_uid()->Set(row_number_, v);
    }
    void set_consumer_id(
        ColumnType::consumer_id::non_optional_type v) {
      return mutable_table()->mutable_consumer_id()->Set(row_number_, v);
    }

   private:
    EnergyPerUidCounterTrackTable* mutable_table() const {
      return const_cast<EnergyPerUidCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, EnergyPerUidCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::uid::type uid() const {
      const auto& col = table_->uid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::consumer_id::type consumer_id() const {
      const auto& col = table_->consumer_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const EnergyPerUidCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class EnergyPerUidCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, EnergyPerUidCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_uid(ColumnType::uid::non_optional_type v) {
        auto* col = mutable_table_->mutable_uid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_consumer_id(ColumnType::consumer_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_consumer_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class EnergyPerUidCounterTrackTable;

    explicit Iterator(EnergyPerUidCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    EnergyPerUidCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit EnergyPerUidCounterTrackTable(StringPool* pool, UidCounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), consumer_id_(ColumnStorage<ColumnType::consumer_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::consumer_id::stored_type>(
          ColumnFlag::consumer_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("consumer_id", &consumer_id_, ColumnFlag::consumer_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~EnergyPerUidCounterTrackTable() override;

  static const char* Name() { return "energy_per_uid_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "uid", ColumnType::uid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "consumer_id", ColumnType::consumer_id::SqlValueType(), false,
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
    consumer_id_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_consumer_id()->Append(std::move(row.consumer_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const UidCounterTrackTable& parent,
      ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id) {
    return std::unique_ptr<Table>(new EnergyPerUidCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(consumer_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const UidCounterTrackTable& parent,
      std::vector<UidCounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new EnergyPerUidCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(consumer_id)));
  }

  const IdColumn<EnergyPerUidCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<EnergyPerUidCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<int32_t>& uid() const {
    return static_cast<const ColumnType::uid&>(columns_[ColumnIndex::uid]);
  }
  const TypedColumn<int32_t>& consumer_id() const {
    return static_cast<const ColumnType::consumer_id&>(columns_[ColumnIndex::consumer_id]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<EnergyPerUidCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<int32_t>* mutable_uid() {
    return static_cast<ColumnType::uid*>(
        &columns_[ColumnIndex::uid]);
  }
  TypedColumn<int32_t>* mutable_consumer_id() {
    return static_cast<ColumnType::consumer_id*>(
        &columns_[ColumnIndex::consumer_id]);
  }

 private:
  EnergyPerUidCounterTrackTable(StringPool* pool,
            const UidCounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::consumer_id::stored_type>(
          ColumnFlag::consumer_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(consumer_id.size() == parent_overlay.size());
    consumer_id_ = std::move(consumer_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("consumer_id", &consumer_id_, ColumnFlag::consumer_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  UidCounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::consumer_id::stored_type> consumer_id_;
};
  

class GpuCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t gpu_id = 7;
  };
  struct ColumnType {
    using id = IdColumn<GpuCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<GpuCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using gpu_id = TypedColumn<uint32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<GpuCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        uint32_t in_gpu_id = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          gpu_id(std::move(in_gpu_id)) {
      type_ = "gpu_counter_track";
    }
    uint32_t gpu_id;

    bool operator==(const GpuCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::gpu_id::Equals(gpu_id, other.gpu_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t gpu_id = ColumnType::gpu_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      GpuCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    GpuCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const GpuCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::gpu_id::type gpu_id() const {
      return table_->gpu_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const GpuCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_gpu_id(
        ColumnType::gpu_id::non_optional_type v) {
      return mutable_table()->mutable_gpu_id()->Set(row_number_, v);
    }

   private:
    GpuCounterTrackTable* mutable_table() const {
      return const_cast<GpuCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, GpuCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::gpu_id::type gpu_id() const {
      const auto& col = table_->gpu_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const GpuCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class GpuCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, GpuCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_gpu_id(ColumnType::gpu_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_gpu_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class GpuCounterTrackTable;

    explicit Iterator(GpuCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    GpuCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit GpuCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), gpu_id_(ColumnStorage<ColumnType::gpu_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::gpu_id::stored_type>(
          ColumnFlag::gpu_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("gpu_id", &gpu_id_, ColumnFlag::gpu_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~GpuCounterTrackTable() override;

  static const char* Name() { return "gpu_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "gpu_id", ColumnType::gpu_id::SqlValueType(), false,
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
    gpu_id_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_gpu_id()->Append(std::move(row.gpu_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::gpu_id::stored_type> gpu_id) {
    return std::unique_ptr<Table>(new GpuCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(gpu_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::gpu_id::stored_type> gpu_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new GpuCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(gpu_id)));
  }

  const IdColumn<GpuCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<GpuCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<uint32_t>& gpu_id() const {
    return static_cast<const ColumnType::gpu_id&>(columns_[ColumnIndex::gpu_id]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<GpuCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<uint32_t>* mutable_gpu_id() {
    return static_cast<ColumnType::gpu_id*>(
        &columns_[ColumnIndex::gpu_id]);
  }

 private:
  GpuCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::gpu_id::stored_type> gpu_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::gpu_id::stored_type>(
          ColumnFlag::gpu_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(gpu_id.size() == parent_overlay.size());
    gpu_id_ = std::move(gpu_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("gpu_id", &gpu_id_, ColumnFlag::gpu_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::gpu_id::stored_type> gpu_id_;
};
  

class GpuTrackTable : public macros_internal::MacroTable {
 public:
  using Id = TrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t scope = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t context_id = 7;
  };
  struct ColumnType {
    using id = IdColumn<GpuTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<GpuTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using scope = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using context_id = TypedColumn<std::optional<int64_t>>;
  };
  struct Row : public TrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<GpuTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_scope = {},
        StringPool::Id in_description = {},
        std::optional<int64_t> in_context_id = {},
        std::nullptr_t = nullptr)
        : TrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id)),
          scope(std::move(in_scope)),
          description(std::move(in_description)),
          context_id(std::move(in_context_id)) {
      type_ = "gpu_track";
    }
    StringPool::Id scope;
    StringPool::Id description;
    std::optional<int64_t> context_id;

    bool operator==(const GpuTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::scope::Equals(scope, other.scope) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::context_id::Equals(context_id, other.context_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t scope = ColumnType::scope::default_flags();
    static constexpr uint32_t description = ColumnType::description::default_flags();
    static constexpr uint32_t context_id = ColumnType::context_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      GpuTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    GpuTrackTable, RowNumber> {
   public:
    ConstRowReference(const GpuTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::scope::type scope() const {
      return table_->scope()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::context_id::type context_id() const {
      return table_->context_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const GpuTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_scope(
        ColumnType::scope::non_optional_type v) {
      return mutable_table()->mutable_scope()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_context_id(
        ColumnType::context_id::non_optional_type v) {
      return mutable_table()->mutable_context_id()->Set(row_number_, v);
    }

   private:
    GpuTrackTable* mutable_table() const {
      return const_cast<GpuTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, GpuTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::scope::type scope() const {
      const auto& col = table_->scope();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::context_id::type context_id() const {
      const auto& col = table_->context_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const GpuTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class GpuTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, GpuTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_scope(ColumnType::scope::non_optional_type v) {
        auto* col = mutable_table_->mutable_scope();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_context_id(ColumnType::context_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_context_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class GpuTrackTable;

    explicit Iterator(GpuTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    GpuTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit GpuTrackTable(StringPool* pool, TrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), scope_(ColumnStorage<ColumnType::scope::stored_type>::Create<false>()),
        description_(ColumnStorage<ColumnType::description::stored_type>::Create<false>()),
        context_id_(ColumnStorage<ColumnType::context_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::scope::stored_type>(
          ColumnFlag::scope),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::description::stored_type>(
          ColumnFlag::description),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::context_id::stored_type>(
          ColumnFlag::context_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("scope", &scope_, ColumnFlag::scope,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("description", &description_, ColumnFlag::description,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("context_id", &context_id_, ColumnFlag::context_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~GpuTrackTable() override;

  static const char* Name() { return "gpu_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "scope", ColumnType::scope::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "context_id", ColumnType::context_id::SqlValueType(), false,
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
    scope_.ShrinkToFit();
    description_.ShrinkToFit();
    context_id_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_scope()->Append(std::move(row.scope));
    mutable_description()->Append(std::move(row.description));
    mutable_context_id()->Append(std::move(row.context_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const TrackTable& parent,
      ColumnStorage<ColumnType::scope::stored_type> scope
, ColumnStorage<ColumnType::description::stored_type> description
, ColumnStorage<ColumnType::context_id::stored_type> context_id) {
    return std::unique_ptr<Table>(new GpuTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(scope), std::move(description), std::move(context_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const TrackTable& parent,
      std::vector<TrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::scope::stored_type> scope
, ColumnStorage<ColumnType::description::stored_type> description
, ColumnStorage<ColumnType::context_id::stored_type> context_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new GpuTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(scope), std::move(description), std::move(context_id)));
  }

  const IdColumn<GpuTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<GpuTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& scope() const {
    return static_cast<const ColumnType::scope&>(columns_[ColumnIndex::scope]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<std::optional<int64_t>>& context_id() const {
    return static_cast<const ColumnType::context_id&>(columns_[ColumnIndex::context_id]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<GpuTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_scope() {
    return static_cast<ColumnType::scope*>(
        &columns_[ColumnIndex::scope]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_context_id() {
    return static_cast<ColumnType::context_id*>(
        &columns_[ColumnIndex::context_id]);
  }

 private:
  GpuTrackTable(StringPool* pool,
            const TrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::scope::stored_type> scope
, ColumnStorage<ColumnType::description::stored_type> description
, ColumnStorage<ColumnType::context_id::stored_type> context_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::scope::stored_type>(
          ColumnFlag::scope),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::description::stored_type>(
          ColumnFlag::description),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::context_id::stored_type>(
          ColumnFlag::context_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(scope.size() == parent_overlay.size());
    scope_ = std::move(scope);
    PERFETTO_DCHECK(description.size() == parent_overlay.size());
    description_ = std::move(description);
    PERFETTO_DCHECK(context_id.size() == parent_overlay.size());
    context_id_ = std::move(context_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("scope", &scope_, ColumnFlag::scope,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("description", &description_, ColumnFlag::description,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("context_id", &context_id_, ColumnFlag::context_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  TrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::scope::stored_type> scope_;
  ColumnStorage<ColumnType::description::stored_type> description_;
  ColumnStorage<ColumnType::context_id::stored_type> context_id_;
};
  

class IrqCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t irq = 7;
  };
  struct ColumnType {
    using id = IdColumn<IrqCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<IrqCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using irq = TypedColumn<int32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<IrqCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        int32_t in_irq = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          irq(std::move(in_irq)) {
      type_ = "irq_counter_track";
    }
    int32_t irq;

    bool operator==(const IrqCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::irq::Equals(irq, other.irq);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t irq = ColumnType::irq::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      IrqCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    IrqCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const IrqCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::irq::type irq() const {
      return table_->irq()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const IrqCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_irq(
        ColumnType::irq::non_optional_type v) {
      return mutable_table()->mutable_irq()->Set(row_number_, v);
    }

   private:
    IrqCounterTrackTable* mutable_table() const {
      return const_cast<IrqCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, IrqCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::irq::type irq() const {
      const auto& col = table_->irq();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const IrqCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class IrqCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, IrqCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_irq(ColumnType::irq::non_optional_type v) {
        auto* col = mutable_table_->mutable_irq();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class IrqCounterTrackTable;

    explicit Iterator(IrqCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    IrqCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit IrqCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), irq_(ColumnStorage<ColumnType::irq::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::irq::stored_type>(
          ColumnFlag::irq),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("irq", &irq_, ColumnFlag::irq,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~IrqCounterTrackTable() override;

  static const char* Name() { return "irq_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "irq", ColumnType::irq::SqlValueType(), false,
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
    irq_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_irq()->Append(std::move(row.irq));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::irq::stored_type> irq) {
    return std::unique_ptr<Table>(new IrqCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(irq)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::irq::stored_type> irq) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new IrqCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(irq)));
  }

  const IdColumn<IrqCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<IrqCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<int32_t>& irq() const {
    return static_cast<const ColumnType::irq&>(columns_[ColumnIndex::irq]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<IrqCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<int32_t>* mutable_irq() {
    return static_cast<ColumnType::irq*>(
        &columns_[ColumnIndex::irq]);
  }

 private:
  IrqCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::irq::stored_type> irq)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::irq::stored_type>(
          ColumnFlag::irq),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(irq.size() == parent_overlay.size());
    irq_ = std::move(irq);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("irq", &irq_, ColumnFlag::irq,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::irq::stored_type> irq_;
};
  

class PerfCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t perf_session_id = 7;
    static constexpr uint32_t cpu = 8;
    static constexpr uint32_t is_timebase = 9;
  };
  struct ColumnType {
    using id = IdColumn<PerfCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<PerfCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using perf_session_id = TypedColumn<uint32_t>;
    using cpu = TypedColumn<uint32_t>;
    using is_timebase = TypedColumn<uint32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<PerfCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        uint32_t in_perf_session_id = {},
        uint32_t in_cpu = {},
        uint32_t in_is_timebase = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          perf_session_id(std::move(in_perf_session_id)),
          cpu(std::move(in_cpu)),
          is_timebase(std::move(in_is_timebase)) {
      type_ = "perf_counter_track";
    }
    uint32_t perf_session_id;
    uint32_t cpu;
    uint32_t is_timebase;

    bool operator==(const PerfCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::perf_session_id::Equals(perf_session_id, other.perf_session_id) &&
       ColumnType::cpu::Equals(cpu, other.cpu) &&
       ColumnType::is_timebase::Equals(is_timebase, other.is_timebase);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t perf_session_id = ColumnType::perf_session_id::default_flags();
    static constexpr uint32_t cpu = ColumnType::cpu::default_flags();
    static constexpr uint32_t is_timebase = ColumnType::is_timebase::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      PerfCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    PerfCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const PerfCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::perf_session_id::type perf_session_id() const {
      return table_->perf_session_id()[row_number_];
    }
    ColumnType::cpu::type cpu() const {
      return table_->cpu()[row_number_];
    }
    ColumnType::is_timebase::type is_timebase() const {
      return table_->is_timebase()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const PerfCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_perf_session_id(
        ColumnType::perf_session_id::non_optional_type v) {
      return mutable_table()->mutable_perf_session_id()->Set(row_number_, v);
    }
    void set_cpu(
        ColumnType::cpu::non_optional_type v) {
      return mutable_table()->mutable_cpu()->Set(row_number_, v);
    }
    void set_is_timebase(
        ColumnType::is_timebase::non_optional_type v) {
      return mutable_table()->mutable_is_timebase()->Set(row_number_, v);
    }

   private:
    PerfCounterTrackTable* mutable_table() const {
      return const_cast<PerfCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, PerfCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::perf_session_id::type perf_session_id() const {
      const auto& col = table_->perf_session_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cpu::type cpu() const {
      const auto& col = table_->cpu();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::is_timebase::type is_timebase() const {
      const auto& col = table_->is_timebase();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const PerfCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class PerfCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, PerfCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_perf_session_id(ColumnType::perf_session_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_perf_session_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cpu(ColumnType::cpu::non_optional_type v) {
        auto* col = mutable_table_->mutable_cpu();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_is_timebase(ColumnType::is_timebase::non_optional_type v) {
        auto* col = mutable_table_->mutable_is_timebase();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class PerfCounterTrackTable;

    explicit Iterator(PerfCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    PerfCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit PerfCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), perf_session_id_(ColumnStorage<ColumnType::perf_session_id::stored_type>::Create<false>()),
        cpu_(ColumnStorage<ColumnType::cpu::stored_type>::Create<false>()),
        is_timebase_(ColumnStorage<ColumnType::is_timebase::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::perf_session_id::stored_type>(
          ColumnFlag::perf_session_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::is_timebase::stored_type>(
          ColumnFlag::is_timebase),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("perf_session_id", &perf_session_id_, ColumnFlag::perf_session_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("is_timebase", &is_timebase_, ColumnFlag::is_timebase,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~PerfCounterTrackTable() override;

  static const char* Name() { return "perf_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "perf_session_id", ColumnType::perf_session_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cpu", ColumnType::cpu::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "is_timebase", ColumnType::is_timebase::SqlValueType(), false,
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
    perf_session_id_.ShrinkToFit();
    cpu_.ShrinkToFit();
    is_timebase_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_perf_session_id()->Append(std::move(row.perf_session_id));
    mutable_cpu()->Append(std::move(row.cpu));
    mutable_is_timebase()->Append(std::move(row.is_timebase));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::perf_session_id::stored_type> perf_session_id
, ColumnStorage<ColumnType::cpu::stored_type> cpu
, ColumnStorage<ColumnType::is_timebase::stored_type> is_timebase) {
    return std::unique_ptr<Table>(new PerfCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(perf_session_id), std::move(cpu), std::move(is_timebase)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::perf_session_id::stored_type> perf_session_id
, ColumnStorage<ColumnType::cpu::stored_type> cpu
, ColumnStorage<ColumnType::is_timebase::stored_type> is_timebase) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new PerfCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(perf_session_id), std::move(cpu), std::move(is_timebase)));
  }

  const IdColumn<PerfCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<PerfCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<uint32_t>& perf_session_id() const {
    return static_cast<const ColumnType::perf_session_id&>(columns_[ColumnIndex::perf_session_id]);
  }
  const TypedColumn<uint32_t>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }
  const TypedColumn<uint32_t>& is_timebase() const {
    return static_cast<const ColumnType::is_timebase&>(columns_[ColumnIndex::is_timebase]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<PerfCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<uint32_t>* mutable_perf_session_id() {
    return static_cast<ColumnType::perf_session_id*>(
        &columns_[ColumnIndex::perf_session_id]);
  }
  TypedColumn<uint32_t>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }
  TypedColumn<uint32_t>* mutable_is_timebase() {
    return static_cast<ColumnType::is_timebase*>(
        &columns_[ColumnIndex::is_timebase]);
  }

 private:
  PerfCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::perf_session_id::stored_type> perf_session_id
, ColumnStorage<ColumnType::cpu::stored_type> cpu
, ColumnStorage<ColumnType::is_timebase::stored_type> is_timebase)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::perf_session_id::stored_type>(
          ColumnFlag::perf_session_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::is_timebase::stored_type>(
          ColumnFlag::is_timebase),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(perf_session_id.size() == parent_overlay.size());
    perf_session_id_ = std::move(perf_session_id);
    PERFETTO_DCHECK(cpu.size() == parent_overlay.size());
    cpu_ = std::move(cpu);
    PERFETTO_DCHECK(is_timebase.size() == parent_overlay.size());
    is_timebase_ = std::move(is_timebase);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("perf_session_id", &perf_session_id_, ColumnFlag::perf_session_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("is_timebase", &is_timebase_, ColumnFlag::is_timebase,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::perf_session_id::stored_type> perf_session_id_;
  ColumnStorage<ColumnType::cpu::stored_type> cpu_;
  ColumnStorage<ColumnType::is_timebase::stored_type> is_timebase_;
};
  

class ProcessCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t upid = 7;
  };
  struct ColumnType {
    using id = IdColumn<ProcessCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<ProcessCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using upid = TypedColumn<uint32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<ProcessCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        uint32_t in_upid = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          upid(std::move(in_upid)) {
      type_ = "process_counter_track";
    }
    uint32_t upid;

    bool operator==(const ProcessCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::upid::Equals(upid, other.upid);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ProcessCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ProcessCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const ProcessCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ProcessCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }

   private:
    ProcessCounterTrackTable* mutable_table() const {
      return const_cast<ProcessCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ProcessCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ProcessCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ProcessCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ProcessCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ProcessCounterTrackTable;

    explicit Iterator(ProcessCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ProcessCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ProcessCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ProcessCounterTrackTable() override;

  static const char* Name() { return "process_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid", ColumnType::upid::SqlValueType(), false,
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
    upid_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_upid()->Append(std::move(row.upid));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::upid::stored_type> upid) {
    return std::unique_ptr<Table>(new ProcessCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(upid)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::upid::stored_type> upid) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ProcessCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(upid)));
  }

  const IdColumn<ProcessCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<ProcessCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<ProcessCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }

 private:
  ProcessCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::upid::stored_type> upid)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(upid.size() == parent_overlay.size());
    upid_ = std::move(upid);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
};
  

class ProcessTrackTable : public macros_internal::MacroTable {
 public:
  using Id = TrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t upid = 5;
  };
  struct ColumnType {
    using id = IdColumn<ProcessTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<ProcessTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using upid = TypedColumn<uint32_t>;
  };
  struct Row : public TrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<ProcessTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        uint32_t in_upid = {},
        std::nullptr_t = nullptr)
        : TrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id)),
          upid(std::move(in_upid)) {
      type_ = "process_track";
    }
    uint32_t upid;

    bool operator==(const ProcessTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::upid::Equals(upid, other.upid);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ProcessTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ProcessTrackTable, RowNumber> {
   public:
    ConstRowReference(const ProcessTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ProcessTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }

   private:
    ProcessTrackTable* mutable_table() const {
      return const_cast<ProcessTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ProcessTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ProcessTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ProcessTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ProcessTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ProcessTrackTable;

    explicit Iterator(ProcessTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ProcessTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ProcessTrackTable(StringPool* pool, TrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ProcessTrackTable() override;

  static const char* Name() { return "process_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid", ColumnType::upid::SqlValueType(), false,
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
    upid_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_upid()->Append(std::move(row.upid));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const TrackTable& parent,
      ColumnStorage<ColumnType::upid::stored_type> upid) {
    return std::unique_ptr<Table>(new ProcessTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(upid)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const TrackTable& parent,
      std::vector<TrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::upid::stored_type> upid) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ProcessTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(upid)));
  }

  const IdColumn<ProcessTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<ProcessTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<ProcessTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }

 private:
  ProcessTrackTable(StringPool* pool,
            const TrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::upid::stored_type> upid)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(upid.size() == parent_overlay.size());
    upid_ = std::move(upid);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  TrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
};
  

class SoftirqCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t softirq = 7;
  };
  struct ColumnType {
    using id = IdColumn<SoftirqCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<SoftirqCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using softirq = TypedColumn<int32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<SoftirqCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        int32_t in_softirq = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          softirq(std::move(in_softirq)) {
      type_ = "softirq_counter_track";
    }
    int32_t softirq;

    bool operator==(const SoftirqCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::softirq::Equals(softirq, other.softirq);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t softirq = ColumnType::softirq::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      SoftirqCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    SoftirqCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const SoftirqCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::softirq::type softirq() const {
      return table_->softirq()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const SoftirqCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_softirq(
        ColumnType::softirq::non_optional_type v) {
      return mutable_table()->mutable_softirq()->Set(row_number_, v);
    }

   private:
    SoftirqCounterTrackTable* mutable_table() const {
      return const_cast<SoftirqCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, SoftirqCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::softirq::type softirq() const {
      const auto& col = table_->softirq();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const SoftirqCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class SoftirqCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, SoftirqCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_softirq(ColumnType::softirq::non_optional_type v) {
        auto* col = mutable_table_->mutable_softirq();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class SoftirqCounterTrackTable;

    explicit Iterator(SoftirqCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    SoftirqCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit SoftirqCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), softirq_(ColumnStorage<ColumnType::softirq::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::softirq::stored_type>(
          ColumnFlag::softirq),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("softirq", &softirq_, ColumnFlag::softirq,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~SoftirqCounterTrackTable() override;

  static const char* Name() { return "softirq_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "softirq", ColumnType::softirq::SqlValueType(), false,
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
    softirq_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_softirq()->Append(std::move(row.softirq));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::softirq::stored_type> softirq) {
    return std::unique_ptr<Table>(new SoftirqCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(softirq)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::softirq::stored_type> softirq) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new SoftirqCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(softirq)));
  }

  const IdColumn<SoftirqCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<SoftirqCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<int32_t>& softirq() const {
    return static_cast<const ColumnType::softirq&>(columns_[ColumnIndex::softirq]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<SoftirqCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<int32_t>* mutable_softirq() {
    return static_cast<ColumnType::softirq*>(
        &columns_[ColumnIndex::softirq]);
  }

 private:
  SoftirqCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::softirq::stored_type> softirq)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::softirq::stored_type>(
          ColumnFlag::softirq),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(softirq.size() == parent_overlay.size());
    softirq_ = std::move(softirq);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("softirq", &softirq_, ColumnFlag::softirq,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::softirq::stored_type> softirq_;
};
  

class ThreadCounterTrackTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t unit = 5;
    static constexpr uint32_t description = 6;
    static constexpr uint32_t utid = 7;
  };
  struct ColumnType {
    using id = IdColumn<ThreadCounterTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<ThreadCounterTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using unit = TypedColumn<StringPool::Id>;
    using description = TypedColumn<StringPool::Id>;
    using utid = TypedColumn<uint32_t>;
  };
  struct Row : public CounterTrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<ThreadCounterTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        StringPool::Id in_unit = {},
        StringPool::Id in_description = {},
        uint32_t in_utid = {},
        std::nullptr_t = nullptr)
        : CounterTrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id), std::move(in_unit), std::move(in_description)),
          utid(std::move(in_utid)) {
      type_ = "thread_counter_track";
    }
    uint32_t utid;

    bool operator==(const ThreadCounterTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::unit::Equals(unit, other.unit) &&
       ColumnType::description::Equals(description, other.description) &&
       ColumnType::utid::Equals(utid, other.utid);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ThreadCounterTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ThreadCounterTrackTable, RowNumber> {
   public:
    ConstRowReference(const ThreadCounterTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::unit::type unit() const {
      return table_->unit()[row_number_];
    }
    ColumnType::description::type description() const {
      return table_->description()[row_number_];
    }
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ThreadCounterTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_unit(
        ColumnType::unit::non_optional_type v) {
      return mutable_table()->mutable_unit()->Set(row_number_, v);
    }
    void set_description(
        ColumnType::description::non_optional_type v) {
      return mutable_table()->mutable_description()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }

   private:
    ThreadCounterTrackTable* mutable_table() const {
      return const_cast<ThreadCounterTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ThreadCounterTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unit::type unit() const {
      const auto& col = table_->unit();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::description::type description() const {
      const auto& col = table_->description();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::utid::type utid() const {
      const auto& col = table_->utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ThreadCounterTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ThreadCounterTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ThreadCounterTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unit(ColumnType::unit::non_optional_type v) {
        auto* col = mutable_table_->mutable_unit();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_description(ColumnType::description::non_optional_type v) {
        auto* col = mutable_table_->mutable_description();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_utid(ColumnType::utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ThreadCounterTrackTable;

    explicit Iterator(ThreadCounterTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ThreadCounterTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ThreadCounterTrackTable(StringPool* pool, CounterTrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ThreadCounterTrackTable() override;

  static const char* Name() { return "thread_counter_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unit", ColumnType::unit::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "description", ColumnType::description::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "utid", ColumnType::utid::SqlValueType(), false,
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
    utid_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_utid()->Append(std::move(row.utid));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTrackTable& parent,
      ColumnStorage<ColumnType::utid::stored_type> utid) {
    return std::unique_ptr<Table>(new ThreadCounterTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(utid)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTrackTable& parent,
      std::vector<CounterTrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::utid::stored_type> utid) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ThreadCounterTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(utid)));
  }

  const IdColumn<ThreadCounterTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<ThreadCounterTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& unit() const {
    return static_cast<const ColumnType::unit&>(columns_[ColumnIndex::unit]);
  }
  const TypedColumn<StringPool::Id>& description() const {
    return static_cast<const ColumnType::description&>(columns_[ColumnIndex::description]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<ThreadCounterTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_unit() {
    return static_cast<ColumnType::unit*>(
        &columns_[ColumnIndex::unit]);
  }
  TypedColumn<StringPool::Id>* mutable_description() {
    return static_cast<ColumnType::description*>(
        &columns_[ColumnIndex::description]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }

 private:
  ThreadCounterTrackTable(StringPool* pool,
            const CounterTrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::utid::stored_type> utid)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(utid.size() == parent_overlay.size());
    utid_ = std::move(utid);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
};
  

class ThreadTrackTable : public macros_internal::MacroTable {
 public:
  using Id = TrackTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t name = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t source_arg_set_id = 4;
    static constexpr uint32_t utid = 5;
  };
  struct ColumnType {
    using id = IdColumn<ThreadTrackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using parent_id = TypedColumn<std::optional<ThreadTrackTable::Id>>;
    using source_arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using utid = TypedColumn<uint32_t>;
  };
  struct Row : public TrackTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<ThreadTrackTable::Id> in_parent_id = {},
        std::optional<uint32_t> in_source_arg_set_id = {},
        uint32_t in_utid = {},
        std::nullptr_t = nullptr)
        : TrackTable::Row(std::move(in_name), std::move(in_parent_id), std::move(in_source_arg_set_id)),
          utid(std::move(in_utid)) {
      type_ = "thread_track";
    }
    uint32_t utid;

    bool operator==(const ThreadTrackTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_arg_set_id::Equals(source_arg_set_id, other.source_arg_set_id) &&
       ColumnType::utid::Equals(utid, other.utid);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ThreadTrackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ThreadTrackTable, RowNumber> {
   public:
    ConstRowReference(const ThreadTrackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      return table_->source_arg_set_id()[row_number_];
    }
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ThreadTrackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_arg_set_id(
        ColumnType::source_arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_source_arg_set_id()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }

   private:
    ThreadTrackTable* mutable_table() const {
      return const_cast<ThreadTrackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ThreadTrackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_arg_set_id::type source_arg_set_id() const {
      const auto& col = table_->source_arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::utid::type utid() const {
      const auto& col = table_->utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ThreadTrackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ThreadTrackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ThreadTrackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_arg_set_id(ColumnType::source_arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_utid(ColumnType::utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ThreadTrackTable;

    explicit Iterator(ThreadTrackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ThreadTrackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ThreadTrackTable(StringPool* pool, TrackTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ThreadTrackTable() override;

  static const char* Name() { return "thread_track"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_arg_set_id", ColumnType::source_arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "utid", ColumnType::utid::SqlValueType(), false,
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
    utid_.ShrinkToFit();
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
    Id id = Id{parent_->Insert(row).id};
    UpdateOverlaysAfterParentInsert();
    mutable_utid()->Append(std::move(row.utid));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const TrackTable& parent,
      ColumnStorage<ColumnType::utid::stored_type> utid) {
    return std::unique_ptr<Table>(new ThreadTrackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(utid)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const TrackTable& parent,
      std::vector<TrackTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::utid::stored_type> utid) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ThreadTrackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(utid)));
  }

  const IdColumn<ThreadTrackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<ThreadTrackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& source_arg_set_id() const {
    return static_cast<const ColumnType::source_arg_set_id&>(columns_[ColumnIndex::source_arg_set_id]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<ThreadTrackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_source_arg_set_id() {
    return static_cast<ColumnType::source_arg_set_id*>(
        &columns_[ColumnIndex::source_arg_set_id]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }

 private:
  ThreadTrackTable(StringPool* pool,
            const TrackTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::utid::stored_type> utid)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(utid.size() == parent_overlay.size());
    utid_ = std::move(utid);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  TrackTable* parent_ = nullptr;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_TRACK_TABLES_PY_H_

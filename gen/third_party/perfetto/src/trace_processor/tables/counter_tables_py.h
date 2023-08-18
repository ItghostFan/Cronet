#ifndef SRC_TRACE_PROCESSOR_TABLES_COUNTER_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_COUNTER_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"

#include "src/trace_processor/tables/track_tables_py.h"

namespace perfetto {
namespace trace_processor {
namespace tables {

class CounterTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t track_id = 3;
    static constexpr uint32_t value = 4;
    static constexpr uint32_t arg_set_id = 5;
  };
  struct ColumnType {
    using id = IdColumn<CounterTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using track_id = TypedColumn<CounterTrackTable::Id>;
    using value = TypedColumn<double>;
    using arg_set_id = TypedColumn<std::optional<uint32_t>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        CounterTrackTable::Id in_track_id = {},
        double in_value = {},
        std::optional<uint32_t> in_arg_set_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          track_id(std::move(in_track_id)),
          value(std::move(in_value)),
          arg_set_id(std::move(in_arg_set_id)) {
      type_ = "counter";
    }
    int64_t ts;
    CounterTrackTable::Id track_id;
    double value;
    std::optional<uint32_t> arg_set_id;

    bool operator==(const CounterTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::value::Equals(value, other.value) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::ts::default_flags();
    static constexpr uint32_t track_id = ColumnType::track_id::default_flags();
    static constexpr uint32_t value = ColumnType::value::default_flags();
    static constexpr uint32_t arg_set_id = ColumnType::arg_set_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      CounterTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    CounterTable, RowNumber> {
   public:
    ConstRowReference(const CounterTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::ts::type ts() const {
      return table_->ts()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
    ColumnType::value::type value() const {
      return table_->value()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const CounterTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }
    void set_value(
        ColumnType::value::non_optional_type v) {
      return mutable_table()->mutable_value()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }

   private:
    CounterTable* mutable_table() const {
      return const_cast<CounterTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, CounterTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::ts::type ts() const {
      const auto& col = table_->ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::value::type value() const {
      const auto& col = table_->value();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const CounterTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class CounterTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, CounterTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_value(ColumnType::value::non_optional_type v) {
        auto* col = mutable_table_->mutable_value();
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
    friend class CounterTable;

    explicit Iterator(CounterTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    CounterTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit CounterTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        track_id_(ColumnStorage<ColumnType::track_id::stored_type>::Create<false>()),
        value_(ColumnStorage<ColumnType::value::stored_type>::Create<false>()),
        arg_set_id_(ColumnStorage<ColumnType::arg_set_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::track_id::stored_type>(
          ColumnFlag::track_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::value::stored_type>(
          ColumnFlag::value),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::arg_set_id::stored_type>(
          ColumnFlag::arg_set_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("track_id", &track_id_, ColumnFlag::track_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("value", &value_, ColumnFlag::value,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("arg_set_id", &arg_set_id_, ColumnFlag::arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~CounterTable() override;

  static const char* Name() { return "counter"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "ts", ColumnType::ts::SqlValueType(), false,
        true,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "value", ColumnType::value::SqlValueType(), false,
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
    ts_.ShrinkToFit();
    track_id_.ShrinkToFit();
    value_.ShrinkToFit();
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
    mutable_ts()->Append(std::move(row.ts));
    mutable_track_id()->Append(std::move(row.track_id));
    mutable_value()->Append(std::move(row.value));
    mutable_arg_set_id()->Append(std::move(row.arg_set_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<CounterTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<CounterTrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }
  const TypedColumn<double>& value() const {
    return static_cast<const ColumnType::value&>(columns_[ColumnIndex::value]);
  }
  const TypedColumn<std::optional<uint32_t>>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<CounterTrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }
  TypedColumn<double>* mutable_value() {
    return static_cast<ColumnType::value*>(
        &columns_[ColumnIndex::value]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::track_id::stored_type> track_id_;
  ColumnStorage<ColumnType::value::stored_type> value_;
  ColumnStorage<ColumnType::arg_set_id::stored_type> arg_set_id_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_COUNTER_TABLES_PY_H_

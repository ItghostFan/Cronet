#ifndef SRC_TRACE_PROCESSOR_PERFETTO_SQL_INTRINSICS_TABLE_FUNCTIONS_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_PERFETTO_SQL_INTRINSICS_TABLE_FUNCTIONS_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"

#include "src/trace_processor/tables/counter_tables_py.h"
#include "src/trace_processor/tables/flow_tables_py.h"
#include "src/trace_processor/tables/metadata_tables_py.h"
#include "src/trace_processor/tables/profiler_tables_py.h"
#include "src/trace_processor/tables/sched_tables_py.h"
#include "src/trace_processor/tables/slice_tables_py.h"

namespace perfetto {
namespace trace_processor {
namespace tables {

class AncestorSliceByStackTable : public macros_internal::MacroTable {
 public:
  using Id = SliceTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t track_id = 4;
    static constexpr uint32_t category = 5;
    static constexpr uint32_t name = 6;
    static constexpr uint32_t depth = 7;
    static constexpr uint32_t stack_id = 8;
    static constexpr uint32_t parent_stack_id = 9;
    static constexpr uint32_t parent_id = 10;
    static constexpr uint32_t arg_set_id = 11;
    static constexpr uint32_t thread_ts = 12;
    static constexpr uint32_t thread_dur = 13;
    static constexpr uint32_t thread_instruction_count = 14;
    static constexpr uint32_t thread_instruction_delta = 15;
    static constexpr uint32_t start_stack_id = 16;
  };
  struct ColumnType {
    using id = IdColumn<AncestorSliceByStackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using track_id = TypedColumn<TrackTable::Id>;
    using category = TypedColumn<std::optional<StringPool::Id>>;
    using name = TypedColumn<std::optional<StringPool::Id>>;
    using depth = TypedColumn<uint32_t>;
    using stack_id = TypedColumn<int64_t>;
    using parent_stack_id = TypedColumn<int64_t>;
    using parent_id = TypedColumn<std::optional<AncestorSliceByStackTable::Id>>;
    using arg_set_id = TypedColumn<uint32_t>;
    using thread_ts = TypedColumn<std::optional<int64_t>>;
    using thread_dur = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_count = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_delta = TypedColumn<std::optional<int64_t>>;
    using start_stack_id = TypedColumn<int64_t>;
  };
  struct Row : public SliceTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        TrackTable::Id in_track_id = {},
        std::optional<StringPool::Id> in_category = {},
        std::optional<StringPool::Id> in_name = {},
        uint32_t in_depth = {},
        int64_t in_stack_id = {},
        int64_t in_parent_stack_id = {},
        std::optional<AncestorSliceByStackTable::Id> in_parent_id = {},
        uint32_t in_arg_set_id = {},
        std::optional<int64_t> in_thread_ts = {},
        std::optional<int64_t> in_thread_dur = {},
        std::optional<int64_t> in_thread_instruction_count = {},
        std::optional<int64_t> in_thread_instruction_delta = {},
        int64_t in_start_stack_id = {},
        std::nullptr_t = nullptr)
        : SliceTable::Row(std::move(in_ts), std::move(in_dur), std::move(in_track_id), std::move(in_category), std::move(in_name), std::move(in_depth), std::move(in_stack_id), std::move(in_parent_stack_id), std::move(in_parent_id), std::move(in_arg_set_id), std::move(in_thread_ts), std::move(in_thread_dur), std::move(in_thread_instruction_count), std::move(in_thread_instruction_delta)),
          start_stack_id(std::move(in_start_stack_id)) {
      type_ = "ancestor_slice_by_stack";
    }
    int64_t start_stack_id;

    bool operator==(const AncestorSliceByStackTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::category::Equals(category, other.category) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::stack_id::Equals(stack_id, other.stack_id) &&
       ColumnType::parent_stack_id::Equals(parent_stack_id, other.parent_stack_id) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::thread_ts::Equals(thread_ts, other.thread_ts) &&
       ColumnType::thread_dur::Equals(thread_dur, other.thread_dur) &&
       ColumnType::thread_instruction_count::Equals(thread_instruction_count, other.thread_instruction_count) &&
       ColumnType::thread_instruction_delta::Equals(thread_instruction_delta, other.thread_instruction_delta) &&
       ColumnType::start_stack_id::Equals(start_stack_id, other.start_stack_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t start_stack_id = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::start_stack_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      AncestorSliceByStackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    AncestorSliceByStackTable, RowNumber> {
   public:
    ConstRowReference(const AncestorSliceByStackTable* table, uint32_t row_number)
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
    ColumnType::dur::type dur() const {
      return table_->dur()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
    ColumnType::category::type category() const {
      return table_->category()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::stack_id::type stack_id() const {
      return table_->stack_id()[row_number_];
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      return table_->parent_stack_id()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::thread_ts::type thread_ts() const {
      return table_->thread_ts()[row_number_];
    }
    ColumnType::thread_dur::type thread_dur() const {
      return table_->thread_dur()[row_number_];
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      return table_->thread_instruction_count()[row_number_];
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      return table_->thread_instruction_delta()[row_number_];
    }
    ColumnType::start_stack_id::type start_stack_id() const {
      return table_->start_stack_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const AncestorSliceByStackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_dur(
        ColumnType::dur::non_optional_type v) {
      return mutable_table()->mutable_dur()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }
    void set_category(
        ColumnType::category::non_optional_type v) {
      return mutable_table()->mutable_category()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_stack_id(
        ColumnType::stack_id::non_optional_type v) {
      return mutable_table()->mutable_stack_id()->Set(row_number_, v);
    }
    void set_parent_stack_id(
        ColumnType::parent_stack_id::non_optional_type v) {
      return mutable_table()->mutable_parent_stack_id()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_thread_ts(
        ColumnType::thread_ts::non_optional_type v) {
      return mutable_table()->mutable_thread_ts()->Set(row_number_, v);
    }
    void set_thread_dur(
        ColumnType::thread_dur::non_optional_type v) {
      return mutable_table()->mutable_thread_dur()->Set(row_number_, v);
    }
    void set_thread_instruction_count(
        ColumnType::thread_instruction_count::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_count()->Set(row_number_, v);
    }
    void set_thread_instruction_delta(
        ColumnType::thread_instruction_delta::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_delta()->Set(row_number_, v);
    }
    void set_start_stack_id(
        ColumnType::start_stack_id::non_optional_type v) {
      return mutable_table()->mutable_start_stack_id()->Set(row_number_, v);
    }

   private:
    AncestorSliceByStackTable* mutable_table() const {
      return const_cast<AncestorSliceByStackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, AncestorSliceByStackTable, RowNumber, ConstRowReference> {
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
    ColumnType::dur::type dur() const {
      const auto& col = table_->dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::category::type category() const {
      const auto& col = table_->category();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::stack_id::type stack_id() const {
      const auto& col = table_->stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      const auto& col = table_->parent_stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_ts::type thread_ts() const {
      const auto& col = table_->thread_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_dur::type thread_dur() const {
      const auto& col = table_->thread_dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      const auto& col = table_->thread_instruction_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      const auto& col = table_->thread_instruction_delta();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_stack_id::type start_stack_id() const {
      const auto& col = table_->start_stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const AncestorSliceByStackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class AncestorSliceByStackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, AncestorSliceByStackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_dur(ColumnType::dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_category(ColumnType::category::non_optional_type v) {
        auto* col = mutable_table_->mutable_category();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_stack_id(ColumnType::stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_stack_id(ColumnType::parent_stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_ts(ColumnType::thread_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_dur(ColumnType::thread_dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_count(ColumnType::thread_instruction_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_delta(ColumnType::thread_instruction_delta::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_delta();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_stack_id(ColumnType::start_stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class AncestorSliceByStackTable;

    explicit Iterator(AncestorSliceByStackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    AncestorSliceByStackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit AncestorSliceByStackTable(StringPool* pool, SliceTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), start_stack_id_(ColumnStorage<ColumnType::start_stack_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_stack_id::stored_type>(
          ColumnFlag::start_stack_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_stack_id", &start_stack_id_, ColumnFlag::start_stack_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~AncestorSliceByStackTable() override;

  static const char* Name() { return "ancestor_slice_by_stack"; }

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
        "dur", ColumnType::dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "category", ColumnType::category::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "stack_id", ColumnType::stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_stack_id", ColumnType::parent_stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_ts", ColumnType::thread_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_dur", ColumnType::thread_dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_count", ColumnType::thread_instruction_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_delta", ColumnType::thread_instruction_delta::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_stack_id", ColumnType::start_stack_id::SqlValueType(), false,
        false,
        true,
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
    start_stack_id_.ShrinkToFit();
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
    mutable_start_stack_id()->Append(std::move(row.start_stack_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const SliceTable& parent,
      ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id) {
    return std::unique_ptr<Table>(new AncestorSliceByStackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(start_stack_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const SliceTable& parent,
      std::vector<SliceTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new AncestorSliceByStackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(start_stack_id)));
  }

  const IdColumn<AncestorSliceByStackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& dur() const {
    return static_cast<const ColumnType::dur&>(columns_[ColumnIndex::dur]);
  }
  const TypedColumn<TrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& category() const {
    return static_cast<const ColumnType::category&>(columns_[ColumnIndex::category]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<int64_t>& stack_id() const {
    return static_cast<const ColumnType::stack_id&>(columns_[ColumnIndex::stack_id]);
  }
  const TypedColumn<int64_t>& parent_stack_id() const {
    return static_cast<const ColumnType::parent_stack_id&>(columns_[ColumnIndex::parent_stack_id]);
  }
  const TypedColumn<std::optional<AncestorSliceByStackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_ts() const {
    return static_cast<const ColumnType::thread_ts&>(columns_[ColumnIndex::thread_ts]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_dur() const {
    return static_cast<const ColumnType::thread_dur&>(columns_[ColumnIndex::thread_dur]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_count() const {
    return static_cast<const ColumnType::thread_instruction_count&>(columns_[ColumnIndex::thread_instruction_count]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_delta() const {
    return static_cast<const ColumnType::thread_instruction_delta&>(columns_[ColumnIndex::thread_instruction_delta]);
  }
  const TypedColumn<int64_t>& start_stack_id() const {
    return static_cast<const ColumnType::start_stack_id&>(columns_[ColumnIndex::start_stack_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<TrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_category() {
    return static_cast<ColumnType::category*>(
        &columns_[ColumnIndex::category]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<int64_t>* mutable_stack_id() {
    return static_cast<ColumnType::stack_id*>(
        &columns_[ColumnIndex::stack_id]);
  }
  TypedColumn<int64_t>* mutable_parent_stack_id() {
    return static_cast<ColumnType::parent_stack_id*>(
        &columns_[ColumnIndex::parent_stack_id]);
  }
  TypedColumn<std::optional<AncestorSliceByStackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_ts() {
    return static_cast<ColumnType::thread_ts*>(
        &columns_[ColumnIndex::thread_ts]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_dur() {
    return static_cast<ColumnType::thread_dur*>(
        &columns_[ColumnIndex::thread_dur]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_count() {
    return static_cast<ColumnType::thread_instruction_count*>(
        &columns_[ColumnIndex::thread_instruction_count]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_delta() {
    return static_cast<ColumnType::thread_instruction_delta*>(
        &columns_[ColumnIndex::thread_instruction_delta]);
  }
  TypedColumn<int64_t>* mutable_start_stack_id() {
    return static_cast<ColumnType::start_stack_id*>(
        &columns_[ColumnIndex::start_stack_id]);
  }

 private:
  AncestorSliceByStackTable(StringPool* pool,
            const SliceTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_stack_id::stored_type>(
          ColumnFlag::start_stack_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(start_stack_id.size() == parent_overlay.size());
    start_stack_id_ = std::move(start_stack_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_stack_id", &start_stack_id_, ColumnFlag::start_stack_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  SliceTable* parent_ = nullptr;
  ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id_;
};
  

class AncestorSliceTable : public macros_internal::MacroTable {
 public:
  using Id = SliceTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t track_id = 4;
    static constexpr uint32_t category = 5;
    static constexpr uint32_t name = 6;
    static constexpr uint32_t depth = 7;
    static constexpr uint32_t stack_id = 8;
    static constexpr uint32_t parent_stack_id = 9;
    static constexpr uint32_t parent_id = 10;
    static constexpr uint32_t arg_set_id = 11;
    static constexpr uint32_t thread_ts = 12;
    static constexpr uint32_t thread_dur = 13;
    static constexpr uint32_t thread_instruction_count = 14;
    static constexpr uint32_t thread_instruction_delta = 15;
    static constexpr uint32_t start_id = 16;
  };
  struct ColumnType {
    using id = IdColumn<AncestorSliceTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using track_id = TypedColumn<TrackTable::Id>;
    using category = TypedColumn<std::optional<StringPool::Id>>;
    using name = TypedColumn<std::optional<StringPool::Id>>;
    using depth = TypedColumn<uint32_t>;
    using stack_id = TypedColumn<int64_t>;
    using parent_stack_id = TypedColumn<int64_t>;
    using parent_id = TypedColumn<std::optional<AncestorSliceTable::Id>>;
    using arg_set_id = TypedColumn<uint32_t>;
    using thread_ts = TypedColumn<std::optional<int64_t>>;
    using thread_dur = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_count = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_delta = TypedColumn<std::optional<int64_t>>;
    using start_id = TypedColumn<SliceTable::Id>;
  };
  struct Row : public SliceTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        TrackTable::Id in_track_id = {},
        std::optional<StringPool::Id> in_category = {},
        std::optional<StringPool::Id> in_name = {},
        uint32_t in_depth = {},
        int64_t in_stack_id = {},
        int64_t in_parent_stack_id = {},
        std::optional<AncestorSliceTable::Id> in_parent_id = {},
        uint32_t in_arg_set_id = {},
        std::optional<int64_t> in_thread_ts = {},
        std::optional<int64_t> in_thread_dur = {},
        std::optional<int64_t> in_thread_instruction_count = {},
        std::optional<int64_t> in_thread_instruction_delta = {},
        SliceTable::Id in_start_id = {},
        std::nullptr_t = nullptr)
        : SliceTable::Row(std::move(in_ts), std::move(in_dur), std::move(in_track_id), std::move(in_category), std::move(in_name), std::move(in_depth), std::move(in_stack_id), std::move(in_parent_stack_id), std::move(in_parent_id), std::move(in_arg_set_id), std::move(in_thread_ts), std::move(in_thread_dur), std::move(in_thread_instruction_count), std::move(in_thread_instruction_delta)),
          start_id(std::move(in_start_id)) {
      type_ = "ancestor_slice";
    }
    SliceTable::Id start_id;

    bool operator==(const AncestorSliceTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::category::Equals(category, other.category) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::stack_id::Equals(stack_id, other.stack_id) &&
       ColumnType::parent_stack_id::Equals(parent_stack_id, other.parent_stack_id) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::thread_ts::Equals(thread_ts, other.thread_ts) &&
       ColumnType::thread_dur::Equals(thread_dur, other.thread_dur) &&
       ColumnType::thread_instruction_count::Equals(thread_instruction_count, other.thread_instruction_count) &&
       ColumnType::thread_instruction_delta::Equals(thread_instruction_delta, other.thread_instruction_delta) &&
       ColumnType::start_id::Equals(start_id, other.start_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t start_id = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::start_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      AncestorSliceTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    AncestorSliceTable, RowNumber> {
   public:
    ConstRowReference(const AncestorSliceTable* table, uint32_t row_number)
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
    ColumnType::dur::type dur() const {
      return table_->dur()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
    ColumnType::category::type category() const {
      return table_->category()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::stack_id::type stack_id() const {
      return table_->stack_id()[row_number_];
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      return table_->parent_stack_id()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::thread_ts::type thread_ts() const {
      return table_->thread_ts()[row_number_];
    }
    ColumnType::thread_dur::type thread_dur() const {
      return table_->thread_dur()[row_number_];
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      return table_->thread_instruction_count()[row_number_];
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      return table_->thread_instruction_delta()[row_number_];
    }
    ColumnType::start_id::type start_id() const {
      return table_->start_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const AncestorSliceTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_dur(
        ColumnType::dur::non_optional_type v) {
      return mutable_table()->mutable_dur()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }
    void set_category(
        ColumnType::category::non_optional_type v) {
      return mutable_table()->mutable_category()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_stack_id(
        ColumnType::stack_id::non_optional_type v) {
      return mutable_table()->mutable_stack_id()->Set(row_number_, v);
    }
    void set_parent_stack_id(
        ColumnType::parent_stack_id::non_optional_type v) {
      return mutable_table()->mutable_parent_stack_id()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_thread_ts(
        ColumnType::thread_ts::non_optional_type v) {
      return mutable_table()->mutable_thread_ts()->Set(row_number_, v);
    }
    void set_thread_dur(
        ColumnType::thread_dur::non_optional_type v) {
      return mutable_table()->mutable_thread_dur()->Set(row_number_, v);
    }
    void set_thread_instruction_count(
        ColumnType::thread_instruction_count::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_count()->Set(row_number_, v);
    }
    void set_thread_instruction_delta(
        ColumnType::thread_instruction_delta::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_delta()->Set(row_number_, v);
    }
    void set_start_id(
        ColumnType::start_id::non_optional_type v) {
      return mutable_table()->mutable_start_id()->Set(row_number_, v);
    }

   private:
    AncestorSliceTable* mutable_table() const {
      return const_cast<AncestorSliceTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, AncestorSliceTable, RowNumber, ConstRowReference> {
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
    ColumnType::dur::type dur() const {
      const auto& col = table_->dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::category::type category() const {
      const auto& col = table_->category();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::stack_id::type stack_id() const {
      const auto& col = table_->stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      const auto& col = table_->parent_stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_ts::type thread_ts() const {
      const auto& col = table_->thread_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_dur::type thread_dur() const {
      const auto& col = table_->thread_dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      const auto& col = table_->thread_instruction_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      const auto& col = table_->thread_instruction_delta();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_id::type start_id() const {
      const auto& col = table_->start_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const AncestorSliceTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class AncestorSliceTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, AncestorSliceTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_dur(ColumnType::dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_category(ColumnType::category::non_optional_type v) {
        auto* col = mutable_table_->mutable_category();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_stack_id(ColumnType::stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_stack_id(ColumnType::parent_stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_ts(ColumnType::thread_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_dur(ColumnType::thread_dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_count(ColumnType::thread_instruction_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_delta(ColumnType::thread_instruction_delta::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_delta();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_id(ColumnType::start_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class AncestorSliceTable;

    explicit Iterator(AncestorSliceTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    AncestorSliceTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit AncestorSliceTable(StringPool* pool, SliceTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), start_id_(ColumnStorage<ColumnType::start_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~AncestorSliceTable() override;

  static const char* Name() { return "ancestor_slice"; }

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
        "dur", ColumnType::dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "category", ColumnType::category::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "stack_id", ColumnType::stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_stack_id", ColumnType::parent_stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_ts", ColumnType::thread_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_dur", ColumnType::thread_dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_count", ColumnType::thread_instruction_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_delta", ColumnType::thread_instruction_delta::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_id", ColumnType::start_id::SqlValueType(), false,
        false,
        true,
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
    start_id_.ShrinkToFit();
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
    mutable_start_id()->Append(std::move(row.start_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const SliceTable& parent,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    return std::unique_ptr<Table>(new AncestorSliceTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(start_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const SliceTable& parent,
      std::vector<SliceTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new AncestorSliceTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(start_id)));
  }

  const IdColumn<AncestorSliceTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& dur() const {
    return static_cast<const ColumnType::dur&>(columns_[ColumnIndex::dur]);
  }
  const TypedColumn<TrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& category() const {
    return static_cast<const ColumnType::category&>(columns_[ColumnIndex::category]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<int64_t>& stack_id() const {
    return static_cast<const ColumnType::stack_id&>(columns_[ColumnIndex::stack_id]);
  }
  const TypedColumn<int64_t>& parent_stack_id() const {
    return static_cast<const ColumnType::parent_stack_id&>(columns_[ColumnIndex::parent_stack_id]);
  }
  const TypedColumn<std::optional<AncestorSliceTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_ts() const {
    return static_cast<const ColumnType::thread_ts&>(columns_[ColumnIndex::thread_ts]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_dur() const {
    return static_cast<const ColumnType::thread_dur&>(columns_[ColumnIndex::thread_dur]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_count() const {
    return static_cast<const ColumnType::thread_instruction_count&>(columns_[ColumnIndex::thread_instruction_count]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_delta() const {
    return static_cast<const ColumnType::thread_instruction_delta&>(columns_[ColumnIndex::thread_instruction_delta]);
  }
  const TypedColumn<SliceTable::Id>& start_id() const {
    return static_cast<const ColumnType::start_id&>(columns_[ColumnIndex::start_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<TrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_category() {
    return static_cast<ColumnType::category*>(
        &columns_[ColumnIndex::category]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<int64_t>* mutable_stack_id() {
    return static_cast<ColumnType::stack_id*>(
        &columns_[ColumnIndex::stack_id]);
  }
  TypedColumn<int64_t>* mutable_parent_stack_id() {
    return static_cast<ColumnType::parent_stack_id*>(
        &columns_[ColumnIndex::parent_stack_id]);
  }
  TypedColumn<std::optional<AncestorSliceTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_ts() {
    return static_cast<ColumnType::thread_ts*>(
        &columns_[ColumnIndex::thread_ts]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_dur() {
    return static_cast<ColumnType::thread_dur*>(
        &columns_[ColumnIndex::thread_dur]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_count() {
    return static_cast<ColumnType::thread_instruction_count*>(
        &columns_[ColumnIndex::thread_instruction_count]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_delta() {
    return static_cast<ColumnType::thread_instruction_delta*>(
        &columns_[ColumnIndex::thread_instruction_delta]);
  }
  TypedColumn<SliceTable::Id>* mutable_start_id() {
    return static_cast<ColumnType::start_id*>(
        &columns_[ColumnIndex::start_id]);
  }

 private:
  AncestorSliceTable(StringPool* pool,
            const SliceTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::start_id::stored_type> start_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(start_id.size() == parent_overlay.size());
    start_id_ = std::move(start_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  SliceTable* parent_ = nullptr;
  ColumnStorage<ColumnType::start_id::stored_type> start_id_;
};
  

class AncestorStackProfileCallsiteTable : public macros_internal::MacroTable {
 public:
  using Id = StackProfileCallsiteTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t depth = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t frame_id = 4;
    static constexpr uint32_t start_id = 5;
  };
  struct ColumnType {
    using id = IdColumn<AncestorStackProfileCallsiteTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using depth = TypedColumn<uint32_t>;
    using parent_id = TypedColumn<std::optional<AncestorStackProfileCallsiteTable::Id>>;
    using frame_id = TypedColumn<StackProfileFrameTable::Id>;
    using start_id = TypedColumn<StackProfileCallsiteTable::Id>;
  };
  struct Row : public StackProfileCallsiteTable::Row {
    Row(uint32_t in_depth = {},
        std::optional<AncestorStackProfileCallsiteTable::Id> in_parent_id = {},
        StackProfileFrameTable::Id in_frame_id = {},
        StackProfileCallsiteTable::Id in_start_id = {},
        std::nullptr_t = nullptr)
        : StackProfileCallsiteTable::Row(std::move(in_depth), std::move(in_parent_id), std::move(in_frame_id)),
          start_id(std::move(in_start_id)) {
      type_ = "experimental_ancestor_stack_profile_callsite";
    }
    StackProfileCallsiteTable::Id start_id;

    bool operator==(const AncestorStackProfileCallsiteTable::Row& other) const {
      return type() == other.type() && ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::frame_id::Equals(frame_id, other.frame_id) &&
       ColumnType::start_id::Equals(start_id, other.start_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t start_id = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::start_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      AncestorStackProfileCallsiteTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    AncestorStackProfileCallsiteTable, RowNumber> {
   public:
    ConstRowReference(const AncestorStackProfileCallsiteTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::frame_id::type frame_id() const {
      return table_->frame_id()[row_number_];
    }
    ColumnType::start_id::type start_id() const {
      return table_->start_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const AncestorStackProfileCallsiteTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_frame_id(
        ColumnType::frame_id::non_optional_type v) {
      return mutable_table()->mutable_frame_id()->Set(row_number_, v);
    }
    void set_start_id(
        ColumnType::start_id::non_optional_type v) {
      return mutable_table()->mutable_start_id()->Set(row_number_, v);
    }

   private:
    AncestorStackProfileCallsiteTable* mutable_table() const {
      return const_cast<AncestorStackProfileCallsiteTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, AncestorStackProfileCallsiteTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::frame_id::type frame_id() const {
      const auto& col = table_->frame_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_id::type start_id() const {
      const auto& col = table_->start_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const AncestorStackProfileCallsiteTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class AncestorStackProfileCallsiteTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, AncestorStackProfileCallsiteTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_frame_id(ColumnType::frame_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_frame_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_id(ColumnType::start_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class AncestorStackProfileCallsiteTable;

    explicit Iterator(AncestorStackProfileCallsiteTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    AncestorStackProfileCallsiteTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit AncestorStackProfileCallsiteTable(StringPool* pool, StackProfileCallsiteTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), start_id_(ColumnStorage<ColumnType::start_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~AncestorStackProfileCallsiteTable() override;

  static const char* Name() { return "experimental_ancestor_stack_profile_callsite"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "frame_id", ColumnType::frame_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_id", ColumnType::start_id::SqlValueType(), false,
        false,
        true,
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
    start_id_.ShrinkToFit();
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
    mutable_start_id()->Append(std::move(row.start_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const StackProfileCallsiteTable& parent,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    return std::unique_ptr<Table>(new AncestorStackProfileCallsiteTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(start_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const StackProfileCallsiteTable& parent,
      std::vector<StackProfileCallsiteTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new AncestorStackProfileCallsiteTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(start_id)));
  }

  const IdColumn<AncestorStackProfileCallsiteTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<std::optional<AncestorStackProfileCallsiteTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<StackProfileFrameTable::Id>& frame_id() const {
    return static_cast<const ColumnType::frame_id&>(columns_[ColumnIndex::frame_id]);
  }
  const TypedColumn<StackProfileCallsiteTable::Id>& start_id() const {
    return static_cast<const ColumnType::start_id&>(columns_[ColumnIndex::start_id]);
  }

  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<std::optional<AncestorStackProfileCallsiteTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<StackProfileFrameTable::Id>* mutable_frame_id() {
    return static_cast<ColumnType::frame_id*>(
        &columns_[ColumnIndex::frame_id]);
  }
  TypedColumn<StackProfileCallsiteTable::Id>* mutable_start_id() {
    return static_cast<ColumnType::start_id*>(
        &columns_[ColumnIndex::start_id]);
  }

 private:
  AncestorStackProfileCallsiteTable(StringPool* pool,
            const StackProfileCallsiteTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::start_id::stored_type> start_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(start_id.size() == parent_overlay.size());
    start_id_ = std::move(start_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  StackProfileCallsiteTable* parent_ = nullptr;
  ColumnStorage<ColumnType::start_id::stored_type> start_id_;
};
  

class ConnectedFlowTable : public macros_internal::MacroTable {
 public:
  using Id = FlowTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t slice_out = 2;
    static constexpr uint32_t slice_in = 3;
    static constexpr uint32_t arg_set_id = 4;
    static constexpr uint32_t start_id = 5;
  };
  struct ColumnType {
    using id = IdColumn<ConnectedFlowTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using slice_out = TypedColumn<SliceTable::Id>;
    using slice_in = TypedColumn<SliceTable::Id>;
    using arg_set_id = TypedColumn<uint32_t>;
    using start_id = TypedColumn<SliceTable::Id>;
  };
  struct Row : public FlowTable::Row {
    Row(SliceTable::Id in_slice_out = {},
        SliceTable::Id in_slice_in = {},
        uint32_t in_arg_set_id = {},
        SliceTable::Id in_start_id = {},
        std::nullptr_t = nullptr)
        : FlowTable::Row(std::move(in_slice_out), std::move(in_slice_in), std::move(in_arg_set_id)),
          start_id(std::move(in_start_id)) {
      type_ = "not_exposed_to_sql";
    }
    SliceTable::Id start_id;

    bool operator==(const ConnectedFlowTable::Row& other) const {
      return type() == other.type() && ColumnType::slice_out::Equals(slice_out, other.slice_out) &&
       ColumnType::slice_in::Equals(slice_in, other.slice_in) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::start_id::Equals(start_id, other.start_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t start_id = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::start_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ConnectedFlowTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ConnectedFlowTable, RowNumber> {
   public:
    ConstRowReference(const ConnectedFlowTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::slice_out::type slice_out() const {
      return table_->slice_out()[row_number_];
    }
    ColumnType::slice_in::type slice_in() const {
      return table_->slice_in()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::start_id::type start_id() const {
      return table_->start_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ConnectedFlowTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_slice_out(
        ColumnType::slice_out::non_optional_type v) {
      return mutable_table()->mutable_slice_out()->Set(row_number_, v);
    }
    void set_slice_in(
        ColumnType::slice_in::non_optional_type v) {
      return mutable_table()->mutable_slice_in()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_start_id(
        ColumnType::start_id::non_optional_type v) {
      return mutable_table()->mutable_start_id()->Set(row_number_, v);
    }

   private:
    ConnectedFlowTable* mutable_table() const {
      return const_cast<ConnectedFlowTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ConnectedFlowTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::slice_out::type slice_out() const {
      const auto& col = table_->slice_out();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::slice_in::type slice_in() const {
      const auto& col = table_->slice_in();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_id::type start_id() const {
      const auto& col = table_->start_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ConnectedFlowTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ConnectedFlowTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ConnectedFlowTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_slice_out(ColumnType::slice_out::non_optional_type v) {
        auto* col = mutable_table_->mutable_slice_out();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_slice_in(ColumnType::slice_in::non_optional_type v) {
        auto* col = mutable_table_->mutable_slice_in();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_id(ColumnType::start_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ConnectedFlowTable;

    explicit Iterator(ConnectedFlowTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ConnectedFlowTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ConnectedFlowTable(StringPool* pool, FlowTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), start_id_(ColumnStorage<ColumnType::start_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ConnectedFlowTable() override;

  static const char* Name() { return "not_exposed_to_sql"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "slice_out", ColumnType::slice_out::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "slice_in", ColumnType::slice_in::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_id", ColumnType::start_id::SqlValueType(), false,
        false,
        true,
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
    start_id_.ShrinkToFit();
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
    mutable_start_id()->Append(std::move(row.start_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const FlowTable& parent,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    return std::unique_ptr<Table>(new ConnectedFlowTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(start_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const FlowTable& parent,
      std::vector<FlowTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ConnectedFlowTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(start_id)));
  }

  const IdColumn<ConnectedFlowTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<SliceTable::Id>& slice_out() const {
    return static_cast<const ColumnType::slice_out&>(columns_[ColumnIndex::slice_out]);
  }
  const TypedColumn<SliceTable::Id>& slice_in() const {
    return static_cast<const ColumnType::slice_in&>(columns_[ColumnIndex::slice_in]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<SliceTable::Id>& start_id() const {
    return static_cast<const ColumnType::start_id&>(columns_[ColumnIndex::start_id]);
  }

  TypedColumn<SliceTable::Id>* mutable_slice_out() {
    return static_cast<ColumnType::slice_out*>(
        &columns_[ColumnIndex::slice_out]);
  }
  TypedColumn<SliceTable::Id>* mutable_slice_in() {
    return static_cast<ColumnType::slice_in*>(
        &columns_[ColumnIndex::slice_in]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<SliceTable::Id>* mutable_start_id() {
    return static_cast<ColumnType::start_id*>(
        &columns_[ColumnIndex::start_id]);
  }

 private:
  ConnectedFlowTable(StringPool* pool,
            const FlowTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::start_id::stored_type> start_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(start_id.size() == parent_overlay.size());
    start_id_ = std::move(start_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  FlowTable* parent_ = nullptr;
  ColumnStorage<ColumnType::start_id::stored_type> start_id_;
};
  

class DescendantSliceByStackTable : public macros_internal::MacroTable {
 public:
  using Id = SliceTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t track_id = 4;
    static constexpr uint32_t category = 5;
    static constexpr uint32_t name = 6;
    static constexpr uint32_t depth = 7;
    static constexpr uint32_t stack_id = 8;
    static constexpr uint32_t parent_stack_id = 9;
    static constexpr uint32_t parent_id = 10;
    static constexpr uint32_t arg_set_id = 11;
    static constexpr uint32_t thread_ts = 12;
    static constexpr uint32_t thread_dur = 13;
    static constexpr uint32_t thread_instruction_count = 14;
    static constexpr uint32_t thread_instruction_delta = 15;
    static constexpr uint32_t start_stack_id = 16;
  };
  struct ColumnType {
    using id = IdColumn<DescendantSliceByStackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using track_id = TypedColumn<TrackTable::Id>;
    using category = TypedColumn<std::optional<StringPool::Id>>;
    using name = TypedColumn<std::optional<StringPool::Id>>;
    using depth = TypedColumn<uint32_t>;
    using stack_id = TypedColumn<int64_t>;
    using parent_stack_id = TypedColumn<int64_t>;
    using parent_id = TypedColumn<std::optional<DescendantSliceByStackTable::Id>>;
    using arg_set_id = TypedColumn<uint32_t>;
    using thread_ts = TypedColumn<std::optional<int64_t>>;
    using thread_dur = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_count = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_delta = TypedColumn<std::optional<int64_t>>;
    using start_stack_id = TypedColumn<int64_t>;
  };
  struct Row : public SliceTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        TrackTable::Id in_track_id = {},
        std::optional<StringPool::Id> in_category = {},
        std::optional<StringPool::Id> in_name = {},
        uint32_t in_depth = {},
        int64_t in_stack_id = {},
        int64_t in_parent_stack_id = {},
        std::optional<DescendantSliceByStackTable::Id> in_parent_id = {},
        uint32_t in_arg_set_id = {},
        std::optional<int64_t> in_thread_ts = {},
        std::optional<int64_t> in_thread_dur = {},
        std::optional<int64_t> in_thread_instruction_count = {},
        std::optional<int64_t> in_thread_instruction_delta = {},
        int64_t in_start_stack_id = {},
        std::nullptr_t = nullptr)
        : SliceTable::Row(std::move(in_ts), std::move(in_dur), std::move(in_track_id), std::move(in_category), std::move(in_name), std::move(in_depth), std::move(in_stack_id), std::move(in_parent_stack_id), std::move(in_parent_id), std::move(in_arg_set_id), std::move(in_thread_ts), std::move(in_thread_dur), std::move(in_thread_instruction_count), std::move(in_thread_instruction_delta)),
          start_stack_id(std::move(in_start_stack_id)) {
      type_ = "descendant_slice_by_stack";
    }
    int64_t start_stack_id;

    bool operator==(const DescendantSliceByStackTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::category::Equals(category, other.category) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::stack_id::Equals(stack_id, other.stack_id) &&
       ColumnType::parent_stack_id::Equals(parent_stack_id, other.parent_stack_id) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::thread_ts::Equals(thread_ts, other.thread_ts) &&
       ColumnType::thread_dur::Equals(thread_dur, other.thread_dur) &&
       ColumnType::thread_instruction_count::Equals(thread_instruction_count, other.thread_instruction_count) &&
       ColumnType::thread_instruction_delta::Equals(thread_instruction_delta, other.thread_instruction_delta) &&
       ColumnType::start_stack_id::Equals(start_stack_id, other.start_stack_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t start_stack_id = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::start_stack_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      DescendantSliceByStackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    DescendantSliceByStackTable, RowNumber> {
   public:
    ConstRowReference(const DescendantSliceByStackTable* table, uint32_t row_number)
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
    ColumnType::dur::type dur() const {
      return table_->dur()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
    ColumnType::category::type category() const {
      return table_->category()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::stack_id::type stack_id() const {
      return table_->stack_id()[row_number_];
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      return table_->parent_stack_id()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::thread_ts::type thread_ts() const {
      return table_->thread_ts()[row_number_];
    }
    ColumnType::thread_dur::type thread_dur() const {
      return table_->thread_dur()[row_number_];
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      return table_->thread_instruction_count()[row_number_];
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      return table_->thread_instruction_delta()[row_number_];
    }
    ColumnType::start_stack_id::type start_stack_id() const {
      return table_->start_stack_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const DescendantSliceByStackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_dur(
        ColumnType::dur::non_optional_type v) {
      return mutable_table()->mutable_dur()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }
    void set_category(
        ColumnType::category::non_optional_type v) {
      return mutable_table()->mutable_category()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_stack_id(
        ColumnType::stack_id::non_optional_type v) {
      return mutable_table()->mutable_stack_id()->Set(row_number_, v);
    }
    void set_parent_stack_id(
        ColumnType::parent_stack_id::non_optional_type v) {
      return mutable_table()->mutable_parent_stack_id()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_thread_ts(
        ColumnType::thread_ts::non_optional_type v) {
      return mutable_table()->mutable_thread_ts()->Set(row_number_, v);
    }
    void set_thread_dur(
        ColumnType::thread_dur::non_optional_type v) {
      return mutable_table()->mutable_thread_dur()->Set(row_number_, v);
    }
    void set_thread_instruction_count(
        ColumnType::thread_instruction_count::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_count()->Set(row_number_, v);
    }
    void set_thread_instruction_delta(
        ColumnType::thread_instruction_delta::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_delta()->Set(row_number_, v);
    }
    void set_start_stack_id(
        ColumnType::start_stack_id::non_optional_type v) {
      return mutable_table()->mutable_start_stack_id()->Set(row_number_, v);
    }

   private:
    DescendantSliceByStackTable* mutable_table() const {
      return const_cast<DescendantSliceByStackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, DescendantSliceByStackTable, RowNumber, ConstRowReference> {
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
    ColumnType::dur::type dur() const {
      const auto& col = table_->dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::category::type category() const {
      const auto& col = table_->category();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::stack_id::type stack_id() const {
      const auto& col = table_->stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      const auto& col = table_->parent_stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_ts::type thread_ts() const {
      const auto& col = table_->thread_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_dur::type thread_dur() const {
      const auto& col = table_->thread_dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      const auto& col = table_->thread_instruction_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      const auto& col = table_->thread_instruction_delta();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_stack_id::type start_stack_id() const {
      const auto& col = table_->start_stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const DescendantSliceByStackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class DescendantSliceByStackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, DescendantSliceByStackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_dur(ColumnType::dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_category(ColumnType::category::non_optional_type v) {
        auto* col = mutable_table_->mutable_category();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_stack_id(ColumnType::stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_stack_id(ColumnType::parent_stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_ts(ColumnType::thread_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_dur(ColumnType::thread_dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_count(ColumnType::thread_instruction_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_delta(ColumnType::thread_instruction_delta::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_delta();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_stack_id(ColumnType::start_stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class DescendantSliceByStackTable;

    explicit Iterator(DescendantSliceByStackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    DescendantSliceByStackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit DescendantSliceByStackTable(StringPool* pool, SliceTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), start_stack_id_(ColumnStorage<ColumnType::start_stack_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_stack_id::stored_type>(
          ColumnFlag::start_stack_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_stack_id", &start_stack_id_, ColumnFlag::start_stack_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~DescendantSliceByStackTable() override;

  static const char* Name() { return "descendant_slice_by_stack"; }

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
        "dur", ColumnType::dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "category", ColumnType::category::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "stack_id", ColumnType::stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_stack_id", ColumnType::parent_stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_ts", ColumnType::thread_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_dur", ColumnType::thread_dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_count", ColumnType::thread_instruction_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_delta", ColumnType::thread_instruction_delta::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_stack_id", ColumnType::start_stack_id::SqlValueType(), false,
        false,
        true,
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
    start_stack_id_.ShrinkToFit();
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
    mutable_start_stack_id()->Append(std::move(row.start_stack_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const SliceTable& parent,
      ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id) {
    return std::unique_ptr<Table>(new DescendantSliceByStackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(start_stack_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const SliceTable& parent,
      std::vector<SliceTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new DescendantSliceByStackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(start_stack_id)));
  }

  const IdColumn<DescendantSliceByStackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& dur() const {
    return static_cast<const ColumnType::dur&>(columns_[ColumnIndex::dur]);
  }
  const TypedColumn<TrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& category() const {
    return static_cast<const ColumnType::category&>(columns_[ColumnIndex::category]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<int64_t>& stack_id() const {
    return static_cast<const ColumnType::stack_id&>(columns_[ColumnIndex::stack_id]);
  }
  const TypedColumn<int64_t>& parent_stack_id() const {
    return static_cast<const ColumnType::parent_stack_id&>(columns_[ColumnIndex::parent_stack_id]);
  }
  const TypedColumn<std::optional<DescendantSliceByStackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_ts() const {
    return static_cast<const ColumnType::thread_ts&>(columns_[ColumnIndex::thread_ts]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_dur() const {
    return static_cast<const ColumnType::thread_dur&>(columns_[ColumnIndex::thread_dur]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_count() const {
    return static_cast<const ColumnType::thread_instruction_count&>(columns_[ColumnIndex::thread_instruction_count]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_delta() const {
    return static_cast<const ColumnType::thread_instruction_delta&>(columns_[ColumnIndex::thread_instruction_delta]);
  }
  const TypedColumn<int64_t>& start_stack_id() const {
    return static_cast<const ColumnType::start_stack_id&>(columns_[ColumnIndex::start_stack_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<TrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_category() {
    return static_cast<ColumnType::category*>(
        &columns_[ColumnIndex::category]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<int64_t>* mutable_stack_id() {
    return static_cast<ColumnType::stack_id*>(
        &columns_[ColumnIndex::stack_id]);
  }
  TypedColumn<int64_t>* mutable_parent_stack_id() {
    return static_cast<ColumnType::parent_stack_id*>(
        &columns_[ColumnIndex::parent_stack_id]);
  }
  TypedColumn<std::optional<DescendantSliceByStackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_ts() {
    return static_cast<ColumnType::thread_ts*>(
        &columns_[ColumnIndex::thread_ts]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_dur() {
    return static_cast<ColumnType::thread_dur*>(
        &columns_[ColumnIndex::thread_dur]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_count() {
    return static_cast<ColumnType::thread_instruction_count*>(
        &columns_[ColumnIndex::thread_instruction_count]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_delta() {
    return static_cast<ColumnType::thread_instruction_delta*>(
        &columns_[ColumnIndex::thread_instruction_delta]);
  }
  TypedColumn<int64_t>* mutable_start_stack_id() {
    return static_cast<ColumnType::start_stack_id*>(
        &columns_[ColumnIndex::start_stack_id]);
  }

 private:
  DescendantSliceByStackTable(StringPool* pool,
            const SliceTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_stack_id::stored_type>(
          ColumnFlag::start_stack_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(start_stack_id.size() == parent_overlay.size());
    start_stack_id_ = std::move(start_stack_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_stack_id", &start_stack_id_, ColumnFlag::start_stack_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  SliceTable* parent_ = nullptr;
  ColumnStorage<ColumnType::start_stack_id::stored_type> start_stack_id_;
};
  

class DescendantSliceTable : public macros_internal::MacroTable {
 public:
  using Id = SliceTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t track_id = 4;
    static constexpr uint32_t category = 5;
    static constexpr uint32_t name = 6;
    static constexpr uint32_t depth = 7;
    static constexpr uint32_t stack_id = 8;
    static constexpr uint32_t parent_stack_id = 9;
    static constexpr uint32_t parent_id = 10;
    static constexpr uint32_t arg_set_id = 11;
    static constexpr uint32_t thread_ts = 12;
    static constexpr uint32_t thread_dur = 13;
    static constexpr uint32_t thread_instruction_count = 14;
    static constexpr uint32_t thread_instruction_delta = 15;
    static constexpr uint32_t start_id = 16;
  };
  struct ColumnType {
    using id = IdColumn<DescendantSliceTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using track_id = TypedColumn<TrackTable::Id>;
    using category = TypedColumn<std::optional<StringPool::Id>>;
    using name = TypedColumn<std::optional<StringPool::Id>>;
    using depth = TypedColumn<uint32_t>;
    using stack_id = TypedColumn<int64_t>;
    using parent_stack_id = TypedColumn<int64_t>;
    using parent_id = TypedColumn<std::optional<DescendantSliceTable::Id>>;
    using arg_set_id = TypedColumn<uint32_t>;
    using thread_ts = TypedColumn<std::optional<int64_t>>;
    using thread_dur = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_count = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_delta = TypedColumn<std::optional<int64_t>>;
    using start_id = TypedColumn<SliceTable::Id>;
  };
  struct Row : public SliceTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        TrackTable::Id in_track_id = {},
        std::optional<StringPool::Id> in_category = {},
        std::optional<StringPool::Id> in_name = {},
        uint32_t in_depth = {},
        int64_t in_stack_id = {},
        int64_t in_parent_stack_id = {},
        std::optional<DescendantSliceTable::Id> in_parent_id = {},
        uint32_t in_arg_set_id = {},
        std::optional<int64_t> in_thread_ts = {},
        std::optional<int64_t> in_thread_dur = {},
        std::optional<int64_t> in_thread_instruction_count = {},
        std::optional<int64_t> in_thread_instruction_delta = {},
        SliceTable::Id in_start_id = {},
        std::nullptr_t = nullptr)
        : SliceTable::Row(std::move(in_ts), std::move(in_dur), std::move(in_track_id), std::move(in_category), std::move(in_name), std::move(in_depth), std::move(in_stack_id), std::move(in_parent_stack_id), std::move(in_parent_id), std::move(in_arg_set_id), std::move(in_thread_ts), std::move(in_thread_dur), std::move(in_thread_instruction_count), std::move(in_thread_instruction_delta)),
          start_id(std::move(in_start_id)) {
      type_ = "descendant_slice";
    }
    SliceTable::Id start_id;

    bool operator==(const DescendantSliceTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::category::Equals(category, other.category) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::stack_id::Equals(stack_id, other.stack_id) &&
       ColumnType::parent_stack_id::Equals(parent_stack_id, other.parent_stack_id) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::thread_ts::Equals(thread_ts, other.thread_ts) &&
       ColumnType::thread_dur::Equals(thread_dur, other.thread_dur) &&
       ColumnType::thread_instruction_count::Equals(thread_instruction_count, other.thread_instruction_count) &&
       ColumnType::thread_instruction_delta::Equals(thread_instruction_delta, other.thread_instruction_delta) &&
       ColumnType::start_id::Equals(start_id, other.start_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t start_id = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::start_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      DescendantSliceTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    DescendantSliceTable, RowNumber> {
   public:
    ConstRowReference(const DescendantSliceTable* table, uint32_t row_number)
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
    ColumnType::dur::type dur() const {
      return table_->dur()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
    ColumnType::category::type category() const {
      return table_->category()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::stack_id::type stack_id() const {
      return table_->stack_id()[row_number_];
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      return table_->parent_stack_id()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::thread_ts::type thread_ts() const {
      return table_->thread_ts()[row_number_];
    }
    ColumnType::thread_dur::type thread_dur() const {
      return table_->thread_dur()[row_number_];
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      return table_->thread_instruction_count()[row_number_];
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      return table_->thread_instruction_delta()[row_number_];
    }
    ColumnType::start_id::type start_id() const {
      return table_->start_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const DescendantSliceTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_dur(
        ColumnType::dur::non_optional_type v) {
      return mutable_table()->mutable_dur()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }
    void set_category(
        ColumnType::category::non_optional_type v) {
      return mutable_table()->mutable_category()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_stack_id(
        ColumnType::stack_id::non_optional_type v) {
      return mutable_table()->mutable_stack_id()->Set(row_number_, v);
    }
    void set_parent_stack_id(
        ColumnType::parent_stack_id::non_optional_type v) {
      return mutable_table()->mutable_parent_stack_id()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_thread_ts(
        ColumnType::thread_ts::non_optional_type v) {
      return mutable_table()->mutable_thread_ts()->Set(row_number_, v);
    }
    void set_thread_dur(
        ColumnType::thread_dur::non_optional_type v) {
      return mutable_table()->mutable_thread_dur()->Set(row_number_, v);
    }
    void set_thread_instruction_count(
        ColumnType::thread_instruction_count::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_count()->Set(row_number_, v);
    }
    void set_thread_instruction_delta(
        ColumnType::thread_instruction_delta::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_delta()->Set(row_number_, v);
    }
    void set_start_id(
        ColumnType::start_id::non_optional_type v) {
      return mutable_table()->mutable_start_id()->Set(row_number_, v);
    }

   private:
    DescendantSliceTable* mutable_table() const {
      return const_cast<DescendantSliceTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, DescendantSliceTable, RowNumber, ConstRowReference> {
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
    ColumnType::dur::type dur() const {
      const auto& col = table_->dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::category::type category() const {
      const auto& col = table_->category();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::stack_id::type stack_id() const {
      const auto& col = table_->stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      const auto& col = table_->parent_stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_ts::type thread_ts() const {
      const auto& col = table_->thread_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_dur::type thread_dur() const {
      const auto& col = table_->thread_dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      const auto& col = table_->thread_instruction_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      const auto& col = table_->thread_instruction_delta();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_id::type start_id() const {
      const auto& col = table_->start_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const DescendantSliceTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class DescendantSliceTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, DescendantSliceTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_dur(ColumnType::dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_category(ColumnType::category::non_optional_type v) {
        auto* col = mutable_table_->mutable_category();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_stack_id(ColumnType::stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_stack_id(ColumnType::parent_stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_ts(ColumnType::thread_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_dur(ColumnType::thread_dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_count(ColumnType::thread_instruction_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_delta(ColumnType::thread_instruction_delta::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_delta();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_id(ColumnType::start_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class DescendantSliceTable;

    explicit Iterator(DescendantSliceTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    DescendantSliceTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit DescendantSliceTable(StringPool* pool, SliceTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), start_id_(ColumnStorage<ColumnType::start_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~DescendantSliceTable() override;

  static const char* Name() { return "descendant_slice"; }

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
        "dur", ColumnType::dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "category", ColumnType::category::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "stack_id", ColumnType::stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_stack_id", ColumnType::parent_stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_ts", ColumnType::thread_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_dur", ColumnType::thread_dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_count", ColumnType::thread_instruction_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_delta", ColumnType::thread_instruction_delta::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_id", ColumnType::start_id::SqlValueType(), false,
        false,
        true,
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
    start_id_.ShrinkToFit();
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
    mutable_start_id()->Append(std::move(row.start_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const SliceTable& parent,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    return std::unique_ptr<Table>(new DescendantSliceTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(start_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const SliceTable& parent,
      std::vector<SliceTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new DescendantSliceTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(start_id)));
  }

  const IdColumn<DescendantSliceTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& dur() const {
    return static_cast<const ColumnType::dur&>(columns_[ColumnIndex::dur]);
  }
  const TypedColumn<TrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& category() const {
    return static_cast<const ColumnType::category&>(columns_[ColumnIndex::category]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<int64_t>& stack_id() const {
    return static_cast<const ColumnType::stack_id&>(columns_[ColumnIndex::stack_id]);
  }
  const TypedColumn<int64_t>& parent_stack_id() const {
    return static_cast<const ColumnType::parent_stack_id&>(columns_[ColumnIndex::parent_stack_id]);
  }
  const TypedColumn<std::optional<DescendantSliceTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_ts() const {
    return static_cast<const ColumnType::thread_ts&>(columns_[ColumnIndex::thread_ts]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_dur() const {
    return static_cast<const ColumnType::thread_dur&>(columns_[ColumnIndex::thread_dur]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_count() const {
    return static_cast<const ColumnType::thread_instruction_count&>(columns_[ColumnIndex::thread_instruction_count]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_delta() const {
    return static_cast<const ColumnType::thread_instruction_delta&>(columns_[ColumnIndex::thread_instruction_delta]);
  }
  const TypedColumn<SliceTable::Id>& start_id() const {
    return static_cast<const ColumnType::start_id&>(columns_[ColumnIndex::start_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<TrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_category() {
    return static_cast<ColumnType::category*>(
        &columns_[ColumnIndex::category]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<int64_t>* mutable_stack_id() {
    return static_cast<ColumnType::stack_id*>(
        &columns_[ColumnIndex::stack_id]);
  }
  TypedColumn<int64_t>* mutable_parent_stack_id() {
    return static_cast<ColumnType::parent_stack_id*>(
        &columns_[ColumnIndex::parent_stack_id]);
  }
  TypedColumn<std::optional<DescendantSliceTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_ts() {
    return static_cast<ColumnType::thread_ts*>(
        &columns_[ColumnIndex::thread_ts]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_dur() {
    return static_cast<ColumnType::thread_dur*>(
        &columns_[ColumnIndex::thread_dur]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_count() {
    return static_cast<ColumnType::thread_instruction_count*>(
        &columns_[ColumnIndex::thread_instruction_count]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_delta() {
    return static_cast<ColumnType::thread_instruction_delta*>(
        &columns_[ColumnIndex::thread_instruction_delta]);
  }
  TypedColumn<SliceTable::Id>* mutable_start_id() {
    return static_cast<ColumnType::start_id*>(
        &columns_[ColumnIndex::start_id]);
  }

 private:
  DescendantSliceTable(StringPool* pool,
            const SliceTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::start_id::stored_type> start_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(start_id.size() == parent_overlay.size());
    start_id_ = std::move(start_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  SliceTable* parent_ = nullptr;
  ColumnStorage<ColumnType::start_id::stored_type> start_id_;
};
  

class ExperimentalAnnotatedCallstackTable : public macros_internal::MacroTable {
 public:
  using Id = StackProfileCallsiteTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t depth = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t frame_id = 4;
    static constexpr uint32_t annotation = 5;
    static constexpr uint32_t start_id = 6;
  };
  struct ColumnType {
    using id = IdColumn<ExperimentalAnnotatedCallstackTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using depth = TypedColumn<uint32_t>;
    using parent_id = TypedColumn<std::optional<ExperimentalAnnotatedCallstackTable::Id>>;
    using frame_id = TypedColumn<StackProfileFrameTable::Id>;
    using annotation = TypedColumn<StringPool::Id>;
    using start_id = TypedColumn<StackProfileCallsiteTable::Id>;
  };
  struct Row : public StackProfileCallsiteTable::Row {
    Row(uint32_t in_depth = {},
        std::optional<ExperimentalAnnotatedCallstackTable::Id> in_parent_id = {},
        StackProfileFrameTable::Id in_frame_id = {},
        StringPool::Id in_annotation = {},
        StackProfileCallsiteTable::Id in_start_id = {},
        std::nullptr_t = nullptr)
        : StackProfileCallsiteTable::Row(std::move(in_depth), std::move(in_parent_id), std::move(in_frame_id)),
          annotation(std::move(in_annotation)),
          start_id(std::move(in_start_id)) {
      type_ = "experimental_annotated_callstack";
    }
    StringPool::Id annotation;
    StackProfileCallsiteTable::Id start_id;

    bool operator==(const ExperimentalAnnotatedCallstackTable::Row& other) const {
      return type() == other.type() && ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::frame_id::Equals(frame_id, other.frame_id) &&
       ColumnType::annotation::Equals(annotation, other.annotation) &&
       ColumnType::start_id::Equals(start_id, other.start_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t annotation = ColumnType::annotation::default_flags();
    static constexpr uint32_t start_id = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::start_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ExperimentalAnnotatedCallstackTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExperimentalAnnotatedCallstackTable, RowNumber> {
   public:
    ConstRowReference(const ExperimentalAnnotatedCallstackTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::frame_id::type frame_id() const {
      return table_->frame_id()[row_number_];
    }
    ColumnType::annotation::type annotation() const {
      return table_->annotation()[row_number_];
    }
    ColumnType::start_id::type start_id() const {
      return table_->start_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExperimentalAnnotatedCallstackTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_frame_id(
        ColumnType::frame_id::non_optional_type v) {
      return mutable_table()->mutable_frame_id()->Set(row_number_, v);
    }
    void set_annotation(
        ColumnType::annotation::non_optional_type v) {
      return mutable_table()->mutable_annotation()->Set(row_number_, v);
    }
    void set_start_id(
        ColumnType::start_id::non_optional_type v) {
      return mutable_table()->mutable_start_id()->Set(row_number_, v);
    }

   private:
    ExperimentalAnnotatedCallstackTable* mutable_table() const {
      return const_cast<ExperimentalAnnotatedCallstackTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExperimentalAnnotatedCallstackTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::frame_id::type frame_id() const {
      const auto& col = table_->frame_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::annotation::type annotation() const {
      const auto& col = table_->annotation();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_id::type start_id() const {
      const auto& col = table_->start_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExperimentalAnnotatedCallstackTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExperimentalAnnotatedCallstackTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ExperimentalAnnotatedCallstackTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_frame_id(ColumnType::frame_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_frame_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_annotation(ColumnType::annotation::non_optional_type v) {
        auto* col = mutable_table_->mutable_annotation();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_id(ColumnType::start_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ExperimentalAnnotatedCallstackTable;

    explicit Iterator(ExperimentalAnnotatedCallstackTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExperimentalAnnotatedCallstackTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExperimentalAnnotatedCallstackTable(StringPool* pool, StackProfileCallsiteTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), annotation_(ColumnStorage<ColumnType::annotation::stored_type>::Create<false>()),
        start_id_(ColumnStorage<ColumnType::start_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::annotation::stored_type>(
          ColumnFlag::annotation),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("annotation", &annotation_, ColumnFlag::annotation,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ExperimentalAnnotatedCallstackTable() override;

  static const char* Name() { return "experimental_annotated_callstack"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "frame_id", ColumnType::frame_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "annotation", ColumnType::annotation::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_id", ColumnType::start_id::SqlValueType(), false,
        false,
        true,
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
    annotation_.ShrinkToFit();
    start_id_.ShrinkToFit();
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
    mutable_annotation()->Append(std::move(row.annotation));
    mutable_start_id()->Append(std::move(row.start_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const StackProfileCallsiteTable& parent,
      ColumnStorage<ColumnType::annotation::stored_type> annotation
, ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    return std::unique_ptr<Table>(new ExperimentalAnnotatedCallstackTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(annotation), std::move(start_id)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const StackProfileCallsiteTable& parent,
      std::vector<StackProfileCallsiteTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::annotation::stored_type> annotation
, ColumnStorage<ColumnType::start_id::stored_type> start_id) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ExperimentalAnnotatedCallstackTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(annotation), std::move(start_id)));
  }

  const IdColumn<ExperimentalAnnotatedCallstackTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<std::optional<ExperimentalAnnotatedCallstackTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<StackProfileFrameTable::Id>& frame_id() const {
    return static_cast<const ColumnType::frame_id&>(columns_[ColumnIndex::frame_id]);
  }
  const TypedColumn<StringPool::Id>& annotation() const {
    return static_cast<const ColumnType::annotation&>(columns_[ColumnIndex::annotation]);
  }
  const TypedColumn<StackProfileCallsiteTable::Id>& start_id() const {
    return static_cast<const ColumnType::start_id&>(columns_[ColumnIndex::start_id]);
  }

  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<std::optional<ExperimentalAnnotatedCallstackTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<StackProfileFrameTable::Id>* mutable_frame_id() {
    return static_cast<ColumnType::frame_id*>(
        &columns_[ColumnIndex::frame_id]);
  }
  TypedColumn<StringPool::Id>* mutable_annotation() {
    return static_cast<ColumnType::annotation*>(
        &columns_[ColumnIndex::annotation]);
  }
  TypedColumn<StackProfileCallsiteTable::Id>* mutable_start_id() {
    return static_cast<ColumnType::start_id*>(
        &columns_[ColumnIndex::start_id]);
  }

 private:
  ExperimentalAnnotatedCallstackTable(StringPool* pool,
            const StackProfileCallsiteTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::annotation::stored_type> annotation
, ColumnStorage<ColumnType::start_id::stored_type> start_id)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::annotation::stored_type>(
          ColumnFlag::annotation),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_id::stored_type>(
          ColumnFlag::start_id),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(annotation.size() == parent_overlay.size());
    annotation_ = std::move(annotation);
    PERFETTO_DCHECK(start_id.size() == parent_overlay.size());
    start_id_ = std::move(start_id);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("annotation", &annotation_, ColumnFlag::annotation,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("start_id", &start_id_, ColumnFlag::start_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  StackProfileCallsiteTable* parent_ = nullptr;
  ColumnStorage<ColumnType::annotation::stored_type> annotation_;
  ColumnStorage<ColumnType::start_id::stored_type> start_id_;
};
  

class ExperimentalCounterDurTable : public macros_internal::MacroTable {
 public:
  using Id = CounterTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t track_id = 3;
    static constexpr uint32_t value = 4;
    static constexpr uint32_t arg_set_id = 5;
    static constexpr uint32_t dur = 6;
    static constexpr uint32_t delta = 7;
  };
  struct ColumnType {
    using id = IdColumn<ExperimentalCounterDurTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using track_id = TypedColumn<CounterTrackTable::Id>;
    using value = TypedColumn<double>;
    using arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using dur = TypedColumn<int64_t>;
    using delta = TypedColumn<double>;
  };
  struct Row : public CounterTable::Row {
    Row(int64_t in_ts = {},
        CounterTrackTable::Id in_track_id = {},
        double in_value = {},
        std::optional<uint32_t> in_arg_set_id = {},
        int64_t in_dur = {},
        double in_delta = {},
        std::nullptr_t = nullptr)
        : CounterTable::Row(std::move(in_ts), std::move(in_track_id), std::move(in_value), std::move(in_arg_set_id)),
          dur(std::move(in_dur)),
          delta(std::move(in_delta)) {
      type_ = "experimental_counter_dur";
    }
    int64_t dur;
    double delta;

    bool operator==(const ExperimentalCounterDurTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::value::Equals(value, other.value) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::delta::Equals(delta, other.delta);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t dur = ColumnType::dur::default_flags();
    static constexpr uint32_t delta = ColumnType::delta::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ExperimentalCounterDurTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExperimentalCounterDurTable, RowNumber> {
   public:
    ConstRowReference(const ExperimentalCounterDurTable* table, uint32_t row_number)
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
    ColumnType::dur::type dur() const {
      return table_->dur()[row_number_];
    }
    ColumnType::delta::type delta() const {
      return table_->delta()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExperimentalCounterDurTable* table, uint32_t row_number)
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
    void set_dur(
        ColumnType::dur::non_optional_type v) {
      return mutable_table()->mutable_dur()->Set(row_number_, v);
    }
    void set_delta(
        ColumnType::delta::non_optional_type v) {
      return mutable_table()->mutable_delta()->Set(row_number_, v);
    }

   private:
    ExperimentalCounterDurTable* mutable_table() const {
      return const_cast<ExperimentalCounterDurTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExperimentalCounterDurTable, RowNumber, ConstRowReference> {
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
    ColumnType::dur::type dur() const {
      const auto& col = table_->dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::delta::type delta() const {
      const auto& col = table_->delta();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExperimentalCounterDurTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExperimentalCounterDurTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ExperimentalCounterDurTable, RowNumber, ConstRowReference>;
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
      void set_dur(ColumnType::dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_delta(ColumnType::delta::non_optional_type v) {
        auto* col = mutable_table_->mutable_delta();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ExperimentalCounterDurTable;

    explicit Iterator(ExperimentalCounterDurTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExperimentalCounterDurTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExperimentalCounterDurTable(StringPool* pool, CounterTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), dur_(ColumnStorage<ColumnType::dur::stored_type>::Create<false>()),
        delta_(ColumnStorage<ColumnType::delta::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::dur::stored_type>(
          ColumnFlag::dur),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::delta::stored_type>(
          ColumnFlag::delta),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("dur", &dur_, ColumnFlag::dur,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("delta", &delta_, ColumnFlag::delta,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ExperimentalCounterDurTable() override;

  static const char* Name() { return "experimental_counter_dur"; }

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
    schema.columns.emplace_back(Table::Schema::Column{
        "dur", ColumnType::dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "delta", ColumnType::delta::SqlValueType(), false,
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
    dur_.ShrinkToFit();
    delta_.ShrinkToFit();
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
    mutable_dur()->Append(std::move(row.dur));
    mutable_delta()->Append(std::move(row.delta));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const CounterTable& parent,
      ColumnStorage<ColumnType::dur::stored_type> dur
, ColumnStorage<ColumnType::delta::stored_type> delta) {
    return std::unique_ptr<Table>(new ExperimentalCounterDurTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(dur), std::move(delta)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const CounterTable& parent,
      std::vector<CounterTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::dur::stored_type> dur
, ColumnStorage<ColumnType::delta::stored_type> delta) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ExperimentalCounterDurTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(dur), std::move(delta)));
  }

  const IdColumn<ExperimentalCounterDurTable::Id>& id() const {
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
  const TypedColumn<int64_t>& dur() const {
    return static_cast<const ColumnType::dur&>(columns_[ColumnIndex::dur]);
  }
  const TypedColumn<double>& delta() const {
    return static_cast<const ColumnType::delta&>(columns_[ColumnIndex::delta]);
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
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<double>* mutable_delta() {
    return static_cast<ColumnType::delta*>(
        &columns_[ColumnIndex::delta]);
  }

 private:
  ExperimentalCounterDurTable(StringPool* pool,
            const CounterTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::dur::stored_type> dur
, ColumnStorage<ColumnType::delta::stored_type> delta)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::dur::stored_type>(
          ColumnFlag::dur),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::delta::stored_type>(
          ColumnFlag::delta),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(dur.size() == parent_overlay.size());
    dur_ = std::move(dur);
    PERFETTO_DCHECK(delta.size() == parent_overlay.size());
    delta_ = std::move(delta);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("dur", &dur_, ColumnFlag::dur,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("delta", &delta_, ColumnFlag::delta,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  CounterTable* parent_ = nullptr;
  ColumnStorage<ColumnType::dur::stored_type> dur_;
  ColumnStorage<ColumnType::delta::stored_type> delta_;
};
  

class ExperimentalSchedUpidTable : public macros_internal::MacroTable {
 public:
  using Id = SchedSliceTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t cpu = 4;
    static constexpr uint32_t utid = 5;
    static constexpr uint32_t end_state = 6;
    static constexpr uint32_t priority = 7;
    static constexpr uint32_t upid = 8;
  };
  struct ColumnType {
    using id = IdColumn<ExperimentalSchedUpidTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using cpu = TypedColumn<uint32_t>;
    using utid = TypedColumn<uint32_t>;
    using end_state = TypedColumn<StringPool::Id>;
    using priority = TypedColumn<int32_t>;
    using upid = TypedColumn<std::optional<uint32_t>>;
  };
  struct Row : public SchedSliceTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        uint32_t in_cpu = {},
        uint32_t in_utid = {},
        StringPool::Id in_end_state = {},
        int32_t in_priority = {},
        std::optional<uint32_t> in_upid = {},
        std::nullptr_t = nullptr)
        : SchedSliceTable::Row(std::move(in_ts), std::move(in_dur), std::move(in_cpu), std::move(in_utid), std::move(in_end_state), std::move(in_priority)),
          upid(std::move(in_upid)) {
      type_ = "experimental_sched_upid";
    }
    std::optional<uint32_t> upid;

    bool operator==(const ExperimentalSchedUpidTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::cpu::Equals(cpu, other.cpu) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::end_state::Equals(end_state, other.end_state) &&
       ColumnType::priority::Equals(priority, other.priority) &&
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
      ExperimentalSchedUpidTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExperimentalSchedUpidTable, RowNumber> {
   public:
    ConstRowReference(const ExperimentalSchedUpidTable* table, uint32_t row_number)
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
    ColumnType::dur::type dur() const {
      return table_->dur()[row_number_];
    }
    ColumnType::cpu::type cpu() const {
      return table_->cpu()[row_number_];
    }
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
    ColumnType::end_state::type end_state() const {
      return table_->end_state()[row_number_];
    }
    ColumnType::priority::type priority() const {
      return table_->priority()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExperimentalSchedUpidTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_dur(
        ColumnType::dur::non_optional_type v) {
      return mutable_table()->mutable_dur()->Set(row_number_, v);
    }
    void set_cpu(
        ColumnType::cpu::non_optional_type v) {
      return mutable_table()->mutable_cpu()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }
    void set_end_state(
        ColumnType::end_state::non_optional_type v) {
      return mutable_table()->mutable_end_state()->Set(row_number_, v);
    }
    void set_priority(
        ColumnType::priority::non_optional_type v) {
      return mutable_table()->mutable_priority()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }

   private:
    ExperimentalSchedUpidTable* mutable_table() const {
      return const_cast<ExperimentalSchedUpidTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExperimentalSchedUpidTable, RowNumber, ConstRowReference> {
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
    ColumnType::dur::type dur() const {
      const auto& col = table_->dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cpu::type cpu() const {
      const auto& col = table_->cpu();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::utid::type utid() const {
      const auto& col = table_->utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::end_state::type end_state() const {
      const auto& col = table_->end_state();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::priority::type priority() const {
      const auto& col = table_->priority();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExperimentalSchedUpidTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExperimentalSchedUpidTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ExperimentalSchedUpidTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_dur(ColumnType::dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cpu(ColumnType::cpu::non_optional_type v) {
        auto* col = mutable_table_->mutable_cpu();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_utid(ColumnType::utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_end_state(ColumnType::end_state::non_optional_type v) {
        auto* col = mutable_table_->mutable_end_state();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_priority(ColumnType::priority::non_optional_type v) {
        auto* col = mutable_table_->mutable_priority();
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
    friend class ExperimentalSchedUpidTable;

    explicit Iterator(ExperimentalSchedUpidTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExperimentalSchedUpidTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExperimentalSchedUpidTable(StringPool* pool, SchedSliceTable* parent)
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
  ~ExperimentalSchedUpidTable() override;

  static const char* Name() { return "experimental_sched_upid"; }

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
        "dur", ColumnType::dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cpu", ColumnType::cpu::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "utid", ColumnType::utid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "end_state", ColumnType::end_state::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "priority", ColumnType::priority::SqlValueType(), false,
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
      const SchedSliceTable& parent,
      ColumnStorage<ColumnType::upid::stored_type> upid) {
    return std::unique_ptr<Table>(new ExperimentalSchedUpidTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(upid)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const SchedSliceTable& parent,
      std::vector<SchedSliceTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::upid::stored_type> upid) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ExperimentalSchedUpidTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(upid)));
  }

  const IdColumn<ExperimentalSchedUpidTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& dur() const {
    return static_cast<const ColumnType::dur&>(columns_[ColumnIndex::dur]);
  }
  const TypedColumn<uint32_t>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }
  const TypedColumn<StringPool::Id>& end_state() const {
    return static_cast<const ColumnType::end_state&>(columns_[ColumnIndex::end_state]);
  }
  const TypedColumn<int32_t>& priority() const {
    return static_cast<const ColumnType::priority&>(columns_[ColumnIndex::priority]);
  }
  const TypedColumn<std::optional<uint32_t>>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<uint32_t>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<StringPool::Id>* mutable_end_state() {
    return static_cast<ColumnType::end_state*>(
        &columns_[ColumnIndex::end_state]);
  }
  TypedColumn<int32_t>* mutable_priority() {
    return static_cast<ColumnType::priority*>(
        &columns_[ColumnIndex::priority]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }

 private:
  ExperimentalSchedUpidTable(StringPool* pool,
            const SchedSliceTable& parent,
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
  SchedSliceTable* parent_ = nullptr;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
};
  

class ExperimentalSliceLayoutTable : public macros_internal::MacroTable {
 public:
  using Id = SliceTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t track_id = 4;
    static constexpr uint32_t category = 5;
    static constexpr uint32_t name = 6;
    static constexpr uint32_t depth = 7;
    static constexpr uint32_t stack_id = 8;
    static constexpr uint32_t parent_stack_id = 9;
    static constexpr uint32_t parent_id = 10;
    static constexpr uint32_t arg_set_id = 11;
    static constexpr uint32_t thread_ts = 12;
    static constexpr uint32_t thread_dur = 13;
    static constexpr uint32_t thread_instruction_count = 14;
    static constexpr uint32_t thread_instruction_delta = 15;
    static constexpr uint32_t layout_depth = 16;
    static constexpr uint32_t filter_track_ids = 17;
  };
  struct ColumnType {
    using id = IdColumn<ExperimentalSliceLayoutTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using track_id = TypedColumn<TrackTable::Id>;
    using category = TypedColumn<std::optional<StringPool::Id>>;
    using name = TypedColumn<std::optional<StringPool::Id>>;
    using depth = TypedColumn<uint32_t>;
    using stack_id = TypedColumn<int64_t>;
    using parent_stack_id = TypedColumn<int64_t>;
    using parent_id = TypedColumn<std::optional<ExperimentalSliceLayoutTable::Id>>;
    using arg_set_id = TypedColumn<uint32_t>;
    using thread_ts = TypedColumn<std::optional<int64_t>>;
    using thread_dur = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_count = TypedColumn<std::optional<int64_t>>;
    using thread_instruction_delta = TypedColumn<std::optional<int64_t>>;
    using layout_depth = TypedColumn<uint32_t>;
    using filter_track_ids = TypedColumn<StringPool::Id>;
  };
  struct Row : public SliceTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        TrackTable::Id in_track_id = {},
        std::optional<StringPool::Id> in_category = {},
        std::optional<StringPool::Id> in_name = {},
        uint32_t in_depth = {},
        int64_t in_stack_id = {},
        int64_t in_parent_stack_id = {},
        std::optional<ExperimentalSliceLayoutTable::Id> in_parent_id = {},
        uint32_t in_arg_set_id = {},
        std::optional<int64_t> in_thread_ts = {},
        std::optional<int64_t> in_thread_dur = {},
        std::optional<int64_t> in_thread_instruction_count = {},
        std::optional<int64_t> in_thread_instruction_delta = {},
        uint32_t in_layout_depth = {},
        StringPool::Id in_filter_track_ids = {},
        std::nullptr_t = nullptr)
        : SliceTable::Row(std::move(in_ts), std::move(in_dur), std::move(in_track_id), std::move(in_category), std::move(in_name), std::move(in_depth), std::move(in_stack_id), std::move(in_parent_stack_id), std::move(in_parent_id), std::move(in_arg_set_id), std::move(in_thread_ts), std::move(in_thread_dur), std::move(in_thread_instruction_count), std::move(in_thread_instruction_delta)),
          layout_depth(std::move(in_layout_depth)),
          filter_track_ids(std::move(in_filter_track_ids)) {
      type_ = "experimental_slice_layout";
    }
    uint32_t layout_depth;
    StringPool::Id filter_track_ids;

    bool operator==(const ExperimentalSliceLayoutTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::category::Equals(category, other.category) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::stack_id::Equals(stack_id, other.stack_id) &&
       ColumnType::parent_stack_id::Equals(parent_stack_id, other.parent_stack_id) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::thread_ts::Equals(thread_ts, other.thread_ts) &&
       ColumnType::thread_dur::Equals(thread_dur, other.thread_dur) &&
       ColumnType::thread_instruction_count::Equals(thread_instruction_count, other.thread_instruction_count) &&
       ColumnType::thread_instruction_delta::Equals(thread_instruction_delta, other.thread_instruction_delta) &&
       ColumnType::layout_depth::Equals(layout_depth, other.layout_depth) &&
       ColumnType::filter_track_ids::Equals(filter_track_ids, other.filter_track_ids);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t layout_depth = ColumnType::layout_depth::default_flags();
    static constexpr uint32_t filter_track_ids = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::filter_track_ids::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ExperimentalSliceLayoutTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExperimentalSliceLayoutTable, RowNumber> {
   public:
    ConstRowReference(const ExperimentalSliceLayoutTable* table, uint32_t row_number)
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
    ColumnType::dur::type dur() const {
      return table_->dur()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
    ColumnType::category::type category() const {
      return table_->category()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::stack_id::type stack_id() const {
      return table_->stack_id()[row_number_];
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      return table_->parent_stack_id()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::thread_ts::type thread_ts() const {
      return table_->thread_ts()[row_number_];
    }
    ColumnType::thread_dur::type thread_dur() const {
      return table_->thread_dur()[row_number_];
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      return table_->thread_instruction_count()[row_number_];
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      return table_->thread_instruction_delta()[row_number_];
    }
    ColumnType::layout_depth::type layout_depth() const {
      return table_->layout_depth()[row_number_];
    }
    ColumnType::filter_track_ids::type filter_track_ids() const {
      return table_->filter_track_ids()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExperimentalSliceLayoutTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_dur(
        ColumnType::dur::non_optional_type v) {
      return mutable_table()->mutable_dur()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }
    void set_category(
        ColumnType::category::non_optional_type v) {
      return mutable_table()->mutable_category()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_stack_id(
        ColumnType::stack_id::non_optional_type v) {
      return mutable_table()->mutable_stack_id()->Set(row_number_, v);
    }
    void set_parent_stack_id(
        ColumnType::parent_stack_id::non_optional_type v) {
      return mutable_table()->mutable_parent_stack_id()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_thread_ts(
        ColumnType::thread_ts::non_optional_type v) {
      return mutable_table()->mutable_thread_ts()->Set(row_number_, v);
    }
    void set_thread_dur(
        ColumnType::thread_dur::non_optional_type v) {
      return mutable_table()->mutable_thread_dur()->Set(row_number_, v);
    }
    void set_thread_instruction_count(
        ColumnType::thread_instruction_count::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_count()->Set(row_number_, v);
    }
    void set_thread_instruction_delta(
        ColumnType::thread_instruction_delta::non_optional_type v) {
      return mutable_table()->mutable_thread_instruction_delta()->Set(row_number_, v);
    }
    void set_layout_depth(
        ColumnType::layout_depth::non_optional_type v) {
      return mutable_table()->mutable_layout_depth()->Set(row_number_, v);
    }
    void set_filter_track_ids(
        ColumnType::filter_track_ids::non_optional_type v) {
      return mutable_table()->mutable_filter_track_ids()->Set(row_number_, v);
    }

   private:
    ExperimentalSliceLayoutTable* mutable_table() const {
      return const_cast<ExperimentalSliceLayoutTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExperimentalSliceLayoutTable, RowNumber, ConstRowReference> {
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
    ColumnType::dur::type dur() const {
      const auto& col = table_->dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::category::type category() const {
      const auto& col = table_->category();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::stack_id::type stack_id() const {
      const auto& col = table_->stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_stack_id::type parent_stack_id() const {
      const auto& col = table_->parent_stack_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_ts::type thread_ts() const {
      const auto& col = table_->thread_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_dur::type thread_dur() const {
      const auto& col = table_->thread_dur();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_count::type thread_instruction_count() const {
      const auto& col = table_->thread_instruction_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::thread_instruction_delta::type thread_instruction_delta() const {
      const auto& col = table_->thread_instruction_delta();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::layout_depth::type layout_depth() const {
      const auto& col = table_->layout_depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::filter_track_ids::type filter_track_ids() const {
      const auto& col = table_->filter_track_ids();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExperimentalSliceLayoutTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExperimentalSliceLayoutTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ExperimentalSliceLayoutTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_dur(ColumnType::dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_category(ColumnType::category::non_optional_type v) {
        auto* col = mutable_table_->mutable_category();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_stack_id(ColumnType::stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_stack_id(ColumnType::parent_stack_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_stack_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_ts(ColumnType::thread_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_dur(ColumnType::thread_dur::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_dur();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_count(ColumnType::thread_instruction_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_instruction_delta(ColumnType::thread_instruction_delta::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_instruction_delta();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_layout_depth(ColumnType::layout_depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_layout_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_filter_track_ids(ColumnType::filter_track_ids::non_optional_type v) {
        auto* col = mutable_table_->mutable_filter_track_ids();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ExperimentalSliceLayoutTable;

    explicit Iterator(ExperimentalSliceLayoutTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExperimentalSliceLayoutTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExperimentalSliceLayoutTable(StringPool* pool, SliceTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), layout_depth_(ColumnStorage<ColumnType::layout_depth::stored_type>::Create<false>()),
        filter_track_ids_(ColumnStorage<ColumnType::filter_track_ids::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::layout_depth::stored_type>(
          ColumnFlag::layout_depth),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::filter_track_ids::stored_type>(
          ColumnFlag::filter_track_ids),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("layout_depth", &layout_depth_, ColumnFlag::layout_depth,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("filter_track_ids", &filter_track_ids_, ColumnFlag::filter_track_ids,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ExperimentalSliceLayoutTable() override;

  static const char* Name() { return "experimental_slice_layout"; }

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
        "dur", ColumnType::dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "category", ColumnType::category::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "stack_id", ColumnType::stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_stack_id", ColumnType::parent_stack_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_ts", ColumnType::thread_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_dur", ColumnType::thread_dur::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_count", ColumnType::thread_instruction_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "thread_instruction_delta", ColumnType::thread_instruction_delta::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "layout_depth", ColumnType::layout_depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "filter_track_ids", ColumnType::filter_track_ids::SqlValueType(), false,
        false,
        true,
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
    layout_depth_.ShrinkToFit();
    filter_track_ids_.ShrinkToFit();
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
    mutable_layout_depth()->Append(std::move(row.layout_depth));
    mutable_filter_track_ids()->Append(std::move(row.filter_track_ids));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const SliceTable& parent,
      ColumnStorage<ColumnType::layout_depth::stored_type> layout_depth
, ColumnStorage<ColumnType::filter_track_ids::stored_type> filter_track_ids) {
    return std::unique_ptr<Table>(new ExperimentalSliceLayoutTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(layout_depth), std::move(filter_track_ids)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const SliceTable& parent,
      std::vector<SliceTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::layout_depth::stored_type> layout_depth
, ColumnStorage<ColumnType::filter_track_ids::stored_type> filter_track_ids) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new ExperimentalSliceLayoutTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(layout_depth), std::move(filter_track_ids)));
  }

  const IdColumn<ExperimentalSliceLayoutTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& dur() const {
    return static_cast<const ColumnType::dur&>(columns_[ColumnIndex::dur]);
  }
  const TypedColumn<TrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& category() const {
    return static_cast<const ColumnType::category&>(columns_[ColumnIndex::category]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<int64_t>& stack_id() const {
    return static_cast<const ColumnType::stack_id&>(columns_[ColumnIndex::stack_id]);
  }
  const TypedColumn<int64_t>& parent_stack_id() const {
    return static_cast<const ColumnType::parent_stack_id&>(columns_[ColumnIndex::parent_stack_id]);
  }
  const TypedColumn<std::optional<ExperimentalSliceLayoutTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_ts() const {
    return static_cast<const ColumnType::thread_ts&>(columns_[ColumnIndex::thread_ts]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_dur() const {
    return static_cast<const ColumnType::thread_dur&>(columns_[ColumnIndex::thread_dur]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_count() const {
    return static_cast<const ColumnType::thread_instruction_count&>(columns_[ColumnIndex::thread_instruction_count]);
  }
  const TypedColumn<std::optional<int64_t>>& thread_instruction_delta() const {
    return static_cast<const ColumnType::thread_instruction_delta&>(columns_[ColumnIndex::thread_instruction_delta]);
  }
  const TypedColumn<uint32_t>& layout_depth() const {
    return static_cast<const ColumnType::layout_depth&>(columns_[ColumnIndex::layout_depth]);
  }
  const TypedColumn<StringPool::Id>& filter_track_ids() const {
    return static_cast<const ColumnType::filter_track_ids&>(columns_[ColumnIndex::filter_track_ids]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<TrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_category() {
    return static_cast<ColumnType::category*>(
        &columns_[ColumnIndex::category]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<int64_t>* mutable_stack_id() {
    return static_cast<ColumnType::stack_id*>(
        &columns_[ColumnIndex::stack_id]);
  }
  TypedColumn<int64_t>* mutable_parent_stack_id() {
    return static_cast<ColumnType::parent_stack_id*>(
        &columns_[ColumnIndex::parent_stack_id]);
  }
  TypedColumn<std::optional<ExperimentalSliceLayoutTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_ts() {
    return static_cast<ColumnType::thread_ts*>(
        &columns_[ColumnIndex::thread_ts]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_dur() {
    return static_cast<ColumnType::thread_dur*>(
        &columns_[ColumnIndex::thread_dur]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_count() {
    return static_cast<ColumnType::thread_instruction_count*>(
        &columns_[ColumnIndex::thread_instruction_count]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_thread_instruction_delta() {
    return static_cast<ColumnType::thread_instruction_delta*>(
        &columns_[ColumnIndex::thread_instruction_delta]);
  }
  TypedColumn<uint32_t>* mutable_layout_depth() {
    return static_cast<ColumnType::layout_depth*>(
        &columns_[ColumnIndex::layout_depth]);
  }
  TypedColumn<StringPool::Id>* mutable_filter_track_ids() {
    return static_cast<ColumnType::filter_track_ids*>(
        &columns_[ColumnIndex::filter_track_ids]);
  }

 private:
  ExperimentalSliceLayoutTable(StringPool* pool,
            const SliceTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::layout_depth::stored_type> layout_depth
, ColumnStorage<ColumnType::filter_track_ids::stored_type> filter_track_ids)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::layout_depth::stored_type>(
          ColumnFlag::layout_depth),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::filter_track_ids::stored_type>(
          ColumnFlag::filter_track_ids),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(layout_depth.size() == parent_overlay.size());
    layout_depth_ = std::move(layout_depth);
    PERFETTO_DCHECK(filter_track_ids.size() == parent_overlay.size());
    filter_track_ids_ = std::move(filter_track_ids);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("layout_depth", &layout_depth_, ColumnFlag::layout_depth,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("filter_track_ids", &filter_track_ids_, ColumnFlag::filter_track_ids,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  SliceTable* parent_ = nullptr;
  ColumnStorage<ColumnType::layout_depth::stored_type> layout_depth_;
  ColumnStorage<ColumnType::filter_track_ids::stored_type> filter_track_ids_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_PERFETTO_SQL_INTRINSICS_TABLE_FUNCTIONS_TABLES_PY_H_

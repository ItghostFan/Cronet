#ifndef SRC_TRACE_PROCESSOR_TABLES_SCHED_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_SCHED_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"



namespace perfetto {
namespace trace_processor {
namespace tables {

class SchedSliceTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t cpu = 4;
    static constexpr uint32_t utid = 5;
    static constexpr uint32_t end_state = 6;
    static constexpr uint32_t priority = 7;
  };
  struct ColumnType {
    using id = IdColumn<SchedSliceTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using cpu = TypedColumn<uint32_t>;
    using utid = TypedColumn<uint32_t>;
    using end_state = TypedColumn<StringPool::Id>;
    using priority = TypedColumn<int32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        uint32_t in_cpu = {},
        uint32_t in_utid = {},
        StringPool::Id in_end_state = {},
        int32_t in_priority = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          dur(std::move(in_dur)),
          cpu(std::move(in_cpu)),
          utid(std::move(in_utid)),
          end_state(std::move(in_end_state)),
          priority(std::move(in_priority)) {
      type_ = "sched_slice";
    }
    int64_t ts;
    int64_t dur;
    uint32_t cpu;
    uint32_t utid;
    StringPool::Id end_state;
    int32_t priority;

    bool operator==(const SchedSliceTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::cpu::Equals(cpu, other.cpu) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::end_state::Equals(end_state, other.end_state) &&
       ColumnType::priority::Equals(priority, other.priority);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::ts::default_flags();
    static constexpr uint32_t dur = ColumnType::dur::default_flags();
    static constexpr uint32_t cpu = ColumnType::cpu::default_flags();
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
    static constexpr uint32_t end_state = ColumnType::end_state::default_flags();
    static constexpr uint32_t priority = ColumnType::priority::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      SchedSliceTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    SchedSliceTable, RowNumber> {
   public:
    ConstRowReference(const SchedSliceTable* table, uint32_t row_number)
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
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const SchedSliceTable* table, uint32_t row_number)
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

   private:
    SchedSliceTable* mutable_table() const {
      return const_cast<SchedSliceTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, SchedSliceTable, RowNumber, ConstRowReference> {
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

   protected:
    explicit ConstIterator(const SchedSliceTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class SchedSliceTable;
    friend class AbstractConstIterator;
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

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class SchedSliceTable;

    explicit Iterator(SchedSliceTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    SchedSliceTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit SchedSliceTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        dur_(ColumnStorage<ColumnType::dur::stored_type>::Create<false>()),
        cpu_(ColumnStorage<ColumnType::cpu::stored_type>::Create<false>()),
        utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()),
        end_state_(ColumnStorage<ColumnType::end_state::stored_type>::Create<false>()),
        priority_(ColumnStorage<ColumnType::priority::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::dur::stored_type>(
          ColumnFlag::dur),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::end_state::stored_type>(
          ColumnFlag::end_state),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::priority::stored_type>(
          ColumnFlag::priority),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("dur", &dur_, ColumnFlag::dur,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("end_state", &end_state_, ColumnFlag::end_state,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("priority", &priority_, ColumnFlag::priority,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~SchedSliceTable() override;

  static const char* Name() { return "sched_slice"; }

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
    dur_.ShrinkToFit();
    cpu_.ShrinkToFit();
    utid_.ShrinkToFit();
    end_state_.ShrinkToFit();
    priority_.ShrinkToFit();
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
    mutable_dur()->Append(std::move(row.dur));
    mutable_cpu()->Append(std::move(row.cpu));
    mutable_utid()->Append(std::move(row.utid));
    mutable_end_state()->Append(std::move(row.end_state));
    mutable_priority()->Append(std::move(row.priority));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<SchedSliceTable::Id>& id() const {
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

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::dur::stored_type> dur_;
  ColumnStorage<ColumnType::cpu::stored_type> cpu_;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
  ColumnStorage<ColumnType::end_state::stored_type> end_state_;
  ColumnStorage<ColumnType::priority::stored_type> priority_;
};
  

class SpuriousSchedWakeupTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t thread_state_id = 3;
    static constexpr uint32_t irq_context = 4;
    static constexpr uint32_t utid = 5;
    static constexpr uint32_t waker_utid = 6;
  };
  struct ColumnType {
    using id = IdColumn<SpuriousSchedWakeupTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using thread_state_id = TypedColumn<int64_t>;
    using irq_context = TypedColumn<std::optional<uint32_t>>;
    using utid = TypedColumn<uint32_t>;
    using waker_utid = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_thread_state_id = {},
        std::optional<uint32_t> in_irq_context = {},
        uint32_t in_utid = {},
        uint32_t in_waker_utid = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          thread_state_id(std::move(in_thread_state_id)),
          irq_context(std::move(in_irq_context)),
          utid(std::move(in_utid)),
          waker_utid(std::move(in_waker_utid)) {
      type_ = "spurious_sched_wakeup";
    }
    int64_t ts;
    int64_t thread_state_id;
    std::optional<uint32_t> irq_context;
    uint32_t utid;
    uint32_t waker_utid;

    bool operator==(const SpuriousSchedWakeupTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::thread_state_id::Equals(thread_state_id, other.thread_state_id) &&
       ColumnType::irq_context::Equals(irq_context, other.irq_context) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::waker_utid::Equals(waker_utid, other.waker_utid);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::ts::default_flags();
    static constexpr uint32_t thread_state_id = ColumnType::thread_state_id::default_flags();
    static constexpr uint32_t irq_context = ColumnType::irq_context::default_flags();
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
    static constexpr uint32_t waker_utid = ColumnType::waker_utid::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      SpuriousSchedWakeupTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    SpuriousSchedWakeupTable, RowNumber> {
   public:
    ConstRowReference(const SpuriousSchedWakeupTable* table, uint32_t row_number)
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
    ColumnType::thread_state_id::type thread_state_id() const {
      return table_->thread_state_id()[row_number_];
    }
    ColumnType::irq_context::type irq_context() const {
      return table_->irq_context()[row_number_];
    }
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
    ColumnType::waker_utid::type waker_utid() const {
      return table_->waker_utid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const SpuriousSchedWakeupTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_thread_state_id(
        ColumnType::thread_state_id::non_optional_type v) {
      return mutable_table()->mutable_thread_state_id()->Set(row_number_, v);
    }
    void set_irq_context(
        ColumnType::irq_context::non_optional_type v) {
      return mutable_table()->mutable_irq_context()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }
    void set_waker_utid(
        ColumnType::waker_utid::non_optional_type v) {
      return mutable_table()->mutable_waker_utid()->Set(row_number_, v);
    }

   private:
    SpuriousSchedWakeupTable* mutable_table() const {
      return const_cast<SpuriousSchedWakeupTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, SpuriousSchedWakeupTable, RowNumber, ConstRowReference> {
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
    ColumnType::thread_state_id::type thread_state_id() const {
      const auto& col = table_->thread_state_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::irq_context::type irq_context() const {
      const auto& col = table_->irq_context();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::utid::type utid() const {
      const auto& col = table_->utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::waker_utid::type waker_utid() const {
      const auto& col = table_->waker_utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const SpuriousSchedWakeupTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class SpuriousSchedWakeupTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_thread_state_id(ColumnType::thread_state_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_thread_state_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_irq_context(ColumnType::irq_context::non_optional_type v) {
        auto* col = mutable_table_->mutable_irq_context();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_utid(ColumnType::utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_waker_utid(ColumnType::waker_utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_waker_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class SpuriousSchedWakeupTable;

    explicit Iterator(SpuriousSchedWakeupTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    SpuriousSchedWakeupTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit SpuriousSchedWakeupTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        thread_state_id_(ColumnStorage<ColumnType::thread_state_id::stored_type>::Create<false>()),
        irq_context_(ColumnStorage<ColumnType::irq_context::stored_type>::Create<false>()),
        utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()),
        waker_utid_(ColumnStorage<ColumnType::waker_utid::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::thread_state_id::stored_type>(
          ColumnFlag::thread_state_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::irq_context::stored_type>(
          ColumnFlag::irq_context),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::waker_utid::stored_type>(
          ColumnFlag::waker_utid),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("thread_state_id", &thread_state_id_, ColumnFlag::thread_state_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("irq_context", &irq_context_, ColumnFlag::irq_context,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("waker_utid", &waker_utid_, ColumnFlag::waker_utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~SpuriousSchedWakeupTable() override;

  static const char* Name() { return "spurious_sched_wakeup"; }

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
        "thread_state_id", ColumnType::thread_state_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "irq_context", ColumnType::irq_context::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "utid", ColumnType::utid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "waker_utid", ColumnType::waker_utid::SqlValueType(), false,
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
    thread_state_id_.ShrinkToFit();
    irq_context_.ShrinkToFit();
    utid_.ShrinkToFit();
    waker_utid_.ShrinkToFit();
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
    mutable_thread_state_id()->Append(std::move(row.thread_state_id));
    mutable_irq_context()->Append(std::move(row.irq_context));
    mutable_utid()->Append(std::move(row.utid));
    mutable_waker_utid()->Append(std::move(row.waker_utid));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<SpuriousSchedWakeupTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& thread_state_id() const {
    return static_cast<const ColumnType::thread_state_id&>(columns_[ColumnIndex::thread_state_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& irq_context() const {
    return static_cast<const ColumnType::irq_context&>(columns_[ColumnIndex::irq_context]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }
  const TypedColumn<uint32_t>& waker_utid() const {
    return static_cast<const ColumnType::waker_utid&>(columns_[ColumnIndex::waker_utid]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_thread_state_id() {
    return static_cast<ColumnType::thread_state_id*>(
        &columns_[ColumnIndex::thread_state_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_irq_context() {
    return static_cast<ColumnType::irq_context*>(
        &columns_[ColumnIndex::irq_context]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<uint32_t>* mutable_waker_utid() {
    return static_cast<ColumnType::waker_utid*>(
        &columns_[ColumnIndex::waker_utid]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::thread_state_id::stored_type> thread_state_id_;
  ColumnStorage<ColumnType::irq_context::stored_type> irq_context_;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
  ColumnStorage<ColumnType::waker_utid::stored_type> waker_utid_;
};
  

class ThreadStateTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t dur = 3;
    static constexpr uint32_t cpu = 4;
    static constexpr uint32_t utid = 5;
    static constexpr uint32_t state = 6;
    static constexpr uint32_t io_wait = 7;
    static constexpr uint32_t blocked_function = 8;
    static constexpr uint32_t waker_utid = 9;
    static constexpr uint32_t irq_context = 10;
  };
  struct ColumnType {
    using id = IdColumn<ThreadStateTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using dur = TypedColumn<int64_t>;
    using cpu = TypedColumn<std::optional<uint32_t>>;
    using utid = TypedColumn<uint32_t>;
    using state = TypedColumn<StringPool::Id>;
    using io_wait = TypedColumn<std::optional<uint32_t>>;
    using blocked_function = TypedColumn<std::optional<StringPool::Id>>;
    using waker_utid = TypedColumn<std::optional<uint32_t>>;
    using irq_context = TypedColumn<std::optional<uint32_t>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_dur = {},
        std::optional<uint32_t> in_cpu = {},
        uint32_t in_utid = {},
        StringPool::Id in_state = {},
        std::optional<uint32_t> in_io_wait = {},
        std::optional<StringPool::Id> in_blocked_function = {},
        std::optional<uint32_t> in_waker_utid = {},
        std::optional<uint32_t> in_irq_context = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          dur(std::move(in_dur)),
          cpu(std::move(in_cpu)),
          utid(std::move(in_utid)),
          state(std::move(in_state)),
          io_wait(std::move(in_io_wait)),
          blocked_function(std::move(in_blocked_function)),
          waker_utid(std::move(in_waker_utid)),
          irq_context(std::move(in_irq_context)) {
      type_ = "thread_state";
    }
    int64_t ts;
    int64_t dur;
    std::optional<uint32_t> cpu;
    uint32_t utid;
    StringPool::Id state;
    std::optional<uint32_t> io_wait;
    std::optional<StringPool::Id> blocked_function;
    std::optional<uint32_t> waker_utid;
    std::optional<uint32_t> irq_context;

    bool operator==(const ThreadStateTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::dur::Equals(dur, other.dur) &&
       ColumnType::cpu::Equals(cpu, other.cpu) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::state::Equals(state, other.state) &&
       ColumnType::io_wait::Equals(io_wait, other.io_wait) &&
       ColumnType::blocked_function::Equals(blocked_function, other.blocked_function) &&
       ColumnType::waker_utid::Equals(waker_utid, other.waker_utid) &&
       ColumnType::irq_context::Equals(irq_context, other.irq_context);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::ts::default_flags();
    static constexpr uint32_t dur = ColumnType::dur::default_flags();
    static constexpr uint32_t cpu = ColumnType::cpu::default_flags();
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
    static constexpr uint32_t state = ColumnType::state::default_flags();
    static constexpr uint32_t io_wait = ColumnType::io_wait::default_flags();
    static constexpr uint32_t blocked_function = ColumnType::blocked_function::default_flags();
    static constexpr uint32_t waker_utid = ColumnType::waker_utid::default_flags();
    static constexpr uint32_t irq_context = ColumnType::irq_context::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ThreadStateTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ThreadStateTable, RowNumber> {
   public:
    ConstRowReference(const ThreadStateTable* table, uint32_t row_number)
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
    ColumnType::state::type state() const {
      return table_->state()[row_number_];
    }
    ColumnType::io_wait::type io_wait() const {
      return table_->io_wait()[row_number_];
    }
    ColumnType::blocked_function::type blocked_function() const {
      return table_->blocked_function()[row_number_];
    }
    ColumnType::waker_utid::type waker_utid() const {
      return table_->waker_utid()[row_number_];
    }
    ColumnType::irq_context::type irq_context() const {
      return table_->irq_context()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ThreadStateTable* table, uint32_t row_number)
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
    void set_state(
        ColumnType::state::non_optional_type v) {
      return mutable_table()->mutable_state()->Set(row_number_, v);
    }
    void set_io_wait(
        ColumnType::io_wait::non_optional_type v) {
      return mutable_table()->mutable_io_wait()->Set(row_number_, v);
    }
    void set_blocked_function(
        ColumnType::blocked_function::non_optional_type v) {
      return mutable_table()->mutable_blocked_function()->Set(row_number_, v);
    }
    void set_waker_utid(
        ColumnType::waker_utid::non_optional_type v) {
      return mutable_table()->mutable_waker_utid()->Set(row_number_, v);
    }
    void set_irq_context(
        ColumnType::irq_context::non_optional_type v) {
      return mutable_table()->mutable_irq_context()->Set(row_number_, v);
    }

   private:
    ThreadStateTable* mutable_table() const {
      return const_cast<ThreadStateTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ThreadStateTable, RowNumber, ConstRowReference> {
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
    ColumnType::state::type state() const {
      const auto& col = table_->state();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::io_wait::type io_wait() const {
      const auto& col = table_->io_wait();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::blocked_function::type blocked_function() const {
      const auto& col = table_->blocked_function();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::waker_utid::type waker_utid() const {
      const auto& col = table_->waker_utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::irq_context::type irq_context() const {
      const auto& col = table_->irq_context();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ThreadStateTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ThreadStateTable;
    friend class AbstractConstIterator;
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
      void set_state(ColumnType::state::non_optional_type v) {
        auto* col = mutable_table_->mutable_state();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_io_wait(ColumnType::io_wait::non_optional_type v) {
        auto* col = mutable_table_->mutable_io_wait();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_blocked_function(ColumnType::blocked_function::non_optional_type v) {
        auto* col = mutable_table_->mutable_blocked_function();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_waker_utid(ColumnType::waker_utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_waker_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_irq_context(ColumnType::irq_context::non_optional_type v) {
        auto* col = mutable_table_->mutable_irq_context();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ThreadStateTable;

    explicit Iterator(ThreadStateTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ThreadStateTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ThreadStateTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        dur_(ColumnStorage<ColumnType::dur::stored_type>::Create<false>()),
        cpu_(ColumnStorage<ColumnType::cpu::stored_type>::Create<false>()),
        utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()),
        state_(ColumnStorage<ColumnType::state::stored_type>::Create<false>()),
        io_wait_(ColumnStorage<ColumnType::io_wait::stored_type>::Create<false>()),
        blocked_function_(ColumnStorage<ColumnType::blocked_function::stored_type>::Create<false>()),
        waker_utid_(ColumnStorage<ColumnType::waker_utid::stored_type>::Create<false>()),
        irq_context_(ColumnStorage<ColumnType::irq_context::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::dur::stored_type>(
          ColumnFlag::dur),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::state::stored_type>(
          ColumnFlag::state),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::io_wait::stored_type>(
          ColumnFlag::io_wait),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::blocked_function::stored_type>(
          ColumnFlag::blocked_function),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::waker_utid::stored_type>(
          ColumnFlag::waker_utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::irq_context::stored_type>(
          ColumnFlag::irq_context),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("dur", &dur_, ColumnFlag::dur,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("state", &state_, ColumnFlag::state,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("io_wait", &io_wait_, ColumnFlag::io_wait,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("blocked_function", &blocked_function_, ColumnFlag::blocked_function,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("waker_utid", &waker_utid_, ColumnFlag::waker_utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("irq_context", &irq_context_, ColumnFlag::irq_context,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ThreadStateTable() override;

  static const char* Name() { return "thread_state"; }

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
        "state", ColumnType::state::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "io_wait", ColumnType::io_wait::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "blocked_function", ColumnType::blocked_function::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "waker_utid", ColumnType::waker_utid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "irq_context", ColumnType::irq_context::SqlValueType(), false,
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
    dur_.ShrinkToFit();
    cpu_.ShrinkToFit();
    utid_.ShrinkToFit();
    state_.ShrinkToFit();
    io_wait_.ShrinkToFit();
    blocked_function_.ShrinkToFit();
    waker_utid_.ShrinkToFit();
    irq_context_.ShrinkToFit();
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
    mutable_dur()->Append(std::move(row.dur));
    mutable_cpu()->Append(std::move(row.cpu));
    mutable_utid()->Append(std::move(row.utid));
    mutable_state()->Append(std::move(row.state));
    mutable_io_wait()->Append(std::move(row.io_wait));
    mutable_blocked_function()->Append(std::move(row.blocked_function));
    mutable_waker_utid()->Append(std::move(row.waker_utid));
    mutable_irq_context()->Append(std::move(row.irq_context));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ThreadStateTable::Id>& id() const {
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
  const TypedColumn<std::optional<uint32_t>>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }
  const TypedColumn<StringPool::Id>& state() const {
    return static_cast<const ColumnType::state&>(columns_[ColumnIndex::state]);
  }
  const TypedColumn<std::optional<uint32_t>>& io_wait() const {
    return static_cast<const ColumnType::io_wait&>(columns_[ColumnIndex::io_wait]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& blocked_function() const {
    return static_cast<const ColumnType::blocked_function&>(columns_[ColumnIndex::blocked_function]);
  }
  const TypedColumn<std::optional<uint32_t>>& waker_utid() const {
    return static_cast<const ColumnType::waker_utid&>(columns_[ColumnIndex::waker_utid]);
  }
  const TypedColumn<std::optional<uint32_t>>& irq_context() const {
    return static_cast<const ColumnType::irq_context&>(columns_[ColumnIndex::irq_context]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_dur() {
    return static_cast<ColumnType::dur*>(
        &columns_[ColumnIndex::dur]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<StringPool::Id>* mutable_state() {
    return static_cast<ColumnType::state*>(
        &columns_[ColumnIndex::state]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_io_wait() {
    return static_cast<ColumnType::io_wait*>(
        &columns_[ColumnIndex::io_wait]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_blocked_function() {
    return static_cast<ColumnType::blocked_function*>(
        &columns_[ColumnIndex::blocked_function]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_waker_utid() {
    return static_cast<ColumnType::waker_utid*>(
        &columns_[ColumnIndex::waker_utid]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_irq_context() {
    return static_cast<ColumnType::irq_context*>(
        &columns_[ColumnIndex::irq_context]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::dur::stored_type> dur_;
  ColumnStorage<ColumnType::cpu::stored_type> cpu_;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
  ColumnStorage<ColumnType::state::stored_type> state_;
  ColumnStorage<ColumnType::io_wait::stored_type> io_wait_;
  ColumnStorage<ColumnType::blocked_function::stored_type> blocked_function_;
  ColumnStorage<ColumnType::waker_utid::stored_type> waker_utid_;
  ColumnStorage<ColumnType::irq_context::stored_type> irq_context_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_SCHED_TABLES_PY_H_

#ifndef SRC_TRACE_PROCESSOR_TABLES_MEMORY_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_MEMORY_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"

#include "src/trace_processor/tables/track_tables_py.h"

namespace perfetto {
namespace trace_processor {
namespace tables {

class MemorySnapshotTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t timestamp = 2;
    static constexpr uint32_t track_id = 3;
    static constexpr uint32_t detail_level = 4;
  };
  struct ColumnType {
    using id = IdColumn<MemorySnapshotTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using timestamp = TypedColumn<int64_t>;
    using track_id = TypedColumn<TrackTable::Id>;
    using detail_level = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_timestamp = {},
        TrackTable::Id in_track_id = {},
        StringPool::Id in_detail_level = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          timestamp(std::move(in_timestamp)),
          track_id(std::move(in_track_id)),
          detail_level(std::move(in_detail_level)) {
      type_ = "memory_snapshot";
    }
    int64_t timestamp;
    TrackTable::Id track_id;
    StringPool::Id detail_level;

    bool operator==(const MemorySnapshotTable::Row& other) const {
      return type() == other.type() && ColumnType::timestamp::Equals(timestamp, other.timestamp) &&
       ColumnType::track_id::Equals(track_id, other.track_id) &&
       ColumnType::detail_level::Equals(detail_level, other.detail_level);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t timestamp = ColumnType::timestamp::default_flags();
    static constexpr uint32_t track_id = ColumnType::track_id::default_flags();
    static constexpr uint32_t detail_level = ColumnType::detail_level::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      MemorySnapshotTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    MemorySnapshotTable, RowNumber> {
   public:
    ConstRowReference(const MemorySnapshotTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::timestamp::type timestamp() const {
      return table_->timestamp()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
    ColumnType::detail_level::type detail_level() const {
      return table_->detail_level()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const MemorySnapshotTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_timestamp(
        ColumnType::timestamp::non_optional_type v) {
      return mutable_table()->mutable_timestamp()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }
    void set_detail_level(
        ColumnType::detail_level::non_optional_type v) {
      return mutable_table()->mutable_detail_level()->Set(row_number_, v);
    }

   private:
    MemorySnapshotTable* mutable_table() const {
      return const_cast<MemorySnapshotTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, MemorySnapshotTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::timestamp::type timestamp() const {
      const auto& col = table_->timestamp();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::detail_level::type detail_level() const {
      const auto& col = table_->detail_level();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const MemorySnapshotTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class MemorySnapshotTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_timestamp(ColumnType::timestamp::non_optional_type v) {
        auto* col = mutable_table_->mutable_timestamp();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_detail_level(ColumnType::detail_level::non_optional_type v) {
        auto* col = mutable_table_->mutable_detail_level();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class MemorySnapshotTable;

    explicit Iterator(MemorySnapshotTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    MemorySnapshotTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit MemorySnapshotTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        timestamp_(ColumnStorage<ColumnType::timestamp::stored_type>::Create<false>()),
        track_id_(ColumnStorage<ColumnType::track_id::stored_type>::Create<false>()),
        detail_level_(ColumnStorage<ColumnType::detail_level::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::timestamp::stored_type>(
          ColumnFlag::timestamp),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::track_id::stored_type>(
          ColumnFlag::track_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::detail_level::stored_type>(
          ColumnFlag::detail_level),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("timestamp", &timestamp_, ColumnFlag::timestamp,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("track_id", &track_id_, ColumnFlag::track_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("detail_level", &detail_level_, ColumnFlag::detail_level,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~MemorySnapshotTable() override;

  static const char* Name() { return "memory_snapshot"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "timestamp", ColumnType::timestamp::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "detail_level", ColumnType::detail_level::SqlValueType(), false,
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
    timestamp_.ShrinkToFit();
    track_id_.ShrinkToFit();
    detail_level_.ShrinkToFit();
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
    mutable_timestamp()->Append(std::move(row.timestamp));
    mutable_track_id()->Append(std::move(row.track_id));
    mutable_detail_level()->Append(std::move(row.detail_level));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<MemorySnapshotTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& timestamp() const {
    return static_cast<const ColumnType::timestamp&>(columns_[ColumnIndex::timestamp]);
  }
  const TypedColumn<TrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }
  const TypedColumn<StringPool::Id>& detail_level() const {
    return static_cast<const ColumnType::detail_level&>(columns_[ColumnIndex::detail_level]);
  }

  TypedColumn<int64_t>* mutable_timestamp() {
    return static_cast<ColumnType::timestamp*>(
        &columns_[ColumnIndex::timestamp]);
  }
  TypedColumn<TrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }
  TypedColumn<StringPool::Id>* mutable_detail_level() {
    return static_cast<ColumnType::detail_level*>(
        &columns_[ColumnIndex::detail_level]);
  }

 private:
  
  
  ColumnStorage<ColumnType::timestamp::stored_type> timestamp_;
  ColumnStorage<ColumnType::track_id::stored_type> track_id_;
  ColumnStorage<ColumnType::detail_level::stored_type> detail_level_;
};
  

class ProcessMemorySnapshotTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t snapshot_id = 2;
    static constexpr uint32_t upid = 3;
  };
  struct ColumnType {
    using id = IdColumn<ProcessMemorySnapshotTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using snapshot_id = TypedColumn<MemorySnapshotTable::Id>;
    using upid = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(MemorySnapshotTable::Id in_snapshot_id = {},
        uint32_t in_upid = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          snapshot_id(std::move(in_snapshot_id)),
          upid(std::move(in_upid)) {
      type_ = "process_memory_snapshot";
    }
    MemorySnapshotTable::Id snapshot_id;
    uint32_t upid;

    bool operator==(const ProcessMemorySnapshotTable::Row& other) const {
      return type() == other.type() && ColumnType::snapshot_id::Equals(snapshot_id, other.snapshot_id) &&
       ColumnType::upid::Equals(upid, other.upid);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t snapshot_id = ColumnType::snapshot_id::default_flags();
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ProcessMemorySnapshotTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ProcessMemorySnapshotTable, RowNumber> {
   public:
    ConstRowReference(const ProcessMemorySnapshotTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::snapshot_id::type snapshot_id() const {
      return table_->snapshot_id()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ProcessMemorySnapshotTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_snapshot_id(
        ColumnType::snapshot_id::non_optional_type v) {
      return mutable_table()->mutable_snapshot_id()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }

   private:
    ProcessMemorySnapshotTable* mutable_table() const {
      return const_cast<ProcessMemorySnapshotTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ProcessMemorySnapshotTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::snapshot_id::type snapshot_id() const {
      const auto& col = table_->snapshot_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ProcessMemorySnapshotTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ProcessMemorySnapshotTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_snapshot_id(ColumnType::snapshot_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_snapshot_id();
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
    friend class ProcessMemorySnapshotTable;

    explicit Iterator(ProcessMemorySnapshotTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ProcessMemorySnapshotTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ProcessMemorySnapshotTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        snapshot_id_(ColumnStorage<ColumnType::snapshot_id::stored_type>::Create<false>()),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::snapshot_id::stored_type>(
          ColumnFlag::snapshot_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("snapshot_id", &snapshot_id_, ColumnFlag::snapshot_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ProcessMemorySnapshotTable() override;

  static const char* Name() { return "process_memory_snapshot"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "snapshot_id", ColumnType::snapshot_id::SqlValueType(), false,
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
    type_.ShrinkToFit();
    snapshot_id_.ShrinkToFit();
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
    Id id = Id{row_number};
    type_.Append(string_pool_->InternString(row.type()));
    mutable_snapshot_id()->Append(std::move(row.snapshot_id));
    mutable_upid()->Append(std::move(row.upid));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ProcessMemorySnapshotTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<MemorySnapshotTable::Id>& snapshot_id() const {
    return static_cast<const ColumnType::snapshot_id&>(columns_[ColumnIndex::snapshot_id]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }

  TypedColumn<MemorySnapshotTable::Id>* mutable_snapshot_id() {
    return static_cast<ColumnType::snapshot_id*>(
        &columns_[ColumnIndex::snapshot_id]);
  }
  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }

 private:
  
  
  ColumnStorage<ColumnType::snapshot_id::stored_type> snapshot_id_;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
};
  

class MemorySnapshotNodeTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t process_snapshot_id = 2;
    static constexpr uint32_t parent_node_id = 3;
    static constexpr uint32_t path = 4;
    static constexpr uint32_t size = 5;
    static constexpr uint32_t effective_size = 6;
    static constexpr uint32_t arg_set_id = 7;
  };
  struct ColumnType {
    using id = IdColumn<MemorySnapshotNodeTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using process_snapshot_id = TypedColumn<ProcessMemorySnapshotTable::Id>;
    using parent_node_id = TypedColumn<std::optional<MemorySnapshotNodeTable::Id>>;
    using path = TypedColumn<StringPool::Id>;
    using size = TypedColumn<int64_t>;
    using effective_size = TypedColumn<int64_t>;
    using arg_set_id = TypedColumn<std::optional<uint32_t>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(ProcessMemorySnapshotTable::Id in_process_snapshot_id = {},
        std::optional<MemorySnapshotNodeTable::Id> in_parent_node_id = {},
        StringPool::Id in_path = {},
        int64_t in_size = {},
        int64_t in_effective_size = {},
        std::optional<uint32_t> in_arg_set_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          process_snapshot_id(std::move(in_process_snapshot_id)),
          parent_node_id(std::move(in_parent_node_id)),
          path(std::move(in_path)),
          size(std::move(in_size)),
          effective_size(std::move(in_effective_size)),
          arg_set_id(std::move(in_arg_set_id)) {
      type_ = "memory_snapshot_node";
    }
    ProcessMemorySnapshotTable::Id process_snapshot_id;
    std::optional<MemorySnapshotNodeTable::Id> parent_node_id;
    StringPool::Id path;
    int64_t size;
    int64_t effective_size;
    std::optional<uint32_t> arg_set_id;

    bool operator==(const MemorySnapshotNodeTable::Row& other) const {
      return type() == other.type() && ColumnType::process_snapshot_id::Equals(process_snapshot_id, other.process_snapshot_id) &&
       ColumnType::parent_node_id::Equals(parent_node_id, other.parent_node_id) &&
       ColumnType::path::Equals(path, other.path) &&
       ColumnType::size::Equals(size, other.size) &&
       ColumnType::effective_size::Equals(effective_size, other.effective_size) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t process_snapshot_id = ColumnType::process_snapshot_id::default_flags();
    static constexpr uint32_t parent_node_id = ColumnType::parent_node_id::default_flags();
    static constexpr uint32_t path = ColumnType::path::default_flags();
    static constexpr uint32_t size = ColumnType::size::default_flags();
    static constexpr uint32_t effective_size = ColumnType::effective_size::default_flags();
    static constexpr uint32_t arg_set_id = ColumnType::arg_set_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      MemorySnapshotNodeTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    MemorySnapshotNodeTable, RowNumber> {
   public:
    ConstRowReference(const MemorySnapshotNodeTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::process_snapshot_id::type process_snapshot_id() const {
      return table_->process_snapshot_id()[row_number_];
    }
    ColumnType::parent_node_id::type parent_node_id() const {
      return table_->parent_node_id()[row_number_];
    }
    ColumnType::path::type path() const {
      return table_->path()[row_number_];
    }
    ColumnType::size::type size() const {
      return table_->size()[row_number_];
    }
    ColumnType::effective_size::type effective_size() const {
      return table_->effective_size()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const MemorySnapshotNodeTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_process_snapshot_id(
        ColumnType::process_snapshot_id::non_optional_type v) {
      return mutable_table()->mutable_process_snapshot_id()->Set(row_number_, v);
    }
    void set_parent_node_id(
        ColumnType::parent_node_id::non_optional_type v) {
      return mutable_table()->mutable_parent_node_id()->Set(row_number_, v);
    }
    void set_path(
        ColumnType::path::non_optional_type v) {
      return mutable_table()->mutable_path()->Set(row_number_, v);
    }
    void set_size(
        ColumnType::size::non_optional_type v) {
      return mutable_table()->mutable_size()->Set(row_number_, v);
    }
    void set_effective_size(
        ColumnType::effective_size::non_optional_type v) {
      return mutable_table()->mutable_effective_size()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }

   private:
    MemorySnapshotNodeTable* mutable_table() const {
      return const_cast<MemorySnapshotNodeTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, MemorySnapshotNodeTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::process_snapshot_id::type process_snapshot_id() const {
      const auto& col = table_->process_snapshot_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_node_id::type parent_node_id() const {
      const auto& col = table_->parent_node_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::path::type path() const {
      const auto& col = table_->path();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::size::type size() const {
      const auto& col = table_->size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::effective_size::type effective_size() const {
      const auto& col = table_->effective_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const MemorySnapshotNodeTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class MemorySnapshotNodeTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_process_snapshot_id(ColumnType::process_snapshot_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_process_snapshot_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_node_id(ColumnType::parent_node_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_node_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_path(ColumnType::path::non_optional_type v) {
        auto* col = mutable_table_->mutable_path();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_size(ColumnType::size::non_optional_type v) {
        auto* col = mutable_table_->mutable_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_effective_size(ColumnType::effective_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_effective_size();
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
    friend class MemorySnapshotNodeTable;

    explicit Iterator(MemorySnapshotNodeTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    MemorySnapshotNodeTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit MemorySnapshotNodeTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        process_snapshot_id_(ColumnStorage<ColumnType::process_snapshot_id::stored_type>::Create<false>()),
        parent_node_id_(ColumnStorage<ColumnType::parent_node_id::stored_type>::Create<false>()),
        path_(ColumnStorage<ColumnType::path::stored_type>::Create<false>()),
        size_(ColumnStorage<ColumnType::size::stored_type>::Create<false>()),
        effective_size_(ColumnStorage<ColumnType::effective_size::stored_type>::Create<false>()),
        arg_set_id_(ColumnStorage<ColumnType::arg_set_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::process_snapshot_id::stored_type>(
          ColumnFlag::process_snapshot_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::parent_node_id::stored_type>(
          ColumnFlag::parent_node_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::path::stored_type>(
          ColumnFlag::path),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::size::stored_type>(
          ColumnFlag::size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::effective_size::stored_type>(
          ColumnFlag::effective_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::arg_set_id::stored_type>(
          ColumnFlag::arg_set_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("process_snapshot_id", &process_snapshot_id_, ColumnFlag::process_snapshot_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("parent_node_id", &parent_node_id_, ColumnFlag::parent_node_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("path", &path_, ColumnFlag::path,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("size", &size_, ColumnFlag::size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("effective_size", &effective_size_, ColumnFlag::effective_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("arg_set_id", &arg_set_id_, ColumnFlag::arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~MemorySnapshotNodeTable() override;

  static const char* Name() { return "memory_snapshot_node"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "process_snapshot_id", ColumnType::process_snapshot_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_node_id", ColumnType::parent_node_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "path", ColumnType::path::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "size", ColumnType::size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "effective_size", ColumnType::effective_size::SqlValueType(), false,
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
    process_snapshot_id_.ShrinkToFit();
    parent_node_id_.ShrinkToFit();
    path_.ShrinkToFit();
    size_.ShrinkToFit();
    effective_size_.ShrinkToFit();
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
    mutable_process_snapshot_id()->Append(std::move(row.process_snapshot_id));
    mutable_parent_node_id()->Append(std::move(row.parent_node_id));
    mutable_path()->Append(std::move(row.path));
    mutable_size()->Append(std::move(row.size));
    mutable_effective_size()->Append(std::move(row.effective_size));
    mutable_arg_set_id()->Append(std::move(row.arg_set_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<MemorySnapshotNodeTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<ProcessMemorySnapshotTable::Id>& process_snapshot_id() const {
    return static_cast<const ColumnType::process_snapshot_id&>(columns_[ColumnIndex::process_snapshot_id]);
  }
  const TypedColumn<std::optional<MemorySnapshotNodeTable::Id>>& parent_node_id() const {
    return static_cast<const ColumnType::parent_node_id&>(columns_[ColumnIndex::parent_node_id]);
  }
  const TypedColumn<StringPool::Id>& path() const {
    return static_cast<const ColumnType::path&>(columns_[ColumnIndex::path]);
  }
  const TypedColumn<int64_t>& size() const {
    return static_cast<const ColumnType::size&>(columns_[ColumnIndex::size]);
  }
  const TypedColumn<int64_t>& effective_size() const {
    return static_cast<const ColumnType::effective_size&>(columns_[ColumnIndex::effective_size]);
  }
  const TypedColumn<std::optional<uint32_t>>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }

  TypedColumn<ProcessMemorySnapshotTable::Id>* mutable_process_snapshot_id() {
    return static_cast<ColumnType::process_snapshot_id*>(
        &columns_[ColumnIndex::process_snapshot_id]);
  }
  TypedColumn<std::optional<MemorySnapshotNodeTable::Id>>* mutable_parent_node_id() {
    return static_cast<ColumnType::parent_node_id*>(
        &columns_[ColumnIndex::parent_node_id]);
  }
  TypedColumn<StringPool::Id>* mutable_path() {
    return static_cast<ColumnType::path*>(
        &columns_[ColumnIndex::path]);
  }
  TypedColumn<int64_t>* mutable_size() {
    return static_cast<ColumnType::size*>(
        &columns_[ColumnIndex::size]);
  }
  TypedColumn<int64_t>* mutable_effective_size() {
    return static_cast<ColumnType::effective_size*>(
        &columns_[ColumnIndex::effective_size]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::process_snapshot_id::stored_type> process_snapshot_id_;
  ColumnStorage<ColumnType::parent_node_id::stored_type> parent_node_id_;
  ColumnStorage<ColumnType::path::stored_type> path_;
  ColumnStorage<ColumnType::size::stored_type> size_;
  ColumnStorage<ColumnType::effective_size::stored_type> effective_size_;
  ColumnStorage<ColumnType::arg_set_id::stored_type> arg_set_id_;
};
  

class MemorySnapshotEdgeTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t source_node_id = 2;
    static constexpr uint32_t target_node_id = 3;
    static constexpr uint32_t importance = 4;
  };
  struct ColumnType {
    using id = IdColumn<MemorySnapshotEdgeTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using source_node_id = TypedColumn<MemorySnapshotNodeTable::Id>;
    using target_node_id = TypedColumn<MemorySnapshotNodeTable::Id>;
    using importance = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(MemorySnapshotNodeTable::Id in_source_node_id = {},
        MemorySnapshotNodeTable::Id in_target_node_id = {},
        uint32_t in_importance = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          source_node_id(std::move(in_source_node_id)),
          target_node_id(std::move(in_target_node_id)),
          importance(std::move(in_importance)) {
      type_ = "memory_snapshot_edge";
    }
    MemorySnapshotNodeTable::Id source_node_id;
    MemorySnapshotNodeTable::Id target_node_id;
    uint32_t importance;

    bool operator==(const MemorySnapshotEdgeTable::Row& other) const {
      return type() == other.type() && ColumnType::source_node_id::Equals(source_node_id, other.source_node_id) &&
       ColumnType::target_node_id::Equals(target_node_id, other.target_node_id) &&
       ColumnType::importance::Equals(importance, other.importance);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t source_node_id = ColumnType::source_node_id::default_flags();
    static constexpr uint32_t target_node_id = ColumnType::target_node_id::default_flags();
    static constexpr uint32_t importance = ColumnType::importance::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      MemorySnapshotEdgeTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    MemorySnapshotEdgeTable, RowNumber> {
   public:
    ConstRowReference(const MemorySnapshotEdgeTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::source_node_id::type source_node_id() const {
      return table_->source_node_id()[row_number_];
    }
    ColumnType::target_node_id::type target_node_id() const {
      return table_->target_node_id()[row_number_];
    }
    ColumnType::importance::type importance() const {
      return table_->importance()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const MemorySnapshotEdgeTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_source_node_id(
        ColumnType::source_node_id::non_optional_type v) {
      return mutable_table()->mutable_source_node_id()->Set(row_number_, v);
    }
    void set_target_node_id(
        ColumnType::target_node_id::non_optional_type v) {
      return mutable_table()->mutable_target_node_id()->Set(row_number_, v);
    }
    void set_importance(
        ColumnType::importance::non_optional_type v) {
      return mutable_table()->mutable_importance()->Set(row_number_, v);
    }

   private:
    MemorySnapshotEdgeTable* mutable_table() const {
      return const_cast<MemorySnapshotEdgeTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, MemorySnapshotEdgeTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_node_id::type source_node_id() const {
      const auto& col = table_->source_node_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::target_node_id::type target_node_id() const {
      const auto& col = table_->target_node_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::importance::type importance() const {
      const auto& col = table_->importance();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const MemorySnapshotEdgeTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class MemorySnapshotEdgeTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_source_node_id(ColumnType::source_node_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_node_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_target_node_id(ColumnType::target_node_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_target_node_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_importance(ColumnType::importance::non_optional_type v) {
        auto* col = mutable_table_->mutable_importance();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class MemorySnapshotEdgeTable;

    explicit Iterator(MemorySnapshotEdgeTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    MemorySnapshotEdgeTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit MemorySnapshotEdgeTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        source_node_id_(ColumnStorage<ColumnType::source_node_id::stored_type>::Create<false>()),
        target_node_id_(ColumnStorage<ColumnType::target_node_id::stored_type>::Create<false>()),
        importance_(ColumnStorage<ColumnType::importance::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::source_node_id::stored_type>(
          ColumnFlag::source_node_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::target_node_id::stored_type>(
          ColumnFlag::target_node_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::importance::stored_type>(
          ColumnFlag::importance),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("source_node_id", &source_node_id_, ColumnFlag::source_node_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("target_node_id", &target_node_id_, ColumnFlag::target_node_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("importance", &importance_, ColumnFlag::importance,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~MemorySnapshotEdgeTable() override;

  static const char* Name() { return "memory_snapshot_edge"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_node_id", ColumnType::source_node_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "target_node_id", ColumnType::target_node_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "importance", ColumnType::importance::SqlValueType(), false,
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
    source_node_id_.ShrinkToFit();
    target_node_id_.ShrinkToFit();
    importance_.ShrinkToFit();
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
    mutable_source_node_id()->Append(std::move(row.source_node_id));
    mutable_target_node_id()->Append(std::move(row.target_node_id));
    mutable_importance()->Append(std::move(row.importance));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<MemorySnapshotEdgeTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<MemorySnapshotNodeTable::Id>& source_node_id() const {
    return static_cast<const ColumnType::source_node_id&>(columns_[ColumnIndex::source_node_id]);
  }
  const TypedColumn<MemorySnapshotNodeTable::Id>& target_node_id() const {
    return static_cast<const ColumnType::target_node_id&>(columns_[ColumnIndex::target_node_id]);
  }
  const TypedColumn<uint32_t>& importance() const {
    return static_cast<const ColumnType::importance&>(columns_[ColumnIndex::importance]);
  }

  TypedColumn<MemorySnapshotNodeTable::Id>* mutable_source_node_id() {
    return static_cast<ColumnType::source_node_id*>(
        &columns_[ColumnIndex::source_node_id]);
  }
  TypedColumn<MemorySnapshotNodeTable::Id>* mutable_target_node_id() {
    return static_cast<ColumnType::target_node_id*>(
        &columns_[ColumnIndex::target_node_id]);
  }
  TypedColumn<uint32_t>* mutable_importance() {
    return static_cast<ColumnType::importance*>(
        &columns_[ColumnIndex::importance]);
  }

 private:
  
  
  ColumnStorage<ColumnType::source_node_id::stored_type> source_node_id_;
  ColumnStorage<ColumnType::target_node_id::stored_type> target_node_id_;
  ColumnStorage<ColumnType::importance::stored_type> importance_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_MEMORY_TABLES_PY_H_

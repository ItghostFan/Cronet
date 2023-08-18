#ifndef SRC_TRACE_PROCESSOR_TABLES_METADATA_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_METADATA_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"



namespace perfetto {
namespace trace_processor {
namespace tables {

class ProcessTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t pid = 2;
    static constexpr uint32_t name = 3;
    static constexpr uint32_t start_ts = 4;
    static constexpr uint32_t end_ts = 5;
    static constexpr uint32_t parent_upid = 6;
    static constexpr uint32_t uid = 7;
    static constexpr uint32_t android_appid = 8;
    static constexpr uint32_t cmdline = 9;
    static constexpr uint32_t arg_set_id = 10;
  };
  struct ColumnType {
    using id = IdColumn<ProcessTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using pid = TypedColumn<uint32_t>;
    using name = TypedColumn<std::optional<StringPool::Id>>;
    using start_ts = TypedColumn<std::optional<int64_t>>;
    using end_ts = TypedColumn<std::optional<int64_t>>;
    using parent_upid = TypedColumn<std::optional<uint32_t>>;
    using uid = TypedColumn<std::optional<uint32_t>>;
    using android_appid = TypedColumn<std::optional<uint32_t>>;
    using cmdline = TypedColumn<std::optional<StringPool::Id>>;
    using arg_set_id = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_pid = {},
        std::optional<StringPool::Id> in_name = {},
        std::optional<int64_t> in_start_ts = {},
        std::optional<int64_t> in_end_ts = {},
        std::optional<uint32_t> in_parent_upid = {},
        std::optional<uint32_t> in_uid = {},
        std::optional<uint32_t> in_android_appid = {},
        std::optional<StringPool::Id> in_cmdline = {},
        uint32_t in_arg_set_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          pid(std::move(in_pid)),
          name(std::move(in_name)),
          start_ts(std::move(in_start_ts)),
          end_ts(std::move(in_end_ts)),
          parent_upid(std::move(in_parent_upid)),
          uid(std::move(in_uid)),
          android_appid(std::move(in_android_appid)),
          cmdline(std::move(in_cmdline)),
          arg_set_id(std::move(in_arg_set_id)) {
      type_ = "internal_process";
    }
    uint32_t pid;
    std::optional<StringPool::Id> name;
    std::optional<int64_t> start_ts;
    std::optional<int64_t> end_ts;
    std::optional<uint32_t> parent_upid;
    std::optional<uint32_t> uid;
    std::optional<uint32_t> android_appid;
    std::optional<StringPool::Id> cmdline;
    uint32_t arg_set_id;

    bool operator==(const ProcessTable::Row& other) const {
      return type() == other.type() && ColumnType::pid::Equals(pid, other.pid) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::start_ts::Equals(start_ts, other.start_ts) &&
       ColumnType::end_ts::Equals(end_ts, other.end_ts) &&
       ColumnType::parent_upid::Equals(parent_upid, other.parent_upid) &&
       ColumnType::uid::Equals(uid, other.uid) &&
       ColumnType::android_appid::Equals(android_appid, other.android_appid) &&
       ColumnType::cmdline::Equals(cmdline, other.cmdline) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t pid = ColumnType::pid::default_flags();
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t start_ts = ColumnType::start_ts::default_flags();
    static constexpr uint32_t end_ts = ColumnType::end_ts::default_flags();
    static constexpr uint32_t parent_upid = ColumnType::parent_upid::default_flags();
    static constexpr uint32_t uid = ColumnType::uid::default_flags();
    static constexpr uint32_t android_appid = ColumnType::android_appid::default_flags();
    static constexpr uint32_t cmdline = ColumnType::cmdline::default_flags();
    static constexpr uint32_t arg_set_id = ColumnType::arg_set_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ProcessTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ProcessTable, RowNumber> {
   public:
    ConstRowReference(const ProcessTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::pid::type pid() const {
      return table_->pid()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::start_ts::type start_ts() const {
      return table_->start_ts()[row_number_];
    }
    ColumnType::end_ts::type end_ts() const {
      return table_->end_ts()[row_number_];
    }
    ColumnType::parent_upid::type parent_upid() const {
      return table_->parent_upid()[row_number_];
    }
    ColumnType::uid::type uid() const {
      return table_->uid()[row_number_];
    }
    ColumnType::android_appid::type android_appid() const {
      return table_->android_appid()[row_number_];
    }
    ColumnType::cmdline::type cmdline() const {
      return table_->cmdline()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ProcessTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_pid(
        ColumnType::pid::non_optional_type v) {
      return mutable_table()->mutable_pid()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_start_ts(
        ColumnType::start_ts::non_optional_type v) {
      return mutable_table()->mutable_start_ts()->Set(row_number_, v);
    }
    void set_end_ts(
        ColumnType::end_ts::non_optional_type v) {
      return mutable_table()->mutable_end_ts()->Set(row_number_, v);
    }
    void set_parent_upid(
        ColumnType::parent_upid::non_optional_type v) {
      return mutable_table()->mutable_parent_upid()->Set(row_number_, v);
    }
    void set_uid(
        ColumnType::uid::non_optional_type v) {
      return mutable_table()->mutable_uid()->Set(row_number_, v);
    }
    void set_android_appid(
        ColumnType::android_appid::non_optional_type v) {
      return mutable_table()->mutable_android_appid()->Set(row_number_, v);
    }
    void set_cmdline(
        ColumnType::cmdline::non_optional_type v) {
      return mutable_table()->mutable_cmdline()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }

   private:
    ProcessTable* mutable_table() const {
      return const_cast<ProcessTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ProcessTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::pid::type pid() const {
      const auto& col = table_->pid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_ts::type start_ts() const {
      const auto& col = table_->start_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::end_ts::type end_ts() const {
      const auto& col = table_->end_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_upid::type parent_upid() const {
      const auto& col = table_->parent_upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::uid::type uid() const {
      const auto& col = table_->uid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::android_appid::type android_appid() const {
      const auto& col = table_->android_appid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cmdline::type cmdline() const {
      const auto& col = table_->cmdline();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ProcessTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ProcessTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ProcessTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_pid(ColumnType::pid::non_optional_type v) {
        auto* col = mutable_table_->mutable_pid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_ts(ColumnType::start_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_end_ts(ColumnType::end_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_end_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_upid(ColumnType::parent_upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_uid(ColumnType::uid::non_optional_type v) {
        auto* col = mutable_table_->mutable_uid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_android_appid(ColumnType::android_appid::non_optional_type v) {
        auto* col = mutable_table_->mutable_android_appid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cmdline(ColumnType::cmdline::non_optional_type v) {
        auto* col = mutable_table_->mutable_cmdline();
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
    friend class ProcessTable;

    explicit Iterator(ProcessTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ProcessTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ProcessTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        pid_(ColumnStorage<ColumnType::pid::stored_type>::Create<false>()),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        start_ts_(ColumnStorage<ColumnType::start_ts::stored_type>::Create<false>()),
        end_ts_(ColumnStorage<ColumnType::end_ts::stored_type>::Create<false>()),
        parent_upid_(ColumnStorage<ColumnType::parent_upid::stored_type>::Create<false>()),
        uid_(ColumnStorage<ColumnType::uid::stored_type>::Create<false>()),
        android_appid_(ColumnStorage<ColumnType::android_appid::stored_type>::Create<false>()),
        cmdline_(ColumnStorage<ColumnType::cmdline::stored_type>::Create<false>()),
        arg_set_id_(ColumnStorage<ColumnType::arg_set_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::pid::stored_type>(
          ColumnFlag::pid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_ts::stored_type>(
          ColumnFlag::start_ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::end_ts::stored_type>(
          ColumnFlag::end_ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::parent_upid::stored_type>(
          ColumnFlag::parent_upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::uid::stored_type>(
          ColumnFlag::uid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::android_appid::stored_type>(
          ColumnFlag::android_appid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cmdline::stored_type>(
          ColumnFlag::cmdline),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::arg_set_id::stored_type>(
          ColumnFlag::arg_set_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("pid", &pid_, ColumnFlag::pid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("start_ts", &start_ts_, ColumnFlag::start_ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("end_ts", &end_ts_, ColumnFlag::end_ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("parent_upid", &parent_upid_, ColumnFlag::parent_upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("uid", &uid_, ColumnFlag::uid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("android_appid", &android_appid_, ColumnFlag::android_appid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cmdline", &cmdline_, ColumnFlag::cmdline,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("arg_set_id", &arg_set_id_, ColumnFlag::arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ProcessTable() override;

  static const char* Name() { return "internal_process"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "pid", ColumnType::pid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_ts", ColumnType::start_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "end_ts", ColumnType::end_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_upid", ColumnType::parent_upid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "uid", ColumnType::uid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "android_appid", ColumnType::android_appid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cmdline", ColumnType::cmdline::SqlValueType(), false,
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
    pid_.ShrinkToFit();
    name_.ShrinkToFit();
    start_ts_.ShrinkToFit();
    end_ts_.ShrinkToFit();
    parent_upid_.ShrinkToFit();
    uid_.ShrinkToFit();
    android_appid_.ShrinkToFit();
    cmdline_.ShrinkToFit();
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
    mutable_pid()->Append(std::move(row.pid));
    mutable_name()->Append(std::move(row.name));
    mutable_start_ts()->Append(std::move(row.start_ts));
    mutable_end_ts()->Append(std::move(row.end_ts));
    mutable_parent_upid()->Append(std::move(row.parent_upid));
    mutable_uid()->Append(std::move(row.uid));
    mutable_android_appid()->Append(std::move(row.android_appid));
    mutable_cmdline()->Append(std::move(row.cmdline));
    mutable_arg_set_id()->Append(std::move(row.arg_set_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ProcessTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& pid() const {
    return static_cast<const ColumnType::pid&>(columns_[ColumnIndex::pid]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<int64_t>>& start_ts() const {
    return static_cast<const ColumnType::start_ts&>(columns_[ColumnIndex::start_ts]);
  }
  const TypedColumn<std::optional<int64_t>>& end_ts() const {
    return static_cast<const ColumnType::end_ts&>(columns_[ColumnIndex::end_ts]);
  }
  const TypedColumn<std::optional<uint32_t>>& parent_upid() const {
    return static_cast<const ColumnType::parent_upid&>(columns_[ColumnIndex::parent_upid]);
  }
  const TypedColumn<std::optional<uint32_t>>& uid() const {
    return static_cast<const ColumnType::uid&>(columns_[ColumnIndex::uid]);
  }
  const TypedColumn<std::optional<uint32_t>>& android_appid() const {
    return static_cast<const ColumnType::android_appid&>(columns_[ColumnIndex::android_appid]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& cmdline() const {
    return static_cast<const ColumnType::cmdline&>(columns_[ColumnIndex::cmdline]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }

  TypedColumn<uint32_t>* mutable_pid() {
    return static_cast<ColumnType::pid*>(
        &columns_[ColumnIndex::pid]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_start_ts() {
    return static_cast<ColumnType::start_ts*>(
        &columns_[ColumnIndex::start_ts]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_end_ts() {
    return static_cast<ColumnType::end_ts*>(
        &columns_[ColumnIndex::end_ts]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_parent_upid() {
    return static_cast<ColumnType::parent_upid*>(
        &columns_[ColumnIndex::parent_upid]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_uid() {
    return static_cast<ColumnType::uid*>(
        &columns_[ColumnIndex::uid]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_android_appid() {
    return static_cast<ColumnType::android_appid*>(
        &columns_[ColumnIndex::android_appid]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_cmdline() {
    return static_cast<ColumnType::cmdline*>(
        &columns_[ColumnIndex::cmdline]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::pid::stored_type> pid_;
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::start_ts::stored_type> start_ts_;
  ColumnStorage<ColumnType::end_ts::stored_type> end_ts_;
  ColumnStorage<ColumnType::parent_upid::stored_type> parent_upid_;
  ColumnStorage<ColumnType::uid::stored_type> uid_;
  ColumnStorage<ColumnType::android_appid::stored_type> android_appid_;
  ColumnStorage<ColumnType::cmdline::stored_type> cmdline_;
  ColumnStorage<ColumnType::arg_set_id::stored_type> arg_set_id_;
};
  

class ThreadTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t tid = 2;
    static constexpr uint32_t name = 3;
    static constexpr uint32_t start_ts = 4;
    static constexpr uint32_t end_ts = 5;
    static constexpr uint32_t upid = 6;
    static constexpr uint32_t is_main_thread = 7;
  };
  struct ColumnType {
    using id = IdColumn<ThreadTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using tid = TypedColumn<uint32_t>;
    using name = TypedColumn<std::optional<StringPool::Id>>;
    using start_ts = TypedColumn<std::optional<int64_t>>;
    using end_ts = TypedColumn<std::optional<int64_t>>;
    using upid = TypedColumn<std::optional<uint32_t>>;
    using is_main_thread = TypedColumn<std::optional<uint32_t>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_tid = {},
        std::optional<StringPool::Id> in_name = {},
        std::optional<int64_t> in_start_ts = {},
        std::optional<int64_t> in_end_ts = {},
        std::optional<uint32_t> in_upid = {},
        std::optional<uint32_t> in_is_main_thread = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          tid(std::move(in_tid)),
          name(std::move(in_name)),
          start_ts(std::move(in_start_ts)),
          end_ts(std::move(in_end_ts)),
          upid(std::move(in_upid)),
          is_main_thread(std::move(in_is_main_thread)) {
      type_ = "internal_thread";
    }
    uint32_t tid;
    std::optional<StringPool::Id> name;
    std::optional<int64_t> start_ts;
    std::optional<int64_t> end_ts;
    std::optional<uint32_t> upid;
    std::optional<uint32_t> is_main_thread;

    bool operator==(const ThreadTable::Row& other) const {
      return type() == other.type() && ColumnType::tid::Equals(tid, other.tid) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::start_ts::Equals(start_ts, other.start_ts) &&
       ColumnType::end_ts::Equals(end_ts, other.end_ts) &&
       ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::is_main_thread::Equals(is_main_thread, other.is_main_thread);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t tid = ColumnType::tid::default_flags();
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t start_ts = ColumnType::start_ts::default_flags();
    static constexpr uint32_t end_ts = ColumnType::end_ts::default_flags();
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
    static constexpr uint32_t is_main_thread = ColumnType::is_main_thread::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ThreadTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ThreadTable, RowNumber> {
   public:
    ConstRowReference(const ThreadTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::tid::type tid() const {
      return table_->tid()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::start_ts::type start_ts() const {
      return table_->start_ts()[row_number_];
    }
    ColumnType::end_ts::type end_ts() const {
      return table_->end_ts()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
    ColumnType::is_main_thread::type is_main_thread() const {
      return table_->is_main_thread()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ThreadTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_tid(
        ColumnType::tid::non_optional_type v) {
      return mutable_table()->mutable_tid()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_start_ts(
        ColumnType::start_ts::non_optional_type v) {
      return mutable_table()->mutable_start_ts()->Set(row_number_, v);
    }
    void set_end_ts(
        ColumnType::end_ts::non_optional_type v) {
      return mutable_table()->mutable_end_ts()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_is_main_thread(
        ColumnType::is_main_thread::non_optional_type v) {
      return mutable_table()->mutable_is_main_thread()->Set(row_number_, v);
    }

   private:
    ThreadTable* mutable_table() const {
      return const_cast<ThreadTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ThreadTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::tid::type tid() const {
      const auto& col = table_->tid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_ts::type start_ts() const {
      const auto& col = table_->start_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::end_ts::type end_ts() const {
      const auto& col = table_->end_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::is_main_thread::type is_main_thread() const {
      const auto& col = table_->is_main_thread();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ThreadTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ThreadTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ThreadTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_tid(ColumnType::tid::non_optional_type v) {
        auto* col = mutable_table_->mutable_tid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_ts(ColumnType::start_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_end_ts(ColumnType::end_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_end_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_is_main_thread(ColumnType::is_main_thread::non_optional_type v) {
        auto* col = mutable_table_->mutable_is_main_thread();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ThreadTable;

    explicit Iterator(ThreadTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ThreadTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ThreadTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        tid_(ColumnStorage<ColumnType::tid::stored_type>::Create<false>()),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        start_ts_(ColumnStorage<ColumnType::start_ts::stored_type>::Create<false>()),
        end_ts_(ColumnStorage<ColumnType::end_ts::stored_type>::Create<false>()),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        is_main_thread_(ColumnStorage<ColumnType::is_main_thread::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::tid::stored_type>(
          ColumnFlag::tid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_ts::stored_type>(
          ColumnFlag::start_ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::end_ts::stored_type>(
          ColumnFlag::end_ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::is_main_thread::stored_type>(
          ColumnFlag::is_main_thread),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("tid", &tid_, ColumnFlag::tid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("start_ts", &start_ts_, ColumnFlag::start_ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("end_ts", &end_ts_, ColumnFlag::end_ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("is_main_thread", &is_main_thread_, ColumnFlag::is_main_thread,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ThreadTable() override;

  static const char* Name() { return "internal_thread"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "tid", ColumnType::tid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_ts", ColumnType::start_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "end_ts", ColumnType::end_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid", ColumnType::upid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "is_main_thread", ColumnType::is_main_thread::SqlValueType(), false,
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
    tid_.ShrinkToFit();
    name_.ShrinkToFit();
    start_ts_.ShrinkToFit();
    end_ts_.ShrinkToFit();
    upid_.ShrinkToFit();
    is_main_thread_.ShrinkToFit();
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
    mutable_tid()->Append(std::move(row.tid));
    mutable_name()->Append(std::move(row.name));
    mutable_start_ts()->Append(std::move(row.start_ts));
    mutable_end_ts()->Append(std::move(row.end_ts));
    mutable_upid()->Append(std::move(row.upid));
    mutable_is_main_thread()->Append(std::move(row.is_main_thread));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ThreadTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& tid() const {
    return static_cast<const ColumnType::tid&>(columns_[ColumnIndex::tid]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<int64_t>>& start_ts() const {
    return static_cast<const ColumnType::start_ts&>(columns_[ColumnIndex::start_ts]);
  }
  const TypedColumn<std::optional<int64_t>>& end_ts() const {
    return static_cast<const ColumnType::end_ts&>(columns_[ColumnIndex::end_ts]);
  }
  const TypedColumn<std::optional<uint32_t>>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<std::optional<uint32_t>>& is_main_thread() const {
    return static_cast<const ColumnType::is_main_thread&>(columns_[ColumnIndex::is_main_thread]);
  }

  TypedColumn<uint32_t>* mutable_tid() {
    return static_cast<ColumnType::tid*>(
        &columns_[ColumnIndex::tid]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_start_ts() {
    return static_cast<ColumnType::start_ts*>(
        &columns_[ColumnIndex::start_ts]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_end_ts() {
    return static_cast<ColumnType::end_ts*>(
        &columns_[ColumnIndex::end_ts]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_is_main_thread() {
    return static_cast<ColumnType::is_main_thread*>(
        &columns_[ColumnIndex::is_main_thread]);
  }

 private:
  
  
  ColumnStorage<ColumnType::tid::stored_type> tid_;
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::start_ts::stored_type> start_ts_;
  ColumnStorage<ColumnType::end_ts::stored_type> end_ts_;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::is_main_thread::stored_type> is_main_thread_;
};
  

class ArgTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t arg_set_id = 2;
    static constexpr uint32_t flat_key = 3;
    static constexpr uint32_t key = 4;
    static constexpr uint32_t int_value = 5;
    static constexpr uint32_t string_value = 6;
    static constexpr uint32_t real_value = 7;
    static constexpr uint32_t value_type = 8;
  };
  struct ColumnType {
    using id = IdColumn<ArgTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using arg_set_id = TypedColumn<uint32_t>;
    using flat_key = TypedColumn<StringPool::Id>;
    using key = TypedColumn<StringPool::Id>;
    using int_value = TypedColumn<std::optional<int64_t>>;
    using string_value = TypedColumn<std::optional<StringPool::Id>>;
    using real_value = TypedColumn<std::optional<double>>;
    using value_type = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_arg_set_id = {},
        StringPool::Id in_flat_key = {},
        StringPool::Id in_key = {},
        std::optional<int64_t> in_int_value = {},
        std::optional<StringPool::Id> in_string_value = {},
        std::optional<double> in_real_value = {},
        StringPool::Id in_value_type = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          arg_set_id(std::move(in_arg_set_id)),
          flat_key(std::move(in_flat_key)),
          key(std::move(in_key)),
          int_value(std::move(in_int_value)),
          string_value(std::move(in_string_value)),
          real_value(std::move(in_real_value)),
          value_type(std::move(in_value_type)) {
      type_ = "internal_args";
    }
    uint32_t arg_set_id;
    StringPool::Id flat_key;
    StringPool::Id key;
    std::optional<int64_t> int_value;
    std::optional<StringPool::Id> string_value;
    std::optional<double> real_value;
    StringPool::Id value_type;

    bool operator==(const ArgTable::Row& other) const {
      return type() == other.type() && ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::flat_key::Equals(flat_key, other.flat_key) &&
       ColumnType::key::Equals(key, other.key) &&
       ColumnType::int_value::Equals(int_value, other.int_value) &&
       ColumnType::string_value::Equals(string_value, other.string_value) &&
       ColumnType::real_value::Equals(real_value, other.real_value) &&
       ColumnType::value_type::Equals(value_type, other.value_type);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t arg_set_id = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::arg_set_id::default_flags();
    static constexpr uint32_t flat_key = ColumnType::flat_key::default_flags();
    static constexpr uint32_t key = ColumnType::key::default_flags();
    static constexpr uint32_t int_value = ColumnType::int_value::default_flags();
    static constexpr uint32_t string_value = ColumnType::string_value::default_flags();
    static constexpr uint32_t real_value = ColumnType::real_value::default_flags();
    static constexpr uint32_t value_type = ColumnType::value_type::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ArgTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ArgTable, RowNumber> {
   public:
    ConstRowReference(const ArgTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::flat_key::type flat_key() const {
      return table_->flat_key()[row_number_];
    }
    ColumnType::key::type key() const {
      return table_->key()[row_number_];
    }
    ColumnType::int_value::type int_value() const {
      return table_->int_value()[row_number_];
    }
    ColumnType::string_value::type string_value() const {
      return table_->string_value()[row_number_];
    }
    ColumnType::real_value::type real_value() const {
      return table_->real_value()[row_number_];
    }
    ColumnType::value_type::type value_type() const {
      return table_->value_type()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ArgTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_flat_key(
        ColumnType::flat_key::non_optional_type v) {
      return mutable_table()->mutable_flat_key()->Set(row_number_, v);
    }
    void set_key(
        ColumnType::key::non_optional_type v) {
      return mutable_table()->mutable_key()->Set(row_number_, v);
    }
    void set_int_value(
        ColumnType::int_value::non_optional_type v) {
      return mutable_table()->mutable_int_value()->Set(row_number_, v);
    }
    void set_string_value(
        ColumnType::string_value::non_optional_type v) {
      return mutable_table()->mutable_string_value()->Set(row_number_, v);
    }
    void set_real_value(
        ColumnType::real_value::non_optional_type v) {
      return mutable_table()->mutable_real_value()->Set(row_number_, v);
    }
    void set_value_type(
        ColumnType::value_type::non_optional_type v) {
      return mutable_table()->mutable_value_type()->Set(row_number_, v);
    }

   private:
    ArgTable* mutable_table() const {
      return const_cast<ArgTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ArgTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::flat_key::type flat_key() const {
      const auto& col = table_->flat_key();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::key::type key() const {
      const auto& col = table_->key();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::int_value::type int_value() const {
      const auto& col = table_->int_value();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::string_value::type string_value() const {
      const auto& col = table_->string_value();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::real_value::type real_value() const {
      const auto& col = table_->real_value();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::value_type::type value_type() const {
      const auto& col = table_->value_type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ArgTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ArgTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ArgTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_flat_key(ColumnType::flat_key::non_optional_type v) {
        auto* col = mutable_table_->mutable_flat_key();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_key(ColumnType::key::non_optional_type v) {
        auto* col = mutable_table_->mutable_key();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_int_value(ColumnType::int_value::non_optional_type v) {
        auto* col = mutable_table_->mutable_int_value();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_string_value(ColumnType::string_value::non_optional_type v) {
        auto* col = mutable_table_->mutable_string_value();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_real_value(ColumnType::real_value::non_optional_type v) {
        auto* col = mutable_table_->mutable_real_value();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_value_type(ColumnType::value_type::non_optional_type v) {
        auto* col = mutable_table_->mutable_value_type();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ArgTable;

    explicit Iterator(ArgTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ArgTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ArgTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        arg_set_id_(ColumnStorage<ColumnType::arg_set_id::stored_type>::Create<false>()),
        flat_key_(ColumnStorage<ColumnType::flat_key::stored_type>::Create<false>()),
        key_(ColumnStorage<ColumnType::key::stored_type>::Create<false>()),
        int_value_(ColumnStorage<ColumnType::int_value::stored_type>::Create<false>()),
        string_value_(ColumnStorage<ColumnType::string_value::stored_type>::Create<false>()),
        real_value_(ColumnStorage<ColumnType::real_value::stored_type>::Create<false>()),
        value_type_(ColumnStorage<ColumnType::value_type::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::arg_set_id::stored_type>(
          ColumnFlag::arg_set_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::flat_key::stored_type>(
          ColumnFlag::flat_key),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::key::stored_type>(
          ColumnFlag::key),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::int_value::stored_type>(
          ColumnFlag::int_value),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::string_value::stored_type>(
          ColumnFlag::string_value),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::real_value::stored_type>(
          ColumnFlag::real_value),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::value_type::stored_type>(
          ColumnFlag::value_type),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("arg_set_id", &arg_set_id_, ColumnFlag::arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("flat_key", &flat_key_, ColumnFlag::flat_key,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("key", &key_, ColumnFlag::key,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("int_value", &int_value_, ColumnFlag::int_value,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("string_value", &string_value_, ColumnFlag::string_value,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("real_value", &real_value_, ColumnFlag::real_value,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("value_type", &value_type_, ColumnFlag::value_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ArgTable() override;

  static const char* Name() { return "internal_args"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        true,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "flat_key", ColumnType::flat_key::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "key", ColumnType::key::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "int_value", ColumnType::int_value::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "string_value", ColumnType::string_value::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "real_value", ColumnType::real_value::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "value_type", ColumnType::value_type::SqlValueType(), false,
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
    arg_set_id_.ShrinkToFit();
    flat_key_.ShrinkToFit();
    key_.ShrinkToFit();
    int_value_.ShrinkToFit();
    string_value_.ShrinkToFit();
    real_value_.ShrinkToFit();
    value_type_.ShrinkToFit();
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
    mutable_arg_set_id()->Append(std::move(row.arg_set_id));
    mutable_flat_key()->Append(std::move(row.flat_key));
    mutable_key()->Append(std::move(row.key));
    mutable_int_value()->Append(std::move(row.int_value));
    mutable_string_value()->Append(std::move(row.string_value));
    mutable_real_value()->Append(std::move(row.real_value));
    mutable_value_type()->Append(std::move(row.value_type));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ArgTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& flat_key() const {
    return static_cast<const ColumnType::flat_key&>(columns_[ColumnIndex::flat_key]);
  }
  const TypedColumn<StringPool::Id>& key() const {
    return static_cast<const ColumnType::key&>(columns_[ColumnIndex::key]);
  }
  const TypedColumn<std::optional<int64_t>>& int_value() const {
    return static_cast<const ColumnType::int_value&>(columns_[ColumnIndex::int_value]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& string_value() const {
    return static_cast<const ColumnType::string_value&>(columns_[ColumnIndex::string_value]);
  }
  const TypedColumn<std::optional<double>>& real_value() const {
    return static_cast<const ColumnType::real_value&>(columns_[ColumnIndex::real_value]);
  }
  const TypedColumn<StringPool::Id>& value_type() const {
    return static_cast<const ColumnType::value_type&>(columns_[ColumnIndex::value_type]);
  }

  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_flat_key() {
    return static_cast<ColumnType::flat_key*>(
        &columns_[ColumnIndex::flat_key]);
  }
  TypedColumn<StringPool::Id>* mutable_key() {
    return static_cast<ColumnType::key*>(
        &columns_[ColumnIndex::key]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_int_value() {
    return static_cast<ColumnType::int_value*>(
        &columns_[ColumnIndex::int_value]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_string_value() {
    return static_cast<ColumnType::string_value*>(
        &columns_[ColumnIndex::string_value]);
  }
  TypedColumn<std::optional<double>>* mutable_real_value() {
    return static_cast<ColumnType::real_value*>(
        &columns_[ColumnIndex::real_value]);
  }
  TypedColumn<StringPool::Id>* mutable_value_type() {
    return static_cast<ColumnType::value_type*>(
        &columns_[ColumnIndex::value_type]);
  }

 private:
  
  
  ColumnStorage<ColumnType::arg_set_id::stored_type> arg_set_id_;
  ColumnStorage<ColumnType::flat_key::stored_type> flat_key_;
  ColumnStorage<ColumnType::key::stored_type> key_;
  ColumnStorage<ColumnType::int_value::stored_type> int_value_;
  ColumnStorage<ColumnType::string_value::stored_type> string_value_;
  ColumnStorage<ColumnType::real_value::stored_type> real_value_;
  ColumnStorage<ColumnType::value_type::stored_type> value_type_;
};
  

class ClockSnapshotTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t clock_id = 3;
    static constexpr uint32_t clock_name = 4;
    static constexpr uint32_t clock_value = 5;
    static constexpr uint32_t snapshot_id = 6;
  };
  struct ColumnType {
    using id = IdColumn<ClockSnapshotTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using clock_id = TypedColumn<int64_t>;
    using clock_name = TypedColumn<std::optional<StringPool::Id>>;
    using clock_value = TypedColumn<int64_t>;
    using snapshot_id = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        int64_t in_clock_id = {},
        std::optional<StringPool::Id> in_clock_name = {},
        int64_t in_clock_value = {},
        uint32_t in_snapshot_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          clock_id(std::move(in_clock_id)),
          clock_name(std::move(in_clock_name)),
          clock_value(std::move(in_clock_value)),
          snapshot_id(std::move(in_snapshot_id)) {
      type_ = "clock_snapshot";
    }
    int64_t ts;
    int64_t clock_id;
    std::optional<StringPool::Id> clock_name;
    int64_t clock_value;
    uint32_t snapshot_id;

    bool operator==(const ClockSnapshotTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::clock_id::Equals(clock_id, other.clock_id) &&
       ColumnType::clock_name::Equals(clock_name, other.clock_name) &&
       ColumnType::clock_value::Equals(clock_value, other.clock_value) &&
       ColumnType::snapshot_id::Equals(snapshot_id, other.snapshot_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = ColumnType::ts::default_flags();
    static constexpr uint32_t clock_id = ColumnType::clock_id::default_flags();
    static constexpr uint32_t clock_name = ColumnType::clock_name::default_flags();
    static constexpr uint32_t clock_value = ColumnType::clock_value::default_flags();
    static constexpr uint32_t snapshot_id = ColumnType::snapshot_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ClockSnapshotTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ClockSnapshotTable, RowNumber> {
   public:
    ConstRowReference(const ClockSnapshotTable* table, uint32_t row_number)
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
    ColumnType::clock_id::type clock_id() const {
      return table_->clock_id()[row_number_];
    }
    ColumnType::clock_name::type clock_name() const {
      return table_->clock_name()[row_number_];
    }
    ColumnType::clock_value::type clock_value() const {
      return table_->clock_value()[row_number_];
    }
    ColumnType::snapshot_id::type snapshot_id() const {
      return table_->snapshot_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ClockSnapshotTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_clock_id(
        ColumnType::clock_id::non_optional_type v) {
      return mutable_table()->mutable_clock_id()->Set(row_number_, v);
    }
    void set_clock_name(
        ColumnType::clock_name::non_optional_type v) {
      return mutable_table()->mutable_clock_name()->Set(row_number_, v);
    }
    void set_clock_value(
        ColumnType::clock_value::non_optional_type v) {
      return mutable_table()->mutable_clock_value()->Set(row_number_, v);
    }
    void set_snapshot_id(
        ColumnType::snapshot_id::non_optional_type v) {
      return mutable_table()->mutable_snapshot_id()->Set(row_number_, v);
    }

   private:
    ClockSnapshotTable* mutable_table() const {
      return const_cast<ClockSnapshotTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ClockSnapshotTable, RowNumber, ConstRowReference> {
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
    ColumnType::clock_id::type clock_id() const {
      const auto& col = table_->clock_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::clock_name::type clock_name() const {
      const auto& col = table_->clock_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::clock_value::type clock_value() const {
      const auto& col = table_->clock_value();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::snapshot_id::type snapshot_id() const {
      const auto& col = table_->snapshot_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ClockSnapshotTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ClockSnapshotTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ClockSnapshotTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_clock_id(ColumnType::clock_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_clock_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_clock_name(ColumnType::clock_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_clock_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_clock_value(ColumnType::clock_value::non_optional_type v) {
        auto* col = mutable_table_->mutable_clock_value();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_snapshot_id(ColumnType::snapshot_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_snapshot_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ClockSnapshotTable;

    explicit Iterator(ClockSnapshotTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ClockSnapshotTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ClockSnapshotTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        clock_id_(ColumnStorage<ColumnType::clock_id::stored_type>::Create<false>()),
        clock_name_(ColumnStorage<ColumnType::clock_name::stored_type>::Create<false>()),
        clock_value_(ColumnStorage<ColumnType::clock_value::stored_type>::Create<false>()),
        snapshot_id_(ColumnStorage<ColumnType::snapshot_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::clock_id::stored_type>(
          ColumnFlag::clock_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::clock_name::stored_type>(
          ColumnFlag::clock_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::clock_value::stored_type>(
          ColumnFlag::clock_value),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::snapshot_id::stored_type>(
          ColumnFlag::snapshot_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("clock_id", &clock_id_, ColumnFlag::clock_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("clock_name", &clock_name_, ColumnFlag::clock_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("clock_value", &clock_value_, ColumnFlag::clock_value,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("snapshot_id", &snapshot_id_, ColumnFlag::snapshot_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ClockSnapshotTable() override;

  static const char* Name() { return "clock_snapshot"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "ts", ColumnType::ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "clock_id", ColumnType::clock_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "clock_name", ColumnType::clock_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "clock_value", ColumnType::clock_value::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "snapshot_id", ColumnType::snapshot_id::SqlValueType(), false,
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
    clock_id_.ShrinkToFit();
    clock_name_.ShrinkToFit();
    clock_value_.ShrinkToFit();
    snapshot_id_.ShrinkToFit();
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
    mutable_clock_id()->Append(std::move(row.clock_id));
    mutable_clock_name()->Append(std::move(row.clock_name));
    mutable_clock_value()->Append(std::move(row.clock_value));
    mutable_snapshot_id()->Append(std::move(row.snapshot_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ClockSnapshotTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<int64_t>& clock_id() const {
    return static_cast<const ColumnType::clock_id&>(columns_[ColumnIndex::clock_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& clock_name() const {
    return static_cast<const ColumnType::clock_name&>(columns_[ColumnIndex::clock_name]);
  }
  const TypedColumn<int64_t>& clock_value() const {
    return static_cast<const ColumnType::clock_value&>(columns_[ColumnIndex::clock_value]);
  }
  const TypedColumn<uint32_t>& snapshot_id() const {
    return static_cast<const ColumnType::snapshot_id&>(columns_[ColumnIndex::snapshot_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<int64_t>* mutable_clock_id() {
    return static_cast<ColumnType::clock_id*>(
        &columns_[ColumnIndex::clock_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_clock_name() {
    return static_cast<ColumnType::clock_name*>(
        &columns_[ColumnIndex::clock_name]);
  }
  TypedColumn<int64_t>* mutable_clock_value() {
    return static_cast<ColumnType::clock_value*>(
        &columns_[ColumnIndex::clock_value]);
  }
  TypedColumn<uint32_t>* mutable_snapshot_id() {
    return static_cast<ColumnType::snapshot_id*>(
        &columns_[ColumnIndex::snapshot_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::clock_id::stored_type> clock_id_;
  ColumnStorage<ColumnType::clock_name::stored_type> clock_name_;
  ColumnStorage<ColumnType::clock_value::stored_type> clock_value_;
  ColumnStorage<ColumnType::snapshot_id::stored_type> snapshot_id_;
};
  

class CpuTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t cluster_id = 2;
    static constexpr uint32_t processor = 3;
  };
  struct ColumnType {
    using id = IdColumn<CpuTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using cluster_id = TypedColumn<uint32_t>;
    using processor = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_cluster_id = {},
        StringPool::Id in_processor = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          cluster_id(std::move(in_cluster_id)),
          processor(std::move(in_processor)) {
      type_ = "cpu";
    }
    uint32_t cluster_id;
    StringPool::Id processor;

    bool operator==(const CpuTable::Row& other) const {
      return type() == other.type() && ColumnType::cluster_id::Equals(cluster_id, other.cluster_id) &&
       ColumnType::processor::Equals(processor, other.processor);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t cluster_id = ColumnType::cluster_id::default_flags();
    static constexpr uint32_t processor = ColumnType::processor::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      CpuTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    CpuTable, RowNumber> {
   public:
    ConstRowReference(const CpuTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::cluster_id::type cluster_id() const {
      return table_->cluster_id()[row_number_];
    }
    ColumnType::processor::type processor() const {
      return table_->processor()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const CpuTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_cluster_id(
        ColumnType::cluster_id::non_optional_type v) {
      return mutable_table()->mutable_cluster_id()->Set(row_number_, v);
    }
    void set_processor(
        ColumnType::processor::non_optional_type v) {
      return mutable_table()->mutable_processor()->Set(row_number_, v);
    }

   private:
    CpuTable* mutable_table() const {
      return const_cast<CpuTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, CpuTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cluster_id::type cluster_id() const {
      const auto& col = table_->cluster_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::processor::type processor() const {
      const auto& col = table_->processor();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const CpuTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class CpuTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, CpuTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_cluster_id(ColumnType::cluster_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_cluster_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_processor(ColumnType::processor::non_optional_type v) {
        auto* col = mutable_table_->mutable_processor();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class CpuTable;

    explicit Iterator(CpuTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    CpuTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit CpuTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        cluster_id_(ColumnStorage<ColumnType::cluster_id::stored_type>::Create<false>()),
        processor_(ColumnStorage<ColumnType::processor::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cluster_id::stored_type>(
          ColumnFlag::cluster_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::processor::stored_type>(
          ColumnFlag::processor),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("cluster_id", &cluster_id_, ColumnFlag::cluster_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("processor", &processor_, ColumnFlag::processor,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~CpuTable() override;

  static const char* Name() { return "cpu"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cluster_id", ColumnType::cluster_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "processor", ColumnType::processor::SqlValueType(), false,
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
    cluster_id_.ShrinkToFit();
    processor_.ShrinkToFit();
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
    mutable_cluster_id()->Append(std::move(row.cluster_id));
    mutable_processor()->Append(std::move(row.processor));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<CpuTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& cluster_id() const {
    return static_cast<const ColumnType::cluster_id&>(columns_[ColumnIndex::cluster_id]);
  }
  const TypedColumn<StringPool::Id>& processor() const {
    return static_cast<const ColumnType::processor&>(columns_[ColumnIndex::processor]);
  }

  TypedColumn<uint32_t>* mutable_cluster_id() {
    return static_cast<ColumnType::cluster_id*>(
        &columns_[ColumnIndex::cluster_id]);
  }
  TypedColumn<StringPool::Id>* mutable_processor() {
    return static_cast<ColumnType::processor*>(
        &columns_[ColumnIndex::processor]);
  }

 private:
  
  
  ColumnStorage<ColumnType::cluster_id::stored_type> cluster_id_;
  ColumnStorage<ColumnType::processor::stored_type> processor_;
};
  

class CpuFreqTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t cpu_id = 2;
    static constexpr uint32_t freq = 3;
  };
  struct ColumnType {
    using id = IdColumn<CpuFreqTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using cpu_id = TypedColumn<CpuTable::Id>;
    using freq = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(CpuTable::Id in_cpu_id = {},
        uint32_t in_freq = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          cpu_id(std::move(in_cpu_id)),
          freq(std::move(in_freq)) {
      type_ = "cpu_freq";
    }
    CpuTable::Id cpu_id;
    uint32_t freq;

    bool operator==(const CpuFreqTable::Row& other) const {
      return type() == other.type() && ColumnType::cpu_id::Equals(cpu_id, other.cpu_id) &&
       ColumnType::freq::Equals(freq, other.freq);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t cpu_id = ColumnType::cpu_id::default_flags();
    static constexpr uint32_t freq = ColumnType::freq::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      CpuFreqTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    CpuFreqTable, RowNumber> {
   public:
    ConstRowReference(const CpuFreqTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::cpu_id::type cpu_id() const {
      return table_->cpu_id()[row_number_];
    }
    ColumnType::freq::type freq() const {
      return table_->freq()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const CpuFreqTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_cpu_id(
        ColumnType::cpu_id::non_optional_type v) {
      return mutable_table()->mutable_cpu_id()->Set(row_number_, v);
    }
    void set_freq(
        ColumnType::freq::non_optional_type v) {
      return mutable_table()->mutable_freq()->Set(row_number_, v);
    }

   private:
    CpuFreqTable* mutable_table() const {
      return const_cast<CpuFreqTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, CpuFreqTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cpu_id::type cpu_id() const {
      const auto& col = table_->cpu_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::freq::type freq() const {
      const auto& col = table_->freq();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const CpuFreqTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class CpuFreqTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, CpuFreqTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_cpu_id(ColumnType::cpu_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_cpu_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_freq(ColumnType::freq::non_optional_type v) {
        auto* col = mutable_table_->mutable_freq();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class CpuFreqTable;

    explicit Iterator(CpuFreqTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    CpuFreqTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit CpuFreqTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        cpu_id_(ColumnStorage<ColumnType::cpu_id::stored_type>::Create<false>()),
        freq_(ColumnStorage<ColumnType::freq::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu_id::stored_type>(
          ColumnFlag::cpu_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::freq::stored_type>(
          ColumnFlag::freq),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("cpu_id", &cpu_id_, ColumnFlag::cpu_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("freq", &freq_, ColumnFlag::freq,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~CpuFreqTable() override;

  static const char* Name() { return "cpu_freq"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cpu_id", ColumnType::cpu_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "freq", ColumnType::freq::SqlValueType(), false,
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
    cpu_id_.ShrinkToFit();
    freq_.ShrinkToFit();
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
    mutable_cpu_id()->Append(std::move(row.cpu_id));
    mutable_freq()->Append(std::move(row.freq));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<CpuFreqTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<CpuTable::Id>& cpu_id() const {
    return static_cast<const ColumnType::cpu_id&>(columns_[ColumnIndex::cpu_id]);
  }
  const TypedColumn<uint32_t>& freq() const {
    return static_cast<const ColumnType::freq&>(columns_[ColumnIndex::freq]);
  }

  TypedColumn<CpuTable::Id>* mutable_cpu_id() {
    return static_cast<ColumnType::cpu_id*>(
        &columns_[ColumnIndex::cpu_id]);
  }
  TypedColumn<uint32_t>* mutable_freq() {
    return static_cast<ColumnType::freq*>(
        &columns_[ColumnIndex::freq]);
  }

 private:
  
  
  ColumnStorage<ColumnType::cpu_id::stored_type> cpu_id_;
  ColumnStorage<ColumnType::freq::stored_type> freq_;
};
  

class ExpMissingChromeProcTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t upid = 2;
    static constexpr uint32_t reliable_from = 3;
  };
  struct ColumnType {
    using id = IdColumn<ExpMissingChromeProcTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using upid = TypedColumn<uint32_t>;
    using reliable_from = TypedColumn<std::optional<int64_t>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_upid = {},
        std::optional<int64_t> in_reliable_from = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          upid(std::move(in_upid)),
          reliable_from(std::move(in_reliable_from)) {
      type_ = "experimental_missing_chrome_processes";
    }
    uint32_t upid;
    std::optional<int64_t> reliable_from;

    bool operator==(const ExpMissingChromeProcTable::Row& other) const {
      return type() == other.type() && ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::reliable_from::Equals(reliable_from, other.reliable_from);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
    static constexpr uint32_t reliable_from = ColumnType::reliable_from::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ExpMissingChromeProcTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExpMissingChromeProcTable, RowNumber> {
   public:
    ConstRowReference(const ExpMissingChromeProcTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
    ColumnType::reliable_from::type reliable_from() const {
      return table_->reliable_from()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExpMissingChromeProcTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_reliable_from(
        ColumnType::reliable_from::non_optional_type v) {
      return mutable_table()->mutable_reliable_from()->Set(row_number_, v);
    }

   private:
    ExpMissingChromeProcTable* mutable_table() const {
      return const_cast<ExpMissingChromeProcTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExpMissingChromeProcTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::reliable_from::type reliable_from() const {
      const auto& col = table_->reliable_from();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExpMissingChromeProcTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExpMissingChromeProcTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, ExpMissingChromeProcTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_reliable_from(ColumnType::reliable_from::non_optional_type v) {
        auto* col = mutable_table_->mutable_reliable_from();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ExpMissingChromeProcTable;

    explicit Iterator(ExpMissingChromeProcTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExpMissingChromeProcTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExpMissingChromeProcTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        reliable_from_(ColumnStorage<ColumnType::reliable_from::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::reliable_from::stored_type>(
          ColumnFlag::reliable_from),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("reliable_from", &reliable_from_, ColumnFlag::reliable_from,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ExpMissingChromeProcTable() override;

  static const char* Name() { return "experimental_missing_chrome_processes"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid", ColumnType::upid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "reliable_from", ColumnType::reliable_from::SqlValueType(), false,
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
    upid_.ShrinkToFit();
    reliable_from_.ShrinkToFit();
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
    mutable_upid()->Append(std::move(row.upid));
    mutable_reliable_from()->Append(std::move(row.reliable_from));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ExpMissingChromeProcTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<std::optional<int64_t>>& reliable_from() const {
    return static_cast<const ColumnType::reliable_from&>(columns_[ColumnIndex::reliable_from]);
  }

  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_reliable_from() {
    return static_cast<ColumnType::reliable_from*>(
        &columns_[ColumnIndex::reliable_from]);
  }

 private:
  
  
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::reliable_from::stored_type> reliable_from_;
};
  

class FiledescriptorTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t ufd = 2;
    static constexpr uint32_t fd = 3;
    static constexpr uint32_t ts = 4;
    static constexpr uint32_t upid = 5;
    static constexpr uint32_t path = 6;
  };
  struct ColumnType {
    using id = IdColumn<FiledescriptorTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ufd = TypedColumn<int64_t>;
    using fd = TypedColumn<int64_t>;
    using ts = TypedColumn<std::optional<int64_t>>;
    using upid = TypedColumn<std::optional<uint32_t>>;
    using path = TypedColumn<std::optional<StringPool::Id>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ufd = {},
        int64_t in_fd = {},
        std::optional<int64_t> in_ts = {},
        std::optional<uint32_t> in_upid = {},
        std::optional<StringPool::Id> in_path = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ufd(std::move(in_ufd)),
          fd(std::move(in_fd)),
          ts(std::move(in_ts)),
          upid(std::move(in_upid)),
          path(std::move(in_path)) {
      type_ = "filedescriptor";
    }
    int64_t ufd;
    int64_t fd;
    std::optional<int64_t> ts;
    std::optional<uint32_t> upid;
    std::optional<StringPool::Id> path;

    bool operator==(const FiledescriptorTable::Row& other) const {
      return type() == other.type() && ColumnType::ufd::Equals(ufd, other.ufd) &&
       ColumnType::fd::Equals(fd, other.fd) &&
       ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::path::Equals(path, other.path);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ufd = ColumnType::ufd::default_flags();
    static constexpr uint32_t fd = ColumnType::fd::default_flags();
    static constexpr uint32_t ts = ColumnType::ts::default_flags();
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
    static constexpr uint32_t path = ColumnType::path::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      FiledescriptorTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    FiledescriptorTable, RowNumber> {
   public:
    ConstRowReference(const FiledescriptorTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::ufd::type ufd() const {
      return table_->ufd()[row_number_];
    }
    ColumnType::fd::type fd() const {
      return table_->fd()[row_number_];
    }
    ColumnType::ts::type ts() const {
      return table_->ts()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
    ColumnType::path::type path() const {
      return table_->path()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const FiledescriptorTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ufd(
        ColumnType::ufd::non_optional_type v) {
      return mutable_table()->mutable_ufd()->Set(row_number_, v);
    }
    void set_fd(
        ColumnType::fd::non_optional_type v) {
      return mutable_table()->mutable_fd()->Set(row_number_, v);
    }
    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_path(
        ColumnType::path::non_optional_type v) {
      return mutable_table()->mutable_path()->Set(row_number_, v);
    }

   private:
    FiledescriptorTable* mutable_table() const {
      return const_cast<FiledescriptorTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, FiledescriptorTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::ufd::type ufd() const {
      const auto& col = table_->ufd();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::fd::type fd() const {
      const auto& col = table_->fd();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::ts::type ts() const {
      const auto& col = table_->ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::path::type path() const {
      const auto& col = table_->path();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const FiledescriptorTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class FiledescriptorTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, FiledescriptorTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ufd(ColumnType::ufd::non_optional_type v) {
        auto* col = mutable_table_->mutable_ufd();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_fd(ColumnType::fd::non_optional_type v) {
        auto* col = mutable_table_->mutable_fd();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_path(ColumnType::path::non_optional_type v) {
        auto* col = mutable_table_->mutable_path();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class FiledescriptorTable;

    explicit Iterator(FiledescriptorTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    FiledescriptorTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit FiledescriptorTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ufd_(ColumnStorage<ColumnType::ufd::stored_type>::Create<false>()),
        fd_(ColumnStorage<ColumnType::fd::stored_type>::Create<false>()),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        path_(ColumnStorage<ColumnType::path::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ufd::stored_type>(
          ColumnFlag::ufd),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::fd::stored_type>(
          ColumnFlag::fd),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::path::stored_type>(
          ColumnFlag::path),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ufd", &ufd_, ColumnFlag::ufd,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("fd", &fd_, ColumnFlag::fd,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("path", &path_, ColumnFlag::path,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~FiledescriptorTable() override;

  static const char* Name() { return "filedescriptor"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "ufd", ColumnType::ufd::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "fd", ColumnType::fd::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "ts", ColumnType::ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid", ColumnType::upid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "path", ColumnType::path::SqlValueType(), false,
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
    ufd_.ShrinkToFit();
    fd_.ShrinkToFit();
    ts_.ShrinkToFit();
    upid_.ShrinkToFit();
    path_.ShrinkToFit();
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
    mutable_ufd()->Append(std::move(row.ufd));
    mutable_fd()->Append(std::move(row.fd));
    mutable_ts()->Append(std::move(row.ts));
    mutable_upid()->Append(std::move(row.upid));
    mutable_path()->Append(std::move(row.path));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<FiledescriptorTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ufd() const {
    return static_cast<const ColumnType::ufd&>(columns_[ColumnIndex::ufd]);
  }
  const TypedColumn<int64_t>& fd() const {
    return static_cast<const ColumnType::fd&>(columns_[ColumnIndex::fd]);
  }
  const TypedColumn<std::optional<int64_t>>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<std::optional<uint32_t>>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& path() const {
    return static_cast<const ColumnType::path&>(columns_[ColumnIndex::path]);
  }

  TypedColumn<int64_t>* mutable_ufd() {
    return static_cast<ColumnType::ufd*>(
        &columns_[ColumnIndex::ufd]);
  }
  TypedColumn<int64_t>* mutable_fd() {
    return static_cast<ColumnType::fd*>(
        &columns_[ColumnIndex::fd]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_path() {
    return static_cast<ColumnType::path*>(
        &columns_[ColumnIndex::path]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ufd::stored_type> ufd_;
  ColumnStorage<ColumnType::fd::stored_type> fd_;
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::path::stored_type> path_;
};
  

class MetadataTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t key_type = 3;
    static constexpr uint32_t int_value = 4;
    static constexpr uint32_t str_value = 5;
  };
  struct ColumnType {
    using id = IdColumn<MetadataTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using key_type = TypedColumn<StringPool::Id>;
    using int_value = TypedColumn<std::optional<int64_t>>;
    using str_value = TypedColumn<std::optional<StringPool::Id>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_name = {},
        StringPool::Id in_key_type = {},
        std::optional<int64_t> in_int_value = {},
        std::optional<StringPool::Id> in_str_value = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          name(std::move(in_name)),
          key_type(std::move(in_key_type)),
          int_value(std::move(in_int_value)),
          str_value(std::move(in_str_value)) {
      type_ = "metadata";
    }
    StringPool::Id name;
    StringPool::Id key_type;
    std::optional<int64_t> int_value;
    std::optional<StringPool::Id> str_value;

    bool operator==(const MetadataTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::key_type::Equals(key_type, other.key_type) &&
       ColumnType::int_value::Equals(int_value, other.int_value) &&
       ColumnType::str_value::Equals(str_value, other.str_value);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t key_type = ColumnType::key_type::default_flags();
    static constexpr uint32_t int_value = ColumnType::int_value::default_flags();
    static constexpr uint32_t str_value = ColumnType::str_value::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      MetadataTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    MetadataTable, RowNumber> {
   public:
    ConstRowReference(const MetadataTable* table, uint32_t row_number)
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
    ColumnType::key_type::type key_type() const {
      return table_->key_type()[row_number_];
    }
    ColumnType::int_value::type int_value() const {
      return table_->int_value()[row_number_];
    }
    ColumnType::str_value::type str_value() const {
      return table_->str_value()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const MetadataTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_key_type(
        ColumnType::key_type::non_optional_type v) {
      return mutable_table()->mutable_key_type()->Set(row_number_, v);
    }
    void set_int_value(
        ColumnType::int_value::non_optional_type v) {
      return mutable_table()->mutable_int_value()->Set(row_number_, v);
    }
    void set_str_value(
        ColumnType::str_value::non_optional_type v) {
      return mutable_table()->mutable_str_value()->Set(row_number_, v);
    }

   private:
    MetadataTable* mutable_table() const {
      return const_cast<MetadataTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, MetadataTable, RowNumber, ConstRowReference> {
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
    ColumnType::key_type::type key_type() const {
      const auto& col = table_->key_type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::int_value::type int_value() const {
      const auto& col = table_->int_value();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::str_value::type str_value() const {
      const auto& col = table_->str_value();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const MetadataTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class MetadataTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, MetadataTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_key_type(ColumnType::key_type::non_optional_type v) {
        auto* col = mutable_table_->mutable_key_type();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_int_value(ColumnType::int_value::non_optional_type v) {
        auto* col = mutable_table_->mutable_int_value();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_str_value(ColumnType::str_value::non_optional_type v) {
        auto* col = mutable_table_->mutable_str_value();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class MetadataTable;

    explicit Iterator(MetadataTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    MetadataTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit MetadataTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        key_type_(ColumnStorage<ColumnType::key_type::stored_type>::Create<false>()),
        int_value_(ColumnStorage<ColumnType::int_value::stored_type>::Create<false>()),
        str_value_(ColumnStorage<ColumnType::str_value::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::key_type::stored_type>(
          ColumnFlag::key_type),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::int_value::stored_type>(
          ColumnFlag::int_value),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::str_value::stored_type>(
          ColumnFlag::str_value),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("key_type", &key_type_, ColumnFlag::key_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("int_value", &int_value_, ColumnFlag::int_value,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("str_value", &str_value_, ColumnFlag::str_value,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~MetadataTable() override;

  static const char* Name() { return "metadata"; }

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
        "key_type", ColumnType::key_type::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "int_value", ColumnType::int_value::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "str_value", ColumnType::str_value::SqlValueType(), false,
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
    key_type_.ShrinkToFit();
    int_value_.ShrinkToFit();
    str_value_.ShrinkToFit();
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
    mutable_key_type()->Append(std::move(row.key_type));
    mutable_int_value()->Append(std::move(row.int_value));
    mutable_str_value()->Append(std::move(row.str_value));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<MetadataTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<StringPool::Id>& key_type() const {
    return static_cast<const ColumnType::key_type&>(columns_[ColumnIndex::key_type]);
  }
  const TypedColumn<std::optional<int64_t>>& int_value() const {
    return static_cast<const ColumnType::int_value&>(columns_[ColumnIndex::int_value]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& str_value() const {
    return static_cast<const ColumnType::str_value&>(columns_[ColumnIndex::str_value]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<StringPool::Id>* mutable_key_type() {
    return static_cast<ColumnType::key_type*>(
        &columns_[ColumnIndex::key_type]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_int_value() {
    return static_cast<ColumnType::int_value*>(
        &columns_[ColumnIndex::int_value]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_str_value() {
    return static_cast<ColumnType::str_value*>(
        &columns_[ColumnIndex::str_value]);
  }

 private:
  
  
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::key_type::stored_type> key_type_;
  ColumnStorage<ColumnType::int_value::stored_type> int_value_;
  ColumnStorage<ColumnType::str_value::stored_type> str_value_;
};
  

class RawTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t name = 3;
    static constexpr uint32_t cpu = 4;
    static constexpr uint32_t utid = 5;
    static constexpr uint32_t arg_set_id = 6;
    static constexpr uint32_t common_flags = 7;
  };
  struct ColumnType {
    using id = IdColumn<RawTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using name = TypedColumn<StringPool::Id>;
    using cpu = TypedColumn<uint32_t>;
    using utid = TypedColumn<uint32_t>;
    using arg_set_id = TypedColumn<uint32_t>;
    using common_flags = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        StringPool::Id in_name = {},
        uint32_t in_cpu = {},
        uint32_t in_utid = {},
        uint32_t in_arg_set_id = {},
        uint32_t in_common_flags = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          name(std::move(in_name)),
          cpu(std::move(in_cpu)),
          utid(std::move(in_utid)),
          arg_set_id(std::move(in_arg_set_id)),
          common_flags(std::move(in_common_flags)) {
      type_ = "raw";
    }
    int64_t ts;
    StringPool::Id name;
    uint32_t cpu;
    uint32_t utid;
    uint32_t arg_set_id;
    uint32_t common_flags;

    bool operator==(const RawTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::cpu::Equals(cpu, other.cpu) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::common_flags::Equals(common_flags, other.common_flags);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::ts::default_flags();
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t cpu = ColumnType::cpu::default_flags();
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
    static constexpr uint32_t arg_set_id = ColumnType::arg_set_id::default_flags();
    static constexpr uint32_t common_flags = ColumnType::common_flags::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      RawTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    RawTable, RowNumber> {
   public:
    ConstRowReference(const RawTable* table, uint32_t row_number)
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
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::cpu::type cpu() const {
      return table_->cpu()[row_number_];
    }
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::common_flags::type common_flags() const {
      return table_->common_flags()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const RawTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_cpu(
        ColumnType::cpu::non_optional_type v) {
      return mutable_table()->mutable_cpu()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_common_flags(
        ColumnType::common_flags::non_optional_type v) {
      return mutable_table()->mutable_common_flags()->Set(row_number_, v);
    }

   private:
    RawTable* mutable_table() const {
      return const_cast<RawTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, RawTable, RowNumber, ConstRowReference> {
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
    ColumnType::name::type name() const {
      const auto& col = table_->name();
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
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::common_flags::type common_flags() const {
      const auto& col = table_->common_flags();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const RawTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class RawTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, RawTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
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
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_common_flags(ColumnType::common_flags::non_optional_type v) {
        auto* col = mutable_table_->mutable_common_flags();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class RawTable;

    explicit Iterator(RawTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    RawTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit RawTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        cpu_(ColumnStorage<ColumnType::cpu::stored_type>::Create<false>()),
        utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()),
        arg_set_id_(ColumnStorage<ColumnType::arg_set_id::stored_type>::Create<false>()),
        common_flags_(ColumnStorage<ColumnType::common_flags::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
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
        Column::IsFlagsAndTypeValid<ColumnType::arg_set_id::stored_type>(
          ColumnFlag::arg_set_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::common_flags::stored_type>(
          ColumnFlag::common_flags),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("arg_set_id", &arg_set_id_, ColumnFlag::arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("common_flags", &common_flags_, ColumnFlag::common_flags,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~RawTable() override;

  static const char* Name() { return "raw"; }

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
        "name", ColumnType::name::SqlValueType(), false,
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
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "common_flags", ColumnType::common_flags::SqlValueType(), false,
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
    name_.ShrinkToFit();
    cpu_.ShrinkToFit();
    utid_.ShrinkToFit();
    arg_set_id_.ShrinkToFit();
    common_flags_.ShrinkToFit();
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
    mutable_name()->Append(std::move(row.name));
    mutable_cpu()->Append(std::move(row.cpu));
    mutable_utid()->Append(std::move(row.utid));
    mutable_arg_set_id()->Append(std::move(row.arg_set_id));
    mutable_common_flags()->Append(std::move(row.common_flags));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<RawTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<uint32_t>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<uint32_t>& common_flags() const {
    return static_cast<const ColumnType::common_flags&>(columns_[ColumnIndex::common_flags]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<uint32_t>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<uint32_t>* mutable_common_flags() {
    return static_cast<ColumnType::common_flags*>(
        &columns_[ColumnIndex::common_flags]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::cpu::stored_type> cpu_;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
  ColumnStorage<ColumnType::arg_set_id::stored_type> arg_set_id_;
  ColumnStorage<ColumnType::common_flags::stored_type> common_flags_;
};
  

class FtraceEventTable : public macros_internal::MacroTable {
 public:
  using Id = RawTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t name = 3;
    static constexpr uint32_t cpu = 4;
    static constexpr uint32_t utid = 5;
    static constexpr uint32_t arg_set_id = 6;
    static constexpr uint32_t common_flags = 7;
  };
  struct ColumnType {
    using id = IdColumn<FtraceEventTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using name = TypedColumn<StringPool::Id>;
    using cpu = TypedColumn<uint32_t>;
    using utid = TypedColumn<uint32_t>;
    using arg_set_id = TypedColumn<uint32_t>;
    using common_flags = TypedColumn<uint32_t>;
  };
  struct Row : public RawTable::Row {
    Row(int64_t in_ts = {},
        StringPool::Id in_name = {},
        uint32_t in_cpu = {},
        uint32_t in_utid = {},
        uint32_t in_arg_set_id = {},
        uint32_t in_common_flags = {},
        std::nullptr_t = nullptr)
        : RawTable::Row(std::move(in_ts), std::move(in_name), std::move(in_cpu), std::move(in_utid), std::move(in_arg_set_id), std::move(in_common_flags))
           {
      type_ = "ftrace_event";
    }
    

    bool operator==(const FtraceEventTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::cpu::Equals(cpu, other.cpu) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::common_flags::Equals(common_flags, other.common_flags);
    }
  };
  struct ColumnFlag {
    
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      FtraceEventTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    FtraceEventTable, RowNumber> {
   public:
    ConstRowReference(const FtraceEventTable* table, uint32_t row_number)
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
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::cpu::type cpu() const {
      return table_->cpu()[row_number_];
    }
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
    ColumnType::arg_set_id::type arg_set_id() const {
      return table_->arg_set_id()[row_number_];
    }
    ColumnType::common_flags::type common_flags() const {
      return table_->common_flags()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const FtraceEventTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_cpu(
        ColumnType::cpu::non_optional_type v) {
      return mutable_table()->mutable_cpu()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }
    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_common_flags(
        ColumnType::common_flags::non_optional_type v) {
      return mutable_table()->mutable_common_flags()->Set(row_number_, v);
    }

   private:
    FtraceEventTable* mutable_table() const {
      return const_cast<FtraceEventTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, FtraceEventTable, RowNumber, ConstRowReference> {
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
    ColumnType::name::type name() const {
      const auto& col = table_->name();
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
    ColumnType::arg_set_id::type arg_set_id() const {
      const auto& col = table_->arg_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::common_flags::type common_flags() const {
      const auto& col = table_->common_flags();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const FtraceEventTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class FtraceEventTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, FtraceEventTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
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
      void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_common_flags(ColumnType::common_flags::non_optional_type v) {
        auto* col = mutable_table_->mutable_common_flags();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class FtraceEventTable;

    explicit Iterator(FtraceEventTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    FtraceEventTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit FtraceEventTable(StringPool* pool, RawTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent) {
    
    
    
  }
  ~FtraceEventTable() override;

  static const char* Name() { return "ftrace_event"; }

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
        "name", ColumnType::name::SqlValueType(), false,
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
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "common_flags", ColumnType::common_flags::SqlValueType(), false,
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
    
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const RawTable& parent
      ) {
    return std::unique_ptr<Table>(new FtraceEventTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count())
        ));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const RawTable& parent,
      std::vector<RawTable::RowNumber> parent_overlay
      ) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new FtraceEventTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped))
        ));
  }

  const IdColumn<FtraceEventTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<uint32_t>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }
  const TypedColumn<uint32_t>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<uint32_t>& common_flags() const {
    return static_cast<const ColumnType::common_flags&>(columns_[ColumnIndex::common_flags]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<uint32_t>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<uint32_t>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<uint32_t>* mutable_common_flags() {
    return static_cast<ColumnType::common_flags*>(
        &columns_[ColumnIndex::common_flags]);
  }

 private:
  FtraceEventTable(StringPool* pool,
            const RawTable& parent,
            const RowMap& parent_overlay
            )
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    
    

    
    
  }
  RawTable* parent_ = nullptr;
  
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_METADATA_TABLES_PY_H_

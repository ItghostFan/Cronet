#ifndef SRC_TRACE_PROCESSOR_TABLES_ANDROID_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_ANDROID_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"

#include "src/trace_processor/tables/metadata_tables_py.h"

namespace perfetto {
namespace trace_processor {
namespace tables {

class AndroidLogTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t utid = 3;
    static constexpr uint32_t prio = 4;
    static constexpr uint32_t tag = 5;
    static constexpr uint32_t msg = 6;
  };
  struct ColumnType {
    using id = IdColumn<AndroidLogTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using utid = TypedColumn<uint32_t>;
    using prio = TypedColumn<uint32_t>;
    using tag = TypedColumn<std::optional<StringPool::Id>>;
    using msg = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        uint32_t in_utid = {},
        uint32_t in_prio = {},
        std::optional<StringPool::Id> in_tag = {},
        StringPool::Id in_msg = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          utid(std::move(in_utid)),
          prio(std::move(in_prio)),
          tag(std::move(in_tag)),
          msg(std::move(in_msg)) {
      type_ = "android_logs";
    }
    int64_t ts;
    uint32_t utid;
    uint32_t prio;
    std::optional<StringPool::Id> tag;
    StringPool::Id msg;

    bool operator==(const AndroidLogTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::prio::Equals(prio, other.prio) &&
       ColumnType::tag::Equals(tag, other.tag) &&
       ColumnType::msg::Equals(msg, other.msg);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = ColumnType::ts::default_flags();
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
    static constexpr uint32_t prio = ColumnType::prio::default_flags();
    static constexpr uint32_t tag = ColumnType::tag::default_flags();
    static constexpr uint32_t msg = ColumnType::msg::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      AndroidLogTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    AndroidLogTable, RowNumber> {
   public:
    ConstRowReference(const AndroidLogTable* table, uint32_t row_number)
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
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
    ColumnType::prio::type prio() const {
      return table_->prio()[row_number_];
    }
    ColumnType::tag::type tag() const {
      return table_->tag()[row_number_];
    }
    ColumnType::msg::type msg() const {
      return table_->msg()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const AndroidLogTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }
    void set_prio(
        ColumnType::prio::non_optional_type v) {
      return mutable_table()->mutable_prio()->Set(row_number_, v);
    }
    void set_tag(
        ColumnType::tag::non_optional_type v) {
      return mutable_table()->mutable_tag()->Set(row_number_, v);
    }
    void set_msg(
        ColumnType::msg::non_optional_type v) {
      return mutable_table()->mutable_msg()->Set(row_number_, v);
    }

   private:
    AndroidLogTable* mutable_table() const {
      return const_cast<AndroidLogTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, AndroidLogTable, RowNumber, ConstRowReference> {
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
    ColumnType::utid::type utid() const {
      const auto& col = table_->utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::prio::type prio() const {
      const auto& col = table_->prio();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::tag::type tag() const {
      const auto& col = table_->tag();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::msg::type msg() const {
      const auto& col = table_->msg();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const AndroidLogTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class AndroidLogTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, AndroidLogTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_utid(ColumnType::utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_prio(ColumnType::prio::non_optional_type v) {
        auto* col = mutable_table_->mutable_prio();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_tag(ColumnType::tag::non_optional_type v) {
        auto* col = mutable_table_->mutable_tag();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_msg(ColumnType::msg::non_optional_type v) {
        auto* col = mutable_table_->mutable_msg();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class AndroidLogTable;

    explicit Iterator(AndroidLogTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    AndroidLogTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit AndroidLogTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()),
        prio_(ColumnStorage<ColumnType::prio::stored_type>::Create<false>()),
        tag_(ColumnStorage<ColumnType::tag::stored_type>::Create<false>()),
        msg_(ColumnStorage<ColumnType::msg::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::prio::stored_type>(
          ColumnFlag::prio),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::tag::stored_type>(
          ColumnFlag::tag),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::msg::stored_type>(
          ColumnFlag::msg),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("prio", &prio_, ColumnFlag::prio,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("tag", &tag_, ColumnFlag::tag,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("msg", &msg_, ColumnFlag::msg,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~AndroidLogTable() override;

  static const char* Name() { return "android_logs"; }

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
        "utid", ColumnType::utid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "prio", ColumnType::prio::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "tag", ColumnType::tag::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "msg", ColumnType::msg::SqlValueType(), false,
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
    utid_.ShrinkToFit();
    prio_.ShrinkToFit();
    tag_.ShrinkToFit();
    msg_.ShrinkToFit();
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
    mutable_utid()->Append(std::move(row.utid));
    mutable_prio()->Append(std::move(row.prio));
    mutable_tag()->Append(std::move(row.tag));
    mutable_msg()->Append(std::move(row.msg));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<AndroidLogTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }
  const TypedColumn<uint32_t>& prio() const {
    return static_cast<const ColumnType::prio&>(columns_[ColumnIndex::prio]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& tag() const {
    return static_cast<const ColumnType::tag&>(columns_[ColumnIndex::tag]);
  }
  const TypedColumn<StringPool::Id>& msg() const {
    return static_cast<const ColumnType::msg&>(columns_[ColumnIndex::msg]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<uint32_t>* mutable_prio() {
    return static_cast<ColumnType::prio*>(
        &columns_[ColumnIndex::prio]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_tag() {
    return static_cast<ColumnType::tag*>(
        &columns_[ColumnIndex::tag]);
  }
  TypedColumn<StringPool::Id>* mutable_msg() {
    return static_cast<ColumnType::msg*>(
        &columns_[ColumnIndex::msg]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
  ColumnStorage<ColumnType::prio::stored_type> prio_;
  ColumnStorage<ColumnType::tag::stored_type> tag_;
  ColumnStorage<ColumnType::msg::stored_type> msg_;
};
  

class AndroidDumpstateTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t section = 2;
    static constexpr uint32_t service = 3;
    static constexpr uint32_t line = 4;
  };
  struct ColumnType {
    using id = IdColumn<AndroidDumpstateTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using section = TypedColumn<std::optional<StringPool::Id>>;
    using service = TypedColumn<std::optional<StringPool::Id>>;
    using line = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(std::optional<StringPool::Id> in_section = {},
        std::optional<StringPool::Id> in_service = {},
        StringPool::Id in_line = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          section(std::move(in_section)),
          service(std::move(in_service)),
          line(std::move(in_line)) {
      type_ = "android_dumpstate";
    }
    std::optional<StringPool::Id> section;
    std::optional<StringPool::Id> service;
    StringPool::Id line;

    bool operator==(const AndroidDumpstateTable::Row& other) const {
      return type() == other.type() && ColumnType::section::Equals(section, other.section) &&
       ColumnType::service::Equals(service, other.service) &&
       ColumnType::line::Equals(line, other.line);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t section = ColumnType::section::default_flags();
    static constexpr uint32_t service = ColumnType::service::default_flags();
    static constexpr uint32_t line = ColumnType::line::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      AndroidDumpstateTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    AndroidDumpstateTable, RowNumber> {
   public:
    ConstRowReference(const AndroidDumpstateTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::section::type section() const {
      return table_->section()[row_number_];
    }
    ColumnType::service::type service() const {
      return table_->service()[row_number_];
    }
    ColumnType::line::type line() const {
      return table_->line()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const AndroidDumpstateTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_section(
        ColumnType::section::non_optional_type v) {
      return mutable_table()->mutable_section()->Set(row_number_, v);
    }
    void set_service(
        ColumnType::service::non_optional_type v) {
      return mutable_table()->mutable_service()->Set(row_number_, v);
    }
    void set_line(
        ColumnType::line::non_optional_type v) {
      return mutable_table()->mutable_line()->Set(row_number_, v);
    }

   private:
    AndroidDumpstateTable* mutable_table() const {
      return const_cast<AndroidDumpstateTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, AndroidDumpstateTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::section::type section() const {
      const auto& col = table_->section();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::service::type service() const {
      const auto& col = table_->service();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::line::type line() const {
      const auto& col = table_->line();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const AndroidDumpstateTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class AndroidDumpstateTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, AndroidDumpstateTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_section(ColumnType::section::non_optional_type v) {
        auto* col = mutable_table_->mutable_section();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_service(ColumnType::service::non_optional_type v) {
        auto* col = mutable_table_->mutable_service();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_line(ColumnType::line::non_optional_type v) {
        auto* col = mutable_table_->mutable_line();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class AndroidDumpstateTable;

    explicit Iterator(AndroidDumpstateTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    AndroidDumpstateTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit AndroidDumpstateTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        section_(ColumnStorage<ColumnType::section::stored_type>::Create<false>()),
        service_(ColumnStorage<ColumnType::service::stored_type>::Create<false>()),
        line_(ColumnStorage<ColumnType::line::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::section::stored_type>(
          ColumnFlag::section),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::service::stored_type>(
          ColumnFlag::service),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::line::stored_type>(
          ColumnFlag::line),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("section", &section_, ColumnFlag::section,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("service", &service_, ColumnFlag::service,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("line", &line_, ColumnFlag::line,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~AndroidDumpstateTable() override;

  static const char* Name() { return "android_dumpstate"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "section", ColumnType::section::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "service", ColumnType::service::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "line", ColumnType::line::SqlValueType(), false,
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
    section_.ShrinkToFit();
    service_.ShrinkToFit();
    line_.ShrinkToFit();
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
    mutable_section()->Append(std::move(row.section));
    mutable_service()->Append(std::move(row.service));
    mutable_line()->Append(std::move(row.line));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<AndroidDumpstateTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& section() const {
    return static_cast<const ColumnType::section&>(columns_[ColumnIndex::section]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& service() const {
    return static_cast<const ColumnType::service&>(columns_[ColumnIndex::service]);
  }
  const TypedColumn<StringPool::Id>& line() const {
    return static_cast<const ColumnType::line&>(columns_[ColumnIndex::line]);
  }

  TypedColumn<std::optional<StringPool::Id>>* mutable_section() {
    return static_cast<ColumnType::section*>(
        &columns_[ColumnIndex::section]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_service() {
    return static_cast<ColumnType::service*>(
        &columns_[ColumnIndex::service]);
  }
  TypedColumn<StringPool::Id>* mutable_line() {
    return static_cast<ColumnType::line*>(
        &columns_[ColumnIndex::line]);
  }

 private:
  
  
  ColumnStorage<ColumnType::section::stored_type> section_;
  ColumnStorage<ColumnType::service::stored_type> service_;
  ColumnStorage<ColumnType::line::stored_type> line_;
};
  

class AndroidGameInterventionListTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t package_name = 2;
    static constexpr uint32_t uid = 3;
    static constexpr uint32_t current_mode = 4;
    static constexpr uint32_t standard_mode_supported = 5;
    static constexpr uint32_t standard_mode_downscale = 6;
    static constexpr uint32_t standard_mode_use_angle = 7;
    static constexpr uint32_t standard_mode_fps = 8;
    static constexpr uint32_t perf_mode_supported = 9;
    static constexpr uint32_t perf_mode_downscale = 10;
    static constexpr uint32_t perf_mode_use_angle = 11;
    static constexpr uint32_t perf_mode_fps = 12;
    static constexpr uint32_t battery_mode_supported = 13;
    static constexpr uint32_t battery_mode_downscale = 14;
    static constexpr uint32_t battery_mode_use_angle = 15;
    static constexpr uint32_t battery_mode_fps = 16;
  };
  struct ColumnType {
    using id = IdColumn<AndroidGameInterventionListTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using package_name = TypedColumn<StringPool::Id>;
    using uid = TypedColumn<int64_t>;
    using current_mode = TypedColumn<int32_t>;
    using standard_mode_supported = TypedColumn<int32_t>;
    using standard_mode_downscale = TypedColumn<std::optional<double>>;
    using standard_mode_use_angle = TypedColumn<std::optional<int32_t>>;
    using standard_mode_fps = TypedColumn<std::optional<double>>;
    using perf_mode_supported = TypedColumn<int32_t>;
    using perf_mode_downscale = TypedColumn<std::optional<double>>;
    using perf_mode_use_angle = TypedColumn<std::optional<int32_t>>;
    using perf_mode_fps = TypedColumn<std::optional<double>>;
    using battery_mode_supported = TypedColumn<int32_t>;
    using battery_mode_downscale = TypedColumn<std::optional<double>>;
    using battery_mode_use_angle = TypedColumn<std::optional<int32_t>>;
    using battery_mode_fps = TypedColumn<std::optional<double>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_package_name = {},
        int64_t in_uid = {},
        int32_t in_current_mode = {},
        int32_t in_standard_mode_supported = {},
        std::optional<double> in_standard_mode_downscale = {},
        std::optional<int32_t> in_standard_mode_use_angle = {},
        std::optional<double> in_standard_mode_fps = {},
        int32_t in_perf_mode_supported = {},
        std::optional<double> in_perf_mode_downscale = {},
        std::optional<int32_t> in_perf_mode_use_angle = {},
        std::optional<double> in_perf_mode_fps = {},
        int32_t in_battery_mode_supported = {},
        std::optional<double> in_battery_mode_downscale = {},
        std::optional<int32_t> in_battery_mode_use_angle = {},
        std::optional<double> in_battery_mode_fps = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          package_name(std::move(in_package_name)),
          uid(std::move(in_uid)),
          current_mode(std::move(in_current_mode)),
          standard_mode_supported(std::move(in_standard_mode_supported)),
          standard_mode_downscale(std::move(in_standard_mode_downscale)),
          standard_mode_use_angle(std::move(in_standard_mode_use_angle)),
          standard_mode_fps(std::move(in_standard_mode_fps)),
          perf_mode_supported(std::move(in_perf_mode_supported)),
          perf_mode_downscale(std::move(in_perf_mode_downscale)),
          perf_mode_use_angle(std::move(in_perf_mode_use_angle)),
          perf_mode_fps(std::move(in_perf_mode_fps)),
          battery_mode_supported(std::move(in_battery_mode_supported)),
          battery_mode_downscale(std::move(in_battery_mode_downscale)),
          battery_mode_use_angle(std::move(in_battery_mode_use_angle)),
          battery_mode_fps(std::move(in_battery_mode_fps)) {
      type_ = "android_game_intervention_list";
    }
    StringPool::Id package_name;
    int64_t uid;
    int32_t current_mode;
    int32_t standard_mode_supported;
    std::optional<double> standard_mode_downscale;
    std::optional<int32_t> standard_mode_use_angle;
    std::optional<double> standard_mode_fps;
    int32_t perf_mode_supported;
    std::optional<double> perf_mode_downscale;
    std::optional<int32_t> perf_mode_use_angle;
    std::optional<double> perf_mode_fps;
    int32_t battery_mode_supported;
    std::optional<double> battery_mode_downscale;
    std::optional<int32_t> battery_mode_use_angle;
    std::optional<double> battery_mode_fps;

    bool operator==(const AndroidGameInterventionListTable::Row& other) const {
      return type() == other.type() && ColumnType::package_name::Equals(package_name, other.package_name) &&
       ColumnType::uid::Equals(uid, other.uid) &&
       ColumnType::current_mode::Equals(current_mode, other.current_mode) &&
       ColumnType::standard_mode_supported::Equals(standard_mode_supported, other.standard_mode_supported) &&
       ColumnType::standard_mode_downscale::Equals(standard_mode_downscale, other.standard_mode_downscale) &&
       ColumnType::standard_mode_use_angle::Equals(standard_mode_use_angle, other.standard_mode_use_angle) &&
       ColumnType::standard_mode_fps::Equals(standard_mode_fps, other.standard_mode_fps) &&
       ColumnType::perf_mode_supported::Equals(perf_mode_supported, other.perf_mode_supported) &&
       ColumnType::perf_mode_downscale::Equals(perf_mode_downscale, other.perf_mode_downscale) &&
       ColumnType::perf_mode_use_angle::Equals(perf_mode_use_angle, other.perf_mode_use_angle) &&
       ColumnType::perf_mode_fps::Equals(perf_mode_fps, other.perf_mode_fps) &&
       ColumnType::battery_mode_supported::Equals(battery_mode_supported, other.battery_mode_supported) &&
       ColumnType::battery_mode_downscale::Equals(battery_mode_downscale, other.battery_mode_downscale) &&
       ColumnType::battery_mode_use_angle::Equals(battery_mode_use_angle, other.battery_mode_use_angle) &&
       ColumnType::battery_mode_fps::Equals(battery_mode_fps, other.battery_mode_fps);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t package_name = ColumnType::package_name::default_flags();
    static constexpr uint32_t uid = ColumnType::uid::default_flags();
    static constexpr uint32_t current_mode = ColumnType::current_mode::default_flags();
    static constexpr uint32_t standard_mode_supported = ColumnType::standard_mode_supported::default_flags();
    static constexpr uint32_t standard_mode_downscale = ColumnType::standard_mode_downscale::default_flags();
    static constexpr uint32_t standard_mode_use_angle = ColumnType::standard_mode_use_angle::default_flags();
    static constexpr uint32_t standard_mode_fps = ColumnType::standard_mode_fps::default_flags();
    static constexpr uint32_t perf_mode_supported = ColumnType::perf_mode_supported::default_flags();
    static constexpr uint32_t perf_mode_downscale = ColumnType::perf_mode_downscale::default_flags();
    static constexpr uint32_t perf_mode_use_angle = ColumnType::perf_mode_use_angle::default_flags();
    static constexpr uint32_t perf_mode_fps = ColumnType::perf_mode_fps::default_flags();
    static constexpr uint32_t battery_mode_supported = ColumnType::battery_mode_supported::default_flags();
    static constexpr uint32_t battery_mode_downscale = ColumnType::battery_mode_downscale::default_flags();
    static constexpr uint32_t battery_mode_use_angle = ColumnType::battery_mode_use_angle::default_flags();
    static constexpr uint32_t battery_mode_fps = ColumnType::battery_mode_fps::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      AndroidGameInterventionListTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    AndroidGameInterventionListTable, RowNumber> {
   public:
    ConstRowReference(const AndroidGameInterventionListTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::package_name::type package_name() const {
      return table_->package_name()[row_number_];
    }
    ColumnType::uid::type uid() const {
      return table_->uid()[row_number_];
    }
    ColumnType::current_mode::type current_mode() const {
      return table_->current_mode()[row_number_];
    }
    ColumnType::standard_mode_supported::type standard_mode_supported() const {
      return table_->standard_mode_supported()[row_number_];
    }
    ColumnType::standard_mode_downscale::type standard_mode_downscale() const {
      return table_->standard_mode_downscale()[row_number_];
    }
    ColumnType::standard_mode_use_angle::type standard_mode_use_angle() const {
      return table_->standard_mode_use_angle()[row_number_];
    }
    ColumnType::standard_mode_fps::type standard_mode_fps() const {
      return table_->standard_mode_fps()[row_number_];
    }
    ColumnType::perf_mode_supported::type perf_mode_supported() const {
      return table_->perf_mode_supported()[row_number_];
    }
    ColumnType::perf_mode_downscale::type perf_mode_downscale() const {
      return table_->perf_mode_downscale()[row_number_];
    }
    ColumnType::perf_mode_use_angle::type perf_mode_use_angle() const {
      return table_->perf_mode_use_angle()[row_number_];
    }
    ColumnType::perf_mode_fps::type perf_mode_fps() const {
      return table_->perf_mode_fps()[row_number_];
    }
    ColumnType::battery_mode_supported::type battery_mode_supported() const {
      return table_->battery_mode_supported()[row_number_];
    }
    ColumnType::battery_mode_downscale::type battery_mode_downscale() const {
      return table_->battery_mode_downscale()[row_number_];
    }
    ColumnType::battery_mode_use_angle::type battery_mode_use_angle() const {
      return table_->battery_mode_use_angle()[row_number_];
    }
    ColumnType::battery_mode_fps::type battery_mode_fps() const {
      return table_->battery_mode_fps()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const AndroidGameInterventionListTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_package_name(
        ColumnType::package_name::non_optional_type v) {
      return mutable_table()->mutable_package_name()->Set(row_number_, v);
    }
    void set_uid(
        ColumnType::uid::non_optional_type v) {
      return mutable_table()->mutable_uid()->Set(row_number_, v);
    }
    void set_current_mode(
        ColumnType::current_mode::non_optional_type v) {
      return mutable_table()->mutable_current_mode()->Set(row_number_, v);
    }
    void set_standard_mode_supported(
        ColumnType::standard_mode_supported::non_optional_type v) {
      return mutable_table()->mutable_standard_mode_supported()->Set(row_number_, v);
    }
    void set_standard_mode_downscale(
        ColumnType::standard_mode_downscale::non_optional_type v) {
      return mutable_table()->mutable_standard_mode_downscale()->Set(row_number_, v);
    }
    void set_standard_mode_use_angle(
        ColumnType::standard_mode_use_angle::non_optional_type v) {
      return mutable_table()->mutable_standard_mode_use_angle()->Set(row_number_, v);
    }
    void set_standard_mode_fps(
        ColumnType::standard_mode_fps::non_optional_type v) {
      return mutable_table()->mutable_standard_mode_fps()->Set(row_number_, v);
    }
    void set_perf_mode_supported(
        ColumnType::perf_mode_supported::non_optional_type v) {
      return mutable_table()->mutable_perf_mode_supported()->Set(row_number_, v);
    }
    void set_perf_mode_downscale(
        ColumnType::perf_mode_downscale::non_optional_type v) {
      return mutable_table()->mutable_perf_mode_downscale()->Set(row_number_, v);
    }
    void set_perf_mode_use_angle(
        ColumnType::perf_mode_use_angle::non_optional_type v) {
      return mutable_table()->mutable_perf_mode_use_angle()->Set(row_number_, v);
    }
    void set_perf_mode_fps(
        ColumnType::perf_mode_fps::non_optional_type v) {
      return mutable_table()->mutable_perf_mode_fps()->Set(row_number_, v);
    }
    void set_battery_mode_supported(
        ColumnType::battery_mode_supported::non_optional_type v) {
      return mutable_table()->mutable_battery_mode_supported()->Set(row_number_, v);
    }
    void set_battery_mode_downscale(
        ColumnType::battery_mode_downscale::non_optional_type v) {
      return mutable_table()->mutable_battery_mode_downscale()->Set(row_number_, v);
    }
    void set_battery_mode_use_angle(
        ColumnType::battery_mode_use_angle::non_optional_type v) {
      return mutable_table()->mutable_battery_mode_use_angle()->Set(row_number_, v);
    }
    void set_battery_mode_fps(
        ColumnType::battery_mode_fps::non_optional_type v) {
      return mutable_table()->mutable_battery_mode_fps()->Set(row_number_, v);
    }

   private:
    AndroidGameInterventionListTable* mutable_table() const {
      return const_cast<AndroidGameInterventionListTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, AndroidGameInterventionListTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::package_name::type package_name() const {
      const auto& col = table_->package_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::uid::type uid() const {
      const auto& col = table_->uid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::current_mode::type current_mode() const {
      const auto& col = table_->current_mode();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::standard_mode_supported::type standard_mode_supported() const {
      const auto& col = table_->standard_mode_supported();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::standard_mode_downscale::type standard_mode_downscale() const {
      const auto& col = table_->standard_mode_downscale();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::standard_mode_use_angle::type standard_mode_use_angle() const {
      const auto& col = table_->standard_mode_use_angle();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::standard_mode_fps::type standard_mode_fps() const {
      const auto& col = table_->standard_mode_fps();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::perf_mode_supported::type perf_mode_supported() const {
      const auto& col = table_->perf_mode_supported();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::perf_mode_downscale::type perf_mode_downscale() const {
      const auto& col = table_->perf_mode_downscale();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::perf_mode_use_angle::type perf_mode_use_angle() const {
      const auto& col = table_->perf_mode_use_angle();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::perf_mode_fps::type perf_mode_fps() const {
      const auto& col = table_->perf_mode_fps();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::battery_mode_supported::type battery_mode_supported() const {
      const auto& col = table_->battery_mode_supported();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::battery_mode_downscale::type battery_mode_downscale() const {
      const auto& col = table_->battery_mode_downscale();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::battery_mode_use_angle::type battery_mode_use_angle() const {
      const auto& col = table_->battery_mode_use_angle();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::battery_mode_fps::type battery_mode_fps() const {
      const auto& col = table_->battery_mode_fps();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const AndroidGameInterventionListTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class AndroidGameInterventionListTable;
    friend class macros_internal::AbstractConstIterator<
      ConstIterator, AndroidGameInterventionListTable, RowNumber, ConstRowReference>;
  };
  class Iterator : public ConstIterator {
    public:
    void set_package_name(ColumnType::package_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_package_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_uid(ColumnType::uid::non_optional_type v) {
        auto* col = mutable_table_->mutable_uid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_current_mode(ColumnType::current_mode::non_optional_type v) {
        auto* col = mutable_table_->mutable_current_mode();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_standard_mode_supported(ColumnType::standard_mode_supported::non_optional_type v) {
        auto* col = mutable_table_->mutable_standard_mode_supported();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_standard_mode_downscale(ColumnType::standard_mode_downscale::non_optional_type v) {
        auto* col = mutable_table_->mutable_standard_mode_downscale();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_standard_mode_use_angle(ColumnType::standard_mode_use_angle::non_optional_type v) {
        auto* col = mutable_table_->mutable_standard_mode_use_angle();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_standard_mode_fps(ColumnType::standard_mode_fps::non_optional_type v) {
        auto* col = mutable_table_->mutable_standard_mode_fps();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_perf_mode_supported(ColumnType::perf_mode_supported::non_optional_type v) {
        auto* col = mutable_table_->mutable_perf_mode_supported();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_perf_mode_downscale(ColumnType::perf_mode_downscale::non_optional_type v) {
        auto* col = mutable_table_->mutable_perf_mode_downscale();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_perf_mode_use_angle(ColumnType::perf_mode_use_angle::non_optional_type v) {
        auto* col = mutable_table_->mutable_perf_mode_use_angle();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_perf_mode_fps(ColumnType::perf_mode_fps::non_optional_type v) {
        auto* col = mutable_table_->mutable_perf_mode_fps();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_battery_mode_supported(ColumnType::battery_mode_supported::non_optional_type v) {
        auto* col = mutable_table_->mutable_battery_mode_supported();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_battery_mode_downscale(ColumnType::battery_mode_downscale::non_optional_type v) {
        auto* col = mutable_table_->mutable_battery_mode_downscale();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_battery_mode_use_angle(ColumnType::battery_mode_use_angle::non_optional_type v) {
        auto* col = mutable_table_->mutable_battery_mode_use_angle();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_battery_mode_fps(ColumnType::battery_mode_fps::non_optional_type v) {
        auto* col = mutable_table_->mutable_battery_mode_fps();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class AndroidGameInterventionListTable;

    explicit Iterator(AndroidGameInterventionListTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    AndroidGameInterventionListTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit AndroidGameInterventionListTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        package_name_(ColumnStorage<ColumnType::package_name::stored_type>::Create<false>()),
        uid_(ColumnStorage<ColumnType::uid::stored_type>::Create<false>()),
        current_mode_(ColumnStorage<ColumnType::current_mode::stored_type>::Create<false>()),
        standard_mode_supported_(ColumnStorage<ColumnType::standard_mode_supported::stored_type>::Create<false>()),
        standard_mode_downscale_(ColumnStorage<ColumnType::standard_mode_downscale::stored_type>::Create<false>()),
        standard_mode_use_angle_(ColumnStorage<ColumnType::standard_mode_use_angle::stored_type>::Create<false>()),
        standard_mode_fps_(ColumnStorage<ColumnType::standard_mode_fps::stored_type>::Create<false>()),
        perf_mode_supported_(ColumnStorage<ColumnType::perf_mode_supported::stored_type>::Create<false>()),
        perf_mode_downscale_(ColumnStorage<ColumnType::perf_mode_downscale::stored_type>::Create<false>()),
        perf_mode_use_angle_(ColumnStorage<ColumnType::perf_mode_use_angle::stored_type>::Create<false>()),
        perf_mode_fps_(ColumnStorage<ColumnType::perf_mode_fps::stored_type>::Create<false>()),
        battery_mode_supported_(ColumnStorage<ColumnType::battery_mode_supported::stored_type>::Create<false>()),
        battery_mode_downscale_(ColumnStorage<ColumnType::battery_mode_downscale::stored_type>::Create<false>()),
        battery_mode_use_angle_(ColumnStorage<ColumnType::battery_mode_use_angle::stored_type>::Create<false>()),
        battery_mode_fps_(ColumnStorage<ColumnType::battery_mode_fps::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::package_name::stored_type>(
          ColumnFlag::package_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::uid::stored_type>(
          ColumnFlag::uid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::current_mode::stored_type>(
          ColumnFlag::current_mode),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::standard_mode_supported::stored_type>(
          ColumnFlag::standard_mode_supported),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::standard_mode_downscale::stored_type>(
          ColumnFlag::standard_mode_downscale),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::standard_mode_use_angle::stored_type>(
          ColumnFlag::standard_mode_use_angle),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::standard_mode_fps::stored_type>(
          ColumnFlag::standard_mode_fps),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::perf_mode_supported::stored_type>(
          ColumnFlag::perf_mode_supported),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::perf_mode_downscale::stored_type>(
          ColumnFlag::perf_mode_downscale),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::perf_mode_use_angle::stored_type>(
          ColumnFlag::perf_mode_use_angle),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::perf_mode_fps::stored_type>(
          ColumnFlag::perf_mode_fps),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::battery_mode_supported::stored_type>(
          ColumnFlag::battery_mode_supported),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::battery_mode_downscale::stored_type>(
          ColumnFlag::battery_mode_downscale),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::battery_mode_use_angle::stored_type>(
          ColumnFlag::battery_mode_use_angle),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::battery_mode_fps::stored_type>(
          ColumnFlag::battery_mode_fps),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("package_name", &package_name_, ColumnFlag::package_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("uid", &uid_, ColumnFlag::uid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("current_mode", &current_mode_, ColumnFlag::current_mode,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("standard_mode_supported", &standard_mode_supported_, ColumnFlag::standard_mode_supported,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("standard_mode_downscale", &standard_mode_downscale_, ColumnFlag::standard_mode_downscale,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("standard_mode_use_angle", &standard_mode_use_angle_, ColumnFlag::standard_mode_use_angle,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("standard_mode_fps", &standard_mode_fps_, ColumnFlag::standard_mode_fps,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("perf_mode_supported", &perf_mode_supported_, ColumnFlag::perf_mode_supported,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("perf_mode_downscale", &perf_mode_downscale_, ColumnFlag::perf_mode_downscale,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("perf_mode_use_angle", &perf_mode_use_angle_, ColumnFlag::perf_mode_use_angle,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("perf_mode_fps", &perf_mode_fps_, ColumnFlag::perf_mode_fps,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("battery_mode_supported", &battery_mode_supported_, ColumnFlag::battery_mode_supported,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("battery_mode_downscale", &battery_mode_downscale_, ColumnFlag::battery_mode_downscale,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("battery_mode_use_angle", &battery_mode_use_angle_, ColumnFlag::battery_mode_use_angle,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("battery_mode_fps", &battery_mode_fps_, ColumnFlag::battery_mode_fps,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~AndroidGameInterventionListTable() override;

  static const char* Name() { return "android_game_intervention_list"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "package_name", ColumnType::package_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "uid", ColumnType::uid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "current_mode", ColumnType::current_mode::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "standard_mode_supported", ColumnType::standard_mode_supported::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "standard_mode_downscale", ColumnType::standard_mode_downscale::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "standard_mode_use_angle", ColumnType::standard_mode_use_angle::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "standard_mode_fps", ColumnType::standard_mode_fps::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "perf_mode_supported", ColumnType::perf_mode_supported::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "perf_mode_downscale", ColumnType::perf_mode_downscale::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "perf_mode_use_angle", ColumnType::perf_mode_use_angle::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "perf_mode_fps", ColumnType::perf_mode_fps::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "battery_mode_supported", ColumnType::battery_mode_supported::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "battery_mode_downscale", ColumnType::battery_mode_downscale::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "battery_mode_use_angle", ColumnType::battery_mode_use_angle::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "battery_mode_fps", ColumnType::battery_mode_fps::SqlValueType(), false,
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
    package_name_.ShrinkToFit();
    uid_.ShrinkToFit();
    current_mode_.ShrinkToFit();
    standard_mode_supported_.ShrinkToFit();
    standard_mode_downscale_.ShrinkToFit();
    standard_mode_use_angle_.ShrinkToFit();
    standard_mode_fps_.ShrinkToFit();
    perf_mode_supported_.ShrinkToFit();
    perf_mode_downscale_.ShrinkToFit();
    perf_mode_use_angle_.ShrinkToFit();
    perf_mode_fps_.ShrinkToFit();
    battery_mode_supported_.ShrinkToFit();
    battery_mode_downscale_.ShrinkToFit();
    battery_mode_use_angle_.ShrinkToFit();
    battery_mode_fps_.ShrinkToFit();
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
    mutable_package_name()->Append(std::move(row.package_name));
    mutable_uid()->Append(std::move(row.uid));
    mutable_current_mode()->Append(std::move(row.current_mode));
    mutable_standard_mode_supported()->Append(std::move(row.standard_mode_supported));
    mutable_standard_mode_downscale()->Append(std::move(row.standard_mode_downscale));
    mutable_standard_mode_use_angle()->Append(std::move(row.standard_mode_use_angle));
    mutable_standard_mode_fps()->Append(std::move(row.standard_mode_fps));
    mutable_perf_mode_supported()->Append(std::move(row.perf_mode_supported));
    mutable_perf_mode_downscale()->Append(std::move(row.perf_mode_downscale));
    mutable_perf_mode_use_angle()->Append(std::move(row.perf_mode_use_angle));
    mutable_perf_mode_fps()->Append(std::move(row.perf_mode_fps));
    mutable_battery_mode_supported()->Append(std::move(row.battery_mode_supported));
    mutable_battery_mode_downscale()->Append(std::move(row.battery_mode_downscale));
    mutable_battery_mode_use_angle()->Append(std::move(row.battery_mode_use_angle));
    mutable_battery_mode_fps()->Append(std::move(row.battery_mode_fps));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<AndroidGameInterventionListTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& package_name() const {
    return static_cast<const ColumnType::package_name&>(columns_[ColumnIndex::package_name]);
  }
  const TypedColumn<int64_t>& uid() const {
    return static_cast<const ColumnType::uid&>(columns_[ColumnIndex::uid]);
  }
  const TypedColumn<int32_t>& current_mode() const {
    return static_cast<const ColumnType::current_mode&>(columns_[ColumnIndex::current_mode]);
  }
  const TypedColumn<int32_t>& standard_mode_supported() const {
    return static_cast<const ColumnType::standard_mode_supported&>(columns_[ColumnIndex::standard_mode_supported]);
  }
  const TypedColumn<std::optional<double>>& standard_mode_downscale() const {
    return static_cast<const ColumnType::standard_mode_downscale&>(columns_[ColumnIndex::standard_mode_downscale]);
  }
  const TypedColumn<std::optional<int32_t>>& standard_mode_use_angle() const {
    return static_cast<const ColumnType::standard_mode_use_angle&>(columns_[ColumnIndex::standard_mode_use_angle]);
  }
  const TypedColumn<std::optional<double>>& standard_mode_fps() const {
    return static_cast<const ColumnType::standard_mode_fps&>(columns_[ColumnIndex::standard_mode_fps]);
  }
  const TypedColumn<int32_t>& perf_mode_supported() const {
    return static_cast<const ColumnType::perf_mode_supported&>(columns_[ColumnIndex::perf_mode_supported]);
  }
  const TypedColumn<std::optional<double>>& perf_mode_downscale() const {
    return static_cast<const ColumnType::perf_mode_downscale&>(columns_[ColumnIndex::perf_mode_downscale]);
  }
  const TypedColumn<std::optional<int32_t>>& perf_mode_use_angle() const {
    return static_cast<const ColumnType::perf_mode_use_angle&>(columns_[ColumnIndex::perf_mode_use_angle]);
  }
  const TypedColumn<std::optional<double>>& perf_mode_fps() const {
    return static_cast<const ColumnType::perf_mode_fps&>(columns_[ColumnIndex::perf_mode_fps]);
  }
  const TypedColumn<int32_t>& battery_mode_supported() const {
    return static_cast<const ColumnType::battery_mode_supported&>(columns_[ColumnIndex::battery_mode_supported]);
  }
  const TypedColumn<std::optional<double>>& battery_mode_downscale() const {
    return static_cast<const ColumnType::battery_mode_downscale&>(columns_[ColumnIndex::battery_mode_downscale]);
  }
  const TypedColumn<std::optional<int32_t>>& battery_mode_use_angle() const {
    return static_cast<const ColumnType::battery_mode_use_angle&>(columns_[ColumnIndex::battery_mode_use_angle]);
  }
  const TypedColumn<std::optional<double>>& battery_mode_fps() const {
    return static_cast<const ColumnType::battery_mode_fps&>(columns_[ColumnIndex::battery_mode_fps]);
  }

  TypedColumn<StringPool::Id>* mutable_package_name() {
    return static_cast<ColumnType::package_name*>(
        &columns_[ColumnIndex::package_name]);
  }
  TypedColumn<int64_t>* mutable_uid() {
    return static_cast<ColumnType::uid*>(
        &columns_[ColumnIndex::uid]);
  }
  TypedColumn<int32_t>* mutable_current_mode() {
    return static_cast<ColumnType::current_mode*>(
        &columns_[ColumnIndex::current_mode]);
  }
  TypedColumn<int32_t>* mutable_standard_mode_supported() {
    return static_cast<ColumnType::standard_mode_supported*>(
        &columns_[ColumnIndex::standard_mode_supported]);
  }
  TypedColumn<std::optional<double>>* mutable_standard_mode_downscale() {
    return static_cast<ColumnType::standard_mode_downscale*>(
        &columns_[ColumnIndex::standard_mode_downscale]);
  }
  TypedColumn<std::optional<int32_t>>* mutable_standard_mode_use_angle() {
    return static_cast<ColumnType::standard_mode_use_angle*>(
        &columns_[ColumnIndex::standard_mode_use_angle]);
  }
  TypedColumn<std::optional<double>>* mutable_standard_mode_fps() {
    return static_cast<ColumnType::standard_mode_fps*>(
        &columns_[ColumnIndex::standard_mode_fps]);
  }
  TypedColumn<int32_t>* mutable_perf_mode_supported() {
    return static_cast<ColumnType::perf_mode_supported*>(
        &columns_[ColumnIndex::perf_mode_supported]);
  }
  TypedColumn<std::optional<double>>* mutable_perf_mode_downscale() {
    return static_cast<ColumnType::perf_mode_downscale*>(
        &columns_[ColumnIndex::perf_mode_downscale]);
  }
  TypedColumn<std::optional<int32_t>>* mutable_perf_mode_use_angle() {
    return static_cast<ColumnType::perf_mode_use_angle*>(
        &columns_[ColumnIndex::perf_mode_use_angle]);
  }
  TypedColumn<std::optional<double>>* mutable_perf_mode_fps() {
    return static_cast<ColumnType::perf_mode_fps*>(
        &columns_[ColumnIndex::perf_mode_fps]);
  }
  TypedColumn<int32_t>* mutable_battery_mode_supported() {
    return static_cast<ColumnType::battery_mode_supported*>(
        &columns_[ColumnIndex::battery_mode_supported]);
  }
  TypedColumn<std::optional<double>>* mutable_battery_mode_downscale() {
    return static_cast<ColumnType::battery_mode_downscale*>(
        &columns_[ColumnIndex::battery_mode_downscale]);
  }
  TypedColumn<std::optional<int32_t>>* mutable_battery_mode_use_angle() {
    return static_cast<ColumnType::battery_mode_use_angle*>(
        &columns_[ColumnIndex::battery_mode_use_angle]);
  }
  TypedColumn<std::optional<double>>* mutable_battery_mode_fps() {
    return static_cast<ColumnType::battery_mode_fps*>(
        &columns_[ColumnIndex::battery_mode_fps]);
  }

 private:
  
  
  ColumnStorage<ColumnType::package_name::stored_type> package_name_;
  ColumnStorage<ColumnType::uid::stored_type> uid_;
  ColumnStorage<ColumnType::current_mode::stored_type> current_mode_;
  ColumnStorage<ColumnType::standard_mode_supported::stored_type> standard_mode_supported_;
  ColumnStorage<ColumnType::standard_mode_downscale::stored_type> standard_mode_downscale_;
  ColumnStorage<ColumnType::standard_mode_use_angle::stored_type> standard_mode_use_angle_;
  ColumnStorage<ColumnType::standard_mode_fps::stored_type> standard_mode_fps_;
  ColumnStorage<ColumnType::perf_mode_supported::stored_type> perf_mode_supported_;
  ColumnStorage<ColumnType::perf_mode_downscale::stored_type> perf_mode_downscale_;
  ColumnStorage<ColumnType::perf_mode_use_angle::stored_type> perf_mode_use_angle_;
  ColumnStorage<ColumnType::perf_mode_fps::stored_type> perf_mode_fps_;
  ColumnStorage<ColumnType::battery_mode_supported::stored_type> battery_mode_supported_;
  ColumnStorage<ColumnType::battery_mode_downscale::stored_type> battery_mode_downscale_;
  ColumnStorage<ColumnType::battery_mode_use_angle::stored_type> battery_mode_use_angle_;
  ColumnStorage<ColumnType::battery_mode_fps::stored_type> battery_mode_fps_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_ANDROID_TABLES_PY_H_

#ifndef SRC_TRACE_PROCESSOR_TABLES_PROFILER_TABLES_PY_H_
#define SRC_TRACE_PROCESSOR_TABLES_PROFILER_TABLES_PY_H_

#include "src/trace_processor/tables/macros_internal.h"

#include "src/trace_processor/tables/track_tables_py.h"

namespace perfetto {
namespace trace_processor {
namespace tables {

class StackProfileMappingTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t build_id = 2;
    static constexpr uint32_t exact_offset = 3;
    static constexpr uint32_t start_offset = 4;
    static constexpr uint32_t start = 5;
    static constexpr uint32_t end = 6;
    static constexpr uint32_t load_bias = 7;
    static constexpr uint32_t name = 8;
  };
  struct ColumnType {
    using id = IdColumn<StackProfileMappingTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using build_id = TypedColumn<StringPool::Id>;
    using exact_offset = TypedColumn<int64_t>;
    using start_offset = TypedColumn<int64_t>;
    using start = TypedColumn<int64_t>;
    using end = TypedColumn<int64_t>;
    using load_bias = TypedColumn<int64_t>;
    using name = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_build_id = {},
        int64_t in_exact_offset = {},
        int64_t in_start_offset = {},
        int64_t in_start = {},
        int64_t in_end = {},
        int64_t in_load_bias = {},
        StringPool::Id in_name = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          build_id(std::move(in_build_id)),
          exact_offset(std::move(in_exact_offset)),
          start_offset(std::move(in_start_offset)),
          start(std::move(in_start)),
          end(std::move(in_end)),
          load_bias(std::move(in_load_bias)),
          name(std::move(in_name)) {
      type_ = "stack_profile_mapping";
    }
    StringPool::Id build_id;
    int64_t exact_offset;
    int64_t start_offset;
    int64_t start;
    int64_t end;
    int64_t load_bias;
    StringPool::Id name;

    bool operator==(const StackProfileMappingTable::Row& other) const {
      return type() == other.type() && ColumnType::build_id::Equals(build_id, other.build_id) &&
       ColumnType::exact_offset::Equals(exact_offset, other.exact_offset) &&
       ColumnType::start_offset::Equals(start_offset, other.start_offset) &&
       ColumnType::start::Equals(start, other.start) &&
       ColumnType::end::Equals(end, other.end) &&
       ColumnType::load_bias::Equals(load_bias, other.load_bias) &&
       ColumnType::name::Equals(name, other.name);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t build_id = ColumnType::build_id::default_flags();
    static constexpr uint32_t exact_offset = ColumnType::exact_offset::default_flags();
    static constexpr uint32_t start_offset = ColumnType::start_offset::default_flags();
    static constexpr uint32_t start = ColumnType::start::default_flags();
    static constexpr uint32_t end = ColumnType::end::default_flags();
    static constexpr uint32_t load_bias = ColumnType::load_bias::default_flags();
    static constexpr uint32_t name = ColumnType::name::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      StackProfileMappingTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    StackProfileMappingTable, RowNumber> {
   public:
    ConstRowReference(const StackProfileMappingTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::build_id::type build_id() const {
      return table_->build_id()[row_number_];
    }
    ColumnType::exact_offset::type exact_offset() const {
      return table_->exact_offset()[row_number_];
    }
    ColumnType::start_offset::type start_offset() const {
      return table_->start_offset()[row_number_];
    }
    ColumnType::start::type start() const {
      return table_->start()[row_number_];
    }
    ColumnType::end::type end() const {
      return table_->end()[row_number_];
    }
    ColumnType::load_bias::type load_bias() const {
      return table_->load_bias()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const StackProfileMappingTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_build_id(
        ColumnType::build_id::non_optional_type v) {
      return mutable_table()->mutable_build_id()->Set(row_number_, v);
    }
    void set_exact_offset(
        ColumnType::exact_offset::non_optional_type v) {
      return mutable_table()->mutable_exact_offset()->Set(row_number_, v);
    }
    void set_start_offset(
        ColumnType::start_offset::non_optional_type v) {
      return mutable_table()->mutable_start_offset()->Set(row_number_, v);
    }
    void set_start(
        ColumnType::start::non_optional_type v) {
      return mutable_table()->mutable_start()->Set(row_number_, v);
    }
    void set_end(
        ColumnType::end::non_optional_type v) {
      return mutable_table()->mutable_end()->Set(row_number_, v);
    }
    void set_load_bias(
        ColumnType::load_bias::non_optional_type v) {
      return mutable_table()->mutable_load_bias()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }

   private:
    StackProfileMappingTable* mutable_table() const {
      return const_cast<StackProfileMappingTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, StackProfileMappingTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::build_id::type build_id() const {
      const auto& col = table_->build_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::exact_offset::type exact_offset() const {
      const auto& col = table_->exact_offset();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_offset::type start_offset() const {
      const auto& col = table_->start_offset();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start::type start() const {
      const auto& col = table_->start();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::end::type end() const {
      const auto& col = table_->end();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::load_bias::type load_bias() const {
      const auto& col = table_->load_bias();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const StackProfileMappingTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class StackProfileMappingTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_build_id(ColumnType::build_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_build_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_exact_offset(ColumnType::exact_offset::non_optional_type v) {
        auto* col = mutable_table_->mutable_exact_offset();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_offset(ColumnType::start_offset::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_offset();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start(ColumnType::start::non_optional_type v) {
        auto* col = mutable_table_->mutable_start();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_end(ColumnType::end::non_optional_type v) {
        auto* col = mutable_table_->mutable_end();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_load_bias(ColumnType::load_bias::non_optional_type v) {
        auto* col = mutable_table_->mutable_load_bias();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class StackProfileMappingTable;

    explicit Iterator(StackProfileMappingTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    StackProfileMappingTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit StackProfileMappingTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        build_id_(ColumnStorage<ColumnType::build_id::stored_type>::Create<false>()),
        exact_offset_(ColumnStorage<ColumnType::exact_offset::stored_type>::Create<false>()),
        start_offset_(ColumnStorage<ColumnType::start_offset::stored_type>::Create<false>()),
        start_(ColumnStorage<ColumnType::start::stored_type>::Create<false>()),
        end_(ColumnStorage<ColumnType::end::stored_type>::Create<false>()),
        load_bias_(ColumnStorage<ColumnType::load_bias::stored_type>::Create<false>()),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::build_id::stored_type>(
          ColumnFlag::build_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::exact_offset::stored_type>(
          ColumnFlag::exact_offset),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_offset::stored_type>(
          ColumnFlag::start_offset),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start::stored_type>(
          ColumnFlag::start),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::end::stored_type>(
          ColumnFlag::end),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::load_bias::stored_type>(
          ColumnFlag::load_bias),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("build_id", &build_id_, ColumnFlag::build_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("exact_offset", &exact_offset_, ColumnFlag::exact_offset,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("start_offset", &start_offset_, ColumnFlag::start_offset,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("start", &start_, ColumnFlag::start,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("end", &end_, ColumnFlag::end,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("load_bias", &load_bias_, ColumnFlag::load_bias,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~StackProfileMappingTable() override;

  static const char* Name() { return "stack_profile_mapping"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "build_id", ColumnType::build_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "exact_offset", ColumnType::exact_offset::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_offset", ColumnType::start_offset::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start", ColumnType::start::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "end", ColumnType::end::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "load_bias", ColumnType::load_bias::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
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
    build_id_.ShrinkToFit();
    exact_offset_.ShrinkToFit();
    start_offset_.ShrinkToFit();
    start_.ShrinkToFit();
    end_.ShrinkToFit();
    load_bias_.ShrinkToFit();
    name_.ShrinkToFit();
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
    mutable_build_id()->Append(std::move(row.build_id));
    mutable_exact_offset()->Append(std::move(row.exact_offset));
    mutable_start_offset()->Append(std::move(row.start_offset));
    mutable_start()->Append(std::move(row.start));
    mutable_end()->Append(std::move(row.end));
    mutable_load_bias()->Append(std::move(row.load_bias));
    mutable_name()->Append(std::move(row.name));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<StackProfileMappingTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& build_id() const {
    return static_cast<const ColumnType::build_id&>(columns_[ColumnIndex::build_id]);
  }
  const TypedColumn<int64_t>& exact_offset() const {
    return static_cast<const ColumnType::exact_offset&>(columns_[ColumnIndex::exact_offset]);
  }
  const TypedColumn<int64_t>& start_offset() const {
    return static_cast<const ColumnType::start_offset&>(columns_[ColumnIndex::start_offset]);
  }
  const TypedColumn<int64_t>& start() const {
    return static_cast<const ColumnType::start&>(columns_[ColumnIndex::start]);
  }
  const TypedColumn<int64_t>& end() const {
    return static_cast<const ColumnType::end&>(columns_[ColumnIndex::end]);
  }
  const TypedColumn<int64_t>& load_bias() const {
    return static_cast<const ColumnType::load_bias&>(columns_[ColumnIndex::load_bias]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }

  TypedColumn<StringPool::Id>* mutable_build_id() {
    return static_cast<ColumnType::build_id*>(
        &columns_[ColumnIndex::build_id]);
  }
  TypedColumn<int64_t>* mutable_exact_offset() {
    return static_cast<ColumnType::exact_offset*>(
        &columns_[ColumnIndex::exact_offset]);
  }
  TypedColumn<int64_t>* mutable_start_offset() {
    return static_cast<ColumnType::start_offset*>(
        &columns_[ColumnIndex::start_offset]);
  }
  TypedColumn<int64_t>* mutable_start() {
    return static_cast<ColumnType::start*>(
        &columns_[ColumnIndex::start]);
  }
  TypedColumn<int64_t>* mutable_end() {
    return static_cast<ColumnType::end*>(
        &columns_[ColumnIndex::end]);
  }
  TypedColumn<int64_t>* mutable_load_bias() {
    return static_cast<ColumnType::load_bias*>(
        &columns_[ColumnIndex::load_bias]);
  }
  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }

 private:
  
  
  ColumnStorage<ColumnType::build_id::stored_type> build_id_;
  ColumnStorage<ColumnType::exact_offset::stored_type> exact_offset_;
  ColumnStorage<ColumnType::start_offset::stored_type> start_offset_;
  ColumnStorage<ColumnType::start::stored_type> start_;
  ColumnStorage<ColumnType::end::stored_type> end_;
  ColumnStorage<ColumnType::load_bias::stored_type> load_bias_;
  ColumnStorage<ColumnType::name::stored_type> name_;
};
  

class StackProfileFrameTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t mapping = 3;
    static constexpr uint32_t rel_pc = 4;
    static constexpr uint32_t symbol_set_id = 5;
    static constexpr uint32_t deobfuscated_name = 6;
  };
  struct ColumnType {
    using id = IdColumn<StackProfileFrameTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using mapping = TypedColumn<StackProfileMappingTable::Id>;
    using rel_pc = TypedColumn<int64_t>;
    using symbol_set_id = TypedColumn<std::optional<uint32_t>>;
    using deobfuscated_name = TypedColumn<std::optional<StringPool::Id>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_name = {},
        StackProfileMappingTable::Id in_mapping = {},
        int64_t in_rel_pc = {},
        std::optional<uint32_t> in_symbol_set_id = {},
        std::optional<StringPool::Id> in_deobfuscated_name = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          name(std::move(in_name)),
          mapping(std::move(in_mapping)),
          rel_pc(std::move(in_rel_pc)),
          symbol_set_id(std::move(in_symbol_set_id)),
          deobfuscated_name(std::move(in_deobfuscated_name)) {
      type_ = "stack_profile_frame";
    }
    StringPool::Id name;
    StackProfileMappingTable::Id mapping;
    int64_t rel_pc;
    std::optional<uint32_t> symbol_set_id;
    std::optional<StringPool::Id> deobfuscated_name;

    bool operator==(const StackProfileFrameTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::mapping::Equals(mapping, other.mapping) &&
       ColumnType::rel_pc::Equals(rel_pc, other.rel_pc) &&
       ColumnType::symbol_set_id::Equals(symbol_set_id, other.symbol_set_id) &&
       ColumnType::deobfuscated_name::Equals(deobfuscated_name, other.deobfuscated_name);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t mapping = ColumnType::mapping::default_flags();
    static constexpr uint32_t rel_pc = ColumnType::rel_pc::default_flags();
    static constexpr uint32_t symbol_set_id = ColumnType::symbol_set_id::default_flags();
    static constexpr uint32_t deobfuscated_name = ColumnType::deobfuscated_name::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      StackProfileFrameTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    StackProfileFrameTable, RowNumber> {
   public:
    ConstRowReference(const StackProfileFrameTable* table, uint32_t row_number)
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
    ColumnType::mapping::type mapping() const {
      return table_->mapping()[row_number_];
    }
    ColumnType::rel_pc::type rel_pc() const {
      return table_->rel_pc()[row_number_];
    }
    ColumnType::symbol_set_id::type symbol_set_id() const {
      return table_->symbol_set_id()[row_number_];
    }
    ColumnType::deobfuscated_name::type deobfuscated_name() const {
      return table_->deobfuscated_name()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const StackProfileFrameTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_mapping(
        ColumnType::mapping::non_optional_type v) {
      return mutable_table()->mutable_mapping()->Set(row_number_, v);
    }
    void set_rel_pc(
        ColumnType::rel_pc::non_optional_type v) {
      return mutable_table()->mutable_rel_pc()->Set(row_number_, v);
    }
    void set_symbol_set_id(
        ColumnType::symbol_set_id::non_optional_type v) {
      return mutable_table()->mutable_symbol_set_id()->Set(row_number_, v);
    }
    void set_deobfuscated_name(
        ColumnType::deobfuscated_name::non_optional_type v) {
      return mutable_table()->mutable_deobfuscated_name()->Set(row_number_, v);
    }

   private:
    StackProfileFrameTable* mutable_table() const {
      return const_cast<StackProfileFrameTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, StackProfileFrameTable, RowNumber, ConstRowReference> {
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
    ColumnType::mapping::type mapping() const {
      const auto& col = table_->mapping();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::rel_pc::type rel_pc() const {
      const auto& col = table_->rel_pc();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::symbol_set_id::type symbol_set_id() const {
      const auto& col = table_->symbol_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::deobfuscated_name::type deobfuscated_name() const {
      const auto& col = table_->deobfuscated_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const StackProfileFrameTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class StackProfileFrameTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_mapping(ColumnType::mapping::non_optional_type v) {
        auto* col = mutable_table_->mutable_mapping();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_rel_pc(ColumnType::rel_pc::non_optional_type v) {
        auto* col = mutable_table_->mutable_rel_pc();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_symbol_set_id(ColumnType::symbol_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_symbol_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_deobfuscated_name(ColumnType::deobfuscated_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_deobfuscated_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class StackProfileFrameTable;

    explicit Iterator(StackProfileFrameTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    StackProfileFrameTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit StackProfileFrameTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        mapping_(ColumnStorage<ColumnType::mapping::stored_type>::Create<false>()),
        rel_pc_(ColumnStorage<ColumnType::rel_pc::stored_type>::Create<false>()),
        symbol_set_id_(ColumnStorage<ColumnType::symbol_set_id::stored_type>::Create<false>()),
        deobfuscated_name_(ColumnStorage<ColumnType::deobfuscated_name::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::mapping::stored_type>(
          ColumnFlag::mapping),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::rel_pc::stored_type>(
          ColumnFlag::rel_pc),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::symbol_set_id::stored_type>(
          ColumnFlag::symbol_set_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::deobfuscated_name::stored_type>(
          ColumnFlag::deobfuscated_name),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("mapping", &mapping_, ColumnFlag::mapping,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("rel_pc", &rel_pc_, ColumnFlag::rel_pc,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("symbol_set_id", &symbol_set_id_, ColumnFlag::symbol_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("deobfuscated_name", &deobfuscated_name_, ColumnFlag::deobfuscated_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~StackProfileFrameTable() override;

  static const char* Name() { return "stack_profile_frame"; }

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
        "mapping", ColumnType::mapping::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "rel_pc", ColumnType::rel_pc::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "symbol_set_id", ColumnType::symbol_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "deobfuscated_name", ColumnType::deobfuscated_name::SqlValueType(), false,
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
    mapping_.ShrinkToFit();
    rel_pc_.ShrinkToFit();
    symbol_set_id_.ShrinkToFit();
    deobfuscated_name_.ShrinkToFit();
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
    mutable_mapping()->Append(std::move(row.mapping));
    mutable_rel_pc()->Append(std::move(row.rel_pc));
    mutable_symbol_set_id()->Append(std::move(row.symbol_set_id));
    mutable_deobfuscated_name()->Append(std::move(row.deobfuscated_name));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<StackProfileFrameTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<StackProfileMappingTable::Id>& mapping() const {
    return static_cast<const ColumnType::mapping&>(columns_[ColumnIndex::mapping]);
  }
  const TypedColumn<int64_t>& rel_pc() const {
    return static_cast<const ColumnType::rel_pc&>(columns_[ColumnIndex::rel_pc]);
  }
  const TypedColumn<std::optional<uint32_t>>& symbol_set_id() const {
    return static_cast<const ColumnType::symbol_set_id&>(columns_[ColumnIndex::symbol_set_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& deobfuscated_name() const {
    return static_cast<const ColumnType::deobfuscated_name&>(columns_[ColumnIndex::deobfuscated_name]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<StackProfileMappingTable::Id>* mutable_mapping() {
    return static_cast<ColumnType::mapping*>(
        &columns_[ColumnIndex::mapping]);
  }
  TypedColumn<int64_t>* mutable_rel_pc() {
    return static_cast<ColumnType::rel_pc*>(
        &columns_[ColumnIndex::rel_pc]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_symbol_set_id() {
    return static_cast<ColumnType::symbol_set_id*>(
        &columns_[ColumnIndex::symbol_set_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_deobfuscated_name() {
    return static_cast<ColumnType::deobfuscated_name*>(
        &columns_[ColumnIndex::deobfuscated_name]);
  }

 private:
  
  
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::mapping::stored_type> mapping_;
  ColumnStorage<ColumnType::rel_pc::stored_type> rel_pc_;
  ColumnStorage<ColumnType::symbol_set_id::stored_type> symbol_set_id_;
  ColumnStorage<ColumnType::deobfuscated_name::stored_type> deobfuscated_name_;
};
  

class StackProfileCallsiteTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t depth = 2;
    static constexpr uint32_t parent_id = 3;
    static constexpr uint32_t frame_id = 4;
  };
  struct ColumnType {
    using id = IdColumn<StackProfileCallsiteTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using depth = TypedColumn<uint32_t>;
    using parent_id = TypedColumn<std::optional<StackProfileCallsiteTable::Id>>;
    using frame_id = TypedColumn<StackProfileFrameTable::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_depth = {},
        std::optional<StackProfileCallsiteTable::Id> in_parent_id = {},
        StackProfileFrameTable::Id in_frame_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          depth(std::move(in_depth)),
          parent_id(std::move(in_parent_id)),
          frame_id(std::move(in_frame_id)) {
      type_ = "stack_profile_callsite";
    }
    uint32_t depth;
    std::optional<StackProfileCallsiteTable::Id> parent_id;
    StackProfileFrameTable::Id frame_id;

    bool operator==(const StackProfileCallsiteTable::Row& other) const {
      return type() == other.type() && ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::frame_id::Equals(frame_id, other.frame_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t depth = ColumnType::depth::default_flags();
    static constexpr uint32_t parent_id = ColumnType::parent_id::default_flags();
    static constexpr uint32_t frame_id = ColumnType::frame_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      StackProfileCallsiteTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    StackProfileCallsiteTable, RowNumber> {
   public:
    ConstRowReference(const StackProfileCallsiteTable* table, uint32_t row_number)
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
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const StackProfileCallsiteTable* table, uint32_t row_number)
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

   private:
    StackProfileCallsiteTable* mutable_table() const {
      return const_cast<StackProfileCallsiteTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, StackProfileCallsiteTable, RowNumber, ConstRowReference> {
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

   protected:
    explicit ConstIterator(const StackProfileCallsiteTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class StackProfileCallsiteTable;
    friend class AbstractConstIterator;
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

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class StackProfileCallsiteTable;

    explicit Iterator(StackProfileCallsiteTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    StackProfileCallsiteTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit StackProfileCallsiteTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        depth_(ColumnStorage<ColumnType::depth::stored_type>::Create<false>()),
        parent_id_(ColumnStorage<ColumnType::parent_id::stored_type>::Create<false>()),
        frame_id_(ColumnStorage<ColumnType::frame_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::depth::stored_type>(
          ColumnFlag::depth),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::parent_id::stored_type>(
          ColumnFlag::parent_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::frame_id::stored_type>(
          ColumnFlag::frame_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("depth", &depth_, ColumnFlag::depth,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("parent_id", &parent_id_, ColumnFlag::parent_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("frame_id", &frame_id_, ColumnFlag::frame_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~StackProfileCallsiteTable() override;

  static const char* Name() { return "stack_profile_callsite"; }

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
    depth_.ShrinkToFit();
    parent_id_.ShrinkToFit();
    frame_id_.ShrinkToFit();
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
    mutable_depth()->Append(std::move(row.depth));
    mutable_parent_id()->Append(std::move(row.parent_id));
    mutable_frame_id()->Append(std::move(row.frame_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<StackProfileCallsiteTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<std::optional<StackProfileCallsiteTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<StackProfileFrameTable::Id>& frame_id() const {
    return static_cast<const ColumnType::frame_id&>(columns_[ColumnIndex::frame_id]);
  }

  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<std::optional<StackProfileCallsiteTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<StackProfileFrameTable::Id>* mutable_frame_id() {
    return static_cast<ColumnType::frame_id*>(
        &columns_[ColumnIndex::frame_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::depth::stored_type> depth_;
  ColumnStorage<ColumnType::parent_id::stored_type> parent_id_;
  ColumnStorage<ColumnType::frame_id::stored_type> frame_id_;
};
  

class StackSampleTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t callsite_id = 3;
  };
  struct ColumnType {
    using id = IdColumn<StackSampleTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using callsite_id = TypedColumn<StackProfileCallsiteTable::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        StackProfileCallsiteTable::Id in_callsite_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          callsite_id(std::move(in_callsite_id)) {
      type_ = "stack_sample";
    }
    int64_t ts;
    StackProfileCallsiteTable::Id callsite_id;

    bool operator==(const StackSampleTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::callsite_id::Equals(callsite_id, other.callsite_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::ts::default_flags();
    static constexpr uint32_t callsite_id = ColumnType::callsite_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      StackSampleTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    StackSampleTable, RowNumber> {
   public:
    ConstRowReference(const StackSampleTable* table, uint32_t row_number)
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
    ColumnType::callsite_id::type callsite_id() const {
      return table_->callsite_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const StackSampleTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_callsite_id(
        ColumnType::callsite_id::non_optional_type v) {
      return mutable_table()->mutable_callsite_id()->Set(row_number_, v);
    }

   private:
    StackSampleTable* mutable_table() const {
      return const_cast<StackSampleTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, StackSampleTable, RowNumber, ConstRowReference> {
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
    ColumnType::callsite_id::type callsite_id() const {
      const auto& col = table_->callsite_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const StackSampleTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class StackSampleTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_callsite_id(ColumnType::callsite_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_callsite_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class StackSampleTable;

    explicit Iterator(StackSampleTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    StackSampleTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit StackSampleTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        callsite_id_(ColumnStorage<ColumnType::callsite_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::callsite_id::stored_type>(
          ColumnFlag::callsite_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("callsite_id", &callsite_id_, ColumnFlag::callsite_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~StackSampleTable() override;

  static const char* Name() { return "stack_sample"; }

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
        "callsite_id", ColumnType::callsite_id::SqlValueType(), false,
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
    callsite_id_.ShrinkToFit();
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
    mutable_callsite_id()->Append(std::move(row.callsite_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<StackSampleTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<StackProfileCallsiteTable::Id>& callsite_id() const {
    return static_cast<const ColumnType::callsite_id&>(columns_[ColumnIndex::callsite_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<StackProfileCallsiteTable::Id>* mutable_callsite_id() {
    return static_cast<ColumnType::callsite_id*>(
        &columns_[ColumnIndex::callsite_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::callsite_id::stored_type> callsite_id_;
};
  

class CpuProfileStackSampleTable : public macros_internal::MacroTable {
 public:
  using Id = StackSampleTable::Id;
    
  struct ColumnIndex {
    static constexpr uint32_t id = 0;
    static constexpr uint32_t type = 1;
    static constexpr uint32_t ts = 2;
    static constexpr uint32_t callsite_id = 3;
    static constexpr uint32_t utid = 4;
    static constexpr uint32_t process_priority = 5;
  };
  struct ColumnType {
    using id = IdColumn<CpuProfileStackSampleTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using callsite_id = TypedColumn<StackProfileCallsiteTable::Id>;
    using utid = TypedColumn<uint32_t>;
    using process_priority = TypedColumn<int32_t>;
  };
  struct Row : public StackSampleTable::Row {
    Row(int64_t in_ts = {},
        StackProfileCallsiteTable::Id in_callsite_id = {},
        uint32_t in_utid = {},
        int32_t in_process_priority = {},
        std::nullptr_t = nullptr)
        : StackSampleTable::Row(std::move(in_ts), std::move(in_callsite_id)),
          utid(std::move(in_utid)),
          process_priority(std::move(in_process_priority)) {
      type_ = "cpu_profile_stack_sample";
    }
    uint32_t utid;
    int32_t process_priority;

    bool operator==(const CpuProfileStackSampleTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::callsite_id::Equals(callsite_id, other.callsite_id) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::process_priority::Equals(process_priority, other.process_priority);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
    static constexpr uint32_t process_priority = ColumnType::process_priority::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      CpuProfileStackSampleTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    CpuProfileStackSampleTable, RowNumber> {
   public:
    ConstRowReference(const CpuProfileStackSampleTable* table, uint32_t row_number)
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
    ColumnType::callsite_id::type callsite_id() const {
      return table_->callsite_id()[row_number_];
    }
    ColumnType::utid::type utid() const {
      return table_->utid()[row_number_];
    }
    ColumnType::process_priority::type process_priority() const {
      return table_->process_priority()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const CpuProfileStackSampleTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_callsite_id(
        ColumnType::callsite_id::non_optional_type v) {
      return mutable_table()->mutable_callsite_id()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }
    void set_process_priority(
        ColumnType::process_priority::non_optional_type v) {
      return mutable_table()->mutable_process_priority()->Set(row_number_, v);
    }

   private:
    CpuProfileStackSampleTable* mutable_table() const {
      return const_cast<CpuProfileStackSampleTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, CpuProfileStackSampleTable, RowNumber, ConstRowReference> {
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
    ColumnType::callsite_id::type callsite_id() const {
      const auto& col = table_->callsite_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::utid::type utid() const {
      const auto& col = table_->utid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::process_priority::type process_priority() const {
      const auto& col = table_->process_priority();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const CpuProfileStackSampleTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class CpuProfileStackSampleTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_callsite_id(ColumnType::callsite_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_callsite_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_utid(ColumnType::utid::non_optional_type v) {
        auto* col = mutable_table_->mutable_utid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_process_priority(ColumnType::process_priority::non_optional_type v) {
        auto* col = mutable_table_->mutable_process_priority();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class CpuProfileStackSampleTable;

    explicit Iterator(CpuProfileStackSampleTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    CpuProfileStackSampleTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit CpuProfileStackSampleTable(StringPool* pool, StackSampleTable* parent)
      : macros_internal::MacroTable(pool, parent),
        parent_(parent), utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()),
        process_priority_(ColumnStorage<ColumnType::process_priority::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::process_priority::stored_type>(
          ColumnFlag::process_priority),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("process_priority", &process_priority_, ColumnFlag::process_priority,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~CpuProfileStackSampleTable() override;

  static const char* Name() { return "cpu_profile_stack_sample"; }

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
        "callsite_id", ColumnType::callsite_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "utid", ColumnType::utid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "process_priority", ColumnType::process_priority::SqlValueType(), false,
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
    process_priority_.ShrinkToFit();
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
    mutable_process_priority()->Append(std::move(row.process_priority));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  static std::unique_ptr<Table> ExtendParent(
      const StackSampleTable& parent,
      ColumnStorage<ColumnType::utid::stored_type> utid
, ColumnStorage<ColumnType::process_priority::stored_type> process_priority) {
    return std::unique_ptr<Table>(new CpuProfileStackSampleTable(
        parent.string_pool(), parent, RowMap(0, parent.row_count()),
        std::move(utid), std::move(process_priority)));
  }

  static std::unique_ptr<Table> SelectAndExtendParent(
      const StackSampleTable& parent,
      std::vector<StackSampleTable::RowNumber> parent_overlay,
      ColumnStorage<ColumnType::utid::stored_type> utid
, ColumnStorage<ColumnType::process_priority::stored_type> process_priority) {
    std::vector<uint32_t> prs_untyped(parent_overlay.size());
    for (uint32_t i = 0; i < parent_overlay.size(); ++i) {
      prs_untyped[i] = parent_overlay[i].row_number();
    }
    return std::unique_ptr<Table>(new CpuProfileStackSampleTable(
        parent.string_pool(), parent, RowMap(std::move(prs_untyped)),
        std::move(utid), std::move(process_priority)));
  }

  const IdColumn<CpuProfileStackSampleTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<StackProfileCallsiteTable::Id>& callsite_id() const {
    return static_cast<const ColumnType::callsite_id&>(columns_[ColumnIndex::callsite_id]);
  }
  const TypedColumn<uint32_t>& utid() const {
    return static_cast<const ColumnType::utid&>(columns_[ColumnIndex::utid]);
  }
  const TypedColumn<int32_t>& process_priority() const {
    return static_cast<const ColumnType::process_priority&>(columns_[ColumnIndex::process_priority]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<StackProfileCallsiteTable::Id>* mutable_callsite_id() {
    return static_cast<ColumnType::callsite_id*>(
        &columns_[ColumnIndex::callsite_id]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<int32_t>* mutable_process_priority() {
    return static_cast<ColumnType::process_priority*>(
        &columns_[ColumnIndex::process_priority]);
  }

 private:
  CpuProfileStackSampleTable(StringPool* pool,
            const StackSampleTable& parent,
            const RowMap& parent_overlay,
            ColumnStorage<ColumnType::utid::stored_type> utid
, ColumnStorage<ColumnType::process_priority::stored_type> process_priority)
      : macros_internal::MacroTable(pool, parent, parent_overlay) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::process_priority::stored_type>(
          ColumnFlag::process_priority),
        "Column type and flag combination is not valid");
    PERFETTO_DCHECK(utid.size() == parent_overlay.size());
    utid_ = std::move(utid);
    PERFETTO_DCHECK(process_priority.size() == parent_overlay.size());
    process_priority_ = std::move(process_priority);

    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("process_priority", &process_priority_, ColumnFlag::process_priority,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  StackSampleTable* parent_ = nullptr;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
  ColumnStorage<ColumnType::process_priority::stored_type> process_priority_;
};
  

class ExperimentalFlamegraphNodesTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t upid = 3;
    static constexpr uint32_t profile_type = 4;
    static constexpr uint32_t focus_str = 5;
    static constexpr uint32_t depth = 6;
    static constexpr uint32_t name = 7;
    static constexpr uint32_t map_name = 8;
    static constexpr uint32_t count = 9;
    static constexpr uint32_t cumulative_count = 10;
    static constexpr uint32_t size = 11;
    static constexpr uint32_t cumulative_size = 12;
    static constexpr uint32_t alloc_count = 13;
    static constexpr uint32_t cumulative_alloc_count = 14;
    static constexpr uint32_t alloc_size = 15;
    static constexpr uint32_t cumulative_alloc_size = 16;
    static constexpr uint32_t parent_id = 17;
    static constexpr uint32_t source_file = 18;
    static constexpr uint32_t line_number = 19;
    static constexpr uint32_t upid_group = 20;
  };
  struct ColumnType {
    using id = IdColumn<ExperimentalFlamegraphNodesTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using upid = TypedColumn<uint32_t>;
    using profile_type = TypedColumn<StringPool::Id>;
    using focus_str = TypedColumn<StringPool::Id>;
    using depth = TypedColumn<uint32_t>;
    using name = TypedColumn<StringPool::Id>;
    using map_name = TypedColumn<StringPool::Id>;
    using count = TypedColumn<int64_t>;
    using cumulative_count = TypedColumn<int64_t>;
    using size = TypedColumn<int64_t>;
    using cumulative_size = TypedColumn<int64_t>;
    using alloc_count = TypedColumn<int64_t>;
    using cumulative_alloc_count = TypedColumn<int64_t>;
    using alloc_size = TypedColumn<int64_t>;
    using cumulative_alloc_size = TypedColumn<int64_t>;
    using parent_id = TypedColumn<std::optional<ExperimentalFlamegraphNodesTable::Id>>;
    using source_file = TypedColumn<std::optional<StringPool::Id>>;
    using line_number = TypedColumn<std::optional<uint32_t>>;
    using upid_group = TypedColumn<std::optional<StringPool::Id>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        uint32_t in_upid = {},
        StringPool::Id in_profile_type = {},
        StringPool::Id in_focus_str = {},
        uint32_t in_depth = {},
        StringPool::Id in_name = {},
        StringPool::Id in_map_name = {},
        int64_t in_count = {},
        int64_t in_cumulative_count = {},
        int64_t in_size = {},
        int64_t in_cumulative_size = {},
        int64_t in_alloc_count = {},
        int64_t in_cumulative_alloc_count = {},
        int64_t in_alloc_size = {},
        int64_t in_cumulative_alloc_size = {},
        std::optional<ExperimentalFlamegraphNodesTable::Id> in_parent_id = {},
        std::optional<StringPool::Id> in_source_file = {},
        std::optional<uint32_t> in_line_number = {},
        std::optional<StringPool::Id> in_upid_group = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          upid(std::move(in_upid)),
          profile_type(std::move(in_profile_type)),
          focus_str(std::move(in_focus_str)),
          depth(std::move(in_depth)),
          name(std::move(in_name)),
          map_name(std::move(in_map_name)),
          count(std::move(in_count)),
          cumulative_count(std::move(in_cumulative_count)),
          size(std::move(in_size)),
          cumulative_size(std::move(in_cumulative_size)),
          alloc_count(std::move(in_alloc_count)),
          cumulative_alloc_count(std::move(in_cumulative_alloc_count)),
          alloc_size(std::move(in_alloc_size)),
          cumulative_alloc_size(std::move(in_cumulative_alloc_size)),
          parent_id(std::move(in_parent_id)),
          source_file(std::move(in_source_file)),
          line_number(std::move(in_line_number)),
          upid_group(std::move(in_upid_group)) {
      type_ = "experimental_flamegraph_nodes";
    }
    int64_t ts;
    uint32_t upid;
    StringPool::Id profile_type;
    StringPool::Id focus_str;
    uint32_t depth;
    StringPool::Id name;
    StringPool::Id map_name;
    int64_t count;
    int64_t cumulative_count;
    int64_t size;
    int64_t cumulative_size;
    int64_t alloc_count;
    int64_t cumulative_alloc_count;
    int64_t alloc_size;
    int64_t cumulative_alloc_size;
    std::optional<ExperimentalFlamegraphNodesTable::Id> parent_id;
    std::optional<StringPool::Id> source_file;
    std::optional<uint32_t> line_number;
    std::optional<StringPool::Id> upid_group;

    bool operator==(const ExperimentalFlamegraphNodesTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::profile_type::Equals(profile_type, other.profile_type) &&
       ColumnType::focus_str::Equals(focus_str, other.focus_str) &&
       ColumnType::depth::Equals(depth, other.depth) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::map_name::Equals(map_name, other.map_name) &&
       ColumnType::count::Equals(count, other.count) &&
       ColumnType::cumulative_count::Equals(cumulative_count, other.cumulative_count) &&
       ColumnType::size::Equals(size, other.size) &&
       ColumnType::cumulative_size::Equals(cumulative_size, other.cumulative_size) &&
       ColumnType::alloc_count::Equals(alloc_count, other.alloc_count) &&
       ColumnType::cumulative_alloc_count::Equals(cumulative_alloc_count, other.cumulative_alloc_count) &&
       ColumnType::alloc_size::Equals(alloc_size, other.alloc_size) &&
       ColumnType::cumulative_alloc_size::Equals(cumulative_alloc_size, other.cumulative_alloc_size) &&
       ColumnType::parent_id::Equals(parent_id, other.parent_id) &&
       ColumnType::source_file::Equals(source_file, other.source_file) &&
       ColumnType::line_number::Equals(line_number, other.line_number) &&
       ColumnType::upid_group::Equals(upid_group, other.upid_group);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted | Column::Flag::kHidden) | ColumnType::ts::default_flags();
    static constexpr uint32_t upid = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::upid::default_flags();
    static constexpr uint32_t profile_type = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::profile_type::default_flags();
    static constexpr uint32_t focus_str = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::focus_str::default_flags();
    static constexpr uint32_t depth = ColumnType::depth::default_flags();
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t map_name = ColumnType::map_name::default_flags();
    static constexpr uint32_t count = ColumnType::count::default_flags();
    static constexpr uint32_t cumulative_count = ColumnType::cumulative_count::default_flags();
    static constexpr uint32_t size = ColumnType::size::default_flags();
    static constexpr uint32_t cumulative_size = ColumnType::cumulative_size::default_flags();
    static constexpr uint32_t alloc_count = ColumnType::alloc_count::default_flags();
    static constexpr uint32_t cumulative_alloc_count = ColumnType::cumulative_alloc_count::default_flags();
    static constexpr uint32_t alloc_size = ColumnType::alloc_size::default_flags();
    static constexpr uint32_t cumulative_alloc_size = ColumnType::cumulative_alloc_size::default_flags();
    static constexpr uint32_t parent_id = ColumnType::parent_id::default_flags();
    static constexpr uint32_t source_file = ColumnType::source_file::default_flags();
    static constexpr uint32_t line_number = ColumnType::line_number::default_flags();
    static constexpr uint32_t upid_group = ColumnType::upid_group::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ExperimentalFlamegraphNodesTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ExperimentalFlamegraphNodesTable, RowNumber> {
   public:
    ConstRowReference(const ExperimentalFlamegraphNodesTable* table, uint32_t row_number)
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
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
    ColumnType::profile_type::type profile_type() const {
      return table_->profile_type()[row_number_];
    }
    ColumnType::focus_str::type focus_str() const {
      return table_->focus_str()[row_number_];
    }
    ColumnType::depth::type depth() const {
      return table_->depth()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::map_name::type map_name() const {
      return table_->map_name()[row_number_];
    }
    ColumnType::count::type count() const {
      return table_->count()[row_number_];
    }
    ColumnType::cumulative_count::type cumulative_count() const {
      return table_->cumulative_count()[row_number_];
    }
    ColumnType::size::type size() const {
      return table_->size()[row_number_];
    }
    ColumnType::cumulative_size::type cumulative_size() const {
      return table_->cumulative_size()[row_number_];
    }
    ColumnType::alloc_count::type alloc_count() const {
      return table_->alloc_count()[row_number_];
    }
    ColumnType::cumulative_alloc_count::type cumulative_alloc_count() const {
      return table_->cumulative_alloc_count()[row_number_];
    }
    ColumnType::alloc_size::type alloc_size() const {
      return table_->alloc_size()[row_number_];
    }
    ColumnType::cumulative_alloc_size::type cumulative_alloc_size() const {
      return table_->cumulative_alloc_size()[row_number_];
    }
    ColumnType::parent_id::type parent_id() const {
      return table_->parent_id()[row_number_];
    }
    ColumnType::source_file::type source_file() const {
      return table_->source_file()[row_number_];
    }
    ColumnType::line_number::type line_number() const {
      return table_->line_number()[row_number_];
    }
    ColumnType::upid_group::type upid_group() const {
      return table_->upid_group()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ExperimentalFlamegraphNodesTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_profile_type(
        ColumnType::profile_type::non_optional_type v) {
      return mutable_table()->mutable_profile_type()->Set(row_number_, v);
    }
    void set_focus_str(
        ColumnType::focus_str::non_optional_type v) {
      return mutable_table()->mutable_focus_str()->Set(row_number_, v);
    }
    void set_depth(
        ColumnType::depth::non_optional_type v) {
      return mutable_table()->mutable_depth()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_map_name(
        ColumnType::map_name::non_optional_type v) {
      return mutable_table()->mutable_map_name()->Set(row_number_, v);
    }
    void set_count(
        ColumnType::count::non_optional_type v) {
      return mutable_table()->mutable_count()->Set(row_number_, v);
    }
    void set_cumulative_count(
        ColumnType::cumulative_count::non_optional_type v) {
      return mutable_table()->mutable_cumulative_count()->Set(row_number_, v);
    }
    void set_size(
        ColumnType::size::non_optional_type v) {
      return mutable_table()->mutable_size()->Set(row_number_, v);
    }
    void set_cumulative_size(
        ColumnType::cumulative_size::non_optional_type v) {
      return mutable_table()->mutable_cumulative_size()->Set(row_number_, v);
    }
    void set_alloc_count(
        ColumnType::alloc_count::non_optional_type v) {
      return mutable_table()->mutable_alloc_count()->Set(row_number_, v);
    }
    void set_cumulative_alloc_count(
        ColumnType::cumulative_alloc_count::non_optional_type v) {
      return mutable_table()->mutable_cumulative_alloc_count()->Set(row_number_, v);
    }
    void set_alloc_size(
        ColumnType::alloc_size::non_optional_type v) {
      return mutable_table()->mutable_alloc_size()->Set(row_number_, v);
    }
    void set_cumulative_alloc_size(
        ColumnType::cumulative_alloc_size::non_optional_type v) {
      return mutable_table()->mutable_cumulative_alloc_size()->Set(row_number_, v);
    }
    void set_parent_id(
        ColumnType::parent_id::non_optional_type v) {
      return mutable_table()->mutable_parent_id()->Set(row_number_, v);
    }
    void set_source_file(
        ColumnType::source_file::non_optional_type v) {
      return mutable_table()->mutable_source_file()->Set(row_number_, v);
    }
    void set_line_number(
        ColumnType::line_number::non_optional_type v) {
      return mutable_table()->mutable_line_number()->Set(row_number_, v);
    }
    void set_upid_group(
        ColumnType::upid_group::non_optional_type v) {
      return mutable_table()->mutable_upid_group()->Set(row_number_, v);
    }

   private:
    ExperimentalFlamegraphNodesTable* mutable_table() const {
      return const_cast<ExperimentalFlamegraphNodesTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ExperimentalFlamegraphNodesTable, RowNumber, ConstRowReference> {
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
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::profile_type::type profile_type() const {
      const auto& col = table_->profile_type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::focus_str::type focus_str() const {
      const auto& col = table_->focus_str();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::depth::type depth() const {
      const auto& col = table_->depth();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::map_name::type map_name() const {
      const auto& col = table_->map_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::count::type count() const {
      const auto& col = table_->count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cumulative_count::type cumulative_count() const {
      const auto& col = table_->cumulative_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::size::type size() const {
      const auto& col = table_->size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cumulative_size::type cumulative_size() const {
      const auto& col = table_->cumulative_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::alloc_count::type alloc_count() const {
      const auto& col = table_->alloc_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cumulative_alloc_count::type cumulative_alloc_count() const {
      const auto& col = table_->cumulative_alloc_count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::alloc_size::type alloc_size() const {
      const auto& col = table_->alloc_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cumulative_alloc_size::type cumulative_alloc_size() const {
      const auto& col = table_->cumulative_alloc_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::parent_id::type parent_id() const {
      const auto& col = table_->parent_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_file::type source_file() const {
      const auto& col = table_->source_file();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::line_number::type line_number() const {
      const auto& col = table_->line_number();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid_group::type upid_group() const {
      const auto& col = table_->upid_group();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ExperimentalFlamegraphNodesTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ExperimentalFlamegraphNodesTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_profile_type(ColumnType::profile_type::non_optional_type v) {
        auto* col = mutable_table_->mutable_profile_type();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_focus_str(ColumnType::focus_str::non_optional_type v) {
        auto* col = mutable_table_->mutable_focus_str();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_depth(ColumnType::depth::non_optional_type v) {
        auto* col = mutable_table_->mutable_depth();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_map_name(ColumnType::map_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_map_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_count(ColumnType::count::non_optional_type v) {
        auto* col = mutable_table_->mutable_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cumulative_count(ColumnType::cumulative_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_cumulative_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_size(ColumnType::size::non_optional_type v) {
        auto* col = mutable_table_->mutable_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cumulative_size(ColumnType::cumulative_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_cumulative_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_alloc_count(ColumnType::alloc_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_alloc_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cumulative_alloc_count(ColumnType::cumulative_alloc_count::non_optional_type v) {
        auto* col = mutable_table_->mutable_cumulative_alloc_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_alloc_size(ColumnType::alloc_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_alloc_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cumulative_alloc_size(ColumnType::cumulative_alloc_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_cumulative_alloc_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_parent_id(ColumnType::parent_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_parent_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_file(ColumnType::source_file::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_file();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_line_number(ColumnType::line_number::non_optional_type v) {
        auto* col = mutable_table_->mutable_line_number();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid_group(ColumnType::upid_group::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid_group();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ExperimentalFlamegraphNodesTable;

    explicit Iterator(ExperimentalFlamegraphNodesTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ExperimentalFlamegraphNodesTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ExperimentalFlamegraphNodesTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        profile_type_(ColumnStorage<ColumnType::profile_type::stored_type>::Create<false>()),
        focus_str_(ColumnStorage<ColumnType::focus_str::stored_type>::Create<false>()),
        depth_(ColumnStorage<ColumnType::depth::stored_type>::Create<false>()),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        map_name_(ColumnStorage<ColumnType::map_name::stored_type>::Create<false>()),
        count_(ColumnStorage<ColumnType::count::stored_type>::Create<false>()),
        cumulative_count_(ColumnStorage<ColumnType::cumulative_count::stored_type>::Create<false>()),
        size_(ColumnStorage<ColumnType::size::stored_type>::Create<false>()),
        cumulative_size_(ColumnStorage<ColumnType::cumulative_size::stored_type>::Create<false>()),
        alloc_count_(ColumnStorage<ColumnType::alloc_count::stored_type>::Create<false>()),
        cumulative_alloc_count_(ColumnStorage<ColumnType::cumulative_alloc_count::stored_type>::Create<false>()),
        alloc_size_(ColumnStorage<ColumnType::alloc_size::stored_type>::Create<false>()),
        cumulative_alloc_size_(ColumnStorage<ColumnType::cumulative_alloc_size::stored_type>::Create<false>()),
        parent_id_(ColumnStorage<ColumnType::parent_id::stored_type>::Create<false>()),
        source_file_(ColumnStorage<ColumnType::source_file::stored_type>::Create<false>()),
        line_number_(ColumnStorage<ColumnType::line_number::stored_type>::Create<false>()),
        upid_group_(ColumnStorage<ColumnType::upid_group::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::profile_type::stored_type>(
          ColumnFlag::profile_type),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::focus_str::stored_type>(
          ColumnFlag::focus_str),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::depth::stored_type>(
          ColumnFlag::depth),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::map_name::stored_type>(
          ColumnFlag::map_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::count::stored_type>(
          ColumnFlag::count),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cumulative_count::stored_type>(
          ColumnFlag::cumulative_count),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::size::stored_type>(
          ColumnFlag::size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cumulative_size::stored_type>(
          ColumnFlag::cumulative_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::alloc_count::stored_type>(
          ColumnFlag::alloc_count),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cumulative_alloc_count::stored_type>(
          ColumnFlag::cumulative_alloc_count),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::alloc_size::stored_type>(
          ColumnFlag::alloc_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cumulative_alloc_size::stored_type>(
          ColumnFlag::cumulative_alloc_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::parent_id::stored_type>(
          ColumnFlag::parent_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::source_file::stored_type>(
          ColumnFlag::source_file),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::line_number::stored_type>(
          ColumnFlag::line_number),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid_group::stored_type>(
          ColumnFlag::upid_group),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("profile_type", &profile_type_, ColumnFlag::profile_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("focus_str", &focus_str_, ColumnFlag::focus_str,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("depth", &depth_, ColumnFlag::depth,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("map_name", &map_name_, ColumnFlag::map_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("count", &count_, ColumnFlag::count,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cumulative_count", &cumulative_count_, ColumnFlag::cumulative_count,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("size", &size_, ColumnFlag::size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cumulative_size", &cumulative_size_, ColumnFlag::cumulative_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("alloc_count", &alloc_count_, ColumnFlag::alloc_count,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cumulative_alloc_count", &cumulative_alloc_count_, ColumnFlag::cumulative_alloc_count,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("alloc_size", &alloc_size_, ColumnFlag::alloc_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cumulative_alloc_size", &cumulative_alloc_size_, ColumnFlag::cumulative_alloc_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("parent_id", &parent_id_, ColumnFlag::parent_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("source_file", &source_file_, ColumnFlag::source_file,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("line_number", &line_number_, ColumnFlag::line_number,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("upid_group", &upid_group_, ColumnFlag::upid_group,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ExperimentalFlamegraphNodesTable() override;

  static const char* Name() { return "experimental_flamegraph_nodes"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "ts", ColumnType::ts::SqlValueType(), false,
        true,
        true,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid", ColumnType::upid::SqlValueType(), false,
        false,
        true,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "profile_type", ColumnType::profile_type::SqlValueType(), false,
        false,
        true,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "focus_str", ColumnType::focus_str::SqlValueType(), false,
        false,
        true,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "depth", ColumnType::depth::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "map_name", ColumnType::map_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "count", ColumnType::count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cumulative_count", ColumnType::cumulative_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "size", ColumnType::size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cumulative_size", ColumnType::cumulative_size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "alloc_count", ColumnType::alloc_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cumulative_alloc_count", ColumnType::cumulative_alloc_count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "alloc_size", ColumnType::alloc_size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cumulative_alloc_size", ColumnType::cumulative_alloc_size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "parent_id", ColumnType::parent_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_file", ColumnType::source_file::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "line_number", ColumnType::line_number::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid_group", ColumnType::upid_group::SqlValueType(), false,
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
    upid_.ShrinkToFit();
    profile_type_.ShrinkToFit();
    focus_str_.ShrinkToFit();
    depth_.ShrinkToFit();
    name_.ShrinkToFit();
    map_name_.ShrinkToFit();
    count_.ShrinkToFit();
    cumulative_count_.ShrinkToFit();
    size_.ShrinkToFit();
    cumulative_size_.ShrinkToFit();
    alloc_count_.ShrinkToFit();
    cumulative_alloc_count_.ShrinkToFit();
    alloc_size_.ShrinkToFit();
    cumulative_alloc_size_.ShrinkToFit();
    parent_id_.ShrinkToFit();
    source_file_.ShrinkToFit();
    line_number_.ShrinkToFit();
    upid_group_.ShrinkToFit();
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
    mutable_upid()->Append(std::move(row.upid));
    mutable_profile_type()->Append(std::move(row.profile_type));
    mutable_focus_str()->Append(std::move(row.focus_str));
    mutable_depth()->Append(std::move(row.depth));
    mutable_name()->Append(std::move(row.name));
    mutable_map_name()->Append(std::move(row.map_name));
    mutable_count()->Append(std::move(row.count));
    mutable_cumulative_count()->Append(std::move(row.cumulative_count));
    mutable_size()->Append(std::move(row.size));
    mutable_cumulative_size()->Append(std::move(row.cumulative_size));
    mutable_alloc_count()->Append(std::move(row.alloc_count));
    mutable_cumulative_alloc_count()->Append(std::move(row.cumulative_alloc_count));
    mutable_alloc_size()->Append(std::move(row.alloc_size));
    mutable_cumulative_alloc_size()->Append(std::move(row.cumulative_alloc_size));
    mutable_parent_id()->Append(std::move(row.parent_id));
    mutable_source_file()->Append(std::move(row.source_file));
    mutable_line_number()->Append(std::move(row.line_number));
    mutable_upid_group()->Append(std::move(row.upid_group));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ExperimentalFlamegraphNodesTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<StringPool::Id>& profile_type() const {
    return static_cast<const ColumnType::profile_type&>(columns_[ColumnIndex::profile_type]);
  }
  const TypedColumn<StringPool::Id>& focus_str() const {
    return static_cast<const ColumnType::focus_str&>(columns_[ColumnIndex::focus_str]);
  }
  const TypedColumn<uint32_t>& depth() const {
    return static_cast<const ColumnType::depth&>(columns_[ColumnIndex::depth]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<StringPool::Id>& map_name() const {
    return static_cast<const ColumnType::map_name&>(columns_[ColumnIndex::map_name]);
  }
  const TypedColumn<int64_t>& count() const {
    return static_cast<const ColumnType::count&>(columns_[ColumnIndex::count]);
  }
  const TypedColumn<int64_t>& cumulative_count() const {
    return static_cast<const ColumnType::cumulative_count&>(columns_[ColumnIndex::cumulative_count]);
  }
  const TypedColumn<int64_t>& size() const {
    return static_cast<const ColumnType::size&>(columns_[ColumnIndex::size]);
  }
  const TypedColumn<int64_t>& cumulative_size() const {
    return static_cast<const ColumnType::cumulative_size&>(columns_[ColumnIndex::cumulative_size]);
  }
  const TypedColumn<int64_t>& alloc_count() const {
    return static_cast<const ColumnType::alloc_count&>(columns_[ColumnIndex::alloc_count]);
  }
  const TypedColumn<int64_t>& cumulative_alloc_count() const {
    return static_cast<const ColumnType::cumulative_alloc_count&>(columns_[ColumnIndex::cumulative_alloc_count]);
  }
  const TypedColumn<int64_t>& alloc_size() const {
    return static_cast<const ColumnType::alloc_size&>(columns_[ColumnIndex::alloc_size]);
  }
  const TypedColumn<int64_t>& cumulative_alloc_size() const {
    return static_cast<const ColumnType::cumulative_alloc_size&>(columns_[ColumnIndex::cumulative_alloc_size]);
  }
  const TypedColumn<std::optional<ExperimentalFlamegraphNodesTable::Id>>& parent_id() const {
    return static_cast<const ColumnType::parent_id&>(columns_[ColumnIndex::parent_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& source_file() const {
    return static_cast<const ColumnType::source_file&>(columns_[ColumnIndex::source_file]);
  }
  const TypedColumn<std::optional<uint32_t>>& line_number() const {
    return static_cast<const ColumnType::line_number&>(columns_[ColumnIndex::line_number]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& upid_group() const {
    return static_cast<const ColumnType::upid_group&>(columns_[ColumnIndex::upid_group]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<StringPool::Id>* mutable_profile_type() {
    return static_cast<ColumnType::profile_type*>(
        &columns_[ColumnIndex::profile_type]);
  }
  TypedColumn<StringPool::Id>* mutable_focus_str() {
    return static_cast<ColumnType::focus_str*>(
        &columns_[ColumnIndex::focus_str]);
  }
  TypedColumn<uint32_t>* mutable_depth() {
    return static_cast<ColumnType::depth*>(
        &columns_[ColumnIndex::depth]);
  }
  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<StringPool::Id>* mutable_map_name() {
    return static_cast<ColumnType::map_name*>(
        &columns_[ColumnIndex::map_name]);
  }
  TypedColumn<int64_t>* mutable_count() {
    return static_cast<ColumnType::count*>(
        &columns_[ColumnIndex::count]);
  }
  TypedColumn<int64_t>* mutable_cumulative_count() {
    return static_cast<ColumnType::cumulative_count*>(
        &columns_[ColumnIndex::cumulative_count]);
  }
  TypedColumn<int64_t>* mutable_size() {
    return static_cast<ColumnType::size*>(
        &columns_[ColumnIndex::size]);
  }
  TypedColumn<int64_t>* mutable_cumulative_size() {
    return static_cast<ColumnType::cumulative_size*>(
        &columns_[ColumnIndex::cumulative_size]);
  }
  TypedColumn<int64_t>* mutable_alloc_count() {
    return static_cast<ColumnType::alloc_count*>(
        &columns_[ColumnIndex::alloc_count]);
  }
  TypedColumn<int64_t>* mutable_cumulative_alloc_count() {
    return static_cast<ColumnType::cumulative_alloc_count*>(
        &columns_[ColumnIndex::cumulative_alloc_count]);
  }
  TypedColumn<int64_t>* mutable_alloc_size() {
    return static_cast<ColumnType::alloc_size*>(
        &columns_[ColumnIndex::alloc_size]);
  }
  TypedColumn<int64_t>* mutable_cumulative_alloc_size() {
    return static_cast<ColumnType::cumulative_alloc_size*>(
        &columns_[ColumnIndex::cumulative_alloc_size]);
  }
  TypedColumn<std::optional<ExperimentalFlamegraphNodesTable::Id>>* mutable_parent_id() {
    return static_cast<ColumnType::parent_id*>(
        &columns_[ColumnIndex::parent_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_source_file() {
    return static_cast<ColumnType::source_file*>(
        &columns_[ColumnIndex::source_file]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_line_number() {
    return static_cast<ColumnType::line_number*>(
        &columns_[ColumnIndex::line_number]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_upid_group() {
    return static_cast<ColumnType::upid_group*>(
        &columns_[ColumnIndex::upid_group]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::profile_type::stored_type> profile_type_;
  ColumnStorage<ColumnType::focus_str::stored_type> focus_str_;
  ColumnStorage<ColumnType::depth::stored_type> depth_;
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::map_name::stored_type> map_name_;
  ColumnStorage<ColumnType::count::stored_type> count_;
  ColumnStorage<ColumnType::cumulative_count::stored_type> cumulative_count_;
  ColumnStorage<ColumnType::size::stored_type> size_;
  ColumnStorage<ColumnType::cumulative_size::stored_type> cumulative_size_;
  ColumnStorage<ColumnType::alloc_count::stored_type> alloc_count_;
  ColumnStorage<ColumnType::cumulative_alloc_count::stored_type> cumulative_alloc_count_;
  ColumnStorage<ColumnType::alloc_size::stored_type> alloc_size_;
  ColumnStorage<ColumnType::cumulative_alloc_size::stored_type> cumulative_alloc_size_;
  ColumnStorage<ColumnType::parent_id::stored_type> parent_id_;
  ColumnStorage<ColumnType::source_file::stored_type> source_file_;
  ColumnStorage<ColumnType::line_number::stored_type> line_number_;
  ColumnStorage<ColumnType::upid_group::stored_type> upid_group_;
};
  

class GpuCounterGroupTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t group_id = 2;
    static constexpr uint32_t track_id = 3;
  };
  struct ColumnType {
    using id = IdColumn<GpuCounterGroupTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using group_id = TypedColumn<int32_t>;
    using track_id = TypedColumn<TrackTable::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int32_t in_group_id = {},
        TrackTable::Id in_track_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          group_id(std::move(in_group_id)),
          track_id(std::move(in_track_id)) {
      type_ = "gpu_counter_group";
    }
    int32_t group_id;
    TrackTable::Id track_id;

    bool operator==(const GpuCounterGroupTable::Row& other) const {
      return type() == other.type() && ColumnType::group_id::Equals(group_id, other.group_id) &&
       ColumnType::track_id::Equals(track_id, other.track_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t group_id = ColumnType::group_id::default_flags();
    static constexpr uint32_t track_id = ColumnType::track_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      GpuCounterGroupTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    GpuCounterGroupTable, RowNumber> {
   public:
    ConstRowReference(const GpuCounterGroupTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::group_id::type group_id() const {
      return table_->group_id()[row_number_];
    }
    ColumnType::track_id::type track_id() const {
      return table_->track_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const GpuCounterGroupTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_group_id(
        ColumnType::group_id::non_optional_type v) {
      return mutable_table()->mutable_group_id()->Set(row_number_, v);
    }
    void set_track_id(
        ColumnType::track_id::non_optional_type v) {
      return mutable_table()->mutable_track_id()->Set(row_number_, v);
    }

   private:
    GpuCounterGroupTable* mutable_table() const {
      return const_cast<GpuCounterGroupTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, GpuCounterGroupTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::group_id::type group_id() const {
      const auto& col = table_->group_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::track_id::type track_id() const {
      const auto& col = table_->track_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const GpuCounterGroupTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class GpuCounterGroupTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_group_id(ColumnType::group_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_group_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_track_id(ColumnType::track_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_track_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class GpuCounterGroupTable;

    explicit Iterator(GpuCounterGroupTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    GpuCounterGroupTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit GpuCounterGroupTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        group_id_(ColumnStorage<ColumnType::group_id::stored_type>::Create<false>()),
        track_id_(ColumnStorage<ColumnType::track_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::group_id::stored_type>(
          ColumnFlag::group_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::track_id::stored_type>(
          ColumnFlag::track_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("group_id", &group_id_, ColumnFlag::group_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("track_id", &track_id_, ColumnFlag::track_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~GpuCounterGroupTable() override;

  static const char* Name() { return "gpu_counter_group"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "group_id", ColumnType::group_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "track_id", ColumnType::track_id::SqlValueType(), false,
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
    group_id_.ShrinkToFit();
    track_id_.ShrinkToFit();
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
    mutable_group_id()->Append(std::move(row.group_id));
    mutable_track_id()->Append(std::move(row.track_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<GpuCounterGroupTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int32_t>& group_id() const {
    return static_cast<const ColumnType::group_id&>(columns_[ColumnIndex::group_id]);
  }
  const TypedColumn<TrackTable::Id>& track_id() const {
    return static_cast<const ColumnType::track_id&>(columns_[ColumnIndex::track_id]);
  }

  TypedColumn<int32_t>* mutable_group_id() {
    return static_cast<ColumnType::group_id*>(
        &columns_[ColumnIndex::group_id]);
  }
  TypedColumn<TrackTable::Id>* mutable_track_id() {
    return static_cast<ColumnType::track_id*>(
        &columns_[ColumnIndex::track_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::group_id::stored_type> group_id_;
  ColumnStorage<ColumnType::track_id::stored_type> track_id_;
};
  

class HeapGraphClassTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t deobfuscated_name = 3;
    static constexpr uint32_t location = 4;
    static constexpr uint32_t superclass_id = 5;
    static constexpr uint32_t classloader_id = 6;
    static constexpr uint32_t kind = 7;
  };
  struct ColumnType {
    using id = IdColumn<HeapGraphClassTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using name = TypedColumn<StringPool::Id>;
    using deobfuscated_name = TypedColumn<std::optional<StringPool::Id>>;
    using location = TypedColumn<std::optional<StringPool::Id>>;
    using superclass_id = TypedColumn<std::optional<HeapGraphClassTable::Id>>;
    using classloader_id = TypedColumn<std::optional<uint32_t>>;
    using kind = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_name = {},
        std::optional<StringPool::Id> in_deobfuscated_name = {},
        std::optional<StringPool::Id> in_location = {},
        std::optional<HeapGraphClassTable::Id> in_superclass_id = {},
        std::optional<uint32_t> in_classloader_id = {},
        StringPool::Id in_kind = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          name(std::move(in_name)),
          deobfuscated_name(std::move(in_deobfuscated_name)),
          location(std::move(in_location)),
          superclass_id(std::move(in_superclass_id)),
          classloader_id(std::move(in_classloader_id)),
          kind(std::move(in_kind)) {
      type_ = "heap_graph_class";
    }
    StringPool::Id name;
    std::optional<StringPool::Id> deobfuscated_name;
    std::optional<StringPool::Id> location;
    std::optional<HeapGraphClassTable::Id> superclass_id;
    std::optional<uint32_t> classloader_id;
    StringPool::Id kind;

    bool operator==(const HeapGraphClassTable::Row& other) const {
      return type() == other.type() && ColumnType::name::Equals(name, other.name) &&
       ColumnType::deobfuscated_name::Equals(deobfuscated_name, other.deobfuscated_name) &&
       ColumnType::location::Equals(location, other.location) &&
       ColumnType::superclass_id::Equals(superclass_id, other.superclass_id) &&
       ColumnType::classloader_id::Equals(classloader_id, other.classloader_id) &&
       ColumnType::kind::Equals(kind, other.kind);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t deobfuscated_name = ColumnType::deobfuscated_name::default_flags();
    static constexpr uint32_t location = ColumnType::location::default_flags();
    static constexpr uint32_t superclass_id = ColumnType::superclass_id::default_flags();
    static constexpr uint32_t classloader_id = ColumnType::classloader_id::default_flags();
    static constexpr uint32_t kind = ColumnType::kind::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      HeapGraphClassTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    HeapGraphClassTable, RowNumber> {
   public:
    ConstRowReference(const HeapGraphClassTable* table, uint32_t row_number)
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
    ColumnType::deobfuscated_name::type deobfuscated_name() const {
      return table_->deobfuscated_name()[row_number_];
    }
    ColumnType::location::type location() const {
      return table_->location()[row_number_];
    }
    ColumnType::superclass_id::type superclass_id() const {
      return table_->superclass_id()[row_number_];
    }
    ColumnType::classloader_id::type classloader_id() const {
      return table_->classloader_id()[row_number_];
    }
    ColumnType::kind::type kind() const {
      return table_->kind()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const HeapGraphClassTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_deobfuscated_name(
        ColumnType::deobfuscated_name::non_optional_type v) {
      return mutable_table()->mutable_deobfuscated_name()->Set(row_number_, v);
    }
    void set_location(
        ColumnType::location::non_optional_type v) {
      return mutable_table()->mutable_location()->Set(row_number_, v);
    }
    void set_superclass_id(
        ColumnType::superclass_id::non_optional_type v) {
      return mutable_table()->mutable_superclass_id()->Set(row_number_, v);
    }
    void set_classloader_id(
        ColumnType::classloader_id::non_optional_type v) {
      return mutable_table()->mutable_classloader_id()->Set(row_number_, v);
    }
    void set_kind(
        ColumnType::kind::non_optional_type v) {
      return mutable_table()->mutable_kind()->Set(row_number_, v);
    }

   private:
    HeapGraphClassTable* mutable_table() const {
      return const_cast<HeapGraphClassTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, HeapGraphClassTable, RowNumber, ConstRowReference> {
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
    ColumnType::deobfuscated_name::type deobfuscated_name() const {
      const auto& col = table_->deobfuscated_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::location::type location() const {
      const auto& col = table_->location();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::superclass_id::type superclass_id() const {
      const auto& col = table_->superclass_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::classloader_id::type classloader_id() const {
      const auto& col = table_->classloader_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::kind::type kind() const {
      const auto& col = table_->kind();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const HeapGraphClassTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class HeapGraphClassTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_deobfuscated_name(ColumnType::deobfuscated_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_deobfuscated_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_location(ColumnType::location::non_optional_type v) {
        auto* col = mutable_table_->mutable_location();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_superclass_id(ColumnType::superclass_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_superclass_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_classloader_id(ColumnType::classloader_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_classloader_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_kind(ColumnType::kind::non_optional_type v) {
        auto* col = mutable_table_->mutable_kind();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class HeapGraphClassTable;

    explicit Iterator(HeapGraphClassTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    HeapGraphClassTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit HeapGraphClassTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        deobfuscated_name_(ColumnStorage<ColumnType::deobfuscated_name::stored_type>::Create<false>()),
        location_(ColumnStorage<ColumnType::location::stored_type>::Create<false>()),
        superclass_id_(ColumnStorage<ColumnType::superclass_id::stored_type>::Create<false>()),
        classloader_id_(ColumnStorage<ColumnType::classloader_id::stored_type>::Create<false>()),
        kind_(ColumnStorage<ColumnType::kind::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::deobfuscated_name::stored_type>(
          ColumnFlag::deobfuscated_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::location::stored_type>(
          ColumnFlag::location),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::superclass_id::stored_type>(
          ColumnFlag::superclass_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::classloader_id::stored_type>(
          ColumnFlag::classloader_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::kind::stored_type>(
          ColumnFlag::kind),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("deobfuscated_name", &deobfuscated_name_, ColumnFlag::deobfuscated_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("location", &location_, ColumnFlag::location,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("superclass_id", &superclass_id_, ColumnFlag::superclass_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("classloader_id", &classloader_id_, ColumnFlag::classloader_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("kind", &kind_, ColumnFlag::kind,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~HeapGraphClassTable() override;

  static const char* Name() { return "heap_graph_class"; }

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
        "deobfuscated_name", ColumnType::deobfuscated_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "location", ColumnType::location::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "superclass_id", ColumnType::superclass_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "classloader_id", ColumnType::classloader_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "kind", ColumnType::kind::SqlValueType(), false,
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
    deobfuscated_name_.ShrinkToFit();
    location_.ShrinkToFit();
    superclass_id_.ShrinkToFit();
    classloader_id_.ShrinkToFit();
    kind_.ShrinkToFit();
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
    mutable_deobfuscated_name()->Append(std::move(row.deobfuscated_name));
    mutable_location()->Append(std::move(row.location));
    mutable_superclass_id()->Append(std::move(row.superclass_id));
    mutable_classloader_id()->Append(std::move(row.classloader_id));
    mutable_kind()->Append(std::move(row.kind));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<HeapGraphClassTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& deobfuscated_name() const {
    return static_cast<const ColumnType::deobfuscated_name&>(columns_[ColumnIndex::deobfuscated_name]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& location() const {
    return static_cast<const ColumnType::location&>(columns_[ColumnIndex::location]);
  }
  const TypedColumn<std::optional<HeapGraphClassTable::Id>>& superclass_id() const {
    return static_cast<const ColumnType::superclass_id&>(columns_[ColumnIndex::superclass_id]);
  }
  const TypedColumn<std::optional<uint32_t>>& classloader_id() const {
    return static_cast<const ColumnType::classloader_id&>(columns_[ColumnIndex::classloader_id]);
  }
  const TypedColumn<StringPool::Id>& kind() const {
    return static_cast<const ColumnType::kind&>(columns_[ColumnIndex::kind]);
  }

  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_deobfuscated_name() {
    return static_cast<ColumnType::deobfuscated_name*>(
        &columns_[ColumnIndex::deobfuscated_name]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_location() {
    return static_cast<ColumnType::location*>(
        &columns_[ColumnIndex::location]);
  }
  TypedColumn<std::optional<HeapGraphClassTable::Id>>* mutable_superclass_id() {
    return static_cast<ColumnType::superclass_id*>(
        &columns_[ColumnIndex::superclass_id]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_classloader_id() {
    return static_cast<ColumnType::classloader_id*>(
        &columns_[ColumnIndex::classloader_id]);
  }
  TypedColumn<StringPool::Id>* mutable_kind() {
    return static_cast<ColumnType::kind*>(
        &columns_[ColumnIndex::kind]);
  }

 private:
  
  
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::deobfuscated_name::stored_type> deobfuscated_name_;
  ColumnStorage<ColumnType::location::stored_type> location_;
  ColumnStorage<ColumnType::superclass_id::stored_type> superclass_id_;
  ColumnStorage<ColumnType::classloader_id::stored_type> classloader_id_;
  ColumnStorage<ColumnType::kind::stored_type> kind_;
};
  

class HeapGraphObjectTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t graph_sample_ts = 3;
    static constexpr uint32_t self_size = 4;
    static constexpr uint32_t native_size = 5;
    static constexpr uint32_t reference_set_id = 6;
    static constexpr uint32_t reachable = 7;
    static constexpr uint32_t type_id = 8;
    static constexpr uint32_t root_type = 9;
    static constexpr uint32_t root_distance = 10;
  };
  struct ColumnType {
    using id = IdColumn<HeapGraphObjectTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using upid = TypedColumn<uint32_t>;
    using graph_sample_ts = TypedColumn<int64_t>;
    using self_size = TypedColumn<int64_t>;
    using native_size = TypedColumn<int64_t>;
    using reference_set_id = TypedColumn<std::optional<uint32_t>>;
    using reachable = TypedColumn<int32_t>;
    using type_id = TypedColumn<HeapGraphClassTable::Id>;
    using root_type = TypedColumn<std::optional<StringPool::Id>>;
    using root_distance = TypedColumn<int32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_upid = {},
        int64_t in_graph_sample_ts = {},
        int64_t in_self_size = {},
        int64_t in_native_size = {},
        std::optional<uint32_t> in_reference_set_id = {},
        int32_t in_reachable = {},
        HeapGraphClassTable::Id in_type_id = {},
        std::optional<StringPool::Id> in_root_type = {},
        int32_t in_root_distance = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          upid(std::move(in_upid)),
          graph_sample_ts(std::move(in_graph_sample_ts)),
          self_size(std::move(in_self_size)),
          native_size(std::move(in_native_size)),
          reference_set_id(std::move(in_reference_set_id)),
          reachable(std::move(in_reachable)),
          type_id(std::move(in_type_id)),
          root_type(std::move(in_root_type)),
          root_distance(std::move(in_root_distance)) {
      type_ = "heap_graph_object";
    }
    uint32_t upid;
    int64_t graph_sample_ts;
    int64_t self_size;
    int64_t native_size;
    std::optional<uint32_t> reference_set_id;
    int32_t reachable;
    HeapGraphClassTable::Id type_id;
    std::optional<StringPool::Id> root_type;
    int32_t root_distance;

    bool operator==(const HeapGraphObjectTable::Row& other) const {
      return type() == other.type() && ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::graph_sample_ts::Equals(graph_sample_ts, other.graph_sample_ts) &&
       ColumnType::self_size::Equals(self_size, other.self_size) &&
       ColumnType::native_size::Equals(native_size, other.native_size) &&
       ColumnType::reference_set_id::Equals(reference_set_id, other.reference_set_id) &&
       ColumnType::reachable::Equals(reachable, other.reachable) &&
       ColumnType::type_id::Equals(type_id, other.type_id) &&
       ColumnType::root_type::Equals(root_type, other.root_type) &&
       ColumnType::root_distance::Equals(root_distance, other.root_distance);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
    static constexpr uint32_t graph_sample_ts = ColumnType::graph_sample_ts::default_flags();
    static constexpr uint32_t self_size = ColumnType::self_size::default_flags();
    static constexpr uint32_t native_size = ColumnType::native_size::default_flags();
    static constexpr uint32_t reference_set_id = static_cast<uint32_t>(Column::Flag::kDense) | ColumnType::reference_set_id::default_flags();
    static constexpr uint32_t reachable = ColumnType::reachable::default_flags();
    static constexpr uint32_t type_id = ColumnType::type_id::default_flags();
    static constexpr uint32_t root_type = ColumnType::root_type::default_flags();
    static constexpr uint32_t root_distance = static_cast<uint32_t>(Column::Flag::kHidden) | ColumnType::root_distance::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      HeapGraphObjectTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    HeapGraphObjectTable, RowNumber> {
   public:
    ConstRowReference(const HeapGraphObjectTable* table, uint32_t row_number)
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
    ColumnType::graph_sample_ts::type graph_sample_ts() const {
      return table_->graph_sample_ts()[row_number_];
    }
    ColumnType::self_size::type self_size() const {
      return table_->self_size()[row_number_];
    }
    ColumnType::native_size::type native_size() const {
      return table_->native_size()[row_number_];
    }
    ColumnType::reference_set_id::type reference_set_id() const {
      return table_->reference_set_id()[row_number_];
    }
    ColumnType::reachable::type reachable() const {
      return table_->reachable()[row_number_];
    }
    ColumnType::type_id::type type_id() const {
      return table_->type_id()[row_number_];
    }
    ColumnType::root_type::type root_type() const {
      return table_->root_type()[row_number_];
    }
    ColumnType::root_distance::type root_distance() const {
      return table_->root_distance()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const HeapGraphObjectTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_graph_sample_ts(
        ColumnType::graph_sample_ts::non_optional_type v) {
      return mutable_table()->mutable_graph_sample_ts()->Set(row_number_, v);
    }
    void set_self_size(
        ColumnType::self_size::non_optional_type v) {
      return mutable_table()->mutable_self_size()->Set(row_number_, v);
    }
    void set_native_size(
        ColumnType::native_size::non_optional_type v) {
      return mutable_table()->mutable_native_size()->Set(row_number_, v);
    }
    void set_reference_set_id(
        ColumnType::reference_set_id::non_optional_type v) {
      return mutable_table()->mutable_reference_set_id()->Set(row_number_, v);
    }
    void set_reachable(
        ColumnType::reachable::non_optional_type v) {
      return mutable_table()->mutable_reachable()->Set(row_number_, v);
    }
    void set_type_id(
        ColumnType::type_id::non_optional_type v) {
      return mutable_table()->mutable_type_id()->Set(row_number_, v);
    }
    void set_root_type(
        ColumnType::root_type::non_optional_type v) {
      return mutable_table()->mutable_root_type()->Set(row_number_, v);
    }
    void set_root_distance(
        ColumnType::root_distance::non_optional_type v) {
      return mutable_table()->mutable_root_distance()->Set(row_number_, v);
    }

   private:
    HeapGraphObjectTable* mutable_table() const {
      return const_cast<HeapGraphObjectTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, HeapGraphObjectTable, RowNumber, ConstRowReference> {
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
    ColumnType::graph_sample_ts::type graph_sample_ts() const {
      const auto& col = table_->graph_sample_ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::self_size::type self_size() const {
      const auto& col = table_->self_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::native_size::type native_size() const {
      const auto& col = table_->native_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::reference_set_id::type reference_set_id() const {
      const auto& col = table_->reference_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::reachable::type reachable() const {
      const auto& col = table_->reachable();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type_id::type type_id() const {
      const auto& col = table_->type_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::root_type::type root_type() const {
      const auto& col = table_->root_type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::root_distance::type root_distance() const {
      const auto& col = table_->root_distance();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const HeapGraphObjectTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class HeapGraphObjectTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_graph_sample_ts(ColumnType::graph_sample_ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_graph_sample_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_self_size(ColumnType::self_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_self_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_native_size(ColumnType::native_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_native_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_reference_set_id(ColumnType::reference_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_reference_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_reachable(ColumnType::reachable::non_optional_type v) {
        auto* col = mutable_table_->mutable_reachable();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_type_id(ColumnType::type_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_type_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_root_type(ColumnType::root_type::non_optional_type v) {
        auto* col = mutable_table_->mutable_root_type();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_root_distance(ColumnType::root_distance::non_optional_type v) {
        auto* col = mutable_table_->mutable_root_distance();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class HeapGraphObjectTable;

    explicit Iterator(HeapGraphObjectTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    HeapGraphObjectTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit HeapGraphObjectTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        graph_sample_ts_(ColumnStorage<ColumnType::graph_sample_ts::stored_type>::Create<false>()),
        self_size_(ColumnStorage<ColumnType::self_size::stored_type>::Create<false>()),
        native_size_(ColumnStorage<ColumnType::native_size::stored_type>::Create<false>()),
        reference_set_id_(ColumnStorage<ColumnType::reference_set_id::stored_type>::Create<true>()),
        reachable_(ColumnStorage<ColumnType::reachable::stored_type>::Create<false>()),
        type_id_(ColumnStorage<ColumnType::type_id::stored_type>::Create<false>()),
        root_type_(ColumnStorage<ColumnType::root_type::stored_type>::Create<false>()),
        root_distance_(ColumnStorage<ColumnType::root_distance::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::graph_sample_ts::stored_type>(
          ColumnFlag::graph_sample_ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::self_size::stored_type>(
          ColumnFlag::self_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::native_size::stored_type>(
          ColumnFlag::native_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::reference_set_id::stored_type>(
          ColumnFlag::reference_set_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::reachable::stored_type>(
          ColumnFlag::reachable),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::type_id::stored_type>(
          ColumnFlag::type_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::root_type::stored_type>(
          ColumnFlag::root_type),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::root_distance::stored_type>(
          ColumnFlag::root_distance),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("graph_sample_ts", &graph_sample_ts_, ColumnFlag::graph_sample_ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("self_size", &self_size_, ColumnFlag::self_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("native_size", &native_size_, ColumnFlag::native_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("reference_set_id", &reference_set_id_, ColumnFlag::reference_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("reachable", &reachable_, ColumnFlag::reachable,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("type_id", &type_id_, ColumnFlag::type_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("root_type", &root_type_, ColumnFlag::root_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("root_distance", &root_distance_, ColumnFlag::root_distance,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~HeapGraphObjectTable() override;

  static const char* Name() { return "heap_graph_object"; }

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
        "graph_sample_ts", ColumnType::graph_sample_ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "self_size", ColumnType::self_size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "native_size", ColumnType::native_size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "reference_set_id", ColumnType::reference_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "reachable", ColumnType::reachable::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type_id", ColumnType::type_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "root_type", ColumnType::root_type::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "root_distance", ColumnType::root_distance::SqlValueType(), false,
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
    type_.ShrinkToFit();
    upid_.ShrinkToFit();
    graph_sample_ts_.ShrinkToFit();
    self_size_.ShrinkToFit();
    native_size_.ShrinkToFit();
    reference_set_id_.ShrinkToFit();
    reachable_.ShrinkToFit();
    type_id_.ShrinkToFit();
    root_type_.ShrinkToFit();
    root_distance_.ShrinkToFit();
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
    mutable_graph_sample_ts()->Append(std::move(row.graph_sample_ts));
    mutable_self_size()->Append(std::move(row.self_size));
    mutable_native_size()->Append(std::move(row.native_size));
    mutable_reference_set_id()->Append(std::move(row.reference_set_id));
    mutable_reachable()->Append(std::move(row.reachable));
    mutable_type_id()->Append(std::move(row.type_id));
    mutable_root_type()->Append(std::move(row.root_type));
    mutable_root_distance()->Append(std::move(row.root_distance));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<HeapGraphObjectTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<int64_t>& graph_sample_ts() const {
    return static_cast<const ColumnType::graph_sample_ts&>(columns_[ColumnIndex::graph_sample_ts]);
  }
  const TypedColumn<int64_t>& self_size() const {
    return static_cast<const ColumnType::self_size&>(columns_[ColumnIndex::self_size]);
  }
  const TypedColumn<int64_t>& native_size() const {
    return static_cast<const ColumnType::native_size&>(columns_[ColumnIndex::native_size]);
  }
  const TypedColumn<std::optional<uint32_t>>& reference_set_id() const {
    return static_cast<const ColumnType::reference_set_id&>(columns_[ColumnIndex::reference_set_id]);
  }
  const TypedColumn<int32_t>& reachable() const {
    return static_cast<const ColumnType::reachable&>(columns_[ColumnIndex::reachable]);
  }
  const TypedColumn<HeapGraphClassTable::Id>& type_id() const {
    return static_cast<const ColumnType::type_id&>(columns_[ColumnIndex::type_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& root_type() const {
    return static_cast<const ColumnType::root_type&>(columns_[ColumnIndex::root_type]);
  }
  const TypedColumn<int32_t>& root_distance() const {
    return static_cast<const ColumnType::root_distance&>(columns_[ColumnIndex::root_distance]);
  }

  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<int64_t>* mutable_graph_sample_ts() {
    return static_cast<ColumnType::graph_sample_ts*>(
        &columns_[ColumnIndex::graph_sample_ts]);
  }
  TypedColumn<int64_t>* mutable_self_size() {
    return static_cast<ColumnType::self_size*>(
        &columns_[ColumnIndex::self_size]);
  }
  TypedColumn<int64_t>* mutable_native_size() {
    return static_cast<ColumnType::native_size*>(
        &columns_[ColumnIndex::native_size]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_reference_set_id() {
    return static_cast<ColumnType::reference_set_id*>(
        &columns_[ColumnIndex::reference_set_id]);
  }
  TypedColumn<int32_t>* mutable_reachable() {
    return static_cast<ColumnType::reachable*>(
        &columns_[ColumnIndex::reachable]);
  }
  TypedColumn<HeapGraphClassTable::Id>* mutable_type_id() {
    return static_cast<ColumnType::type_id*>(
        &columns_[ColumnIndex::type_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_root_type() {
    return static_cast<ColumnType::root_type*>(
        &columns_[ColumnIndex::root_type]);
  }
  TypedColumn<int32_t>* mutable_root_distance() {
    return static_cast<ColumnType::root_distance*>(
        &columns_[ColumnIndex::root_distance]);
  }

 private:
  
  
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::graph_sample_ts::stored_type> graph_sample_ts_;
  ColumnStorage<ColumnType::self_size::stored_type> self_size_;
  ColumnStorage<ColumnType::native_size::stored_type> native_size_;
  ColumnStorage<ColumnType::reference_set_id::stored_type> reference_set_id_;
  ColumnStorage<ColumnType::reachable::stored_type> reachable_;
  ColumnStorage<ColumnType::type_id::stored_type> type_id_;
  ColumnStorage<ColumnType::root_type::stored_type> root_type_;
  ColumnStorage<ColumnType::root_distance::stored_type> root_distance_;
};
  

class HeapGraphReferenceTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t reference_set_id = 2;
    static constexpr uint32_t owner_id = 3;
    static constexpr uint32_t owned_id = 4;
    static constexpr uint32_t field_name = 5;
    static constexpr uint32_t field_type_name = 6;
    static constexpr uint32_t deobfuscated_field_name = 7;
  };
  struct ColumnType {
    using id = IdColumn<HeapGraphReferenceTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using reference_set_id = TypedColumn<uint32_t>;
    using owner_id = TypedColumn<HeapGraphObjectTable::Id>;
    using owned_id = TypedColumn<std::optional<HeapGraphObjectTable::Id>>;
    using field_name = TypedColumn<StringPool::Id>;
    using field_type_name = TypedColumn<StringPool::Id>;
    using deobfuscated_field_name = TypedColumn<std::optional<StringPool::Id>>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_reference_set_id = {},
        HeapGraphObjectTable::Id in_owner_id = {},
        std::optional<HeapGraphObjectTable::Id> in_owned_id = {},
        StringPool::Id in_field_name = {},
        StringPool::Id in_field_type_name = {},
        std::optional<StringPool::Id> in_deobfuscated_field_name = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          reference_set_id(std::move(in_reference_set_id)),
          owner_id(std::move(in_owner_id)),
          owned_id(std::move(in_owned_id)),
          field_name(std::move(in_field_name)),
          field_type_name(std::move(in_field_type_name)),
          deobfuscated_field_name(std::move(in_deobfuscated_field_name)) {
      type_ = "heap_graph_reference";
    }
    uint32_t reference_set_id;
    HeapGraphObjectTable::Id owner_id;
    std::optional<HeapGraphObjectTable::Id> owned_id;
    StringPool::Id field_name;
    StringPool::Id field_type_name;
    std::optional<StringPool::Id> deobfuscated_field_name;

    bool operator==(const HeapGraphReferenceTable::Row& other) const {
      return type() == other.type() && ColumnType::reference_set_id::Equals(reference_set_id, other.reference_set_id) &&
       ColumnType::owner_id::Equals(owner_id, other.owner_id) &&
       ColumnType::owned_id::Equals(owned_id, other.owned_id) &&
       ColumnType::field_name::Equals(field_name, other.field_name) &&
       ColumnType::field_type_name::Equals(field_type_name, other.field_type_name) &&
       ColumnType::deobfuscated_field_name::Equals(deobfuscated_field_name, other.deobfuscated_field_name);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t reference_set_id = static_cast<uint32_t>(Column::Flag::kSorted | Column::Flag::kSetId) | ColumnType::reference_set_id::default_flags();
    static constexpr uint32_t owner_id = ColumnType::owner_id::default_flags();
    static constexpr uint32_t owned_id = ColumnType::owned_id::default_flags();
    static constexpr uint32_t field_name = ColumnType::field_name::default_flags();
    static constexpr uint32_t field_type_name = ColumnType::field_type_name::default_flags();
    static constexpr uint32_t deobfuscated_field_name = ColumnType::deobfuscated_field_name::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      HeapGraphReferenceTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    HeapGraphReferenceTable, RowNumber> {
   public:
    ConstRowReference(const HeapGraphReferenceTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::reference_set_id::type reference_set_id() const {
      return table_->reference_set_id()[row_number_];
    }
    ColumnType::owner_id::type owner_id() const {
      return table_->owner_id()[row_number_];
    }
    ColumnType::owned_id::type owned_id() const {
      return table_->owned_id()[row_number_];
    }
    ColumnType::field_name::type field_name() const {
      return table_->field_name()[row_number_];
    }
    ColumnType::field_type_name::type field_type_name() const {
      return table_->field_type_name()[row_number_];
    }
    ColumnType::deobfuscated_field_name::type deobfuscated_field_name() const {
      return table_->deobfuscated_field_name()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const HeapGraphReferenceTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_reference_set_id(
        ColumnType::reference_set_id::non_optional_type v) {
      return mutable_table()->mutable_reference_set_id()->Set(row_number_, v);
    }
    void set_owner_id(
        ColumnType::owner_id::non_optional_type v) {
      return mutable_table()->mutable_owner_id()->Set(row_number_, v);
    }
    void set_owned_id(
        ColumnType::owned_id::non_optional_type v) {
      return mutable_table()->mutable_owned_id()->Set(row_number_, v);
    }
    void set_field_name(
        ColumnType::field_name::non_optional_type v) {
      return mutable_table()->mutable_field_name()->Set(row_number_, v);
    }
    void set_field_type_name(
        ColumnType::field_type_name::non_optional_type v) {
      return mutable_table()->mutable_field_type_name()->Set(row_number_, v);
    }
    void set_deobfuscated_field_name(
        ColumnType::deobfuscated_field_name::non_optional_type v) {
      return mutable_table()->mutable_deobfuscated_field_name()->Set(row_number_, v);
    }

   private:
    HeapGraphReferenceTable* mutable_table() const {
      return const_cast<HeapGraphReferenceTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, HeapGraphReferenceTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::reference_set_id::type reference_set_id() const {
      const auto& col = table_->reference_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::owner_id::type owner_id() const {
      const auto& col = table_->owner_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::owned_id::type owned_id() const {
      const auto& col = table_->owned_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::field_name::type field_name() const {
      const auto& col = table_->field_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::field_type_name::type field_type_name() const {
      const auto& col = table_->field_type_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::deobfuscated_field_name::type deobfuscated_field_name() const {
      const auto& col = table_->deobfuscated_field_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const HeapGraphReferenceTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class HeapGraphReferenceTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_reference_set_id(ColumnType::reference_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_reference_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_owner_id(ColumnType::owner_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_owner_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_owned_id(ColumnType::owned_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_owned_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_field_name(ColumnType::field_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_field_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_field_type_name(ColumnType::field_type_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_field_type_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_deobfuscated_field_name(ColumnType::deobfuscated_field_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_deobfuscated_field_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class HeapGraphReferenceTable;

    explicit Iterator(HeapGraphReferenceTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    HeapGraphReferenceTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit HeapGraphReferenceTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        reference_set_id_(ColumnStorage<ColumnType::reference_set_id::stored_type>::Create<false>()),
        owner_id_(ColumnStorage<ColumnType::owner_id::stored_type>::Create<false>()),
        owned_id_(ColumnStorage<ColumnType::owned_id::stored_type>::Create<false>()),
        field_name_(ColumnStorage<ColumnType::field_name::stored_type>::Create<false>()),
        field_type_name_(ColumnStorage<ColumnType::field_type_name::stored_type>::Create<false>()),
        deobfuscated_field_name_(ColumnStorage<ColumnType::deobfuscated_field_name::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::reference_set_id::stored_type>(
          ColumnFlag::reference_set_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::owner_id::stored_type>(
          ColumnFlag::owner_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::owned_id::stored_type>(
          ColumnFlag::owned_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::field_name::stored_type>(
          ColumnFlag::field_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::field_type_name::stored_type>(
          ColumnFlag::field_type_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::deobfuscated_field_name::stored_type>(
          ColumnFlag::deobfuscated_field_name),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("reference_set_id", &reference_set_id_, ColumnFlag::reference_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("owner_id", &owner_id_, ColumnFlag::owner_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("owned_id", &owned_id_, ColumnFlag::owned_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("field_name", &field_name_, ColumnFlag::field_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("field_type_name", &field_type_name_, ColumnFlag::field_type_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("deobfuscated_field_name", &deobfuscated_field_name_, ColumnFlag::deobfuscated_field_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~HeapGraphReferenceTable() override;

  static const char* Name() { return "heap_graph_reference"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "reference_set_id", ColumnType::reference_set_id::SqlValueType(), false,
        true,
        false,
        true});
    schema.columns.emplace_back(Table::Schema::Column{
        "owner_id", ColumnType::owner_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "owned_id", ColumnType::owned_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "field_name", ColumnType::field_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "field_type_name", ColumnType::field_type_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "deobfuscated_field_name", ColumnType::deobfuscated_field_name::SqlValueType(), false,
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
    reference_set_id_.ShrinkToFit();
    owner_id_.ShrinkToFit();
    owned_id_.ShrinkToFit();
    field_name_.ShrinkToFit();
    field_type_name_.ShrinkToFit();
    deobfuscated_field_name_.ShrinkToFit();
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
    mutable_reference_set_id()->Append(std::move(row.reference_set_id));
    mutable_owner_id()->Append(std::move(row.owner_id));
    mutable_owned_id()->Append(std::move(row.owned_id));
    mutable_field_name()->Append(std::move(row.field_name));
    mutable_field_type_name()->Append(std::move(row.field_type_name));
    mutable_deobfuscated_field_name()->Append(std::move(row.deobfuscated_field_name));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<HeapGraphReferenceTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& reference_set_id() const {
    return static_cast<const ColumnType::reference_set_id&>(columns_[ColumnIndex::reference_set_id]);
  }
  const TypedColumn<HeapGraphObjectTable::Id>& owner_id() const {
    return static_cast<const ColumnType::owner_id&>(columns_[ColumnIndex::owner_id]);
  }
  const TypedColumn<std::optional<HeapGraphObjectTable::Id>>& owned_id() const {
    return static_cast<const ColumnType::owned_id&>(columns_[ColumnIndex::owned_id]);
  }
  const TypedColumn<StringPool::Id>& field_name() const {
    return static_cast<const ColumnType::field_name&>(columns_[ColumnIndex::field_name]);
  }
  const TypedColumn<StringPool::Id>& field_type_name() const {
    return static_cast<const ColumnType::field_type_name&>(columns_[ColumnIndex::field_type_name]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& deobfuscated_field_name() const {
    return static_cast<const ColumnType::deobfuscated_field_name&>(columns_[ColumnIndex::deobfuscated_field_name]);
  }

  TypedColumn<uint32_t>* mutable_reference_set_id() {
    return static_cast<ColumnType::reference_set_id*>(
        &columns_[ColumnIndex::reference_set_id]);
  }
  TypedColumn<HeapGraphObjectTable::Id>* mutable_owner_id() {
    return static_cast<ColumnType::owner_id*>(
        &columns_[ColumnIndex::owner_id]);
  }
  TypedColumn<std::optional<HeapGraphObjectTable::Id>>* mutable_owned_id() {
    return static_cast<ColumnType::owned_id*>(
        &columns_[ColumnIndex::owned_id]);
  }
  TypedColumn<StringPool::Id>* mutable_field_name() {
    return static_cast<ColumnType::field_name*>(
        &columns_[ColumnIndex::field_name]);
  }
  TypedColumn<StringPool::Id>* mutable_field_type_name() {
    return static_cast<ColumnType::field_type_name*>(
        &columns_[ColumnIndex::field_type_name]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_deobfuscated_field_name() {
    return static_cast<ColumnType::deobfuscated_field_name*>(
        &columns_[ColumnIndex::deobfuscated_field_name]);
  }

 private:
  
  
  ColumnStorage<ColumnType::reference_set_id::stored_type> reference_set_id_;
  ColumnStorage<ColumnType::owner_id::stored_type> owner_id_;
  ColumnStorage<ColumnType::owned_id::stored_type> owned_id_;
  ColumnStorage<ColumnType::field_name::stored_type> field_name_;
  ColumnStorage<ColumnType::field_type_name::stored_type> field_type_name_;
  ColumnStorage<ColumnType::deobfuscated_field_name::stored_type> deobfuscated_field_name_;
};
  

class HeapProfileAllocationTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t upid = 3;
    static constexpr uint32_t heap_name = 4;
    static constexpr uint32_t callsite_id = 5;
    static constexpr uint32_t count = 6;
    static constexpr uint32_t size = 7;
  };
  struct ColumnType {
    using id = IdColumn<HeapProfileAllocationTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using upid = TypedColumn<uint32_t>;
    using heap_name = TypedColumn<StringPool::Id>;
    using callsite_id = TypedColumn<StackProfileCallsiteTable::Id>;
    using count = TypedColumn<int64_t>;
    using size = TypedColumn<int64_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        uint32_t in_upid = {},
        StringPool::Id in_heap_name = {},
        StackProfileCallsiteTable::Id in_callsite_id = {},
        int64_t in_count = {},
        int64_t in_size = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          upid(std::move(in_upid)),
          heap_name(std::move(in_heap_name)),
          callsite_id(std::move(in_callsite_id)),
          count(std::move(in_count)),
          size(std::move(in_size)) {
      type_ = "heap_profile_allocation";
    }
    int64_t ts;
    uint32_t upid;
    StringPool::Id heap_name;
    StackProfileCallsiteTable::Id callsite_id;
    int64_t count;
    int64_t size;

    bool operator==(const HeapProfileAllocationTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::heap_name::Equals(heap_name, other.heap_name) &&
       ColumnType::callsite_id::Equals(callsite_id, other.callsite_id) &&
       ColumnType::count::Equals(count, other.count) &&
       ColumnType::size::Equals(size, other.size);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = ColumnType::ts::default_flags();
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
    static constexpr uint32_t heap_name = ColumnType::heap_name::default_flags();
    static constexpr uint32_t callsite_id = ColumnType::callsite_id::default_flags();
    static constexpr uint32_t count = ColumnType::count::default_flags();
    static constexpr uint32_t size = ColumnType::size::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      HeapProfileAllocationTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    HeapProfileAllocationTable, RowNumber> {
   public:
    ConstRowReference(const HeapProfileAllocationTable* table, uint32_t row_number)
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
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
    ColumnType::heap_name::type heap_name() const {
      return table_->heap_name()[row_number_];
    }
    ColumnType::callsite_id::type callsite_id() const {
      return table_->callsite_id()[row_number_];
    }
    ColumnType::count::type count() const {
      return table_->count()[row_number_];
    }
    ColumnType::size::type size() const {
      return table_->size()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const HeapProfileAllocationTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_heap_name(
        ColumnType::heap_name::non_optional_type v) {
      return mutable_table()->mutable_heap_name()->Set(row_number_, v);
    }
    void set_callsite_id(
        ColumnType::callsite_id::non_optional_type v) {
      return mutable_table()->mutable_callsite_id()->Set(row_number_, v);
    }
    void set_count(
        ColumnType::count::non_optional_type v) {
      return mutable_table()->mutable_count()->Set(row_number_, v);
    }
    void set_size(
        ColumnType::size::non_optional_type v) {
      return mutable_table()->mutable_size()->Set(row_number_, v);
    }

   private:
    HeapProfileAllocationTable* mutable_table() const {
      return const_cast<HeapProfileAllocationTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, HeapProfileAllocationTable, RowNumber, ConstRowReference> {
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
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::heap_name::type heap_name() const {
      const auto& col = table_->heap_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::callsite_id::type callsite_id() const {
      const auto& col = table_->callsite_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::count::type count() const {
      const auto& col = table_->count();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::size::type size() const {
      const auto& col = table_->size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const HeapProfileAllocationTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class HeapProfileAllocationTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_heap_name(ColumnType::heap_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_heap_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_callsite_id(ColumnType::callsite_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_callsite_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_count(ColumnType::count::non_optional_type v) {
        auto* col = mutable_table_->mutable_count();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_size(ColumnType::size::non_optional_type v) {
        auto* col = mutable_table_->mutable_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class HeapProfileAllocationTable;

    explicit Iterator(HeapProfileAllocationTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    HeapProfileAllocationTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit HeapProfileAllocationTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        heap_name_(ColumnStorage<ColumnType::heap_name::stored_type>::Create<false>()),
        callsite_id_(ColumnStorage<ColumnType::callsite_id::stored_type>::Create<false>()),
        count_(ColumnStorage<ColumnType::count::stored_type>::Create<false>()),
        size_(ColumnStorage<ColumnType::size::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::heap_name::stored_type>(
          ColumnFlag::heap_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::callsite_id::stored_type>(
          ColumnFlag::callsite_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::count::stored_type>(
          ColumnFlag::count),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::size::stored_type>(
          ColumnFlag::size),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("heap_name", &heap_name_, ColumnFlag::heap_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("callsite_id", &callsite_id_, ColumnFlag::callsite_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("count", &count_, ColumnFlag::count,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("size", &size_, ColumnFlag::size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~HeapProfileAllocationTable() override;

  static const char* Name() { return "heap_profile_allocation"; }

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
        "upid", ColumnType::upid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "heap_name", ColumnType::heap_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "callsite_id", ColumnType::callsite_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "count", ColumnType::count::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "size", ColumnType::size::SqlValueType(), false,
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
    upid_.ShrinkToFit();
    heap_name_.ShrinkToFit();
    callsite_id_.ShrinkToFit();
    count_.ShrinkToFit();
    size_.ShrinkToFit();
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
    mutable_upid()->Append(std::move(row.upid));
    mutable_heap_name()->Append(std::move(row.heap_name));
    mutable_callsite_id()->Append(std::move(row.callsite_id));
    mutable_count()->Append(std::move(row.count));
    mutable_size()->Append(std::move(row.size));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<HeapProfileAllocationTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<StringPool::Id>& heap_name() const {
    return static_cast<const ColumnType::heap_name&>(columns_[ColumnIndex::heap_name]);
  }
  const TypedColumn<StackProfileCallsiteTable::Id>& callsite_id() const {
    return static_cast<const ColumnType::callsite_id&>(columns_[ColumnIndex::callsite_id]);
  }
  const TypedColumn<int64_t>& count() const {
    return static_cast<const ColumnType::count&>(columns_[ColumnIndex::count]);
  }
  const TypedColumn<int64_t>& size() const {
    return static_cast<const ColumnType::size&>(columns_[ColumnIndex::size]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<StringPool::Id>* mutable_heap_name() {
    return static_cast<ColumnType::heap_name*>(
        &columns_[ColumnIndex::heap_name]);
  }
  TypedColumn<StackProfileCallsiteTable::Id>* mutable_callsite_id() {
    return static_cast<ColumnType::callsite_id*>(
        &columns_[ColumnIndex::callsite_id]);
  }
  TypedColumn<int64_t>* mutable_count() {
    return static_cast<ColumnType::count*>(
        &columns_[ColumnIndex::count]);
  }
  TypedColumn<int64_t>* mutable_size() {
    return static_cast<ColumnType::size*>(
        &columns_[ColumnIndex::size]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::heap_name::stored_type> heap_name_;
  ColumnStorage<ColumnType::callsite_id::stored_type> callsite_id_;
  ColumnStorage<ColumnType::count::stored_type> count_;
  ColumnStorage<ColumnType::size::stored_type> size_;
};
  

class PackageListTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t debuggable = 4;
    static constexpr uint32_t profileable_from_shell = 5;
    static constexpr uint32_t version_code = 6;
  };
  struct ColumnType {
    using id = IdColumn<PackageListTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using package_name = TypedColumn<StringPool::Id>;
    using uid = TypedColumn<int64_t>;
    using debuggable = TypedColumn<int32_t>;
    using profileable_from_shell = TypedColumn<int32_t>;
    using version_code = TypedColumn<int64_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(StringPool::Id in_package_name = {},
        int64_t in_uid = {},
        int32_t in_debuggable = {},
        int32_t in_profileable_from_shell = {},
        int64_t in_version_code = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          package_name(std::move(in_package_name)),
          uid(std::move(in_uid)),
          debuggable(std::move(in_debuggable)),
          profileable_from_shell(std::move(in_profileable_from_shell)),
          version_code(std::move(in_version_code)) {
      type_ = "package_list";
    }
    StringPool::Id package_name;
    int64_t uid;
    int32_t debuggable;
    int32_t profileable_from_shell;
    int64_t version_code;

    bool operator==(const PackageListTable::Row& other) const {
      return type() == other.type() && ColumnType::package_name::Equals(package_name, other.package_name) &&
       ColumnType::uid::Equals(uid, other.uid) &&
       ColumnType::debuggable::Equals(debuggable, other.debuggable) &&
       ColumnType::profileable_from_shell::Equals(profileable_from_shell, other.profileable_from_shell) &&
       ColumnType::version_code::Equals(version_code, other.version_code);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t package_name = ColumnType::package_name::default_flags();
    static constexpr uint32_t uid = ColumnType::uid::default_flags();
    static constexpr uint32_t debuggable = ColumnType::debuggable::default_flags();
    static constexpr uint32_t profileable_from_shell = ColumnType::profileable_from_shell::default_flags();
    static constexpr uint32_t version_code = ColumnType::version_code::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      PackageListTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    PackageListTable, RowNumber> {
   public:
    ConstRowReference(const PackageListTable* table, uint32_t row_number)
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
    ColumnType::debuggable::type debuggable() const {
      return table_->debuggable()[row_number_];
    }
    ColumnType::profileable_from_shell::type profileable_from_shell() const {
      return table_->profileable_from_shell()[row_number_];
    }
    ColumnType::version_code::type version_code() const {
      return table_->version_code()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const PackageListTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_package_name(
        ColumnType::package_name::non_optional_type v) {
      return mutable_table()->mutable_package_name()->Set(row_number_, v);
    }
    void set_uid(
        ColumnType::uid::non_optional_type v) {
      return mutable_table()->mutable_uid()->Set(row_number_, v);
    }
    void set_debuggable(
        ColumnType::debuggable::non_optional_type v) {
      return mutable_table()->mutable_debuggable()->Set(row_number_, v);
    }
    void set_profileable_from_shell(
        ColumnType::profileable_from_shell::non_optional_type v) {
      return mutable_table()->mutable_profileable_from_shell()->Set(row_number_, v);
    }
    void set_version_code(
        ColumnType::version_code::non_optional_type v) {
      return mutable_table()->mutable_version_code()->Set(row_number_, v);
    }

   private:
    PackageListTable* mutable_table() const {
      return const_cast<PackageListTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, PackageListTable, RowNumber, ConstRowReference> {
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
    ColumnType::debuggable::type debuggable() const {
      const auto& col = table_->debuggable();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::profileable_from_shell::type profileable_from_shell() const {
      const auto& col = table_->profileable_from_shell();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::version_code::type version_code() const {
      const auto& col = table_->version_code();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const PackageListTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class PackageListTable;
    friend class AbstractConstIterator;
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
      void set_debuggable(ColumnType::debuggable::non_optional_type v) {
        auto* col = mutable_table_->mutable_debuggable();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_profileable_from_shell(ColumnType::profileable_from_shell::non_optional_type v) {
        auto* col = mutable_table_->mutable_profileable_from_shell();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_version_code(ColumnType::version_code::non_optional_type v) {
        auto* col = mutable_table_->mutable_version_code();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class PackageListTable;

    explicit Iterator(PackageListTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    PackageListTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit PackageListTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        package_name_(ColumnStorage<ColumnType::package_name::stored_type>::Create<false>()),
        uid_(ColumnStorage<ColumnType::uid::stored_type>::Create<false>()),
        debuggable_(ColumnStorage<ColumnType::debuggable::stored_type>::Create<false>()),
        profileable_from_shell_(ColumnStorage<ColumnType::profileable_from_shell::stored_type>::Create<false>()),
        version_code_(ColumnStorage<ColumnType::version_code::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::package_name::stored_type>(
          ColumnFlag::package_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::uid::stored_type>(
          ColumnFlag::uid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::debuggable::stored_type>(
          ColumnFlag::debuggable),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::profileable_from_shell::stored_type>(
          ColumnFlag::profileable_from_shell),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::version_code::stored_type>(
          ColumnFlag::version_code),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("package_name", &package_name_, ColumnFlag::package_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("uid", &uid_, ColumnFlag::uid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("debuggable", &debuggable_, ColumnFlag::debuggable,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("profileable_from_shell", &profileable_from_shell_, ColumnFlag::profileable_from_shell,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("version_code", &version_code_, ColumnFlag::version_code,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~PackageListTable() override;

  static const char* Name() { return "package_list"; }

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
        "debuggable", ColumnType::debuggable::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "profileable_from_shell", ColumnType::profileable_from_shell::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "version_code", ColumnType::version_code::SqlValueType(), false,
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
    debuggable_.ShrinkToFit();
    profileable_from_shell_.ShrinkToFit();
    version_code_.ShrinkToFit();
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
    mutable_debuggable()->Append(std::move(row.debuggable));
    mutable_profileable_from_shell()->Append(std::move(row.profileable_from_shell));
    mutable_version_code()->Append(std::move(row.version_code));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<PackageListTable::Id>& id() const {
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
  const TypedColumn<int32_t>& debuggable() const {
    return static_cast<const ColumnType::debuggable&>(columns_[ColumnIndex::debuggable]);
  }
  const TypedColumn<int32_t>& profileable_from_shell() const {
    return static_cast<const ColumnType::profileable_from_shell&>(columns_[ColumnIndex::profileable_from_shell]);
  }
  const TypedColumn<int64_t>& version_code() const {
    return static_cast<const ColumnType::version_code&>(columns_[ColumnIndex::version_code]);
  }

  TypedColumn<StringPool::Id>* mutable_package_name() {
    return static_cast<ColumnType::package_name*>(
        &columns_[ColumnIndex::package_name]);
  }
  TypedColumn<int64_t>* mutable_uid() {
    return static_cast<ColumnType::uid*>(
        &columns_[ColumnIndex::uid]);
  }
  TypedColumn<int32_t>* mutable_debuggable() {
    return static_cast<ColumnType::debuggable*>(
        &columns_[ColumnIndex::debuggable]);
  }
  TypedColumn<int32_t>* mutable_profileable_from_shell() {
    return static_cast<ColumnType::profileable_from_shell*>(
        &columns_[ColumnIndex::profileable_from_shell]);
  }
  TypedColumn<int64_t>* mutable_version_code() {
    return static_cast<ColumnType::version_code*>(
        &columns_[ColumnIndex::version_code]);
  }

 private:
  
  
  ColumnStorage<ColumnType::package_name::stored_type> package_name_;
  ColumnStorage<ColumnType::uid::stored_type> uid_;
  ColumnStorage<ColumnType::debuggable::stored_type> debuggable_;
  ColumnStorage<ColumnType::profileable_from_shell::stored_type> profileable_from_shell_;
  ColumnStorage<ColumnType::version_code::stored_type> version_code_;
};
  

class PerfSampleTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t cpu = 4;
    static constexpr uint32_t cpu_mode = 5;
    static constexpr uint32_t callsite_id = 6;
    static constexpr uint32_t unwind_error = 7;
    static constexpr uint32_t perf_session_id = 8;
  };
  struct ColumnType {
    using id = IdColumn<PerfSampleTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using ts = TypedColumn<int64_t>;
    using utid = TypedColumn<uint32_t>;
    using cpu = TypedColumn<uint32_t>;
    using cpu_mode = TypedColumn<StringPool::Id>;
    using callsite_id = TypedColumn<std::optional<StackProfileCallsiteTable::Id>>;
    using unwind_error = TypedColumn<std::optional<StringPool::Id>>;
    using perf_session_id = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(int64_t in_ts = {},
        uint32_t in_utid = {},
        uint32_t in_cpu = {},
        StringPool::Id in_cpu_mode = {},
        std::optional<StackProfileCallsiteTable::Id> in_callsite_id = {},
        std::optional<StringPool::Id> in_unwind_error = {},
        uint32_t in_perf_session_id = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          ts(std::move(in_ts)),
          utid(std::move(in_utid)),
          cpu(std::move(in_cpu)),
          cpu_mode(std::move(in_cpu_mode)),
          callsite_id(std::move(in_callsite_id)),
          unwind_error(std::move(in_unwind_error)),
          perf_session_id(std::move(in_perf_session_id)) {
      type_ = "perf_sample";
    }
    int64_t ts;
    uint32_t utid;
    uint32_t cpu;
    StringPool::Id cpu_mode;
    std::optional<StackProfileCallsiteTable::Id> callsite_id;
    std::optional<StringPool::Id> unwind_error;
    uint32_t perf_session_id;

    bool operator==(const PerfSampleTable::Row& other) const {
      return type() == other.type() && ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::utid::Equals(utid, other.utid) &&
       ColumnType::cpu::Equals(cpu, other.cpu) &&
       ColumnType::cpu_mode::Equals(cpu_mode, other.cpu_mode) &&
       ColumnType::callsite_id::Equals(callsite_id, other.callsite_id) &&
       ColumnType::unwind_error::Equals(unwind_error, other.unwind_error) &&
       ColumnType::perf_session_id::Equals(perf_session_id, other.perf_session_id);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t ts = static_cast<uint32_t>(Column::Flag::kSorted) | ColumnType::ts::default_flags();
    static constexpr uint32_t utid = ColumnType::utid::default_flags();
    static constexpr uint32_t cpu = ColumnType::cpu::default_flags();
    static constexpr uint32_t cpu_mode = ColumnType::cpu_mode::default_flags();
    static constexpr uint32_t callsite_id = ColumnType::callsite_id::default_flags();
    static constexpr uint32_t unwind_error = ColumnType::unwind_error::default_flags();
    static constexpr uint32_t perf_session_id = ColumnType::perf_session_id::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      PerfSampleTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    PerfSampleTable, RowNumber> {
   public:
    ConstRowReference(const PerfSampleTable* table, uint32_t row_number)
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
    ColumnType::cpu::type cpu() const {
      return table_->cpu()[row_number_];
    }
    ColumnType::cpu_mode::type cpu_mode() const {
      return table_->cpu_mode()[row_number_];
    }
    ColumnType::callsite_id::type callsite_id() const {
      return table_->callsite_id()[row_number_];
    }
    ColumnType::unwind_error::type unwind_error() const {
      return table_->unwind_error()[row_number_];
    }
    ColumnType::perf_session_id::type perf_session_id() const {
      return table_->perf_session_id()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const PerfSampleTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_utid(
        ColumnType::utid::non_optional_type v) {
      return mutable_table()->mutable_utid()->Set(row_number_, v);
    }
    void set_cpu(
        ColumnType::cpu::non_optional_type v) {
      return mutable_table()->mutable_cpu()->Set(row_number_, v);
    }
    void set_cpu_mode(
        ColumnType::cpu_mode::non_optional_type v) {
      return mutable_table()->mutable_cpu_mode()->Set(row_number_, v);
    }
    void set_callsite_id(
        ColumnType::callsite_id::non_optional_type v) {
      return mutable_table()->mutable_callsite_id()->Set(row_number_, v);
    }
    void set_unwind_error(
        ColumnType::unwind_error::non_optional_type v) {
      return mutable_table()->mutable_unwind_error()->Set(row_number_, v);
    }
    void set_perf_session_id(
        ColumnType::perf_session_id::non_optional_type v) {
      return mutable_table()->mutable_perf_session_id()->Set(row_number_, v);
    }

   private:
    PerfSampleTable* mutable_table() const {
      return const_cast<PerfSampleTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, PerfSampleTable, RowNumber, ConstRowReference> {
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
    ColumnType::cpu::type cpu() const {
      const auto& col = table_->cpu();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::cpu_mode::type cpu_mode() const {
      const auto& col = table_->cpu_mode();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::callsite_id::type callsite_id() const {
      const auto& col = table_->callsite_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::unwind_error::type unwind_error() const {
      const auto& col = table_->unwind_error();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::perf_session_id::type perf_session_id() const {
      const auto& col = table_->perf_session_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const PerfSampleTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class PerfSampleTable;
    friend class AbstractConstIterator;
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
      void set_cpu(ColumnType::cpu::non_optional_type v) {
        auto* col = mutable_table_->mutable_cpu();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_cpu_mode(ColumnType::cpu_mode::non_optional_type v) {
        auto* col = mutable_table_->mutable_cpu_mode();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_callsite_id(ColumnType::callsite_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_callsite_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_unwind_error(ColumnType::unwind_error::non_optional_type v) {
        auto* col = mutable_table_->mutable_unwind_error();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_perf_session_id(ColumnType::perf_session_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_perf_session_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class PerfSampleTable;

    explicit Iterator(PerfSampleTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    PerfSampleTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit PerfSampleTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        utid_(ColumnStorage<ColumnType::utid::stored_type>::Create<false>()),
        cpu_(ColumnStorage<ColumnType::cpu::stored_type>::Create<false>()),
        cpu_mode_(ColumnStorage<ColumnType::cpu_mode::stored_type>::Create<false>()),
        callsite_id_(ColumnStorage<ColumnType::callsite_id::stored_type>::Create<false>()),
        unwind_error_(ColumnStorage<ColumnType::unwind_error::stored_type>::Create<false>()),
        perf_session_id_(ColumnStorage<ColumnType::perf_session_id::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::utid::stored_type>(
          ColumnFlag::utid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu::stored_type>(
          ColumnFlag::cpu),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::cpu_mode::stored_type>(
          ColumnFlag::cpu_mode),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::callsite_id::stored_type>(
          ColumnFlag::callsite_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::unwind_error::stored_type>(
          ColumnFlag::unwind_error),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::perf_session_id::stored_type>(
          ColumnFlag::perf_session_id),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("utid", &utid_, ColumnFlag::utid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cpu", &cpu_, ColumnFlag::cpu,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("cpu_mode", &cpu_mode_, ColumnFlag::cpu_mode,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("callsite_id", &callsite_id_, ColumnFlag::callsite_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("unwind_error", &unwind_error_, ColumnFlag::unwind_error,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("perf_session_id", &perf_session_id_, ColumnFlag::perf_session_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~PerfSampleTable() override;

  static const char* Name() { return "perf_sample"; }

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
        "utid", ColumnType::utid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cpu", ColumnType::cpu::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "cpu_mode", ColumnType::cpu_mode::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "callsite_id", ColumnType::callsite_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "unwind_error", ColumnType::unwind_error::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "perf_session_id", ColumnType::perf_session_id::SqlValueType(), false,
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
    cpu_.ShrinkToFit();
    cpu_mode_.ShrinkToFit();
    callsite_id_.ShrinkToFit();
    unwind_error_.ShrinkToFit();
    perf_session_id_.ShrinkToFit();
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
    mutable_cpu()->Append(std::move(row.cpu));
    mutable_cpu_mode()->Append(std::move(row.cpu_mode));
    mutable_callsite_id()->Append(std::move(row.callsite_id));
    mutable_unwind_error()->Append(std::move(row.unwind_error));
    mutable_perf_session_id()->Append(std::move(row.perf_session_id));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<PerfSampleTable::Id>& id() const {
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
  const TypedColumn<uint32_t>& cpu() const {
    return static_cast<const ColumnType::cpu&>(columns_[ColumnIndex::cpu]);
  }
  const TypedColumn<StringPool::Id>& cpu_mode() const {
    return static_cast<const ColumnType::cpu_mode&>(columns_[ColumnIndex::cpu_mode]);
  }
  const TypedColumn<std::optional<StackProfileCallsiteTable::Id>>& callsite_id() const {
    return static_cast<const ColumnType::callsite_id&>(columns_[ColumnIndex::callsite_id]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& unwind_error() const {
    return static_cast<const ColumnType::unwind_error&>(columns_[ColumnIndex::unwind_error]);
  }
  const TypedColumn<uint32_t>& perf_session_id() const {
    return static_cast<const ColumnType::perf_session_id&>(columns_[ColumnIndex::perf_session_id]);
  }

  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<uint32_t>* mutable_utid() {
    return static_cast<ColumnType::utid*>(
        &columns_[ColumnIndex::utid]);
  }
  TypedColumn<uint32_t>* mutable_cpu() {
    return static_cast<ColumnType::cpu*>(
        &columns_[ColumnIndex::cpu]);
  }
  TypedColumn<StringPool::Id>* mutable_cpu_mode() {
    return static_cast<ColumnType::cpu_mode*>(
        &columns_[ColumnIndex::cpu_mode]);
  }
  TypedColumn<std::optional<StackProfileCallsiteTable::Id>>* mutable_callsite_id() {
    return static_cast<ColumnType::callsite_id*>(
        &columns_[ColumnIndex::callsite_id]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_unwind_error() {
    return static_cast<ColumnType::unwind_error*>(
        &columns_[ColumnIndex::unwind_error]);
  }
  TypedColumn<uint32_t>* mutable_perf_session_id() {
    return static_cast<ColumnType::perf_session_id*>(
        &columns_[ColumnIndex::perf_session_id]);
  }

 private:
  
  
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::utid::stored_type> utid_;
  ColumnStorage<ColumnType::cpu::stored_type> cpu_;
  ColumnStorage<ColumnType::cpu_mode::stored_type> cpu_mode_;
  ColumnStorage<ColumnType::callsite_id::stored_type> callsite_id_;
  ColumnStorage<ColumnType::unwind_error::stored_type> unwind_error_;
  ColumnStorage<ColumnType::perf_session_id::stored_type> perf_session_id_;
};
  

class ProfilerSmapsTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t ts = 3;
    static constexpr uint32_t path = 4;
    static constexpr uint32_t size_kb = 5;
    static constexpr uint32_t private_dirty_kb = 6;
    static constexpr uint32_t swap_kb = 7;
    static constexpr uint32_t file_name = 8;
    static constexpr uint32_t start_address = 9;
    static constexpr uint32_t module_timestamp = 10;
    static constexpr uint32_t module_debugid = 11;
    static constexpr uint32_t module_debug_path = 12;
    static constexpr uint32_t protection_flags = 13;
    static constexpr uint32_t private_clean_resident_kb = 14;
    static constexpr uint32_t shared_dirty_resident_kb = 15;
    static constexpr uint32_t shared_clean_resident_kb = 16;
    static constexpr uint32_t locked_kb = 17;
    static constexpr uint32_t proportional_resident_kb = 18;
  };
  struct ColumnType {
    using id = IdColumn<ProfilerSmapsTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using upid = TypedColumn<uint32_t>;
    using ts = TypedColumn<int64_t>;
    using path = TypedColumn<StringPool::Id>;
    using size_kb = TypedColumn<int64_t>;
    using private_dirty_kb = TypedColumn<int64_t>;
    using swap_kb = TypedColumn<int64_t>;
    using file_name = TypedColumn<StringPool::Id>;
    using start_address = TypedColumn<int64_t>;
    using module_timestamp = TypedColumn<int64_t>;
    using module_debugid = TypedColumn<StringPool::Id>;
    using module_debug_path = TypedColumn<StringPool::Id>;
    using protection_flags = TypedColumn<int64_t>;
    using private_clean_resident_kb = TypedColumn<int64_t>;
    using shared_dirty_resident_kb = TypedColumn<int64_t>;
    using shared_clean_resident_kb = TypedColumn<int64_t>;
    using locked_kb = TypedColumn<int64_t>;
    using proportional_resident_kb = TypedColumn<int64_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_upid = {},
        int64_t in_ts = {},
        StringPool::Id in_path = {},
        int64_t in_size_kb = {},
        int64_t in_private_dirty_kb = {},
        int64_t in_swap_kb = {},
        StringPool::Id in_file_name = {},
        int64_t in_start_address = {},
        int64_t in_module_timestamp = {},
        StringPool::Id in_module_debugid = {},
        StringPool::Id in_module_debug_path = {},
        int64_t in_protection_flags = {},
        int64_t in_private_clean_resident_kb = {},
        int64_t in_shared_dirty_resident_kb = {},
        int64_t in_shared_clean_resident_kb = {},
        int64_t in_locked_kb = {},
        int64_t in_proportional_resident_kb = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          upid(std::move(in_upid)),
          ts(std::move(in_ts)),
          path(std::move(in_path)),
          size_kb(std::move(in_size_kb)),
          private_dirty_kb(std::move(in_private_dirty_kb)),
          swap_kb(std::move(in_swap_kb)),
          file_name(std::move(in_file_name)),
          start_address(std::move(in_start_address)),
          module_timestamp(std::move(in_module_timestamp)),
          module_debugid(std::move(in_module_debugid)),
          module_debug_path(std::move(in_module_debug_path)),
          protection_flags(std::move(in_protection_flags)),
          private_clean_resident_kb(std::move(in_private_clean_resident_kb)),
          shared_dirty_resident_kb(std::move(in_shared_dirty_resident_kb)),
          shared_clean_resident_kb(std::move(in_shared_clean_resident_kb)),
          locked_kb(std::move(in_locked_kb)),
          proportional_resident_kb(std::move(in_proportional_resident_kb)) {
      type_ = "profiler_smaps";
    }
    uint32_t upid;
    int64_t ts;
    StringPool::Id path;
    int64_t size_kb;
    int64_t private_dirty_kb;
    int64_t swap_kb;
    StringPool::Id file_name;
    int64_t start_address;
    int64_t module_timestamp;
    StringPool::Id module_debugid;
    StringPool::Id module_debug_path;
    int64_t protection_flags;
    int64_t private_clean_resident_kb;
    int64_t shared_dirty_resident_kb;
    int64_t shared_clean_resident_kb;
    int64_t locked_kb;
    int64_t proportional_resident_kb;

    bool operator==(const ProfilerSmapsTable::Row& other) const {
      return type() == other.type() && ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::ts::Equals(ts, other.ts) &&
       ColumnType::path::Equals(path, other.path) &&
       ColumnType::size_kb::Equals(size_kb, other.size_kb) &&
       ColumnType::private_dirty_kb::Equals(private_dirty_kb, other.private_dirty_kb) &&
       ColumnType::swap_kb::Equals(swap_kb, other.swap_kb) &&
       ColumnType::file_name::Equals(file_name, other.file_name) &&
       ColumnType::start_address::Equals(start_address, other.start_address) &&
       ColumnType::module_timestamp::Equals(module_timestamp, other.module_timestamp) &&
       ColumnType::module_debugid::Equals(module_debugid, other.module_debugid) &&
       ColumnType::module_debug_path::Equals(module_debug_path, other.module_debug_path) &&
       ColumnType::protection_flags::Equals(protection_flags, other.protection_flags) &&
       ColumnType::private_clean_resident_kb::Equals(private_clean_resident_kb, other.private_clean_resident_kb) &&
       ColumnType::shared_dirty_resident_kb::Equals(shared_dirty_resident_kb, other.shared_dirty_resident_kb) &&
       ColumnType::shared_clean_resident_kb::Equals(shared_clean_resident_kb, other.shared_clean_resident_kb) &&
       ColumnType::locked_kb::Equals(locked_kb, other.locked_kb) &&
       ColumnType::proportional_resident_kb::Equals(proportional_resident_kb, other.proportional_resident_kb);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
    static constexpr uint32_t ts = ColumnType::ts::default_flags();
    static constexpr uint32_t path = ColumnType::path::default_flags();
    static constexpr uint32_t size_kb = ColumnType::size_kb::default_flags();
    static constexpr uint32_t private_dirty_kb = ColumnType::private_dirty_kb::default_flags();
    static constexpr uint32_t swap_kb = ColumnType::swap_kb::default_flags();
    static constexpr uint32_t file_name = ColumnType::file_name::default_flags();
    static constexpr uint32_t start_address = ColumnType::start_address::default_flags();
    static constexpr uint32_t module_timestamp = ColumnType::module_timestamp::default_flags();
    static constexpr uint32_t module_debugid = ColumnType::module_debugid::default_flags();
    static constexpr uint32_t module_debug_path = ColumnType::module_debug_path::default_flags();
    static constexpr uint32_t protection_flags = ColumnType::protection_flags::default_flags();
    static constexpr uint32_t private_clean_resident_kb = ColumnType::private_clean_resident_kb::default_flags();
    static constexpr uint32_t shared_dirty_resident_kb = ColumnType::shared_dirty_resident_kb::default_flags();
    static constexpr uint32_t shared_clean_resident_kb = ColumnType::shared_clean_resident_kb::default_flags();
    static constexpr uint32_t locked_kb = ColumnType::locked_kb::default_flags();
    static constexpr uint32_t proportional_resident_kb = ColumnType::proportional_resident_kb::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      ProfilerSmapsTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    ProfilerSmapsTable, RowNumber> {
   public:
    ConstRowReference(const ProfilerSmapsTable* table, uint32_t row_number)
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
    ColumnType::ts::type ts() const {
      return table_->ts()[row_number_];
    }
    ColumnType::path::type path() const {
      return table_->path()[row_number_];
    }
    ColumnType::size_kb::type size_kb() const {
      return table_->size_kb()[row_number_];
    }
    ColumnType::private_dirty_kb::type private_dirty_kb() const {
      return table_->private_dirty_kb()[row_number_];
    }
    ColumnType::swap_kb::type swap_kb() const {
      return table_->swap_kb()[row_number_];
    }
    ColumnType::file_name::type file_name() const {
      return table_->file_name()[row_number_];
    }
    ColumnType::start_address::type start_address() const {
      return table_->start_address()[row_number_];
    }
    ColumnType::module_timestamp::type module_timestamp() const {
      return table_->module_timestamp()[row_number_];
    }
    ColumnType::module_debugid::type module_debugid() const {
      return table_->module_debugid()[row_number_];
    }
    ColumnType::module_debug_path::type module_debug_path() const {
      return table_->module_debug_path()[row_number_];
    }
    ColumnType::protection_flags::type protection_flags() const {
      return table_->protection_flags()[row_number_];
    }
    ColumnType::private_clean_resident_kb::type private_clean_resident_kb() const {
      return table_->private_clean_resident_kb()[row_number_];
    }
    ColumnType::shared_dirty_resident_kb::type shared_dirty_resident_kb() const {
      return table_->shared_dirty_resident_kb()[row_number_];
    }
    ColumnType::shared_clean_resident_kb::type shared_clean_resident_kb() const {
      return table_->shared_clean_resident_kb()[row_number_];
    }
    ColumnType::locked_kb::type locked_kb() const {
      return table_->locked_kb()[row_number_];
    }
    ColumnType::proportional_resident_kb::type proportional_resident_kb() const {
      return table_->proportional_resident_kb()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const ProfilerSmapsTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_ts(
        ColumnType::ts::non_optional_type v) {
      return mutable_table()->mutable_ts()->Set(row_number_, v);
    }
    void set_path(
        ColumnType::path::non_optional_type v) {
      return mutable_table()->mutable_path()->Set(row_number_, v);
    }
    void set_size_kb(
        ColumnType::size_kb::non_optional_type v) {
      return mutable_table()->mutable_size_kb()->Set(row_number_, v);
    }
    void set_private_dirty_kb(
        ColumnType::private_dirty_kb::non_optional_type v) {
      return mutable_table()->mutable_private_dirty_kb()->Set(row_number_, v);
    }
    void set_swap_kb(
        ColumnType::swap_kb::non_optional_type v) {
      return mutable_table()->mutable_swap_kb()->Set(row_number_, v);
    }
    void set_file_name(
        ColumnType::file_name::non_optional_type v) {
      return mutable_table()->mutable_file_name()->Set(row_number_, v);
    }
    void set_start_address(
        ColumnType::start_address::non_optional_type v) {
      return mutable_table()->mutable_start_address()->Set(row_number_, v);
    }
    void set_module_timestamp(
        ColumnType::module_timestamp::non_optional_type v) {
      return mutable_table()->mutable_module_timestamp()->Set(row_number_, v);
    }
    void set_module_debugid(
        ColumnType::module_debugid::non_optional_type v) {
      return mutable_table()->mutable_module_debugid()->Set(row_number_, v);
    }
    void set_module_debug_path(
        ColumnType::module_debug_path::non_optional_type v) {
      return mutable_table()->mutable_module_debug_path()->Set(row_number_, v);
    }
    void set_protection_flags(
        ColumnType::protection_flags::non_optional_type v) {
      return mutable_table()->mutable_protection_flags()->Set(row_number_, v);
    }
    void set_private_clean_resident_kb(
        ColumnType::private_clean_resident_kb::non_optional_type v) {
      return mutable_table()->mutable_private_clean_resident_kb()->Set(row_number_, v);
    }
    void set_shared_dirty_resident_kb(
        ColumnType::shared_dirty_resident_kb::non_optional_type v) {
      return mutable_table()->mutable_shared_dirty_resident_kb()->Set(row_number_, v);
    }
    void set_shared_clean_resident_kb(
        ColumnType::shared_clean_resident_kb::non_optional_type v) {
      return mutable_table()->mutable_shared_clean_resident_kb()->Set(row_number_, v);
    }
    void set_locked_kb(
        ColumnType::locked_kb::non_optional_type v) {
      return mutable_table()->mutable_locked_kb()->Set(row_number_, v);
    }
    void set_proportional_resident_kb(
        ColumnType::proportional_resident_kb::non_optional_type v) {
      return mutable_table()->mutable_proportional_resident_kb()->Set(row_number_, v);
    }

   private:
    ProfilerSmapsTable* mutable_table() const {
      return const_cast<ProfilerSmapsTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, ProfilerSmapsTable, RowNumber, ConstRowReference> {
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
    ColumnType::ts::type ts() const {
      const auto& col = table_->ts();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::path::type path() const {
      const auto& col = table_->path();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::size_kb::type size_kb() const {
      const auto& col = table_->size_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::private_dirty_kb::type private_dirty_kb() const {
      const auto& col = table_->private_dirty_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::swap_kb::type swap_kb() const {
      const auto& col = table_->swap_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::file_name::type file_name() const {
      const auto& col = table_->file_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::start_address::type start_address() const {
      const auto& col = table_->start_address();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::module_timestamp::type module_timestamp() const {
      const auto& col = table_->module_timestamp();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::module_debugid::type module_debugid() const {
      const auto& col = table_->module_debugid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::module_debug_path::type module_debug_path() const {
      const auto& col = table_->module_debug_path();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::protection_flags::type protection_flags() const {
      const auto& col = table_->protection_flags();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::private_clean_resident_kb::type private_clean_resident_kb() const {
      const auto& col = table_->private_clean_resident_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::shared_dirty_resident_kb::type shared_dirty_resident_kb() const {
      const auto& col = table_->shared_dirty_resident_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::shared_clean_resident_kb::type shared_clean_resident_kb() const {
      const auto& col = table_->shared_clean_resident_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::locked_kb::type locked_kb() const {
      const auto& col = table_->locked_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::proportional_resident_kb::type proportional_resident_kb() const {
      const auto& col = table_->proportional_resident_kb();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const ProfilerSmapsTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class ProfilerSmapsTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_ts(ColumnType::ts::non_optional_type v) {
        auto* col = mutable_table_->mutable_ts();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_path(ColumnType::path::non_optional_type v) {
        auto* col = mutable_table_->mutable_path();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_size_kb(ColumnType::size_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_size_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_private_dirty_kb(ColumnType::private_dirty_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_private_dirty_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_swap_kb(ColumnType::swap_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_swap_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_file_name(ColumnType::file_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_file_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_start_address(ColumnType::start_address::non_optional_type v) {
        auto* col = mutable_table_->mutable_start_address();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_module_timestamp(ColumnType::module_timestamp::non_optional_type v) {
        auto* col = mutable_table_->mutable_module_timestamp();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_module_debugid(ColumnType::module_debugid::non_optional_type v) {
        auto* col = mutable_table_->mutable_module_debugid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_module_debug_path(ColumnType::module_debug_path::non_optional_type v) {
        auto* col = mutable_table_->mutable_module_debug_path();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_protection_flags(ColumnType::protection_flags::non_optional_type v) {
        auto* col = mutable_table_->mutable_protection_flags();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_private_clean_resident_kb(ColumnType::private_clean_resident_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_private_clean_resident_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_shared_dirty_resident_kb(ColumnType::shared_dirty_resident_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_shared_dirty_resident_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_shared_clean_resident_kb(ColumnType::shared_clean_resident_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_shared_clean_resident_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_locked_kb(ColumnType::locked_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_locked_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_proportional_resident_kb(ColumnType::proportional_resident_kb::non_optional_type v) {
        auto* col = mutable_table_->mutable_proportional_resident_kb();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class ProfilerSmapsTable;

    explicit Iterator(ProfilerSmapsTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    ProfilerSmapsTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit ProfilerSmapsTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        ts_(ColumnStorage<ColumnType::ts::stored_type>::Create<false>()),
        path_(ColumnStorage<ColumnType::path::stored_type>::Create<false>()),
        size_kb_(ColumnStorage<ColumnType::size_kb::stored_type>::Create<false>()),
        private_dirty_kb_(ColumnStorage<ColumnType::private_dirty_kb::stored_type>::Create<false>()),
        swap_kb_(ColumnStorage<ColumnType::swap_kb::stored_type>::Create<false>()),
        file_name_(ColumnStorage<ColumnType::file_name::stored_type>::Create<false>()),
        start_address_(ColumnStorage<ColumnType::start_address::stored_type>::Create<false>()),
        module_timestamp_(ColumnStorage<ColumnType::module_timestamp::stored_type>::Create<false>()),
        module_debugid_(ColumnStorage<ColumnType::module_debugid::stored_type>::Create<false>()),
        module_debug_path_(ColumnStorage<ColumnType::module_debug_path::stored_type>::Create<false>()),
        protection_flags_(ColumnStorage<ColumnType::protection_flags::stored_type>::Create<false>()),
        private_clean_resident_kb_(ColumnStorage<ColumnType::private_clean_resident_kb::stored_type>::Create<false>()),
        shared_dirty_resident_kb_(ColumnStorage<ColumnType::shared_dirty_resident_kb::stored_type>::Create<false>()),
        shared_clean_resident_kb_(ColumnStorage<ColumnType::shared_clean_resident_kb::stored_type>::Create<false>()),
        locked_kb_(ColumnStorage<ColumnType::locked_kb::stored_type>::Create<false>()),
        proportional_resident_kb_(ColumnStorage<ColumnType::proportional_resident_kb::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::ts::stored_type>(
          ColumnFlag::ts),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::path::stored_type>(
          ColumnFlag::path),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::size_kb::stored_type>(
          ColumnFlag::size_kb),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::private_dirty_kb::stored_type>(
          ColumnFlag::private_dirty_kb),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::swap_kb::stored_type>(
          ColumnFlag::swap_kb),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::file_name::stored_type>(
          ColumnFlag::file_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::start_address::stored_type>(
          ColumnFlag::start_address),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::module_timestamp::stored_type>(
          ColumnFlag::module_timestamp),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::module_debugid::stored_type>(
          ColumnFlag::module_debugid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::module_debug_path::stored_type>(
          ColumnFlag::module_debug_path),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::protection_flags::stored_type>(
          ColumnFlag::protection_flags),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::private_clean_resident_kb::stored_type>(
          ColumnFlag::private_clean_resident_kb),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::shared_dirty_resident_kb::stored_type>(
          ColumnFlag::shared_dirty_resident_kb),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::shared_clean_resident_kb::stored_type>(
          ColumnFlag::shared_clean_resident_kb),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::locked_kb::stored_type>(
          ColumnFlag::locked_kb),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::proportional_resident_kb::stored_type>(
          ColumnFlag::proportional_resident_kb),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("ts", &ts_, ColumnFlag::ts,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("path", &path_, ColumnFlag::path,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("size_kb", &size_kb_, ColumnFlag::size_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("private_dirty_kb", &private_dirty_kb_, ColumnFlag::private_dirty_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("swap_kb", &swap_kb_, ColumnFlag::swap_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("file_name", &file_name_, ColumnFlag::file_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("start_address", &start_address_, ColumnFlag::start_address,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("module_timestamp", &module_timestamp_, ColumnFlag::module_timestamp,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("module_debugid", &module_debugid_, ColumnFlag::module_debugid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("module_debug_path", &module_debug_path_, ColumnFlag::module_debug_path,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("protection_flags", &protection_flags_, ColumnFlag::protection_flags,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("private_clean_resident_kb", &private_clean_resident_kb_, ColumnFlag::private_clean_resident_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("shared_dirty_resident_kb", &shared_dirty_resident_kb_, ColumnFlag::shared_dirty_resident_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("shared_clean_resident_kb", &shared_clean_resident_kb_, ColumnFlag::shared_clean_resident_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("locked_kb", &locked_kb_, ColumnFlag::locked_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("proportional_resident_kb", &proportional_resident_kb_, ColumnFlag::proportional_resident_kb,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~ProfilerSmapsTable() override;

  static const char* Name() { return "profiler_smaps"; }

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
        "ts", ColumnType::ts::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "path", ColumnType::path::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "size_kb", ColumnType::size_kb::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "private_dirty_kb", ColumnType::private_dirty_kb::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "swap_kb", ColumnType::swap_kb::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "file_name", ColumnType::file_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "start_address", ColumnType::start_address::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "module_timestamp", ColumnType::module_timestamp::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "module_debugid", ColumnType::module_debugid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "module_debug_path", ColumnType::module_debug_path::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "protection_flags", ColumnType::protection_flags::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "private_clean_resident_kb", ColumnType::private_clean_resident_kb::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "shared_dirty_resident_kb", ColumnType::shared_dirty_resident_kb::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "shared_clean_resident_kb", ColumnType::shared_clean_resident_kb::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "locked_kb", ColumnType::locked_kb::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "proportional_resident_kb", ColumnType::proportional_resident_kb::SqlValueType(), false,
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
    ts_.ShrinkToFit();
    path_.ShrinkToFit();
    size_kb_.ShrinkToFit();
    private_dirty_kb_.ShrinkToFit();
    swap_kb_.ShrinkToFit();
    file_name_.ShrinkToFit();
    start_address_.ShrinkToFit();
    module_timestamp_.ShrinkToFit();
    module_debugid_.ShrinkToFit();
    module_debug_path_.ShrinkToFit();
    protection_flags_.ShrinkToFit();
    private_clean_resident_kb_.ShrinkToFit();
    shared_dirty_resident_kb_.ShrinkToFit();
    shared_clean_resident_kb_.ShrinkToFit();
    locked_kb_.ShrinkToFit();
    proportional_resident_kb_.ShrinkToFit();
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
    mutable_ts()->Append(std::move(row.ts));
    mutable_path()->Append(std::move(row.path));
    mutable_size_kb()->Append(std::move(row.size_kb));
    mutable_private_dirty_kb()->Append(std::move(row.private_dirty_kb));
    mutable_swap_kb()->Append(std::move(row.swap_kb));
    mutable_file_name()->Append(std::move(row.file_name));
    mutable_start_address()->Append(std::move(row.start_address));
    mutable_module_timestamp()->Append(std::move(row.module_timestamp));
    mutable_module_debugid()->Append(std::move(row.module_debugid));
    mutable_module_debug_path()->Append(std::move(row.module_debug_path));
    mutable_protection_flags()->Append(std::move(row.protection_flags));
    mutable_private_clean_resident_kb()->Append(std::move(row.private_clean_resident_kb));
    mutable_shared_dirty_resident_kb()->Append(std::move(row.shared_dirty_resident_kb));
    mutable_shared_clean_resident_kb()->Append(std::move(row.shared_clean_resident_kb));
    mutable_locked_kb()->Append(std::move(row.locked_kb));
    mutable_proportional_resident_kb()->Append(std::move(row.proportional_resident_kb));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<ProfilerSmapsTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<int64_t>& ts() const {
    return static_cast<const ColumnType::ts&>(columns_[ColumnIndex::ts]);
  }
  const TypedColumn<StringPool::Id>& path() const {
    return static_cast<const ColumnType::path&>(columns_[ColumnIndex::path]);
  }
  const TypedColumn<int64_t>& size_kb() const {
    return static_cast<const ColumnType::size_kb&>(columns_[ColumnIndex::size_kb]);
  }
  const TypedColumn<int64_t>& private_dirty_kb() const {
    return static_cast<const ColumnType::private_dirty_kb&>(columns_[ColumnIndex::private_dirty_kb]);
  }
  const TypedColumn<int64_t>& swap_kb() const {
    return static_cast<const ColumnType::swap_kb&>(columns_[ColumnIndex::swap_kb]);
  }
  const TypedColumn<StringPool::Id>& file_name() const {
    return static_cast<const ColumnType::file_name&>(columns_[ColumnIndex::file_name]);
  }
  const TypedColumn<int64_t>& start_address() const {
    return static_cast<const ColumnType::start_address&>(columns_[ColumnIndex::start_address]);
  }
  const TypedColumn<int64_t>& module_timestamp() const {
    return static_cast<const ColumnType::module_timestamp&>(columns_[ColumnIndex::module_timestamp]);
  }
  const TypedColumn<StringPool::Id>& module_debugid() const {
    return static_cast<const ColumnType::module_debugid&>(columns_[ColumnIndex::module_debugid]);
  }
  const TypedColumn<StringPool::Id>& module_debug_path() const {
    return static_cast<const ColumnType::module_debug_path&>(columns_[ColumnIndex::module_debug_path]);
  }
  const TypedColumn<int64_t>& protection_flags() const {
    return static_cast<const ColumnType::protection_flags&>(columns_[ColumnIndex::protection_flags]);
  }
  const TypedColumn<int64_t>& private_clean_resident_kb() const {
    return static_cast<const ColumnType::private_clean_resident_kb&>(columns_[ColumnIndex::private_clean_resident_kb]);
  }
  const TypedColumn<int64_t>& shared_dirty_resident_kb() const {
    return static_cast<const ColumnType::shared_dirty_resident_kb&>(columns_[ColumnIndex::shared_dirty_resident_kb]);
  }
  const TypedColumn<int64_t>& shared_clean_resident_kb() const {
    return static_cast<const ColumnType::shared_clean_resident_kb&>(columns_[ColumnIndex::shared_clean_resident_kb]);
  }
  const TypedColumn<int64_t>& locked_kb() const {
    return static_cast<const ColumnType::locked_kb&>(columns_[ColumnIndex::locked_kb]);
  }
  const TypedColumn<int64_t>& proportional_resident_kb() const {
    return static_cast<const ColumnType::proportional_resident_kb&>(columns_[ColumnIndex::proportional_resident_kb]);
  }

  TypedColumn<uint32_t>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<int64_t>* mutable_ts() {
    return static_cast<ColumnType::ts*>(
        &columns_[ColumnIndex::ts]);
  }
  TypedColumn<StringPool::Id>* mutable_path() {
    return static_cast<ColumnType::path*>(
        &columns_[ColumnIndex::path]);
  }
  TypedColumn<int64_t>* mutable_size_kb() {
    return static_cast<ColumnType::size_kb*>(
        &columns_[ColumnIndex::size_kb]);
  }
  TypedColumn<int64_t>* mutable_private_dirty_kb() {
    return static_cast<ColumnType::private_dirty_kb*>(
        &columns_[ColumnIndex::private_dirty_kb]);
  }
  TypedColumn<int64_t>* mutable_swap_kb() {
    return static_cast<ColumnType::swap_kb*>(
        &columns_[ColumnIndex::swap_kb]);
  }
  TypedColumn<StringPool::Id>* mutable_file_name() {
    return static_cast<ColumnType::file_name*>(
        &columns_[ColumnIndex::file_name]);
  }
  TypedColumn<int64_t>* mutable_start_address() {
    return static_cast<ColumnType::start_address*>(
        &columns_[ColumnIndex::start_address]);
  }
  TypedColumn<int64_t>* mutable_module_timestamp() {
    return static_cast<ColumnType::module_timestamp*>(
        &columns_[ColumnIndex::module_timestamp]);
  }
  TypedColumn<StringPool::Id>* mutable_module_debugid() {
    return static_cast<ColumnType::module_debugid*>(
        &columns_[ColumnIndex::module_debugid]);
  }
  TypedColumn<StringPool::Id>* mutable_module_debug_path() {
    return static_cast<ColumnType::module_debug_path*>(
        &columns_[ColumnIndex::module_debug_path]);
  }
  TypedColumn<int64_t>* mutable_protection_flags() {
    return static_cast<ColumnType::protection_flags*>(
        &columns_[ColumnIndex::protection_flags]);
  }
  TypedColumn<int64_t>* mutable_private_clean_resident_kb() {
    return static_cast<ColumnType::private_clean_resident_kb*>(
        &columns_[ColumnIndex::private_clean_resident_kb]);
  }
  TypedColumn<int64_t>* mutable_shared_dirty_resident_kb() {
    return static_cast<ColumnType::shared_dirty_resident_kb*>(
        &columns_[ColumnIndex::shared_dirty_resident_kb]);
  }
  TypedColumn<int64_t>* mutable_shared_clean_resident_kb() {
    return static_cast<ColumnType::shared_clean_resident_kb*>(
        &columns_[ColumnIndex::shared_clean_resident_kb]);
  }
  TypedColumn<int64_t>* mutable_locked_kb() {
    return static_cast<ColumnType::locked_kb*>(
        &columns_[ColumnIndex::locked_kb]);
  }
  TypedColumn<int64_t>* mutable_proportional_resident_kb() {
    return static_cast<ColumnType::proportional_resident_kb*>(
        &columns_[ColumnIndex::proportional_resident_kb]);
  }

 private:
  
  
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::ts::stored_type> ts_;
  ColumnStorage<ColumnType::path::stored_type> path_;
  ColumnStorage<ColumnType::size_kb::stored_type> size_kb_;
  ColumnStorage<ColumnType::private_dirty_kb::stored_type> private_dirty_kb_;
  ColumnStorage<ColumnType::swap_kb::stored_type> swap_kb_;
  ColumnStorage<ColumnType::file_name::stored_type> file_name_;
  ColumnStorage<ColumnType::start_address::stored_type> start_address_;
  ColumnStorage<ColumnType::module_timestamp::stored_type> module_timestamp_;
  ColumnStorage<ColumnType::module_debugid::stored_type> module_debugid_;
  ColumnStorage<ColumnType::module_debug_path::stored_type> module_debug_path_;
  ColumnStorage<ColumnType::protection_flags::stored_type> protection_flags_;
  ColumnStorage<ColumnType::private_clean_resident_kb::stored_type> private_clean_resident_kb_;
  ColumnStorage<ColumnType::shared_dirty_resident_kb::stored_type> shared_dirty_resident_kb_;
  ColumnStorage<ColumnType::shared_clean_resident_kb::stored_type> shared_clean_resident_kb_;
  ColumnStorage<ColumnType::locked_kb::stored_type> locked_kb_;
  ColumnStorage<ColumnType::proportional_resident_kb::stored_type> proportional_resident_kb_;
};
  

class SymbolTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t symbol_set_id = 2;
    static constexpr uint32_t name = 3;
    static constexpr uint32_t source_file = 4;
    static constexpr uint32_t line_number = 5;
  };
  struct ColumnType {
    using id = IdColumn<SymbolTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using symbol_set_id = TypedColumn<uint32_t>;
    using name = TypedColumn<StringPool::Id>;
    using source_file = TypedColumn<StringPool::Id>;
    using line_number = TypedColumn<uint32_t>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(uint32_t in_symbol_set_id = {},
        StringPool::Id in_name = {},
        StringPool::Id in_source_file = {},
        uint32_t in_line_number = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          symbol_set_id(std::move(in_symbol_set_id)),
          name(std::move(in_name)),
          source_file(std::move(in_source_file)),
          line_number(std::move(in_line_number)) {
      type_ = "stack_profile_symbol";
    }
    uint32_t symbol_set_id;
    StringPool::Id name;
    StringPool::Id source_file;
    uint32_t line_number;

    bool operator==(const SymbolTable::Row& other) const {
      return type() == other.type() && ColumnType::symbol_set_id::Equals(symbol_set_id, other.symbol_set_id) &&
       ColumnType::name::Equals(name, other.name) &&
       ColumnType::source_file::Equals(source_file, other.source_file) &&
       ColumnType::line_number::Equals(line_number, other.line_number);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t symbol_set_id = static_cast<uint32_t>(Column::Flag::kSorted | Column::Flag::kSetId) | ColumnType::symbol_set_id::default_flags();
    static constexpr uint32_t name = ColumnType::name::default_flags();
    static constexpr uint32_t source_file = ColumnType::source_file::default_flags();
    static constexpr uint32_t line_number = ColumnType::line_number::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      SymbolTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    SymbolTable, RowNumber> {
   public:
    ConstRowReference(const SymbolTable* table, uint32_t row_number)
        : AbstractConstRowReference(table, row_number) {}

    ColumnType::id::type id() const {
      return table_->id()[row_number_];
    }
    ColumnType::type::type type() const {
      return table_->type()[row_number_];
    }
    ColumnType::symbol_set_id::type symbol_set_id() const {
      return table_->symbol_set_id()[row_number_];
    }
    ColumnType::name::type name() const {
      return table_->name()[row_number_];
    }
    ColumnType::source_file::type source_file() const {
      return table_->source_file()[row_number_];
    }
    ColumnType::line_number::type line_number() const {
      return table_->line_number()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const SymbolTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_symbol_set_id(
        ColumnType::symbol_set_id::non_optional_type v) {
      return mutable_table()->mutable_symbol_set_id()->Set(row_number_, v);
    }
    void set_name(
        ColumnType::name::non_optional_type v) {
      return mutable_table()->mutable_name()->Set(row_number_, v);
    }
    void set_source_file(
        ColumnType::source_file::non_optional_type v) {
      return mutable_table()->mutable_source_file()->Set(row_number_, v);
    }
    void set_line_number(
        ColumnType::line_number::non_optional_type v) {
      return mutable_table()->mutable_line_number()->Set(row_number_, v);
    }

   private:
    SymbolTable* mutable_table() const {
      return const_cast<SymbolTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, SymbolTable, RowNumber, ConstRowReference> {
   public:
    ColumnType::id::type id() const {
      const auto& col = table_->id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::type::type type() const {
      const auto& col = table_->type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::symbol_set_id::type symbol_set_id() const {
      const auto& col = table_->symbol_set_id();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::name::type name() const {
      const auto& col = table_->name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::source_file::type source_file() const {
      const auto& col = table_->source_file();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::line_number::type line_number() const {
      const auto& col = table_->line_number();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const SymbolTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class SymbolTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_symbol_set_id(ColumnType::symbol_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_symbol_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_name(ColumnType::name::non_optional_type v) {
        auto* col = mutable_table_->mutable_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source_file(ColumnType::source_file::non_optional_type v) {
        auto* col = mutable_table_->mutable_source_file();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_line_number(ColumnType::line_number::non_optional_type v) {
        auto* col = mutable_table_->mutable_line_number();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class SymbolTable;

    explicit Iterator(SymbolTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    SymbolTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit SymbolTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        symbol_set_id_(ColumnStorage<ColumnType::symbol_set_id::stored_type>::Create<false>()),
        name_(ColumnStorage<ColumnType::name::stored_type>::Create<false>()),
        source_file_(ColumnStorage<ColumnType::source_file::stored_type>::Create<false>()),
        line_number_(ColumnStorage<ColumnType::line_number::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::symbol_set_id::stored_type>(
          ColumnFlag::symbol_set_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::name::stored_type>(
          ColumnFlag::name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::source_file::stored_type>(
          ColumnFlag::source_file),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::line_number::stored_type>(
          ColumnFlag::line_number),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("symbol_set_id", &symbol_set_id_, ColumnFlag::symbol_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("name", &name_, ColumnFlag::name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("source_file", &source_file_, ColumnFlag::source_file,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("line_number", &line_number_, ColumnFlag::line_number,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~SymbolTable() override;

  static const char* Name() { return "stack_profile_symbol"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "symbol_set_id", ColumnType::symbol_set_id::SqlValueType(), false,
        true,
        false,
        true});
    schema.columns.emplace_back(Table::Schema::Column{
        "name", ColumnType::name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source_file", ColumnType::source_file::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "line_number", ColumnType::line_number::SqlValueType(), false,
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
    symbol_set_id_.ShrinkToFit();
    name_.ShrinkToFit();
    source_file_.ShrinkToFit();
    line_number_.ShrinkToFit();
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
    mutable_symbol_set_id()->Append(std::move(row.symbol_set_id));
    mutable_name()->Append(std::move(row.name));
    mutable_source_file()->Append(std::move(row.source_file));
    mutable_line_number()->Append(std::move(row.line_number));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<SymbolTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<uint32_t>& symbol_set_id() const {
    return static_cast<const ColumnType::symbol_set_id&>(columns_[ColumnIndex::symbol_set_id]);
  }
  const TypedColumn<StringPool::Id>& name() const {
    return static_cast<const ColumnType::name&>(columns_[ColumnIndex::name]);
  }
  const TypedColumn<StringPool::Id>& source_file() const {
    return static_cast<const ColumnType::source_file&>(columns_[ColumnIndex::source_file]);
  }
  const TypedColumn<uint32_t>& line_number() const {
    return static_cast<const ColumnType::line_number&>(columns_[ColumnIndex::line_number]);
  }

  TypedColumn<uint32_t>* mutable_symbol_set_id() {
    return static_cast<ColumnType::symbol_set_id*>(
        &columns_[ColumnIndex::symbol_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_name() {
    return static_cast<ColumnType::name*>(
        &columns_[ColumnIndex::name]);
  }
  TypedColumn<StringPool::Id>* mutable_source_file() {
    return static_cast<ColumnType::source_file*>(
        &columns_[ColumnIndex::source_file]);
  }
  TypedColumn<uint32_t>* mutable_line_number() {
    return static_cast<ColumnType::line_number*>(
        &columns_[ColumnIndex::line_number]);
  }

 private:
  
  
  ColumnStorage<ColumnType::symbol_set_id::stored_type> symbol_set_id_;
  ColumnStorage<ColumnType::name::stored_type> name_;
  ColumnStorage<ColumnType::source_file::stored_type> source_file_;
  ColumnStorage<ColumnType::line_number::stored_type> line_number_;
};
  

class VulkanMemoryAllocationsTable : public macros_internal::MacroTable {
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
    static constexpr uint32_t source = 3;
    static constexpr uint32_t operation = 4;
    static constexpr uint32_t timestamp = 5;
    static constexpr uint32_t upid = 6;
    static constexpr uint32_t device = 7;
    static constexpr uint32_t device_memory = 8;
    static constexpr uint32_t memory_type = 9;
    static constexpr uint32_t heap = 10;
    static constexpr uint32_t function_name = 11;
    static constexpr uint32_t object_handle = 12;
    static constexpr uint32_t memory_address = 13;
    static constexpr uint32_t memory_size = 14;
    static constexpr uint32_t scope = 15;
  };
  struct ColumnType {
    using id = IdColumn<VulkanMemoryAllocationsTable::Id>;
    using type = TypedColumn<StringPool::Id>;
    using arg_set_id = TypedColumn<std::optional<uint32_t>>;
    using source = TypedColumn<StringPool::Id>;
    using operation = TypedColumn<StringPool::Id>;
    using timestamp = TypedColumn<int64_t>;
    using upid = TypedColumn<std::optional<uint32_t>>;
    using device = TypedColumn<std::optional<int64_t>>;
    using device_memory = TypedColumn<std::optional<int64_t>>;
    using memory_type = TypedColumn<std::optional<uint32_t>>;
    using heap = TypedColumn<std::optional<uint32_t>>;
    using function_name = TypedColumn<std::optional<StringPool::Id>>;
    using object_handle = TypedColumn<std::optional<int64_t>>;
    using memory_address = TypedColumn<std::optional<int64_t>>;
    using memory_size = TypedColumn<std::optional<int64_t>>;
    using scope = TypedColumn<StringPool::Id>;
  };
  struct Row : public macros_internal::RootParentTable::Row {
    Row(std::optional<uint32_t> in_arg_set_id = {},
        StringPool::Id in_source = {},
        StringPool::Id in_operation = {},
        int64_t in_timestamp = {},
        std::optional<uint32_t> in_upid = {},
        std::optional<int64_t> in_device = {},
        std::optional<int64_t> in_device_memory = {},
        std::optional<uint32_t> in_memory_type = {},
        std::optional<uint32_t> in_heap = {},
        std::optional<StringPool::Id> in_function_name = {},
        std::optional<int64_t> in_object_handle = {},
        std::optional<int64_t> in_memory_address = {},
        std::optional<int64_t> in_memory_size = {},
        StringPool::Id in_scope = {},
        std::nullptr_t = nullptr)
        : macros_internal::RootParentTable::Row(),
          arg_set_id(std::move(in_arg_set_id)),
          source(std::move(in_source)),
          operation(std::move(in_operation)),
          timestamp(std::move(in_timestamp)),
          upid(std::move(in_upid)),
          device(std::move(in_device)),
          device_memory(std::move(in_device_memory)),
          memory_type(std::move(in_memory_type)),
          heap(std::move(in_heap)),
          function_name(std::move(in_function_name)),
          object_handle(std::move(in_object_handle)),
          memory_address(std::move(in_memory_address)),
          memory_size(std::move(in_memory_size)),
          scope(std::move(in_scope)) {
      type_ = "vulkan_memory_allocations";
    }
    std::optional<uint32_t> arg_set_id;
    StringPool::Id source;
    StringPool::Id operation;
    int64_t timestamp;
    std::optional<uint32_t> upid;
    std::optional<int64_t> device;
    std::optional<int64_t> device_memory;
    std::optional<uint32_t> memory_type;
    std::optional<uint32_t> heap;
    std::optional<StringPool::Id> function_name;
    std::optional<int64_t> object_handle;
    std::optional<int64_t> memory_address;
    std::optional<int64_t> memory_size;
    StringPool::Id scope;

    bool operator==(const VulkanMemoryAllocationsTable::Row& other) const {
      return type() == other.type() && ColumnType::arg_set_id::Equals(arg_set_id, other.arg_set_id) &&
       ColumnType::source::Equals(source, other.source) &&
       ColumnType::operation::Equals(operation, other.operation) &&
       ColumnType::timestamp::Equals(timestamp, other.timestamp) &&
       ColumnType::upid::Equals(upid, other.upid) &&
       ColumnType::device::Equals(device, other.device) &&
       ColumnType::device_memory::Equals(device_memory, other.device_memory) &&
       ColumnType::memory_type::Equals(memory_type, other.memory_type) &&
       ColumnType::heap::Equals(heap, other.heap) &&
       ColumnType::function_name::Equals(function_name, other.function_name) &&
       ColumnType::object_handle::Equals(object_handle, other.object_handle) &&
       ColumnType::memory_address::Equals(memory_address, other.memory_address) &&
       ColumnType::memory_size::Equals(memory_size, other.memory_size) &&
       ColumnType::scope::Equals(scope, other.scope);
    }
  };
  struct ColumnFlag {
    static constexpr uint32_t arg_set_id = ColumnType::arg_set_id::default_flags();
    static constexpr uint32_t source = ColumnType::source::default_flags();
    static constexpr uint32_t operation = ColumnType::operation::default_flags();
    static constexpr uint32_t timestamp = ColumnType::timestamp::default_flags();
    static constexpr uint32_t upid = ColumnType::upid::default_flags();
    static constexpr uint32_t device = ColumnType::device::default_flags();
    static constexpr uint32_t device_memory = ColumnType::device_memory::default_flags();
    static constexpr uint32_t memory_type = ColumnType::memory_type::default_flags();
    static constexpr uint32_t heap = ColumnType::heap::default_flags();
    static constexpr uint32_t function_name = ColumnType::function_name::default_flags();
    static constexpr uint32_t object_handle = ColumnType::object_handle::default_flags();
    static constexpr uint32_t memory_address = ColumnType::memory_address::default_flags();
    static constexpr uint32_t memory_size = ColumnType::memory_size::default_flags();
    static constexpr uint32_t scope = ColumnType::scope::default_flags();
  };

  class RowNumber;
  class ConstRowReference;
  class RowReference;

  class RowNumber : public macros_internal::AbstractRowNumber<
      VulkanMemoryAllocationsTable, ConstRowReference, RowReference> {
   public:
    explicit RowNumber(uint32_t row_number)
        : AbstractRowNumber(row_number) {}
  };
  static_assert(std::is_trivially_destructible<RowNumber>::value,
                "Inheritance used without trivial destruction");

  class ConstRowReference : public macros_internal::AbstractConstRowReference<
    VulkanMemoryAllocationsTable, RowNumber> {
   public:
    ConstRowReference(const VulkanMemoryAllocationsTable* table, uint32_t row_number)
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
    ColumnType::source::type source() const {
      return table_->source()[row_number_];
    }
    ColumnType::operation::type operation() const {
      return table_->operation()[row_number_];
    }
    ColumnType::timestamp::type timestamp() const {
      return table_->timestamp()[row_number_];
    }
    ColumnType::upid::type upid() const {
      return table_->upid()[row_number_];
    }
    ColumnType::device::type device() const {
      return table_->device()[row_number_];
    }
    ColumnType::device_memory::type device_memory() const {
      return table_->device_memory()[row_number_];
    }
    ColumnType::memory_type::type memory_type() const {
      return table_->memory_type()[row_number_];
    }
    ColumnType::heap::type heap() const {
      return table_->heap()[row_number_];
    }
    ColumnType::function_name::type function_name() const {
      return table_->function_name()[row_number_];
    }
    ColumnType::object_handle::type object_handle() const {
      return table_->object_handle()[row_number_];
    }
    ColumnType::memory_address::type memory_address() const {
      return table_->memory_address()[row_number_];
    }
    ColumnType::memory_size::type memory_size() const {
      return table_->memory_size()[row_number_];
    }
    ColumnType::scope::type scope() const {
      return table_->scope()[row_number_];
    }
  };
  static_assert(std::is_trivially_destructible<ConstRowReference>::value,
                "Inheritance used without trivial destruction");
  class RowReference : public ConstRowReference {
   public:
    RowReference(const VulkanMemoryAllocationsTable* table, uint32_t row_number)
        : ConstRowReference(table, row_number) {}

    void set_arg_set_id(
        ColumnType::arg_set_id::non_optional_type v) {
      return mutable_table()->mutable_arg_set_id()->Set(row_number_, v);
    }
    void set_source(
        ColumnType::source::non_optional_type v) {
      return mutable_table()->mutable_source()->Set(row_number_, v);
    }
    void set_operation(
        ColumnType::operation::non_optional_type v) {
      return mutable_table()->mutable_operation()->Set(row_number_, v);
    }
    void set_timestamp(
        ColumnType::timestamp::non_optional_type v) {
      return mutable_table()->mutable_timestamp()->Set(row_number_, v);
    }
    void set_upid(
        ColumnType::upid::non_optional_type v) {
      return mutable_table()->mutable_upid()->Set(row_number_, v);
    }
    void set_device(
        ColumnType::device::non_optional_type v) {
      return mutable_table()->mutable_device()->Set(row_number_, v);
    }
    void set_device_memory(
        ColumnType::device_memory::non_optional_type v) {
      return mutable_table()->mutable_device_memory()->Set(row_number_, v);
    }
    void set_memory_type(
        ColumnType::memory_type::non_optional_type v) {
      return mutable_table()->mutable_memory_type()->Set(row_number_, v);
    }
    void set_heap(
        ColumnType::heap::non_optional_type v) {
      return mutable_table()->mutable_heap()->Set(row_number_, v);
    }
    void set_function_name(
        ColumnType::function_name::non_optional_type v) {
      return mutable_table()->mutable_function_name()->Set(row_number_, v);
    }
    void set_object_handle(
        ColumnType::object_handle::non_optional_type v) {
      return mutable_table()->mutable_object_handle()->Set(row_number_, v);
    }
    void set_memory_address(
        ColumnType::memory_address::non_optional_type v) {
      return mutable_table()->mutable_memory_address()->Set(row_number_, v);
    }
    void set_memory_size(
        ColumnType::memory_size::non_optional_type v) {
      return mutable_table()->mutable_memory_size()->Set(row_number_, v);
    }
    void set_scope(
        ColumnType::scope::non_optional_type v) {
      return mutable_table()->mutable_scope()->Set(row_number_, v);
    }

   private:
    VulkanMemoryAllocationsTable* mutable_table() const {
      return const_cast<VulkanMemoryAllocationsTable*>(table_);
    }
  };
  static_assert(std::is_trivially_destructible<RowReference>::value,
                "Inheritance used without trivial destruction");

  class ConstIterator;
  class ConstIterator : public macros_internal::AbstractConstIterator<
    ConstIterator, VulkanMemoryAllocationsTable, RowNumber, ConstRowReference> {
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
    ColumnType::source::type source() const {
      const auto& col = table_->source();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::operation::type operation() const {
      const auto& col = table_->operation();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::timestamp::type timestamp() const {
      const auto& col = table_->timestamp();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::upid::type upid() const {
      const auto& col = table_->upid();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::device::type device() const {
      const auto& col = table_->device();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::device_memory::type device_memory() const {
      const auto& col = table_->device_memory();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::memory_type::type memory_type() const {
      const auto& col = table_->memory_type();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::heap::type heap() const {
      const auto& col = table_->heap();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::function_name::type function_name() const {
      const auto& col = table_->function_name();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::object_handle::type object_handle() const {
      const auto& col = table_->object_handle();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::memory_address::type memory_address() const {
      const auto& col = table_->memory_address();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::memory_size::type memory_size() const {
      const auto& col = table_->memory_size();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }
    ColumnType::scope::type scope() const {
      const auto& col = table_->scope();
      return col.GetAtIdx(its_[col.overlay_index()].index());
    }

   protected:
    explicit ConstIterator(const VulkanMemoryAllocationsTable* table,
                           std::vector<ColumnStorageOverlay> overlays)
        : AbstractConstIterator(table, std::move(overlays)) {}

    uint32_t CurrentRowNumber() const {
      return its_.back().index();
    }

   private:
    friend class VulkanMemoryAllocationsTable;
    friend class AbstractConstIterator;
  };
  class Iterator : public ConstIterator {
    public:
    void set_arg_set_id(ColumnType::arg_set_id::non_optional_type v) {
        auto* col = mutable_table_->mutable_arg_set_id();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_source(ColumnType::source::non_optional_type v) {
        auto* col = mutable_table_->mutable_source();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_operation(ColumnType::operation::non_optional_type v) {
        auto* col = mutable_table_->mutable_operation();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_timestamp(ColumnType::timestamp::non_optional_type v) {
        auto* col = mutable_table_->mutable_timestamp();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_upid(ColumnType::upid::non_optional_type v) {
        auto* col = mutable_table_->mutable_upid();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_device(ColumnType::device::non_optional_type v) {
        auto* col = mutable_table_->mutable_device();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_device_memory(ColumnType::device_memory::non_optional_type v) {
        auto* col = mutable_table_->mutable_device_memory();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_memory_type(ColumnType::memory_type::non_optional_type v) {
        auto* col = mutable_table_->mutable_memory_type();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_heap(ColumnType::heap::non_optional_type v) {
        auto* col = mutable_table_->mutable_heap();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_function_name(ColumnType::function_name::non_optional_type v) {
        auto* col = mutable_table_->mutable_function_name();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_object_handle(ColumnType::object_handle::non_optional_type v) {
        auto* col = mutable_table_->mutable_object_handle();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_memory_address(ColumnType::memory_address::non_optional_type v) {
        auto* col = mutable_table_->mutable_memory_address();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_memory_size(ColumnType::memory_size::non_optional_type v) {
        auto* col = mutable_table_->mutable_memory_size();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }
      void set_scope(ColumnType::scope::non_optional_type v) {
        auto* col = mutable_table_->mutable_scope();
        col->SetAtIdx(its_[col->overlay_index()].index(), v);
      }

    RowReference row_reference() const {
      return RowReference(mutable_table_, CurrentRowNumber());
    }

    private:
    friend class VulkanMemoryAllocationsTable;

    explicit Iterator(VulkanMemoryAllocationsTable* table,
                      std::vector<ColumnStorageOverlay> overlays)
        : ConstIterator(table, std::move(overlays)),
          mutable_table_(table) {}

    VulkanMemoryAllocationsTable* mutable_table_ = nullptr;
  };

  struct IdAndRow {
    Id id;
    uint32_t row;
    RowReference row_reference;
    RowNumber row_number;
  };

  explicit VulkanMemoryAllocationsTable(StringPool* pool)
      : macros_internal::MacroTable(pool, nullptr),
        arg_set_id_(ColumnStorage<ColumnType::arg_set_id::stored_type>::Create<false>()),
        source_(ColumnStorage<ColumnType::source::stored_type>::Create<false>()),
        operation_(ColumnStorage<ColumnType::operation::stored_type>::Create<false>()),
        timestamp_(ColumnStorage<ColumnType::timestamp::stored_type>::Create<false>()),
        upid_(ColumnStorage<ColumnType::upid::stored_type>::Create<false>()),
        device_(ColumnStorage<ColumnType::device::stored_type>::Create<false>()),
        device_memory_(ColumnStorage<ColumnType::device_memory::stored_type>::Create<false>()),
        memory_type_(ColumnStorage<ColumnType::memory_type::stored_type>::Create<false>()),
        heap_(ColumnStorage<ColumnType::heap::stored_type>::Create<false>()),
        function_name_(ColumnStorage<ColumnType::function_name::stored_type>::Create<false>()),
        object_handle_(ColumnStorage<ColumnType::object_handle::stored_type>::Create<false>()),
        memory_address_(ColumnStorage<ColumnType::memory_address::stored_type>::Create<false>()),
        memory_size_(ColumnStorage<ColumnType::memory_size::stored_type>::Create<false>()),
        scope_(ColumnStorage<ColumnType::scope::stored_type>::Create<false>()) {
    static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::arg_set_id::stored_type>(
          ColumnFlag::arg_set_id),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::source::stored_type>(
          ColumnFlag::source),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::operation::stored_type>(
          ColumnFlag::operation),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::timestamp::stored_type>(
          ColumnFlag::timestamp),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::upid::stored_type>(
          ColumnFlag::upid),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::device::stored_type>(
          ColumnFlag::device),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::device_memory::stored_type>(
          ColumnFlag::device_memory),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::memory_type::stored_type>(
          ColumnFlag::memory_type),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::heap::stored_type>(
          ColumnFlag::heap),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::function_name::stored_type>(
          ColumnFlag::function_name),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::object_handle::stored_type>(
          ColumnFlag::object_handle),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::memory_address::stored_type>(
          ColumnFlag::memory_address),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::memory_size::stored_type>(
          ColumnFlag::memory_size),
        "Column type and flag combination is not valid");
      static_assert(
        Column::IsFlagsAndTypeValid<ColumnType::scope::stored_type>(
          ColumnFlag::scope),
        "Column type and flag combination is not valid");
    uint32_t olay_idx = static_cast<uint32_t>(overlays_.size()) - 1;
    columns_.emplace_back("arg_set_id", &arg_set_id_, ColumnFlag::arg_set_id,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("source", &source_, ColumnFlag::source,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("operation", &operation_, ColumnFlag::operation,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("timestamp", &timestamp_, ColumnFlag::timestamp,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("upid", &upid_, ColumnFlag::upid,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("device", &device_, ColumnFlag::device,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("device_memory", &device_memory_, ColumnFlag::device_memory,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("memory_type", &memory_type_, ColumnFlag::memory_type,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("heap", &heap_, ColumnFlag::heap,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("function_name", &function_name_, ColumnFlag::function_name,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("object_handle", &object_handle_, ColumnFlag::object_handle,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("memory_address", &memory_address_, ColumnFlag::memory_address,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("memory_size", &memory_size_, ColumnFlag::memory_size,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
    columns_.emplace_back("scope", &scope_, ColumnFlag::scope,
                          this, static_cast<uint32_t>(columns_.size()),
                          olay_idx);
  }
  ~VulkanMemoryAllocationsTable() override;

  static const char* Name() { return "vulkan_memory_allocations"; }

  static Table::Schema ComputeStaticSchema() {
    Table::Schema schema;
    schema.columns.emplace_back(Table::Schema::Column{
        "id", SqlValue::Type::kLong, true, true, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "type", SqlValue::Type::kString, false, false, false, false});
    schema.columns.emplace_back(Table::Schema::Column{
        "arg_set_id", ColumnType::arg_set_id::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "source", ColumnType::source::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "operation", ColumnType::operation::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "timestamp", ColumnType::timestamp::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "upid", ColumnType::upid::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "device", ColumnType::device::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "device_memory", ColumnType::device_memory::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "memory_type", ColumnType::memory_type::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "heap", ColumnType::heap::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "function_name", ColumnType::function_name::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "object_handle", ColumnType::object_handle::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "memory_address", ColumnType::memory_address::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "memory_size", ColumnType::memory_size::SqlValueType(), false,
        false,
        false,
        false});
    schema.columns.emplace_back(Table::Schema::Column{
        "scope", ColumnType::scope::SqlValueType(), false,
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
    source_.ShrinkToFit();
    operation_.ShrinkToFit();
    timestamp_.ShrinkToFit();
    upid_.ShrinkToFit();
    device_.ShrinkToFit();
    device_memory_.ShrinkToFit();
    memory_type_.ShrinkToFit();
    heap_.ShrinkToFit();
    function_name_.ShrinkToFit();
    object_handle_.ShrinkToFit();
    memory_address_.ShrinkToFit();
    memory_size_.ShrinkToFit();
    scope_.ShrinkToFit();
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
    mutable_source()->Append(std::move(row.source));
    mutable_operation()->Append(std::move(row.operation));
    mutable_timestamp()->Append(std::move(row.timestamp));
    mutable_upid()->Append(std::move(row.upid));
    mutable_device()->Append(std::move(row.device));
    mutable_device_memory()->Append(std::move(row.device_memory));
    mutable_memory_type()->Append(std::move(row.memory_type));
    mutable_heap()->Append(std::move(row.heap));
    mutable_function_name()->Append(std::move(row.function_name));
    mutable_object_handle()->Append(std::move(row.object_handle));
    mutable_memory_address()->Append(std::move(row.memory_address));
    mutable_memory_size()->Append(std::move(row.memory_size));
    mutable_scope()->Append(std::move(row.scope));
    UpdateSelfOverlayAfterInsert();
    return IdAndRow{std::move(id), row_number, RowReference(this, row_number),
                     RowNumber(row_number)};
  }

  

  const IdColumn<VulkanMemoryAllocationsTable::Id>& id() const {
    return static_cast<const ColumnType::id&>(columns_[ColumnIndex::id]);
  }
  const TypedColumn<StringPool::Id>& type() const {
    return static_cast<const ColumnType::type&>(columns_[ColumnIndex::type]);
  }
  const TypedColumn<std::optional<uint32_t>>& arg_set_id() const {
    return static_cast<const ColumnType::arg_set_id&>(columns_[ColumnIndex::arg_set_id]);
  }
  const TypedColumn<StringPool::Id>& source() const {
    return static_cast<const ColumnType::source&>(columns_[ColumnIndex::source]);
  }
  const TypedColumn<StringPool::Id>& operation() const {
    return static_cast<const ColumnType::operation&>(columns_[ColumnIndex::operation]);
  }
  const TypedColumn<int64_t>& timestamp() const {
    return static_cast<const ColumnType::timestamp&>(columns_[ColumnIndex::timestamp]);
  }
  const TypedColumn<std::optional<uint32_t>>& upid() const {
    return static_cast<const ColumnType::upid&>(columns_[ColumnIndex::upid]);
  }
  const TypedColumn<std::optional<int64_t>>& device() const {
    return static_cast<const ColumnType::device&>(columns_[ColumnIndex::device]);
  }
  const TypedColumn<std::optional<int64_t>>& device_memory() const {
    return static_cast<const ColumnType::device_memory&>(columns_[ColumnIndex::device_memory]);
  }
  const TypedColumn<std::optional<uint32_t>>& memory_type() const {
    return static_cast<const ColumnType::memory_type&>(columns_[ColumnIndex::memory_type]);
  }
  const TypedColumn<std::optional<uint32_t>>& heap() const {
    return static_cast<const ColumnType::heap&>(columns_[ColumnIndex::heap]);
  }
  const TypedColumn<std::optional<StringPool::Id>>& function_name() const {
    return static_cast<const ColumnType::function_name&>(columns_[ColumnIndex::function_name]);
  }
  const TypedColumn<std::optional<int64_t>>& object_handle() const {
    return static_cast<const ColumnType::object_handle&>(columns_[ColumnIndex::object_handle]);
  }
  const TypedColumn<std::optional<int64_t>>& memory_address() const {
    return static_cast<const ColumnType::memory_address&>(columns_[ColumnIndex::memory_address]);
  }
  const TypedColumn<std::optional<int64_t>>& memory_size() const {
    return static_cast<const ColumnType::memory_size&>(columns_[ColumnIndex::memory_size]);
  }
  const TypedColumn<StringPool::Id>& scope() const {
    return static_cast<const ColumnType::scope&>(columns_[ColumnIndex::scope]);
  }

  TypedColumn<std::optional<uint32_t>>* mutable_arg_set_id() {
    return static_cast<ColumnType::arg_set_id*>(
        &columns_[ColumnIndex::arg_set_id]);
  }
  TypedColumn<StringPool::Id>* mutable_source() {
    return static_cast<ColumnType::source*>(
        &columns_[ColumnIndex::source]);
  }
  TypedColumn<StringPool::Id>* mutable_operation() {
    return static_cast<ColumnType::operation*>(
        &columns_[ColumnIndex::operation]);
  }
  TypedColumn<int64_t>* mutable_timestamp() {
    return static_cast<ColumnType::timestamp*>(
        &columns_[ColumnIndex::timestamp]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_upid() {
    return static_cast<ColumnType::upid*>(
        &columns_[ColumnIndex::upid]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_device() {
    return static_cast<ColumnType::device*>(
        &columns_[ColumnIndex::device]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_device_memory() {
    return static_cast<ColumnType::device_memory*>(
        &columns_[ColumnIndex::device_memory]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_memory_type() {
    return static_cast<ColumnType::memory_type*>(
        &columns_[ColumnIndex::memory_type]);
  }
  TypedColumn<std::optional<uint32_t>>* mutable_heap() {
    return static_cast<ColumnType::heap*>(
        &columns_[ColumnIndex::heap]);
  }
  TypedColumn<std::optional<StringPool::Id>>* mutable_function_name() {
    return static_cast<ColumnType::function_name*>(
        &columns_[ColumnIndex::function_name]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_object_handle() {
    return static_cast<ColumnType::object_handle*>(
        &columns_[ColumnIndex::object_handle]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_memory_address() {
    return static_cast<ColumnType::memory_address*>(
        &columns_[ColumnIndex::memory_address]);
  }
  TypedColumn<std::optional<int64_t>>* mutable_memory_size() {
    return static_cast<ColumnType::memory_size*>(
        &columns_[ColumnIndex::memory_size]);
  }
  TypedColumn<StringPool::Id>* mutable_scope() {
    return static_cast<ColumnType::scope*>(
        &columns_[ColumnIndex::scope]);
  }

 private:
  
  
  ColumnStorage<ColumnType::arg_set_id::stored_type> arg_set_id_;
  ColumnStorage<ColumnType::source::stored_type> source_;
  ColumnStorage<ColumnType::operation::stored_type> operation_;
  ColumnStorage<ColumnType::timestamp::stored_type> timestamp_;
  ColumnStorage<ColumnType::upid::stored_type> upid_;
  ColumnStorage<ColumnType::device::stored_type> device_;
  ColumnStorage<ColumnType::device_memory::stored_type> device_memory_;
  ColumnStorage<ColumnType::memory_type::stored_type> memory_type_;
  ColumnStorage<ColumnType::heap::stored_type> heap_;
  ColumnStorage<ColumnType::function_name::stored_type> function_name_;
  ColumnStorage<ColumnType::object_handle::stored_type> object_handle_;
  ColumnStorage<ColumnType::memory_address::stored_type> memory_address_;
  ColumnStorage<ColumnType::memory_size::stored_type> memory_size_;
  ColumnStorage<ColumnType::scope::stored_type> scope_;
};

}  // namespace tables
}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_TABLES_PROFILER_TABLES_PY_H_

/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 *******************************************************************************
 * AUTOGENERATED BY tools/gen_amalgamated_sql.py - DO NOT EDIT
 *******************************************************************************
 */

 #include <string.h>

namespace perfetto {
namespace trace_processor {
namespace prelude::tables_views {

const char kTables[] = R"_d3l1m1t3r_(CREATE TABLE perfetto_tables(name STRING);

CREATE TABLE trace_bounds AS
SELECT 0 AS start_ts, 0 AS end_ts;

CREATE TABLE power_profile(
  device STRING,
  cpu INT,
  cluster INT,
  freq INT,
  power DOUBLE,
  UNIQUE(device, cpu, cluster, freq)
);

CREATE TABLE trace_metrics(name STRING);

CREATE TABLE debug_slices(
  id BIGINT,
  name STRING,
  ts BIGINT,
  dur BIGINT,
  depth BIGINT
);

CREATE VIRTUAL TABLE window USING window();

)_d3l1m1t3r_"
;

const char kViews[] = R"_d3l1m1t3r_(CREATE VIEW counters AS 
SELECT *
FROM counter v 
JOIN counter_track t ON v.track_id = t.id 
ORDER BY ts;

CREATE VIEW slice AS 
SELECT
  *, 
  category AS cat, 
  id AS slice_id 
FROM internal_slice;

CREATE VIEW instant AS 
SELECT ts, track_id, name, arg_set_id 
FROM slice 
WHERE dur = 0;

CREATE VIEW sched AS 
SELECT 
  *,
  ts + dur as ts_end
FROM sched_slice;

CREATE VIEW slices AS 
SELECT * FROM slice;

CREATE VIEW thread AS 
SELECT 
  id as utid,
  *
FROM internal_thread;

CREATE VIEW process AS 
SELECT 
  id as upid,
  * 
FROM internal_process;

-- This should be kept in sync with GlobalArgsTracker::AddArgSet.
CREATE VIEW args AS 
SELECT 
  *,
  CASE value_type
    WHEN 'int' THEN CAST(int_value AS text)
    WHEN 'uint' THEN CAST(int_value AS text)
    WHEN 'string' THEN string_value
    WHEN 'real' THEN CAST(real_value AS text)
    WHEN 'pointer' THEN printf('0x%x', int_value)
    WHEN 'bool' THEN (
      CASE WHEN int_value <> 0 THEN 'true'
      ELSE 'false' END)
    WHEN 'json' THEN string_value
)_d3l1m1t3r_"
R"_d3l1m1t3r_(  ELSE NULL END AS display_value
FROM internal_args;

)_d3l1m1t3r_"
;

struct FileToSql {
  const char* path;
  const char* sql;
};

const FileToSql kFileToSql[] = {
  {"tables.sql", kTables},

  {"views.sql", kViews},
};

}  // namespace prelude::tables_views
}  // namespace trace_processor
}  // namespace perfetto

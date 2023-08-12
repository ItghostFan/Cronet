// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_COMMON_SYS_STATS_COUNTERS_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_COMMON_SYS_STATS_COUNTERS_PROTO_CPP_H_

#include <stdint.h>
#include <bitset>
#include <vector>
#include <string>
#include <type_traits>

#include "perfetto/protozero/cpp_message_obj.h"
#include "perfetto/protozero/copyable_ptr.h"
#include "perfetto/base/export.h"

namespace perfetto {
namespace protos {
namespace gen {
enum MeminfoCounters : int;
enum VmstatCounters : int;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {
enum MeminfoCounters : int {
  MEMINFO_UNSPECIFIED = 0,
  MEMINFO_MEM_TOTAL = 1,
  MEMINFO_MEM_FREE = 2,
  MEMINFO_MEM_AVAILABLE = 3,
  MEMINFO_BUFFERS = 4,
  MEMINFO_CACHED = 5,
  MEMINFO_SWAP_CACHED = 6,
  MEMINFO_ACTIVE = 7,
  MEMINFO_INACTIVE = 8,
  MEMINFO_ACTIVE_ANON = 9,
  MEMINFO_INACTIVE_ANON = 10,
  MEMINFO_ACTIVE_FILE = 11,
  MEMINFO_INACTIVE_FILE = 12,
  MEMINFO_UNEVICTABLE = 13,
  MEMINFO_MLOCKED = 14,
  MEMINFO_SWAP_TOTAL = 15,
  MEMINFO_SWAP_FREE = 16,
  MEMINFO_DIRTY = 17,
  MEMINFO_WRITEBACK = 18,
  MEMINFO_ANON_PAGES = 19,
  MEMINFO_MAPPED = 20,
  MEMINFO_SHMEM = 21,
  MEMINFO_SLAB = 22,
  MEMINFO_SLAB_RECLAIMABLE = 23,
  MEMINFO_SLAB_UNRECLAIMABLE = 24,
  MEMINFO_KERNEL_STACK = 25,
  MEMINFO_PAGE_TABLES = 26,
  MEMINFO_COMMIT_LIMIT = 27,
  MEMINFO_COMMITED_AS = 28,
  MEMINFO_VMALLOC_TOTAL = 29,
  MEMINFO_VMALLOC_USED = 30,
  MEMINFO_VMALLOC_CHUNK = 31,
  MEMINFO_CMA_TOTAL = 32,
  MEMINFO_CMA_FREE = 33,
};
enum VmstatCounters : int {
  VMSTAT_UNSPECIFIED = 0,
  VMSTAT_NR_FREE_PAGES = 1,
  VMSTAT_NR_ALLOC_BATCH = 2,
  VMSTAT_NR_INACTIVE_ANON = 3,
  VMSTAT_NR_ACTIVE_ANON = 4,
  VMSTAT_NR_INACTIVE_FILE = 5,
  VMSTAT_NR_ACTIVE_FILE = 6,
  VMSTAT_NR_UNEVICTABLE = 7,
  VMSTAT_NR_MLOCK = 8,
  VMSTAT_NR_ANON_PAGES = 9,
  VMSTAT_NR_MAPPED = 10,
  VMSTAT_NR_FILE_PAGES = 11,
  VMSTAT_NR_DIRTY = 12,
  VMSTAT_NR_WRITEBACK = 13,
  VMSTAT_NR_SLAB_RECLAIMABLE = 14,
  VMSTAT_NR_SLAB_UNRECLAIMABLE = 15,
  VMSTAT_NR_PAGE_TABLE_PAGES = 16,
  VMSTAT_NR_KERNEL_STACK = 17,
  VMSTAT_NR_OVERHEAD = 18,
  VMSTAT_NR_UNSTABLE = 19,
  VMSTAT_NR_BOUNCE = 20,
  VMSTAT_NR_VMSCAN_WRITE = 21,
  VMSTAT_NR_VMSCAN_IMMEDIATE_RECLAIM = 22,
  VMSTAT_NR_WRITEBACK_TEMP = 23,
  VMSTAT_NR_ISOLATED_ANON = 24,
  VMSTAT_NR_ISOLATED_FILE = 25,
  VMSTAT_NR_SHMEM = 26,
  VMSTAT_NR_DIRTIED = 27,
  VMSTAT_NR_WRITTEN = 28,
  VMSTAT_NR_PAGES_SCANNED = 29,
  VMSTAT_WORKINGSET_REFAULT = 30,
  VMSTAT_WORKINGSET_ACTIVATE = 31,
  VMSTAT_WORKINGSET_NODERECLAIM = 32,
  VMSTAT_NR_ANON_TRANSPARENT_HUGEPAGES = 33,
  VMSTAT_NR_FREE_CMA = 34,
  VMSTAT_NR_SWAPCACHE = 35,
  VMSTAT_NR_DIRTY_THRESHOLD = 36,
  VMSTAT_NR_DIRTY_BACKGROUND_THRESHOLD = 37,
  VMSTAT_PGPGIN = 38,
  VMSTAT_PGPGOUT = 39,
  VMSTAT_PGPGOUTCLEAN = 40,
  VMSTAT_PSWPIN = 41,
  VMSTAT_PSWPOUT = 42,
  VMSTAT_PGALLOC_DMA = 43,
  VMSTAT_PGALLOC_NORMAL = 44,
  VMSTAT_PGALLOC_MOVABLE = 45,
  VMSTAT_PGFREE = 46,
  VMSTAT_PGACTIVATE = 47,
  VMSTAT_PGDEACTIVATE = 48,
  VMSTAT_PGFAULT = 49,
  VMSTAT_PGMAJFAULT = 50,
  VMSTAT_PGREFILL_DMA = 51,
  VMSTAT_PGREFILL_NORMAL = 52,
  VMSTAT_PGREFILL_MOVABLE = 53,
  VMSTAT_PGSTEAL_KSWAPD_DMA = 54,
  VMSTAT_PGSTEAL_KSWAPD_NORMAL = 55,
  VMSTAT_PGSTEAL_KSWAPD_MOVABLE = 56,
  VMSTAT_PGSTEAL_DIRECT_DMA = 57,
  VMSTAT_PGSTEAL_DIRECT_NORMAL = 58,
  VMSTAT_PGSTEAL_DIRECT_MOVABLE = 59,
  VMSTAT_PGSCAN_KSWAPD_DMA = 60,
  VMSTAT_PGSCAN_KSWAPD_NORMAL = 61,
  VMSTAT_PGSCAN_KSWAPD_MOVABLE = 62,
  VMSTAT_PGSCAN_DIRECT_DMA = 63,
  VMSTAT_PGSCAN_DIRECT_NORMAL = 64,
  VMSTAT_PGSCAN_DIRECT_MOVABLE = 65,
  VMSTAT_PGSCAN_DIRECT_THROTTLE = 66,
  VMSTAT_PGINODESTEAL = 67,
  VMSTAT_SLABS_SCANNED = 68,
  VMSTAT_KSWAPD_INODESTEAL = 69,
  VMSTAT_KSWAPD_LOW_WMARK_HIT_QUICKLY = 70,
  VMSTAT_KSWAPD_HIGH_WMARK_HIT_QUICKLY = 71,
  VMSTAT_PAGEOUTRUN = 72,
  VMSTAT_ALLOCSTALL = 73,
  VMSTAT_PGROTATED = 74,
  VMSTAT_DROP_PAGECACHE = 75,
  VMSTAT_DROP_SLAB = 76,
  VMSTAT_PGMIGRATE_SUCCESS = 77,
  VMSTAT_PGMIGRATE_FAIL = 78,
  VMSTAT_COMPACT_MIGRATE_SCANNED = 79,
  VMSTAT_COMPACT_FREE_SCANNED = 80,
  VMSTAT_COMPACT_ISOLATED = 81,
  VMSTAT_COMPACT_STALL = 82,
  VMSTAT_COMPACT_FAIL = 83,
  VMSTAT_COMPACT_SUCCESS = 84,
  VMSTAT_COMPACT_DAEMON_WAKE = 85,
  VMSTAT_UNEVICTABLE_PGS_CULLED = 86,
  VMSTAT_UNEVICTABLE_PGS_SCANNED = 87,
  VMSTAT_UNEVICTABLE_PGS_RESCUED = 88,
  VMSTAT_UNEVICTABLE_PGS_MLOCKED = 89,
  VMSTAT_UNEVICTABLE_PGS_MUNLOCKED = 90,
  VMSTAT_UNEVICTABLE_PGS_CLEARED = 91,
  VMSTAT_UNEVICTABLE_PGS_STRANDED = 92,
  VMSTAT_NR_ZSPAGES = 93,
  VMSTAT_NR_ION_HEAP = 94,
  VMSTAT_NR_GPU_HEAP = 95,
  VMSTAT_ALLOCSTALL_DMA = 96,
  VMSTAT_ALLOCSTALL_MOVABLE = 97,
  VMSTAT_ALLOCSTALL_NORMAL = 98,
  VMSTAT_COMPACT_DAEMON_FREE_SCANNED = 99,
  VMSTAT_COMPACT_DAEMON_MIGRATE_SCANNED = 100,
  VMSTAT_NR_FASTRPC = 101,
  VMSTAT_NR_INDIRECTLY_RECLAIMABLE = 102,
  VMSTAT_NR_ION_HEAP_POOL = 103,
  VMSTAT_NR_KERNEL_MISC_RECLAIMABLE = 104,
  VMSTAT_NR_SHADOW_CALL_STACK_BYTES = 105,
  VMSTAT_NR_SHMEM_HUGEPAGES = 106,
  VMSTAT_NR_SHMEM_PMDMAPPED = 107,
  VMSTAT_NR_UNRECLAIMABLE_PAGES = 108,
  VMSTAT_NR_ZONE_ACTIVE_ANON = 109,
  VMSTAT_NR_ZONE_ACTIVE_FILE = 110,
  VMSTAT_NR_ZONE_INACTIVE_ANON = 111,
  VMSTAT_NR_ZONE_INACTIVE_FILE = 112,
  VMSTAT_NR_ZONE_UNEVICTABLE = 113,
  VMSTAT_NR_ZONE_WRITE_PENDING = 114,
  VMSTAT_OOM_KILL = 115,
  VMSTAT_PGLAZYFREE = 116,
  VMSTAT_PGLAZYFREED = 117,
  VMSTAT_PGREFILL = 118,
  VMSTAT_PGSCAN_DIRECT = 119,
  VMSTAT_PGSCAN_KSWAPD = 120,
  VMSTAT_PGSKIP_DMA = 121,
  VMSTAT_PGSKIP_MOVABLE = 122,
  VMSTAT_PGSKIP_NORMAL = 123,
  VMSTAT_PGSTEAL_DIRECT = 124,
  VMSTAT_PGSTEAL_KSWAPD = 125,
  VMSTAT_SWAP_RA = 126,
  VMSTAT_SWAP_RA_HIT = 127,
  VMSTAT_WORKINGSET_RESTORE = 128,
};
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_COMMON_SYS_STATS_COUNTERS_PROTO_CPP_H_

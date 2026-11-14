# Supporting Structures in System Design

These structures appear in system-design interviews because they trade memory, consistency, and update cost for lower latency or less storage. The goal is to explain their role and failure modes, not implement a production storage engine.

## Cache

A cache keeps frequently used results closer to callers. An eviction policy (such as LRU or LFU) decides what leaves when capacity is reached.

- **Use when:** reads are repeated and stale data can be bounded or tolerated.
- **Trade-offs:** hit rate versus memory; invalidation complexity; hot-key concentration; cache stampedes.
- **Interview note:** define TTL, invalidation, and behavior on cache miss or outage.

## Bloom filter

A Bloom filter is a space-efficient probabilistic set-membership structure. It can report false positives but not false negatives, assuming insertions are recorded correctly.

- **Use when:** a cheap negative check can avoid an expensive lookup.
- **Trade-offs:** false-positive rate versus memory and number of hash functions; it cannot enumerate keys or delete entries in its basic form.
- **Interview note:** a positive result still requires checking the source of truth.

## B-tree and B+ tree indexes

B-trees keep keys in sorted multiway nodes, reducing tree height and storage-page reads. B+ trees keep records or record pointers in leaves and link leaves for ordered scans.

- **Use when:** storage engines need indexed lookups and range scans over disk or pages.
- **Trade-offs:** writes maintain sorted structure; indexes consume storage and add write amplification.
- **Interview note:** distinguish an index's lookup path from the primary data record.

## Log-structured merge trees

An LSM tree buffers writes in memory and flushes sorted runs to disk, later merging them. Reads may consult multiple levels and use filters to skip runs.

- **Use when:** write throughput is prioritized and compaction can run asynchronously.
- **Trade-offs:** write amplification and compaction compete with foreground work; reads can be slower without caches or filters.
- **Interview note:** compare read/write mix and durability needs rather than calling one storage layout universally faster.

Related: [Caches and queues in the system-design toolbox](../system-design/building-blocks.md), [hash tables](./hash-tables.md), and [trees](./trees.md).

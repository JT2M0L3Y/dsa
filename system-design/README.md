# System Design Interviews

System-design interviews assess how you clarify requirements, shape a system, and explain trade-offs. They are conversations, not a search for one universally correct architecture.

## A repeatable interview approach

1. **Clarify scope:** users, core use cases, what is explicitly out of scope.
2. **Set requirements:** functional behavior plus availability, latency, durability, privacy, and consistency needs.
3. **Estimate scale:** state assumptions; estimate peak request rates, storage growth, and bandwidth only as precisely as useful.
4. **Define interfaces and data:** APIs, key entities, ownership, and access patterns.
5. **Draw the high-level design:** request path, storage, asynchronous work, and trust boundaries.
6. **Deep-dive on bottlenecks:** partitioning, replication, caching, queues, hot keys, and failure handling.
7. **Compare trade-offs:** explain what the proposed design optimizes and what it makes harder.

Do not begin with a list of fashionable technologies. Tie each component to a requirement or workload. Numbers are estimates, not promises: show the assumptions and revise them when requirements change.

## Building blocks

[System-design building blocks](./building-blocks.md) summarizes common components and their trade-offs.

## Worked case studies

Each case uses a consistent interview walkthrough: requirements, rough estimates, APIs/data model, architecture, scaling choices, failure modes, and trade-offs.

- [URL shortener](./case-studies/url-shortener.md)
- [Chat and messaging](./case-studies/chat-messaging.md)
- [Rate limiter](./case-studies/rate-limiter.md)
- [File storage](./case-studies/file-storage.md)
- [News feed](./case-studies/news-feed.md)
- [Video streaming](./case-studies/video-streaming.md)
- [Ride sharing](./case-studies/ride-sharing.md)
- [E-commerce](./case-studies/e-commerce.md)

The examples are deliberately language-neutral. Use the diagrams to explain component boundaries, then adapt scale and consistency choices to the interview's clarified requirements.

Related: [data structures](../data-structures/README.md), [algorithms](../algorithms/README.md), and [DSA relationship diagrams](../diagrams/README.md).

# System Design Roadmap for SDE 2

> A comprehensive guide covering everything an SDE-2 needs to master for system design interviews and day-to-day work.

---

## Table of Contents
1. [Prerequisites – Core Computer Science Fundamentals](#1-prerequisites--core-computer-science-fundamentals)
2. [Networking Fundamentals](#2-networking-fundamentals)
3. [Operating Systems & Concurrency](#3-operating-systems--concurrency)
4. [Databases – SQL & NoSQL](#4-databases--sql--nosql)
5. [Caching](#5-caching)
6. [Distributed Systems Concepts](#6-distributed-systems-concepts)
7. [Design Patterns for Scalable Systems](#7-design-patterns-for-scalable-systems)
8. [AI / ML System Design](#8-ai--ml-system-design)
9. [System Design Building Blocks](#9-system-design-building-blocks)
10. [Real-World Case Studies](#10-real-world-case-studies)
11. [Mock Interviews & Practice](#11-mock-interviews--practice)
12. [Complete Book List](#12-complete-book-list)
13. [YouTube References](#13-youtube-references)

---

## 1. Prerequisites – Core Computer Science Fundamentals

### Topics to Master
| Topic | Details |
|-------|---------|
| **Data Structures** | Arrays, Linked Lists, Trees, Graphs, Hash Tables, Heaps, Tries |
| **Algorithms** | Sorting, Searching, BFS/DFS, Topological Sort, Dijkstra, Dynamic Programming |
| **Time & Space Complexity** | Big O, Amortized Analysis |
| **OOP & SOLID** | Inheritance, Polymorphism, Encapsulation, Abstraction, SOLID Principles |

### Books
- "Cracking the Coding Interview" – Gayle Laakmann McDowell
- "Introduction to Algorithms" (CLRS) – Chapters 1–15, 22–26

### YouTube
- [freeCodeCamp – Data Structures & Algorithms](https://www.youtube.com/watch?v=8hly31xKli0)
- [Abdul Bari – Algorithms Playlist](https://www.youtube.com/playlist?list=PLDN4rrl48XKpZkf03iYFl-O29szjTr3_O)

---

## 2. Networking Fundamentals

### Topics to Master
| Topic | Details |
|-------|---------|
| **OSI & TCP/IP Model** | Layers, encapsulation, PDU |
| **HTTP/HTTPS** | Methods, status codes, headers, cookies, sessions |
| **TCP vs UDP** | Handshake, reliability, flow control, congestion control |
| **DNS** | Resolution process, caching, TLD, authoritative nameservers |
| **CDN** | Edge servers, origin pull/push, caching strategies |
| **Load Balancers** | L4 vs L7, round-robin, least connections, weighted |
| **WebSockets** | Full-duplex communication, upgrade handshake |
| **API Protocols** | REST, gRPC, GraphQL – when to use what |

### Books
- "Computer Networking: A Top-Down Approach" – Kurose & Ross

### YouTube
- [Kurose & Ross Lectures](https://www.youtube.com/user/kuroseross)
- [freeCodeCamp – Computer Networking Course](https://www.youtube.com/watch?v=3QhU9jd03a0)

---

## 3. Operating Systems & Concurrency

### Topics to Master
| Topic | Details |
|-------|---------|
| **Process vs Thread** | Context switch, PCB, TCB |
| **Concurrency & Parallelism** | Race conditions, deadlocks, critical sections |
| **Threading Models** | 1:1, M:N, goroutines |
| **Locking** | Mutex, semaphore, read-write lock, spinlock |
| **Atomic Operations** | CAS, fetch-and-add, memory barriers |
| **Scheduling** | FCFS, Round Robin, Shortest Job Next |
| **Memory Management** | Paging, segmentation, virtual memory, TLB |
| **I/O Models** | Blocking, non-blocking, multiplexing (select/epoll/kqueue), async |

### Books
- "Operating Systems: Three Easy Pieces" – Remzi Arpaci-Dusseau (FREE online)
- "Java Concurrency in Practice" – Brian Goetz

### YouTube
- [MIT 6.004 – Operating Systems](https://www.youtube.com/playlist?list=PL8EC1756A7B1764F6)
- [Tech Dummies – Concurrency](https://www.youtube.com/watch?v=oV9rvDllK-k)

---

## 4. Databases – SQL & NoSQL

### Topics to Master

#### SQL (Relational Databases)
| Topic | Details |
|-------|---------|
| **Indexing** | B-Tree, Hash indexes, covering indexes, composite indexes |
| **ACID** | Atomicity, Consistency, Isolation, Durability |
| **Isolation Levels** | Read Uncommitted → Serializable (with phantom reads, dirty reads) |
| **Normalization** | 1NF → 3NF, denormalization trade-offs |
| **Query Optimization** | EXPLAIN, query plans, slow query analysis |
| **Transactions** | BEGIN/COMMIT, rollback, savepoints |
| **Connection Pooling** | HikariCP, pgBouncer |

#### NoSQL Databases
| Type | Examples | Use Cases |
|------|----------|-----------|
| **Key-Value** | Redis, DynamoDB | Caching, sessions, leaderboards |
| **Document** | MongoDB, Firestore | Flexible schemas, catalogs |
| **Column-Family** | Cassandra, HBase | Time-series, IoT, write-heavy apps |
| **Graph** | Neo4j, Dgraph | Recommendations, social graphs |
| **Time-Series** | InfluxDB, TimescaleDB | Metrics, monitoring |

#### Important Trade-offs
| Topic | Key Idea |
|-------|----------|
| **Sharding** | Horizontal partitioning, hash-based vs range-based |
| **Replication** | Leader-follower, leaderless, quorum reads/writes |
| **CAP Theorem** | Consistency vs Availability vs Partition Tolerance |
| **PACELC** | Trade-off under normal conditions too |
| **BASE** | Basically Available, Soft state, Eventually consistent |

### Books
- "Designing Data-Intensive Applications" – Martin Kleppmann **(MUST READ)**
- "High Performance MySQL" – Baron Schwartz

### YouTube
- [Gaurav Sen – Database Series](https://www.youtube.com/playlist?list=PLMCXHnjXnTnvSXK7bCCfeoG4lY6U2CzR6)
- [Hussein Nasser – Database Engineering](https://www.youtube.com/c/HusseinNasser-software-engineering)

---

## 5. Caching

### Topics to Master
| Topic | Details |
|-------|---------|
| **Cache Strategies** | Cache Aside, Read-Through, Write-Through, Write-Behind, Refresh-Ahead |
| **Eviction Policies** | LRU, LFU, FIFO, TTL-based |
| **Redis** | Data structures, persistence (RDB/AOF), sentinel, cluster |
| **Memcached** | Simple key-value, no persistence, slab allocator |
| **Cache Invalidation** | Write-invalidate, write-update, TTL |
| **Distributed Caching** | Consistent hashing, gossip protocol |
| **Application Caching** | HTTP caching (ETag, Cache-Control), CDN caching |
| **Caching Pitfalls** | Cache stampede, thundering herd, cold start |

### Books
- "Redis in Action" – Josiah L. Carlson
- "Designing Data-Intensive Applications" (caching chapters)

### YouTube
- [Redis Explained – ByteByteGo](https://www.youtube.com/watch?v=OqCK0ASqEMo)
- [System Design – Cache](https://www.youtube.com/watch?v=U3RkDLtS7uY)

---

## 6. Distributed Systems Concepts

### Topics to Master
| Topic | Details |
|-------|---------|
| **Consistent Hashing** | Virtual nodes, ring, used in DynamoDB, Cassandra |
| **Gossip Protocol** | Epidemic broadcast, convergence, failure detection |
| **Quorum** | Read/write quorum, sloppy quorum, hinted handoff |
| **Vector Clocks** | Causality tracking, conflict resolution |
| **Distributed Consensus** | Paxos, Raft, Zab |
| **Leader Election** | Bully algorithm, Raft leader election |
| **Distributed Transactions** | 2PC, 3PC, Saga pattern |
| **Distributed ID Generation** | Snowflake, UUID v7, MongoDB ObjectID |
| **CQRS & Event Sourcing** | Command-query segregation, event store, replay |
| **Bloom Filters** | Probabilistic data structures, false positives |
| **Rate Limiting** | Token bucket, leaky bucket, sliding window |
| **Monitoring** | Metrics (RED/USE), tracing (Jaeger), logging (ELK) |

### Books
- "Designing Data-Intensive Applications" – Martin Kleppmann **(BIBLE)**
- "Distributed Systems" – Maarten van Steen (FREE online)

### YouTube
- [MIT 6.824 – Distributed Systems (Raft)](https://www.youtube.com/watch?v=64Zp3tzNbpE)
- [ByteByteGo – Distributed Systems](https://www.youtube.com/c/ByteByteGo)
- [Raft Visualization](https://raft.github.io/)

---

## 7. Design Patterns for Scalable Systems

### Topics to Master
| Pattern | Description |
|---------|-------------|
| **Circuit Breaker** | Prevent cascading failures (Hystrix, Resilience4J) |
| **Bulkhead** | Isolate resources into pools |
| **Retry with Backoff** | Exponential backoff + jitter |
| **Event-Driven Architecture** | Events, producers, consumers, brokers |
| **Event Sourcing** | State as sequence of events |
| **Saga** | Choreography vs orchestration for distributed transactions |
| **Strangler Fig** | Incrementally migrate monolith to microservices |
| **Sidecar / Ambassador** | Proxy side-by-side with service (Envoy, Linkerd) |
| **CQRS** | Separate read and write models |
| **Throttling** | Rate limiting at application layer |

### Books
- "Design Patterns: Elements of Reusable Object-Oriented Software" – GoF
- "Microservices Patterns" – Chris Richardson

### YouTube
- [Chris Richardson – Microservices Patterns](https://www.youtube.com/watch?v=OoN7uP0mIZE)
- [Gaurav Sen – System Design Patterns](https://www.youtube.com/playlist?list=PLMCXHnjXnTnsL4PHHvsoo6z7-2QRIF7-i)

---

## 8. AI / ML System Design

### Topics to Master

| Topic | Details |
|-------|---------|
| **Vector Databases** | Embeddings, ANN search, HNSW, IVF, cosine similarity – Pinecone, Weaviate, Milvus, Qdrant |
| **RAG Architecture** | Retrieval-Augmented Generation: chunking, embedding, indexing, retrieval, reranking |
| **LLM Serving** | Model inference serving (vLLM, TGI, Triton), batching (continuous batching), quantization (GPTQ, AWQ, GGUF), KV-cache |
| **Prompt Engineering** | System prompts, few-shot, chain-of-thought, structured output, safety guardrails |
| **Recommendation Systems** | Collaborative filtering, content-based, matrix factorization, two-tower model, feature store |
| **Search Ranking** | Learning to Rank (LTR), feature engineering, real-time inference |
| **Model Training Pipelines** | Data pipeline (ETL, feature engineering), distributed training (FSDP, DeepSpeed), experiment tracking (MLflow, Weights & Biases) |
| **Feature Store** | Feast, Tecton – online vs offline features, feature serving, point-in-time joins |
| **Model Registry & Versioning** | MLflow, DVC, model lineage, staging → production promotion |
| **Model Monitoring** | Data drift, concept drift, prediction monitoring, explainability (SHAP, LIME) |
| **A/B Testing** | Experimentation framework, statistical significance, MAB (Multi-Armed Bandit) |
| **GPU Infrastructure** | CUDA, NCCL, GPU memory management, multi-GPU inference, spot instances |
| **Content Moderation** | NSFW detection, toxicity filtering, image/video moderation using ML models |
| **Search & Autocomplete** | Trie-based, Elasticsearch suggesters, ML-based ranking |
| **Personalization** | User embeddings, real-time feature computation, personalization at edge vs server |

### Books
- "Designing Machine Learning Systems" – Chip Huyen
- "Machine Learning Engineering" – Andriy Burkov
- "Recommendation Systems: The Textbook" – Charu Aggarwal
- "Speech and Language Processing" – Jurafsky & Martin (NLP fundamentals)

### YouTube
- [Chip Huyen – ML System Design](https://www.youtube.com/watch?v=06oXU9cA6Tc)
- [MLOps.community](https://www.youtube.com/c/MLOpscommunity)
- [Stanford CS 329S – ML System Design](https://www.youtube.com/playlist?list=PLoROMvodv4rMpCO6h4n1lwI_W4zJ3QN1o)
- [Andrej Karpathy – Intro to LLMs](https://www.youtube.com/watch?v=zjkBMFhNj_g)
- [Umar Jamil – RAG from Scratch](https://www.youtube.com/watch?v=ihiksecI5sE)
- [AI Engineering YouTube](https://www.youtube.com/@aiengineeringyt)

### AI System Design Case Studies (In addition to §9)

| # | System | Key Concepts |
|---|--------|--------------|
| 1 | **Design ChatGPT / LLM Chatbot** | Stateless vs stateful, context window, streaming (SSE), token management, prompt caching, guardrails |
| 2 | **Design RAG System** | Chunking strategy, embedding model, vector DB, hybrid search (BM25 + vector), reranking, citation |
| 3 | **Design YouTube Recommendations** | Two-tower retrieval, candidate generation, ranking, re-ranking, exploration vs exploitation |
| 4 | **Design Netflix Recommendations** | Collaborative filtering, matrix factorization, contextual bandits, A/B testing at scale |
| 5 | **Design Google Search** | Crawler, inverted index, PageRank, query understanding, ranking signals, BERT for search |
| 6 | **Design Content Moderation System** | Image/video pipeline, NSFW classifiers, LLM-based text moderation, human-in-the-loop, async queues |
| 7 | **Design Autocomplete / Typeahead** | Trie, frequency-based ranking, ML-enhanced suggestion, personalization, caching |
| 8 | **Design Fraud Detection System** | Real-time scoring, feature engineering, ensemble models, rule engine + ML, feature store, stream processing |
| 9 | **Design E-Commerce Search** | Query understanding, typo tolerance, synonym expansion, faceted search, ranking with CTR features |
| 10 | **Design Image Search** | CLIP embeddings, multimodal retrieval, vector DB, hybrid with text metadata |

### YouTube for AI Case Studies
- [Chip Huyen – Real-World ML System Design](https://www.youtube.com/watch?v=06oXU9cA6Tc)
- [Umar Jamil – AI Engineering](https://www.youtube.com/@umarjamilai)
- [Stanford CS 329S](https://www.youtube.com/playlist?list=PLoROMvodv4rMpCO6h4n1lwI_W4zJ3QN1o)
- [Eugene Yan – ML Systems](https://eugeneyan.com/writing/)

---

## 9. System Design Building Blocks

### Topics to Master (in order of priority)

| # | Building Block | What to Know |
|---|---------------|--------------|
| 1 | **URL Shortener** | Hash generation, Base62 encoding, redirection, analytics |
| 2 | **Rate Limiter** | Token bucket, sliding window, distributed counter (Redis) |
| 3 | **Chat System** | WebSockets, presence, message ordering, history |
| 4 | **Unique ID Generator** | Snowflake, UUID, database-backed sequences |
| 5 | **Distributed Cache** | Consistent hashing, replication, eviction |
| 6 | **Distributed Queue** | Kafka vs RabbitMQ, partitions, consumer groups |
| 7 | **Distributed File System** | HDFS, Google File System concepts |
| 8 | **Distributed Search** | Elasticsearch, inverted indexes, sharding |
| 9 | **Notification System** | Push, pull, WebSocket, SMS, email, 3rd-party integrations |
| 10 | **Payment System** | Idempotency, 2PC, reconciliation, ledger |
| 11 | **Distributed Lock** | ZooKeeper, Redis Redlock, etcd |
| 12 | **Metrics & Monitoring** | Prometheus, Grafana, data model, scrape vs push |

### YouTube
- [System Design Building Block Playlist](https://www.youtube.com/playlist?list=PLMCXHnjXnTnvo6alSjVkgxV-VH6EPyvoX)
- [ByteByteGo – Building Blocks](https://www.youtube.com/c/ByteByteGo)

---

## 10. Real-World Case Studies

### Must-Know Designs (Including AI)

| # | System | Key Concepts | AI Aspects |
|---|--------|--------------|------------|
| 1 | **Design TinyURL / Bitly** | Hash function, Base62, redirection, analytics | — |
| 2 | **Design YouTube / Netflix** | Video upload pipeline, transcoding, CDN, pre-signed URLs, adaptive bitrate (HLS/DASH) | Recommendation system, content understanding, thumbnail selection |
| 3 | **Design Twitter / Feed** | Fan-out (push/pull), timeline, timeline cache, news feed generation | Ranking model, relevance scoring, trending topics algorithm |
| 4 | **Design Uber / Lyft** | Geohashing, QuadTrees, real-time dispatch, ETA calculation | ETA prediction, ETD prediction, fraud detection |
| 5 | **Design WhatsApp / Messenger** | End-to-end encryption, message ordering, persistent connections | Spam detection, smart replies, message translation |
| 6 | **Design Instagram** | Photo upload, feed, stories, hashtags, follower graph | Content recommendation, explore page ranking, image moderation |
| 7 | **Design Amazon / E-commerce** | Product catalog, shopping cart, order processing, payment | Product recommendations, search ranking, fraud detection, demand forecasting |
| 8 | **Design Dropbox / Google Drive** | File sync, chunking, delta sync, conflict resolution | OCR, document classification, duplicate detection |
| 9 | **Design Web Crawler** | BFS frontier, politeness, deduplication (Bloom filter), URL normalization | Content classification, spam detection, relevance scoring |
| 10 | **Design Yelp / Nearby Places** | Geohashing, spatial indexes, location-based search | Personalization, review sentiment analysis, recommendation |
| 11 | **Design Ticketmaster** | Concurrency control, optimistic locking, seat allocation | Dynamic pricing, demand prediction, bot detection |
| 12 | **Design Google Docs / Collab Editor** | CRDT vs OT, operational transformation, conflict resolution | Smart compose, grammar correction, summarization |
| 13 | **Design Tinder** | Swipe logic, geolocation, real-time matching | Recommendation model (ELO-like), smart photos, anti-bot |
| 14 | **Design Reddit / Hacker News** | Voting, hot ranking algorithm (Hacker News, Reddit), comment tree | Content moderation (toxicity), personalized feed ranking, trending detection |
| 15 | **Design API Rate Limiter** | Token bucket, distributed counters, per-user throttling | Anomaly detection, adaptive rate limiting using ML |

### YouTube
- [Gaurav Sen – System Design Playlist](https://www.youtube.com/playlist?list=PLMCXHnjXnTnvo6alSjVkgxV-VH6EPyvoX)
- [ByteByteGo – System Design Playlist](https://www.youtube.com/playlist?list=PLQnljOFTspQXjD0GwsgQL-NIhTz_Hg8Lb)
- [System Design Interview – Jordan has no life](https://www.youtube.com/@jordanhasnolife5163)
- [System Design Fight Club](https://www.youtube.com/c/SystemDesignFightClub)
- [Think Software](https://www.youtube.com/@ThinkSoftware)

---

## 11. Mock Interviews & Practice

### Platforms
| Platform | Link | Features |
|----------|------|----------|
| **Pramp** | https://www.pramp.com | Free peer mock interviews |
| **InterviewBit – System Design** | https://www.interviewbit.com/courses/system-design | Structured curriculum |
| **Grokking the System Design Interview** | https://www.designgurus.org | Premium course, highly recommended |
| **System Design Primer (GitHub)** | https://github.com/donnemartin/system-design-primer | Free, open-source, comprehensive |
| **LeetCode – System Design** | https://leetcode.com/discuss/interview-question/system-design | Community solutions |
| **Hello Interview** | https://www.hellointerview.com | AI mock interviews + solutions |
| **Exponent** | https://www.tryexponent.com | Mock interviews with FAANG engineers |
| **System Design (Alex Xu)** | https://bytebytego.com | Courses + cheat sheets |
| **High Scalability** | http://highscalability.com | Real-world architecture breakdowns |
| **InfoQ Architecture** | https://www.infoq.com/architecture-design | Conference talks, case studies |

### How to Approach Any System Design Question

**Step 1 – Clarify Requirements**
- Functional requirements (features)
- Non-functional requirements (scale, latency, availability, consistency, durability)
- DAU, MAU, read/write ratio, traffic estimates

**Step 2 – Back-of-the-Envelope Calculations**
- Traffic estimates (QPS, bandwidth, storage)
- Storage estimates (per record × #records × replication factor)
- Cache sizing
- Use powers of 2 table (KB, MB, GB, TB, PB)

**Step 3 – High-Level Design**
- Box-and-arrow diagram
- Key components (client → CDN → LB → API Gateway → Microservices → DB/Cache)

**Step 4 – Deep Dive – Database Schema**
- Entities, relationships, indexes
- SQL vs NoSQL justification
- Sharding key selection

**Step 5 – Deep Dive – Key Component**
- Pick 1–2 interesting components (feed generation, rate limiter, search)
- Explain internal algorithm, data structures, trade-offs

**Step 6 – Reliability, Scalability, Availability**
- Single points of failure
- Replication, failover, retry, circuit breaker
- Horizontal scaling plan

**Step 7 – Wrap Up / Trade-offs**
- What would you do differently given more time?
- Alternative approaches considered

---

## 12. Complete Book List

### Core System Design (Start Here)
| # | Book | Author | Why |
|---|------|--------|-----|
| 1 | **Designing Data-Intensive Applications** | Martin Kleppmann | **The Bible.** Read cover-to-cover. |
| 2 | **System Design Interview – Vol 1 & 2** | Alex Xu | Practical interview walkthroughs |
| 3 | **The System Design Primer** (GitHub) | Donne Martin | Free high-level primer |
| 4 | **Grokking the System Design Interview** | DesignGurus | Structured course format |

### Distributed Systems
| # | Book | Author |
|---|------|--------|
| 1 | **Distributed Systems** | Maarten van Steen (FREE) |
| 2 | **Distributed Systems: Principles and Paradigms** | Tanenbaum & Van Steen |
| 3 | **Distributed Computing: Principles, Algorithms, and Systems** | Ajay D. Kshemkalyani |

### Databases
| # | Book | Author |
|---|------|--------|
| 1 | **High Performance MySQL** | Baron Schwartz |
| 2 | **Redis in Action** | Josiah L. Carlson |
| 3 | **MongoDB: The Definitive Guide** | Kristina Chodorow |
| 4 | **Cassandra: The Definitive Guide** | Eben Hewitt |

### Microservices & Architecture
| # | Book | Author |
|---|------|--------|
| 1 | **Microservices Patterns** | Chris Richardson |
| 2 | **Building Microservices** | Sam Newman |
| 3 | **Clean Architecture** | Robert C. Martin |
| 4 | **Fundamentals of Software Architecture** | Mark Richards & Neal Ford |

### Cloud & DevOps
| # | Book | Author |
|---|------|--------|
| 1 | **AWS Certified Solutions Architect – Official Study Guide** | Ben Piper |
| 2 | **Site Reliability Engineering (Google SRE Book)** | Betsy Beyer et al. (FREE online) |
| 3 | **The DevOps Handbook** | Gene Kim et al. |
| 4 | **The Phoenix Project** | Gene Kim (novel about DevOps) |

### Algorithms & CS Fundamentals
| # | Book | Author |
|---|------|--------|
| 1 | **Introduction to Algorithms (CLRS)** | Cormen, Leiserson, Rivest, Stein |
| 2 | **The Algorithm Design Manual** | Steven Skiena |
| 3 | **Operating Systems: Three Easy Pieces** | Remzi Arpaci-Dusseau (FREE) |
| 4 | **Computer Networking: A Top-Down Approach** | Kurose & Ross |

---

## 13. YouTube References

### Top YouTube Channels for System Design

| Channel | Link | Best For |
|---------|------|----------|
| **Gaurav Sen** | [System Design Playlist](https://www.youtube.com/playlist?list=PLMCXHnjXnTnvo6alSjVkgxV-VH6EPyvoX) | Case studies, building blocks, detailed explanations |
| **ByteByteGo** | [ByteByteGo](https://www.youtube.com/c/ByteByteGo) | Animated explanations, concise, visual |
| **Hussein Nasser** | [Hussein Nasser](https://www.youtube.com/c/HusseinNasser-software-engineering) | Networking, databases, deep fundamentals |
| **Jordan has no life** | [System Design Interview](https://www.youtube.com/@jordanhasnolife5163) | FAANG mock interviews, whiteboard |
| **System Design Fight Club** | [SDFC](https://www.youtube.com/c/SystemDesignFightClub) | Real interview experience |
| **Think Software** | [Think Software](https://www.youtube.com/@ThinkSoftware) | Clean explanations, scalability concepts |
| **Concept && Coding** | [Concept && Coding](https://www.youtube.com/@conceptandcoding) | Building blocks, Java focused |
| **Tech Dummies** | [Tech Dummies](https://www.youtube.com/c/TechDummiesNarendraL) | System design case studies |
| **Nick White** | [Nick White](https://www.youtube.com/@NickWhite) | LeetCode + System Design prep strategies |
| **SDE Skills** | [SDE Skills](https://www.youtube.com/@sdeskills) | Indian context, interview-focused |

### Essential Individual Videos

| Topic | Video |
|-------|-------|
| CAP Theorem | [Gaurav Sen – CAP Theorem](https://www.youtube.com/watch?v=YvS4E5LtTDo) |
| Consistent Hashing | [ByteByteGo – Consistent Hashing](https://www.youtube.com/watch?v=UF9Iqmg94tk) |
| Design YouTube | [Gaurav Sen – YouTube Design](https://www.youtube.com/watch?v=OqCK0ASqEMo) |
| Design Twitter | [ByteByteGo – Twitter](https://www.youtube.com/watch?v=o5n85GRbQOY) |
| Design Uber | [Gaurav Sen – Uber](https://www.youtube.com/watch?v=umWABiC0Q3A) |
| Design WhatsApp | [System Design – WhatsApp](https://www.youtube.com/watch?v=vvhC7hVHbUo) |
| Design URL Shortener | [ByteByteGo – TinyURL](https://www.youtube.com/watch?v=AVM73ao5_CI) |
| Rate Limiting | [Gaurav Sen – Rate Limiting](https://www.youtube.com/watch?v=FU4WmWE6GNY) |
| Transactions & ACID | [Hussein Nasser – ACID](https://www.youtube.com/watch?v=GAe5oB742dw) |
| Raft Consensus | [MIT 6.824 – Raft](https://www.youtube.com/watch?v=64Zp3tzNbpE) |
| Distributed Systems Playlist | [MIT 6.824 Full Course](https://www.youtube.com/playlist?list=PLrw6a1wE39_tb2fErI4-WkMbsvGQk9O4A) |
| Reverse Proxy vs Load Balancer | [ByteByteGo – Reverse Proxy vs LB](https://www.youtube.com/watch?v=S8J2fkN2U4c) |
| Kafka Deep Dive | [Gaurav Sen – Kafka](https://www.youtube.com/watch?v=J2M0-eMCJ0M) |
| SQL vs NoSQL | [Gaurav Sen – SQL vs NoSQL](https://www.youtube.com/watch?v=Q5aTUc7c4jg) |

---

## Quick Start (1 Month) – Bare Minimum to Start

| Week | Focus | Tasks |
|------|-------|-------|
| **1** | DSA Review + Networking | CLRS ch 10–15, Kurose ch 1–3 |
| **2** | Databases + CAP Theorem | DDIA ch 1–6, B-tree indexing, ACID |
| **3** | Scalability Basics + Caching | DDIA ch 7–9, consistent hashing, Redis |
| **4** | 3 Case Studies + Mock | Design URL Shortener, Chat, YouTube |

## Intermediate (2–3 Months)

| Week | Focus |
|------|-------|
| 5–6 | Distributed Systems (DDIA ch 9–12) + Consensus (Raft) |
| 7–8 | 5 More Case Studies (Twitter, Uber, WhatsApp, Instagram, Dropbox) |
| 9–10 | Microservices Patterns + Circuit Breaker, Saga, CQRS |
| 11–12 | Mock interviews (Pramp) + LeetCode system design discussions |

## AI/ML Books (in addition to §12)

| # | Book | Author |
|---|------|--------|
| 1 | **Designing Machine Learning Systems** | Chip Huyen |
| 2 | **Machine Learning Engineering** | Andriy Burkov |
| 3 | **Building LLM Apps** | Valentina Alto |
| 4 | **AI Engineering** | Chip Huyen |
| 5 | **Recommendation Systems: The Textbook** | Charu Aggarwal |

## AI/ML YouTube Channels (in addition to §13)

| Channel | Link | Best For |
|---------|------|----------|
| **Chip Huyen** | [ML System Design](https://www.youtube.com/watch?v=06oXU9cA6Tc) | Real-world ML systems |
| **Stanford CS 329S** | [ML System Design](https://www.youtube.com/playlist?list=PLoROMvodv4rMpCO6h4n1lwI_W4zJ3QN1o) | Academic ML system design |
| **Umar Jamil** | [AI Engineering](https://www.youtube.com/@umarjamilai) | RAG, LLMs, hands-on |
| **Andrej Karpathy** | [Neural Networks](https://www.youtube.com/@AndrejKarpathy) | Deep fundamentals of AI/LLMs |
| **AI Engineering** | [AI Engineering](https://www.youtube.com/@aiengineeringyt) | LLM ops, RAG, agents |
| **Sam Witteveen** | [NLP with Deep Learning](https://www.youtube.com/@samwitteveenai) | LLM fine-tuning, RAG |
| **Eugene Yan** | [Blog](https://eugeneyan.com/writing/) | ML systems at scale |
| **MLOps.community** | [YouTube](https://www.youtube.com/c/MLOpscommunity) | MLOps, deployment, monitoring |

## Advanced (3–6 Months)

| Focus | Goals |
|-------|-------|
| DDIA Cover-to-Cover (ch 1–12) | Master all distributed systems concepts |
| Designing Machine Learning Systems (Huyen) | Master ML system design end-to-end |
| All 15+ Classic Case Studies + 10 AI Case Studies | Draw from memory, explain trade-offs |
| Pramp / Exponent mocks | 10+ mock interviews |
| Real project at work | Apply patterns (circuit breaker, caching, sharding, RAG, feature store) |
| Contribute to OSS (Kafka, Redis, vLLM, etc.) | Deeper understanding of internals |

---

## Quick Reference – Key Formulas & Numbers

### Latency Numbers Every Programmer Should Know
| Operation | Time |
|-----------|------|
| L1 cache reference | 0.5 ns |
| Branch mispredict | 5 ns |
| L2 cache reference | 7 ns |
| Mutex lock/unlock | 25 ns |
| Main memory reference | 100 ns |
| Compress 1 KB with Zippy | 3,000 ns (3 µs) |
| Send 2 KB over 1 Gbps network | 20,000 ns (20 µs) |
| Read 1 MB sequentially from memory | 250,000 ns (250 µs) |
| Round trip within same datacenter | 500,000 ns (500 µs) |
| Disk seek | 10,000,000 ns (10 ms) |
| Read 1 MB sequentially from disk | 30,000,000 ns (30 ms) |
| Send packet CA → Netherlands → CA | 150,000,000 ns (150 ms) |

### Powers of 2 Table
| Power | Approx | Full Name |
|-------|--------|-----------|
| 10 | 1,000 | 1 KB |
| 20 | 10^6 | 1 MB |
| 30 | 10^9 | 1 GB |
| 40 | 10^12 | 1 TB |
| 50 | 10^15 | 1 PB |

### QPS Estimates for Popular Services
- Twitter: ~6,000 QPS (peak ~40k)
- Facebook: ~600,000 QPS (peak ~3M)
- WhatsApp: ~40,000 QPS
- Google Search: ~80,000 QPS
- YouTube: ~10,000 QPS (video searches)
- Netflix: ~400,000 QPS (streaming sessions)

---

> **Final Advice:** Read **Designing Data-Intensive Applications** twice. Watch **Gaurav Sen** and **ByteByteGo** case studies. Practice drawing on a whiteboard. Focus on trade-offs, not "correct" answers. The best SDE-2 engineers understand *why* a decision is made, not just *what* the decision is.

---

*Happy designing! 🚀*

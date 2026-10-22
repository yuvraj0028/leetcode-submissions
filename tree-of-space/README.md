# Tree of Space

Given a complete, balanced M-ary tree with `N` nodes and `Q` queries, implement the following operations. Each query returns `true` when the operation succeeds, otherwise `false`.

- `Lock(X, uid)` — Lock node `X` for user `uid`. It fails if `X` or any of its ancestors or descendants is already locked by any user.
- `Unlock(X, uid)` — Unlock node `X`. It succeeds only if `X` is locked by the same `uid`.
- `UpgradeLock(X, uid)` — Lock `X` on behalf of `uid` after unlocking its locked descendants. It fails if `X` is already locked, has a locked ancestor, has no locked descendants, or any locked descendant belongs to a different user.

## Input format

- First line: number of nodes `N`.
- Second line: number of children per node `m`.
- Third line: number of queries `Q`.
- Next `N` lines: node names (root first).
- Next `Q` lines: `operationType nodeName userId`, where operation type is `1` for lock, `2` for unlock, and `3` for upgrade.

## Implementations

| File | Strategy |
| --- | --- |
| `tree-of-space.cpp` | Basic single-threaded implementation |
| `tree-of-space-global-lock.cpp` | One global mutex for the whole tree |
| `tree-of-space-global-recursive-mutex.cpp` | Global recursive mutex |
| `tree-of-space-fine-grained-locking.cpp` | Per-node locks with ancestor/descendant tracking |

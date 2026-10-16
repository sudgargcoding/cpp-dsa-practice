# practice_cpp

A personal collection of **C++ solutions to data-structure and algorithm (DSA) problems**: HackerRank-style exercises, LeetCode/interview questions, and a handful of classic algorithm implementations written while learning and preparing for coding interviews.

The code is meant to be read and tinkered with. Each file is a small, self-contained solution to one problem or one algorithm, with no build system or external dependencies.

## Contents

- [Repository layout](#repository-layout)
- [Topics covered](#topics-covered)
- [Getting started](#getting-started)
- [Reading the solutions](#reading-the-solutions)
- [Known issues](#known-issues)
- [Contributing and feedback](#contributing-and-feedback)

## Repository layout

```
practice_cpp/
├── coding_probs_1/   # 13 files – interview problems (arrays, strings, DP, stack, design)
├── coding_probs_2/   # 19 files – graph traversals, string matching, tries/automata, caches, DP
├── coding_probs_3/   # 22 files – interview problems (BFS/DFS, heaps, sliding window, simulations)
├── .gitignore
└── README.md
```

Each file name describes the problem or algorithm (for example `lru.cpp`, `word_ladder_bfs.cpp`, `kmp.cpp`). Where a solution is based on a published problem, the first line of the file is a comment with the link to it (jointaro.com, algo.monster or leetcode.com).

## Topics covered

### `coding_probs_1/`
| Area | Files |
|------|-------|
| Dynamic programming | `robbers.cpp` (House Robber), `travel_cost.cpp` (Minimum Cost for Tickets) |
| Stack | `parenthesis.cpp` (Valid Parentheses), `path.cpp` (Simplify Path), `temperature.cpp` (Daily Temperatures) |
| Sliding window / hashing | `sliding_window.cpp` (Longest Substring Without Repeating Characters), `subarray_sum.cpp` (Subarray Sum Equals K) |
| Strings and number tricks | `palindrome.cpp` (Longest Palindromic Substring), `negabinary.cpp` (Adding Two Negabinary Numbers) |
| Greedy / matrix | `feed_hamsters.cpp` (Minimum Food Buckets), `reconstruct_2dmatrix.cpp` (Reconstruct a 2-Row Binary Matrix) |
| Design | `lru.cpp` (LRU Cache) |
| Scratch | `test.cpp` |

### `coding_probs_2/`
| Area | Files |
|------|-------|
| Graph traversal | `bfs.cpp`, `dfs.cpp`, `dfs_path.cpp` (max path sum in a tree), `cheapest_flight_bfs.cpp`, `cheapest_flight_2.cpp` (Cheapest Flights Within K Stops) |
| String matching | `kmp.cpp` (Knuth–Morris–Pratt), `rabin_karp.cpp` (rolling hash) |
| String data structures | `trie.cpp`, `suffix_tree.cpp` (naive suffix tree), `sam_suffix_automation.cpp` (suffix automaton) |
| Automata | `dfa_1.cpp` (DFA that checks whether a binary number is divisible by 3) |
| Caches | `lru.cpp`, `lfu.cpp` (LFU Cache) |
| Dynamic programming | `lcs1.cpp` (Longest Common Subsequence, memoized), `robber_1.cpp`, `robber_2.cpp` (House Robber variants) |
| Stack | `pathSimplifier.cpp`, `temperature.cpp` |
| Misc | `hello.cpp` (currently an identical copy of `kmp.cpp`) |

### `coding_probs_3/`
| Area | Files |
|------|-------|
| BFS / DFS on grids and graphs | `number_of_islands_bfs.cpp`, `number_islands_dfs.cpp`, `word_ladder_bfs.cpp`, `tree_traversal_bfs.cpp` (level order), `word_search.cpp` (Word Search II), `robot_roomcleaner.cpp` |
| Two pointers / sliding window | `trapped_water_2pointers.cpp` (Trapping Rain Water), `sliding_window.cpp` (Sliding Window Maximum) |
| Heaps | `kclosest.cpp` (K Closest Points to Origin), `merge_k_list_heap.cpp` (Merge k Sorted Lists), `meeting_rooms.cpp` (Meeting Rooms II) |
| Dynamic programming | `book_shelves.cpp` (Filling Bookcase Shelves), `longest_repeating.cpp` (Longest Repeating Substring), `prerp2.cpp` (LCS practice) |
| Parsing and strings | `calculator.cpp` (Basic Calculator), `atoi.cpp`, `alien_dic.cpp` (Verifying an Alien Dictionary), `log_comparator.cpp` (Reorder Data in Log Files), `version_comparee.cpp` (Compare Version Numbers) |
| Design and simulation | `elevator_state_machine.cpp` (elevator modelled as a state machine), `grab_file.cpp` (binary search on a sorted phonebook file) |
| Revision sheet | `preparation.cpp` (BFS, DFS, islands, binary search and more in one file) |

## Getting started

### Prerequisites
- A C++17-capable compiler: `g++` 9+ or `clang++` 10+ (Apple clang from Xcode Command Line Tools works).
- No other dependencies.

### Build and run a single solution
Compile one file at a time. There is no Makefile or CMake project.

```bash
git clone <repo-url>
cd practice_cpp

g++ -std=c++17 -Wall -Wextra -o /tmp/lru coding_probs_2/lru.cpp
/tmp/lru
```

Swap in any file that contains a `main()`, for example:

```bash
g++ -std=c++17 -o /tmp/kmp  coding_probs_2/kmp.cpp  && /tmp/kmp
g++ -std=c++17 -o /tmp/trie coding_probs_2/trie.cpp && /tmp/trie
```

### Files that read input files
`coding_probs_3/grab_file.cpp` searches a sorted `phonebook.txt` in the current directory. Create that file first, with one `name phone` entry per line, sorted by name, then run the binary from the same directory.

## Reading the solutions

There are three kinds of files:

1. **Runnable programs.** These have a `main()` with hard-coded sample input and print their result. About half of the files are like this (for example `bfs.cpp`, `lfu.cpp`, `trie.cpp`, `calculator.cpp`).
2. **LeetCode-style snippets.** These contain only a `class Solution { ... }` with the method signature the judge expects (for example `coding_probs_1/robbers.cpp`, `coding_probs_3/kclosest.cpp`). They have no `main()`, so they won't link on their own. To try one, paste it into the problem's page on the original site, or add a small `main()` that calls it.
3. **Scratch and revision files** such as `test.cpp` and `preparation.cpp`.

Some solutions are adapted from published solutions rather than written from scratch. Those files link to the source in a comment near the top.

## Known issues

This is a learning repo, so not everything is polished.

- `coding_probs_2/hello.cpp` is a duplicate of `kmp.cpp`.
- Same-named solutions appear in more than one folder (`lru.cpp`, `temperature.cpp`, `sliding_window.cpp`), because they were written at different times.
- The solutions have not been reviewed for edge cases. Treat them as study notes, not production code.

## Contributing and feedback

This is a personal practice repository, so there is no formal contribution process. Suggestions are welcome, whether a better approach, a bug in a solution, or a fix for one of the files above. Open an issue or a pull request.

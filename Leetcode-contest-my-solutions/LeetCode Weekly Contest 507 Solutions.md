```
# LeetCode Weekly Contest 507 Solutions
This repository contains optimized solutions, algorithmic explanations, and implementation details for the problems solved in **LeetCode Weekly Contest 507**.

---

## 📂 Problem 1: Maximum Manhattan Distance After K Operations

### 📝 Problem Overview
The problem requires finding the maximum Manhattan distance possible from the origin $(0, 0)$ given a string of movement commands (`U`, `D`, `L`, `R`). A specific subset of the input may contain unmapped wildcard components (`space`) that can be optimally transformed into any direction to maximize the distance.

### 💡 Core Intuition
The maximum Manhattan distance from the origin is calculated as $|X| + |Y|$, representing net movement along the horizontal axis ($|R - L|$) and vertical axis ($|U - D|$). Wildcard markers (`space`) represent free choices. To achieve the absolute maximum global distance, every single wildcard should be dedicated to expanding whichever axis and direction are already dominant. 

Thus, the optimal distance is simply the baseline displacement plus the total count of available wildcards:
$$\text{Max Distance} = |R - L| + |U - D| + \text{space}$$

### 💻 Implementation

```cpp
class Solution {
public:
    int maxDistance(string moves) {
        int x = moves.size();
        int u = 0;
        int d = 0;
        int l = 0;
        int r = 0;
        int space = 0;

        for (int i = 0; i < x; i++) {
            if (moves[i] == 'U')
                u++;
            else if (moves[i] == 'D')
                d++;
            else if (moves[i] == 'L')
                l++;
            else if (moves[i] == 'R')
                r++;
            else 
                space++;
        }
   
        return abs(r - l) + abs(u - d) + space;
    }
};

```

### 📊 Complexity Analysis

* **Time Complexity:** $\mathcal{O}(N)$ where $N$ is the length of the `moves` string. We perform a single linear scan through the input array.
* **Space Complexity:** $\mathcal{O}(1)$ as only integer counter variables are allocated.

---

## 📂 Problem 2: Valid Subarrays With Matching Digit Conditions

### 📝 Problem Overview

Given an array `nums` and an integer target digit `x`, find the total number of contiguous subarrays whose cumulative sum satisfies a specific visual digit alignment rule: the sum's first digit and last digit must both equal `x`.

### 💡 Core Intuition

This approach checks all possible contiguous subarrays using a nested loop framework. For each starting position `i`, we expand the window to index `j`, computing a running `current_sum`.

Each dynamic sum state is validated against the following criteria:

1. **Last Digit Check:** `sum % 10 == x`
2. **First Digit Check:** Repeatedly dividing by 10 isolates the most significant digit, which must also match `x`.

### 💻 Implementation

```cpp
class Solution {
private:
    bool isValid(long long sum, int x) {
        if (sum % 10 != x) return false;
        while (sum >= 10) {
            sum /= 10;
        }
        return sum == x;
    }

public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long current_sum = 0;
            for (int j = i; j < n; j++) {
                current_sum += nums[j]; 

                if (isValid(current_sum, x)) {
                    count++;
                }
            }
        }
        return count;
    }
};

```

### 📊 Complexity Analysis

* **Time Complexity:** $\mathcal{O}(N^2)$ due to the nested loops traversing all valid structural subarrays. The digit validation helper functions run in logarithmic time $\mathcal{O}(\log_{10}(\text{sum}))$, leading to an overall average time complexity of $\mathcal{O}(N^2 \cdot \log(\text{sum}))$.
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space as calculations are managed inline with scalar trackers.

---

## 📂 Problem 3: Shortest Path With At Most K Consecutive Same-Label Nodes

### 📝 Problem Overview

Find the shortest path in a weighted graph from Node $0$ to Node $n-1$. Each node is marked with a character identifier inside a string `labels`. The primary traversal constraint states that you cannot traverse more than $K$ consecutive nodes sharing identical label values.

### 💡 Core Intuition

Standard shortest-path algorithms fail here because paths yielding a minimal weight might be blocked downstream due to label streak exhaustion.

To overcome this, we leverage a **State-Space Dijkstra** architecture. The traversal state space is expanded into a 2D table `dp[node][streak]`, tracking the shortest path to a given node relative to the exact sequence streak length leading into it. We compute transitions dynamically using a min-heap tracking mechanism. When evaluating a neighbor:

* If labels match (`labels[u] == labels[v]`), the streak increments.
* If labels change, the streak resets to `1`.
* If a state's computed streak length exceeds $K$, the transition is aborted.

### 💻 Implementation

```cpp
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // 1. Graph Adjacency List Construction
        vector<vector<pair<int, int>>> adj(n);        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj[u].push_back({v, weight});
        }

        const long long INF = 1e18;
        
        // 2. DP Table: dp[node][streak] -> Minimum distance to reach 'node' with specific 'streak'
        vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));
        
        // Min-Heap: {current_distance, current_node, current_streak}
        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<>> pq;

        // Base Case Initialization
        dp[0][1] = 0;
        pq.push({0, 0, 1});

        // 3. Dijkstra's State-Space Engine Traversal
        while (!pq.empty()) {
            auto [dist, u, streak] = pq.top();
            pq.pop();

            // Optimization Check: Skip stale state entries
            if (dist > dp[u][streak]) continue;

            // Process Neighbor Adjustments
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                // Calculate state transitions
                int next_streak = (labels[u] == labels[v]) ? (streak + 1) : 1;

                // Boundary Constraint Verification
                if (next_streak > k) continue;

                long long next_dist = dist + weight;

                // Relaxation Step
                if (next_dist < dp[v][next_streak]) {
                    dp[v][next_streak] = next_dist;
                    pq.push({next_dist, v, next_streak});
                }
            }
        }

        // 4. Final Result Extraction across all valid streaks at Destination (n - 1)
        long long min_path = INF;
        for (int s = 1; s <= k; s++) {
            min_path = min(min_path, dp[n - 1][s]);
        }

        return (min_path == INF) ? -1 : (int)min_path;
    }
};

```

### 📊 Complexity Analysis

* **Time Complexity:** $\mathcal{O}((V \cdot K + E) \cdot \log(V \cdot K))$ where $V = n$ and $E$ equals the number of edges. Each vertex supports up to $K$ sub-states inside the sorting min-heap layout.
* **Space Complexity:** $\mathcal{O}(V \cdot K + E)$ required to maintain our adjacency list structures alongside the 2D DP memoization table layout.

```
---

```

# Jump Game III — DFS Solution in C++

## Problem Link

[https://leetcode.com/problems/jump-game-iii/](https://leetcode.com/problems/jump-game-iii/)

---

# Problem Statement

You are given an array `arr` of non-negative integers and a starting index `start`.

From any index `i`, you can jump to:

* `i + arr[i]`
* `i - arr[i]`

Your task is to determine whether it is possible to reach **any index having value `0`**.

Return:

* `true` → if we can reach an index with value `0`
* `false` → otherwise

---

# Example

Input:

```cpp
arr = [4,2,3,0,3,1,2]
start = 5
```

Output:

```cpp
true
```

Explanation:

Starting from index `5`:

```text
5 -> 4 -> 1 -> 3
```

At index `3`, value is `0`.
So answer becomes `true`.

---

# Core Observation

At every index, we have two choices:

```cpp
i + arr[i]
i - arr[i]
```

This creates a graph-like traversal problem.

So we can solve it using:

* DFS (Depth First Search)
* BFS (Breadth First Search)

Here we are using DFS.

---

# Important Problem in This Question

If we keep visiting the same indices again and again:

```text
1 -> 4 -> 1 -> 4 -> 1
```

we can get stuck in an infinite recursion loop.

So we need a way to mark visited indices.

---

# Smart Trick Used

Since array values are non-negative initially,
we can mark an index as visited by making it negative.

Example:

```cpp
arr[i] *= -1;
```

Now:

```cpp
arr[i] < 0
```

means:

```text
Already visited
```

---

# Dry Run

Input:

```cpp
arr = [4,2,3,0,3,1,2]
start = 5
```

---

## Step 1

Current index:

```cpp
5
```

Value:

```cpp
arr[5] = 1
```

Possible jumps:

```cpp
5 + 1 = 6
5 - 1 = 4
```

Mark visited:

```cpp
arr[5] = -1
```

---

## Step 2

Go to index `6`

```cpp
arr[6] = 2
```

Possible jumps:

```cpp
6 + 2 = 8 (out of bound)
6 - 2 = 4
```

---

## Step 3

Go to index `4`

```cpp
arr[4] = 3
```

Possible jumps:

```cpp
4 + 3 = 7 (out of bound)
4 - 3 = 1
```

---

## Step 4

Go to index `1`

```cpp
arr[1] = 2
```

Possible jumps:

```cpp
1 + 2 = 3
1 - 2 = -1
```

---

## Step 5

Go to index `3`

```cpp
arr[3] = 0
```

Found zero.

Return:

```cpp
true
```

---

# DFS Approach

## Base Cases

### 1. Out of Bound

```cpp
if(i < 0 || i >= n)
```

Invalid index.

---

### 2. Already Visited

```cpp
arr[i] < 0
```

We already explored this index.

---

### 3. Found Zero

```cpp
arr[i] == 0
```

Answer found.

---

# Optimized C++ Solution

```cpp
class Solution {
public:

    bool dfs(vector<int>& arr, int i) {

        int n = arr.size();

        // Out of bound OR already visited
        if(i < 0 || i >= n || arr[i] < 0)
            return false;

        // Found zero
        if(arr[i] == 0)
            return true;

        int jump = arr[i];

        // Mark visited
        arr[i] *= -1;

        bool forward = dfs(arr, i + jump);
        bool backward = dfs(arr, i - jump);

        return forward || backward;
    }

    bool canReach(vector<int>& arr, int start) {

        return dfs(arr, start);
    }
};
```

---

# Time Complexity

Each index is visited at most once.

```text
Time Complexity: O(n)
```

---

# Space Complexity

Recursive DFS stack can go up to `n`.

```text
Space Complexity: O(n)
```

---

# Why This Solution is Efficient

* No extra visited array used
* Uses in-place marking
* Every node visited once
* Very clean DFS implementation
* Accepted in 0 ms runtime

---

# Common Mistakes

## Mistake 1

Using:

```cpp
i > n
```

instead of:

```cpp
i >= n
```

---

## Mistake 2

Forgetting:

```cpp
return true;
```

inside:

```cpp
if(arr[i] == 0)
```

---

## Mistake 3

Changing value to negative before storing jump.

Wrong:

```cpp
arr[i] *= -1;

dfs(arr, i + arr[i]);
```

Because jump direction changes.

Correct:

```cpp
int jump = arr[i];
arr[i] *= -1;
```

---

# X (Twitter) Post

Back on DSA grind after a long time 🚀

Solved Jump Game III using DFS + visited marking trick.

Key learning:
Instead of using an extra visited array, we can mark visited indices by converting values to negative.

✔️ Graph traversal mindset
✔️ DFS recursion
✔️ O(n) solution
✔️ 0 ms accepted

Consistency > Motivation 🔥

#leetcode #cpp #dsa #programming #100DaysOfCode #coding

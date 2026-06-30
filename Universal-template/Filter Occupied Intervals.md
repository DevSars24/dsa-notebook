# 3975. Filter Occupied Intervals

> **Difficulty:** Medium  
> **Pattern:** Merge Intervals + Interval Subtraction

---

# 💡 Intuition

This problem consists of **two independent interval operations**.

1. Merge all overlapping or touching occupied intervals.
2. Remove the free interval `[freeStart, freeEnd]` from every merged interval.

The important observation is that **touching intervals must also be merged**.

Example:

```
[1,3] [4,6]
```

Since `4 = 3 + 1`, they become

```
[1,6]
```

Therefore, while merging we use

```cpp
currentEnd + 1 >= nextStart
```

instead of

```cpp
currentEnd >= nextStart
```

---

# Algorithm

### Step 1

Sort all occupied intervals.

```cpp
sort(occupiedIntervals.begin(), occupiedIntervals.end());
```

---

### Step 2

Merge overlapping **or touching** intervals.

```cpp
if(currentEnd + 1 >= nextStart)
```

---

### Step 3

For every merged interval, remove the free interval.

There are only four cases.

### Case 1

No overlap

```
Occupied

|-----------|

          Free

                    |------|
```

Keep the interval.

---

### Case 2

Free interval completely covers occupied interval

```
Occupied

     |------|

Free

|----------------|
```

Discard it.

---

### Case 3

Overlap on left side

```
Occupied

|-------------|

Free

          |----------|
```

Keep

```
|------|
```

---

### Case 4

Overlap on right side

```
Occupied

      |-------------|

Free

|----------|
```

Keep

```
           |------|
```

---

### Case 5

Free interval lies inside occupied interval

```
Occupied

|------------------------|

Free

      |---------|
```

Split into

```
|----|     |----|
```

---

# Optimal C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(
        vector<vector<int>>& occupiedIntervals,
        int freeStart,
        int freeEnd) {

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        vector<int> current = occupiedIntervals[0];

        for (int i = 1; i < occupiedIntervals.size(); i++) {

            if (current[1] + 1 >= occupiedIntervals[i][0]) {
                current[1] = max(current[1], occupiedIntervals[i][1]);
            }
            else {
                merged.push_back(current);
                current = occupiedIntervals[i];
            }
        }

        merged.push_back(current);

        vector<vector<int>> result;

        for (auto &interval : merged) {

            int start = interval[0];
            int end = interval[1];

            // No overlap
            if (end < freeStart || start > freeEnd) {
                result.push_back({start, end});
                continue;
            }

            // Left remaining part
            if (start < freeStart) {
                result.push_back({start, freeStart - 1});
            }

            // Right remaining part
            if (end > freeEnd) {
                result.push_back({freeEnd + 1, end});
            }
        }

        return result;
    }
};
```

---

# Complexity Analysis

Sorting

```
O(n log n)
```

Merging

```
O(n)
```

Removing Free Interval

```
O(n)
```

Overall

```
Time : O(n log n)

Space : O(n)
```

---

# Key Observation

Normal merge condition

```cpp
currentEnd >= nextStart
```

Touching interval merge condition

```cpp
currentEnd + 1 >= nextStart
```

---

# Takeaway

Whenever a problem says

- overlapping intervals
- touching intervals
- adjacent intervals

always check whether the merge condition should be

```cpp
currentEnd >= nextStart
```

or

```cpp
currentEnd + 1 >= nextStart
```

This single observation is the trick of this problem.

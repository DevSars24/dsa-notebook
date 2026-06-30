# Standard Template — Occupied Intervals

A reusable template for **Merge Interval** problems.

Applicable to:

- Merge Intervals
- Insert Interval
- Remove Interval
- Employee Free Time
- Calendar Problems
- Meeting Rooms
- Occupied Intervals
- Union of Segments

---

# Step 1 — Sort

Always sort by starting point.

```cpp
sort(intervals.begin(), intervals.end());
```

---

# Step 2 — Merge

## Only Overlapping

```cpp
if(current[1] >= intervals[i][0]) {

    current[1] = max(current[1], intervals[i][1]);

}
```

---

## Overlapping + Touching

```cpp
if(current[1] + 1 >= intervals[i][0]) {

    current[1] = max(current[1], intervals[i][1]);

}
```

Use this when the problem states

- touching intervals
- adjacent intervals
- consecutive integers

---

# Standard Merge Template

```cpp
sort(intervals.begin(), intervals.end());

vector<vector<int>> merged;

vector<int> current = intervals[0];

for(int i = 1; i < intervals.size(); i++) {

    if(current[1] + 1 >= intervals[i][0]) {

        current[1] = max(current[1], intervals[i][1]);

    }

    else {

        merged.push_back(current);

        current = intervals[i];

    }
}

merged.push_back(current);
```

---

# Standard Remove Interval Template

Suppose we want to remove

```
[removeLeft, removeRight]
```

from every interval.

```cpp
vector<vector<int>> answer;

for(auto &interval : merged) {

    int left = interval[0];
    int right = interval[1];

    // No overlap
    if(right < removeLeft || left > removeRight) {

        answer.push_back({left, right});

        continue;
    }

    // Left remaining part
    if(left < removeLeft) {

        answer.push_back({left, removeLeft - 1});

    }

    // Right remaining part
    if(right > removeRight) {

        answer.push_back({removeRight + 1, right});

    }
}
```

---

# Complete Generic Template

```cpp
sort(intervals.begin(), intervals.end());

vector<vector<int>> merged;

vector<int> current = intervals[0];

for(int i = 1; i < intervals.size(); i++) {

    if(current[1] + 1 >= intervals[i][0]) {

        current[1] = max(current[1], intervals[i][1]);

    }

    else {

        merged.push_back(current);

        current = intervals[i];

    }
}

merged.push_back(current);

vector<vector<int>> answer;

for(auto &interval : merged) {

    int left = interval[0];
    int right = interval[1];

    // Custom processing
}
```

---

# Time Complexity

Sorting

```
O(n log n)
```

Merge

```
O(n)
```

Overall

```
O(n log n)
```

Space

```
O(n)
```

---

# Checklist Before Coding

- Sort intervals.
- Decide merge condition.
- Merge intervals.
- Process merged intervals.
- Handle left part.
- Handle right part.
- Return answer.

---

# Common Merge Conditions

## Overlap Only

```cpp
currentEnd >= nextStart
```

---

## Overlap + Touching

```cpp
currentEnd + 1 >= nextStart
```

---

# Related LeetCode Problems

| Problem | Pattern |
|----------|---------|
| 56. Merge Intervals | Merge |
| 57. Insert Interval | Merge |
| 435. Non-overlapping Intervals | Greedy |
| 986. Interval List Intersections | Two Pointers |
| Employee Free Time | Merge |
| 3975. Filter Occupied Intervals | Merge + Remove Interval |

---

# Golden Rule

Almost every interval problem follows this pipeline:

```
Sort
   ↓
Merge
   ↓
Process
   ↓
Return
```

Master this template once, and you'll be able to solve most interval problems efficiently.

# 📁 File 1: `inversion_count_merge_sort.cpp`

```cpp
// Problem: Inversion of Array
// Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Approach: Merge Sort based counting
// Time Complexity: O(N log N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;
        long long cnt = 0;

        // Merge while counting inversions
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                // All remaining elements in left part form inversions
                cnt += (m - i + 1);
            }
        }

        // Copy remaining elements
        while (i <= m) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        // Copy back to original array
        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& arr, int l, int r) {
        long long cnt = 0;
        if (l < r) {
            int m = l + (r - l) / 2;
            cnt += mergeSort(arr, l, m);
            cnt += mergeSort(arr, m + 1, r);
            cnt += merge(arr, l, m, r);
        }
        return cnt;
    }

    long long inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
```

---

# 📘 File 2: `MERGE_SORT_NOTES.md`

## 🔹 What is Merge Sort?

Merge Sort is a **Divide and Conquer** algorithm.

Steps:

1. Divide the array into two halves
2. Recursively sort both halves
3. Merge the two sorted halves

It is **stable**, **predictable**, and works in **O(N log N)** time in all cases.

---

## 🔹 Why Merge Sort for Inversion Count?

### ❓ Inversion Definition

An inversion is a pair `(i, j)` such that:

* `i < j`
* `arr[i] > arr[j]`

### ❌ Brute Force

```cpp
for(i=0;i<n;i++)
 for(j=i+1;j<n;j++)
  if(arr[i] > arr[j]) cnt++;
```

Time: **O(N²)** ❌ (TLE for large N)

---

## 🔹 Core Intuition (MOST IMPORTANT)

While merging two **sorted halves**:

Left:  `[1, 4, 6]`
Right: `[2, 3, 5]`

If:

```
left[i] > right[j]
```

Then **ALL remaining elements** from `i` to `mid` in left array are also greater than `right[j]`.

So inversions added:

```
(mid - i + 1)
```

This single observation reduces complexity drastically.

---

## 🔹 Dry Run Example

Array: `[8, 4, 2, 1]`

1. Split → `[8,4]` and `[2,1]`
2. Sort → `[4,8]` and `[1,2]`
3. Merge:

   * 4 > 1 → +2 inversions
   * 4 > 2 → +2 inversions

Total inversions = **6**

---

## 🔹 Algorithm Steps (Merge Sort + Count)

1. Recursively divide array
2. While merging:

   * If `left[i] <= right[j]` → no inversion
   * Else → count `(mid - i + 1)` inversions
3. Merge sorted halves

---

## 🔹 Time & Space Complexity

| Case    | Time       |
| ------- | ---------- |
| Best    | O(N log N) |
| Average | O(N log N) |
| Worst   | O(N log N) |

Space: **O(N)** (temporary array)

---

## 🔹 C++ Standard Template

```cpp
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
```

---

## 🔹 Java Standard Template

```java
void mergeSort(int[] arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
```

---

## 🔹 When to Use Merge Sort?

✔ Large input size
✔ Stable sorting required
✔ Inversion count / range problems
✔ Linked list sorting

---

## 🔥 Key Takeaway (Exam + Interview)

> **Merge Sort is not just a sorting algorithm — it's a framework to solve many problems efficiently.**

Master this → You unlock:

* Inversion Count
* Count of smaller elements
* Reverse pairs
* Range counting problems

---

✍️ Tip: Practice explaining **WHY `(mid - i + 1)` works** — that's what interviewers want.

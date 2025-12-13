// LeetCode Problem: 2537. Count the Number of Good Subarrays
// Link: [https://leetcode.com/problems/count-the-number-of-good-subarrays/](https://leetcode.com/problems/count-the-number-of-good-subarrays/)
// Difficulty: Medium

/*
============================ PROBLEM DESCRIPTION ============================
You are given:

* An integer array nums
* An integer k

A subarray is called GOOD if it contains at least k pairs (i, j) such that:
i < j and nums[i] == nums[j]

Your task is to return the total number of GOOD subarrays.

A subarray is a contiguous, non-empty portion of the array.

============================ KEY OBSERVATION ============================
If a number appears `f` times in a subarray, it contributes:

```
f * (f - 1) / 2
```

pairs.

Instead of recalculating pairs from scratch for every subarray (O(n²)),
we maintain the count dynamically using a sliding window.

============================ SLIDING WINDOW INSIGHT ============================
When extending the window by adding nums[j]:

* If nums[j] has already appeared `x` times in the window,
  it contributes `x` NEW pairs.

We maintain:

* A frequency map `mp`
* A running count `pairs` = total number of equal pairs in the window

If at any point `pairs >= k`, then:

* All subarrays starting at `i` and ending at `j, j+1, ..., n-1` are GOOD
* Hence, we add `(n - j)` to the result

Then we shrink the window from the left to find other valid subarrays.

============================ ALGORITHM ============================

1. Initialize two pointers `i` and `j`
2. Expand the window using `j`
3. Update `pairs` using frequency map
4. When `pairs >= k`, count valid subarrays and shrink from left
5. Continue until the array is fully processed

============================ TIME & SPACE COMPLEXITY ============================
Time Complexity: O(n)
Space Complexity: O(n)

============================ IMPLEMENTATION ============================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
long long countGood(vector<int>& nums, int k) {
int n = nums.size();
int i = 0;
long long result = 0;
long long pairs = 0;

```
    unordered_map<int, int> mp;

    for (int j = 0; j < n; j++) {
        // Adding nums[j] creates mp[nums[j]] new pairs
        pairs += mp[nums[j]];
        mp[nums[j]]++;

        // Shrink window while condition is satisfied
        while (pairs >= k) {
            result += (n - j);

            mp[nums[i]]--;
            pairs -= mp[nums[i]];
            i++;
        }
    }

    return result;
}
```

};

/*
============================ EXAMPLE WALKTHROUGH ============================
nums = [3,1,4,3,2,2,4], k = 2

Window expands and dynamically tracks:

* Frequencies
* Number of equal pairs

Whenever pairs >= k, all future extensions of the window remain valid,
allowing efficient counting.

============================ KEY TAKEAWAYS ============================
✔ Count pairs incrementally instead of recomputing
✔ Use two pointers with frequency map
✔ `(n - j)` trick avoids extra loops
✔ Excellent example of optimized sliding window
*/

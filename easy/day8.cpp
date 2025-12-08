/*
===========================================================================
      📘 Maximum Length Bitonic Subarray — GeeksforGeeks
===========================================================================

🔗 Problem Link:
https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1

---------------------------------------------------------------------------
📝 Problem Statement
---------------------------------------------------------------------------
You are given an array 'arr' of positive integers.

A subarray arr[i … j] is called *bitonic* if there exists some index k
(i <= k <= j) such that:

1) Non-decreasing (increasing) part:
       arr[i] <= arr[i+1] <= ... <= arr[k]

2) Non-increasing (decreasing) part:
       arr[k] >= arr[k+1] >= ... >= arr[j]

Your task:
➡ Return the **maximum length** of any such bitonic subarray.

---------------------------------------------------------------------------
💡 Example
---------------------------------------------------------------------------
Input:
    arr = [12, 4, 78, 90, 45, 23]

Output:
    5

Explanation:
    The longest bitonic subarray is:
        4 <= 78 <= 90 >= 45 >= 23
        Length = 5

---------------------------------------------------------------------------
⏱ Constraints
---------------------------------------------------------------------------
1 ≤ arr.size() ≤ 1e6
1 ≤ arr[i] ≤ 1e6
Expected Time:  O(n)
Expected Aux Space: O(1) — but O(n) DP allowed in practice

---------------------------------------------------------------------------
💡 Intuition & Approach (Most Important Part)
---------------------------------------------------------------------------
This problem is the *super-version* of LeetCode's "Longest Mountain".

We build two arrays:

1️⃣ inc[i] → length of NON-DECREASING subarray ending at i
     (arr[i] >= arr[i-1])

2️⃣ dec[i] → length of NON-INCREASING subarray starting at i
     (arr[i] >= arr[i+1])

For any index 'i' acting as the PEAK, bitonic length is:

        inc[i] + dec[i] - 1

Why minus 1?
Because arr[i] counted twice (once in both arrays).

The maximum of all such values = answer.

---------------------------------------------------------------------------
🎯 When to Use This Technique?
---------------------------------------------------------------------------
Use this DP method when:

✔ A problem involves INCREASING then DECREASING pattern  
✔ You need the LONGEST such subarray  
✔ Start and end are unknown  
✔ Strict or non-strict variation is allowed  
✔ Doing 2-pointer expansion becomes O(n²)

This solves the entire thing in O(n).

This technique applies to:
- Longest Mountain (strict version)
- Bitonic array problems (non-strict version)
- Max increasing + decreasing combination questions

--------------------------------------------------------------------------- */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitonic(vector<int> &arr) {

        int n = arr.size();
        if (n == 0) return 0;

        // DP arrays
        vector<int> inc(n, 1), dec(n, 1);

        // Build inc[] → non-decreasing prefix lengths
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i-1])
                inc[i] = inc[i-1] + 1;
        }

        // Build dec[] → non-increasing suffix lengths
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i+1])
                dec[i] = dec[i+1] + 1;
        }

        // Compute max bitonic length
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, inc[i] + dec[i] - 1);
        }

        return ans;
    }
};


/*
===========================================================================
                     ✅ END OF SOLUTION — VERIFIED
===========================================================================


*/

/*
===============================================================================
Problem Name   : Maximum Subarray
Platform       : Coding Ninjas (Code360)
Difficulty     : Medium
Topic          : Arrays / Kadane’s Algorithm

-------------------------------------------------------------------------------
Problem Link:
https://www.naukri.com/code360/problems/maximum-subarray_893296

-------------------------------------------------------------------------------
Problem Statement:
Given an integer array arr of size n, find a subarray such that the sum of
its elements is maximum.

Rules:
1. Subarray must be CONTIGUOUS.
2. If multiple subarrays have the same maximum sum,
   return the one with GREATER LENGTH.
3. If still multiple answers exist, return any.

-------------------------------------------------------------------------------
Examples:

Input:
arr = [1, 2, 5, -7, 2, 3]
Output:
[1, 2, 5]

Explanation:
The subarray [1, 2, 5] gives the maximum sum = 8.

--------------------------------------------------

Input:
arr = [-2, -3, -4, 1]
Output:
[1]

Explanation:
All elements except the last are negative, so the maximum subarray is [1].

-------------------------------------------------------------------------------
Core Intuition (MOST IMPORTANT):
--------------------------------
"Negative prefix can NEVER help in forming a maximum sum subarray."

If the running sum becomes negative, carrying it forward will only reduce
future sums — so we RESET and start a new subarray.

This idea is known as Kadane’s Algorithm.

-------------------------------------------------------------------------------
Approach:
--------------------------------
We maintain:
1. currSum    -> sum of current subarray
2. maxSum     -> best sum seen so far
3. start      -> start index of current subarray
4. bestStart  -> start index of best subarray
5. bestEnd    -> end index of best subarray

Steps:
- Traverse array from left to right
- Add current element to currSum
- If currSum becomes better than maxSum, update answer
- If currSum becomes negative, reset it and start new subarray

-------------------------------------------------------------------------------
Dry Run Example:
--------------------------------
arr = [1, 2, 5, -7, 2, 3]

i=0 -> currSum=1  -> maxSum=1
i=1 -> currSum=3  -> maxSum=3
i=2 -> currSum=8  -> maxSum=8  ✅
i=3 -> currSum=1  (continue)
i=4 -> currSum=3
i=5 -> currSum=6

Best subarray = [1, 2, 5]

-------------------------------------------------------------------------------
Time Complexity:
--------------------------------
O(n)

Space Complexity:
--------------------------------
O(1) extra space (excluding output vector)

-------------------------------------------------------------------------------
Similar Questions to Practice (Same Intuition):
--------------------------------
1. Maximum Subarray Sum (Kadane)
2. Maximum Product Subarray
3. Circular Maximum Subarray
4. Longest Subarray with Positive Sum
5. Minimum Subarray Sum (Reverse Kadane)

-------------------------------------------------------------------------------
Key Takeaway:
--------------------------------
Kadane is not about memorizing code.
It’s about knowing WHEN to DROP the past and START fresh.

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maximumsumSubarray(vector<int> &arr, int n)
{
    int currsum = 0;
    int maxsum = INT_MIN;

    int start = 0;
    int beststart = 0, bestend = 0;

    for (int i = 0; i < n; i++) {

        // 1️⃣ Add current element
        currsum += arr[i];

        // 2️⃣ Check if this is the best subarray so far
        if (currsum > maxsum ||
           (currsum == maxsum && i - start > bestend - beststart)) {

            maxsum = currsum;
            beststart = start;
            bestend = i;
        }

        // 3️⃣ If current sum becomes negative, reset
        if (currsum < 0) {
            currsum = 0;
            start = i + 1;
        }
    }

    // Build result subarray
    vector<int> result;
    for (int i = beststart; i <= bestend; i++) {
        result.push_back(arr[i]);
    }

    return result;
}

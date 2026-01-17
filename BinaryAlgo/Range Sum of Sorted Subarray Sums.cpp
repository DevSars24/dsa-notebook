/*
LeetCode: 1508. Range Sum of Sorted Subarray Sums
Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

Approach Used: Brute Force

Explanation:
1. Generate all possible subarray sums.
2. Store them in a vector.
3. Sort the vector.
4. Compute the sum of elements from index (left-1) to (right-1).
5. Apply modulo 1e9 + 7 to avoid overflow.

Why this passes:
- Constraints are small (n <= 1000).
- Total subarrays = n*(n+1)/2 ≈ 5e5 (manageable).
- Brute force is acceptable here.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        const int MOD = 1e9 + 7;
        vector<long long> subSums;

        // Generate all subarray sums
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                subSums.push_back(sum);
            }
        }

        // Sort all subarray sums
        sort(subSums.begin(), subSums.end());

        // Compute range sum
        long long ans = 0;
        for(int i = left - 1; i <= right - 1; i++) {
            ans = (ans + subSums[i]) % MOD;
        }

        return ans;
    }
};

/*
---------------------------------------------------
Optimized Solution (To be added later):
- Binary Search + Prefix Sum
- Min Heap based approach
---------------------------------------------------
*/

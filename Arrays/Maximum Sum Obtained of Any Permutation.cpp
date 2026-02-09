/*
--------------------------------------------------------------------
LeetCode Problem: Maximum Sum Obtained of Any Permutation
Link: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

Difficulty: Medium
--------------------------------------------------------------------

🧠 Intuition:
Each query [l, r] increases the contribution count of all indices
from l to r by 1. We want to maximize the total sum:

    sum(nums[i] * frequency[i])

To maximize this:
- Larger numbers should be multiplied with larger frequencies.
- Smaller numbers with smaller frequencies.

So the idea is:
1. Compute how many times each index is used (frequency array).
2. Sort both `nums` and `frequency` in descending order.
3. Multiply corresponding elements and sum them.

This greedy pairing gives the maximum possible sum.

--------------------------------------------------------------------

🛠️ Approach:
1. Use a difference array (`events`) to efficiently process all range queries.
2. Convert difference array into prefix sum to get frequency of each index.
3. Sort both `nums` and `events` in descending order.
4. Multiply pairwise and accumulate result using modulo.

--------------------------------------------------------------------

⏱️ Time Complexity:
- O(n log n + q)  
  where n = size of nums, q = number of requests.

🧠 Space Complexity:
- O(n) for frequency array.

--------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // Step 1: Difference array to count frequencies
        vector<int> events(n, 0);

        for (auto &req : requests) {
            int start = req[0];
            int end   = req[1];

            events[start] += 1;
            if (end + 1 < n)
                events[end + 1] -= 1;
        }

        // Step 2: Prefix sum to get actual frequencies
        for (int i = 1; i < n; i++) {
            events[i] += events[i - 1];
        }

        // Step 3: Sort nums and frequencies in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        sort(events.begin(), events.end(), greater<int>());

        // Step 4: Multiply and sum
        long long result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + 1LL * nums[i] * events[i]) % MOD;
        }

        return (int)result;
    }
};

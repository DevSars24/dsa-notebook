question link here is ->
https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int dp[101]; // constraint ke hisaab se enough size

    int solve(vector<int> &nums, int i, int n) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        // choice 1: steal current house
        int steal = nums[i] + solve(nums, i + 2, n);

        // choice 2: skip current house
        int skip = solve(nums, i + 1, n);

        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp)); // correct spelling
        return solve(nums, 0, n);
    }
};
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
📝 Dry Run with Example

Input: nums = {2, 7, 9, 3, 1}

We want max money without robbing adjacent houses.

rob(nums)

memset(dp,-1,...)

call solve(nums, 0, 5)

solve(0)

option1 (steal 2): 2 + solve(2)
option2 (skip 2): solve(1)

solve(2)

steal = 9 + solve(4)
skip = solve(3)

solve(4)

steal = 1 + solve(6) → 1 + 0 = 1
skip = solve(5) → 0
max = 1

solve(3)

steal = 3 + solve(5) → 3 + 0 = 3
skip = solve(4) → 1
max = 3

Back to solve(2)

steal = 9 + 1 = 10
skip = 3
max = 10

solve(1)
steal = 7 + solve(3) → 7 + 3 = 10
skip = solve(2) → 10
max = 10

Back to solve(0)
steal = 2 + 10 = 12
skip = 10
max = 12

✅ Answer = 12

👉 Output for {2,7,9,3,1} = 12

















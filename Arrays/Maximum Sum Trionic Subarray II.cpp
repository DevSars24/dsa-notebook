#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Problem: Maximum Sum Trionic Subarray II
 * Strategy: State-based Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(n) -> can be optimized to O(1)
 */

class Solution {
public:
    typedef long long ll;
    const ll NEG = -1e17;

    ll maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return -1; // Pattern Up-Down-Up requires min 4 elements

        // dp[i][state] stores max sum ending at index i in a specific phase
        vector<vector<ll>> dp(n, vector<ll>(3, NEG));
        ll ans = NEG;

        for (int i = 1; i < n; i++) {
            // --- Phase 0: Increasing (UP) ---
            if (nums[i] > nums[i - 1]) {
                // Start a new sequence at (i-1, i) or continue existing UP trend
                dp[i][0] = max((ll)nums[i-1] + nums[i], (dp[i-1][0] != NEG ? dp[i-1][0] + nums[i] : NEG));
            }

            // --- Phase 1: Decreasing (DOWN) ---
            if (nums[i] < nums[i - 1]) {
                // Transition from UP phase or continue DOWN trend
                ll from_prev_phase = (dp[i-1][0] != NEG ? dp[i-1][0] + nums[i] : NEG);
                ll continue_phase = (dp[i-1][1] != NEG ? dp[i-1][1] + nums[i] : NEG);
                dp[i][1] = max(from_prev_phase, continue_phase);
            }

            // --- Phase 2: Second Increasing (UP) ---
            if (nums[i] > nums[i - 1]) {
                // Transition from DOWN phase or continue final UP trend
                ll from_prev_phase = (dp[i-1][1] != NEG ? dp[i-1][1] + nums[i] : NEG);
                ll continue_phase = (dp[i-1][2] != NEG ? dp[i-1][2] + nums[i] : NEG);
                dp[i][2] = max(from_prev_phase, continue_phase);
            }

            ans = max(ans, dp[i][2]);
        }

        return (ans <= NEG + 1e14) ? -1 : ans;
    }
};

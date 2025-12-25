/*
Problem: Maximum Alternating Subsequence Sum
--------------------------------------------
Given an array of integers, we need to find the maximum alternating sum 
of a subsequence. 

Alternating sum means:
- First chosen element is added
- Second chosen element is subtracted
- Third is added
- Fourth is subtracted
... and so on.

Example:
---------
nums = [4, 2, 5, 3]

Best subsequence = [4, 2, 5]
Alternating sum = 4 - 2 + 5 = 7

So answer = 7


--------------------------------------------
Approach: Recursion + Memoization (Top-Down DP)
--------------------------------------------
At each index we have 2 choices:
1. Skip current element
2. Take current element
   - If it's an "even" pick (1st, 3rd, 5th...), we add it
   - If it's an "odd" pick (2nd, 4th, ...), we subtract it

We store results in a DP table `t[idx][iseven]` 
to avoid recalculating same states.
--------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    long long t[1000001][2]; // DP table

    // Recursive function
    long long solve(int idx, vector<int>& nums, bool iseven) {
        // Base case: If index goes out of array
        if(idx >= n) return 0;

        // If already computed, return memoized value
        if(t[idx][iseven] != -1) return t[idx][iseven];

        // Choice 1: Skip current element
        long long skip = solve(idx+1, nums, iseven);

        // Choice 2: Take current element
        long long val = nums[idx];
        if(!iseven) val = -val; // subtract if odd-position pick

        long long take = solve(idx+1, nums, !iseven) + val;

        // Store & return maximum of both choices
        return t[idx][iseven] = max(skip, take);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t)); // Initialize DP with -1
        return solve(0, nums, true); // Start at idx=0, first pick = add
    }
};


/*
--------------------------------------------
Dry Run Example: nums = [1, 2]
--------------------------------------------
Call: solve(0, true)

At idx=0 (num=1, add it):
- Skip → solve(1, true)
- Take → 1 + solve(1, false)

Now:
solve(1, true) → (num=2, add it)
    - Skip → solve(2,true)=0
    - Take → 2 + solve(2,false)=2+0=2
    => max = 2

solve(1, false) → (num=2, subtract it)
    - Skip → solve(2,false)=0
    - Take → -2 + solve(2,true) = -2+0=-2
    => max = 0

Back to idx=0:
- Skip = 2
- Take = 1 + 0 = 1
=> Answer = max(2, 1) = 2

So maximum alternating sum for [1,2] = 2
(Best subsequence = [2])
--------------------------------------------
*/


int main() {
    Solution obj;
    
    // Example 1
    vector<int> nums1 = {1, 2};
    cout << "Answer for [1,2] = " << obj.maxAlternatingSum(nums1) << endl; // 2

    // Example 2
    vector<int> nums2 = {4, 2, 5, 3};
    cout << "Answer for [4,2,5,3] = " << obj.maxAlternatingSum(nums2) << endl; // 7

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
====================================================================
                  HOUSE ROBBER I  (Linear)
====================================================================

Problem:
- Ek straight line me 'n' houses hain.
- Har house me kuch paisa hai.
- Agar tum ek house rob karte ho, to uske adjacent house rob nahi kar sakte.
- Find maximum paisa jo rob kiya ja sake.

Key points:
- Houses ek line me hain → range hamesha 0 ... n-1.
- Base condition: jab index array ke bahar chala jaye (i >= n), return 0.

Example:
   nums = [2,7,9,3,1]
   Optimal rob = 7 + 3 + 2 (ya 2 + 9 + 1)
   Answer = 12
*/

int t1[101]; // memoization table for House Robber I

int solveLinear(vector<int>& nums, int i, int n) {
    if (i >= n) return 0; // base case

    if (t1[i] != -1) return t1[i]; // already solved

    // Choice 1: Rob this house + jump to i+2
    int steal = nums[i] + solveLinear(nums, i + 2, n);

    // Choice 2: Skip this house, go to i+1
    int skip = solveLinear(nums, i + 1, n);

    // Store and return best option
    return t1[i] = max(steal, skip);
}

int robLinear(vector<int>& nums) {
    memset(t1, -1, sizeof(t1));
    return solveLinear(nums, 0, nums.size());
}

/*
====================================================================
                  HOUSE ROBBER II  (Circular)
====================================================================

Problem:
- Ab houses ek circle me hain.
- Matlab house[0] aur house[n-1] adjacent hain.
- Isliye hum ek saath first aur last dono rob nahi kar sakte.

Trick:
- Do subcases banate hain:
   Case 1: Rob from [0 ... n-2] (first include, last exclude)
   Case 2: Rob from [1 ... n-1] (first exclude, last include)

- Answer = max(case1, case2)

Key points:
- Yahan recursion ke liye hume "end index" dena padta hai.
- Base condition: if (i > end) return 0.

Example:
   nums = [2,3,2]
   Case 1: rob [0,1] → max = 3
   Case 2: rob [1,2] → max = 3
   Final answer = 3
*/

int t2[101]; // memoization table for House Robber II

int solveCircular(vector<int>& nums, int i, int end) {
    if (i > end) return 0; // base case

    if (t2[i] != -1) return t2[i];

    int steal = nums[i] + solveCircular(nums, i + 2, end);
    int skip = solveCircular(nums, i + 1, end);

    return t2[i] = max(steal, skip);
}

int robCircular(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];               // only one house
    if (n == 2) return max(nums[0], nums[1]); // only two houses

    // Case 1: 0 ... n-2
    memset(t2, -1, sizeof(t2));
    int case1 = solveCircular(nums, 0, n - 2);

    // Case 2: 1 ... n-1
    memset(t2, -1, sizeof(t2));
    int case2 = solveCircular(nums, 1, n - 1);

    return max(case1, case2);
}

/*
====================================================================
                  DIFFERENCE SUMMARY
====================================================================

House Robber I (Linear):
- Range: [0 ... n-1]
- Base condition: if(i >= n) return 0;
- Function call: solve(nums, 0, n)

House Robber II (Circular):
- Range split into [0 ... n-2] and [1 ... n-1]
- Base condition: if(i > end) return 0;
- Function call: max(solve(0, n-2), solve(1, n-1))

====================================================================
                  DRY RUN EXAMPLE
====================================================================

Example: nums = [2,3,2]  (House Robber II)

Case 1: range [0..1]
   solve(0,1):
      steal = 2 + solve(2,1) → 2 + 0 = 2
      skip  = solve(1,1)
              = max(3 + solve(3,1), solve(2,1))
              = max(3+0, 0) = 3
      answer = max(2,3) = 3

Case 2: range [1..2]
   solve(1,2):
      steal = 3 + solve(3,2) → 3 + 0 = 3
      skip  = solve(2,2)
              = max(2 + solve(4,2), solve(3,2))
              = max(2+0, 0) = 2
      answer = max(3,2) = 3

Final Answer = max(3,3) = 3
====================================================================
*/

int main() {
    vector<int> nums1 = {2, 7, 9, 3, 1};
    cout << "House Robber I result: " << robLinear(nums1) << endl; // 12

    vector<int> nums2 = {2, 3, 2};
    cout << "House Robber II result: " << robCircular(nums2) << endl; // 3

    return 0;
}

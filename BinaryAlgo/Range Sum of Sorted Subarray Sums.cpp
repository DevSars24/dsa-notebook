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


/*
LeetCode: 1508. Range Sum of Sorted Subarray Sums
Link:
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

------------------------------------------------------------
OPTIMIZED APPROACH: MIN HEAP
------------------------------------------------------------

We want the subarray sums in sorted order WITHOUT generating all
O(n^2) subarrays.

Heap stores:
    {current_subarray_sum, ending_index}

------------------------------------------------------------
DRY RUN EXAMPLE
------------------------------------------------------------

nums = [1, 2, 3, 4]
n = 4
left = 3
right = 6

All subarrays (only for understanding):
[1] = 1
[1,2] = 3
[1,2,3] = 6
[1,2,3,4] = 10
[2] = 2
[2,3] = 5
[2,3,4] = 9
[3] = 3
[3,4] = 7
[4] = 4

Sorted sums:
[1,2,3,3,4,5,6,7,9,10]

We need index 3 to 6 → 3 + 3 + 4 + 5 = 15

------------------------------------------------------------
INITIAL HEAP PUSH (single elements):
------------------------------------------------------------
Heap = {(1,0), (2,1), (3,2), (4,3)}

------------------------------------------------------------
POP PROCESS (count = 1 → right)
------------------------------------------------------------

count = 1
pop (1,0)
extend → push (3,1)
heap → (2,1), (3,1), (3,2), (4,3)

count = 2
pop (2,1)
extend → push (5,2)
heap → (3,1), (3,2), (4,3), (5,2)

count = 3
pop (3,1)
ADD → result = 3
extend → push (6,2)

count = 4
pop (3,2)
ADD → result = 6
extend → push (7,3)

count = 5
pop (4,3)
ADD → result = 10

count = 6
pop (5,2)
ADD → result = 15
extend → push (9,3)

STOP (count == right)

------------------------------------------------------------
FINAL ANSWER = 15
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        const int MOD = 1e9 + 7;

        // Min heap: {subarray_sum, ending_index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Step 1: Push all single-element subarrays
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long result = 0;

        // Step 2: Extract smallest sums up to 'right'
        for(int count = 1; count <= right; count++) {

            auto p = pq.top();
            pq.pop();

            int sum = p.first;
            int idx = p.second;

            // Step 3: Add only if within range
            if(count >= left) {
                result = (result + sum) % MOD;
            }

            // Step 4: Extend subarray
            if(idx + 1 < n) {
                pq.push({sum + nums[idx + 1], idx + 1});
            }
        }

        return result;
    }
};

/*
------------------------------------------------------------
TIME COMPLEXITY:  O(right log n)
SPACE COMPLEXITY: O(n)

WHY THIS PASSES:
- n ≤ 1000
- right ≤ n*(n+1)/2
- We only process needed subarray sums
------------------------------------------------------------
*/


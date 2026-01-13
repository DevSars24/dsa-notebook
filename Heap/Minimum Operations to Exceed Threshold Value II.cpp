
/*
===============================================================================
Problem: Minimum Operations to Exceed Threshold Value II
Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

Difficulty: Medium
Platform: LeetCode

-------------------------------------------------------------------------------
Problem Statement:
You are given an array of integers `nums` and an integer `k`.

In one operation:
- Remove the two smallest elements from the array
- Create a new number = (2 * smallest) + secondSmallest
- Insert this new number back into the array

Your task is to return the minimum number of operations required so that
all elements in the array are greater than or equal to `k`.

-------------------------------------------------------------------------------
Key Observations:
- We always need the two smallest elements → Min Heap is ideal
- Greedy approach works: combine smallest elements first
- Priority Queue (min-heap) gives O(log n) access to smallest values

-------------------------------------------------------------------------------
Approach (Min Heap / Priority Queue):

1. Push all elements of nums into a min-heap
2. While the smallest element is less than k:
   a. Extract the smallest element
   b. Extract the second smallest element
   c. Combine them using: (2 * smallest + secondSmallest)
   d. Push the result back into the heap
   e. Increment operation count
3. Once all elements are >= k, return count

-------------------------------------------------------------------------------
Why This Works:
- Combining smaller elements first increases the minimum value fastest
- Greedy strategy ensures minimum number of operations
- Min heap guarantees optimal extraction order

-------------------------------------------------------------------------------
Time Complexity:
- Building heap: O(n)
- Each operation: O(log n)
- Total: O(n log n)

Space Complexity:
- O(n) for the heap

-------------------------------------------------------------------------------
Example:
Input:
nums = [2, 11, 10, 1, 3], k = 10

Operations:
1) Combine 1 and 2 → 2*1 + 2 = 4 → heap: [3,4,10,11]
2) Combine 3 and 4 → 2*3 + 4 = 10 → heap: [10,10,11]

Output:
2

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        // Min heap to always access smallest elements
        priority_queue<long, vector<long>, greater<long>> pq(
            nums.begin(), nums.end()
        );

        long long count = 0;

        // Continue until smallest element reaches threshold
        while (!pq.empty() && pq.top() < k) {

            long long smallest = pq.top();
            pq.pop();

            long long secondSmallest = pq.top();
            pq.pop();

            long long combined = (smallest * 2) + secondSmallest;

            pq.push(combined);
            count++;
        }

        return count;
    }
};

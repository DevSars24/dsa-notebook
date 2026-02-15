/*
===============================================================================
Problem: Corporate Flight Bookings
Platform: LeetCode
Link: https://leetcode.com/problems/corporate-flight-bookings/
Difficulty: Medium

Author: Saurabh Singh
Language: C++
Approach: Difference Array + Prefix Sum
Time Complexity: O(n + m)
Space Complexity: O(n)

===============================================================================

🧠 Problem Summary:
-------------------
You are given a list of bookings. Each booking is represented as:

    bookings[i] = [start, end, seats]

This means that 'seats' number of seats are booked for every flight
from 'start' to 'end' (inclusive).

Return an array of size n where:
    result[i] = total seats booked for flight (i + 1)

Flights are 1-indexed.

-------------------------------------------------------------------------------

🚀 Core Idea:
-------------
Instead of updating each index from start to end (which would take O(n)
per booking), we use a DIFFERENCE ARRAY technique.

Difference Array Concept:
-------------------------
If we want to add 'x' to a range [L, R], we:
    diff[L] += x
    diff[R + 1] -= x

After processing all bookings, we compute prefix sum of diff array
to get final values.

This reduces range update complexity from O(n*m) → O(n + m)

-------------------------------------------------------------------------------

🔍 Algorithm Steps:
-------------------
1. Create diff array of size (n + 2) initialized with 0.
2. For each booking:
       diff[start] += seats
       diff[end + 1] -= seats
3. Compute prefix sum from 1 to n.
4. Store results in output vector.

-------------------------------------------------------------------------------

📊 Example:
-----------
Input:
    bookings = [[1,2,10], [2,3,20], [2,5,25]]
    n = 5

After applying difference updates:
    diff = [0, 10, 45, -10, 0, -25, ...]

After prefix sum:
    result = [10, 55, 45, 25, 25]

-------------------------------------------------------------------------------

🎯 Why This Approach?
---------------------
- Avoids nested loops
- Efficient range updates
- Foundational for:
    • Sweep Line Algorithm
    • Lazy Propagation
    • Segment Trees
    • Interval Problems

-------------------------------------------------------------------------------
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        // Step 1: Create difference array
        vector<int> diff(n + 2, 0);

        // Step 2: Apply range updates
        for (auto &b : bookings) {
            int start = b[0];
            int end = b[1];
            int seats = b[2];

            diff[start] += seats;
            diff[end + 1] -= seats;
        }

        // Step 3: Compute prefix sum
        vector<int> result(n);
        int currSum = 0;

        for (int i = 1; i <= n; i++) {
            currSum += diff[i];
            result[i - 1] = currSum;
        }

        return result;
    }
};

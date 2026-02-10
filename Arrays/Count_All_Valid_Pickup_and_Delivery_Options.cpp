/***************************************************************
 * File Name   : Count_All_Valid_Pickup_and_Delivery_Options.cpp
 *
 * Problem     : Count All Valid Pickup and Delivery Options
 * Platform    : LeetCode
 * Difficulty  : Hard
 *
 * Description :
 * Given an integer n, return the total number of valid pickup
 * and delivery sequences such that each delivery happens after
 * its corresponding pickup.
 *
 * The answer may be very large, so return it modulo 10^9 + 7.
 *
 * ------------------------------------------------------------
 * Approach :
 * - This problem is solved using a mathematical observation.
 * - Suppose we already have (i-1) pickup–delivery pairs.
 * - Total occupied positions = 2 * (i - 1)
 * - New pickup Pi and delivery Di can be inserted in:
 *
 *      (2i - 1) * (2i) / 2  ways
 *
 * - Multiply possibilities for all i from 2 to n.
 * - Use modulo at each step to avoid overflow.
 *
 * ------------------------------------------------------------
 * Example :
 * Input  : n = 3
 * Output : 90
 *
 * Explanation :
 * i = 2 → 6 ways
 * i = 3 → 15 ways
 * Total = 1 × 6 × 15 = 90
 *
 * ------------------------------------------------------------
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 *
 ***************************************************************/

class Solution {
public:
    int M = 1e9 + 7;

    int countOrders(int n) {

        long long result = 1;

        for (int i = 2; i <= n; i++) {

            // Number of available slots for ith pair
            long long spaces = (i - 1) * 2 + 1;

            // Total valid placements
            long long possibilities = (spaces * (spaces + 1)) / 2;

            // Update result with modulo
            result = (result * possibilities) % M;
        }

        return result;
    }
};

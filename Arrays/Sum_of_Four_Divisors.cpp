/********************************************************
 * File Name   : Sum_of_Four_Divisors.cpp
 * Problem     : Sum of Four Divisors
 * Platform    : LeetCode
 * Difficulty  : Medium
 *
 * Description :
 * Given an integer array nums, return the sum of divisors
 * of all numbers that have exactly four divisors.
 *
 * Approach :
 * - For each number, iterate till sqrt(num)
 * - Count divisors and accumulate their sum
 * - Early exit if divisor count exceeds 4
 *
 * Time Complexity  : O(n * sqrt(max(nums)))
 * Space Complexity : O(1)
 *
 ********************************************************/

class Solution {
public:

    int findSumDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        // Loop till sqrt(num)
        for (int fact = 1; fact * fact <= num; fact++) {

            if (num % fact == 0) {
                int other = num / fact;

                // Perfect square case
                if (fact == other) {
                    divisors += 1;
                    sum += fact;
                } 
                // Pair of divisors
                else {
                    divisors += 2;
                    sum += (fact + other);
                }
            }

            // Early termination
            if (divisors > 4)
                return 0;
        }

        // Only return sum if exactly 4 divisors
        return (divisors == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int num : nums)
            result += findSumDivisors(num);

        return result;
    }
};

/*****************************************************************************************
 * Problem: 762. Prime Number of Set Bits in Binary Representation
 * Platform: LeetCode
 * Difficulty: Easy
 *
 * Description:
 * Given two integers left and right, return the count of numbers in the
 * inclusive range [left, right] having a prime number of set bits in their
 * binary representation.
 *
 * A set bit means the number of 1's in the binary form of a number.
 *
 * Example:
 * Input: left = 6, right = 10
 * Output: 4
 *
 *****************************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:

    /*
     * Function: isPrime
     * -----------------
     * Checks whether a given number is prime.
     *
     * Prime numbers are numbers greater than 1
     * that have no divisors other than 1 and itself.
     *
     * Time Complexity: O(sqrt(n))
     */
    bool isPrime(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    /*
     * Function: countPrimeSetBits
     * ---------------------------
     * Iterates through each number in range [left, right].
     * For each number:
     *   1. Count number of set bits using built-in function.
     *   2. Check if that count is prime.
     *   3. If yes → increment answer.
     *
     * __builtin_popcount(x)
     * Returns number of 1s in binary representation of x.
     *
     * Time Complexity:
     *   O(n * log n)  (popcount + prime check)
     *
     * Space Complexity:
     *   O(1)
     */
    int countPrimeSetBits(int left, int right) {

        int count = 0;

        for (int i = left; i <= right; i++) {

            // Count set bits in binary representation
            int setBits = __builtin_popcount(i);

            // Check if set bit count is prime
            if (isPrime(setBits)) {
                count++;
            }
        }

        return count;
    }
};


/*****************************************************************************************
 * Interview Insight:
 *
 * 1. Maximum value of right ≤ 10^6
 * 2. Maximum possible set bits ≤ 20
 *
 * So instead of checking prime every time,
 * we can pre-store prime numbers up to 20:
 *
 * Prime set = {2,3,5,7,11,13,17,19}
 *
 * This allows O(1) prime check.
 *
 *****************************************************************************************/

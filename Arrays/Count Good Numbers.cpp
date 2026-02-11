/*
===============================================================
Problem Name  : Count Good Numbers
Platform      : LeetCode
Problem Link  : https://leetcode.com/problems/count-good-numbers/
Author        : Saurabh Singh
Language      : C++
Approach      : Binary Exponentiation (Fast Power)
Time Complexity  : O(log n)
Space Complexity : O(log n)  // due to recursion stack
===============================================================

Problem Summary:
----------------
A digit string is considered "good" if:

1. Digits at even indices (0-based indexing) are even digits.
   Possible digits = {0, 2, 4, 6, 8} → 5 choices

2. Digits at odd indices are prime digits.
   Possible digits = {2, 3, 5, 7} → 4 choices

Given n, return total number of good digit strings of length n.
Answer must be modulo 1e9+7.

---------------------------------------------------------------
Mathematical Idea:
------------------

Even positions count = ceil(n/2) = (n + 1) / 2
Odd positions count  = floor(n/2) = n / 2

Total good numbers = 5^(ceil(n/2)) × 4^(floor(n/2))

Since n can be very large (up to 10^15),
we use Fast Exponentiation (Binary Exponentiation).

---------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Solution {
public:
    
    const int M = 1e9 + 7;

    /*
    ---------------------------------------------------------------
    Function: findpower
    Purpose : Computes (a^b) % M using Binary Exponentiation
    ---------------------------------------------------------------
    Logic:
        If b == 0 → return 1
        Compute half = a^(b/2)
        Square it
        If b is odd → multiply by a
    ---------------------------------------------------------------
    */
    long long findpower(long long a, long long b) {

        if (b == 0)
            return 1;

        long long half = findpower(a, b / 2);
        long long result = (half * half) % M;

        // If exponent is odd, multiply one extra 'a'
        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    /*
    ---------------------------------------------------------------
    Function: countGoodNumbers
    ---------------------------------------------------------------
    Returns total good numbers of length n.
    ---------------------------------------------------------------
    */
    int countGoodNumbers(long long n) {
        
        long long even_positions = (n + 1) / 2;
        long long odd_positions  = n / 2;

        return (1LL * findpower(5, even_positions) *
                findpower(4, odd_positions)) % M;
    }
};

/*
======================== Example ===============================

Input:  n = 4

Even positions = 2
Odd positions  = 2

Total = 5^2 * 4^2
      = 25 * 16
      = 400

===============================================================
*/

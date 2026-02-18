/*
    ============================================================
    Problem: Alternating Bits
    Platform: LeetCode
    Language: C++
    Author: Saurabh Singh
    ============================================================

    🧠 Problem Statement:
    Given a positive integer n, return true if and only if
    its binary representation has alternating bits.

    ------------------------------------------------------------
    📌 Example:

    Input:  n = 5
    Binary: 101
    Output: true

    Input:  n = 7
    Binary: 111
    Output: false

    ------------------------------------------------------------
    💡 Approach (Bit Manipulation Trick):

    Step 1:
        Right shift the number by 1 bit.
        n >> 1

    Step 2:
        XOR the original number with shifted number.
        result = n ^ (n >> 1)

        If bits were alternating,
        result will become all 1s (like 11111).

    Example:
        n = 5 → 101
        n>>1 = 010
        XOR  = 111

    Step 3:
        Check if result is of form 111...111

        Trick:
            For a number of form 111...111,
            (x & (x + 1)) == 0

        Example:
            x = 111 (7)
            x+1 = 1000 (8)
            AND = 0

    ------------------------------------------------------------
    ⏱ Time Complexity: O(1)
    📦 Space Complexity: O(1)

    ------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {

        // Step 1: XOR with right-shifted value
        unsigned int result = n ^ (n >> 1);

        // Step 2: Check if result is all 1s
        return (result & (result + 1)) == 0;
    }
};

/*
    ------------------------------------------------------------
    🔎 Dry Run Example:

    n = 10
    Binary = 1010

    n >> 1 = 0101
    XOR    = 1111

    result = 15

    result & (result + 1)
    = 1111 & 10000
    = 0

    ✅ Returns true
    ------------------------------------------------------------
*/

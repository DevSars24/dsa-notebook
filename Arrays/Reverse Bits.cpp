/*
    ================================================================
    🧠 LeetCode Problem: Reverse Bits
    🔗 Question Link:
    https://leetcode.com/problems/reverse-bits/
    ================================================================

    📌 Problem Statement:
    Reverse bits of a given 32-bit unsigned integer.

    Example:
    Input:  n = 00000010100101000001111010011100
    Output: 00111001011110000010100101000000

    ================================================================

    💡 Intuition:

    Every integer is stored in binary form (32 bits).
    To reverse the bits:
        - Take the last bit of n (using n & 1)
        - Add it to result
        - Left shift result
        - Right shift n
        - Repeat this process 32 times

    Basically:
        Extract bit → Append to result → Shift

    ================================================================

    ⚙️ Approach:

    1. Initialize result = 0
    2. Loop 32 times (because integer is 32 bits)
    3. Each iteration:
            - Left shift result
            - Add last bit of n
            - Right shift n
    4. Return result

    ================================================================

    ⏱ Time Complexity:
        O(32) ≈ O(1)   (Constant time)

    📦 Space Complexity:
        O(1)

    ================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        
        int result = 0;

        for(int i = 0; i < 32; i++) {
            
            // Left shift result to make space
            result <<= 1;

            // Add last bit of n to result
            result |= (n & 1);

            // Right shift n to process next bit
            n >>= 1;
        }

        return result;
    }
};


/*
    ================================================================
    🧪 Dry Run Example:

    Suppose n = 5
    Binary: 00000000000000000000000000000101

    Iteration 1:
        result = 0 << 1 = 0
        result |= 1  → result = 1
        n >>= 1 → 2

    Iteration 2:
        result = 1 << 1 = 2
        result |= 0 → result = 2
        n >>= 1 → 1

    Iteration 3:
        result = 2 << 1 = 4
        result |= 1 → result = 5
        n >>= 1 → 0

    Continue till 32 iterations...

    Final reversed result returned.
    ================================================================
*/

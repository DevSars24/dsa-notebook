/*
    ------------------------------------------------------------
    Problem: Check if Digits Are Equal in String After Operations
    Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations/

    ------------------------------------------------------------
    Problem Statement:
    You are given a string s consisting of digits.
    Perform the following operation repeatedly until the length
    of the string becomes 2:

    - Replace each digit with the sum of itself and the next digit,
      modulo 10.

    After all operations, check whether the final two digits are equal.

    ------------------------------------------------------------
    Approach:
    - Keep reducing the string length until only two digits remain.
    - In each iteration:
        - Replace s[i] with (s[i] + s[i+1]) % 10.
    - Once the string length becomes 2, compare both digits.

    ------------------------------------------------------------
    Example:
    Input:  "3902"
    Step 1: (3+9)%10 = 2, (9+0)%10 = 9, (0+2)%10 = 2  -> "292"
    Step 2: (2+9)%10 = 1, (9+2)%10 = 1               -> "11"
    Output: true

    ------------------------------------------------------------
    Time Complexity:
    O(n^2)
    (Each reduction step takes O(n), and there are O(n) steps)

    Space Complexity:
    O(1)
    (In-place modification of the string)

    ------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        // Reduce the string until only two digits remain
        while (n > 2) {
            for (int i = 0; i < n - 1; i++) {
                s[i] = ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            }
            n--;
        }

        // Check if the final two digits are equal
        return s[0] == s[1];
    }
};

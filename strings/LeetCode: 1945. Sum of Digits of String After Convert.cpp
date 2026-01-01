/*
    LeetCode: 1945. Sum of Digits of String After Convert

    Problem:
    Given a string s consisting of lowercase letters and an integer k.
    Convert s into a number by mapping a -> 1, b -> 2, ..., z -> 26,
    then repeatedly replace the number with the sum of its digits k times.
    Return the final integer.

    Approach:
    1. Convert each character to its alphabet position.
    2. Concatenate them into a string.
    3. Repeat k times:
        - Calculate digit sum.
        - Convert sum back to string.
    4. Return the final value.

    Time Complexity: O(n + k * digits)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {

        int x = s.size();
        string words = "";

        // Convert characters to numbers
        for (int i = 0; i < x; i++) {
            words += to_string(s[i] - 'a' + 1);
        }

        int result = 0;

        // Perform k transformations
        while (k--) {
            int sum = 0;
            for (char ch : words) {
                sum += ch - '0';
            }
            result = sum;
            words = to_string(sum);
        }

        return result;
    }
};

/*
    File: str.cpping_to_integer_atoi
    Problem: LeetCode 8 - String to Integer (atoi)
    Author: Saurabh Singh Rajput
    Approach: Two pointers (i & j)
    
    Steps:
    1. Skip leading whitespaces
    2. Detect sign (+ or -)
    3. Convert numeric digits to integer
    4. Handle overflow using INT_MAX / INT_MIN

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int sign = 1;
        int i = 0, j = 0;
        int n = s.size();

        // Step 1: Skip leading spaces
        while (j < n && s[j] == ' ') {
            j++;
        }

        // Step 2: Handle sign
        if (j < n && (s[j] == '+' || s[j] == '-')) {
            if (s[j] == '-') {
                sign = -1;
            }
            j++;
        }

        // Step 3: Convert digits
        i = j;
        long long result = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');

            // Step 4: Handle overflow
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(result * sign);
    }
};

/*
------------------------------------------------------------
LeetCode Problem: Break a Palindrome
Link: https://leetcode.com/problems/break-a-palindrome/

Problem Statement:
You are given a palindromic string `palindrome`.
Replace exactly one character such that the resulting string
is NOT a palindrome and is lexicographically smallest possible.

If it is impossible to do so, return an empty string.

------------------------------------------------------------

Approach:

1. If the length of the string is 1:
   - It is impossible to break the palindrome.
   - Return an empty string.

2. Traverse only the first half of the string:
   - If you find a character that is not 'a',
     change it to 'a' and return immediately.
   - This ensures the lexicographically smallest result.

3. If all characters in the first half are 'a':
   - Change the last character to 'b' to break the palindrome.

------------------------------------------------------------

Time Complexity : O(n)
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.size();

        // Case: Single character palindrome
        if (n == 1) {
            return "";
        }

        // Try to replace first non-'a' in the first half
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // If all characters are 'a', change the last character
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};

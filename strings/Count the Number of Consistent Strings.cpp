/*
------------------------------------------------------------
Problem: Count the Number of Consistent Strings
Platform: LeetCode
Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
Difficulty: Easy
------------------------------------------------------------

Problem Statement:
You are given a string `allowed` containing distinct characters
and an array of strings `words`.

A string is considered "consistent" if all characters in the string
appear in the string `allowed`.

Return the number of consistent strings in the array `words`.

------------------------------------------------------------
Approach:
- Store all characters of `allowed` in an unordered_set for O(1) lookup.
- For each word:
    - Check if every character exists in the set.
    - If yes, count it as a consistent string.

Why unordered_set?
- Fast lookup
- No need to track frequency, only presence

------------------------------------------------------------
Time Complexity:
- O(A + total_characters_in_words)

Space Complexity:
- O(A), where A = size of `allowed`

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Checks if all characters of 'word' are present in 'allowed'
    bool is_identical(string allowed, string word) {
        unordered_set<char> allowedSet;

        for (char ch : allowed) {
            allowedSet.insert(ch);
        }

        for (char ch : word) {
            if (allowedSet.find(ch) == allowedSet.end()) {
                return false;
            }
        }

        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;

        for (string word : words) {
            if (is_identical(allowed, word)) {
                count++;
            }
        }

        return count;
    }
};

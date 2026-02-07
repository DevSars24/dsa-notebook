/*
    Problem:
    --------
    Given two strings s and t, check whether s is a subsequence of t.

    A subsequence is formed by deleting some (or none) characters
    from t without changing the order of remaining characters.

    ------------------------------------------------------------
    Intuition:
    ----------
    Use two pointers:
    - Pointer i traverses string s
    - Pointer j traverses string t

    Try to match characters of s in order while scanning t.
    If all characters of s are matched, s is a subsequence of t.

    ------------------------------------------------------------
    Approach:
    ---------
    1. Initialize two pointers i = 0, j = 0
    2. Traverse while both pointers are within bounds
    3. If s[i] == t[j], move i forward
    4. Always move j forward
    5. At the end, if i == length of s, return true

    ------------------------------------------------------------
    Time Complexity:
    ----------------
    O(n), where n = length of t

    Space Complexity:
    -----------------
    O(1)

    ------------------------------------------------------------
    Author: Saurabh Singh
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == m;
    }
};

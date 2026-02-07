/*
    Problem:
    --------
    Given two strings str1 and str2, determine whether str2
    can be formed as a subsequence of str1.

    You are allowed to increment characters in str1 cyclically:
    'a' -> 'b', 'b' -> 'c', ..., 'z' -> 'a'

    Each character in str1 can be incremented at most once.

    ----------------------------------------------------------
    Intuition:
    ----------
    Use a two-pointer technique.
    - Traverse str1 and try to match characters of str2 in order.
    - A character matches if:
        1. It is already equal
        2. Incrementing it once makes it equal
        3. 'z' incremented cyclically becomes 'a'

    ----------------------------------------------------------
    Time Complexity:
    ----------------
    O(n), where n = length of str1

    Space Complexity:
    -----------------
    O(1)

    ----------------------------------------------------------
    Author: Saurabh Singh
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        int i = 0, j = 0;

        while (i < m && j < n) {
            // Match directly OR after one cyclic increment
            if (
                str1[i] == str2[j] ||
                str1[i] + 1 == str2[j] ||
                str1[i] - 25 == str2[j]   // 'z' -> 'a'
            ) {
                j++;
            }
            i++;
        }

        return j == n;
    }
};

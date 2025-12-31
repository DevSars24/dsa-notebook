/*
------------------------------------------------------------
Problem: Rotate String
Platform: LeetCode
Link: https://leetcode.com/problems/rotate-string/
Difficulty: Easy
------------------------------------------------------------

Problem Statement:
Given two strings `s` and `goal`, return true if and only if
`s` can become `goal` after some number of rotations.

A rotation means moving the first character of `s` to the end.

------------------------------------------------------------
Approach (Substring Rotation Trick):
- If lengths are different, rotation is impossible.
- Concatenate the original string with itself.
- If `goal` is a substring of the doubled string,
  then `goal` is a valid rotation of `s`.

Why this works?
- All possible rotations of a string exist as substrings
  inside `s + s`.

------------------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(n)

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();

        if (m != n) return false;

        string x = s;
        x += s;

        if (x.find(goal) != string::npos)
            return true;

        return false;
    }
};

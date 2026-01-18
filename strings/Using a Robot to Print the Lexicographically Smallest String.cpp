/*
===========================================================
LeetCode 2434
Using a Robot to Print the Lexicographically Smallest String
===========================================================

Platform   : LeetCode
Difficulty : Medium
Link       : https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

-----------------------------------------------------------
Problem Summary:
-----------------------------------------------------------
You are given a string s and a robot that holds an empty string t.
The robot can perform the following operations:

1. Take the FIRST character of s and append it to string t.
2. Take the LAST character of t and write it onto paper.

Repeat operations until both s and t are empty.

Goal:
Return the lexicographically smallest string that can be written
on the paper.

-----------------------------------------------------------
Key Insight:
-----------------------------------------------------------
- String t behaves like a STACK (LIFO).
- We must decide WHEN to pop from t and write to paper.
- Greedy rule:
    Pop from t ONLY IF its top is <= the smallest character
    that will appear in the future part of s.

-----------------------------------------------------------
Core Idea:
-----------------------------------------------------------
Precompute the minimum character to the RIGHT of each index
in s, so we always know:
"Will a smaller character come later or not?"

-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {

        int n = s.length();

        /*
        ---------------------------------------------------
        Step 1: Build future minimum array
        ---------------------------------------------------
        minCharToRight[i] = minimum character in s[i...n-1]
        This helps us decide whether to pop from stack or wait.
        */

        vector<char> minCharToRight(n);
        minCharToRight[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minCharToRight[i] = min(s[i], minCharToRight[i + 1]);
        }

        /*
        ---------------------------------------------------
        Step 2: Initialize stack and answer
        ---------------------------------------------------
        t     -> behaves like a stack
        paper -> final answer
        */

        string t = "";
        string paper = "";

        int i = 0;

        /*
        ---------------------------------------------------
        Step 3: Process characters of s one by one
        ---------------------------------------------------
        */

        while (i < n) {

            // Operation 1: move s[i] to stack t
            t.push_back(s[i]);

            /*
            Find minimum character that may appear in the future
            If we are at the last index, future min is s[i] itself
            */
            char futureMin =
                (i + 1 < n) ? minCharToRight[i + 1] : s[i];

            /*
            ---------------------------------------------------
            Greedy Decision:
            ---------------------------------------------------
            While:
            - stack is not empty
            - top of stack <= future minimum character
            Then:
            - pop from stack
            - write to paper
            */
            while (!t.empty() && t.back() <= futureMin) {
                paper.push_back(t.back());
                t.pop_back();
            }

            i++;
        }

        /*
        ---------------------------------------------------
        Step 4: Empty remaining stack
        ---------------------------------------------------
        Once s is exhausted, everything in t can be written.
        */

        while (!t.empty()) {
            paper.push_back(t.back());
            t.pop_back();
        }

        return paper;
    }
};

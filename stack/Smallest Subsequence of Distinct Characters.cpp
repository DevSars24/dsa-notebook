/*
===============================================================================
Problem Name   : Smallest Subsequence of Distinct Characters
Platform       : LeetCode
Problem ID     : 1081 (Same as LeetCode 316)
Difficulty     : Medium
Topic          : Monotonic Stack + Greedy

-------------------------------------------------------------------------------
Problem Link:
https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

-------------------------------------------------------------------------------
Problem Statement:
Given a string s, return the lexicographically smallest subsequence of s
that contains all the distinct characters of s exactly once.

Rules:
1. Each character must appear exactly once.
2. Relative order must be preserved.
3. Result must be lexicographically smallest.

-------------------------------------------------------------------------------
Examples:
Input : "bcabc"
Output: "abc"

Input : "cbacdcbc"
Output: "acdb"

-------------------------------------------------------------------------------
Core Intuition (MOST IMPORTANT):
--------------------------------
We want the smallest string in dictionary order, but:
- we cannot change relative order
- we cannot remove a character if it will NOT appear again later

So for each character, we decide:
❓ Can I remove a bigger character from the left if a smaller one appears?

Answer:
YES — but only if the removed character appears again in the future.

-------------------------------------------------------------------------------
Key Observations:
--------------------------------
1. We process characters from LEFT to RIGHT.
2. We maintain a MONOTONIC INCREASING STACK (lexicographically).
3. We POP from stack only when:
   - stack top > current character
   - AND stack top appears again later (future safe)
4. We avoid duplicates using a visited[] array.

-------------------------------------------------------------------------------
Why lastIndex[] ?
--------------------------------
To know whether a character will appear again in the future.
If lastIndex[ch] > currentIndex → safe to remove now.

-------------------------------------------------------------------------------
Why visited[] ?
--------------------------------
To ensure each character appears exactly once in the result.

-------------------------------------------------------------------------------
POP Condition (Golden Rule):
--------------------------------
Pop while:
- stack is not empty
- top > current character
- top appears again later

-------------------------------------------------------------------------------
Dry Run Example:
--------------------------------
Input: "cbacdcbc"

Process:
c → push
b → pop c, push b
a → pop b, push a
c → push
d → push
c → skip (already used)
b → cannot pop d (d won't appear again), push b
c → skip

Result = "acdb"

-------------------------------------------------------------------------------
Time Complexity:
--------------------------------
O(n)

Space Complexity:
--------------------------------
O(n)

-------------------------------------------------------------------------------
Key Takeaway:
--------------------------------
Monotonic Stack is used when:
- order must be preserved
- greedy local decisions affect global result
- we compare current element with previous ones

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {

        int n = s.size();

        // last occurrence of each character
        vector<int> lastIndex(26, -1);
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            // skip if already included
            if (visited[ch - 'a'])
                continue;

            // pop larger characters if they appear again later
            while (!st.empty() &&
                   st.top() > ch &&
                   lastIndex[st.top() - 'a'] > i) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // build answer from stack
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

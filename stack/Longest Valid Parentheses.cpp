/*
===============================================================================
Problem Name   : Longest Valid Parentheses
Platform       : GeeksforGeeks
Difficulty     : Hard
Link           :
https://www.geeksforgeeks.org/problems/valid-substring0624/1

-------------------------------------------------------------------------------
Problem Statement:
Given a string consisting only of '(' and ')',
find the length of the longest contiguous (continuous)
valid parentheses substring.

A parentheses string is valid if:
1. Every '(' has a corresponding ')'
2. ')' always comes after its '('
3. The substring must be continuous

-------------------------------------------------------------------------------
Key Insight / Learning:
--------------------------------
❌ Counting total valid pairs is NOT the same as
   finding the longest valid substring.

Initially, I was solving:
→ "How many valid parentheses exist?"

But the actual problem asks:
→ "What is the LONGEST CONTIGUOUS valid block?"

This realization changes the entire approach.

-------------------------------------------------------------------------------
Correct Approach (Index-based Stack):
--------------------------------
We use a stack to store indices instead of characters.

Why indices?
Because substring length = current_index - last_invalid_index

Steps:
1. Push -1 initially (acts as base index)
2. For '(' → push its index
3. For ')':
   - pop one index
   - if stack becomes empty → push current index as new base
   - else → valid substring length = i - stack.top()

-------------------------------------------------------------------------------
Example:
Input: ")()())"

Index: 0 1 2 3 4 5
Char : ) ( ) ( ) )

Valid substrings:
()() → length = 4

-------------------------------------------------------------------------------
Time Complexity : O(n)
Space Complexity: O(n)

-------------------------------------------------------------------------------
Why char-stack / sum += 2 fails?
--------------------------------
That approach only counts total valid pairs.
It cannot track substring boundaries or continuity.

-------------------------------------------------------------------------------
Author Notes:
-------------
This problem taught me an important DSA lesson:
"Correct intuition matters more than correct syntax."

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(string& s) {

        stack<int> st;
        st.push(-1);          // base index for valid substring
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    // invalid ')', reset base
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};

/*
------------------------------------------------------------
Problem: 2696. Minimum String Length After Removing Substrings
Platform: LeetCode
Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
Difficulty: Easy
------------------------------------------------------------

Problem Statement:
You are given a string `s` consisting of uppercase English letters.
You can repeatedly remove substrings "AB" or "CD" from the string.

After each removal, the string concatenates and may form new valid
substrings again.

Return the minimum possible length of the final string.

------------------------------------------------------------
Approach (Stack-based):
- Use a stack to process characters one by one.
- For each character:
    - If the top of the stack with current character forms "AB" or "CD",
      pop the stack (remove the pair).
    - Otherwise, push the character onto the stack.
- Stack naturally handles cascading removals after concatenation.

------------------------------------------------------------
Why Stack?
- Adjacent pair removal
- Automatic backtracking after deletions
- Linear time solution

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
    int minLength(string s) {
        stack<char> st;
        int alive;

        for (char ch : s) {
            alive = 1;

            if (!st.empty() && st.top() == 'A' && ch == 'B') {
                st.pop();
                alive = 0;
            }

            if (!st.empty() && st.top() == 'C' && ch == 'D') {
                st.pop();
                alive = 0;
            }

            if (alive == 1) {
                st.push(ch);
            }
        }

        return st.size();
    }
};

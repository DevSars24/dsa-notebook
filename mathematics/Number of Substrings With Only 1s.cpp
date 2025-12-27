/*
===============================================================================
Problem Name   : Number of Substrings With Only 1s
Platform       : LeetCode
Problem ID     : 1513
Difficulty     : Medium (but feels Easy once insight clicks)
Topic          : String | Counting | Math

-------------------------------------------------------------------------------
Problem Link:
https://leetcode.com/problems/number-of-substrings-with-only-1s/

-------------------------------------------------------------------------------
Problem Statement:
Given a binary string s, return the number of substrings that contain
only '1's. Since the answer can be very large, return it modulo (1e9 + 7).

-------------------------------------------------------------------------------
Examples:
Input : "0110111"
Output: 9

Input : "101"
Output: 2

-------------------------------------------------------------------------------
Key Observation (CORE INSIGHT):
--------------------------------
Substrings containing only '1's can exist ONLY inside
continuous blocks of consecutive '1's.

We never need to generate substrings explicitly.

-------------------------------------------------------------------------------
Block Insight:
--------------------------------
If a block contains k consecutive '1's:

"111...1" (k times)

Number of substrings from this block =
k * (k + 1) / 2

Reason:
length 1 substrings → k
length 2 substrings → k-1
...
length k substrings → 1

Sum = 1 + 2 + ... + k = k*(k+1)/2

-------------------------------------------------------------------------------
Approach:
--------------------------------
1. Traverse the string once.
2. Maintain a counter `count` for consecutive '1's.
3. When '0' appears:
   - Add contribution of previous block using formula.
   - Reset count.
4. After loop, add contribution of last block.
5. Apply modulo at every step to avoid overflow.

-------------------------------------------------------------------------------
Why Modulo Is Important:
--------------------------------
For long strings with large blocks of '1's,
k*(k+1)/2 can exceed integer limits.

-------------------------------------------------------------------------------
Time Complexity:
--------------------------------
O(n)

Space Complexity:
--------------------------------
O(1)

-------------------------------------------------------------------------------
Key Takeaway:
--------------------------------
When substrings are uniform (same character),
count blocks instead of generating substrings.

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSub(string s) {

        const long long MOD = 1e9 + 7;

        long long count = 0;
        long long ans = 0;

        for (char ch : s) {
            if (ch == '1') {
                count++;               // extend current block
            } else {
                ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;
                count = 0;             // block ends
            }
        }

        // last block (if string ends with '1')
        ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;

        return (int)ans;
    }
};

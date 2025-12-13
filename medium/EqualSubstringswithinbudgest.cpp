// LeetCode Problem: 1208. Get Equal Substrings Within Budget
// Link: [https://leetcode.com/problems/get-equal-substrings-within-budget/](https://leetcode.com/problems/get-equal-substrings-within-budget/)
// Difficulty: Medium

/*
============================ PROBLEM DESCRIPTION ============================
You are given two strings s and t of the same length and an integer maxCost.

Changing the i-th character of s to the i-th character of t costs:
|s[i] - t[i]|   (absolute difference of ASCII values)

Your task:
Return the maximum length of a substring of s that can be changed into the
corresponding substring of t with total cost <= maxCost.

If no such substring exists, return 0.

============================ KEY OBSERVATION ============================
Each index i has an independent cost:
cost[i] = |s[i] - t[i]|

The problem reduces to:
➡ Find the longest contiguous subarray whose total cost is <= maxCost.

This is a classic VARIABLE-SIZE SLIDING WINDOW problem.

============================ SLIDING WINDOW INTUITION ============================

* Expand the window using pointer j
* Add the cost of index j to the current window cost
* If the cost exceeds maxCost, shrink the window from the left
* At all times, maintain a valid window (cost <= maxCost)

============================ ALGORITHM ============================

1. Initialize two pointers i and j
2. Maintain currCost = total cost of current window [i..j]
3. Expand j and add abs(s[j] - t[j]) to currCost
4. While currCost > maxCost, shrink window from left (i++)
5. Update maximum length

============================ TIME & SPACE COMPLEXITY ============================
Time Complexity: O(n)
Space Complexity: O(1)

============================ IMPLEMENTATION ============================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int equalSubstring(string s, string t, int maxCost) {
int n = s.size();
int i = 0, j = 0;
int currcost = 0;
int maxlen = 0;

```
    while (j < n) {
        currcost += abs(s[j] - t[j]);

        // Shrink window until cost is valid
        while (currcost > maxCost) {
            currcost -= abs(s[i] - t[i]);
            i++;
        }

        maxlen = max(maxlen, j - i + 1);
        j++;
    }

    return maxlen;
}
```

};

/*
============================ EXAMPLE ============================
Input:
s = "abcd"
t = "bcdf"
maxCost = 3

Costs:
|a-b| = 1
|b-c| = 1
|c-d| = 1
|d-f| = 2

Longest valid window is "abc" with total cost = 3.

============================ KEY TAKEAWAYS ============================
✔ Convert characters into cost differences
✔ Use sliding window for longest subarray under budget
✔ Always maintain a valid window
✔ Clean O(n) interview-ready solution
*/

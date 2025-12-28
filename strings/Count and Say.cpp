/*
====================================================
📌 Problem: Count and Say
🔢 Problem No: 38
🔗 Link: https://leetcode.com/problems/count-and-say/
🏷️ Platform: LeetCode
🎯 Difficulty: Medium
====================================================

🧠 Problem Statement:
The count-and-say sequence is a sequence of digit strings defined as:
- countAndSay(1) = "1"
- countAndSay(n) is the run-length encoding (RLE) of countAndSay(n - 1)

Run-length encoding describes the previous string by counting
consecutive identical digits and "saying" them.

----------------------------------------------------
💡 Intuition:
- At every step, we only need the previous string.
- The task is NOT about counting total frequency of characters.
- Order and consecutive grouping matter.
- Hence, HashMap is NOT suitable here.

Although this problem may look like DP, full tabulation is unnecessary.
However, using tabulation can help beginners reason clearly.

----------------------------------------------------
🚫 Common Mistake:
Using HashMap for RLE → ❌ Wrong
Reason: HashMap loses order and consecutive grouping.

----------------------------------------------------
✅ Approach (Iterative with Tabulation):
1. Use a vector<string> dp where:
   dp[i] = count-and-say result for i
2. Base case:
   dp[1] = "1"
3. For i = 2 to n:
   dp[i] = build(dp[i - 1])
4. The build() function performs run-length encoding
   using a linear scan.

----------------------------------------------------
⏱️ Time Complexity:
O(total characters generated), feasible since n ≤ 30

🧠 Space Complexity:
O(n) due to tabulation (can be optimized to O(1))

----------------------------------------------------
✅ Solution:
*/

class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n + 1);
        dp[1] = "1";

        for (int i = 2; i <= n; i++) {
            dp[i] = build(dp[i - 1]);
        }

        return dp[n];
    }

    string build(const string& s) {
        string res = "";
        int count = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                res += to_string(count);
                res += s[i - 1];
                count = 1;
            }
        }

        // Handle last group
        res += to_string(count);
        res += s.back();

        return res;
    }
};

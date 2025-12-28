/*
====================================================
📌 Problem: Check If Two String Arrays are Equivalent
🔢 Problem No: 1662
🔗 Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
🏷️ Platform: LeetCode
🎯 Difficulty: Easy
====================================================

🧠 Problem Statement:
Given two string arrays word1 and word2,
check whether concatenating all strings in word1
results in the same string as concatenating all strings in word2.

----------------------------------------------------
💡 Intuition:
- Order matters.
- Final comparison is between two complete strings.
- Simply concatenate all strings from both arrays
  and compare the results.

----------------------------------------------------
🚫 Why NOT HashMap?
- We are NOT checking frequency of characters.
- Sequence and order are important.
- HashMap would break ordering.

----------------------------------------------------
✅ Approach:
1. Create two strings x1 and x2.
2. Append all elements of word1 into x1.
3. Append all elements of word2 into x2.
4. Compare x1 and x2.

----------------------------------------------------
⏱️ Time Complexity:
O(n + m)
where n = total characters in word1
      m = total characters in word2

🧠 Space Complexity:
O(n + m) for concatenated strings

----------------------------------------------------
✅ Solution:
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x1 = "", x2 = "";

        for (int i = 0; i < word1.size(); i++) {
            x1 += word1[i];
        }

        for (int i = 0; i < word2.size(); i++) {
            x2 += word2[i];
        }

        return x1 == x2;
    }
};

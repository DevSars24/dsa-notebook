/*
====================================================
📌 Problem: Check if the Sentence Is Pangram
🔗 Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
🏷️ Platform: LeetCode
🆔 Problem No: 1832
🎯 Difficulty: Easy
====================================================

🧠 Problem Statement:
A pangram is a sentence where every letter of the English alphabet
appears at least once.

Given a string `sentence` containing only lowercase English letters,
return true if it is a pangram, otherwise return false.

----------------------------------------------------
💡 Approach / Intuition:
- There are exactly 26 lowercase English letters.
- If the length of the string is less than 26, it can never be a pangram.
- Use a frequency array of size 26 to track occurrences of each character.
- Traverse the string and increment the count for each character.
- Finally, check if any character count is zero.

----------------------------------------------------
⏱️ Time Complexity:
O(n), where n is the length of the sentence.

🧠 Space Complexity:
O(1), since the frequency array size is constant (26).

----------------------------------------------------
✅ Solution:
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        vector<int> charpres(26, 0);

        // If sentence length is less than 26, it can't be a pangram
        if (n < 26) return false;

        // Count character occurrences
        for (char ch : sentence) {
            charpres[ch - 'a']++;
        }

        // Check if any character is missing
        for (int i = 0; i < 26; i++) {
            if (charpres[i] == 0)
                return false;
        }

        return true;
    }
};

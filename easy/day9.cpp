/*
------------------------------------------------------------
🟦 LeetCode 125 — Valid Palindrome
------------------------------------------------------------

🔶 QUESTION:
Given a string s, return true if it is a palindrome, or false otherwise.

A palindrome means:
  - Read same forward & backward
  - Ignore non-alphanumeric characters
  - Ignore cases (A == a)

Example:
------------------------------------------------------------
Input:  "A man, a plan, a canal: Panama"
Output: true

Input:  "race a car"
Output: false
------------------------------------------------------------


🟦 APPROACH (Two Pointer Method)
------------------------------------------------------------

We use two indices:
  i → start of the string
  j → end of the string

Step-by-step logic:
1. Move i forward until s[i] is alphanumeric
2. Move j backward until s[j] is alphanumeric
3. Compare lowercase versions of s[i] and s[j]
4. If mismatch → return false
5. If match → move both pointers inward

Continue until i >= j.

This ensures:
  ✔ All special characters are skipped  
  ✔ Case-insensitive comparison  
  ✔ Efficient O(n) solution  

------------------------------------------------------------


🟦 TIME & SPACE COMPLEXITY
------------------------------------------------------------
Time Complexity:   O(n)  
Space Complexity:  O(1)   (two pointers only)

------------------------------------------------------------


🟦 FINAL C++ SOLUTION
------------------------------------------------------------
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            char left = s[i];
            char right = s[j];

            // Skip non-alphanumeric from left side
            if (!isalnum(left)) {
                i++;
                continue;
            }

            // Skip non-alphanumeric from right side
            if (!isalnum(right)) {
                j--;
                continue;
            }

            // Compare lowercase characters
            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};


/************************************************************
 🧮 Sum of Numbers (Given as Strings)
 ------------------------------------------------------------
 Problem Link:
 https://www.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1

 Difficulty: Easy–Medium
 ------------------------------------------------------------

 ❓ PROBLEM STATEMENT
 ------------------------------------------------------------
 You are given two non-negative numbers represented as strings
 s1 and s2.

 Your task is to find their sum and return it as a string.

 Note:
 - Numbers can be very large (beyond built-in integer limits)
 - Result should not contain leading zeros

 ------------------------------------------------------------

 📥 INPUT
 ------------------------------------------------------------
 - string s1
 - string s2

 ------------------------------------------------------------

 📤 OUTPUT
 ------------------------------------------------------------
 - string representing the sum of s1 and s2

 ------------------------------------------------------------

 🧪 EXAMPLES
 ------------------------------------------------------------
 Input:
   s1 = "123"
   s2 = "456"
 Output:
   "579"

 Input:
   s1 = "00123"
   s2 = "0456"
 Output:
   "579"

 ------------------------------------------------------------

 🧠 INTUITION
 ------------------------------------------------------------
 Since the numbers can be very large, we cannot convert them
 directly into integers (int / long long).

 So we perform **manual addition**, exactly like we do on paper:
 - Start adding digits from the rightmost side
 - Keep track of carry
 - Store result digit by digit
 - Reverse the final result

 ------------------------------------------------------------

 🔑 CORE IDEA
 ------------------------------------------------------------
 - Use two pointers starting from the end of both strings
 - Add corresponding digits + carry
 - Push the result digit into a string
 - Reverse the result at the end
 - Remove leading zeros if any

 ------------------------------------------------------------

 🛠️ APPROACH (STEP-BY-STEP)
 ------------------------------------------------------------
 1. Initialize pointers:
      i = s1.length() - 1
      j = s2.length() - 1
      carry = 0

 2. Loop while:
      i >= 0 OR j >= 0 OR carry exists

 3. Add:
      - digit from s1 (if exists)
      - digit from s2 (if exists)
      - carry

 4. Push (sum % 10) to result string
 5. Update carry = sum / 10
 6. Reverse the result string
 7. Remove leading zeros
 8. Return final string

 ------------------------------------------------------------

 ⏱️ TIME & SPACE COMPLEXITY
 ------------------------------------------------------------
 Time Complexity:
   O(max(len(s1), len(s2)))

 Space Complexity:
   O(max(len(s1), len(s2)))  (result string)

 ------------------------------------------------------------

 ✅ WHY THIS SOLUTION IS CORRECT
 ------------------------------------------------------------
 ✔ Handles very large numbers
 ✔ Mimics manual digit-by-digit addition
 ✔ Correctly manages carry
 ✔ Removes leading zeros
 ✔ Fully accepted on GeeksforGeeks

 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findSum(string &s1, string &s2) {

        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string ans = "";

        // Add digits from right to left
        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            if (i >= 0)
                sum += s1[i--] - '0';

            if (j >= 0)
                sum += s2[j--] - '0';

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        // Reverse the result
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int idx = 0;
        while (idx < ans.size() - 1 && ans[idx] == '0') {
            idx++;
        }

        return ans.substr(idx);
    }
};

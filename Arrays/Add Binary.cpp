/*
================================================================================
🟢 Problem Title  : Add Binary
🔗 Problem Link   : https://leetcode.com/problems/add-binary/
🏷 Platform        : LeetCode
💻 Language        : C++
================================================================================

📘 Problem Statement:
Given two binary strings a and b, return their sum as a binary string.

You are not allowed to convert the entire binary string into an integer directly.
The addition must be performed similar to manual binary addition.

--------------------------------------------------------------------------------
🧠 Intuition:

Binary addition works exactly like decimal addition, but with base 2.

Rules:
0 + 0 = 0
0 + 1 = 1
1 + 1 = 0 (carry 1)
1 + 1 + 1 = 1 (carry 1)

We traverse both strings from the last index (rightmost bit),
keep track of carry, and build the result string.

--------------------------------------------------------------------------------
🚀 Approach:

1️⃣ Initialize two pointers:
    - m = a.length() - 1
    - n = b.length() - 1

2️⃣ Maintain:
    - carry = 0
    - result string

3️⃣ Loop while m >= 0 OR n >= 0:
    - Start sum with carry
    - If m >= 0 → add a[m]
    - If n >= 0 → add b[n]
    - Append (sum % 2) to result
    - Update carry = sum / 2
    - Move pointers left

4️⃣ After loop:
    - If carry still exists → append it

5️⃣ Reverse the result string

--------------------------------------------------------------------------------
⏱ Time Complexity:
O(max(N, M))
Where N = length of a, M = length of b

We traverse both strings once.

--------------------------------------------------------------------------------
📦 Space Complexity:
O(max(N, M))
For storing the result string.

--------------------------------------------------------------------------------
✅ Why This Works Efficiently?

- No integer conversion (avoids overflow).
- Linear traversal.
- Constant extra variables.
- Optimal solution.

--------------------------------------------------------------------------------
🎯 Key Concept Used:
✔ Two Pointer Technique
✔ Carry Handling
✔ String Manipulation

================================================================================
*/

class Solution {
public:
    string addBinary(string a, string b) {

        int m = a.length() - 1;
        int n = b.length() - 1;

        string result = "";

        int sum = 0;
        int carry = 0;

        while (m >= 0 || n >= 0) {

            sum = carry;

            if (m >= 0) {
                sum += a[m] - '0';
                m--;
            }

            if (n >= 0) {
                sum += b[n] - '0';
                n--;
            }

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        if (carry) {
            result += '1';
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

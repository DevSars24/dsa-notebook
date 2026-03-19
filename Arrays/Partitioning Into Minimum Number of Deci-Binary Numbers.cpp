/*
===========================================================
🧠 Problem: Partitioning Into Minimum Number of Deci-Binary Numbers
🔗 Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

👨‍💻 Author: Saurabh Singh Rajput
===========================================================

📌 Problem Statement:
Given a decimal number n as a string, return the minimum number of 
positive deci-binary numbers needed so that they sum up to n.

A deci-binary number is a number where each digit is either 0 or 1.

-----------------------------------------------------------

💡 Key Observation (IMPORTANT 🔥):
- Each deci-binary number contributes at most '1' to each digit position.
- So, to form a digit like '9', we need at least 9 deci-binary numbers.

👉 Therefore:
The answer is simply the maximum digit present in the string.

-----------------------------------------------------------

🧠 Approach:
1. Traverse the string
2. Find the maximum digit
3. Return that digit as integer

-----------------------------------------------------------

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)

-----------------------------------------------------------

✅ Example:

Input:  n = "32"
Output: 3

Explanation:
- Max digit = 3 → minimum 3 deci-binary numbers required

-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        // Step 1: Find maximum digit in string
        char maxch = *max_element(n.begin(), n.end());

        // Step 2: Convert char to integer and return
        return maxch - '0';
    }
};

/*
-----------------------------------------------------------
🚀 Dry Run:

Input: "82734"

Digits → 8, 2, 7, 3, 4
Max digit → 8

So, answer = 8

-----------------------------------------------------------

🎯 Interview Insight:
- This problem tests observation, not brute force
- Instead of constructing numbers, we directly derive answer

-----------------------------------------------------------

💥 Pro Tip:
Whenever digits contribute independently → think "max digit"

===========================================================
*/

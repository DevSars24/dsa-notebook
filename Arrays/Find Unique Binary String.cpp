/*
===========================================================
🧠 Problem: Find Unique Binary String
🔗 Link: https://leetcode.com/problems/find-unique-binary-string/

👨‍💻 Author: Saurabh Singh Rajput
===========================================================

📌 Problem Statement:
Given an array of n unique binary strings nums, each of length n,
return a binary string of length n that does NOT appear in nums.

-----------------------------------------------------------

💡 Key Idea (IMPORTANT 🔥):
- Convert binary strings → integers
- Store in a set
- Try all numbers from 0 → n
- First missing number = answer

👉 Then convert back to binary string

-----------------------------------------------------------

🧠 Approach:
1. Convert each binary string into integer using stoi(base 2)
2. Store in unordered_set
3. Iterate from 0 to n:
   - If number not in set → convert to binary
4. Return binary string of length n

-----------------------------------------------------------

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

-----------------------------------------------------------

✅ Example:

Input: nums = ["01","10"]
Output: "00"

Explanation:
- Possible strings: "00", "01", "10", "11"
- Missing: "00"

-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<int> st;

        // Step 1: Convert binary strings to integers
        for(string &num : nums){
            st.insert(stoi(num, 0, 2));
        }

        int n = nums.size();

        // Step 2: Find missing number
        for(int number = 0; number <= n; number++){
            if(st.find(number) == st.end()){

                // Step 3: Convert number → binary string
                string result = bitset<16>(number).to_string();

                // Step 4: Return last n bits
                return result.substr(16 - n, n);
            }
        }

        return "";
    }
};

/*
-----------------------------------------------------------
🚀 Dry Run:

Input: ["111","011","001"]

Binary → Decimal:
111 → 7
011 → 3
001 → 1

Check from 0:
0 ❌ not present → answer

Binary of 0 = "000"

-----------------------------------------------------------

🎯 Interview Insight:
- This is a "Missing Number + Encoding" problem
- Key trick: binary ↔ integer conversion

-----------------------------------------------------------

💥 Advanced Insight (🔥 BEST APPROACH):

👉 Diagonal Trick (Cantor’s Diagonalization)

for(int i = 0; i < n; i++){
    result += (nums[i][i] == '0') ? '1' : '0';
}

✔ Guarantees unique string
✔ O(n) time, O(1) space

===========================================================
*/

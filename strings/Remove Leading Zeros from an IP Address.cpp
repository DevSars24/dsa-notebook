/*
===========================================================
📌 Problem: Remove Leading Zeros from an IP Address
📍 Platform: GeeksforGeeks
🔗 Question Link:
https://www.geeksforgeeks.org/problems/remove-leading-zeros-from-an-ip-address3530/1

===========================================================
🧠 Problem Description:
Given a string representing an IP address, remove all the
leading zeros from each segment of the IP address.

Rules:
- IP address consists of 4 segments separated by '.'
- Remove only leading zeros of each segment
- If a segment becomes empty after removing zeros,
  replace it with "0"

===========================================================
✅ Example:
Input:
"001.200.001.004"

Output:
"1.200.1.4"

===========================================================
💡 Intuition:
IP address ek string hai jo '.' se split hoti hai.
Har segment me:
- Pehle leading zeros skip karo
- Agar koi digit bachi ho → use copy karo
- Agar segment sirf zeros ka ho → "0" add karo

Is problem me:
- Split karna zaroori nahi
- Direct string traversal zyada clean aur efficient hai

===========================================================
⚙️ Approach:
- Two pointer technique use ki
- Pointer i → current segment ka start
- Pointer j → leading zeros skip karta hai
- Valid digits ko result string me add karte hain
- Dot '.' ko preserve karte hain

===========================================================
⏱️ Complexity:
Time Complexity: O(n)
Space Complexity: O(n)

===========================================================
✨ Key Takeaway:
- String parsing
- Two pointer traversal
- Real-world formatted input handling
- Reusable pattern for URL, CSV, logs parsing

===========================================================
*/

class Solution {
public:
    string newIPAdd(string s) {

        int n = s.size();
        int i = 0;
        string ans = "";

        while (i < n) {
            int j = i;

            // Step 1: Skip leading zeros in the segment
            while (j < n && s[j] == '0')
                j++;

            // Step 2: If segment has digits (not just zeros)
            if (j < n && s[j] != '.') {
                while (j < n && s[j] != '.') {
                    ans += s[j];
                    j++;
                }
            } else {
                // Segment was all zeros
                ans += '0';
            }

            // Step 3: Add dot if present
            if (j < n && s[j] == '.') {
                ans += '.';
                j++;
            }

            // Move to next segment
            i = j;
        }

        return ans;
    }
};

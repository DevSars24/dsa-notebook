/**
 * 📌 Problem: Minimum Number of Flips to Make the Binary String Alternating
 * 🔗 Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
 *
 * 💡 Approach:
 * - Since the string is circular, we simulate all rotations by doubling the string.
 * - Create two alternating patterns:
 *      s1 = "101010..."
 *      s2 = "010101..."
 * - Use sliding window of size n over the doubled string.
 * - Count mismatches (flips needed) with both patterns.
 * - Take minimum over all windows.
 *
 * ⏱ Time Complexity: O(n)
 * 🧠 Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {

        int n = s.length();

        // Step 1: Double the string to handle circular rotations
        s = s + s;

        // Step 2: Create alternating patterns
        string s1 = "", s2 = "";

        for(int i = 0; i < 2 * n; i++){
            s1 += (i % 2 ? '0' : '1'); // Pattern: 1010...
            s2 += (i % 2 ? '1' : '0'); // Pattern: 0101...
        }

        int result = INT_MAX;

        int flip1 = 0; // mismatches with s1
        int flip2 = 0; // mismatches with s2

        int i = 0;

        // Step 3: Sliding window
        for(int j = 0; j < 2 * n; j++){

            // Add current character mismatch
            if(s[j] != s1[j]) flip1++;
            if(s[j] != s2[j]) flip2++;

            // Maintain window size = n
            if(j - i + 1 > n){
                if(s[i] != s1[i]) flip1--;
                if(s[i] != s2[i]) flip2--;
                i++;
            }

            // Step 4: Update result when window size is exactly n
            if(j - i + 1 == n){
                result = min(result, min(flip1, flip2));
            }
        }

        return result;
    }
};

/*
🔍 Example:
Input:  s = "111000"
Output: 2

✨ Explanation:
Rotate and flip minimum characters to make alternating string.

--------------------------------------------------------

🔥 Key Takeaways:
✔ Convert circular problem → linear using doubling
✔ Compare with both alternating patterns
✔ Use sliding window for efficiency

--------------------------------------------------------
*/

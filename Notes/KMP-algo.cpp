/***************************************************************
 📌 Topic: KMP Algorithm – LPS (Longest Prefix Suffix)
 📍 Core Idea: Prefix function using two pointers (pre, suf)

 ---------------------------------------------------------------
 🧠 What is LPS?

 lps[i] = length of the longest proper prefix of s[0..i]
          which is also a suffix of s[0..i]

 Proper prefix ≠ whole string

 ---------------------------------------------------------------
 🧠 Why LPS?

 • Avoids re-checking characters
 • Allows linear time string processing
 • Backbone of KMP pattern matching
 • Used in palindrome & string trick problems

 ---------------------------------------------------------------
 🧩 Variables used (exact as board):

 vector<int> lps(s.size(), 0);

 pre = prefix pointer
 suf = suffix pointer

 ---------------------------------------------------------------
 🧠 Pointer Meaning:

 pre → how many characters already matched (prefix length)
 suf → current index we are trying to compute LPS for

 ---------------------------------------------------------------
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

void buildLPS(const string& s, vector<int>& lps) {

    int pre = 0;   // prefix pointer
    int suf = 1;   // suffix pointer

    // LPS[0] is always 0, so start from index 1
    while (suf < s.size()) {

        // CASE 1: Characters match
        if (s[pre] == s[suf]) {

            // prefix extended by 1
            lps[suf] = pre + 1;

            // move both pointers
            pre++;
            suf++;
        }
        else {
            // CASE 2: Characters do not match

            if (pre == 0) {
                // No prefix to fall back to
                lps[suf] = 0;
                suf++;
            }
            else {
                // Fall back prefix pointer
                pre = lps[pre - 1];
            }
        }
    }
}

/***************************************************************
 🧪 Dry Run Example (VERY IMPORTANT)

 String: "aabaa"
 Index :  0 1 2 3 4
 Chars :  a a b a a

 Step-by-step:

 suf = 1, pre = 0
 a == a → lps[1] = 1

 suf = 2, pre = 1
 b != a → pre = lps[0] = 0
 b != a → lps[2] = 0

 suf = 3, pre = 0
 a == a → lps[3] = 1

 suf = 4, pre = 1
 a == a → lps[4] = 2

 Final LPS = [0,1,0,1,2]

 ---------------------------------------------------------------
 ⚠️ IMPORTANT CLARIFICATION:

 LPS does NOT mean palindrome.
 "aabaa" palindrome hona coincidence hai.

 Example: "abcab"
 LPS = [0,0,0,1,2] → not palindrome

 ---------------------------------------------------------------
 ***************************************************************/

/***************************************************************
 🧠 Key Observations (Interview Gold)

 1️⃣ suf pointer NEVER goes backward
 2️⃣ pre pointer jumps using lps[pre-1]
 3️⃣ No nested loops → O(n)
 4️⃣ pre == 0 case avoids infinite loop

 ---------------------------------------------------------------
 ***************************************************************/

/***************************************************************
 📌 Where this LPS code is used:

 • KMP Pattern Matching
 • Min chars to add for palindrome
 • Longest Happy Prefix
 • Repeated Substring Pattern
 • String periodicity problems

 ---------------------------------------------------------------
 🧠 Mental Model (ONE LINE):

 "LPS remembers how much prefix is already matched,
 so we never re-compare characters."

 ---------------------------------------------------------------
 ***************************************************************/

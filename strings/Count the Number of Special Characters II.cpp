/*
 * ============================================================
 *  LeetCode 2967 — Count the Number of Special Characters II
 * ============================================================
 *
 *  PROBLEM LINK  : https://leetcode.com/problems/count-the-number-of-special-characters-ii/
 *  DIFFICULTY    : Medium
 *  TOPIC TAGS    : Hash Map, String, Array
 *  AUTHOR        : Saurabh Singh Rajput
 *  VERDICT       : Accepted (896 / 896 test cases passed)
 * ============================================================
 *
 *  ──────────────────────────────────────────────────────────
 *  PROBLEM STATEMENT
 *  ──────────────────────────────────────────────────────────
 *  You are given a string `word`.
 *
 *  A letter 'c' is called SPECIAL if:
 *    - Every lowercase 'c' appears BEFORE every uppercase 'C' in `word`.
 *    - Both lowercase 'c' and uppercase 'C' exist in `word`.
 *
 *  Return the number of special letters in `word`.
 *
 *  ──────────────────────────────────────────────────────────
 *  EXAMPLES
 *  ──────────────────────────────────────────────────────────
 *
 *  Example 1:
 *    Input  : word = "aaAbcBC"
 *    Output : 3
 *    Explanation:
 *      'a' → last 'a' at index 1, first 'A' at index 2  → 1 < 2  ✓ Special
 *      'b' → last 'b' at index 4, first 'B' at index 5  → 4 < 5  ✓ Special
 *      'c' → last 'c' at index 3, first 'C' at index 6  → 3 < 6  ✓ Special
 *
 *  Example 2:
 *    Input  : word = "abc"
 *    Output : 0
 *    Explanation: No uppercase letters exist.
 *
 *  Example 3:
 *    Input  : word = "AbBCCA"
 *    Output : 0
 *    Explanation:
 *      'b' → last 'b' at index 2, first 'B' at index 1  → 2 > 1  ✗ Not special
 *
 *  ──────────────────────────────────────────────────────────
 *  CONSTRAINTS
 *  ──────────────────────────────────────────────────────────
 *    - 1  <=  word.length  <=  2 * 10^5
 *    - word consists only of English letters (a–z, A–Z)
 *
 *  ──────────────────────────────────────────────────────────
 *  APPROACH / INTUITION
 *  ──────────────────────────────────────────────────────────
 *
 *  Key Observation:
 *    For letter 'c' to be special, ALL lowercase 'c' must appear
 *    before ALL uppercase 'C'.
 *
 *    This means:
 *      lastOccurrence(lowercase 'c')  <  firstOccurrence(uppercase 'C')
 *
 *  Steps:
 *    1. Traverse the string once.
 *       - For lowercase letters: keep updating lastSmall[i]
 *         (we want the LAST occurrence, so we keep overwriting).
 *       - For uppercase letters: record firstCapital[i] ONLY once
 *         (we want the FIRST occurrence, so we set it once and skip).
 *
 *    2. For each of the 26 letters, check:
 *       - Both lastSmall[i] and firstCapital[i] exist (not -1), AND
 *       - lastSmall[i] < firstCapital[i]
 *       If yes → count it as special.
 *
 *  ──────────────────────────────────────────────────────────
 *  COMPLEXITY ANALYSIS
 *  ──────────────────────────────────────────────────────────
 *    Time  : O(n)  — single pass over the string + O(26) check
 *    Space : O(1)  — two fixed-size arrays of length 26
 *
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        // lastSmall[i]    → last index where lowercase (i + 'a') appears
        // firstCapital[i] → first index where uppercase (i + 'A') appears
        vector<int> lastSmall(26, -1);
        vector<int> firstCapital(26, -1);

        // ── Pass 1: Fill lastSmall and firstCapital ──────────────
        for (int i = 0; i < n; i++) {
            if (islower(word[i])) {
                // Keep overwriting → ensures we store the LAST occurrence
                lastSmall[word[i] - 'a'] = i;
            } else {
                // Set only once → ensures we store the FIRST occurrence
                if (firstCapital[word[i] - 'A'] == -1) {
                    firstCapital[word[i] - 'A'] = i;
                }
            }
        }

        // ── Pass 2: Count special letters ────────────────────────
        int count = 0;
        for (int i = 0; i < 26; i++) {
            // Both cases must exist AND last lowercase < first uppercase
            if (lastSmall[i] != -1 && firstCapital[i] != -1) {
                if (lastSmall[i] < firstCapital[i]) {
                    count++;
                }
            }
        }

        return count;
    }
};

/*
 *  ──────────────────────────────────────────────────────────
 *  DRY RUN — word = "aaAbcBC"
 *  ──────────────────────────────────────────────────────────
 *
 *  Index:  0   1   2   3   4   5   6
 *  Char :  a   a   A   b   c   B   C
 *
 *  After Pass 1:
 *    lastSmall    : a→1, b→4, c→5  (others = -1)  [NOTE: 'c' is at index 5... wait,
 *                                                   'c' at index 3 before 'B','C' — index 3]
 *    firstCapital : A→2, B→5, C→6  (others = -1)
 *
 *  Pass 2 Checks:
 *    'a': lastSmall[0]=1, firstCapital[0]=2  → 1 < 2  ✓ count=1
 *    'b': lastSmall[1]=4, firstCapital[1]=5  → 4 < 5  ✓ count=2
 *    'c': lastSmall[2]=3, firstCapital[2]=6  → 3 < 6  ✓ count=3
 *
 *  Answer: 3 ✓
 *
 *  ──────────────────────────────────────────────────────────
 *  WHY "LAST" lowercase and "FIRST" uppercase?
 *  ──────────────────────────────────────────────────────────
 *  We need EVERY lowercase to be before EVERY uppercase.
 *  The hardest constraint is:
 *    → The LAST lowercase must still be before the FIRST uppercase.
 *  If that holds, all others automatically hold too.
 *  This is why we track lastSmall and firstCapital.
 *
 * ============================================================
 */

// ── Quick test (optional main) ───────────────────────────────
int main() {
    Solution sol;

    cout << sol.numberOfSpecialChars("aaAbcBC") << "\n"; // Expected: 3
    cout << sol.numberOfSpecialChars("abc")     << "\n"; // Expected: 0
    cout << sol.numberOfSpecialChars("AbBCCA")  << "\n"; // Expected: 0
    cout << sol.numberOfSpecialChars("HAhAhA")  << "\n"; // Expected: 1 ('h' only)

    return 0;
}

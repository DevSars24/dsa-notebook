/*
    Problem:
    --------
    Given a string `s` consisting of lowercase English letters,
    find the length of the longest substring such that
    all characters present in that substring occur the same number of times.
    Such a substring is called "balanced".

    Example:
    --------
    Input:  s = "aabbab"
    Output: 4
    Explanation: "aabb" is a balanced substring (a -> 2, b -> 2)

    ---------------------------------------------------------------
    Approach:
    ---------
    1. Use a brute-force approach with optimization using frequency array.
    2. Fix a starting index `i`.
    3. For every ending index `j >= i`, keep updating character frequencies.
    4. Check if the current frequency distribution is balanced.
    5. Update the maximum length accordingly.

    ---------------------------------------------------------------
    Time Complexity:
    ----------------
    O(N^2 * 26)
    - N^2 for all substrings
    - 26 for checking character frequencies

    Space Complexity:
    -----------------
    O(26) ≈ O(1)
    - Frequency array for lowercase letters

    ---------------------------------------------------------------
    Author: Saurabh Singh
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Function to check if all non-zero frequencies
    in the array are equal.
*/
bool checkBalance(const vector<int>& freq) {
    int common = 0;

    for (int count : freq) {
        if (count > 0) {
            if (common == 0)
                common = count;
            else if (count != common)
                return false;
        }
    }
    return true;
}

/*
    Returns the length of the longest balanced substring.
*/
int longestBalanced(string s) {
    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);

        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            if (checkBalance(freq)) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << longestBalanced(s) << endl;
    return 0;
}

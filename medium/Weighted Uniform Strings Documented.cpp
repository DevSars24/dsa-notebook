// Weighted Uniform Strings - Fully Documented Solution
// Problem Link: https://www.hackerrank.com/challenges/weighted-uniform-string/problem


//DESCRIPTION:
// A uniform substring is made of SAME CHARACTER repeated consecutively.
// Example: "a", "aa", "aaa" are uniform. But "ab", "aba" are not.
// Each character has a weight: 'a' = 1, 'b' = 2, ... 'z' = 26.
// Weight of a uniform substring = character_weight * substring_length.
// Goal: Precompute ALL possible uniform substring weights for string s.
// Then answer queries: if weight exists → print "Yes", else "No".
// -----------------------------------------------------------------------------
// INTUITION:
// Instead of generating substrings (which is slow), we scan string once.
// While scanning, we track how many times the SAME character repeats.
// Example: "aaabbc"
// a → 1, aa → 2, aaa → 3
// b → 2, bb → 4
// c → 3
// ALL weights: {1,2,3,2,4,3}
// Use unordered_set<int> to store unique weights for O(1) lookup.
// -----------------------------------------------------------------------------
// DRY RUN (for input: "abccddde"):
// a → 1 → store 1
// b → 2 → store 2
// c → 3 → store 3
// cc → 6 → store 6
// d → 4 → store 4
// dd → 8 → store 8
// ddd → 12 → store 12
// e → 5 → store 5
// Final SET = {1,2,3,6,4,8,12,5}
// -----------------------------------------------------------------------------
// WHY unordered_set? (IMPORTANT)
// Fast O(1) lookup for each query.
// Automatically handles duplicates.
// We do not need counts, only presence.
// -----------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {

    unordered_set<int> weights;  // stores all uniform substring weights
    char prev = '#';             // previous character
    int curr_weight = 0;         // running weight for the current uniform block

    // Scan the string
    for(char c : s) {
        int w = c - 'a' + 1; // character weight

        if(c == prev) {
            // same character continues
            curr_weight += w;
        } else {
            // new character starts, reset weight
            curr_weight = w;
        }

        // store this weight in set
        weights.insert(curr_weight);
        prev = c;
    }

    // Answer queries
    vector<string> ans;
    for(int q : queries) {
        ans.push_back(weights.count(q) ? "Yes" : "No");
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<int> queries(n);
    for(int i = 0; i < n; i++) cin >> queries[i];

    vector<string> result = weightedUniformStrings(s, queries);

    for(string &x : result) cout << x << "\n";

    return 0;
}

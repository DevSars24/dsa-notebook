#include <bits/stdc++.h>
using namespace std;

/*
 Problem:
 Longest Substring with Exactly K Unique Characters

 Approach:
 Sliding Window + HashMap

 Time Complexity: O(N)
 Space Complexity: O(K)
*/

class Solution {
public:
    int longestKSubstr(string &s, int k) {

        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int maxLength = -1;

        while (j < s.size()) {

            // include current character
            mp[s[j]]++;

            // shrink window if unique characters exceed k
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            // update answer if window has exactly k unique characters
            if (mp.size() == k) {
                maxLength = max(maxLength, j - i + 1);
            }

            j++;
        }

        return maxLength;
    }
};

int main() {
    string s;
    int k;
    cin >> s >> k;

    Solution obj;
    cout << obj.longestKSubstr(s, k) << endl;

    return 0;
}

/**
 * Problem: Count the Number of Substrings With Dominant Ones
 * Link: https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/
 * * INTUITION:
 * A substring is "dominant" if the number of 1s is at least the square of the number of 0s.
 * Let 'ones' be the count of 1s and 'zeros' be the count of 0s.
 * Condition: ones >= zeros * zeros
 * * Since the maximum length of the string is 40,000, a nested O(N^2) loop will Time Limit Exceeded (TLE).
 * However, because of the 'zeros * zeros' condition, the number of zeros in any valid dominant 
 * substring is capped at sqrt(N). For N = 40,000, sqrt(N) is 200.
 * * APPROACH:
 * 1. Precompute the positions of all '0's in a vector to allow jumping between them.
 * 2. Use a Prefix Sum array to get the count of '1's in any range [i, j] in O(1) time.
 * 3. Iterate through each possible starting index 'i'.
 * 4. For each 'i', iterate through a limited number of zeros (up to ~200).
 * 5. For a fixed number of zeros, calculate how many '1's are required and count 
 * the valid ending positions 'j' before the next zero appears.
 * * TIME COMPLEXITY: O(N * sqrt(N))
 * SPACE COMPLEXITY: O(N)
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> zeroPos;
        
        // 1. Store indices of all zeros to quickly skip blocks of ones
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeroPos.push_back(i);
            }
        }

        // 2. Prefix sum for ones: pref[i] stores count of '1's in s[0...i-1]
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == '1' ? 1 : 0);
        }

        int result = 0;

        // 3. Iterate through every possible starting point of a substring
        for (int i = 0; i < n; i++) {
            // Find the first zero that occurs at or after index i
            auto it = lower_bound(zeroPos.begin(), zeroPos.end(), i);
            
            // Case A: Substrings with 0 zeros (only ones)
            // All substrings from 'i' up to the first zero (or end of string) are valid
            int firstZeroIdx = (it == zeroPos.end()) ? n : *it;
            result += (firstZeroIdx - i);

            int zeroCount = 0;
            // Case B: Substrings with 1, 2, ... up to sqrt(N) zeros
            for (; it != zeroPos.end(); ++it) {
                zeroCount++;
                
                // If zeros^2 exceeds the remaining length, no more valid substrings possible for this 'i'
                if (zeroCount * zeroCount > n) break;

                int currZeroIdx = *it;
                // Peek at the next zero index to know the range of 1s we can include
                int nextZeroIdx = (next(it) == zeroPos.end()) ? n : *next(it);
                
                int onesRequired = zeroCount * zeroCount;
                int onesAtCurrZero = pref[currZeroIdx + 1] - pref[i];
                
                // How many more ones do we need to satisfy the condition?
                int additionalOnesNeeded = max(0, onesRequired - onesAtCurrZero);
                
                // The substring must at least end at (currZeroIdx + additionalOnesNeeded)
                int startJ = currZeroIdx + additionalOnesNeeded;
                
                // If the required end index is before the next zero, all positions between 
                // startJ and nextZeroIdx-1 are valid ending points.
                if (startJ < nextZeroIdx) {
                    result += (nextZeroIdx - startJ);
                }
            }
        }

        return result;
    }
};

// Example Usage:
int main() {
    Solution sol;
    string s = "00011";
    // Substrings: "1", "1", "11", "011", "0011" (5 total)
    // Condition: ones >= zeros^2
    cout << "Result for 00011: " << sol.numberOfSubstrings(s) << endl; 
    return 0;
}

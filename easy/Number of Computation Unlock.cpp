// LeetCode Problem: Count the Number of Computer Unlocking Permutations
// Link: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
//
// -------------------------------------------------------------
// PROBLEM SUMMARY
// -------------------------------------------------------------
// You are given an array `complexity` of size `n`.
// You must count the number of valid permutations of this array
// under the following rule:
//
//     The first element of the permutation must be the UNIQUE minimum.
//
// That means:
//   - complexity[0] must be STRICTLY smaller than every other element.
//   - If this is NOT true → answer = 0.
//   - If it IS true → the remaining (n - 1) elements can be permuted freely.
//
// Thus, the total number of valid permutations is:
//
//              (n - 1)!  modulo (1e9 + 7)
//
// -------------------------------------------------------------
// APPROACH
// -------------------------------------------------------------
// Step 1: Verify that complexity[0] is strictly the smallest element.
//         Loop from i = 1 to n-1:
//             if complexity[i] <= complexity[0] → return 0
//
// Step 2: Compute factorial(n - 1) modulo 1e9+7.
//         Example: n = 5 → compute 4! = 24.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// -------------------------------------------------------------
// IMPLEMENTATION
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long M = 1000000007; // correct modulus constant

    int countPermutations(vector<int>& complexity) {

        int n = complexity.size();
        long long result = 1;

        // Step 1: Check if the first element is strictly the smallest
        for (int i = 1; i < n; i++) {
            if (complexity[0] >= complexity[i])
                return 0;
        }

        // Step 2: Compute (n-1)! % M
        for (int i = 1; i < n; i++) {
            result = (result * i) % M;
        }

        return result;
    }
};

// -------------------------------------------------------------
// SAMPLE USAGE
// -------------------------------------------------------------
// int main() {
//     Solution s;
//     vector<int> v = {1, 5, 6, 10};
//     cout << s.countPermutations(v); // Output: 6 (3!)
// }

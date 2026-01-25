// https://leetcode.com/problems/plus-one/
// Problem 66: Plus One
// Given a large integer represented as an array of digits, increment it by one.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;      // add 1 if no carry
                return digits;
            }
            digits[i] = 0;        // digit was 9 -> becomes 0
        }

        // If all digits were 9 (e.g., [9,9,9] -> [1,0,0,0])
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> digits1 = {1, 2, 3};
    vector<int> ans1 = sol.plusOne(digits1);
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> ans2 = sol.plusOne(digits2);
    for (int x : ans2) cout << x << " ";
    cout << endl;

    // Example 3
    vector<int> digits3 = {9};
    vector<int> ans3 = sol.plusOne(digits3);
    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}

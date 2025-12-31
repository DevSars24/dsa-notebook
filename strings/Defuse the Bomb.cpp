/*
------------------------------------------------------------
Problem: 1652. Defuse the Bomb
Platform: LeetCode
Link: https://leetcode.com/problems/defuse-the-bomb/
Difficulty: Easy
------------------------------------------------------------

Problem Statement:
You are given a circular array `code` and an integer `k`.

- If k > 0, replace each element with the sum of the next k elements.
- If k < 0, replace each element with the sum of the previous |k| elements.
- If k == 0, replace each element with 0.

Return the resulting array.

------------------------------------------------------------
Approach (Brute-force with Circular Indexing):
- Handle k == 0 separately by returning a zero-filled array.
- For k > 0:
    - For each index, sum the next k elements using modulo (% n).
- For k < 0:
    - For each index, sum the previous |k| elements.
    - Use (index + n) % n to safely handle negative indices.
- Use a temporary variable to avoid modifying k during iteration.

------------------------------------------------------------
Time Complexity:
- O(n * |k|)

Space Complexity:
- O(n)

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result;
        } 
        else if (k > 0) {

            for (int i = 0; i < n; i++) {
                int sum = 0;
                int temp = k;

                sum += code[(i + 1) % n];
                while (temp > 1) {
                    sum += code[(i + temp) % n];
                    temp--;
                }

                result[i] = sum;
            }
        } 
        else { // k < 0

            for (int i = 0; i < n; i++) {
                int sum = 0;
                int temp = -k;

                sum += code[(i - 1 + n) % n];
                while (temp > 1) {
                    sum += code[(i - temp + n) % n];
                    temp--;
                }

                result[i] = sum;
            }
        }

        return result;
    }
};

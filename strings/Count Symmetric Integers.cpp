/*
------------------------------------------------------------
Problem: Count Symmetric Integers
Platform: LeetCode
Link: https://leetcode.com/problems/count-symmetric-integers/

Description:
An integer is called symmetric if it has an even number of digits
and the sum of the first half of digits is equal to the sum of the
second half of digits.

Given two integers low and high, return the number of symmetric
integers in the range [low, high].

------------------------------------------------------------
Approach:
1. Iterate from low to high.
2. Convert each number to string.
3. If length is even:
   - Split into two halves.
   - Calculate digit sum of both halves.
4. If sums are equal, increment count.

------------------------------------------------------------
Time Complexity:
O((high - low) * d)
where d is number of digits (≤ 5)

Space Complexity:
O(1)

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_symmetric(string s) {
        int n = s.size();
        int half = n / 2;
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < half; i++) {
            sum1 += s[i] - '0';
        }

        for (int i = half; i < n; i++) {
            sum2 += s[i] - '0';
        }

        return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int i = low; i <= high; i++) {
            string x = to_string(i);
            int len = x.size();

            if (len % 2 == 0 && is_symmetric(x)) {
                count++;
            }
        }
        return count;
    }
};

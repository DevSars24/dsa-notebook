/************************************************************
 * Problem: Maximum Equal Sum of Three Stacks
 * Platform: GeeksforGeeks
 *
 * Intuition:
 * Each stack has positive integers.
 * We can only remove elements from the TOP of the stack.
 *
 * Observation:
 * - If all three stack sums are equal → that's our answer.
 * - Otherwise, we must reduce the stack having the MAXIMUM sum
 *   because removing from a smaller sum stack will only
 *   reduce the possibility of equality.
 *
 * Approach (Greedy):
 * 1. Calculate sum of all three stacks.
 * 2. Maintain pointers (i, j, k) for S1, S2, S3 respectively
 *    representing how many elements are removed from top.
 * 3. While all stacks are non-empty:
 *    - If all sums are equal → return sum
 *    - Remove the top element from the stack
 *      having the maximum sum.
 *
 * Time Complexity: O(N1 + N2 + N3)
 * Space Complexity: O(1)
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualSum(int N1, int N2, int N3,
                    vector<int> &S1,
                    vector<int> &S2,
                    vector<int> &S3) {

        int sum1 = 0, sum2 = 0, sum3 = 0;

        for (int x : S1) sum1 += x;
        for (int x : S2) sum2 += x;
        for (int x : S3) sum3 += x;

        int i = 0, j = 0, k = 0;

        while (true) {

            // If any stack becomes empty
            if (i == N1 || j == N2 || k == N3)
                return 0;

            // If all sums are equal
            if (sum1 == sum2 && sum2 == sum3)
                return sum1;

            // Remove from stack having maximum sum
            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= S1[i++];
            }
            else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= S2[j++];
            }
            else {
                sum3 -= S3[k++];
            }
        }
    }
};

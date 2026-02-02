/**
 * @file SmoothDescentPeriods.cpp
 * @brief Calculates the total number of smooth descent periods in a stock price list.
 *
 * URL: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
 * 
 * A smooth descent period is defined as a contiguous subarray where
 * each price is exactly 1 less than the previous one.
 * For example: [9, 8, 7] is smooth, but [9, 8, 6] is not.
 * Each single element itself counts as a smooth period.
 * 
 * This program implements an efficient solution in O(n) time
 * by counting the length of consecutive descent segments.
 *
 * @author  
 * @date    
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Returns the total number of smooth descent periods.
     * 
     * We iterate through the prices, and maintain a counter for
     * the length of the current smooth descent sequence. Once the descent
     * breaks, we reset the counter. The number of sub-periods added is
     * equal to the length of the current descent segment.
     *
     * @param prices A vector of stock prices.
     * @return Total count of smooth descent periods.
     */
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 1;   // Start with 1 for the first individual period
        long long count = 1;    // Current smooth sequence length

        for (int i = 1; i < prices.size(); i++) {
            // If prices[i] is exactly 1 less than prices[i-1], extend current segment
            if (prices[i - 1] - prices[i] == 1) {
                count++;
            } else {
                // Reset when descent breaks
                count = 1;
            }
            result += count; // Add all sub-periods ending at index i
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> prices = {3, 2, 1, 4};
    long long answer = sol.getDescentPeriods(prices);

    cout << "Number of smooth descent periods: " << answer << endl;
    // Expected output: 6
    // Explanation: 
    // [3], [2], [1], [4], [3,2], [2,1]
    
    return 0;
}

/*
===============================================================================
Problem Name   : Stock Span Problem
Platform       : GeeksforGeeks / Coding Ninjas
Difficulty     : Medium
Topic          : Stack (Monotonic Stack)

-------------------------------------------------------------------------------
Problem Statement:
Given an array prices[] where prices[i] is the stock price on day i,
calculate the stock span for each day.

The stock span of a day i is defined as the maximum number of consecutive
days just before the given day (including the current day) for which the
price of the stock was less than or equal to today's price.

-------------------------------------------------------------------------------
Example:
Input:
prices = [100, 80, 60, 70, 60, 75, 85]

Output:
[1, 1, 1, 2, 1, 4, 6]

Explanation:
- Day 0 (100): no previous days → span = 1
- Day 3 (70): previous smaller prices → [60] → span = 2
- Day 6 (85): previous smaller prices → [75, 60, 70, 60, 80] → span = 6

-------------------------------------------------------------------------------
Brute Force Approach:
--------------------------------
For each day, scan left until price > current price.
Time Complexity: O(n²)  ❌ (Too slow for large inputs)

-------------------------------------------------------------------------------
Optimal Approach (Monotonic Stack):
--------------------------------
We maintain a stack that stores indices of days.
The stack is kept MONOTONIC DECREASING (prices decreasing).

Algorithm:
1. Traverse prices from left to right.
2. Pop indices from stack while price at those indices
   is STRICTLY LESS than current day's price.
3. If stack becomes empty:
      span = i + 1
   Else:
      span = i - stack.top()
4. Push current index into stack.

-------------------------------------------------------------------------------
Key Insight:
--------------------------------
We are finding the "Previous Greater or Equal Element".
The distance from that element gives the stock span.

-------------------------------------------------------------------------------
Time Complexity : O(n)
Space Complexity: O(n)

Each index is pushed and popped at most once.

-------------------------------------------------------------------------------
Author Notes:
-------------
Stock Span is a CLASSIC monotonic stack problem.
Same pattern appears in:
- Previous Greater Element
- Daily Temperatures
- Largest Rectangle in Histogram

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findStockSpans(vector<int>& prices) {

    int n = prices.size();
    vector<int> span(n);
    stack<int> st;   // stores indices

    for (int i = 0; i < n; i++) {

        // Remove all previous prices strictly smaller than current
        while (!st.empty() && prices[st.top()] < prices[i]) {
            st.pop();
        }

        // If stack empty, span is entire range till now
        span[i] = st.empty() ? (i + 1) : (i - st.top());

        // Push current index
        st.push(i);
    }

    return span;
}

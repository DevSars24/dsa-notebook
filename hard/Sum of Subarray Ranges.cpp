/*
===========================================================
Problem Name : Sum of Subarray Ranges
Platform     : GeeksforGeeks
Difficulty   : Medium
Link         : https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1

-----------------------------------------------------------
Problem Statement:
Given an integer array arr[], the range of a subarray is defined
as the difference between the maximum and minimum element in
that subarray.

Your task is to return the sum of ranges of all possible
subarrays of the array.

-----------------------------------------------------------
Key Observation:
For any subarray:
    range = maximum - minimum

So overall answer can be written as:
    (Sum of all subarray maximums)
  - (Sum of all subarray minimums)

Instead of calculating max/min for every subarray (O(N^2)),
we calculate the contribution of each element.

-----------------------------------------------------------
Core Idea (Contribution Technique):

For each element arr[i]:
1. Count how many subarrays in which arr[i] is the MAXIMUM
2. Count how many subarrays in which arr[i] is the MINIMUM

Contribution of arr[i] =
    arr[i] × (count_as_max - count_as_min)

Final Answer = Sum of contributions of all elements

-----------------------------------------------------------
How to count contributions efficiently?

We use Monotonic Stack to find:
- Previous Greater Element (PGE)
- Next Greater Element (NGE)
- Previous Smaller Element (PSE)
- Next Smaller Element (NSE)

For element at index i:
count_as_max =
    (i - PGE[i]) × (NGE[i] - i)

count_as_min =
    (i - PSE[i]) × (NSE[i] - i)

-----------------------------------------------------------
Stack Rules (Important):
- For MAX contribution:
    - PGE uses <=
    - NGE uses <
- For MIN contribution:
    - PSE uses >=
    - NSE uses >

This avoids double counting in case of duplicates.

-----------------------------------------------------------
Dry Run Example:
arr = [1, 2, 3]

Subarrays:
[1] [2] [3] [1,2] [2,3] [1,2,3]

Sum of ranges = 4

Our method:
1 contributes as:
    max = 1 time, min = 3 times
2 contributes as:
    max = 2 times, min = 2 times
3 contributes as:
    max = 3 times, min = 1 time

Final sum = 4

-----------------------------------------------------------
Time Complexity:
O(N)
(each element pushed and popped once)

Space Complexity:
O(N)
(extra arrays + stack)

-----------------------------------------------------------
Why this approach?
✔ Optimal for large constraints (N up to 10^6)
✔ Classic monotonic stack application
✔ Interview favourite pattern
✔ Clean and scalable solution

===========================================================
*/

class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> pge(n), nge(n), pse(n), nse(n);
        stack<int> st;

        // ---------- Previous Greater Element ----------
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // ---------- Next Greater Element ----------
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // ---------- Previous Smaller Element ----------
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // ---------- Next Smaller Element ----------
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        // ---------- Contribution Calculation ----------
        for (int i = 0; i < n; i++) {
            long long maxCnt = (long long)(i - pge[i]) * (nge[i] - i);
            long long minCnt = (long long)(i - pse[i]) * (nse[i] - i);
            ans += arr[i] * (maxCnt - minCnt);
        }

        return (int)ans;
    }
};

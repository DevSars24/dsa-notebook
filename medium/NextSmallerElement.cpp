/*
===========================================================
File Name   : NextSmallerElement.cpp
Problem    : Next Smaller Element
Platform   : GeeksforGeeks
Link       : https://www.geeksforgeeks.org/problems/next-smaller-element/1

-----------------------------------------------------------
Problem Statement:
You are given an integer array arr[].
For every element in the array, find the Next Smaller Element (NSE).

The Next Smaller Element of an element x is the first element
to the right of x that is strictly smaller than x.

If no such element exists, assign -1.

-----------------------------------------------------------
Examples:

Input:
arr = [4, 8, 5, 2, 25]
Output:
[2, 5, 2, -1, -1]

Input:
arr = [13, 7, 6, 12]
Output:
[7, 6, -1, -1]

-----------------------------------------------------------
Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^5

-----------------------------------------------------------
Expected Complexity:
Time  : O(n)
Space : O(n)

-----------------------------------------------------------
Intuition:
For every element, we want the first smaller element on its right.
A brute-force approach would check all elements on the right, leading
to O(n^2) time.

To optimize, we use a monotonic stack.

The stack stores indices of elements whose Next Smaller Element
has not been found yet.

-----------------------------------------------------------
Approach (Monotonic Stack):
1. Traverse the array from left to right.
2. Maintain a stack that keeps indices of elements in increasing order.
3. For each element:
   - While stack is not empty and current element is smaller than
     the element at stack's top:
        - Current element is the Next Smaller Element of stack top.
        - Update result and pop the stack.
4. Push current index onto the stack.
5. After traversal, elements left in the stack do not have any
   smaller element to the right → assign -1.

-----------------------------------------------------------
Algorithm:
1. Initialize an empty stack.
2. Loop through the array from i = 0 to n-1.
3. While stack is not empty and arr[stack.top()] > arr[i]:
      arr[stack.top()] = arr[i]
      pop stack
4. Push current index into the stack.
5. After the loop, assign -1 to all remaining indices in the stack.
6. Return the modified array.

-----------------------------------------------------------
Dry Run:
Input: [4, 8, 5, 2, 25]

Step-by-step:
- 5 resolves 8 → 8 → 5
- 2 resolves 5 → 5 → 2
- 2 resolves 4 → 4 → 2
- 25 has no smaller element → -1

Output: [2, 5, 2, -1, -1]

-----------------------------------------------------------
Time Complexity:
O(n)
Each element is pushed and popped at most once.

-----------------------------------------------------------
Space Complexity:
O(n)
Stack space in worst case.

-----------------------------------------------------------
Why This Solution?
✔ Optimal and efficient
✔ Uses monotonic stack pattern
✔ Handles large input sizes
✔ Interview-standard approach

===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;   // stores indices

        for (int i = 0; i < n; i++) {

            // resolve elements waiting for a smaller element
            while (!st.empty() && arr[st.top()] > arr[i]) {
                arr[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        // elements with no smaller element to the right
        while (!st.empty()) {
            arr[st.top()] = -1;
            st.pop();
        }

        return arr;
    }
};

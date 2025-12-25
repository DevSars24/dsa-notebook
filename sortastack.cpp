/*
===========================================================
File Name   : SortAStack.cpp
Problem    : Sort a Stack
Platform   : GeeksforGeeks
Difficulty : Medium
Link       : https://www.geeksforgeeks.org/problems/sort-a-stack/1

-----------------------------------------------------------
Problem Description:
You are given a stack of integers.
Your task is to sort the stack in ascending order such that:
- The smallest element is at the bottom of the stack
- The largest element is at the top of the stack

-----------------------------------------------------------
Examples:

Input:
st = [1, 2, 3]
Output:
[3, 2, 1]

Input:
st = [41, 3, 32, 2, 11]
Output:
[41, 32, 11, 3, 2]

-----------------------------------------------------------
Approach Used:
Vector + Sorting

-----------------------------------------------------------
Intuition:
A stack does not allow random access, making direct sorting difficult.
To simplify:
1. Remove all elements from the stack.
2. Store them in a container that supports sorting.
3. Sort the elements.
4. Push them back into the stack in sorted order.

This ensures the largest element ends up on the top of the stack.

-----------------------------------------------------------
Step-by-Step Algorithm:
1. Initialize an empty vector.
2. Pop all elements from the stack and store them in the vector.
3. Sort the vector in ascending order.
4. Push elements from the vector back into the stack in order.

-----------------------------------------------------------
Dry Run:
Input Stack (top → bottom):
[11, 2, 32, 3, 41]

After extracting:
Vector = [11, 2, 32, 3, 41]

After sorting:
Vector = [2, 3, 11, 32, 41]

After pushing back:
Stack (top → bottom):
[41, 32, 11, 3, 2]

-----------------------------------------------------------
Time Complexity:
O(n log n)
- Sorting the vector dominates the complexity.

-----------------------------------------------------------
Space Complexity:
O(n)
- Extra space used to store stack elements.

-----------------------------------------------------------
Why This Solution?
✔ Simple and easy to understand
✔ Uses STL sort for reliability
✔ Suitable when extra space is allowed
✔ Ideal for quick implementation

-----------------------------------------------------------
Note:
This approach uses an auxiliary data structure (vector).
A recursive solution without extra space also exists but is
more complex and less intuitive.

===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sortStack(stack<int> &st) {
        
        vector<int> nums;
        
        // Extract elements from stack
        while (!st.empty()) {
            nums.push_back(st.top());
            st.pop();
        }
        
        // Sort elements
        sort(nums.begin(), nums.end());
        
        // Push back into stack
        for (int x : nums) {
            st.push(x);
        }
    }
};

/*
===========================================================
Problem Name : Subarrays with First Element Minimum
Platform     : GeeksforGeeks
Difficulty   : Medium
Link         : https://www.geeksforgeeks.org/problems/subarrays-with-first-element-minimum/1

-----------------------------------------------------------
Problem Statement:
You are given an array arr[].
Count the number of subarrays such that the first element
of the subarray is the minimum element in that subarray.

A subarray is valid if:
first_element <= every other element in the subarray.

-----------------------------------------------------------
Key Observation:
For any index i:
A subarray starting at i remains valid
UNTIL we encounter an element smaller than arr[i].

So for index i:
- Find the first index j > i such that arr[j] < arr[i]
- All subarrays starting at i and ending before j are valid

-----------------------------------------------------------
Approach Used:
Monotonic Stack (Next Smaller Element to the Right)

Steps:
1. Use a stack to find the index of the next smaller element
   to the right for every index.
2. Store that index in an array `nextright[]`
3. If no smaller element exists, store n
4. For each index i:
   Number of valid subarrays = nextright[i] - i
5. Sum up for all indices

-----------------------------------------------------------
Important Detail (Equal Case):
Equal elements are ALLOWED in valid subarrays.
Hence we use STRICT comparison ( > ) in stack condition.

-----------------------------------------------------------
Example:
arr = [1, 2, 1]

nextright = [3, 2, 3]

Index 0: 3 - 0 = 3  -> [1], [1,2], [1,2,1]
Index 1: 2 - 1 = 1  -> [2]
Index 2: 3 - 2 = 1  -> [1]

Total = 5

-----------------------------------------------------------
Time Complexity:
O(N)

Space Complexity:
O(N)

-----------------------------------------------------------
Why this works:
- Stack ensures each element is pushed and popped once
- Efficient handling of next smaller boundaries
- Perfect fit for this problem

===========================================================
*/

class Solution {
public:
    int countSubarrays(vector<int> &arr) {
       
        int n = arr.size();
        int sum = 0;
        stack<int> st;
        vector<int> nextright(n, n);  // default n
        
        for (int i = 0; i < n; i++) {
            
            // STRICT comparison: equal elements allowed
            while (!st.empty() && arr[st.top()] > arr[i]) {
                nextright[st.top()] = i;   // store index
                st.pop();
            }
            st.push(i);
        }
     
        for (int i = 0; i < n; i++) {
            sum += (nextright[i] - i);
        }
       
        return sum;
    }
};

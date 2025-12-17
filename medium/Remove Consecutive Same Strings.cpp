/*
Problem Name:
Remove Consecutive Same Strings

Problem Link:
https://www.geeksforgeeks.org/problems/string-manipulation3706/1
?page=1&difficulty[]=0&category[]=Stack&sortBy=submissions

Problem Statement:
Given an array of strings, remove consecutive duplicate strings.
Whenever two adjacent strings are the same, they cancel each other.
Return the count of strings left after all possible removals.

Approach:
- Use a stack of strings
- Traverse the array:
    • If stack is empty → push
    • If current string != stack top → push
    • Else (same string) → pop (cancel)
- Return stack size

Time Complexity: O(N × L)
Space Complexity: O(N)
Where L is the average length of a string
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool issame(string a, string b) {
        int x = a.size();
        int y = b.size();
        
        if (x != y) return false;
        
        for (int i = 0; i < x; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
  
    int removeConsecutiveSame(vector<string>& arr) {
        
        stack<string> st;
        int n = arr.size();
         
        for (int i = 0; i < n; i++) {
             
            if (st.empty()) {
                st.push(arr[i]);
            }
            else if (!issame(arr[i], st.top())) {
                st.push(arr[i]);
            } 
            else {
                st.pop();  // consecutive same → cancel
            }
        }
         
        return st.size();
    }
};

/*
Problem Name:
Replace Non-Coprime Numbers in Array

Problem Link:
https://leetcode.com/problems/replace-non-coprime-numbers-in-array/

Problem Statement:
You are given an array of integers nums.
You need to repeatedly replace adjacent non-coprime numbers
with their Least Common Multiple (LCM) until no such pair exists.
Return the final array.

------------------------------------------------------------

Approach (Stack-like using Vector):

- Use a vector `result` as a stack.
- Traverse the array from left to right.
- For each number:
    • If stack is empty → push it.
    • Otherwise:
        - Compare current number with stack top.
        - If gcd(top, current) > 1:
            → They are non-coprime
            → Remove stack top
            → Replace current with LCM(top, current)
            → Continue checking (chain reaction)
        - Else:
            → Stop merging
    • Push the final merged value.

This approach efficiently handles cascading merges.

------------------------------------------------------------

Why (prev / gcd) * curr for LCM?
- Prevents integer overflow
- More stable than (prev * curr) / gcd

------------------------------------------------------------

Time Complexity:
O(N log M)
- Each number is pushed & popped at most once
- gcd computation costs log M

Space Complexity:
O(N)
- Stack-like vector

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        vector<int> result;

        for (int num : nums) {

            if (result.empty()) {
                result.push_back(num);
            } 
            else {
                while (!result.empty()) {

                    int prev = result.back();
                    int GCD = gcd(prev, num);

                    if (GCD > 1) {
                        result.pop_back();
                        num = (prev / GCD) * num;  
                    } 
                    else {
                        break;
                    }
                }
                result.push_back(num);
            }
        }

        return result;
    }
};

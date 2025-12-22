/************************************************************
 🚀 Largest Subarray with 0 Sum
 ------------------------------------------------------------
 Problem Link:
 https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

 Difficulty: Medium
 ------------------------------------------------------------

 ❓ PROBLEM STATEMENT
 ------------------------------------------------------------
 Given an array arr[] containing both positive and negative
 integers, find the length of the longest subarray
 whose sum is equal to 0.

 A subarray is a contiguous part of the array.

 ------------------------------------------------------------

 📥 INPUT
 ------------------------------------------------------------
 - Vector<int> arr
   (may contain positive, negative, and zero values)

 ------------------------------------------------------------

 📤 OUTPUT
 ------------------------------------------------------------
 - Integer representing the length of the longest
   subarray with sum = 0

 ------------------------------------------------------------

 🧪 EXAMPLES
 ------------------------------------------------------------
 Input:  [15, -2, 2, -8, 1, 7, 10, 23]
 Output: 5
 Explanation:
   Longest subarray is [-2, 2, -8, 1, 7]

 Input:  [2, 10, 4]
 Output: 0

 Input:  [1, 0, -4, 3, 1, 0]
 Output: 5

 ------------------------------------------------------------

 🧠 INTUITION (Hinglish)
 ------------------------------------------------------------
 Sliding Window yahan kaam nahi karega kyunki
 array me negative numbers bhi ho sakte hain.

 Isliye hum PREFIX SUM ka use karte hain.

 Key observation:
 Agar kisi point pe same prefix sum dobara milta hai,
 toh beech ka subarray ka sum 0 hota hai.

 Example:
   prefixSum[i] == prefixSum[j]
   => arr[i+1 ... j] ka sum = 0

 ------------------------------------------------------------

 🔑 CORE IDEA
 ------------------------------------------------------------
 - Prefix sum calculate karte jao
 - Ek unordered_map rakho:
     prefixSum -> first index
 - Agar same prefix sum dubara mile:
     length = currentIndex - firstIndex
 - Maximum length track karte raho

 ------------------------------------------------------------

 🛠️ APPROACH (STEP-BY-STEP)
 ------------------------------------------------------------
 1. Initialize:
    - sum = 0
    - unordered_map<int,int> mp
    - mp[0] = -1   (important for subarrays starting at index 0)

 2. Traverse array:
    - sum += arr[i]
    - Agar sum map me pehle se hai:
        longest = max(longest, i - mp[sum])
    - Nahi hai:
        mp[sum] = i  (store first occurrence only)

 3. Return longest

 ------------------------------------------------------------

 ⏱️ TIME & SPACE COMPLEXITY
 ------------------------------------------------------------
 Time Complexity:
   O(N)  — single traversal with hashmap

 Space Complexity:
   O(N)  — hashmap storing prefix sums

 ------------------------------------------------------------

 ✅ WHY THIS SOLUTION IS CORRECT
 ------------------------------------------------------------
 ✔ Handles negative numbers
 ✔ Handles zero values
 ✔ Finds longest (not just any) subarray
 ✔ Optimal O(N) solution
 ✔ Fully accepted on GeeksforGeeks

 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, int> mp;
        int sum = 0;
        int longest = 0;

        // Prefix sum 0 occurs before array starts
        mp[0] = -1;

        for (int i = 0; i < n; i++) {

            sum += arr[i];

            // If prefix sum seen before,
            // subarray between indices has sum = 0
            if (mp.find(sum) != mp.end()) {
                longest = max(longest, i - mp[sum]);
            }
            else {
                // Store first occurrence only
                mp[sum] = i;
            }
        }

        return longest;
    }
};

/*
    ========================================================================
    📌 Problem: Count Binary Substrings
    🔗 LeetCode: Count Binary Substrings
    ========================================================================

    🧠 Problem Understanding:
    --------------------------
    Given a binary string `s` (containing only '0' and '1'),
    return the number of non-empty substrings that:

    1. Have equal number of 0's and 1's
    2. All 0's and all 1's in the substring are grouped consecutively

    ------------------------------------------------------------------------
    ✅ Valid Examples:

    Input:  "00110011"
    Output: 6

    Valid substrings:
    "0011", "01", "1100", "10", "0011", "01"

    ------------------------------------------------------------------------
    ❌ Invalid Example:

    "0101"
    Because 0s and 1s are not grouped consecutively.

    ========================================================================
    💡 Core Idea:
    ========================================================================

    Instead of generating all substrings (O(N²)), we observe something:

    🔎 We only need to count consecutive groups of same characters.

    Example:
    s = "001110011"

    Groups:
    "00"  -> length = 2
    "111" -> length = 3
    "00"  -> length = 2
    "11"  -> length = 2

    Now the trick:

    Number of valid substrings between two adjacent groups =
    min(previous_group_length, current_group_length)

    So answer = sum of min(prev, curr) for all adjacent groups.

    ========================================================================
    🚀 Optimal Approach (O(N))
    ========================================================================

    We maintain:
    - prev  -> length of previous group
    - curr  -> length of current group
    - result -> final answer

    When character changes:
        result += min(prev, curr)
        prev = curr
        curr = 1

    At the end:
        result += min(prev, curr)

    ========================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int result = 0;   // Stores final answer
        int prev = 0;     // Length of previous group
        int curr = 1;     // Length of current group
        
        // Traverse string from second character
        for(int i = 1; i < s.length(); i++) {
            
            if(s[i] == s[i-1]) {
                // Same group → increase current count
                curr++;
            }
            else {
                // Group changed
                // Add minimum of previous and current group
                result += min(prev, curr);
                
                // Update previous group
                prev = curr;
                
                // Reset current group count
                curr = 1;
            }
        }
        
        // Add last group comparison
        result += min(prev, curr);
        
        return result;
    }
};

/*
    ========================================================================
    🧪 Dry Run Example
    ========================================================================

    Input: "00110011"

    Step-by-step groups:

    "00" -> curr = 2
    change → prev = 2

    "11" -> curr = 2
    change → result += min(2,2) = 2

    "00" -> curr = 2
    change → result += min(2,2) = 2

    "11" -> curr = 2

    Final add:
    result += min(2,2) = 2

    Total = 2 + 2 + 2 = 6

    ========================================================================
    ⏱ Time Complexity:
    ========================================================================
    O(N)
    - Single pass traversal

    ========================================================================
    💾 Space Complexity:
    ========================================================================
    O(1)
    - Only 3 integer variables used

    ========================================================================
    🔥 Why This is Optimal?
    ========================================================================
    - No substring generation
    - No extra arrays
    - Only group counting
    - Clean greedy logic

    ========================================================================
    🎯 Interview Tip:
    ========================================================================
    If interviewer asks:
    "Why min(prev, curr)?"

    Answer:
    Because valid substrings must have equal number of 0s and 1s,
    and they must come from adjacent groups.
    So maximum balanced substrings between two groups =
    smaller group size.

    ========================================================================
    👑 Author: Saurabh Singh Rajput
    🚀 Discipline > Motivation
    ========================================================================
*/

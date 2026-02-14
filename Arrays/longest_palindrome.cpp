/*
    File Name: longest_palindrome.cpp
    Author: Saurabh Singh Rajput
    Platform: LeetCode
    Problem: Longest Palindromic Substring
    Approach: Expand Around Center
*/

class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        // Edge case: If string has 0 or 1 character
        if(n <= 1) return s;
        
        int start = 0;     // Starting index of longest palindrome
        int maxLen = 1;    // Length of longest palindrome
        
        for(int i = 0; i < n; i++){
            
            // --------------------------
            // Case 1: Odd Length Palindrome
            // Center at index i
            // --------------------------
            int l = i, r = i;
            
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
            
            // --------------------------
            // Case 2: Even Length Palindrome
            // Center between i and i+1
            // --------------------------
            l = i;
            r = i + 1;
            
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        
        // Return longest palindromic substring
        return s.substr(start, maxLen);
    }
};

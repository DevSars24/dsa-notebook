#include <bits/stdc++.h>
using namespace std;

/*
   This program defines a Solution class with a function `isValid`
   that checks if a given word (string) is valid according to rules:

   1. The word length must be at least 3.
   2. The word must contain at least one vowel and at least one consonant.
   3. The word can contain only alphabets (A-Z, a-z) and digits (0-9).
   4. Any other character (like @, #, $, etc.) makes the word invalid.

   Helper functions:
   - isvowel(ch): checks if a character is a vowel.
   - isconsonant(ch): checks if a character is a consonant.
   - my_isdigit(ch): checks if a character is in '0'–'9' range.
   - my_isalpha(ch): checks if a character is in 'a'–'z' or 'A'–'Z' range.
*/

class Solution {
public:

    // Function to check if a character is a vowel (a, e, i, o, u)
    bool isvowel(char ch) {
        ch = tolower(ch); // convert to lowercase for uniform check
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    // Function to check if a character is a consonant
    bool isconsonant(char ch) {
        ch = tolower(ch);                  // convert to lowercase
        return my_isalpha(ch) && !isvowel(ch); // must be alphabet but not vowel
    }

    // Function to check if a character is a digit (0-9)
    bool my_isdigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }

    // Function to check if a character is an alphabet (A-Z or a-z)
    bool my_isalpha(char ch) {
        return ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') );
    }

    // Main function to validate the word
    bool isValid(string word) {
        int x = 0; // vowel counter
        int y = 0; // consonant counter

        int n = word.size();

        // Rule 1: word must have at least 3 characters
        if (n < 3) {   
            return false;
        }

        // Count vowels
        for (char ch: word) {
            if (isvowel(ch)) {
                x++;
            }
        }

        // Count consonants
        for (char ch: word) {
            if (isconsonant(ch)) {
                y++;
            }
        }

        // Rule 2: must contain at least one vowel and one consonant
        if (x == 0 || y == 0) {   
            return false;
        }

        // Rule 3: only digits and alphabets allowed
        for (char ch: word) {
            if (my_isdigit(ch) || isvowel(ch) || isconsonant(ch)) {
                continue; // valid character
            } else {
                return false;  // invalid character found
            }
        }

        // All rules satisfied
        return true; 
    }
};

// Example usage and test cases
int main() {
    Solution s;
    cout << boolalpha;  // print true/false instead of 1/0

    cout << s.isValid("abc") << endl;     // true (valid word)
    cout << s.isValid("a1b") << endl;     // true (digit allowed + vowel + consonant)
    cout << s.isValid("aa") << endl;      // false (length < 3)
    cout << s.isValid("123") << endl;     // false (no vowel or consonant)
    cout << s.isValid("a@b") << endl;     // false (invalid character '@')
    cout << s.isValid("Code123") << endl; // true (vowels + consonants + digits)

    return 0;
}

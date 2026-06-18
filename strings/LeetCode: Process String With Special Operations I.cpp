```cpp
/*
===============================================================
LeetCode: Process String With Special Operations I
Link:
https://leetcode.com/problems/process-string-with-special-operations-i/

Difficulty: Easy

===============================================================
Problem Summary
===============================================================

You are given a string s.

Process each character from left to right:

1. '*'  -> Remove the last character from the current result
           (if result is not empty)

2. '#'  -> Duplicate the current result
           result = result + result

3. '%'  -> Reverse the current result

4. Any other lowercase letter:
           Append it to the result

Return the final processed string.

===============================================================
Intuition
===============================================================

We simulate the operations exactly as described.

Maintain a string called "result".

For every character:

- Letter -> append
- '*'    -> pop last character
- '#'    -> double the string
- '%'    -> reverse the string

Since operations directly modify the current state,
simulation is the most natural and simplest approach.

===============================================================
Example Dry Run
===============================================================

Input:
s = "ab#c%*"

result = ""

Step 1:
'a'
result = "a"

Step 2:
'b'
result = "ab"

Step 3:
'#'
result = "abab"

Step 4:
'c'
result = "ababc"

Step 5:
'%'
reverse(result)
result = "cbaba"

Step 6:
'*'
remove last character

result = "cbab"

Output:
"cbab"

===============================================================
Edge Cases
===============================================================

1. Empty Result + '*'

s = "*"

result = ""

Nothing to remove.

Output = ""

---------------------------------------------------------------

2. Empty Result + '#'

s = "#"

result = ""

result += result

Output = ""

---------------------------------------------------------------

3. Empty Result + '%'

s = "%"

reverse("")

Output = ""

---------------------------------------------------------------

4. Multiple Deletes

s = "a***"

a -> "a"
* -> ""
* -> ""
* -> ""

Output = ""

---------------------------------------------------------------

5. Consecutive Reverse

s = "abc%%"

abc
cba
abc

Output = "abc"

---------------------------------------------------------------

6. Consecutive Duplicate

s = "ab##"

ab
abab
abababab

Output = "abababab"

===============================================================
Approach
===============================================================

Use one string "result".

Traverse the input string:

1. If current character is '*'
      pop_back()

2. If current character is '#'
      result += result

3. If current character is '%'
      reverse(result)

4. Otherwise
      append current character

Return result.

===============================================================
Complexity Analysis
===============================================================

Let N = length of input string
Let M = maximum size of generated string

Time Complexity:
O(M)

Reason:
- append => O(1)
- pop_back => O(1)
- reverse => O(length of result)
- duplication => O(length of result)

Overall bounded by total generated output size.

Space Complexity:
O(M)

for storing the resulting string.

===============================================================
LeetCode Accepted Solution
===============================================================
*/

class Solution {
public:
    string processStr(string s) {

        string result = "";

        for (char &ch : s) {

            // Delete last character
            if (ch == '*') {

                if (!result.empty()) {
                    result.pop_back();
                }
            }

            // Duplicate current string
            else if (ch == '#') {

                result += result;
            }

            // Reverse current string
            else if (ch == '%') {

                reverse(result.begin(), result.end());
            }

            // Normal character
            else {

                result += ch;
            }
        }

        return result;
    }
};
```

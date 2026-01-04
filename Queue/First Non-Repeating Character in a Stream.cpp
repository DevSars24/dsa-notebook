/*
------------------------------------------------------------
Platform   : GeeksforGeeks
Problem    : First Non-Repeating Character in a Stream
Link       : https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
Difficulty : medium (Conceptually IMPORTANT)
------------------------------------------------------------

🧠 WHY I GOT STUCK (REAL LEARNING):
The keyword "prefix / stream" was the turning point.

At first, only hashing came to mind.
But hashing alone cannot preserve ORDER.

The moment "stream" clicked,
QUEUE became mandatory.

------------------------------------------------------------
🔑 CORE INSIGHT:
For every prefix of the string, we need:
1. Frequency of characters  → unordered_map
2. Order of appearance      → queue

HashMap answers:
"How many times did this character appear?"

Queue answers:
"Which character came first and is still valid?"

------------------------------------------------------------
🛠️ APPROACH:
1. Traverse the string character by character (stream).
2. Increase frequency using unordered_map.
3. Push character into queue.
4. While queue front is repeating (freq > 1), pop it.
5. If queue is empty → add '#'
   else → add queue.front()

------------------------------------------------------------
⏱ Time Complexity:
O(n) — each character enters and leaves queue once.

💾 Space Complexity:
O(1) — since only lowercase English characters.

------------------------------------------------------------
🧠 KEY TAKEAWAY:
Whenever you see:
- prefix
- stream
- first non-repeating

Think immediately:
👉 unordered_map + queue

------------------------------------------------------------
*/

class Solution {
public:
    string firstNonRepeating(string &s) {

        unordered_map<char,int> freq;  // frequency count
        queue<char> q;                 // maintains order
        string ans = "";

        for(char ch : s){

            freq[ch]++;
            q.push(ch);

            // remove all repeating characters from front
            while(!q.empty() && freq[q.front()] > 1){
                q.pop();
            }

            if(q.empty())
                ans.push_back('#');
            else
                ans.push_back(q.front());
        }

        return ans;
    }
};

/*
===========================================================
Problem Name : Diagonal Tree Traversal
Platform     : GeeksforGeeks
Difficulty   : Medium
Link         : https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

-----------------------------------------------------------
Problem Statement:
Given a Binary Tree, return the diagonal traversal of the tree.

Diagonal traversal means:
- Nodes lying on the same diagonal (slope -1) are printed together
- If diagonal nodes are present in left and right subtrees,
  then left subtree diagonal nodes are printed first

-----------------------------------------------------------
Intuition (Simple Language):
Is problem me ek simple observation hai:

👉 Right child hamesha SAME diagonal me aata hai  
👉 Left child hamesha NEXT diagonal me aata hai  

Isliye:
- Right side ko turant process kar sakte hain
- Left children ko baad ke liye store karna padega

-----------------------------------------------------------
Approach Used (Vector Based):
Hum 2 vectors use karte hain:

1. s1 → current diagonal ke starting nodes
2. s2 → next diagonal ke nodes (left children)

Steps:
1. Root ko s1 me daal do
2. Jab tak s1 empty na ho:
   - s2 clear karo
   - s1 ke har node ke liye:
       - Right chain traverse karo
       - Data ans me daalte jao
       - Left child s2 me store karte jao
   - s1 = s2 (next diagonal)

-----------------------------------------------------------
Dry Run (Example):

Tree:
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \     /
         4   7   13

Initial:
s1 = [8]
ans = []

-------------------------
Diagonal 1:
Process 8 → 10 → 14

ans = [8, 10, 14]
s2  = [3, 13]

s1 = s2

-------------------------
Diagonal 2:
Process 3 → 6 → 7
Process 13

ans = [8, 10, 14, 3, 6, 7, 13]
s2  = [1, 4]

s1 = s2

-------------------------
Diagonal 3:
Process 1
Process 4

ans = [8, 10, 14, 3, 6, 7, 13, 1, 4]

-------------------------
Final Output:
[8, 10, 14, 3, 6, 7, 13, 1, 4]

-----------------------------------------------------------
Time Complexity:
O(n)
Har node sirf ek baar visit hota hai.

-----------------------------------------------------------
Space Complexity:
O(n)
Vectors s1 and s2 use ho rahe hain.

-----------------------------------------------------------
Why This Approach is Good:
✔ Simple logic
✔ Easy to dry run
✔ No recursion
✔ Interview friendly
✔ GFG accepted

===========================================================
*/

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        
        vector<int> ans;
        
        if (root == nullptr) {
            return ans;
        }
        
        vector<Node*> s1;   // current diagonal
        vector<Node*> s2;   // next diagonal (left children)
        
        s1.push_back(root);
        
        while (!s1.empty()) {
            
            s2.clear();  
            
            for (Node* node : s1) {
                
                while (node != nullptr) {
                    
                    ans.push_back(node->data);
                    
                    if (node->left) {
                        s2.push_back(node->left);
                    }
                    
                    node = node->right;
                }
            }
            
            s1 = s2;
        }
        
        return ans;
    }
};

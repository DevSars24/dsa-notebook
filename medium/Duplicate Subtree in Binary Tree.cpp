/************************************************************
 📌 PROBLEM: Duplicate Subtree in Binary Tree
 🔗 Link:
 https://www.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

 ------------------------------------------------------------
 🧩 PROBLEM DESCRIPTION
 ------------------------------------------------------------
 Given a binary tree, your task is to check whether the tree
 contains a duplicate subtree of size 2 or more.

 A subtree is considered duplicate if:
 1. It has the same structure
 2. It has the same node values
 3. It appears more than once in the tree
 4. Its size is at least 2 (leaf nodes are NOT allowed)

 Return:
   1 -> if such a duplicate subtree exists
   0 -> otherwise

 ------------------------------------------------------------
 🧪 EXAMPLE
 ------------------------------------------------------------
        1
       / \
      2   3
     /   /
    4   2
       /
      4

 Duplicate subtree:
       2
      /
     4

 Output: 1

 ------------------------------------------------------------
 🧠 INTUITION
 ------------------------------------------------------------
 To detect duplicate subtrees, we need a way to:
 - Compare subtree structures
 - Compare subtree values
 - Detect repetition

 The best way is to:
 👉 Convert every subtree into a unique STRING representation
 👉 Store each subtree string in a map with its frequency

 If any subtree string:
 - Appears more than once
 - Represents a subtree of size >= 2
 Then we have found a duplicate subtree.

 ------------------------------------------------------------
 🔍 WHY SERIALIZATION WORKS?
 ------------------------------------------------------------
 Each subtree is converted into a string like:

   root_value,left_subtree,right_subtree

 Example:
   Tree:
       2
      /
     4

   Serialization:
       "2,4,N,N,N"

 - "N" represents NULL child
 - This preserves STRUCTURE + VALUES

 ------------------------------------------------------------
 ⚠️ IMPORTANT EDGE CASE
 ------------------------------------------------------------
 Leaf nodes like:
   "4,N,N"

 Even if they repeat, they are NOT allowed
 because subtree size must be >= 2

 Hence we check:
   (root->left || root->right)

 ------------------------------------------------------------
 🛠️ APPROACH (STEP BY STEP)
 ------------------------------------------------------------
 1. Use postorder traversal (left, right, root)
 2. Serialize each subtree into a string
 3. Store frequency of each subtree string in a map
 4. If a subtree string appears twice AND
    subtree has at least one child → mark duplicate found

 ------------------------------------------------------------
 ⏱️ TIME & SPACE COMPLEXITY
 ------------------------------------------------------------
 Time Complexity:  O(N)
 Space Complexity: O(N)

 Where N = number of nodes in the tree

 ------------------------------------------------------------
 ✅ GUARANTEED GFG ACCEPTED
 ------------------------------------------------------------
 Handles:
 - Multiple test cases
 - Duplicate leaf issue
 - Structure correctness

 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

/* ---------------- NODE DEFINITION ---------------- */
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

/* ---------------- SOLUTION CLASS ---------------- */
class Solution {
public:

    /*
     solve()
     - Serializes subtree rooted at 'root'
     - Stores frequency in map
     - Detects duplicate subtree of size >= 2
    */
    string solve(Node* root, map<string,int>& mp, int& found) {

        // Base case: NULL node
        if (root == nullptr)
            return "N";

        // Serialize current subtree
        string s = to_string(root->data) + "," +
                   solve(root->left, mp, found) + "," +
                   solve(root->right, mp, found);

        // Check duplicate subtree of size >= 2
        if (mp[s] == 1 && (root->left || root->right))
            found = 1;

        // Store frequency
        mp[s]++;

        return s;
    }

    /*
     dupSub()
     - Entry point function
     - Returns 1 if duplicate subtree exists else 0
    */
    int dupSub(Node *root) {

        map<string,int> mp;   // stores subtree serialization count
        int found = 0;        // flag

        solve(root, mp, found);
        return found;
    }
};

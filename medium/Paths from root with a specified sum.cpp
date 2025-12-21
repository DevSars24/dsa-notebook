/************************************************************
 🔗 QUESTION LINK
 ------------------------------------------------------------
 https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

 ------------------------------------------------------------
 🧩 PROBLEM TITLE
 ------------------------------------------------------------
 Paths from root with a specified sum

 ------------------------------------------------------------
 📝 PROBLEM DESCRIPTION
 ------------------------------------------------------------
 Given a binary tree and an integer K, print all the paths
 starting from the root such that the sum of all the nodes
 in the path equals K.

 IMPORTANT RULES:
 1. The path must always start from the ROOT.
 2. The path may end at ANY node (leaf is NOT mandatory).
 3. Node values can be positive, negative, or zero.
 4. Multiple valid paths may exist.
 5. Order of nodes in each path must be preserved
    (root → downward).

 ------------------------------------------------------------
 📥 INPUT
 ------------------------------------------------------------
 - Root of a binary tree
 - Integer K (target sum)

 ------------------------------------------------------------
 📤 OUTPUT
 ------------------------------------------------------------
 - A vector of vectors containing all valid paths
   whose sum is equal to K.

 ------------------------------------------------------------
 🧪 EXAMPLE
 ------------------------------------------------------------
 Tree:
            0
           / \
          0  -3
         / \
        1  -4
       /
      3
       \
        0

 K = 1

 Valid Paths:
 1) 0 → 0 → 1
 2) 0 → 0 → 1 → 0

 ------------------------------------------------------------
 🧠 INTUITION
 ------------------------------------------------------------
 We traverse the tree from the root using DFS.

 While traversing:
 - Maintain a vector `path` that stores the current path
 - Reduce the remaining sum by current node's value
 - Whenever remaining sum becomes 0, the current path
   is a valid answer (even if it does NOT end at a leaf)

 ⚠️ IMPORTANT:
 We must NOT stop traversal when sum becomes 0,
 because future nodes may contain negative or positive
 values which can again make the sum equal to K.

 ------------------------------------------------------------
 🛠️ APPROACH (STEP-BY-STEP)
 ------------------------------------------------------------
 1. Start DFS from the root.
 2. Add current node value to `path`.
 3. Subtract node value from remaining sum.
 4. If remaining sum == 0:
      → store current path in answer.
 5. Recursively visit left and right children.
 6. Backtrack by removing current node from path.

 ------------------------------------------------------------
 ⏱️ TIME & SPACE COMPLEXITY
 ------------------------------------------------------------
 Time Complexity:
   O(N²) in worst case (skewed tree + copying paths)

 Space Complexity:
   O(H) for recursion stack + path storage
   (H = height of tree)

 ------------------------------------------------------------
 ✅ WHY THIS SOLUTION IS CORRECT
 ------------------------------------------------------------
 ✔ Handles negative values
 ✔ Handles paths ending at internal nodes
 ✔ Handles multiple valid paths in same branch
 ✔ Uses backtracking properly
 ✔ Fully compliant with GFG constraints

 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

/* ----------------------------------------------------------
   Binary Tree Node (Given by GFG)
---------------------------------------------------------- */
struct Node {
    int key;
    Node *left, *right;
};

/* ----------------------------------------------------------
   Solution Class
---------------------------------------------------------- */
class Solution {
  public:

    /* ------------------------------------------------------
       Helper DFS Function
    ------------------------------------------------------ */
    void solve(Node* root, int sum,
               vector<int>& path,
               vector<vector<int>>& ans) {

        // Base case
        if (root == nullptr)
            return;

        // Include current node in path
        path.push_back(root->key);
        sum -= root->key;

        // If sum becomes zero, store the path
        // (Path may end at ANY node)
        if (sum == 0) {
            ans.push_back(path);
        }

        // Continue traversal (important for negative values)
        solve(root->left, sum, path, ans);
        solve(root->right, sum, path, ans);

        // Backtrack
        path.pop_back();
    }

    /* ------------------------------------------------------
       Main Function
    ------------------------------------------------------ */
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(root, sum, path, ans);
        return ans;
    }
};

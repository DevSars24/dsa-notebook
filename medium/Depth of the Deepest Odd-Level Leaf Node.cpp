/*
============================================================
📌 Problem: Depth of the Deepest Odd-Level Leaf Node
🔗 Link:
https://www.geeksforgeeks.org/problems/depth-of-node/1

------------------------------------------------------------
🧠 Problem Description:
Given a binary tree of size n, find the depth of the deepest
leaf node which lies at an ODD level.

Definitions:
1. Root is at level 1
2. Levels start from 1
3. Odd levels = 1, 3, 5, ...
4. Leaf node = node with no left and right child
5. Depth = number of nodes from root to that leaf
   (root and leaf included)

If no leaf exists at an odd level, return 0.

------------------------------------------------------------
🧪 Examples:

Example 1:
        1
       / \
      2   3
     / \ / \
    4  5 6  7

Odd-level leaf nodes: 4, 5, 6, 7 (level 3)
Answer: 3

Example 2:
        1
       / \
      2   4

No odd-level leaf exists
Answer: 0

------------------------------------------------------------
🛠️ Why BFS (Level Order Traversal)?

- We need LEVEL information → BFS naturally gives levels
- We need DEEPEST odd-level leaf → traverse entire tree
- Track (node, level) using a queue

------------------------------------------------------------
🧠 Approach (Step-by-Step):

1. If root is NULL, return 0
2. Initialize answer = 0
3. Push (root, level = 1) into queue
4. While queue is not empty:
   a. Pop front element
   b. If node is a leaf AND level is odd:
        update answer = max(answer, level)
   c. Push left child with level + 1
   d. Push right child with level + 1
5. Return answer

------------------------------------------------------------
⏱ Time Complexity: O(N)
🧠 Space Complexity: O(N)

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* ----------- Binary Tree Node Definition ----------- */
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* ----------- Solution Class ----------- */
class Solution {
  public:
    int depthOfOddLeaf(Node *root) {

        int ans = 0;
        if (root == nullptr)
            return ans;

        // Queue stores (node, level)
        queue<pair<Node*, int>> q;
        q.push({root, 1});   // root is at level 1

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int level = it.second;

            // Check if leaf node at odd level
            if (node->left == nullptr && node->right == nullptr) {
                if (level % 2 == 1) {
                    ans = max(ans, level);
                }
            }

            if (node->left)
                q.push({node->left, level + 1});

            if (node->right)
                q.push({node->right, level + 1});
        }

        return ans;
    }
};

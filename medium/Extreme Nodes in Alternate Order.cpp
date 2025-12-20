/*
============================================================
📌 Problem: Extreme Nodes in Alternate Order
🔗 Link:
https://www.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1

------------------------------------------------------------
🧠 Problem Description:
Given a binary tree, print the extreme nodes of each level
in alternate order.

Definitions:
- Level order traversal is used (BFS).
- Root is considered at level 1.
- For odd levels → take the LEFTMOST node.
- For even levels → take the RIGHTMOST node.

Return the result as a vector of integers.

------------------------------------------------------------
🧪 Example:

Tree:
            1
           / \
          2   3
         / \   \
        4   5   6

Traversal:
- Level 1 (odd)  → leftmost  → 1
- Level 2 (even) → rightmost → 3
- Level 3 (odd)  → leftmost  → 4

Output:
[1, 3, 4]

------------------------------------------------------------
🛠️ Why BFS (Level Order Traversal)?

- Problem is strictly LEVEL based
- BFS naturally processes nodes level by level
- Queue size tells how many nodes are present at current level
- Index (`i`) helps identify leftmost and rightmost nodes

------------------------------------------------------------
🧠 Core Idea:
For each level:
- If level is ODD → pick node at index 0
- If level is EVEN → pick node at index (size - 1)

------------------------------------------------------------
🧠 Approach (Step-by-Step):

1. If root is NULL, return empty vector
2. Push root into a queue
3. Initialize level = 1
4. While queue is not empty:
   a. Get current level size = queue.size()
   b. Traverse all nodes of current level:
        - if level is odd and index == 0 → add node
        - if level is even and index == size - 1 → add node
        - push left and right children into queue
   c. Increment level
5. Return answer vector

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

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/* ----------- Solution Class ----------- */
class Solution {
  public:
    vector<int> extremeNodes(Node* root) {

        vector<int> ans;
        if (root == nullptr)
            return ans;

        queue<Node*> q;
        q.push(root);

        int level = 1;   // root is at level 1

        while (!q.empty()) {

            int n = q.size();   // number of nodes at current level

            for (int i = 0; i < n; i++) {

                Node* node = q.front();
                q.pop();

                // Odd level → leftmost node
                if (level % 2 == 1 && i == 0) {
                    ans.push_back(node->data);
                }

                // Even level → rightmost node
                if (level % 2 == 0 && i == n - 1) {
                    ans.push_back(node->data);
                }

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            level++;
        }

        return ans;
    }
};

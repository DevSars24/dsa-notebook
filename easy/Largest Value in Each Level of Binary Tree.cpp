/*
============================================================
📌 Problem: Largest Value in Each Level of Binary Tree
🔗 Link:
https://www.geeksforgeeks.org/problems/largest-value-in-each-level/1

------------------------------------------------------------
🧠 Problem Description:
Given a binary tree, find the largest value in each level
of the tree and return the values in a vector.

Each level of the tree should be processed independently,
and the maximum value at that level should be recorded.

------------------------------------------------------------
🧪 Example:

Input Tree:
            1
           / \
          3   2
         / \   \
        5   3   9

Output:
[1, 3, 9]

Explanation:
- Level 0 → max = 1
- Level 1 → max = 3
- Level 2 → max = 9

------------------------------------------------------------
🛠️ Why BFS (Level Order Traversal)?

- We need to process nodes **level by level**
- BFS naturally groups nodes by level using a queue
- `queue.size()` tells us how many nodes are present
  at the current level

------------------------------------------------------------
🧠 Approach (Step-by-Step):

1. If root is NULL, return empty vector
2. Push root into a queue
3. While queue is not empty:
   a. Get current level size = queue.size()
   b. Initialize maxValue = INT_MIN
   c. Process all nodes of current level:
        - update maxValue
        - push left and right children into queue
   d. Push maxValue into answer vector
4. Return answer vector

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
    vector<int> largestValues(Node* root) {

        vector<int> ans;
        if (root == nullptr)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();        // number of nodes at this level
            int maximum = INT_MIN;  // max value at this level

            while (n--) {

                Node* node = q.front();
                q.pop();

                maximum = max(maximum, node->data);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(maximum);
        }

        return ans;
    }
};

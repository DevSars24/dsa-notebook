/*
===========================================================
📌 Problem: Bottom View of Binary Tree
🔗 Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

-----------------------------------------------------------
🧠 Problem Description:
Given a binary tree, print the bottom view of the tree.
The bottom view contains the nodes that are visible when
the tree is viewed from the bottom.

For each horizontal distance from the root, the node that
appears last in level order traversal (i.e., the lowest one)
is included in the bottom view.

-----------------------------------------------------------
🧪 Example:

Input Tree:
            20
           /  \
          8   22
         / \    \
        5   3    25
           / \
          10 14

Output:
5 10 3 14 25

-----------------------------------------------------------
🛠️ Approach:
1. Use **Level Order Traversal (BFS)**.
2. Maintain a **map<int, int>** where:
      - key   → horizontal distance (HD)
      - value → node value
3. For every node visited:
      - overwrite map[HD] with current node's value
      - this ensures the bottom-most node remains
4. Traverse the map from left to right to build the answer.

-----------------------------------------------------------
⏱️ Time Complexity:
O(N log N)  (due to map insertion)

🧠 Space Complexity:
O(N)  (queue + map)

===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* ----------- Binary Tree Node Definition ----------- */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

/* ----------- Solution Class ----------- */
class Solution {
public:
    vector<int> bottomView(Node *root) {

        vector<int> ans;
        if (root == nullptr)
            return ans;

        // horizontal distance -> node value
        map<int, int> mpp;

        // queue stores (node, horizontal distance)
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            // overwrite to keep bottom-most node
            mpp[line] = node->data;

            if (node->left)
                q.push({node->left, line - 1});

            if (node->right)
                q.push({node->right, line + 1});
        }

        // extract answer from map
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

/* ----------- Driver Code (for local testing) ----------- */
int main() {

    /*
            20
           /  \
          8   22
         / \    \
        5  3     25
          / \
         10 14
    */

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);

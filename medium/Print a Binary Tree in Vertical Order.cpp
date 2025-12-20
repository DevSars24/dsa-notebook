/*
============================================================
📌 Problem: Print a Binary Tree in Vertical Order
🔗 Link:
https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

------------------------------------------------------------
🧠 Problem Description:
Given the root of a binary tree, print the vertical order
traversal of the tree from leftmost vertical line to the
rightmost vertical line.

👉 If multiple nodes lie on the same vertical line,
they must be printed in the SAME ORDER as they appear
in LEVEL ORDER traversal (top to bottom, left to right).

------------------------------------------------------------
🧩 Key Observations:
1. Tree ko vertical lines me divide karna hai
2. Left child → vertical line - 1
3. Right child → vertical line + 1
4. Same vertical line ke multiple nodes ho sakte hain
5. Order MUST be level order (BFS)

------------------------------------------------------------
❌ Why NOT map<int,int> ?
Because:
- map<int,int> sirf ek value store karta hai per key
- same vertical line me multiple nodes overwrite ho jaayenge

------------------------------------------------------------
✅ Why map<int, vector<int>> ?
Because:
- key   → vertical line
- value → us line ke saare nodes (in BFS order)
- map automatically left → right order maintain karta hai
- vector preserves insertion (level order) order

------------------------------------------------------------
🛠️ Data Structures Used:
1. queue<pair<Node*, int>>
   → for level order traversal (BFS)
2. map<int, vector<int>>
   → vertical line wise storage

------------------------------------------------------------
🧠 Approach (Best & Simple):
1. If root is NULL, return empty answer
2. Push (root, 0) into queue
3. While queue is not empty:
   - pop front
   - store node->data in map[line]
   - push left child with line - 1
   - push right child with line + 1
4. Traverse map from leftmost to rightmost
5. Store values in answer

------------------------------------------------------------
⏱ Time Complexity: O(N log N)
🧠 Space Complexity: O(N)

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* ----------- Tree Node Definition ----------- */
class Node {
  public:
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
    vector<vector<int>> verticalOrder(Node *root) {

        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        // Queue for BFS: (node, vertical line)
        queue<pair<Node*, int>> q;

        // Map: vertical line -> list of nodes
        map<int, vector<int>> mp;

        q.push({root, 0});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            // Store node value in its vertical line
            mp[line].push_back(node->data);

            if (node->left)
                q.push({node->left, line - 1});

            if (node->right)
                q.push({node->right, line + 1});
        }

        // Extract result from leftmost to rightmost vertical line
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

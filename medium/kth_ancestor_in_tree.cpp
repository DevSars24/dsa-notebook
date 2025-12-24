/************************************************************
 * File: kth_ancestor_in_tree.cpp
 *
 * Problem: Kth Ancestor in a Tree
 * Link   : https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
 *
 * Difficulty : Medium
 *
 * ----------------------------------------------------------
 * Problem Statement:
 * Given a binary tree, an integer k, and a node value.
 * Find the k-th ancestor of the given node.
 * If no such ancestor exists, return -1.
 *
 * Notes:
 * 1. Node always exists in the tree.
 * 2. All node values are distinct.
 *
 * ----------------------------------------------------------
 * Example:
 * Input:  k = 2, node = 4
 * Output: 1
 *
 * Explanation:
 * Path to node 4 is: 1 -> 2 -> 4
 * 1st ancestor = 2
 * 2nd ancestor = 1
 *
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

/* Tree Node structure */
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int ans = -1;

    /*
     * DFS helper function
     * root  : current node
     * k     : kth ancestor to find
     * node  : target node value
     * path  : stores path from root to current node
     */
    void dfs(Node* root, int k, int node, vector<int>& path) {
        if (root == nullptr)
            return;

        // add current node to path
        path.push_back(root->data);

        // if target node found
        if (root->data == node) {
            int idx = path.size() - 1 - k;
            if (idx >= 0)
                ans = path[idx];
            else
                ans = -1;
        }

        // DFS left and right
        dfs(root->left, k, node, path);
        dfs(root->right, k, node, path);

        // backtracking
        path.pop_back();
    }

    /*
     * Main function called by GFG
     */
    int kthAncestor(Node* root, int k, int node) {
        vector<int> path;
        dfs(root, k, node, path);
        return ans;
    }
};

/*
------------------------------------------------------------
Approach Explanation:

1. Perform DFS traversal from root.
2. Maintain a vector 'path' storing nodes from root
   to the current node.
3. When target node is found:
   - Its k-th ancestor will be at index:
       path.size() - 1 - k
4. If index is valid, return that value.
5. Otherwise, return -1.
6. Use backtracking (pop_back) to maintain correct path.
------------------------------------------------------------

Time Complexity  : O(N)
Space Complexity : O(H)
Where:
N = number of nodes
H = height of the tree (recursion stack + path vector)

------------------------------------------------------------
Why this works well?
- Simple DFS
- Clear path tracking
- Easy to debug
- Interview friendly explanation
------------------------------------------------------------
*/

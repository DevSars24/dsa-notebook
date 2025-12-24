/************************************************************
 * File Name   : deepest_leaves_sum.cpp
 * Problem     : Deepest Leaves Sum
 * Platform    : LeetCode
 * Link        : https://leetcode.com/problems/deepest-leaves-sum/
 * Difficulty  : Medium
 *
 * ----------------------------------------------------------
 * PROBLEM STATEMENT:
 * Given the root of a binary tree, return the sum of values
 * of its deepest leaves.
 *
 * ----------------------------------------------------------
 * APPROACH:
 *
 * We solve this problem in TWO STEPS:
 *
 * 1) Find the height (number of levels) of the binary tree
 *    using DFS (recursion).
 *
 * 2) Perform Level Order Traversal (BFS) using a queue.
 *    - Traverse the tree level by level.
 *    - Maintain the current level count.
 *    - When we reach the deepest level (height),
 *      calculate and return the sum of all nodes at that level.
 *
 * ----------------------------------------------------------
 * WHY THIS WORKS:
 *
 * - DFS is best for computing tree height.
 * - BFS naturally processes nodes level-by-level.
 * - Combining both gives a clean and readable solution.
 *
 * ----------------------------------------------------------
 * TIME COMPLEXITY:
 *   O(N)  -> DFS visits all nodes once
 *           BFS visits all nodes once
 *
 * SPACE COMPLEXITY:
 *   O(N)  -> Queue (worst case last level)
 *   O(H)  -> Recursion stack for DFS
 *
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    /* -------- STEP 1: Find height of tree using DFS -------- */
    int hei(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight  = hei(root->left);
        int rightHeight = hei(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    /* -------- STEP 2: BFS to find sum at deepest level -------- */
    int deepestLeavesSum(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int height = hei(root);   // total levels in tree

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int sum = 0;

        while (!q.empty()) {
            int n = q.size();
            int levelSum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            // if this is the deepest level
            if (level == height) {
                sum = levelSum;
                break;
            }

            level++;
        }

        return sum;
    }
};

/*
--------------------
EXAMPLE:

Input:
root = [1,2,3,4,5,null,6,7,null,null,null,null,8]

Deepest level nodes: 7, 8
Output: 15
--------------------
*/

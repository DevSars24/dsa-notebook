/**
 * File: balanced_binary_tree.cpp
 * Problem: Balanced Binary Tree
 * Link: https://leetcode.com/problems/balanced-binary-tree/
 *
 * Approach:
 *  - A binary tree is height-balanced if for every node,
 *    the height difference between its left and right subtree is ≤ 1.
 *  - For each node:
 *      1. Compute height of left subtree
 *      2. Compute height of right subtree
 *      3. Check height difference
 *      4. Recursively validate left and right subtrees
 *
 * Time Complexity:
 *  - O(N^2) in worst case (skewed tree)
 *
 * Space Complexity:
 *  - O(H) where H is the height of the tree (recursion stack)
 */

#include <iostream>
#include <algorithm>
#include <cmath>
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
    /**
     * Function to calculate height of binary tree
     */
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    /**
     * Function to check if binary tree is height-balanced
     */
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);

        if (abs(leftH - rightH) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

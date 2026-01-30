/*
========================================================
Problem   : Find Duplicate Subtrees
Platform  : LeetCode
Link      : https://leetcode.com/problems/find-duplicate-subtrees/
Author    : Saurabh Singh Rajput
Language  : C++
========================================================

Problem Statement:
Given the root of a binary tree, return all duplicate subtrees.
Two subtrees are considered duplicate if they have the same structure
and the same node values.

Approach:
- Use DFS (postorder traversal).
- Serialize each subtree into a string:
    root_val,left_subtree,right_subtree
- Store the frequency of each serialized subtree in a hash map.
- When a subtree serialization appears for the second time,
  add the root node of that subtree to the answer.

Why Postorder?
Because we need left and right subtree information before
processing the current node.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

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
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    unordered_map<string, int> mp;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root) {
        if (root == nullptr)
            return "#";

        string left  = dfs(root->left);
        string right = dfs(root->right);

        string curr = to_string(root->val) + "," + left + "," + right;
        mp[curr]++;

        // Push only once when duplicate appears
        if (mp[curr] == 2) {
            ans.push_back(root);
        }

        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

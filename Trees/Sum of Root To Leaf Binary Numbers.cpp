/*
    Problem: Sum of Root To Leaf Binary Numbers
    Platform: LeetCode
    Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

    ------------------------------------------------------------
    🧠 Problem Understanding:

    Given a binary tree where each node contains either 0 or 1.
    Each root-to-leaf path represents a binary number.

    We need to return the total sum of all root-to-leaf binary numbers.

    ------------------------------------------------------------
    💡 Approach:

    ✔ Use DFS (Depth First Search)
    ✔ At each node:
        current_value = (current_value * 2) + node->val

      Why?
        Because moving to next binary digit means:
        left shift (multiply by 2) and add current bit.

    ✔ If leaf node:
        return the computed value.

    ✔ Otherwise:
        return sum of left subtree + right subtree.

    ------------------------------------------------------------
    ⏱ Time Complexity:
        O(N)
        We visit every node once.

    🧠 Space Complexity:
        O(H)
        Recursive stack (H = height of tree)

*/

class Solution {
public:

    // DFS helper function
    int solve(TreeNode* root, int val) {

        if (!root)
            return 0;

        // Build binary number
        val = (2 * val) + root->val;

        // If leaf node → return binary value
        if (root->left == nullptr && root->right == nullptr)
            return val;

        // Recur for left and right subtree
        return solve(root->left, val) + solve(root->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};

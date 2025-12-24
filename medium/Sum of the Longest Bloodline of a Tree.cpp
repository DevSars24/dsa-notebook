/***************************************************************
    File Name   : sum_of_longest_bloodline.cpp
    Problem     : Sum of the Longest Bloodline of a Tree
    Platform    : GeeksforGeeks
    Link        :
    https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

    ------------------------------------------------------------
    PROBLEM DESCRIPTION:
    ------------------------------------------------------------
    Given a binary tree, find the sum of nodes on the longest
    path from the root to any leaf node.

    - If there are multiple root-to-leaf paths of the same
      maximum length, return the path having the maximum sum.

    ------------------------------------------------------------
    APPROACH (SIMPLE LANGUAGE):
    ------------------------------------------------------------
    For every node:
    - Find the longest path from left subtree
    - Find the longest path from right subtree

    Compare:
    - If left path is longer → take left
    - If right path is longer → take right
    - If both same length → take the one with max sum

    Store:
    - length of path
    - sum of path

***************************************************************/

class Solution {
public: 

    // Returns a pair:
    // first  -> length of longest root-to-leaf path
    // second -> sum of nodes on that path
    pair<int,int> solve(Node* root) {

        // Base case: empty tree
        if (root == nullptr) {
            return {0, 0};
        }

        // Get result from left and right subtrees
        auto left  = solve(root->left);
        auto right = solve(root->right);

        // If left path is longer
        if (left.first > right.first) {
            return {
                left.first + 1,
                left.second + root->data
            };
        }
        // If right path is longer
        else if (right.first > left.first) {
            return {
                right.first + 1,
                right.second + root->data
            };
        }
        // If both paths have same length → choose max sum
        else {
            return {
                left.first + 1,
                max(left.second, right.second) + root->data
            };
        }
    }

    // Final function required by GeeksforGeeks
    int sumOfLongRootToLeafPath(Node *root) {
        return solve(root).second;
    }
};

/***************************************************************
    TIME COMPLEXITY:
    ------------------------------------------------------------
    O(N)
    - Each node is visited once

    SPACE COMPLEXITY:
    ------------------------------------------------------------
    O(H)
    - Recursive stack space
    - H = height of the tree

    ------------------------------------------------------------
    NOTES:
    ------------------------------------------------------------
    - Clean recursive Tree DP approach
    - No extra data structures
    - Interview & GFG accepted solution
    - Pattern useful for many tree problems

***************************************************************/


***************************************************************/

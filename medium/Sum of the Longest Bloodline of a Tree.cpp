/***************************************************************
    Problem: Sum of the Longest Bloodline of a Tree
    Platform: GeeksforGeeks
    Link:
    https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

    ------------------------------------------------------------
    PROBLEM STATEMENT:
    ------------------------------------------------------------
    Given a binary tree, find the sum of nodes on the longest
    path from the root to any leaf.

    - If multiple root-to-leaf paths have the same maximum
      length, choose the path with the maximum sum.

    ------------------------------------------------------------
    KEY DEFINITIONS:
    ------------------------------------------------------------
    Bloodline = Path from ROOT to LEAF

    We need:
    1. Longest root-to-leaf path (maximum length)
    2. If length ties, choose maximum sum path

    ------------------------------------------------------------
    INTUITION (VERY SIMPLE):
    ------------------------------------------------------------
    For every node:
    - Ask left subtree: "What is your longest path & its sum?"
    - Ask right subtree: "What is your longest path & its sum?"

    Compare:
    - If left path is longer → choose left
    - If right path is longer → choose right
    - If both same length → choose max sum

    Add current node value to chosen path.

    ------------------------------------------------------------
    APPROACH:
    ------------------------------------------------------------
    Use recursion + pair<int,int>

    pair.first  -> length of longest path
    pair.second -> sum of that path

    Base case:
    - If node is NULL → {0, 0}

    Recursive case:
    - Compute left and right subtree answers
    - Compare lengths
    - Resolve tie using sum

    ------------------------------------------------------------
    WHY THIS WORKS:
    ------------------------------------------------------------
    - Every node is processed once
    - Decision is local but ensures global correctness
    - Clean Tree DP approach

***************************************************************/

class Solution {
public:

    // Returns {length, sum} of longest root-to-leaf path
    pair<int,int> solve(Node* root) {

        // Base case
        if (root == nullptr) {
            return {0, 0};
        }

        // Recursive calls
        auto left  = solve(root->left);
        auto right = solve(root->right);

        // Choose longer path
        if (left.first > right.first) {
            return {left.first + 1,
                    left.second + root->data};
        }
        else if (right.first > left.first) {
            return {right.first + 1,
                    right.second + root->data};
        }
        else {
            // Same length → choose max sum
            return {left.first + 1,
                    max(left.second, right.second) + root->data};
        }
    }

    int sumOfLongRootToLeafPath(Node *root) {
        return solve(root).second;
    }
};

/***************************************************************
    TIME COMPLEXITY:
    ------------------------------------------------------------
    O(N)
    - Each node visited exactly once

    SPACE COMPLEXITY:
    ------------------------------------------------------------
    O(H)
    - Recursion stack (H = height of tree)

    ------------------------------------------------------------
    IMPORTANT NOTES:
    ------------------------------------------------------------
    - No extra data structures used
    - Clean recursion
    - Interview safe & GFG accepted
    - Pattern repeats in:
        * Deepest Leaves Sum
        * Diameter type problems
        * Tree DP questions

***************************************************************/

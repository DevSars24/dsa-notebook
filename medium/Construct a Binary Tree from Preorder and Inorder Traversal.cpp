/************************************************************
 *  Problem: Construct a Binary Tree from Preorder and Inorder Traversal
 *
 *  Platform: Coding Ninjas / Naukri Code360
 *  Question Link:
 *  https://www.naukri.com/code360/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539
 *
 *  ---------------------------------------------------------
 *  Problem Statement:
 *
 *  You are given two integer arrays:
 *   - preorder traversal of a binary tree
 *   - inorder traversal of the same binary tree
 *
 *  Your task is to construct and return the binary tree.
 *
 *  ---------------------------------------------------------
 *  Traversal Properties:
 *
 *  Preorder  -> Root | Left | Right
 *  Inorder   -> Left | Root | Right
 *
 *  ---------------------------------------------------------
 *  Key Observations:
 *
 *  1. The first element of preorder traversal is always the ROOT.
 *  2. Using inorder traversal, elements to the left of root form
 *     the left subtree and elements to the right form the right subtree.
 *  3. This process is applied recursively.
 *
 *  ---------------------------------------------------------
 *  Approach (Recursive - DFS):
 *
 *  - Maintain an index (preIndex) to track current root in preorder.
 *  - Create root node using preorder[preIndex].
 *  - Find the root position in inorder traversal.
 *  - Recursively build left subtree using left inorder segment.
 *  - Recursively build right subtree using right inorder segment.
 *
 *  ---------------------------------------------------------
 *  Time Complexity:
 *      O(N^2)  (linear search in inorder for each node)
 *
 *  Space Complexity:
 *      O(N)    (recursive stack space)
 *
 *  ---------------------------------------------------------
 *  Note:
 *  This is the most clean and beginner-friendly approach.
 *  An optimized O(N) solution can be achieved using hashmap.
 *
 ************************************************************/

/************************************************************
    Binary Tree Node structure
 ************************************************************/

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include <vector>
using namespace std;

/************************************************************
 *  Helper Function to Build Tree Recursively
 ************************************************************/

TreeNode<int>* buildTree(
    vector<int>& preorder,
    vector<int>& inorder,
    int& preIndex,
    int inStart,
    int inEnd
) {
    // Base Case
    if (inStart > inEnd) return NULL;

    // Step 1: Create root from preorder
    TreeNode<int>* root = new TreeNode<int>(preorder[preIndex]);
    preIndex++;

    // Step 2: Find root index in inorder traversal
    int rootIndex = inStart;
    while (inorder[rootIndex] != root->data) {
        rootIndex++;
    }

    // Step 3: Build left and right subtrees
    root->left = buildTree(preorder, inorder, preIndex, inStart, rootIndex - 1);
    root->right = buildTree(preorder, inorder, preIndex, rootIndex + 1, inEnd);

    return root;
}

/************************************************************
 *  Main Function
 ************************************************************/

TreeNode<int>* buildBinaryTree(vector<int>& inorder, vector<int>& preorder) {
    int preIndex = 0;
    return buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1);
}

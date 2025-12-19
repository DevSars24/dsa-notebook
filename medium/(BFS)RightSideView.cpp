/*************************************************************
 *  Question: Right View of Binary Tree
 *  
 *  Link:
 *  https://www.naukri.com/code360/problems/right-view_764605
 *
 *  Problem Statement:
 *  ------------------
 *  You are given a Binary Tree.
 *  Your task is to return the Right View of the binary tree.
 *
 *  The Right View of a Binary Tree contains all the nodes that
 *  are visible when the tree is viewed from the right side.
 *  The nodes must be printed from top to bottom order.
 *
 *  Binary Tree Node Structure:
 *
 *  template <typename T>
 *  class BinaryTreeNode {
 *  public:
 *      T data;
 *      BinaryTreeNode<T> *left;
 *      BinaryTreeNode<T> *right;
 *      BinaryTreeNode(T data) {
 *          this->data = data;
 *          left = NULL;
 *          right = NULL;
 *      }
 *  };
 *
 *************************************************************/

/*
 *  Approach: Breadth First Search (Level Order Traversal)
 *  -----------------------------------------------------
 *  - Perform level-order traversal using a queue.
 *  - For each level, the last node encountered is the
 *    rightmost node and hence part of the right view.
 *  - Push that node’s value into the result vector.
 *
 *  Why BFS?
 *  - BFS naturally processes the tree level by level.
 *  - Identifying the last node of each level becomes easy.
 *
 *  Steps:
 *  1. If the root is NULL, return an empty vector.
 *  2. Push the root into a queue.
 *  3. While the queue is not empty:
 *     - Get the size of the queue (number of nodes at this level).
 *     - Traverse all nodes of the current level.
 *     - Store the data of the last node in the result.
 *     - Push left and right children into the queue.
 *
 *  Time Complexity:
 *  - O(N), where N is the number of nodes in the tree.
 *
 *  Space Complexity:
 *  - O(N), due to the queue used for level-order traversal.
 */

#include <vector>
#include <queue>
using namespace std;

vector<int> printRightView(BinaryTreeNode<int>* root) {

    vector<int> ans;

    // Base case: empty tree
    if (root == nullptr) {
        return ans;
    }

    // Queue for level order traversal
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {

        int levelSize = q.size();

        // Traverse all nodes at current level
        for (int i = 0; i < levelSize; i++) {

            BinaryTreeNode<int>* node = q.front();
            q.pop();

            // Last node of the level -> Right View
            if (i == levelSize - 1) {
                ans.push_back(node->data);
            }

            // Push children for next level
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return ans;
}

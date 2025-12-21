/****************************************************
 * Problem: Connect Nodes at Same Level
 * Platform: GeeksforGeeks
 * Link: https://www.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
 *
 * --------------------------------------------------
 * PROBLEM STATEMENT:
 * Given a binary tree, connect nodes at the same level
 * using a pointer nextRight. The nextRight pointer of
 * the last node at each level should be set to NULL.
 *
 * Each node has the structure:
 *
 * class Node {
 * public:
 *     int data;
 *     Node* left;
 *     Node* right;
 *     Node* nextRight;
 * };
 *
 * --------------------------------------------------
 * APPROACH USED:
 * Breadth First Search (Level Order Traversal)
 *
 * - Use a queue to process nodes level by level
 * - For each level:
 *   • Connect nodes from left to right using nextRight
 *   • Last node of the level points to NULL
 * - Push children into the queue for next level
 *
 * Constraint guarantees at least one node exists.
 *
 * --------------------------------------------------
 * TIME COMPLEXITY:
 * O(N)  → Each node is visited once
 *
 * SPACE COMPLEXITY:
 * O(N)  → Queue used for level order traversal
 *
 ****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        // Constraint: at least one node exists
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();

            // Case: only one node at this level
            if (n == 1) {

                Node* node = q.front();
                q.pop();

                node->nextRight = nullptr;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);

            } 
            // Case: more than one node at this level
            else {

                // Connect nodes except last
                while (n > 1) {

                    Node* node = q.front();
                    q.pop();

                    node->nextRight = q.front();

                    if (node->left)  q.push(node->left);
                    if (node->right) q.push(node->right);

                    n--;
                }

                // Handle last node of the level
                Node* node2 = q.front();
                q.pop();

                node2->nextRight = nullptr;

                if (node2->left)  q.push(node2->left);
                if (node2->right) q.push(node2->right);
            }
        }

        return root;
    }
};

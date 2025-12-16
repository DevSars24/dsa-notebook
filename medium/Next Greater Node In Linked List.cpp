/*******************************************************
 * LeetCode: Next Greater Node In Linked List
 * Link:
 * https://leetcode.com/problems/next-greater-node-in-linked-list/
 *
 * -----------------------------------------------------
 * PROBLEM STATEMENT:
 * You are given the head of a singly linked list.
 * For each node, find the value of the next node
 * that is strictly greater than the current node.
 * If such a node does not exist, output 0.
 *
 * -----------------------------------------------------
 * APPROACH:
 *
 * Step 1: Convert Linked List to Array
 * - Linked list does not allow backward traversal
 * - Array helps us apply Next Greater Element logic easily
 *
 * Step 2: Apply Next Greater Element using Stack
 * - Stack stores indices of elements
 * - When current element > stack top element
 *   → we found the next greater element
 *
 * -----------------------------------------------------
 * TIME COMPLEXITY: O(n)
 * SPACE COMPLEXITY: O(n)
 *******************************************************/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        // Step 1: Convert linked list to array
        vector<int> arr;
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();

        // Step 2: Next Greater Element using stack
        vector<int> ans(n, 0);   // default answer is 0
        stack<int> st;           // stores indices

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

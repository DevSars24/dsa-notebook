/*
Problem Link:
https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

Given an array of integers, repeatedly remove adjacent pairs 
with opposite signs until no more such pairs exist. Return the
resulting array.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> s;

        for(int i = 0; i < arr.size(); i++) {
            // If stack is empty, just push
            if (s.empty()) {
                s.push(arr[i]);
            }
            else if ((s.top() > 0 && arr[i] < 0) || (s.top() < 0 && arr[i] > 0)) {
                // Opposite sign → cancel both
                s.pop();
            }
            else {
                // Same sign or zero cases — push
                s.push(arr[i]);
            }
        }

        // Build answer from stack
        vector<int> ans(s.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    Solution sol;
    vector<int> result = sol.makeBeautiful(arr);

    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

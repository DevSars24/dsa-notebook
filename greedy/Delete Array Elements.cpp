class Solution {
  public:
    vector<int> deleteElement(vector<int>& arr, int k) {
        stack<int> s;
        int count = 0;

        for (int x : arr) {
            // Only delete if count < k AND the current element is strictly greater
            while (!s.empty() && count < k && s.top() < x) {
                s.pop();
                count++;
            }
            s.push(x);
        }

        // IMPORTANT: We REMOVE the second while loop that pops from the end.
        // This platform expects the decreasing elements to stay.

        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};

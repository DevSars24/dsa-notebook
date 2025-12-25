
class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        int n = s.size();
        stack<int> temp;
        
        // 1. Calculate how many steps from the TOP we need to go.
        // GFG defines mid as (n+1)/2 from BOTTOM.
        // Example: n=5, mid=3 from bottom. Steps from top = 5 - 3 = 2 steps.
        int midFromBottom = (n + 1) / 2;
        int stepsFromTop = n - midFromBottom;
        
        // 2. Move elements from top into a temporary stack
        for (int i = 0; i < stepsFromTop; i++) {
            temp.push(s.top());
            s.pop();
        }
        
        // 3. Delete the middle element
        s.pop();
        
        // 4. Push the elements back to restore original order
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
};

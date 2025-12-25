/*
===========================================================
File: SpecialStack.cpp
Problem: Get Minimum Element from Stack in O(1)
Platform: GeeksforGeeks
Language: C++

-----------------------------------------------------------
Description:
This file implements a SpecialStack that supports the
following operations in constant time O(1):

1. push(x)   → Insert an element into the stack
2. pop()     → Remove the top element
3. peek()    → Get the top element
4. getMin()  → Retrieve the minimum element
5. isEmpty() → Check if the stack is empty

-----------------------------------------------------------
Approach:
We use a single stack along with a variable `mini` to track
the current minimum element.

Instead of using an auxiliary stack, we apply an encoding
technique when pushing elements smaller than the current
minimum.

Encoding Formula:
    encoded_value = 2 * x - mini

This encoded value is always smaller than the current
minimum, which helps in detecting minimum changes during pop.

-----------------------------------------------------------
Intuition:
When a new minimum arrives, we need to remember the previous
minimum. Encoding allows us to store this history inside the
stack itself.

During pop:
- If top >= mini → normal value
- If top < mini  → encoded value, decode previous minimum

-----------------------------------------------------------
Decoding Formula:
    previous_min = 2 * current_min - encoded_value

-----------------------------------------------------------
Edge Cases Handled:
- Empty stack operations
- Negative numbers
- Large values using long long
- Stack becoming empty after pop

-----------------------------------------------------------
Time Complexity:
- push()   → O(1)
- pop()    → O(1)
- peek()   → O(1)
- getMin() → O(1)

-----------------------------------------------------------
Space Complexity:
- O(1) extra space (no auxiliary stack used)

-----------------------------------------------------------
Why This Solution?
✔ Optimized
✔ Interview-friendly
✔ No extra memory
✔ Works for all integer ranges

===========================================================
*/

class SpecialStack {
    stack<long long> st;
    long long mini;

  public:
    SpecialStack() {
        mini = LLONG_MAX;
    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            mini = x;
        } else if (x >= mini) {
            st.push(x);
        } else {
            // push encoded value
            st.push(2LL * x - mini);
            mini = x;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        // encoded value detected
        if (top < mini) {
            mini = 2 * mini - top;
        }
    }

    int peek() {
        if (st.empty()) return -1;

        long long top = st.top();
        return (top < mini) ? mini : top;
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        return st.empty() ? -1 : mini;
    }
};

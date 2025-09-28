#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
int solve(int n, vector<int> &dp) {
    if (n <= 1) 
        return n;

    if (dp[n] != -1) 
        return dp[n];

    // store result in dp and return
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}

int fib(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main() {
    int n = 5;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    📝 Dry Run for n = 5

We need fib(5).
Initially: dp = {-1, -1, -1, -1, -1, -1}

solve(5)
dp[5] = -1 → compute

solve(4) + solve(3)
solve(4)
dp[4] = -1 → compute

solve(3) + solve(2)
solve(3)
dp[3] = -1 → compute
solve(2) + solve(1)

solve(2)
dp[2] = -1 → compute
solve(1) + solve(0)
→ 1 + 0 = 1
store dp[2] = 1

Back to solve(3)
solve(2) = 1 (already stored in dp)
solve(1) = 1
→ 1 + 1 = 2
store dp[3] = 2

Back to solve(4)
solve(3) = 2 (from dp)
solve(2) = 1 (from dp)
→ 2 + 1 = 3
store dp[4] = 3


Back to solve(5)
solve(4) = 3
solve(3) = 2
→ 3 + 2 = 5
store dp[5] = 5

✅ Final Answer: Fibonacci(5) = 5

👉 Output:

Fibonacci(5) = 5

2nd way bottom up approach here please see this 
```
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------📝 Dry Run for n = 5
 dry run this here 
Initialize:
dp = {-1, -1, -1, -1, -1, -1}

Set base cases:
dp[0] = 0
dp[1] = 1

Now loop:

i = 2:
dp[2] = dp[1] + dp[0] = 1 + 0 = 1
→ dp = {0, 1, 1, -1, -1, -1}

i = 3:
dp[3] = dp[2] + dp[1] = 1 + 1 = 2
→ dp = {0, 1, 1, 2, -1, -1}

i = 4:
dp[4] = dp[3] + dp[2] = 2 + 1 = 3
→ dp = {0, 1, 1, 2, 3, -1}

i = 5:
dp[5] = dp[4] + dp[3] = 3 + 2 = 5
→ dp = {0, 1, 1, 2, 3, 5}

Final Answer → dp[5] = 5
#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    if (n >= 1) dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------









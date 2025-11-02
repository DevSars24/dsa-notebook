#include <bits/stdc++.h>
using namespace std;

int main() {
    string x = "ABCBDAB";
    string y = "BDCAB";
    int n = x.length();
    int m = y.length();

    // Create DP table
    vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));

    // Fill table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i - 1] == y[j - 1])  // match characters
                c[i][j] = 1 + c[i - 1][j - 1];
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }

    cout << "Length of LCS = " << c[n][m] << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int i = 0;
        int j = tokens.size() - 1;

        int score = 0;
        int maxScore = 0;

        while (i <= j) {
            // Face-up play (gain score)
            if (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
                maxScore = max(maxScore, score);
            }
            // Face-down play (gain power)
            else if (score > 0) {
                power += tokens[j];
                score--;
                j--;
            }
            // No move possible
            else {
                break;
            }
        }
        return maxScore;
    }
};

int main() {
    Solution sol;
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;

    cout << sol.bagOfTokensScore(tokens, power) << endl;
    return 0;
}

class Solution {
  public:
    int missingNumber(vector<int> &arr) {

        sort(arr.begin(), arr.end());
        int expected = 1;

        for (int x : arr) {

            if (x <= 0) continue;      // negative + zero skip

            if (x == expected) {
                expected++;
            }
            else if (x > expected) {  // yahin break hona chahiye
                break;
            }
        }

        return expected;
    }
};

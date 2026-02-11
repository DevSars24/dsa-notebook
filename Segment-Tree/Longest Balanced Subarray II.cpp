/*
===========================================================
Problem: Longest Balanced Subarray II
Platform: LeetCode
Approach: Segment Tree with Lazy Propagation
Author: Saurabh Singh
Language: C++

Description:
We convert:
    even  -> +1
    odd   -> -1

We maintain prefix balance values using a segment tree.
Segment tree keeps track of:
    - Minimum prefix value in range
    - Maximum prefix value in range

If 0 lies within [segmin, segmax], then a balanced
subarray exists.

Time Complexity: O(n log n)
Space Complexity: O(n)
===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    vector<int> segmin, segmax, lazy;

    /*------------------------------------------------------
        Lazy Propagation Handler
    ------------------------------------------------------*/
    void propagate(int i, int l, int r) {

        if(lazy[i] != 0) {

            segmin[i] += lazy[i];
            segmax[i] += lazy[i];

            if(l != r) {
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }

            lazy[i] = 0;
        }
    }

    /*------------------------------------------------------
        Range Update: Adds 'val' to range [ql, qr]
    ------------------------------------------------------*/
    void updaterange(int ql, int qr, int i, int l, int r, int val) {

        propagate(i, l, r);

        if(r < ql || l > qr)
            return;

        if(l >= ql && r <= qr) {
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }

        int mid = l + (r - l) / 2;

        updaterange(ql, qr, 2*i+1, l, mid, val);
        updaterange(ql, qr, 2*i+2, mid+1, r, val);

        segmin[i] = min(segmin[2*i+1], segmin[2*i+2]);
        segmax[i] = max(segmax[2*i+1], segmax[2*i+2]);
    }

    /*------------------------------------------------------
        Find Leftmost Index where prefix sum == 0
    ------------------------------------------------------*/
    int findleftmostzero(int i, int l, int r) {

        propagate(i, l, r);

        if(segmin[i] > 0 || segmax[i] < 0)
            return -1;

        if(l == r)
            return l;

        int mid = l + (r - l) / 2;

        int leftresult = findleftmostzero(2*i+1, l, mid);

        if(leftresult != -1)
            return leftresult;

        return findleftmostzero(2*i+2, mid+1, r);
    }

    /*------------------------------------------------------
        Main Function
    ------------------------------------------------------*/
    int longestBalanced(vector<int>& nums) {

        n = nums.size();

        segmin.assign(4*n, 0);
        segmax.assign(4*n, 0);
        lazy.assign(4*n, 0);

        int maxl = 0;
        unordered_map<int,int> mp;

        for(int r = 0; r < n; r++) {

            int val = (nums[r] % 2 == 0) ? 1 : -1;

            int prev = -1;
            if(mp.count(nums[r]))
                prev = mp[nums[r]];

            // Remove previous contribution
            if(prev != -1)
                updaterange(0, prev, 0, 0, n-1, -val);

            // Add new contribution
            updaterange(0, r, 0, 0, n-1, val);

            int l = findleftmostzero(0, 0, n-1);

            if(l != -1)
                maxl = max(maxl, r - l + 1);

            mp[nums[r]] = r;
        }

        return maxl;
    }
};


/*----------------------------------------------------------
    Optional Driver Code (For Local Testing)
----------------------------------------------------------*/
int main() {

    Solution sol;

    vector<int> nums = {1,2,3,4,5,6};

    cout << "Longest Balanced Length: "
         << sol.longestBalanced(nums) << endl;

    return 0;
}

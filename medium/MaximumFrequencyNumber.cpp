#include <bits/stdc++.h>
using namespace std;

/*
 * Function: maximumFrequency
 * ---------------------------
 * Returns the number with maximum frequency in the array.
 * If tie occurs, returns the element which appears first.
 *
 * arr : input array of integers
 * n   : size of the array
 */
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> mp;          // Frequency map
    unordered_map<int,int> firstIndex;  // First occurrence index

    for(int i = 0; i < n; i++){
        mp[arr[i]]++;                   // Count frequency
        if(firstIndex.count(arr[i]) == 0)
            firstIndex[arr[i]] = i;    // Store first index
    }

    int maxFreq = 0;
    int ans = arr[0];  // assume first element as answer

    for(auto &p : mp){
        int num = p.first;
        int freq = p.second;

        if(freq > maxFreq){
            maxFreq = freq;
            ans = num;
        }
        else if(freq == maxFreq){
            if(firstIndex[num] < firstIndex[ans]){
                ans = num;  // tie-breaker: smaller first index
            }
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        cout << maximumFrequency(arr, N) << endl;
    }
    return 0;
}

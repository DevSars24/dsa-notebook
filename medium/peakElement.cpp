class Solution {
public:
    int peakElement(vector<int> &arr) {
        
        int n = arr.size();
    
        if(n == 1)
            return 0;
        
        if(arr[0] > arr[1])
            return 0;
         
        if(arr[n-2] < arr[n-1])
            return n-1;   // ✅ yahin close
        
        for(int i = 1; i < n-1; i++){
            if(arr[i] > arr[i+1] && arr[i] > arr[i-1]){
                return i;
            }
        }
        
        return -1; // safety
    }
};

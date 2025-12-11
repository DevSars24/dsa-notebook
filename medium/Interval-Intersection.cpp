class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();
   
        vector<vector<int>> result;
 
        int i = 0;
        int j = 0;

        while(i < m && j < n) {

            int s1 = firstList[i][0];
            int e1 = firstList[i][1];

            int s2 = secondList[j][0];
            int e2 = secondList[j][1];

            // Check intersection
            if(s1 <= e2 && e1 >= s2) {
                int start = max(s1, s2);
                int end = min(e1, e2);
                result.push_back({start, end});
            }

            // Move pointer based on which interval ends first
            if(e1 < e2){
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};

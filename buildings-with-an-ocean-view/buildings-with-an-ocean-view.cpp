class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans;
        ans.push_back(n-1);
        int rightMax = heights[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            if(rightMax < heights[i])
                ans.push_back(i);
            rightMax = max(rightMax,heights[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
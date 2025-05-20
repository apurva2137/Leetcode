class Solution {
private:
    int path(int curr, int step, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n=triangle.size();
        if(curr==n-1){
            return triangle[curr][step];
        }
        int mini=INT_MAX;
        if(dp[curr][step]!=-1) return dp[curr][step];
        int same = triangle[curr][step] + path(curr+1,step,triangle,dp);
        int plusone= triangle[curr][step] + path(curr+1,step+1,triangle,dp);
        return dp[curr][step]= min(same,plusone);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();

        vector<vector<int>> dp;
        for (int i = 0; i < m; ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        return path(0,0,triangle, dp);
        
    }
};
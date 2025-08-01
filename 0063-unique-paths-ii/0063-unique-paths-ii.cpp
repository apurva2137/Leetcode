class Solution {
public:
    int path(int i , int j , vector<vector<int>>& obs, vector<vector<int>>& dp){
        int m = obs.size();
        int n = obs[0].size();
        if(i>= m || j >= n || obs[i][j] == 1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right =path(i , j + 1, obs , dp );
        int bottom = path(i+1 , j , obs , dp );
        return dp[i][j] = right + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return path(0,0,obs,dp);
    }
};
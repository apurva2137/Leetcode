class Solution {
private:
    int path(int m, int n , int i , int j, vector<vector<int>>& dp,vector<vector<int>>& obs ){
         if(i>=m || j>=n) return 0;
        if(obs[i][j]==1) return 0;
        if(i==m-1 && j==n-1){
            return 1;
        }
       
        if(dp[i][j]!=-1) return dp[i][j];

        int right = path(m,n,i,j+1,dp,obs);
        int bottom = path(m,n,i+1,j,dp,obs);
        return dp[i][j] = right + bottom;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
         if(obs[0][0] == 1) return 0;
        return path(m,n,0,0,dp,obs);
    }
};
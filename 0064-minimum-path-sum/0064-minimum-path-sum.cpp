class Solution {
private:
    int path(int m ,int n, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];

        int right = path(m,n,i,j+1,grid,dp);
        int bottom = path(m,n,i+1,j,grid,dp);
        return dp[i][j]= grid[i][j] + min(right,bottom);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return path(m,n,0,0,grid,dp);
    }
};
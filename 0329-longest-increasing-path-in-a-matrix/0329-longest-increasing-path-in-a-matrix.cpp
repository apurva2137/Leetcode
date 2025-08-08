class Solution {
public:
    int ans = 1 ; 
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size() ; 

        vector<vector<int>>dp(m, vector<int>(n, -1));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(dp[i][j] == -1){
                    dfs(matrix, i, j, dp) ; 
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>> &matrix, int r, int c, vector<vector<int>>&dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(dp[r][c] == -1){
            dp[r][c] = 1;
        }
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int i=0;i<4;i++) {
            int x = dx[i] + r;
            int y = dy[i] + c;
            if(x < 0 || y <0 || x>=m || y>=n ) continue ;
            if(matrix[x][y] > matrix[r][c]) {
                if(dp[x][y] == -1){
                    dfs(matrix, x, y, dp);
                }
                dp[r][c] = max(dp[r][c], dp[x][y]+1);
                ans = max(ans, dp[r][c]);
            }
        }
    }
};
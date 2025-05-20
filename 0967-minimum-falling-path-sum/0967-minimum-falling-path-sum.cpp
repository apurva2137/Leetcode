class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            dp[m-1][j] = matrix[m-1][j];
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int down = dp[i+1][j];
                int diagLeft = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int diagRight = (j < n-1) ? dp[i+1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({down, diagLeft, diagRight});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};

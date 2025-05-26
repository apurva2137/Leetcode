class Solution {
public:

    int solve(int idx, bool canBuy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp) {

        if(idx == prices.size() || k == 0) {
            return 0;
        }

        if(dp[idx][k][canBuy] != -1) {
            return dp[idx][k][canBuy];
        }
        int buy = 0;
        int sell = 0;

        if(canBuy) {
           buy = max(-prices[idx] + solve(idx + 1, false, k, prices, dp), solve(idx + 1, true, k, prices, dp));
        } 
        else {
            sell = max(prices[idx] + solve(idx + 1, true, k - 1, prices, dp), solve(idx + 1, false, k, prices, dp));
        }
        

        return dp[idx][k][canBuy] = max(buy, sell);
 
    }
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (k + 1, vector<int> (2, -1)));
        return solve(0, true, k, prices, dp);
    }
};
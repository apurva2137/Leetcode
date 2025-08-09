class Solution {
public:
    int profit(int i , int buy , vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();

        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int pro = 0;
        if(buy){
           pro = max(-prices[i] + profit(i+1 , 0 , prices, dp) , 
                     profit(i+1 , 1 , prices, dp));
        }
        else{
            pro = max(prices[i] + profit(i+1, 1 , prices,dp),
                      profit(i+1, 0 , prices , dp));
        }
        return dp[i][buy] = pro;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n , vector<int>(2,-1));

        return profit(0,1,prices,dp);
    }
};
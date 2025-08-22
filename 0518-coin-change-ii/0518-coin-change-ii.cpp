class Solution {
public:
    int subset(int i , int amount , vector<int>& coins , vector<vector<int>>& dp){
        int n = coins.size();
        if(i>=n) return 0;
        if(amount == 0) return 1;
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 0 ;
        if(coins[i] <= amount){
            take = subset(i , amount - coins[i] , coins , dp);
        }
        int not_take = subset(i+1 , amount , coins , dp);
        return dp[i][amount] = (take + not_take) ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount + 1 , -1));
        return subset(0 , amount, coins , dp);
    }
};
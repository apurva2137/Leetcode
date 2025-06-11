class Solution {
    int coin(vector<int>& coins,int i, int amount,vector<vector<int>>& dp){
        if(i==0) {
        if(amount % coins[i] == 0) return amount/coins[i];
        else return 1e9;}
        int take = INT_MAX;
        if(dp[i][amount] != -1) return dp[i][amount];
        if(coins[i] <= amount){
            take = 1 + coin(coins , i , amount - coins[i],dp);
        }
        int not_take = coin(coins , i-1 , amount,dp);
        return dp[i][amount] = min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = coin(coins,n-1,amount,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
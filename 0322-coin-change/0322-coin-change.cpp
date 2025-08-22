class Solution {
public:
    int ways(int i , int amount , vector<int>& nums , vector<vector<int>>& dp){
        if(i == nums.size()-1 ){
            if(amount % nums[i] == 0) return amount / nums[i];
            else return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int take = INT_MAX ;
        if(nums[i] <= amount){
            take = 1 + ways(i , amount - nums[i] , nums , dp);
        }
        int not_take = ways(i+1 , amount , nums , dp);
        return dp[i][amount] = min(take , not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1, -1));
        int ans = ways(0 , amount , coins , dp) ;
        return ans == 1e9 ? -1 : ans;
    }
};
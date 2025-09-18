class Solution {
public:
    int amount(int i , vector<int>& nums, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + amount(i+2 , nums, dp);
        int not_take = amount(i+1 , nums , dp);
        return dp[i] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return amount(0 , nums , dp);
    }
};
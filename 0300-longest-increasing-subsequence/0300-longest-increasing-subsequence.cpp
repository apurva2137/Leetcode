class Solution {
public:
    int rec(int i , int prev_i , vector<int>& nums , vector<vector<int>>& dp ){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i][prev_i + 1] != -1) return dp[i][prev_i + 1];
        int take = 0;
        if(prev_i == -1 || nums[i] > nums[prev_i]) take = 1 + rec(i+1 , i , nums , dp);
        int not_take = rec(i+1 , prev_i , nums , dp);
        return dp[i][prev_i + 1] = max(take , not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n + 1 , -1));

        return rec(0 , -1 , nums,dp);
       
    }
};
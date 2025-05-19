class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int> dp(n+1,-1);
        return maxsum(nums,dp,n);
    }
    int maxsum(vector<int>& nums,vector<int>& dp,int n){
        if(n==0) return nums[n];
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        int pick = nums[n] + maxsum(nums,dp,n-2);
        int not_pick = maxsum(nums,dp,n-1);

        return dp[n]= max(pick , not_pick);
    }
};
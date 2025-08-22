class Solution {
public:
    bool subset(int i ,int target, vector<int>& nums , vector<vector<int>>& dp){
        if(i > nums.size()) return false;
        if(i == nums.size()) return target == 0;
        
        if(dp[i][target] != -1) return dp[i][target];

        bool take = false;
        if(nums[i] <= target){
            take = subset(i + 1, target - nums[i] , nums , dp);
        }
        bool not_take = subset(i + 1, target , nums , dp);
        return dp[i][target] = (take || not_take);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(target + 1 , -1));
        return subset(0 , target , nums, dp);
    }
};
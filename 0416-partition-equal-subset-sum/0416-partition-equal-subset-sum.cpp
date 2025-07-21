class Solution {
public:
    bool subset(int i ,vector<int>& arr , int target , vector<vector<int>>& dp){
        int n = arr.size();
        if(i >= n) return target == 0;
        if(target == 0) return true;

        if(dp[i][target]!=-1) return dp[i][target];
        bool take = false;
        if(arr[i] <= target){
            take = subset(i+1 , arr , target - arr[i] , dp);
        }
        bool not_take = subset(i+1 , arr , target , dp);
        return dp[i][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() ,0);
        if(sum % 2 != 0) return false;
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1 , -1));
        return subset(0 , nums , target , dp);
    }
};
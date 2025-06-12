class Solution {
private:
    int part(vector<int>& arr, int target,int i, vector<vector<int>>& dp){
        int n = arr.size();
        if(i==0){
            if(target == 0 && arr[0]==0) return 2 ;
            if(target == 0 || target == arr[0]) return 1;
            else return 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int take = 0;
        if(arr[i] <= target){
            take = part(arr, target - arr[i],  i-1 , dp);
        }
        int not_take = part(arr, target , i-1 , dp);
        return dp[i][target] = (take + not_take);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total - target < 0 || (total - target) % 2 != 0) return 0;

        int sum1 = (total - target) / 2;

        vector<vector<int>> dp(n, vector<int>(sum1 + 1, -1));
        return part(nums, sum1, n - 1, dp);
    }
};

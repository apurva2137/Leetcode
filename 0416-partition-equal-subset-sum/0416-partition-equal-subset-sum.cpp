class Solution {
    bool part(vector<int>& nums, int i , vector<vector<int>>& dp, int leftsum, int totalsum){
        int n = nums.size();

        if(leftsum == totalsum/2) return true;
        
        if(leftsum > totalsum/2 ) return false;

        if(i >= n){
            return (leftsum == totalsum/2);
        }
        
        if(dp[i][leftsum] != -1) return dp[i][leftsum];

        bool take = part(nums , i+1 , dp , leftsum + nums[i], totalsum);
        bool not_take = part(nums , i+1 , dp , leftsum , totalsum);

        return dp[i][leftsum] = (take || not_take);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin() , nums.end() , 0);

        if(totalsum % 2 !=0) return false; 
        vector<vector<int>> dp(n , vector<int>(totalsum/2 + 1, -1));
        return part(nums , 0 , dp, 0, totalsum );
    }
};
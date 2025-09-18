class Solution {
public:
    int mincost(int i , vector<int>& cost , vector<int>& dp){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take1 = cost[i] + mincost(i+1 , cost,dp);
        int take2 = cost[i] + mincost(i+2 , cost , dp);
        return dp[i] = min(take1,take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =  cost.size();
        vector<int> dp(n, -1);
        int start0 = mincost(0 , cost ,dp);
        dp = vector<int>(n,-1);
        int start1 = mincost(1 , cost ,dp);
        return min(start0 , start1);
    }
};
class Solution {
public:
    long long calcpts(vector<vector<int>>& questions ,int i, vector<long long>& dp){
        int n = questions.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        long long take = questions[i][0] + 
                               calcpts(questions,i + questions[i][1] + 1,dp);

        long long not_take = calcpts(questions , i+1 , dp);

        return dp[i] = max(take  , not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return calcpts(questions , 0,dp);
    }
};
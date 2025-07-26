class Solution {
public:
    bool find(int idx , const string& s , set<string>& dict, vector<int>& dp){
        int n = s.size();
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i = 1 ; i <= n - idx ; i++ ){
            if(dict.count(s.substr(idx , i))){
                if(find(idx + i , s , dict,dp)) return dp[idx]=true;
            }
        }
        return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        set<string> dict(wordDict.begin() , wordDict.end());
        return find(0,s,dict,dp);
    }
};
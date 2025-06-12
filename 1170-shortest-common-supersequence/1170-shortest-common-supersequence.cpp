class Solution {
public:
     string lcs(string s , string t){
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1,0));

        for(int i = 1 ; i<=m ; i++){
            for(int j = 1 ; j<=n ; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        int i = m;
        int j = n;
        string ans="";
        while(i>0 && j >0){
            if(s[i-1]==t[j-1]){
                ans += s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += s[i-1];
                i--;
            }
            else{
                ans += t[j-1];
                j--;
            }

        }
         while (i > 0) {
            ans += s[i - 1];
            i--;
        }
        while (j > 0) {
            ans += t[j - 1];
            j--;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string s, string t) {
        return lcs(s,t);
    }
};
class Solution {
public:
    bool isallstars(int i , string p ){
       for(int k = 1 ; k <= i ; k++){
            if(p[k-1] != '*') return false;
        }
        return true;
    }
  
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1,false));
        dp[0][0] = true;

        for(int j = 1 ; j <= n ; j++){
            dp[0][j] = isallstars(j,p);
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j<= n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1]; 
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j] = false; 
                }
            }
        }
        return dp[m][n];
    }
};
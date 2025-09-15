class Solution {
    string lcs(string s , string t){
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int maxlen = 0, endpt = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    int orig_start = i - dp[i][j];     
                    int rev_start  = j - dp[i][j];     

                    if (orig_start == (m - 1 - (j - 1))) { 
                        if (dp[i][j] > maxlen) {
                            maxlen = dp[i][j];
                            endpt = i;
                        }
                    }
                }
                else dp[i][j] = 0;
            }
        }
        return s.substr(endpt - maxlen, maxlen);
    }
public:
    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};

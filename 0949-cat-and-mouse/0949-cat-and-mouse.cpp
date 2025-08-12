class Solution {
public:
    int dp[101][101][501];
    
    int solve(int m, int c, int moves, int n, vector<vector<int>>& g){
       
        if(moves>5*n){
            return 0;
        }
        
        if(m==c){
            return dp[m][c][moves] = 2;
        }
        
        if(m==0){
            return dp[m][c][moves] = 1;
        }
        
        if(dp[m][c][moves]!=-1){
            return dp[m][c][moves];
        }
        
        if(moves%2==0){
            bool isDraw=false;
            
            for(auto &x:g[m]){
                int ans=solve(x,c,moves+1,n,g);
                if(ans==1){
                    return dp[m][c][moves] = 1;
                }
                if(ans==0){
                    isDraw=true;
                }
            }
            
            if(isDraw){
                return dp[m][c][moves] = 0;
            }
            return dp[m][c][moves] = 2;
        }
        else{
           
             bool isDraw=false;
            
            for(auto &x:g[c]){
                if(x==0){
                    continue;
                }
                int ans=solve(m,x,moves+1,n,g);
                if(ans==2){
                    return dp[m][c][moves] = 2;
                }
                if(ans==0){
                    isDraw=true;
                }
            }
            if(isDraw){
                return dp[m][c][moves] = 0;
            }
            return dp[m][c][moves] = 1;
        }
    }
    
    int catMouseGame(vector<vector<int>>& g) {
        int n=g.size();
        memset(dp,-1,sizeof(dp));
        return solve(1,2,0,n,g);
       
    }

};
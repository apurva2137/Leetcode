class Solution {
public:
    bool solver(int i, int j, int idx,vector<vector<char>>& board, string &word,vector<vector<bool>>& vis  ){
        if(idx==word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||vis[i][j]||board[i][j]!=word[idx]){

            return false;
        }

        vis[i][j]=true;

        bool found=solver(i+1,j,idx+1,board,word,vis)||
             solver(i,j+1,idx+1,board,word,vis)||
             solver(i-1,j,idx+1,board,word,vis)||       
             solver(i,j-1,idx+1,board,word,vis);

        vis[i][j]=false;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n=board.size();
        int m=board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solver(i,j,0,board,word,vis)){
                    return true;
                }
            }
        }
        return false;

    }
};
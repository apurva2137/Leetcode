class Solution {
public:
    bool solve(int i , int j ,int idx , vector<vector<char>>& board,vector<vector<int>>& vis, string word ){
        if(idx == word.size()) return true;

        if(i<0 || j<0 || i >= board.size() || j >= board[0].size() || vis[i][j] || board[i][j] != word[idx]) return false;

        vis[i][j] = 1;

        bool found = solve(i+1 , j , idx + 1 , board , vis ,word) ||
        solve(i , j+1 , idx + 1 , board , vis ,word) ||
        solve(i-1 , j , idx + 1 , board , vis ,word) ||
        solve(i , j - 1, idx + 1 , board , vis ,word);

        vis[i][j] = 0;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m , vector<int>(n,0));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(solve(i , j, 0 , board , vis , word)) return true;
            }
        }
        return false;
    }
};
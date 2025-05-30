class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i<m;i++){
                matrix[i][col]=0;
            }
            for(int j = 0 ; j<n;j++){
                matrix[row][j]=0;
            }
        }
    }
};
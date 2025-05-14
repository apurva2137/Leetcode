class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) q.push({i,j});
            }
        }
        if(n==1 || m==1){

        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<n;i++){
                matrix[i][c]=0;
            }
            for(int i=0;i<m;i++){
                matrix[r][i]=0;
            }
        }
    }
};
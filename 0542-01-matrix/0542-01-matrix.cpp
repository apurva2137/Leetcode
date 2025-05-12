class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> vis(n,-1);
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else mat[i][j]=INT_MAX;
            }
        }
        int row[4]={1,0,-1,0};
        int col[4]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nc>=0 && nc<m && nr>=0 && nr<n && mat[nr][nc]> mat[r][c]+1){  
                    mat[nr][nc]=mat[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n=image.size();
        int m=image[0].size();
        
        int initial_color= image[sr][sc];
        if (initial_color == color) return image;

        
        if(image[sr][sc]==initial_color) {
            q.push({sr,sc});
            image[sr][sc]=color;
        }
        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
               int nr= r[i]+row;
               int nc= c[i]+col;
               if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initial_color){
                image[nr][nc]=color;
                q.push({nr,nc});
            }
        }
        }
        return image;
    }
};
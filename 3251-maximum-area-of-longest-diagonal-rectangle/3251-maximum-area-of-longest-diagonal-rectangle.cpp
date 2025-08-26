class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        double maxd= 0;
        int idx = -1;
        int maxa = INT_MIN;

        for(int i = 0 ; i < dim.size() ; i++){
            int len = dim[i][0];
            int width = dim[i][1];
            double diag = sqrt(len * len + width * width);
            if(diag > maxd || diag == maxd && len * width > maxa){
                maxd = diag;
                maxa =len*width;
            }
        }
        return maxa;
    }
};
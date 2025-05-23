class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_ones=INT_MIN;
        int index = 0;
        for(int i =0 ;i<mat.size();i++){
            int ones=0;
            for(int j = 0 ;j< mat[0].size();j++){
                if(mat[i][j]==1) ones++;
            }
            if(ones > max_ones){
                index = i;
                max_ones = ones;
            }
        }
        return {index,max_ones};
    }
};
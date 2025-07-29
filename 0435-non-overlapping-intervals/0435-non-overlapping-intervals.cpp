class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& itv) {
        sort(itv.begin() , itv.end() , [](const auto& a , const auto& b){
             return a[1] < b[1];
        } );

        int endpr = itv[0][1];
        int count = 0;
        for(int i = 1 ; i < itv.size() ; i++){
            if(itv[i][0] < endpr) count++;
            else endpr = itv[i][1];
        }
        return count;
    }
};
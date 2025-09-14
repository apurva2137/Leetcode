class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv) {
        sort(itv.begin() , itv.end());
        vector<vector<int>> ans;

        int startpr = itv[0][0];
        int endpr = itv[0][1];

        for(int i = 1 ; i < itv.size() ; i++){
            int start = itv[i][0];
            int end = itv[i][1];

            if(start <= endpr){
                endpr = max(end,endpr);
            }
            else{
                ans.push_back({startpr,endpr});
                startpr = start;
                endpr = end;
            }
        }
        ans.push_back({startpr,endpr});
        return ans;
    }
};
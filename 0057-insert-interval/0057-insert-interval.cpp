class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& itv, vector<int>& newitv) {
        vector<vector<int>> ans;
        int i = 0;
        int n = itv.size();

        while( i < n && itv[i][1] < newitv[0]){
            ans.push_back({itv[i][0] , itv[i][1]});
            i++;
        }

        while( i < n && itv[i][0] <= newitv[1]){
            newitv[0] = min(itv[i][0] , newitv[0]);
            newitv[1] = max(itv[i][1] , newitv[1]);
            i++;
        }
        ans.push_back(newitv);

        while(i < n){
            ans.push_back({itv[i][0] , itv[i][1]});
            i++;
        }

        return ans;
    }
};
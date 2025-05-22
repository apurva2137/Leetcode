class Solution {
    void combination(vector<vector<int>>& ans,vector<int>& v,vector<int>& can,int target,int i){
        int n=can.size();
        if(i==n){
              if(target==0) ans.push_back(v);
              return;
        }

        if(can[i] <= target){
            v.push_back(can[i]);
            combination(ans,v,can, target - can[i],i);
            v.pop_back();
        }
        combination(ans,v,can,target,i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combination(ans,v,can,target,0);
        return ans;
    }
};
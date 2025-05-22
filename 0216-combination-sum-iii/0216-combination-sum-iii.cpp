class Solution {
    void combination(vector<vector<int>> &ans,vector<int>& v, int target, int k,int idx){
        if(target==0 && v.size()==k) {
            ans.push_back(v);
            return;
        }
        if(target<0 || v.size() > k) return;
         for (int i = idx; i <= 9; ++i) {
            v.push_back(i);
            combination(ans, v, target - i, k, i + 1); 
            v.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        combination(ans,v,n,k,1);
        return ans;
    }
};
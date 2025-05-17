class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        powerset(ans,v,0,nums);
        return ans;
    }
    void powerset(vector<vector<int>>& ans,
     vector<int>& v,int i, vector<int>& nums){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        powerset(ans,v,i+1,nums);
        v.pop_back();
        powerset(ans,v,i+1,nums);
     }
};
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 2 ; i < nums.size() ; i++){
            if(nums[i] - nums[i-2] > k ) continue;
            if(nums[i] - nums[i-2] <= k){
                ans.push_back({nums[i-2] , nums[i-1] , nums[i]});
                i+=2;
            }
        }
        if(ans.size() < n/3) return {};
        else return ans;
    }
};
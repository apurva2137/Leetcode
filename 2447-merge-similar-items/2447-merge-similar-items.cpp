class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& nums, vector<vector<int>>& nums2) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int,int> mp;

        for(auto num : nums) {
            mp[num[0]] = num[1];
        }
        for(int i = 0 ; i< nums2.size() ; i++){
            if(mp.count(nums2[i][0])){
                mp[nums2[i][0]] += nums2[i][1];
            }
            else mp[nums2[i][0]] = nums2[i][1];
        }
        for(auto it : mp) ans.push_back({it.first,it.second});
        sort(ans.begin() , ans.end());
        return ans;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int > mp;
        int maxf = 0;
        int ans = 0;

        for(auto it : nums) {
            mp[it]++;
            maxf = max(maxf , mp[it]);
        }

        for(auto it: mp){
            if(it.second == maxf){
                ans += it.second;
            }
        }
        return ans;
    }
};
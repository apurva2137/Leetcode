class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto it: nums) mp[it]++;
        
        int maxcount = 0;
        int count = 0;

        for(auto& it: mp){
            maxcount = max(maxcount , it.second);
        }
        for(auto& it:mp){
            if(it.second == maxcount) count += maxcount;
        }

        return count;
    }
};
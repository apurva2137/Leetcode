class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int right = 0;
        int count = 0;
        int sum = 0;
        
        unordered_map<int,int> mp;

        mp[0] = 1;

        while(right < nums.size()){
            sum += nums[right];

            int rem = sum%k;

            if(rem < 0) rem += k;

            if(mp.find(rem) != mp.end()) count += mp[rem];
            
            mp[rem]++;

            right++;
        }
        return count;
    }
};
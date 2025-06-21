class Solution {
public:
    int sub(vector<int>& nums , int k){
        unordered_map<int,int> mp;
        int left = 0 ;
        int right = 0;
        int n = nums.size();
        int count = 0;
         
        while(right < n){
            mp[nums[right]]++;
            while(mp.size() > k ){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto& num : nums){
            mp[num]++;
        }
        int k = mp.size();
        return sub(nums,k) - sub(nums,k-1);
    }

};
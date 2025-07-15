class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int zeroes = 0;

        while(right < n){
            if(nums[right] == 0) zeroes++;
            if(zeroes > 1){
               if(nums[left] == 0) zeroes--;
               left++;
            }
            maxlen = max(maxlen , right - left);
            right++;
        }
        return maxlen;
    }
};
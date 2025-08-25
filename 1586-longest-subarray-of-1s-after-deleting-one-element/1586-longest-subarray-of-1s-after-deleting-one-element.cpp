class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n= nums.size();
        int zeroes = 0;
        int maxlen = INT_MIN;

        while(right < n){
            if(nums[right] == 0) zeroes++;
            while(zeroes > 1){
                if(nums[left] == 0) zeroes--;
                left++;
            }
            maxlen = max(maxlen , right - left);
            right++;
        }
        return maxlen;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 ;
        int right = 0;
        int n = nums.size() ;
        int maxcount = 0;
        int count = 0;
        int zeroes = 0;
        while(right < n){
           if(nums[right] == 0) zeroes++;
           while(zeroes > k){
              if(nums[left] == 0) zeroes--;
              left++;
           }
           count = max(count , right - left + 1);
           right++;
        }
        return count;
    }
};
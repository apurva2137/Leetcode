class Solution {
    int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int left = 0;
        int right = nums.size()-1;
        int count = 0;
        vector<int> power(nums.size() , 1);
        for(int i = 1 ; i<nums.size() ; i++){
           power[i] = (power[i-1] * 2 ) % mod;
        }
        while(left <= right){
            if(nums[left] + nums[right] <= target){
               count = (count + power[right - left]) % mod;
               left++;
            }
            else {
                right--;
            }
        }
       return count ;
    }
};
class Solution {
public:
    int countSubs(vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int count = 0;
        int subs = 0;
        int n = nums.size();
        if( k < 0) return 0;
        while(right < n){

            if(nums[right] % 2 != 0) count++;

            while(count > k){
                if(nums[left] %2 != 0) count--;
                left++;
            }
            subs += right - left + 1;
            right++;
        }
        return subs;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubs(nums,k) - countSubs(nums , k-1);
    }
};
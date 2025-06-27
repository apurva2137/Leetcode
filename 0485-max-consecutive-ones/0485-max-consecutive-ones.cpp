class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int maxcount = 0;
        while(right < n){
            if(nums[right] == 0){
                left = right + 1;
            }
            maxcount = max(maxcount,right-left+1);
            right++;
        }
        return maxcount;
    }
};
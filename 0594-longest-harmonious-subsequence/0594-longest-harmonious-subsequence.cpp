class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int left = 0 ; 
        int right = 0 ;

        int n = nums.size();
        int maxlen = 0;
        while(right < n){
            if(nums[right] - nums[left] > 1){
              left++;
            }
            if(nums[right] - nums[left] == 1)
            maxlen = max(maxlen , right - left+1 );
            right++;
        }
        return maxlen;
    }
};
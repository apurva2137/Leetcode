class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i-1] > nums[i]) {
                ans= nums[i];
                break;
            }
        }
        return ans;
    }
};
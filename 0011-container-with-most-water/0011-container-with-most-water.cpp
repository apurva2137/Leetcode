class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int maxarea = 0;

        while(left <= right){
            int height = min(nums[left] , nums[right]);
            maxarea = max(maxarea , (right - left) * height);
            if(nums[left] < nums[right]) left++;
            else right --;
        }
        return maxarea;
    }
};
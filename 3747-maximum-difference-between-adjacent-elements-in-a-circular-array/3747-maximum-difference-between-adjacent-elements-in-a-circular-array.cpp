class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxdiff = INT_MIN;
        int n = nums.size();
        for(int i = 1 ; i < 2*nums.size() ; i++ ){
            maxdiff = max( maxdiff , abs(nums[i%n] - nums[(i-1) % n]));
        }
        return maxdiff;
    }
};
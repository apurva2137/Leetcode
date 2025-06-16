class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff = -1;
        int j = 0 ; 
        int minel = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            minel = min(minel , nums[i]);
            if((maxdiff < nums[i] - minel) && nums[i]!=minel)
            maxdiff = nums[i] - minel ;
        }
        return maxdiff;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int fsmall = INT_MAX;
        int ssmall = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= fsmall){
                fsmall = nums[i]; 
            }
            else if(nums[i] <= ssmall) ssmall = nums[i]; 
            else return true;
        }
        return false;
    }
};
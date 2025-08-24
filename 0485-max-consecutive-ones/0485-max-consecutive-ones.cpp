class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen = INT_MIN;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 1){
                count = 0;
            }
            else count++;
            maxlen = max(maxlen , count);
        }
        return maxlen;
    }
};
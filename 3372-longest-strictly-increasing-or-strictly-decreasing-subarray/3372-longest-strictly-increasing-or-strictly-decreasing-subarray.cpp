class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incr = 1;
        int maxincr = 1;
        int decr = 1;
        int maxdecr = 1;

        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i+1] > nums[i]) {
              incr++;
              maxincr = max(maxincr , incr);
              decr = 1;
            }
            else if(nums[i] > nums[i+1]) {
                decr++;
                maxdecr = max(maxdecr , decr);
                incr = 1;
            }
            else {
                incr = 1;
                decr = 1;
            }
        }
        return max(maxincr , maxdecr);
    }
};
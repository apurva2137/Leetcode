class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxincr = 1;
        int incr = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                incr++;
            } else {
                maxincr = max(maxincr, incr);
                incr = 1;
            }
        }
        maxincr = max(maxincr, incr); 

        int maxdecr = 1;
        int decr = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                decr++;
            } else {
                maxdecr = max(maxdecr, decr);
                decr = 1;
            }
        }
        maxdecr = max(maxdecr, decr); 

        return max(maxincr, maxdecr);
    }
};

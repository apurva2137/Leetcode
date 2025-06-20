class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxval = 0;
        long maxdiff = 0;
        long maxel = 0;

        for(long num : nums){
            maxval = max(maxval , num * maxdiff);
            maxdiff = max(maxdiff , maxel - num);
            maxel = max(maxel , num);
        }
        return maxval;
    }
};
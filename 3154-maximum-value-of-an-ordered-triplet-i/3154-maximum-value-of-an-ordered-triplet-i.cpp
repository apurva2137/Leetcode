class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long maxdiff = 0;
        long maxel = 0;
        long maxval = 0;

        for(long num : nums){
            maxval = max(maxval , num * maxdiff);

            maxdiff = max(maxdiff , maxel - num); 

            maxel = max(maxel , num); 
        }
        return maxval;
    }
};
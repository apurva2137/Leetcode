class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxval = 0;
        int n = nums.size();
        long long val = 0;
        for(int i = 0 ; i < n ; i++){
           for(int j = i+1 ; j < n ; j++){
            for(int k = j+1 ; k < n ; k++){
                val = (nums[i] - nums[j]) * 1LL * nums[k];
                maxval = max(maxval , val);
            }
          }
        }
        return maxval;
    }
};
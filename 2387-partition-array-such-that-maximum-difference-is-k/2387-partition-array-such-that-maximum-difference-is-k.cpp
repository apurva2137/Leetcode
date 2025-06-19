class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int maxi = nums[n-1];
        int mini = nums[0];
        long long count = 1;

        if(maxi - mini <= k) return count;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] - mini > k){
                count++;
                mini = nums[i];
            }
        }
        return count;
    }
};
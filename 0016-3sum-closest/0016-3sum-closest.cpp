class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size() ;
        int close = INT_MAX/2;

        for(int i = 0 ; i < n; i++){
            if(i>0 && nums[i] == nums[i-1]) i++;
            int j = i+1;
            int k = n-1;
            while(j<k){
                long long sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(close - target)){
                    close = sum;
                }
                if(sum > target) k--;
                else if(sum < target) j++;
                else return sum;
            }
        }
        return close;
    }
};
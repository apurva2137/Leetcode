class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int sum = 0;
        double maxa = INT_MIN;
        int count = 0;
        while(right < n){
             sum += nums[right];
             if(right - left+1 == k){
                maxa = max(maxa , double(sum)/k);
                sum -= nums[left];
                left++;
             }
             right++;
        }
        return maxa;
    }
};
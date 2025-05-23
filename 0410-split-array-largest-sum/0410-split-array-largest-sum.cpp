class Solution {
    int cal(vector<int>& nums, int maxp){
        int part = 1;
        int sum=0;

        for(int i=0 ; i< nums.size() ; i++){
            if(sum + nums[i] > maxp){
                part++;
                sum = nums[i];
            }
            else sum+= nums[i];
        }
        return part;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return -1;
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(left <= right){
            int mid = left + ((right - left )/2);
            int part= cal(nums , mid);
            if(part > k){
                left = mid+1;
            }
            else{
                ans = mid;
                right = mid -1;
            }
        }
        return ans;
    }
};
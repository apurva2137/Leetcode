class Solution {
public:
    int checksum(vector<int>& nums, int div){
        int total=0;
        for(int i = 0 ; i < nums.size() ; i++){
            total += ceil(double(nums[i] )/double(div));
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin() , nums.end());
        int ans = -1;
        while(left <= right){
            int mid = left + ((right - left)/2);
            if(checksum(nums,mid) <= threshold){
                ans = mid;
                right = mid -1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
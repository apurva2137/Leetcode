class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right= *max_element(nums.begin(),nums.end());
        int div=right;
        while(left<=right){
            int mid= left+ ((right-left)/2);
            if(divide(nums,mid,threshold)){
                div=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return div;
    }
    bool divide(vector<int>& nums, int divisor,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(double(nums[i])/divisor);
        }
        if(sum<=threshold) return true;
        return false;
    }
};
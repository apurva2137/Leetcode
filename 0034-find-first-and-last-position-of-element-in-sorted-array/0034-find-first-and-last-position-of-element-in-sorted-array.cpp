class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        int first=search(nums,target,true);
        int last=search(nums,target,false);
        return {first,last};
    }
    int search(vector<int>& nums, int target, bool isleft){
        int left=0;
        int right= nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid = left + ((right - left)/2);
            if(nums[mid]>target) right=mid-1;
            else if(nums[mid]<target) left=mid+1;
            else{
                ans=mid;
                if(isleft){
                    right=mid-1;
                }
                else{
                    left= mid+1;
                }
            }
        }
        return ans;
    }
};
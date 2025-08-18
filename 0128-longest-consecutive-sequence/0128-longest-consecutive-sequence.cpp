class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int maxlen = 1;
        int len = 1;
        if(nums.size() == 0) return 0;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1] + 1) len++;
            else{
                maxlen = max(maxlen , len);
                len = 1;
            }
        }
        return max(maxlen,len);
    }
};
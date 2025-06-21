class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i< nums.size()-1 ; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0 ;
                i++;
            }
        }
        int count = 0;
        for(int i = 0 ;  i < nums.size() ; i++){
            if(nums[i] == 0) count++;
            else ans.push_back(nums[i]);
        }
        for(int i = 0 ; i < count ; i++){
            ans.push_back(0);
        }
        return ans;
    }
};
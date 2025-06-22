class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int prev = nums[0] % 2;
        for(int i = 1 ; i < nums.size() ; i++){
            int parity = (nums[i] % 2 == 0) ? 0 : 1;
            if(prev == parity) return false;
            prev = parity;
        }
        return true;
    }
};
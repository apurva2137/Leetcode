class Solution {
public:
    int findMin(vector<int>& nums) {
        int minel = *min_element(nums.begin() , nums.end());
        return minel;
    }
};
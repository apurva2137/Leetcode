class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        if(m*n != nums.size()) return {};
        vector<vector<int>> v(m, vector<int>(n));
        
           for(int i = 0 ; i < nums.size() ; i++){
             v[i / n ][i % n] = nums[i];
           }
        
        return v;
    }
};
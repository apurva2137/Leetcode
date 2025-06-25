class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        if(m*n != nums.size()) return {};
        vector<vector<int>> v(m, vector<int>(n));
        
           for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                v[row][col] = nums[row * n + col];
            }
           }
        
        return v;
    }
};
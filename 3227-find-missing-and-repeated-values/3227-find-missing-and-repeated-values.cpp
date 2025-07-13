class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> nums(n*n,0);

        vector<int> ans(2);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                nums[grid[i][j]-1] +=1 ;
            }
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] ==0 ) ans[1] = i+1;
            else if(nums[i] == 2) ans[0] = i+1;
        }
        return ans;
    }
};
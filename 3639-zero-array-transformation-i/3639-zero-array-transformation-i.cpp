class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n,0);

        for(int i = 0; i < queries.size() ; i++){
            diff[queries[i][0]]++;

            if(queries[i][1] + 1 < n){
                diff[queries[i][1] + 1] --;
            }
        }
        int count = 0 ;
        for( int i = 0 ; i < n; i++){
             count += diff[i];
             if(nums[i] > count) return false;
        }
        return true;
    }
};
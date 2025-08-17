class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;

        int n = nums.size();

        set<vector<int>> s;

        for(int i = 0 ; i < n ; i++){

            for(int j = i+1 ; j < n ; j++){

                int k = j+1;
                int m = n-1;
                while(k < m){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[m];
                    
                    if(sum > target) m--;

                    else if(sum < target) k++;

                    else{
                        s.insert({nums[i] , nums[j] , nums[k] , nums[m]});
                        k++;
                        m--;
                    }
                }
            }
        }

        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};
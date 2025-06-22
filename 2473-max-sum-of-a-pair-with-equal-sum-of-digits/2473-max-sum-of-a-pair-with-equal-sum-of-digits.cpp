class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;

        for(int i = 0 ; i< nums.size() ; i++){
            int num = nums[i];
            int sum = 0;
            while(num > 0){
                 sum += num % 10;
                 num /=10;
            }
            mp[sum].push_back(nums[i]);
        }
        int maxsum = -1;
        for(auto& it: mp){
            if(it.second.size() > 1){
            sort(it.second.rbegin(),it.second.rend());
            int num1 = it.second[0];
            int num2 = it.second[1];
               maxsum = max(maxsum , num1+num2);
            }
        }
        return maxsum;
    }
};
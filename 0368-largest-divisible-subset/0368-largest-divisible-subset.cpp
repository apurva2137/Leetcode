class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans;
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi = 1;
        int lastidx = 0;
        sort(arr.begin() , arr.end());
        
        for(int i = 0 ; i < n ; i++){
            hash[i] = i;
            for(int prev = 0 ; prev < i ; prev++){
                if(arr[i] % arr[prev] == 0 && dp[i] < 1 + dp[prev]){
                   dp[i] = 1 + dp[prev];
                   hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }
        ans.push_back(arr[lastidx]);

        while(hash[lastidx] != lastidx){
            lastidx = hash[lastidx];
            ans.push_back(arr[lastidx]);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
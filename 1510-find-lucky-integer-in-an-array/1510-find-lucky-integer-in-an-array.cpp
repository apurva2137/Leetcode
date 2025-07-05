class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxn = -1;
        for(auto it: arr) mp[it]++;
        for(auto it : mp){
            if(it.first == it.second) maxn = max(maxn , it.first);
        }
        return maxn;
    }
};
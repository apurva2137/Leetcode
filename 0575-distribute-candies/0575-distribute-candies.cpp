class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mp;
        for(int i=0;i<candyType.size();i++){
            mp[candyType[i]]++;
        }
        int s=candyType.size()/2;
        int q=mp.size();
        return min(s,q);
    }
};
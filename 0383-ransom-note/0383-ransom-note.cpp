class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(auto c : r) mp1[c]++;
        for(auto c : m) mp2[c]++;

        for(int i = 0 ; i < r.size() ; i++){
            if(mp1[r[i]] > mp2[r[i]]) return false;
        }
        return true;
    }
};
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        int len = 0;
        for(auto it : mp){
            if(it.second % 2 != 0) len += 1;
            else len += 2;
        }
        return len;
    }
};
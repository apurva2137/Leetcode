class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto c: s) mp[c]++;
        int odd = 0;
        for(auto& it : mp){
            if(it.second % 2 != 0) odd++;
        }
        return (odd > 1) ? s.size() - odd + 1 : s.size();
    }
};
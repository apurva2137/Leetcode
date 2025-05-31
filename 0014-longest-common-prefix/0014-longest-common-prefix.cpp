class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());

        int n = strs.size();

        string s = strs[0];
        string t = strs[n-1];
        string str = "";
        int len = min(s.size() , t.size());
        for(int i =0 ; i< len ; i++){
            if(s[i] != t[i]) break;
            str += s[i];
        }
        return str;
    }
};
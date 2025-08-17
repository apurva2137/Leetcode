class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            s += s[i];
            string t = s.substr(i,n);
            if(t == goal) return true;
        }
        return false;
    }
};
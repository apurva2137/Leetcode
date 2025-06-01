class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0) return t[0];
        else if(t.size()==0) return s[0];
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        char c;
        for(int i = 0 ; i  < t.size() ; i++){
            if(s[i] != t[i])  {
                c= t[i];
                break;}
        }
        return c;
    }
};
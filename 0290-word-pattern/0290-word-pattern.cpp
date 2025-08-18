class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        int i = 0; 
        int j = 0; 

        while( j < p.size() && i < s.size()){
            string word = "";

            while(i < s.size() && s[i]!=' ' ){
                word += s[i];
                i++;
            }
            i++;
            if(mp2.count(word) && mp2[word] != p[j] ||
             mp1.count(p[j]) && mp1[p[j]] != word) return false;
            mp1[p[j]]=word;
            mp2[word] = p[j];
            j++;
            if(i < s.size() && j >= p.size()) return false;
        }
        return i>=s.size() && j== p.size() ;
    }
};

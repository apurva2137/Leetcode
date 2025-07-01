class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        int i = 0; 
        int j = 0; 

        while (i < s.size() && j < p.size()) {
            string word = "";

            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            i++;

            if (mp1.count(p[j]) && mp1[p[j]] != word || 
                mp2.count(word) && mp2[word] != p[j]) {
                return false;
            }

            mp1[p[j]] = word;
            mp2[word] = p[j];
            j++;

            if (j == p.size() && i < s.size()) return false;
        }

        return j == p.size() && i >= s.size();
    }
};

class Solution {
public:
    bool closeStrings(string word1, string word2) {
     if(word1.size()!=word2.size()) return false;
     set<char> s1(word1.begin(),word1.end());
     set<char> s2(word2.begin(),word2.end());
     vector<int> v1(26,0),v2(26,0);
     for(int i=0;i<word1.size();i++){
        v1[word1[i]-'a']++;
        v2[word2[i]-'a']++;
     }
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
     return v1==v2 && s1==s2;
    }
};
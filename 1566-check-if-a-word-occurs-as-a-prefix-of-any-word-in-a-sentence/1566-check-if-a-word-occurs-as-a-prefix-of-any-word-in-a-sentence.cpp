class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int n = searchWord.size();
        int word = 1;
        for(int i = 0 ; i <s.size() ; i++ ){
            if(s[i] == ' ') word++;
            else{
                string st = s.substr(i,n);
                if(st==searchWord && i==0) return word;
                else if(st==searchWord && i>0 && s[i-1] == ' ') return word;
                else continue;
            }
        }
        return -1;
    }
};
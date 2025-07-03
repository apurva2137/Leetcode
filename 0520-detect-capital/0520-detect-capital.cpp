class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        int idx = -1;
        for(int i = 0 ; i < word.size() ; i++){
            if(isupper(word[i])){
                cap++;
                idx = i;
            }
        }
        if(cap == word.size() || cap == 0 || cap == 1 && idx == 0) return true;
        return false;
    }
};
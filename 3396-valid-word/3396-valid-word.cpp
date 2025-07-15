class Solution {
public:
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
             c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
    bool isValid(string word) {
        int n = word.size();
        if(n<3) return false;
        int vowel = 0;
        int cons = 0 ;
        for(auto c:word){
            if(!isdigit(c) && !isalpha(c)) return false;
            if(isvowel(c)) vowel++;
            else if(!isvowel(c) && !isdigit(c)) cons++;
        }
        if(vowel < 1 || cons < 1) return false;
        return true;
    }
};
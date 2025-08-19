class Solution {
public:
    string reverseVowels(string s) {
        set<int> vowels = {'a' , 'e' , 'i' ,'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U'};

        int  i =0;
        int n = s.size();
        int j = n -1;
        while(i < j){
            if(vowels.count(s[i]) && vowels.count(s[j])){
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            else if(vowels.count(s[i]) && !vowels.count(s[j])){
                j--;
            }
            else i++;
        }
        return s;
    }
};
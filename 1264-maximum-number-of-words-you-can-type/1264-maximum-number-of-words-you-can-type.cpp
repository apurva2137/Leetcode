class Solution {
public:
    int canBeTypedWords(string text, string letters) {
        int count = 0;
        int i = 0;
        stringstream ss(text);
        string word;
        int words = 0;

        while(ss >> word){
            words++;
        }
        while(i < text.size()){
            char c = text[i];

            if(letters.find(c) != string::npos){
                count++;
                while(i < text.size() && text[i] != ' '){
                    i++;
                }
            }
            else i++;
        }
        return words-count;
    }
};
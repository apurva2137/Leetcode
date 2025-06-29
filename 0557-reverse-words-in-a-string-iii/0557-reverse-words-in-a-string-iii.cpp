class Solution {
public:
    string reverseWords(string s) {
        string temp ="";
        string ans = "";
        int i = 0;
        while(i < s.size()){
            char ch = s[i];
            if(ch != ' '){
                temp = ch + temp;
            }
            else if(ch == ' '){
                if(!ans.empty()){
                    ans =ans+ " "+ temp;
                }
                else ans = temp;
                temp = "";
            }
            i++;
        }
        if(temp!=""){
            if(!ans.empty()) ans = ans + " " + temp;
            else ans = temp;
        }
        return ans;
    }
};
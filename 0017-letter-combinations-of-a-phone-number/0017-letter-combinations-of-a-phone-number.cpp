class Solution {
public:
    void gen(int i ,string digits , string s ,vector<string>& ans, string alpha[]){
        if( i >= digits.size()){
            ans.push_back(s);
            return;
        }
        int digit = digits[i] - '0';
        string st = alpha[digit];

        for(int j = 0 ; j < st.size() ; j++){
            s.push_back(st[j]);
            gen(i+1 , digits , s, ans , alpha);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ans;
        string alpha[10] = {"" , "", "abc", "def" , "ghi" , "jkl", "mno" , "pqrs", "tuv", "wxyz"};

        gen(0 , digits , "" , ans,alpha);
        return ans;
    }
};
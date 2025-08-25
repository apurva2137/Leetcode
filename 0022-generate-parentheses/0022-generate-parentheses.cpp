class Solution {
public:
    void gen(int open , int close , int n ,string s, vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(s);
        }
        if(open < n){
            gen(open+1 , close , n , s + '(' , ans);
        }
        if(close < open && close < n ){
            gen(open , close + 1 , n , s + ')' , ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        gen(0 , 0 , n , "",ans);
        return ans;
    }
};
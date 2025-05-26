class Solution {
private:
    void generate(int n , string s , vector<string>& ans ){
        if(s.size() >= n) {
            ans.push_back(s);
            return;
        }
        generate(n , s + "1" , ans);
        if(s.empty() || s.back()!= '0'){
            generate(n , s + "0" , ans);
       }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(n , "" , ans);
        return ans;
    }
};
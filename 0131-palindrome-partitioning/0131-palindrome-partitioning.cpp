class Solution {
private:
    bool ispal(string s){
        int n=s.size();
        for(int i = 0 ; i <(n /2) ; i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }

    void gen(vector<vector<string>>& ans, vector<string>& v, const string& s , int i){
        if(i == s.size()){
            ans.push_back(v);
            return;
        }
        
        for(int j= i ; j < s.size() ;j++){
            string st = s.substr(i,j-i+1);
            if(ispal(st)) {
            v.push_back(st);
            gen(ans , v, s, j+1);
            v.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        gen(ans , v, s, 0);
        return ans;
    }
};
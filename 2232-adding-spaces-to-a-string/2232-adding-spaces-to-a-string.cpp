class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int j = 0;
        int idx = 0;
        int n = s.size();
        while(j<spaces.size()){
            int space = spaces[j];
            for(int i = idx ; i < space ; i++){
                ans += s[i];
            }
            ans += ' ';
            idx = space;
            j++;
        }
        while(idx < n){
            ans += s[idx];
            idx++;
        }
        return ans;
    }
};
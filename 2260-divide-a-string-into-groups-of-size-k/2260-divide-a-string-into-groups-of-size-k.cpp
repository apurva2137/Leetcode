class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string st ="";
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            st += c;
            if(st.size() == k){
                ans.push_back(st);
                st = "";
            }
        }
        if(!st.empty()){
           int j = k -st.size();
           while(j){
            st += fill;
            j--;
           }
           ans.push_back(st);
        }
        return ans;
    }
};
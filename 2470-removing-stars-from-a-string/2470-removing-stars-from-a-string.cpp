class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        int top=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                st.push(s[i]);
                top++;
            }
            else{
                st.pop();
                top--;
            }
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
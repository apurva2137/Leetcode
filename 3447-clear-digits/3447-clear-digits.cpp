class Solution {
public:
    string clearDigits(string s) {
       stack<int> st;
       for(int i=0;i<s.size();i++) {
        if(isdigit(s[i])) st.pop();
        else st.push(s[i]);
       }
       int top=st.size();
       int i=0;
       string str="";
       while(!st.empty()){
           str+=st.top();
           st.pop();
       }
       reverse(str.begin(),str.end());
       return str;
    }
};
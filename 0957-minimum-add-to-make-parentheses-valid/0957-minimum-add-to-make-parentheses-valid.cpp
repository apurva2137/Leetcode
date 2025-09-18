class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;

        for(auto c: s){
            if(c == '(') st.push('(');
            else{
                if(!st.empty() && st.top() == '(') st.pop();
                else{
                    st.push(c);
                }
            }
        }
        return  st.size();
    }
};
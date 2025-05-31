class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int count = 0;
        int maxcount = 0;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') {
                count = st.size();
                st.pop();
                maxcount = max(maxcount , count);
            }
        }
        return maxcount;
    }
};
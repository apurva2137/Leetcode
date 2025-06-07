class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n = num.size();
        if(num.size() == 1) return "0";
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && k > 0 && st.top() > (num[i] - '0')) {
                st.pop();
                k--;
            }
               st.push(num[i] - '0');
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()){
            ans += char((st.top()) + '0');
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int index = 0;
        while (index < ans.size() && ans[index] == '0') {
            index++;
        }
        ans = ans.substr(index);
        return ans.empty() ? "0" : ans;
    }
};
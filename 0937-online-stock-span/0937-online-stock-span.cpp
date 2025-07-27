class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx;
    StockSpanner() {
        idx = -1;
        stack<int>();
    }
    int next(int price) {
        idx++;
        while(!st.empty() && st.top().first <= price) st.pop();
        int ans = idx - (st.empty() ? -1 :  st.top().second);
        st.push({price ,idx});
        return ans;
    }
};

class Solution {
public:
    long long subarraySumMin(const vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n), next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        st = stack<int>();
     
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += 1LL * arr[i] * (i - prev[i]) * (next[i] - i);
        }

        return total;
    }

    long long subarraySumMax(const vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n), next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        st = stack<int>();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += 1LL * arr[i] * (i - prev[i]) * (next[i] - i);
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subarraySumMax(nums) - subarraySumMin(nums);
    }
};

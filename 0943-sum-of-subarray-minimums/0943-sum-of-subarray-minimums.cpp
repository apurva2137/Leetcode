class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevLess(n), nextLess(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            prevLess[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        s = stack<int>(); 
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            nextLess[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            long long count = (i - prevLess[i]) * (nextLess[i] - i);
            res = (res + arr[i] * count) % mod;
        }

        return res;
    }
};

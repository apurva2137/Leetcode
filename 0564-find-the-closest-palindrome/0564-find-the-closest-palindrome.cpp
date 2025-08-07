class Solution {
public:
    string nearestPalindromic(string s) {
        long n = stol(s), res = -1;
        vector<long> c = {long(pow(10, s.size() - 1)) - 1, long(pow(10, s.size())) + 1};
        string p = s.substr(0, (s.size() + 1) / 2);
        auto i = -1;
        while (i <= 1) {
            string pal = to_string(stol(p) + i++);
            string r = pal.substr(0, s.size() / 2);
            reverse(r.begin(), r.end());
            c.push_back(stol(pal + r));
        }
        i = 0;
        while (i < c.size()) {
            long x = c[i++];
            if (x != n && (res == -1 || 
            abs(x - n) < abs(res - n) || 
            (abs(x - n) == abs(res - n) && x < res))) {
                res = x;
            }
        }
        return to_string(res);
    }
};
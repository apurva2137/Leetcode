class Solution {
public:
    int strongPasswordChecker(string s) {
        if (s.size() == 0)
            return 6;
        if (s.size() == 1)
            return 5;

        int cnt = 0; 
        unordered_map<string, int> mpp;
        int i = 0;

        while (i < s.size()) {
            if (isupper(s[i])) mpp["uppercase"]++;
            else if (islower(s[i])) mpp["lowercase"]++;
            else if (isdigit(s[i])) mpp["digits"]++;

            int j = i;
            while (j < s.size() && s[i] == s[j]) j++;
            int len = j - i;
            if (len >= 3) cnt += len / 3;
            i = j;
        }

        int cnt1 = 0; 
        if (mpp["uppercase"] == 0) cnt1++;
        if (mpp["lowercase"] == 0) cnt1++;
        if (mpp["digits"] == 0) cnt1++;

        if (s.size() < 6) {
            return max(6 - (int)s.size(), cnt1);
        } 
        else if (s.size() > 20) {
            int len = s.size() - 20; 
            vector<int> res(3, 0); 
            i = 0;
            while (i < s.size()) {
                int j = i;
                while (j < s.size() && s[i] == s[j]) j++;
                int len = j - i;
                if (len >= 3) {
                    res[len % 3]++;
                }
                i = j;
            }
            for (int k = 0; k < 3; k++) {
                if (len <= 0) break;
                int mini = min(res[k], len / (k + 1));
                cnt -= mini;
                len -= mini * (k + 1);
            }

            cnt -= len / 3;
            return (s.size() - 20) + max(cnt, cnt1);
        }
        return max(cnt, cnt1);
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> tFreq;
        for (char c : t) tFreq[c]++;

        unordered_map<char, int> sFreq;
        int required = tFreq.size();
        int formed = 0;

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.size()) {
            char c = s[right];
            sFreq[c]++;

            if (tFreq.count(c) && sFreq[c] == tFreq[c])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                sFreq[s[left]]--;
                if (tFreq.count(s[left]) && sFreq[s[left]] < tFreq[s[left]])
                    formed--;
                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len = 0;
        int n = words.size();
        unordered_map<string,int> mp;
        bool hasMiddle = false;
        for(int i = 0 ; i < n ; i++){
             mp[words[i]]++;
        }
        for (auto& it : mp) {
            string s = it.first;
            string rev = string(s.rbegin(), s.rend());
            int count = it.second;
            if (s == rev) {
                len += (count / 2) * 4;
                if (count % 2 == 1) hasMiddle = true;
            } else if (mp.count(rev)) {
                int mincount = min(count, mp[rev]);
                len += mincount * 4;
                mp[rev] = 0; 
                mp[s] = 0;
            }
        }
        if(hasMiddle) len+=2;

        return len;
    }
};
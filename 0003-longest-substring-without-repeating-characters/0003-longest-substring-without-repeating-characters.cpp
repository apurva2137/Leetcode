class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int left = 0;
        int right = 0;
        int n = s.size();
        vector<int> mp(256 , -1);

        while(right < n){
            if(mp[s[right]] != -1 && mp[s[right]] >= left ){
                left = mp[s[right]] + 1;
            }
            maxlen = max(maxlen , right - left + 1);
            mp[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};
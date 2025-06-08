class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mp;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxlen = 0;
        int maxfreq=0;
        while(right < n){
            mp[s[right]-'A']++;
            
            maxfreq = max(maxfreq,mp[s[right] - 'A']);

            if((right - left + 1) - maxfreq > k){
                mp[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen , (right -left +1));
            right++;
        }
        return maxlen;
    }
};
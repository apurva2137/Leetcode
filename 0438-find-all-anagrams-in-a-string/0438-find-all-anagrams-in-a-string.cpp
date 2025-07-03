class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> mpp(26,0);
        vector<int> mp(26,0);
        
        for(int i=0;i<k;i++){
            mpp[p[i]-'a']++;
            mp[s[i]-'a']++;
        }
        
        vector<int> ans;

        if(mpp == mp) ans.push_back(0);
        
        for(int i=k ; i < n; i++){
            mp[s[i-k] - 'a']--;
            mp[s[i] - 'a']++;
            
            if(mpp == mp) ans.push_back(i-k+1);
        }
        return ans;
    }
};
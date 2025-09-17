class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp1;
        int count = 0;

        int i = 0;

        for(auto it : s) mp1[it]++;

        unordered_map<char,int> mp2;

        while(i < s.size()){
            mp2[s[i]]++;
            mp1[s[i]]--;

            if(mp1[s[i]] == 0) mp1.erase(s[i]);

            if(mp1.size() == mp2.size()) count++;

            i++;
        }
        return count;
    }
};
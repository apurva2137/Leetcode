class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        
        for(int i = 0 ; i < words.size() ; i++){
            string s = words[i];
            int n = s.size();
            for(int j = i+1 ; j < words.size() ; j++){
                int size = words[j].size();
                string word = words[j];
                if(word.substr(0,n) == s && word.substr(size-n, n)==s)
                count++;
            }
        }
        return count;
    }
};
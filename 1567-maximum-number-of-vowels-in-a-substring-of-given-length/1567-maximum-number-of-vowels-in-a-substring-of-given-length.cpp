class Solution {
public:
    bool isvowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    int maxVowels(string s, int k) {
        int left = 0;
        int right = 0;
        int maxc = 0;
        int count = 0;
        int n = s.size();

        while(right < n){
            if(isvowel(s[right])) count++;
            if(right >= k -1){
                maxc = max(maxc , count);
                if(isvowel(s[left]))
                    count--;
                left++;
            }
            right++;
        }
        return maxc;
    }
};
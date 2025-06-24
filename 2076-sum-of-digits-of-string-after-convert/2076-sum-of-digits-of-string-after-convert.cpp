class Solution {
public:
    int getLucky(string s, int k) {
        unordered_map<char,int> mp;
        for(char i = 'a'; i <= 'z' ; i++){
            mp[i] = i - 'a' + 1;
        }
        
        long long sum = 0;
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            int val = mp[c];
            while(val > 0){
                sum += val % 10;
                val = val / 10;
            }
        }

        k--;
        if(k == 0) return sum;

        int ans = sum;
        int res = 0;
        
        while(k > 0){
            res = 0;  // ✅ Reset before each transformation
            while(ans > 0){
                res += ans % 10;
                ans /= 10;
            }
            ans = res;  
            k--;
        }

        return res;
    }
};

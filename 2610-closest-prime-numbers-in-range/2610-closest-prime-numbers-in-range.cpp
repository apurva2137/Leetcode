class Solution {
    bool isprime(int n){
        if(n<=1) return false;
        for(int i = 2; i*i <=n ; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        int prev = -1;
        int minDiff = INT_MAX;
        int res1 = -1, res2 = -1;

        for (int i = left; i <= right; ++i) {
            if (isprime(i)) {
                if (prev != -1 && i - prev < minDiff) {
                    minDiff = i - prev;
                    res1 = prev;
                    res2 = i;
                }
                prev = i;
            }
        }
        return {res1,res2};
    }
};
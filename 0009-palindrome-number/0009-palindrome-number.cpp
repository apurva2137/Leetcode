class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int temp = x;
        int rev = 0;

        while(temp > 0){
            rev = 1LL*rev*10 + temp%10;
            temp /= 10;
        }
        return rev == x;
    }
};
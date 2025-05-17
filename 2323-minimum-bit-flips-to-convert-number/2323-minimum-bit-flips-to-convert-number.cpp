class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorv = start ^ goal ;
        int count = 0;
        while(xorv !=0){
           count += xorv & 1;
           
           xorv >>= 1 ;
        }
        return count;
    }
};
class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            int guess_num=guess(mid);
            if(guess_num==0) return mid;
            else if(guess_num==-1) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
};
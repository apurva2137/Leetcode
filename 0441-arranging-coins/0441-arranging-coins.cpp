class Solution {
public:
    bool arrange(long long rows , int n){
        long long count = (rows * (rows + 1))/2;
        return count <= n;
    }
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(arrange(mid , n)){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};
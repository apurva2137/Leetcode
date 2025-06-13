class Solution {
public:
    long long countb(vector<int>& piles, int hour){
        long long total = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            total += ceil(double(piles[i]) / double(hour));
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin() , piles.end());
        int ans = right;
        while(left <= right){
            int mid = left + ((right - left)/2);
            if(countb(piles , mid) <= h){
                ans = mid;
                right = mid -1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
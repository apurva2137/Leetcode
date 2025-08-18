class Solution {
public:
    long long hourly(vector<int>& piles, int h){
        long long tot = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            tot += ceil(double(piles[i]) / double(h));
        }
        return tot;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin() , piles.end());
        int ans = right;
        while(left <= right){
            int mid = left + ((right - left) / 2);
            if(hourly(piles,mid) <= h){
                ans = mid;
                right = mid-1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
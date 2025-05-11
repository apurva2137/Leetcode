class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left=1;
        long long right=*max_element(piles.begin(),piles.end());
        long long maxel=right;
        while(left<=right){
            long long mid=left + (right-left)/2;
            if(hourly(piles,mid)<=h){
                maxel=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return maxel;
    }
    long long hourly(vector<int>& piles, int hourly){
        long long tot=0;
        for(int i=0;i<piles.size();i++){
           tot+= ceil((piles[i]+hourly-1)/hourly);
        }
        return tot;
    }
};
class Solution {
public:
    int ship(vector<int>& weights, int minw){
        int total = 0;
        int day = 1;

        for(int i = 0 ; i < weights.size() ; i++){
            if(total + weights[i] > minw){
                day++;
                total = 0;
            }
            total += weights[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left =*max_element(weights.begin() ,weights.end());
        int right =accumulate(weights.begin() , weights.end(),0);

        int ans = -1;

        while(left <= right){
            int mid = left + ((right - left)/2);
            if(ship(weights , mid) <= days){
                ans = mid;
                right = mid -1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
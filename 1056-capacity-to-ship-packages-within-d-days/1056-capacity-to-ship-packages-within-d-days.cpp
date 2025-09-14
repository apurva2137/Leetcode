class Solution {
public:
    int ship(vector<int>& weights, int minw){
        int tot = 0;
        int days = 1;

        for(int i = 0 ; i < weights.size() ; i++){
            if(tot + weights[i] <= minw){
                tot += weights[i];
            }
            else{
                days++;
                tot = weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin() , weights.end());
        int right = accumulate(weights.begin() , weights.end(),0);

        int ans = right;

        while(left <= right){
            int mid = left + ((right - left) / 2);

            if(ship(weights , mid) <= days){
                ans = mid;
                right = mid - 1;
            }

            else left = mid + 1;
        }
        return ans;
    }
};
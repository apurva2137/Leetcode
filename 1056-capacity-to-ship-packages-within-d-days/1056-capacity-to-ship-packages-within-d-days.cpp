class Solution {
public:
    bool mincap(int cap , vector<int>& weights, int days ){
           
           int load = 0, d=1;

           for(auto w : weights ){
              if(load + w > cap){
                d++;
                load = 0 ;
              }
              load += w;
           }
           return d<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int left= *max_element( weights.begin() , weights.end() );
        int right= accumulate( weights.begin() , weights.end(), 0);

        int ans = left;

        while(left <= right){
            int mid = left + ((right - left )/ 2);

            if( mincap( mid, weights, days)){
                ans = mid;
                right = mid -1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
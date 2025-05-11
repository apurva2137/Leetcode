class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=k*1LL * m*1LL;
        if(val > bloomDay.size()) return -1;

        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int mindays=right;
        while(left<=right){
            int mid= left+ (right-left)/2;
            if(countif(bloomDay,mid,m,k)){
                mindays=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return mindays;
    }
    bool countif(vector<int>& bloomDay,int day, int m, int k){
        int n=bloomDay.size();
        int count=0;
        int bloom=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else{
                bloom+=count/k;
                count=0;
            }
        }
        bloom+=count/k;
        if(bloom>=m) return true;
        return false;
    }
};
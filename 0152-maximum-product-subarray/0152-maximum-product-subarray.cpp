class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod=INT_MIN;
        int lprod=1;
        int rprod=1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            lprod*=nums[i];
            rprod*=nums[n-i-1];

            max_prod=max(max_prod,max(lprod,rprod));
            if(lprod==0) lprod=1;
            if(rprod==0) rprod=1;
        }
       
        return max_prod;
    }
};
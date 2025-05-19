class Solution {
public:
    string triangleType(vector<int>& nums) {
        int equal=1;
        sort(nums.begin(),nums.end());
        int a= nums[0];
        int b= nums[1];
        int c=nums[2];
        if(a+b <= c) return "none";
        for(int i=0; i<3; i++){
            if(nums[i]==nums[i+1]) equal++;
        }
        if(equal==3) return "equilateral";
        else if(equal==2) return "isosceles";
        else  return "scalene";
    }
};
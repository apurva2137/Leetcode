class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(), n=nums2.size();
        vector<int>res(k);
        for(int i=0; i<=k; i++){
            if(i<=m and k-i<=n){
                vector<int>v1=maxArray(nums1, i), v2=maxArray(nums2, k-i);
                vector<int>v=merge(v1,v2 , k);
                res=max(res, v);
            }
        }
        return res;
    }
	
    vector<int>merge(vector<int>&nums1 , vector<int>&nums2, int k){
        vector<int>v(k);
        for(int i=0, j=0, t=0;t<k; t++){
            v[t]=cmp(nums1,i, nums2, j)?nums1[i++]:nums2[j++];
        }
        return v;
    }
	
    bool cmp(vector<int>&nums1, int i, vector<int>&nums2,int j){
        while(i<nums1.size() and j<nums2.size() and nums1[i]==nums2[j]){
            i++, j++;
        }
        return j==nums2.size() or (i<nums1.size() and nums1[i]>nums2[j]);
    }
	
    vector<int>maxArray(vector<int>&nums, int k){
        int n=nums.size();
        vector<int>v;
        for(int i=0; i<n; i++){
            while(v.size()+n-i>k and !v.empty() and v.back()<nums[i])v.pop_back();
            if(v.size()<k)v.push_back(nums[i]);
        }
        return v;
    }
};
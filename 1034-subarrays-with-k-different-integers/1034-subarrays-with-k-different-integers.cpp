class Solution {
    int countsubs(vector<int>& s, int k){
int left = 0;
        int right=0;
        int n = s.size();
        int count = 0;
        unordered_map<int , int> mp;
        
        while(right < n){
            if(mp[s[right]] ==0) k--;
            mp[s[right]]++;
                        
            while(k<0){
                mp[s[left]]--;
                if(mp[s[left]] == 0) k++;
                left++;
            }
            count += right - left + 1;
            right++;
        }
        
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countsubs(nums , k) - countsubs(nums , k - 1);
    }
};

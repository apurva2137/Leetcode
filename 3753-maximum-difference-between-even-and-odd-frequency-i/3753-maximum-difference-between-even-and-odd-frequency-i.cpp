class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26 , 0);
        for(int i = 0 ; i < s.size() ; i++){
            v[s[i] - 'a']++;
        }
        int evemin = INT_MAX;
        int oddmax = 0;
      

        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] % 2 != 0){
                oddmax = max(oddmax,v[i]);
            } 
            if(v[i] % 2 == 0 && v[i] > 0){
                evemin = min(evemin , v[i]) ;   
            }
        }
      
        return oddmax-evemin;
    }
};
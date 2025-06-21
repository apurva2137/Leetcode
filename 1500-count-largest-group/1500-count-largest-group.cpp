class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> v(40,0);
        for(int i = 1 ; i <= n ; i++){
           int num = i;
           int sum = 0 ;
           while(num > 0){
              sum += num % 10;
              num /= 10;
           }
           v[sum]++;
        }
        int maxel = *max_element(v.begin() , v.end());
        int count = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] == maxel)
            count++;
        }
        return count;
    }
};
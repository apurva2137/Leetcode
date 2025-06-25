class Solution {
public:
    int chalkReplacer(vector<int>& chalk, long long k) {
        long long sum = accumulate(chalk.begin() , chalk.end() , 0LL);

        while(k > 0 && k >= sum) k-= sum;

        if(k==0) return 0;
        
        while(k > 0) {
          for(long long i = 0 ; i < chalk.size() ; i++){
              if(k < chalk[i]) return i;
              
              else  k -= chalk[i];
          }
        }
       
        return -1;
    }
};
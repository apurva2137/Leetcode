class Solution {
public:
    double average(vector<int>& salary) {

        int n = salary.size();

        sort(salary.begin() , salary.end()); // 1000 2000 3000 4000

        int sum = 0;
        int count = 0;
        for(int i = 1 ; i < n-1 ; i++){
            count++;
            sum += salary[i];
        }
        return double(sum)/count;
    }
};
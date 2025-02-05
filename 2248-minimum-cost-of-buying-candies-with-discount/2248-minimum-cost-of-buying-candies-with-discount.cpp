class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int c=0;
        int count=0;
        int n=cost.size()-1;
        for(int i=0;i<cost.size();i++){
            c+=cost[n-i];
            count++;
            if(count==2){
            i++;
            count=0;
            }
        }
        return c;
    }
};
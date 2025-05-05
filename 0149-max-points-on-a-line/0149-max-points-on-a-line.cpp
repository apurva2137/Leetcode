class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
       for(int i=0;i<n-1;i++){
            map<double,int> m;
            for(int j=i+1;j<n;j++){
    double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
    if(pt[j][1]-pt[i][1]<0 &&(pt[j][0]-pt[i][0])==0 ) m[abs(x)]++; 
                else m[x]++;
            }
            int t = 0;
            for(auto i:m)
                t = max(t, i.second+1); 
            ans = max(t, ans);
        }
        return ans;
    }
};
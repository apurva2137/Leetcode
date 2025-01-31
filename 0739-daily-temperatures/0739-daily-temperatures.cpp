class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> v(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            int curr=temperatures[i];
            while(!s.empty() && temperatures[s.top()]<=curr){
                s.pop();
            }
            if(s.empty()){
                v[i]=0;
            }
            else{
                v[i]=s.top()-i;
            }
            s.push(i);
        }
        return v;
    }
};
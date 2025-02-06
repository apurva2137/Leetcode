class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
            while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top()){
                st.pop();
            }
            if(st.empty() || st.top()<0) st.push(asteroids[i]);
            if(!st.empty() && st.top()==abs(asteroids[i])) st.pop();
            }
        }
        vector<int> v(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            v[i]=st.top();
            st.pop();
            i--;
        }
        return v;
    }
};
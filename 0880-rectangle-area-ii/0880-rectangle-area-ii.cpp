class Solution {
public:  
    int rectangleArea(vector<vector<int>>& rect) {
        sort(rect.begin(),rect.end(),[](vector<int>&a, vector<int>&b){return a[1]<b[1];});
        
        long long int tarea = 0;
        int MOD = 1e9 + 7;
        
        while(!rect.empty())
        {
            
            map<int,int>tmap;
                                    
            int it = 0;
            int miny = rect[0][1];
            int minty = INT_MAX;
            
            while(it<rect.size() && rect[it][1]==miny)
                  minty=min(minty,rect[it][3]),it++;
            
            int range = min(minty-miny,it<rect.size() ? rect[it][1] - miny : INT_MAX);
            
            it = 0;
            while(!rect.empty() && it<rect.size() && rect[it][1]==miny)
            { 
                tmap[rect[it][0]] += 1;
                tmap[rect[it][2]] -= 1;
                
                rect[it][1]+=range;
                if(rect[it][3]>rect[it][1])it++;
                else rect.erase(rect.begin()+it);
            }
            
            int curr = 0;
            int first;
            long long int w;
            long long int h = range;
            long long int area = 0; 
            
            for(auto &t : tmap)
            {
                if(curr==0)first = t.first;
                curr+=t.second;
                if(curr==0)
                {
                    w = (t.first-first);
                    area =  area % MOD + ( w * h) % MOD;   
                }
            }
            
            tarea = (tarea + area) %MOD;
            
        }
        
        return tarea;
    }
};
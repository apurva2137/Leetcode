class Solution {
public:
    bool check(string& s,string& t) {
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=t[i]) cnt++;
            if(cnt>2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        map<string,vector<string>> adj;
        int n=strs.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=j) {
                    if(check(strs[i],strs[j])) {
                        adj[strs[i]].push_back(strs[j]);
                        adj[strs[j]].push_back(strs[i]);
                    }
                }
            }
        }
        map<string,int> vis;
        int res=0;
        for(int i=0;i<n;i++) {
            if(vis.find(strs[i])==vis.end()) {
                res++;
                vis[strs[i]]=1;
                queue<string> q;
                q.push(strs[i]);
                while(!q.empty()) {
                    string node=q.front();
                    q.pop();
                    for(auto it:adj[node]) {
                        if(vis.find(it)==vis.end()) {
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int> indegree(V,0);
        vector<vector<int>> revGraph(V);
        for (int u = 0; u < V; ++u) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it : revGraph[node]){
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            } 
            ans.push_back(node);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
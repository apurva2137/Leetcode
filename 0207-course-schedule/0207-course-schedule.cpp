class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            topo.push_back(node);
        }
        return (topo.size()==V);
    }
};
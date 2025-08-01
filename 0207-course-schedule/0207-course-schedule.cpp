class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> indeg(n);
        vector<vector<int>> adj(n);

        for(auto edge : prereq){
            adj[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i < indeg.size() ; i++){
            if(indeg[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
            topo.push_back(node);
        }
        return topo.size() == n;
    }
};
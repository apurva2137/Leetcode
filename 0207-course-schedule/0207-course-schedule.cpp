class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(V);
        vector<int> indeg(V);
        queue<int> q;

        for(auto edge: prereq){
            adj[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
        }

        for(int i = 0 ; i < V ; i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
            ans.push_back(node);
        }
        return V == ans.size();
    }
};
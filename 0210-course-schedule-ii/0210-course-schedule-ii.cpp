class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int> ans;
        vector<int> indeg(n);
        vector<vector<int>> adj(n);

        for(auto edge: prereq){
            adj[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
        }
        queue<int> q;

        for(int i = 0 ; i < n ; i++){
            if(indeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                indeg[it]--;

                if(indeg[it] == 0) q.push(it);
            }
            ans.push_back(node);
        }
        if(ans.size() == n) return ans;
        return {};
    }
};
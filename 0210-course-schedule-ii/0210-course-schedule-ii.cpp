class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<int> in(V,0);
        vector<vector<int>> adj(V);

        for(auto edge: edges){
            adj[edge[1]].push_back(edge[0]);
            in[edge[0]]++;
        }
        queue<int> q;
        for(int i=0;i<in.size();i++){
           if(in[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();

            for(auto it: adj[node]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
            ans.push_back(node);
        }
        if(ans.size()==V) return ans;
        return {};
    }
};
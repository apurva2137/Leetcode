class Solution {
public:
    bool dfs(int src , vector<int>& vis ,vector<vector<int>>& graph, int col){
        vis[src] = col;

        for(auto node: graph[src]){
            if(!vis[node]){
                if(!dfs(node , vis , graph , !col)) return false;
            }
            else{
                if(vis[node] == col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(!dfs(i , vis , graph , 0)) return false;
            }
        }
        return true;
    }
};
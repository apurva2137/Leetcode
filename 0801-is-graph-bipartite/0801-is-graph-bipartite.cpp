class Solution {
private:
    bool dfs(int src, int clr, vector<vector<int>>& graph, vector<int>& color){
        color[src]=clr;

        for(auto node: graph[src]){
            if(color[node]==-1){
                if(dfs(node,!clr,graph,color)==false) return false;
            }
            else if(color[node]==clr) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false) return false;
            }
        }
        return true;
    }
};
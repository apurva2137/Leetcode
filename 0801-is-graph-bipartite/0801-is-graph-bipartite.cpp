class Solution {
public:
    bool bipartite(vector<vector<int>>& graph , vector<int>& color, int src , int col){
        color[src] = col;

        for(auto it: graph[src]){
            if(color[it] == -1){
                if(!bipartite(graph , color , it , !col)) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N , -1);

        for(int i = 0 ; i < N ; i++){
            if(color[i] == -1){
                if(!bipartite(graph , color , i , 0)) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i < flights.size() ; i++){
            int src = flights[i][0];
            int node = flights[i][1];
            int wt = flights[i][2];
            adj[src].push_back({node,wt});
        }
        queue<pair<int,pair<int,int>>> q;

        q.push({0 , {src,0}});
        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        while(!q.empty()){
             int dist = q.front().first;
             int node = q.front().second.first;
             int stops = q.front().second.second;

             q.pop();
             if (stops > k) continue;

             for(auto it: adj[node]){

                int adjNode = it.first;
                int wt = it.second;

                if(dist + wt < dis[adjNode]){

                    if(stops <= k){
                        dis[adjNode] = dist + wt;
                        q.push({dist + wt , {adjNode , stops+1}});
                    }
                }
             }
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};
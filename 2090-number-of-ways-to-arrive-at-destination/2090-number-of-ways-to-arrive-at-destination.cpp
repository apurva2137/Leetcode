class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        
        for(auto& road : roads){
            int u = road[0], v = road[1], wt = road[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto& [adjNode, wt] : graph[node]){
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(dis + wt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
};

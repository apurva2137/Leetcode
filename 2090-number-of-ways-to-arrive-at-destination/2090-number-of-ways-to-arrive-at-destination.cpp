class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int,int>>> graph(n);

       for(int i = 0 ; i < roads.size() ; i++){
            int src = roads[i][0];
            int node = roads[i][1];
            int wt = roads[i][2];
            graph[src].push_back({node,wt});
            graph[node].push_back({src,wt});
        }

       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        pq.push({0,0});
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        ways[0] = 1;
        dist[0] = 0;


        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto& [adjNode , wt]: graph[node]){
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode] , adjNode});
                }
                else if(dis + wt == dist[adjNode] ){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for(auto edge : flights){
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            adj[from].push_back({to, weight});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        int stopCnt = 0;
        while(!q.empty()){
            auto it = q.front();
            int node = it.second.first;
            int distNode = it.second.second;
            int level = it.first;
            if(level > k){
                break;
            }
            q.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;

                if(distNode + adjDist < dist[adjNode]){
                    dist[adjNode] = distNode + adjDist;
                    q.push({level + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
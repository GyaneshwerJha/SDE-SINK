class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];

        // created adjacency matrix
        for(auto edge : times){
            int from = edge[0];
            int to = edge[1];
            int time = edge[2];
            adj[from].push_back({to, time});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[0] = -1;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int distNode = it.first;
            pq.pop();
            for(auto it2 : adj[node]){
                int adjNode = it2.first;
                int adjDist = it2.second;

                if(distNode + adjDist < dist[adjNode]){
                    dist[adjNode] = distNode + adjDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }


        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
        }

        int maxi = *max_element(dist.begin(), dist.end());

        return maxi;
    }
};
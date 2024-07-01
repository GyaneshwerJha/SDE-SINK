#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        int src = 0;
        int dst = n - 1;
        vector<pair<int, int>> adj[n];
        for(auto& edge : roads){
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];
            adj[from].push_back({to, wt});
            adj[to].push_back({from, wt});
        }

        vector<long long> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        ways[src] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // // Skip outdated entries
            // if(cost > dist[node]) continue;

            for(auto& it : adj[node]){
                int adjNode = it.first;
                long long adjDist = it.second;

                if(cost + adjDist < dist[adjNode]){
                    dist[adjNode] = cost + adjDist;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if (cost + adjDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[dst];
    }
};

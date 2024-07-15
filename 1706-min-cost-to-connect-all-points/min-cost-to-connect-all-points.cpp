class Solution {
public:
    
public:
    int minCostConnectPoints(vector<vector<int>>& input) {
        int n = input.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n, 0);
        pq.push({0, 0});

        int minCost = 0;
        while (!pq.empty()) {
            pair<int, int> it = pq.top();
            int cost = it.first;
            int node = it.second;
            pq.pop();
            if(visited[node]) continue;

            visited[node] = 1;
            minCost += cost;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int dist = abs(input[node][0] - input[i][0]) + abs(input[node][1] - input[i][1]); 
                    pq.push({dist, i});
                }
            }
        }
        return minCost;
    }

};
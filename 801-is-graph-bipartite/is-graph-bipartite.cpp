class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1); // Initialize all nodes as uncolored (-1)

        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) { // If the node is not colored
                queue<int> q;
                q.push(i);
                color[i] = 1; // Start coloring with 1

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) { // If the neighbor is not colored
                            color[neighbor] = 1 - color[node]; // Color with the opposite color
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) { // If the neighbor has the same color
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

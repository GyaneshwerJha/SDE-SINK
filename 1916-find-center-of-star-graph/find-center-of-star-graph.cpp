class Solution {
public:
   int findCenter(vector<vector<int>>& edges) {
    int V = edges.size();
    vector<int> adj[V + 2];  // Adjust size to V+1 to cover all vertices (1-indexed)

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= V + 2; i++) {
        if (adj[i].size() == V) {  
            return i;
        }
    }
    return -1;  
}

};
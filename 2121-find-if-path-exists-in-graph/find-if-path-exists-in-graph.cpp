class Solution {
public:
    void bfs(int source, int destination, vector<int> *adj, vector<int> &vis){
        
        vis[source] = 1;
        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); 
        }
        
        vector<int> vis(n, 0);

        bfs(source, destination, adj, vis);

        return vis[destination] == 1;
    }
};
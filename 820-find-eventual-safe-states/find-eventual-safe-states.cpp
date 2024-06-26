class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &visited, vector<int> &inRecursion, vector<int> &check){
        visited[node] = true;
        inRecursion[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, adj, visited, inRecursion, check) == true){
                    return true;
                }
            }
            else{
                if(inRecursion[it] == true){
                    return true;
                }
            }
        }
        
        check[node] = 1;
        inRecursion[node] = false;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> inRecursion(V, 0);
        vector<int> check(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, graph, visited, inRecursion, check);
            }
        }
        
        vector<int> safeNode;
        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                safeNode.push_back(i);
            }
        }

        return safeNode;
    }
};
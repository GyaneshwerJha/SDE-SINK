class Solution {
public:
    bool solve(vector<vector<int>> &graph, vector<int> color, int start){
        int V = graph.size();
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(solve(graph, color, i) == false){
                    return false;
                }
            }
        }

        return true;
    }
};
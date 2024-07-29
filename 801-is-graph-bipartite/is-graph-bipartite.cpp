class Solution {
public:
    int result = true;
    void dfs(int curr, vector<vector<int>>& graph, vector<int> &color){
        for(auto e : graph[curr]){
            if(color[e] == 0){
                color[e] = color[curr] == 1 ? 2 : 1;
                dfs(e, graph, color);
            }
            else if(color[e] == color[curr]){
                result = false;
            }
        }
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                color[i] = 1;
                dfs(i, graph, color);
            }
        }


        return result;
    }
};
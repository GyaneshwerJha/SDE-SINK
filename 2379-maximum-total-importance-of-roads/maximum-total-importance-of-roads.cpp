class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int V = roads.size();
        vector<int> adj[n];
        for(int i = 0; i < V; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<pair<int, int>> inDegree;
        for(int i = 0; i < n; i++){
            int degree = adj[i].size();
            inDegree.push_back({degree, i});
        }
        sort(inDegree.begin(), inDegree.end());

        // for(int i = 0; i < n; i++){
        //     auto it = inDegree[i];
        //     cout<<it.first<<" :"<<it.second<<endl;
        // }

        vector<int> importance(n);
        int i = 1;
        for(auto it : inDegree){
            importance[it.second] = i;
            i++;
        }

        // for(int i = 0; i < n; i++){
        //     cout<<i<<" :"<<importance[i]<<endl;
        // }

        long long maxImportance = 0;
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                maxImportance += (importance[i] + importance[it]);
            }
        }

        

        return maxImportance / 2;
    }
};
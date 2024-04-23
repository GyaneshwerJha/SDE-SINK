// class Solution {
// public:

//     void bfs(int node, vector<vector<int>> &adj, unordered_map<int, int> &mp){
//         vector<int> visited(adj.size(), 0);
//         visited[node] = 1;

//         queue<int> q;
//         q.push(node);
//         int h = 0;
//         while(!q.empty()){
//             int size = q.size();
//             for(int i = 0; i < size; i++){
//                 int curr = q.front();
//                 q.pop();

//                 for(auto it : adj[curr]){
//                     if(!visited[it]){
//                         visited[it] = 1;
//                         q.push(it);
//                     }
//                 }
//             }
//             h++;
//         }

//         mp[node] = h;
//     }

//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         vector<int> degree(n);
//         for(auto &edge : edges){
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//             degree[u]++;
//             degree[v]++;
//         }
        
//         int maxi = *max_element(degree.begin(), degree.end());
//         vector<int> a;
//         if(maxi == 1){
//             for(int i = 0; i < n; i++){
//                 a.push_back(i);
//             }
//             return a;
//         } 
//         queue<int> q;
//         for(int i = 0; i < n; i++){
//             if(degree[i] > 1){
//                 q.push(i);
//             }
//         }
//         unordered_map<int, int> mp;
//         while(!q.empty()){
//             int i = q.front();
//             q.pop();
//             bfs(i, adj, mp);
//         }

//         int min_val = INT_MAX;
//         for (const auto& pair : mp) {
//             if (pair.second < min_val) {
//                 min_val = pair.second;
//             }
//         }

//         vector<int> ans;
//         for(const auto& pair : mp){
//             if(pair.second == min_val){
//                 ans.push_back(pair.first);
//             }
//         }

//         if(ans.size() == 0){
//             ans.push_back(0);
//         }

//         return ans;

//     }
// };


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int>res;
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;//updating how many edges each node has
            degrees[edges[i][0]]++;
        }
        queue<int>queue;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1)//adding all the leave nodes
                queue.push(i);
        }
        while(!queue.empty())
        {
            res.clear();// clear vector before we start traversing level by level.
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                int cur=queue.front();
                queue.pop();
                res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
                for(auto &neighbor:adj[cur])
                {
                    degrees[neighbor]--;//removing current leave nodes
                    if(degrees[neighbor]==1)//adding current leave nodes
                        queue.push(neighbor);
                }
            }
        }
        return res;
    }
};
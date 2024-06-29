class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        int size = edges.size();

        for(int i = 0; i < size; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int>inDegree(n);
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }

        vector<vector<int>> res(n);
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                res[i] = {};
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int it : adj[node]){
                
                set<int> st;
                for(auto it : res[node]){
                    st.insert(it);
                }

                for(auto it : res[it]){
                    st.insert(it);
                }
                st.insert(node);
                vector<int> v;
                for(auto it : st){
                    v.push_back(it);
                }
                res[it] = v;
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return res;

    }
};
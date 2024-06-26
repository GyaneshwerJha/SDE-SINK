class Solution {
public:
vector<int> topoSort(int V, vector<vector<int>>& adj) 
	{  
	   vector<int> inDegree(V, 0);
	   queue<int> q;
	   for(int i = 0; i < V; i++){
	       for(auto it : adj[i]){
	           inDegree[it]++;
	       }
	   }
	   vector<int> res;
	   for(int i = 0; i < V; i++){
	       if(inDegree[i] == 0){
	           q.push(i);
	       }
	   }
	   
	   while(!q.empty()){
	       auto node = q.front();
	       q.pop();
	       res.push_back(node);
	       
	       for(auto it : adj[node]){
	           inDegree[it]--;
	           if(inDegree[it] == 0){
	               q.push(it);
	           }
	       }
	   }
	   
	   return res;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> num = topoSort(numCourses, adj);
        if(num.size() != numCourses) return false;
        return true;
    }
};
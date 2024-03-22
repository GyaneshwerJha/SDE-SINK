class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < len; i++){
            mp[tasks[i]]++;
        }

        priority_queue<int> pq;
        for(auto it : mp){
            pq.push(it.second);
        }

        int minInterval = 0;
        
        while(!pq.empty()){
            vector<int> temp;
            for(int i = 1; i <= n + 1; i++){
                if(!pq.empty()){
                    int t = pq.top();
                    pq.pop();
                    t--;
                    temp.push_back(t);
                }    
            }    
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] > 0){
                  pq.push(temp[i]);
                }
            }
            if(pq.empty()){
                minInterval += temp.size();
            }
            else{
                minInterval += n + 1;
            }

        }
        return minInterval;
    }
};
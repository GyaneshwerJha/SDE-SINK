class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<pair<int, int>> trackPos;
        for(int i = 0; i < n; i++){
            trackPos.push_back({positions[i], i});
        }

        sort(begin(trackPos), end(trackPos));

        // for(int i = 0; i < n; i++){
        //     cout<<trackPos[i].first<<" "<<trackPos[i].second<<endl;
        // }

        vector<int> sortedPos;
        for(int i = 0; i < n; i++){
            sortedPos.push_back(trackPos[i].second);
            cout<<trackPos[i].second;
        }

        stack<int> st;
        
        for(int i = 0; i < n; i++){
            int idx = sortedPos[i];
            if(directions[sortedPos[i]] == 'R'){
                st.push(sortedPos[i]);
            }
            else{
                while(!st.empty() && healths[idx] > 0){
                    int top_idx = st.top();
                    st.pop();
                    
                    if(healths[top_idx] > healths[idx]){
                        healths[top_idx] -= 1;
                        healths[idx] = 0;
                        st.push(top_idx);
                    }
                    else if(healths[top_idx] < healths[idx]){
                        healths[top_idx] = 0;
                        healths[idx] -= 1;
                    }
                    else{
                        healths[top_idx] = 0;
                        healths[idx] = 0;
                    }
                }
            }
        }
        sortedPos.clear();
        // cout<<sortedPos.size();
        cout<<endl;
        for(int i = 0; i < n; i++){
            cout<<healths[i]<<" ";
        }

        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                sortedPos.push_back(healths[i]);
            }
        }


        return sortedPos;
    }
};
class Solution {
public:
    static bool sortByFreq(const pair<char, int> &a, const pair<char, int> &b){
        return a.second > b.second;
    }

    int minimumPushes(string word) {
        int len = word.size();
        unordered_map<char, int> mp;

        for(int i = 0; i < len; i++){
            mp[word[i]]++;
        }

        vector<pair<char, int>> v;
        for(auto it : mp){
            v.push_back(it);
        }

        sort(v.begin(), v.end(), sortByFreq);
        
        for(auto it : v){
            cout<<it.first<<" -> "<<it.second<<endl;
        }

        int cnt = 1;
        int mini = 0;
        for(auto it : v){
            int ele = it.first;
            int freq = it.second;
            if(cnt <= 8){
                mini += freq;
                cout<<"count"<<cnt<<" ";
                cout<<mini<<endl;
            }
            else if(cnt > 8 && cnt <= 16){
                mini += 2 * freq;
                cout<<"count"<<cnt<<" ";
                cout<<mini<<endl;
            }
            else if(cnt > 16 && cnt <= 24){
                mini += 3 * freq;
                cout<<"count"<<cnt<<" ";
                cout<<mini<<endl;
            }
            else{
                mini += 4 * freq;
                cout<<"count"<<cnt<<" ";
                cout<<mini<<endl;
            }
            cnt++;
            // cout<<cnt<<endl;
        }
        
        return mini;
    }
};
class Solution {
public:
    bool check(int mid, vector<int> &c){
        int cnt = 0;
        for(int i = 0; i < c.size(); i++){
            if(c[i] >= mid){
                cnt++;
            }
        }

        // cout<<cnt<<endl;
        return cnt >= mid;
    }

    int hIndex(vector<int>& c) {
        int n = c.size();
        int low = 0, high = n;
        int ans = INT_MIN;
        while(low <= high){
            int mid = low + (high - low) / 2;
            cout<<mid<<endl;
            if(check(mid, c)){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    bool isFine(vector<int> &position, int m, int mid){
        int n = position.size();
        int prev = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                prev = i;
                m--;
            }
            else{
                if(position[i] - position[prev] >= mid){
                    prev = i;
                    m--;
                    if(m == 0) return true;
                }
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());

        int low = 1;
        int high = position[n - 1] - position[0];
        int maxi = INT_MIN;

        while(low <= high){
            int mid = (low + high) / 2;
            if(isFine(position, m, mid)){
                maxi = max(maxi, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return maxi;
    }
};
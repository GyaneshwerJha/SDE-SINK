class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr1(n, 1);
        vector<int> arr2(n, 1);

        // left to right pass
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                arr1[i] = arr1[i - 1] + 1;
            }
        }

        // right to left pass
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                arr2[i] = arr2[i + 1] + 1;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += max(arr1[i], arr2[i]);
        }

        return cnt;
    }
};
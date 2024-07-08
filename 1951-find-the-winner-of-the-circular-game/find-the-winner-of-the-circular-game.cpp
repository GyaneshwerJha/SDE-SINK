class Solution {
public:
    int findTheWinner(int n, int k) {
        k = k - 1;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = i + 1;
        }



        while(arr.size() > 1){
            int index = (index + k) % arr.size();
            arr.erase(arr.begin() + index);
            if(arr.size() == 1){
                return arr[0];
            }
        }
        return arr[0];
    }
};
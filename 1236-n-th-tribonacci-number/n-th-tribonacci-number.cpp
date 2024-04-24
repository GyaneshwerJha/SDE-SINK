class Solution {
public:
    int tribonacci(int n) {
        vector<long long int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(1);

        for(int i = 0; i < n; i++){
            long long int a = v[i] + v[i + 1] + v[i + 2];
            v.push_back(a);
        }

        // for(int i = 0; i < v.size(); i++){
        //     cout<<v[i]<<" ";
        // }

        return v[n];
    }
};
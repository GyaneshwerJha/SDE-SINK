class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxL(n);
        vector<int> maxR(n);

        maxL[0] = height[0];
        maxR[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++){
            maxL[i] = max(maxL[i-1], height[i]);
        }

        stack<int> st;
        st.push(height[n - 1]);

        int maxi;
        for(int i = n - 2; i >= 0; i--){
            maxi = max(height[i], st.top());
            st.push(maxi);
        }

        for(int i = 0; i < n - 1; i++){
            maxR[i] = st.top();
            st.pop();
        }

        // for(int i = 0; i < n; i++){
        //     cout<<maxL[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++){
        //     cout<<maxR[i]<<" ";
        // }

        int area = 0;
        for(int i = 0; i < n; i++){
            area += min(maxL[i], maxR[i]) - height[i];
        }
        return area;
    }
};
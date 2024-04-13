class Solution {
public:
vector<int> nsr(vector<int> &heights){
        int n = heights.size();
        int pseudoIndex = n;
        vector<int> v;
        stack<pair<int, int>> st;
        for(int i = n - 1; i >= 0; i--){
            if(st.size() == 0){
                v.push_back(pseudoIndex);
            }
            else if(st.top().first < heights[i]){
                v.push_back(st.top().second);
            }
            else{
                while(st.size() != 0 && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    v.push_back(pseudoIndex);
                }
                else{
                    v.push_back(st.top().second);
                }
            }

            st.push({heights[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
    }

    vector<int> nsl(vector<int> &heights){
        int n = heights.size();
        int psuedoIndex = -1;
        stack<pair<int, int>> st;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(st.size() == 0){
                v.push_back(psuedoIndex);
            }
            else if(st.top().first < heights[i]){
                v.push_back(st.top().second);
            }
            else{
                while(st.size() != 0 && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    v.push_back(psuedoIndex);
                }
                else{
                    v.push_back(st.top().second);
                }
            }

            st.push({heights[i], i});
        }

        return v;
    }
    int MAH(vector<int>& heights) {
        int n = heights.size();
        // find NSR if no smaller element then index + 1 is the smaller index
        vector<int> NSR = nsr(heights);
        cout<<NSR[0];

        // find NSL if no smaller element then -1 is the smaller indexx
        vector<int> NSL = nsl(heights);
        cout<<NSL[0];

        // width arr[] = NSR - NSL
        vector<int> width;
        for(int i = 0; i < n; i++){
            width.push_back((NSR[i] - NSL[i]) - 1);
        }


        // area array[] = arr[i] * width[i]
        vector<int> area;
        for(int i = 0; i < n; i++){
            area.push_back(heights[i] * width[i]);
        }


        // find the max element from area array
        int maxArea = *max_element(area.begin(), area.end());

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m, 0);

        for(int col = 0; col < m; col++){
            v[col] = matrix[0][col] - '0';  
        }

        int mx = MAH(v);

        for(int row = 1; row < n; row++){
            for(int col = 0; col < m; col++){
                v[col] = matrix[row][col] == '1' ? v[col] + 1 : 0;
            }
            int curr = MAH(v);
            mx = max(mx, curr);
        }

        return mx;
    }
};
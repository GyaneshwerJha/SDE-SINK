class Solution {
public:

int removeAndCount(string &str, char first, char second, int points) {
            stack<char> st;
            int sum = 0;
            for (char c : str) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    sum += points;
                } else {
                    st.push(c);
                }
            }
            // Reconstruct the remaining string
            string remaining = "";
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            str = remaining;
            return sum;
        }
    int maximumGain(string s, int x, int y) {
        int sum = 0;
        bool isY = y > x;
        
        // Function to remove and count specific substrings
        

        if (isY) {
            sum += removeAndCount(s, 'b', 'a', y);
            sum += removeAndCount(s, 'a', 'b', x);
        } else {
            sum += removeAndCount(s, 'a', 'b', x);
            sum += removeAndCount(s, 'b', 'a', y);
        }
        
        return sum;
    }
};

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;

        string ans = "";
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i] == '('){
                    ans += '(';
                    st.push(s[i]);
                }
                else{
                    string temp = "";
                    temp += ')';
                    st.pop();

                    if(!st.empty()){
                        ans += temp;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<char> st;
        
        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        int j = n - 1;
        while(s[j] == ' '){
            j--;
        }

        while(i <= j){
            if(isalnum(s[i])){
                st.push(s[i]);
            }
            else{
                if(s[i] == ' ' && s[i - 1] != ' '){
                    st.push(' ');
                }
            }
            i++;
        }

        string ans = "";
        string temp = "";

        while(!st.empty()){
            char c = st.top();
            if(isalnum(c)){
                temp += c;
            }
            else{
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += ' ';
                temp = "";
            }
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};
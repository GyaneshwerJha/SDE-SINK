class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        stack<string> st;

        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        int j = n - 1;
        while(s[j] == ' '){
            j--;
        }

        string temp = "";
        while(i <= j){
            if(s[i] == ' '){
                st.push(temp + " ");
                temp = "";
                while(s[i] == ' '){
                    i++;
                }
            }
            else{
                temp += s[i];
                i++;
            }
        }
        st.push(temp + " ");
        string ans = "";
        while(!st.empty()){
           ans += st.top();
           st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
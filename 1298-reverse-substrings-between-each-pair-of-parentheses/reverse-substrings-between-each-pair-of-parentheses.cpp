class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> s1;
        string ans = "";

        for(int i = 0; i < n; i++){
            if(s[i] != ')'){
                s1.push(s[i]);
            }
            else{
                while(!s1.empty() && s1.top() != '('){
                    ans += s1.top();
                    s1.pop();
                }
                s1.pop();
                for(int j = 0; j < ans.length(); j++){
                    s1.push(ans[j]);
                }
                ans = "";
            }
        }

        if(s1.empty()){
            return ans;
        }

        string ans2 = "";
        while(!s1.empty()){
            ans2 += s1.top();
            s1.pop();
        }
        reverse(ans2.begin(), ans2.end());
        return ans + ans2;
    }
};
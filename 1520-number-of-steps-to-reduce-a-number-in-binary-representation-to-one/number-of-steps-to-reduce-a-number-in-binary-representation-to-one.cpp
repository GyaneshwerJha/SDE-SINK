class Solution {
public:

    string divideByTwo(string s){
        if(s.length() <= 1){
            return "0";
        }
        return s.substr(0, s.length() - 1);
    }

    string addOne(string s){
        int n = s.length();
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1'){
                s[i] = '0';
            }
            else{
                s[i] = '1';
                carry = 0;
                break;
            }
        }
        if(carry){
           s =  '1' + s;
        }

        return s;
    }

    int numSteps(string s) {
        int n = s.length();
        int nStep = 0;
        while(s != "1"){
            if(s[s.length() - 1] == '1'){
                s = addOne(s);
                // cout<<"adding 1 "<<s<<endl;
            }
            else{
                s = divideByTwo(s);
                // cout<<"dividing 2 "<<s<<endl;
            }
            nStep++;
        }

        return nStep;
    }
};
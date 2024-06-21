class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string real1 = "";
        string imag1 = "";

        string real2 = "";
        string imag2 = "";
        int i = 0;

        bool foundPlus = false;
        while(i < num1.size() - 1){
            if(num1[i] == '+'){
                foundPlus = true;
                i++;
                continue;
            }
            if(foundPlus == false){
                real1 += num1[i];
            }
            else{
                imag1 += num1[i];
            }
            i++;
        }

        i = 0;
        foundPlus = false;
        while(i < num2.size() - 1){
            if(num2[i] == '+'){
                foundPlus = true;
                i++;
                continue;
            }

            if(foundPlus == false){
                real2 += num2[i];
            }
            else{
                imag2 += num2[i];
            }
            i++;
        }

        // (1 + -1i)(1 + -1i)

        int resReal1 = stoi(real1) * stoi(real2);
        int i1 = stoi(real1) * stoi(imag2);
        int i2 = stoi(imag1) * stoi(real2);
        cout<<i1<<" "<<i2;
        int imag = i1 + i2;
        int resReal2 = stoi(imag1) * stoi(imag2);

        int resReal = resReal1 - resReal2;
        string st = "";
        st += to_string(resReal);
        st += '+';
        st += to_string(imag);
        st += 'i';
        
        return st;
    }   
};
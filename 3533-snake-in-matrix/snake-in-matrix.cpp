class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int c_size = commands.size();
        int i = 0, j = 0;
        for(int k = 0; k < c_size; k++){
            if(commands[k] == "RIGHT"){
                j = j + 1;
            }
            else if(commands[k] == "DOWN"){
                i += 1;
            }
            else if(commands[k] == "LEFT"){
                j -= 1;
            }
            else{
                i -= 1;
            }
        }

        return (i * n) + j;
    }
};
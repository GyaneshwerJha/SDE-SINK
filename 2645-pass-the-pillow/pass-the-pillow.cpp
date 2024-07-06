class Solution {
public:
    int passThePillow(int n, int time) {
      int nPos = time / (n - 1);
      int remain = time % (n - 1);

      if(nPos % 2 == 0){
        return remain + 1;
      }
      else{
        return n - remain;
      }
    }
};
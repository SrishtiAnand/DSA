class Solution {
public:
    bool canWinNim(int n) {
        int stoneleft =0;
        if(n<=3){
            return true;
        }else{
           return n % 4 != 0;
        }
    }
};
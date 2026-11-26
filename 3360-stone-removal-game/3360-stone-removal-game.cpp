class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        while(n){
            if(n<x){
                return false;
            }
            n = n-x;
            int b = n;
            x--;
            if(b<x){
                return true;
            }else{
                n = n-x;
                x--;
            }
        }
        return false;
    }
};
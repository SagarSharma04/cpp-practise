class Solution {
public:
    bool isHappy(int n) {
        if(n>1 && n<=9 && n!=7){
            return false;
        }
        if(n==1){
            return true;
        }
        int sum=0;
        int dig = n;
        while(dig>0){
            int x = dig%10;
            sum += x*x;
            dig /= 10;
        }
        n = sum;
        return isHappy(n);
    }
};
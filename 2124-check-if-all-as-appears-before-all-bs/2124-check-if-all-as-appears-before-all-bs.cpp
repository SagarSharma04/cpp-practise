class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int ind=0;
        if(n==1){
            return true;
        }
        bool flag = true;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                flag = false;
                ind = i;
                break;
            }
        }
        if(flag){
            return true;
        }
        for(int j = ind;j<n;j++){
            if(s[j]=='a'){
                return false;
            }
        }
        return true;
    }
};
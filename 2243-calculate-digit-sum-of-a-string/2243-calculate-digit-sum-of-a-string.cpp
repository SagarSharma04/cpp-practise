class Solution {
public:
    string digitSum(string s, int k) {
        if(s.length()<=k){
            return s;
        }
        int i=0;
        int n = s.length();
        string final = "";
        while(i<n){
            string ans="";
            int cnt=0;
            int sum=0;
            while(i<n && cnt < k){
                sum += s[i] - '0';
                i++;
                cnt++;
            }
            final += to_string(sum);
            
        }
        return digitSum(final,k);
        
    }
};
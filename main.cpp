#include <iostream>
#include<string>
using namespace std;

// int main() {
//     cout << "My first GitHub project!" << endl;
//     cout<<"Let's Start Bro"<<endl;
//     return 0;
// }

// int count(string s){
//     int n = s.length();
    
//     int cnt=0;
//     while(char ch!=" "){

//     }
//     return cnt;
// }
bool alpha1(char ch){
    if(ch>='a' && ch <= 'z'){
        return true;
    }
    return false;
}

int main(){
    string s  ="Hello World";
    int n = s.length();
    int cnt=0;
    int i = n-1;
    while(s[i] != ' '){
        cnt++;
        i--;
    }
    cout<<cnt;
    return 0;
}



#include<iostream>
using namespace std;

bool isDivisible(string s) {
    // a number to be divisible by 60 has to be divisible by both 3 and 20
    // a number is divisible by 3 id sum of its digit is divisible by 3
    // a number is divisible by 20 if and only if it contains at least one 0 and an even digit
    // these statement should satisfy
    int a = 0;
    int n = s.size();
    int flag1 = 0, flag2 = 0; 
    for(int i = 0; i < n; ++i) {
        a += (s[i] - '0');
        if(s[i] - '0' == 0) {
            // to get the atleast one zero
            flag2 += 1;
        }
        if((s[i] - '0') % 2 == 0 && (s[i] - '0') != 0){
            // to check for at least an even
            flag1 += 1;
        }
    }
    if(a % 3 == 0) {
        if(flag2 > 1) {
            return true;
        } else{
            if(flag1 && flag2) {
                return true;
            }
        }
    }
    return false;

}

int main() {
    int t;
    cin>>t;
    while(t) {
        string s;
        cin>>s;
        if(isDivisible(s)) {
            cout<<"red";
        }else {
            cout<<"cyan";
        }
        cout<<endl;
        --t;
    }
}
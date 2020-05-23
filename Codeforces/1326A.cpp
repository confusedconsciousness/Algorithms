//https://codeforces.com/problemset/problem/1326/A
#include<iostream>
#include<math.h>
using namespace std;

typedef long long int ll;
int main() {
    ll t;
    cin>>t;
    while(t) {
        ll n;
        cin>>n;
        int f = 0;

        if(n == 1) {
            cout<<-1;
            f = 1;
        }
        // n digit number
        string s = "";
        s.push_back('2');
        for(ll i = 1; i < n; ++i) {
            s.push_back('3');
        }
        if(f == 0) {
            for(int i = 0; i < n; ++i) {
                cout<<(s[i] - '0');
            }
        }
        cout<<endl;     
        --t;
    }
}
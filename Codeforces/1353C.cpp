//https://codeforces.com/problemset/problem/1353/C
#include<iostream>
#include<math.h>
using namespace std;
typedef long long int ll;

ll tutorial(ll n) {
    n = (n - 1) / 2;
    return 8 * (n) * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll n;
        cin>>n;
        //cout<<tutorial(n)<<endl;
        ll results = 0;
        while(n > 0) {
            // results = moves * elements
            results += ((ll) floor(n / 2)) * (4 * (n - 1));
            n = n - 2;
        }
        cout<<results<<endl;
        --t;
    }
}
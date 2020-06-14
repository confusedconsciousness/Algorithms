//https://codeforces.com/problemset/problem/1362/C
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
typedef long long ll;

int set_bit(ll n) {
    int c = 0;
    for(int i = 0; i <= 18; ++i) {
        if(n & 1L << i) {
            ++c;
        }
    }
    return c;
}

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll n;
        cin>>n;
        ll sum = 0;

        for(int i = 0; i <= 64; ++i) {
            sum += n / (ll) pow(2, i);
        }
        cout<<sum<<endl;
        --t;
    }
    return 0;
}
//https://codeforces.com/problemset/problem/1277/A
#include<iostream>
#include<math.h>
#include<string>
typedef long long int ll;
using namespace std;

ll F(int n) {
    if(n < 10) {
        return n;
    }
    if(n == 10) {
        return 9;
    }
    ll a = 10;
    ll res = 0; // count
    while(a < n) {
        res += 9;
        a *= 10;
    }
    a /= 10; // revert back and now look at it manually 
    // first make the a to 1111...n times
    ll digits = to_string(a).size();
    for(ll i = 0; i < digits - 1; ++i) {
        a += pow(10, i);
    }
    int b = a;
    while(a <= n) {
        ++res;
        a += b;
    }
    return res;
}


ll tutorial(int n) {
    ll res = 0;
    ll b = 0;
    for(int i = 0; i <= 9; ++i) {
        b = b * 10 + 1; // this is important, generates 1, 11, 111, 1111, ... till end
        for(int j = 1; j <= 9; ++j) {
            if(b * j <= n) { // we are just checking whether it is multiple of it or not
                ++res;
            }
        }
    }
    return res;
}

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll n;
        cin>>n;
        cout<<tutorial(n)<<endl;
        --t;
    }
}
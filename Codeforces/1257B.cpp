//https://codeforces.com/problemset/problem/1257/B
#include<iostream>
#include<unordered_set>
typedef long long int ll;
using namespace std;

int F(ll x, ll y, unordered_set<ll> &U) {
    if(U.find(x) != U.end()) {
        return 0;
    } else {
        U.insert(x);
    }
    
    if(x >= y) {
        return 1;
    } else {
        if(x % 2 == 0) {
            return F(x * 1.5, y, U);
        } else {
            return F(x - 1, y, U);
        }
    }
}

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll x, y;
        cin>>x>>y;
        unordered_set<ll> U;
        int res = F(x, y, U);
        if(res == 0) {
            cout<<"NO";
        } else {
            cout<<"YES";
        }
        cout<<endl;
        --t;
    }
}
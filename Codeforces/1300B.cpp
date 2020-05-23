//https://codeforces.com/problemset/problem/1300/B
#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll n;
        cin>>n;
        vector<ll> a(2 * n, 0);
        for(ll i = 0; i < 2 * n; ++i) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        ll ma, mb;
        n = 2 * n; // original size
        ma = (n - 1) / 2;
        mb = n / 2;
        cout<<(a[mb] - a[ma])<<endl;
        --t;
    }
}
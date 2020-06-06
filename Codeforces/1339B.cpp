//https://codeforces.com/problemset/problem/1339/B
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll n;
        cin>>n;
        vector<ll> A(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        vector<ll> res(n, 0);
        int l = (n - 1) / 2, idx = 0;
        int r = l + 1;
       
        sort(A.begin(), A.end());
        while(l > -1 && r < n) {
            res[idx++] = A[l--];
            res[idx++] = A[r++];
        }
        if(r < n) {
            // in case of odd
            res[idx] = A[r];
        } 
        if(l > -1) {
            res[idx] = A[l];
        }

        for(int i = 0; i < n; ++i) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        --t;
    }
    
}
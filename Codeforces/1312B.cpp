//https://codeforces.com/problemset/problem/1312/B
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t) {
        int n;
        cin>>n;
        vector<int> A(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        sort(A.begin(), A.end(), greater<int>());
        for(int i = 0; i < n; ++i) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        --t;
    }
}
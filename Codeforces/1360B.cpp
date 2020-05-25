//https://codeforces.com/problemset/problem/1360/B
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
        sort(A.begin(), A.end());
        int res = INT_MAX;
        for(int i = 1; i < n; ++i) {
            res = min(res, A[i] - A[i - 1]);
        }
        cout<<res<<endl;
        --t;
    }
}
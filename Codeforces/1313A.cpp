//https://codeforces.com/problemset/problem/1313/A
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t) {
        vector<int> A(3, 0);
        int res = 0;
        for(int i = 0; i < 3; ++i) {
            cin>>A[i];
        }
        sort(A.begin(), A.end(), greater<int>());
        // check for single product (set) only
        for(int i = 0; i < 3; ++i) {
            if(A[i] > 0) {
                ++res;
                A[i]--;
            }
        }
        // set of 2
        for(int i = 0; i < 3; ++i) {
            for(int j = i + 1; j < 3; ++j) {
                if(A[i] > 0 && A[j] > 0) {
                    ++res;
                    --A[i];
                    --A[j];
                }
            }
        }
        // set of 3
        if(A[0] > 0 && A[1] > 0 && A[2] > 0) {
            ++res;
        }
        cout<<res<<endl;
        --t;
    }
}
//https://codeforces.com/problemset/problem/1360/C
#include<iostream>
#include<vector>
#include<math.h>
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
        //sort(A.begin(), A.end());
        int f = 0;
        vector<int> odd, even;

        int odd_cnt = 0;
        int even_cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(A[i] % 2 == 0) {
                even.push_back(A[i]);
                ++even_cnt;
            } else {
                odd.push_back(A[i]);
                ++odd_cnt;
            }
        }

        // if odd_cnt and even_cnt are even then our result is YES
        if(even_cnt % 2 == 0 && odd_cnt % 2 == 0) {
            cout<<"YES";
        } else {
            // find that one pair of odd and even
            for(int i = 0; i < odd.size(); ++i) {
                for(int j = 0; j < even.size(); ++j) {
                    if(abs(odd[i] - even[j]) == 1){
                        f = 1;
                        break;
                    }
                }
                if(f == 1) {
                    break;
                }
            }
            if(f == 1) {
                cout<<"YES";
            }else{
                cout<<"NO";
            }

        }
        cout<<endl;
        --t;
    }
}
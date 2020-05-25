//https://codeforces.com/problemset/problem/1360/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t) {
        int a, b;
        cin>>a>>b;
        int c = 2 * min(a, b);
        int d = max(c, max(a, b));
        cout<<d * d<<endl;
        --t;
    }
}
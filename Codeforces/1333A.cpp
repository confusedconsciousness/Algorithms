//https://codeforces.com/problemset/problem/1333/A
#include<iostream>
using namespace std;

void construct(int n, int m) {
    cout<<"W";
    // rest should be black
    for(int j = 1; j < m; ++j) {
        cout<<"B";
    }
    cout<<endl;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout<<"B";
        }
        cout<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t) {
        int n, m; // rows and columns
        cin>>n>>m; 
        construct(n, m);
        --t;
    }
}
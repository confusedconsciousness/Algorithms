//https://codeforces.com/problemset/problem/1326/B
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int f = a[0]; // contains the running maximum
    cout<<f<<" ";
    for(int i = 1; i < n; ++i) {
        a[i] = a[i] + f;
        cout<<a[i]<<" ";
        f = max(f, a[i]);
    }

}
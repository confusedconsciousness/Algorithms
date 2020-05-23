//https://codeforces.com/problemset/problem/1321/A
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n, 0), b(n, 0);
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin>>b[i];
    }

    int x = 0, y = 0; // non overlapping
    for(int i = 0; i < n; ++i) {
        if(a[i] == 1 && b[i] == 0) {
            ++x;
        } else if(b[i] == 1 && a[i] == 0) {
            ++y;
        }
    }
    if(x == 0) {
        cout<<-1<<endl;
    } else {
        cout<<((y / x) + 1)<<endl;
    }
}
//https://codeforces.com/problemset/problem/1365/B
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t) {
        int n;
        cin>>n;
        vector<int> a(n, 0), b(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin>>b[i];
        }

        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; ++i) {
            if(b[i] == 0) {
                ++t1;
            } else {
                ++t2;
            }
        }
        int f = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(a[i] > a[i + 1]) {
                f = 1;
                break;
            }
        }
        // my hypothesis as long as we have atleast an element of each type it is possible
        if(f == 0) {
            cout<<"YES";
        } else {
            if(t1 > 0 && t2 > 0) {
                cout<<"YES";
            } else {
                cout<<"NO";
            }
        }
        cout<<endl;
        --t;
    }
}
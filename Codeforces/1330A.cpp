//https://codeforces.com/problemset/problem/1330/A
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t) {
        int n, x;
        cin>>n>>x;
        vector<int> b(101, 0);
        vector<int> a(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
            b[a[i]] = 1; // present
        }
        int rem = 0;
        int res = 0;

        for(int i = 1; i <= 100; ++i) {
            if(x > 0 && b[i] == 0) {
                // here we have to decrement the x
                --x;
                res = max(res, i);
            } else if( x >= 0 && b[i] == 1) {
                // here we need to take that number into account
                res = max(res, i);
            } else {
                break;
            }
        }
        if(x > 0) {
            // after all we still have some events left
            res += x;
        }
        cout<<res<<endl;
        --t;
    }
}
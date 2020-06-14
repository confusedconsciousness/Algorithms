//https://codeforces.com/problemset/problem/1270/B
#include<iostream>
#include<vector>
typedef long long int ll;
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t) {
        int n;
        cin>>n;
        vector<ll> a(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        // if some interesting subarray exists, then there will also exist a subarray of length 2
        int l = -1, r = -1, f = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(abs(a[i] - a[i + 1]) >= 2) {
                l = i;
                r = i + 1;
                f = 1;
                break;
            }
        }
        if(f == 1) {
            cout<<"YES"<<endl<<(l + 1)<<" "<<(r + 1)<<endl;
        } else {
            cout<<"NO"<<endl;
        }

        --t;
    }
}
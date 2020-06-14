//https://codeforces.com/problemset/problem/1365/C
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int tutorial(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<int> pos(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    map<int, int> offset;
    for(int i = 0; i < n; ++i) {
        int cur = pos[b[i]] - i;
        if(cur < 0) {
            cur += n;
        }
        offset[cur]++;
    }
    int res = 0;
    map<int, int> ::iterator iter;
    for(iter = offset.begin(); iter != offset.end(); ++iter) {
        res = max(res, iter->second);
    }
    return res;
}


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
    cout<<tutorial(a, b)<<endl;
    /*
    int s, e = n;
    int m, res = 0;
    for(int i = 0; i < n; ++i) {
        e = 0; // total n steps we need to cover
        m = 0; // will hold the total matches for this iteration
        while(e < n) {
            if(a[(i + e) % n] == b[e]) {
                ++m;
            }
            ++e;
        }
        res = max(res, m);
    }
    cout<<res<<endl;
    */
    return 0;
}
//https://codeforces.com/problemset/problem/1316/B
#include<iostream>
#include<string>
#include<vector>
//#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;

pair<string, int> string_modification(string s) {
    pair<string, int> P;
    int n = s.size();
    string ax = s;
    sort(ax.begin(), ax.end());
    if(ax == s) {
        P.first = s;
        P.second = 1;
        return P;
    }
    // otherwise we'll find the smallest characters in the string
    char c = 'z'; // considering all the lowercase for the moment
    vector<int> pos; // will contain the indices (possible ks)
    for(int i = 0; i < n; ++i) {
        if(c > s[i]) {
            c = s[i];
        }
    }
    // now search for the positions
    for(int i = 0; i < n; ++i) {
        if(c == s[i]) {
            pos.push_back(i);
        }
    }
    int k = 1;
    string tmp = s; // lexographically smallest

    for(int i = 0; i < n; ++i) {
        ax = s.substr(i, n);
        // the suffix can be different
        if((i % 2 == 0 && n % 2 == 0) || (i % 2 != 0 && n % 2 != 0)) {
            // i and n have the same parity
            ax += s.substr(0, i);
        } else {
            ax += s.substr(0, i);
            reverse(ax.end() - i, ax.end());
        }
        
        if(tmp.compare(ax) > 0) {
            tmp = ax;
            k = i + 1;
        }
        ax = ""; // reset
    }

    P.first = tmp;
    P.second = k;
    return P;

}

int main() {
    int t;
    cin>>t;
    while(t) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        pair<string, int> P;
        P = string_modification(s);
        cout<<P.first<<endl;
        cout<<P.second<<endl;
        --t;
    }
    
}
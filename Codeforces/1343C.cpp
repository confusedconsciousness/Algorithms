#include<iostream>
#include<vector>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll alternatingSequence(vector<ll> a) {
    int n = a.size();
    int l = 0, r = 0;
    vector<vector<ll> > seq;
    vector<ll> aux;
    while(r < n) {
        if(a[l] * a[r] > 0) {
            aux.push_back(a[r]);
            ++r;
        } else {
            seq.push_back(aux);
            aux.clear();
            l = r;
        }
    }
    if(aux.size() > 0) {
        seq.push_back(aux);
    }
    ll sum = 0;
    /*
    for(int i = 0; i < seq.size(); ++i) {
        for(int j = 0; j < seq[i].size(); ++j) {
            cout<<seq[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i = 0; i < seq.size(); ++i) {
        sort(seq[i].begin(), seq[i].end());
        if(seq[i][0] > 0) {
            sum += seq[i].back();
        } else {
            sum += seq[i].back();
        }
    }
    return sum;
}


ll efficient(vector<ll> a) {
    int n = a.size();
    int l = 0, r = 0;
    ll aux = a[0]; 
    ll sum = 0;
    while(r < n) {
        if(a[l] * a[r] > 0) {
            aux = max(aux, a[r]);
            r++;
        } else {
            sum += aux;
            aux = a[r]; // initialise it again
            l = r;
        }
    }
    sum += aux;
    return sum;
}

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
        cout<<efficient(a)<<endl;
        --t;
    }
}


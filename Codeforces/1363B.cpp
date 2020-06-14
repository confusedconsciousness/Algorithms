//https://codeforces.com/problemset/problem/1363/B
#include<iostream>
#include<string>
#include<vector>
typedef long long int LL;
using namespace std;

int min_requirement(string &s) {
    int n = s.size();
    int num_zeros = 0, num_ones = 0;
    int done_zeros = 0, done_ones = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            ++num_zeros;
        } else {
            ++num_ones;
        }
    }
    int cost = INT_MAX;
    int c1, c2;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            ++done_zeros; 
        } else {
            ++done_ones;
        }
        c1 = done_zeros + (num_ones - done_ones); //  111....
        c2 = done_ones + (num_zeros - done_zeros); // 000....
        cost = min(cost, min(c1, c2));
    }
    return cost;
}

int main() {
    int t;
    cin>>t;
    while(t) {
        string s;
        cin>>s;
        cout<<min_requirement(s)<<endl;
        --t;
    }
    
}
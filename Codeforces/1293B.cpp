//https://codeforces.com/problemset/problem/1293/B
#include<iostream>
#include<math.h>
#include<limits>

using namespace std;

int main() {
    int n; // total opponents
    cin>>n;
    double res = 0;
    for(int i = 1; i <= n; ++i) {
        res += 1 / double(i);
    }
    cout.precision(20);
    cout<<res<<endl;
    return 0;
}
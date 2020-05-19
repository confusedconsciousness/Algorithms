//https://codeforces.com/problemset/problem/1354/A
#include<iostream>
#include<math.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        // let's figure out the base cases
        if(b >= a) {
            cout<<b<<endl;
        } else if(d >= c) {
            cout<<-1<<endl;
        } else{
            double diff = c - d;
            double remaining = a - b;

            ll times = (ll) ceil(remaining / diff);
            ll total_time = (c * times + b);
            cout<<total_time<<endl;
    
        }
        --t;
    }
}
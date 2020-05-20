//https://codeforces.com/problemset/problem/1342/A
#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll x, y; // coordinates
        ll a, b; // dollars
        cin>>x>>y;
        cin>>a>>b;
        ll money = 0;
        if(2 * a < b) {
            // always spend a dollar even to decrement the coordinates simultaneously
            money = (x + y) * a;
        } else {
            // else we'll first bring both the coordinate to one point
            if(x < y) {
                money += (y - x) * a;
                money += x * b;
            } else {
                money += (x - y) * a;
                money += y * b;
            }
        }
        cout<<money<<endl;
        --t;
    }
}
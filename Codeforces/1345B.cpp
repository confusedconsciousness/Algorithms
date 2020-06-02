//https://codeforces.com/problemset/problem/1345/B
#include<iostream>
#include<math.h>
typedef long long ll;
using namespace std;
// *********************************** MY STRATEGY ******************************************
ll cards(ll h) {
    // give cards required for a height h
    return h * (3 * h + 1) / 2;
}

ll bsearch(ll n) {
    // returns the height such that it consumes all n or leaves few
    ll l = 0, r = 81650;
    ll mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(cards(mid) == n) {
            return mid;
        } else if (cards(mid) > n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return mid;
}
// *******************************************************************************************
ll differentStrategy(ll n) {
    ll res = 0;
    while (n > 1) {
        ll h = floor((pow(24 * n + 1, 0.5) - 1) / 6);
        if(n >= cards(h)) {
            n = n - cards(h);
            ++res;
        } else if (cards(h) > n) {
            n = n - cards(h - 1);
            ++res;
        } else {
            break;
        }
    }
    return res;
}

int main() {
    ll t;
    cin>>t;
    while(t) {
        ll n;
        cin>>n; // number of cards
        /*
        int res = 0;
        while(n > 1) {
            //cout<<"here";
            // upper limit of h (when n = 10^9) is 81650
            ll h = bsearch(n);
            //cout<<"h: "<<h<<endl;
            //break;
            if(n == cards(h)) {
                n = n - cards(h);
                ++res;
            } else if(cards(h) > n) {
                n = n - cards(h - 1);
                ++res;
            } else if (n > cards(h)){
                n = n - cards(h);
                ++res;
            } else {
                break;
            }
        }
        cout<<res<<endl;
        */
       cout<<differentStrategy(n)<<endl;
        --t;
    }
}
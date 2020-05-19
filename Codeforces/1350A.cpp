//https://codeforces.com/problemset/problem/1350/A
#include<iostream>
#include<math.h>
typedef long long int ll;
using namespace std;

ll F(int n) {
    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            return i;
        }
    }
    return n;
}

int main(){
    ll t;
    cin>>t;
    while(t) {
        ll n, k;
        cin>>n>>k;
        if(n % 2 == 0) {
            // then its smallest divisor will be 2 and if we add even to even then too it will be even
            n = n + 2 * k;
        }else {
            // find the smallest divisor, of course it won't be even
            // but odd + odd = even
            n += F(n);
            n = n + 2 * (k - 1);
        }
        cout<<n<<endl;
        --t;
    }
}
//https://codeforces.com/problemset/problem/1266/B
#include<iostream>
#include<math.h>
#include<unordered_set>
using namespace std;

typedef long long int ll;

bool tutorial(ll n) {
    // n = 14 * d + t
    // where d is the total dice (d >= 1) and t is the value present on the top (1 <= t <= 6)
    ll d = floor(n / 14);
    ll t = n % 14;
    if(d >= 1 && t >= 1 && t <= 6) {
        return true;
    }
    return false;
}

void my_solution(ll* A, ll n) {
    // A is the array and n is its size
    unordered_set<int> U;
    for(int i = 1; i <= 6; ++i) {
        U.insert(14 + i);
    }
    for(int i = 0; i < n; ++i) {
        int t = A[i] / 14;
        if(A[i] % 14 == 0 || A[i] < 14) {
            cout<<"NO"<<endl;
        }else {
            int number = A[i] - 14 * (t - 1);
            if(U.find(number) != U.end()) {
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}

int main() {
    ll n;
    cin>>n;
    ll A[n];
    for(ll i = 0; i < n; ++i) {
        cin>>A[i];
    }
    bool res;
    for(int i = 0; i < n; ++i) {
       res = tutorial(A[i]);
       if(res == true) {
           cout<<"YES";
       } else {
           cout<<"NO";
       }
       cout<<endl;
    }

}
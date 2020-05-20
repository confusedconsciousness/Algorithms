//https://codeforces.com/problemset/problem/1337/B
#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t) {
        int x, m, n;
        cin>>x>>m>>n;
        // absorption will do more damage, so use it first and then use lightning strike
        while(m) {
            if(x <= 10) {
                break;
            }
            x = floor(x / 2) + 10;
            --m;
        }
        while(n) {
            x = x - 10;
            if(x <= 0) {
                break;
            }
            --n;
        }
        if(x <= 0) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
        --t;
    }
}
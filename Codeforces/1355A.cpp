#include<iostream>
#include<vector>
#include<string>
typedef long long int ll;
using namespace std;

ll maxDigit(string s) {
    ll a = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] - '0' > a) {
            a = s[i] - '0';
        }
    }
    return a;
}

ll minDigit(string s) {
    int a = 9;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] - '0' < a) {
            a = s[i] - '0';
        }
    }
    return a;
}

int main() {
    int t;
    cin>>t;
    while(t) {
        string s;
        ll a1, k;
        cin>>a1>>k;
        ll res = a1;
        while(k > 1) {
            s = to_string(res);
            if(minDigit(s) == 0) {
                break;
            }
            res = res + minDigit(s) * maxDigit(s);
            //cout<<"res: "<<res<<endl;
            --k;
        }
        cout<<res<<endl;
        --t;
    }


}
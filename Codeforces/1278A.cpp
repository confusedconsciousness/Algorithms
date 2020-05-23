//https://codeforces.com/problemset/problem/1278/A
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool match(vector<int> a, vector<int> b) {
    // check whether the strings are anagram or not?
    for(int i = 0; i < 256; ++i) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while(t) {
        string p; // original string
        cin>>p;
        string h;
        cin>>h; // hashed version
        int n = h.size();
        int l = 0, r = p.size() - 1; // pointers

        vector<int> a(256, 0), b(256, 0);
        // initialise the a and b
        for(int i = 0; i < p.size(); ++i) {
            a[p[i] - 'a']++;
            b[h[i] - 'a']++;
        }
        int flag = 0;
        while (r < n) {
            // we'll check whether the condition is satisfied
            if(match(a, b)) {
                cout<<"YES"<<endl;
                flag = 1;
                break;
            } else {
                b[h[l] - 'a']--; // remove that character
                ++l; // increment l
                ++r; // increment r
                b[h[r] - 'a']++; // include that character
            }
        }
        if(flag == 0) {
            cout<<"NO"<<endl;
        }
        --t;
    }
}
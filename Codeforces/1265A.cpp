//https://codeforces.com/problemset/problem/1265/A
#include<iostream>
#include<string>
using namespace std;


bool possible(string s) {
    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == s[i + 1] && s[i] != '?') {
            return false;
        }
    }
    return true;
}


string parse(string &s) {
    int n = s.size();
    // sliding window approach
    int l = 0, r = 0;
    // base case
    if(s[0] == '?') {
        if(s[1] == 'a' || s[1] == 'b'){
            s[0] = 'c';
        } else {
            s[0] = 'a';
        }
    }

    while(r < n) {
        if(s[r] == '?') {
            // check at both the position
            if(r - 1 > -1 && r + 1 < n) {
                // in mid somewhere
                if(s[r - 1] == 'a' && (s[r + 1] == 'a' || s[r + 1] == '?')) {
                    s[r] = 'b';
                } else if(s[r - 1] == 'a' && (s[r + 1] == 'b' || s[r + 1] == '?')) {
                    s[r] = 'c';
                } else if(s[r - 1] == 'a' && (s[r + 1] == 'c' || s[r + 1] == '?')) {
                    s[r] = 'b';
                } else if(s[r - 1] == 'b' && (s[r + 1] == 'a' || s[r + 1] == '?')) {
                    s[r] = 'c';
                } else if(s[r - 1] == 'b' && (s[r + 1] == 'b' || s[r + 1] == '?')) {
                    s[r] = 'a';
                } else if(s[r - 1] == 'b' && (s[r + 1] == 'c' || s[r + 1] == '?')) {
                    s[r] = 'a';
                } else if(s[r - 1] == 'c' && (s[r + 1] == 'c' || s[r + 1] == '?')) {
                    s[r] = 'b';
                } else if(s[r - 1] == 'c' && (s[r + 1] == 'b' || s[r + 1] == '?')) {
                    s[r] = 'a';
                } else if(s[r - 1] == 'c' && (s[r + 1] == 'a' || s[r + 1] == '?')) {
                    s[r] = 'b';
                }
            }     
        }
        ++r;
    }
    r = r - 1;
    // end case
    if(s[r] == '?') {
        if(s[r - 1] == 'a' || s[r - 1] == 'b') {
            s[r] = 'c';
        } else {
            s[r] = 'a';
        }
    }

     return s;
}
int main() {
    int t;
    cin>>t;
    while(t) {
        string s;
        cin>>s;
        if(possible(s)) {
            cout<<parse(s)<<endl;
        } else {
            cout<<-1<<endl;
        }
        
        --t;
    }
}
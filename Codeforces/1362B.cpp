//https://codeforces.com/problemset/problem/1362/B
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int johnnyAndHisHobbies(vector<int> A) {
    int n = A.size();
    set<int> s1;
    set<int> s2;
    for(int i = 0; i < n; ++i) {
        s1.insert(A[i]);
    }
    
    for(int i = 1; i < 1025; ++i) {
        for(int j = 0; j < n; ++j) {
            s2.insert(A[j] ^ i);
        }
        if(s1 == s2) {
            return i;
        }
        s2.clear();
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t) {
        int n;
        cin>>n;
        vector<int> A(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        cout<<johnnyAndHisHobbies(A)<<endl;
        --t;
    }
}
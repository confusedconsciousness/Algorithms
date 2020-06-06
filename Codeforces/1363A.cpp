//https://codeforces.com/problemset/problem/1363/A
#include<iostream>
#include<vector>
using namespace std;

bool oddSelection(vector<int> A, int x) {
    int n = A.size();
    int total_evens = 0, total_odds = 0;
    for(int i = 0; i < n; ++i) {
        if(A[i] % 2 == 0) {
            ++total_evens;
        } else {
            ++total_odds;
        }
    }
    // how can we get odd sum
    // odd no of odd elements + any number of even elements = odd sum
    // base case no odd available
    if(total_odds == 0) {
        return false;
    } else if (total_evens == 0) {
        if(x % 2 == 0) {
            // never possible, because even number of odds makes sum even
            return false;
        } else {
            return true;
        }
    } else {
        if (total_odds % 2 == 0) {
            --total_odds; // make it odd
        }
        if(total_odds + total_evens >= x) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t) {
        int n, x;
        cin>>n>>x;
        vector<int> A(n, 0);
        for(int i = 0; i < n; ++i) {
            cin>>A[i];
        }
        if(oddSelection(A, x)) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }
        cout<<endl;
        --t;
    }
}
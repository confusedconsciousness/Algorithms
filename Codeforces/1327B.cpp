//https://codeforces.com/problemset/problem/1327/B
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t) {
        int n; // no of daughters
        cin>>n;
        vector<vector<int> > L;
        int k;
        for(int i = 0; i < n; ++i) {
            cin>>k;
            vector<int> aux(k, 0);
            for(int j = 0; j < k; ++j) {
                cin>>aux[j];
            }
            L.push_back(aux);
        }

        // we've n daughters, and n kingdoms
        bool available[n]; // whether this kingdom is available or not
        for(int i = 0; i < n; ++i) {
            available[i] = true;
        }

        // let's get going throught the list
        int f = 0;
        int girl = -1;
        int kingdom = -1;
        for(int i = 0; i < L.size(); ++i) {
            f = 0;
            for(int j = 0; j < L[i].size(); ++j) {
                // we are going throught each list and as we go through we first check whether it is available or not
                if(available[L[i][j] - 1]) {
                    available[L[i][j] - 1] = false; // make it unavailable for the next girl
                    f = 1; // it means we found someone
                    break; // simply go to the next girl
                }
            }
            // if we reach here with f == 0
            // it means we were not able to find a kingdom for the current girl
            if(f == 0) {
                girl = i + 1;
            }
        }

        // let's see which kingdom is left
        for(int i = 0; i < n; ++i) {
            if(available[i] == true) {
                kingdom = i + 1;
                break;
            }
        }

        if(girl == -1 && kingdom == -1) {
            cout<<"OPTIMAL"<<endl;
        } else {
            cout<<"IMPROVE"<<endl;
            cout<<girl<<" "<<kingdom<<endl;
        }


        --t;
    }
}
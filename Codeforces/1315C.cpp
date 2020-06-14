#include<iostream>
#include<vector>
using namespace std;

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
        int upper_bound = 2 * n;
        bool available[upper_bound + 1]; // initialise it
        for(int i = 0; i < upper_bound + 1; ++i) {
            available[i] = true;
        }
        for(int i = 0; i < n; ++i) {
            available[A[i]] = false; // these numbers can't be used
        }

        vector<int> res; // we'lll store the result her
        int f = 0; // flag to tell that we've found something
        for(int i = 0; i < n; ++i) {
            f = 0;
            res.push_back(A[i]);
            for(int j = A[i] + 1; j <= upper_bound; ++j) {
                // find smallest empty space
                if(available[j]) {
                    res.push_back(j);
                    available[j] = false;
                    f = 1;
                    break;
                }
            }
            if(f == 0) {
                break;
            }
        }
        if(f == 0) {
            cout<<-1;
        } else {
            for(int i = 0; i < 2 * n; ++i) {
                cout<<res[i]<<" ";
            }
        }
        cout<<endl;
        --t;
    }
}
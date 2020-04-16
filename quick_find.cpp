#include<iostream>
#include<vector>
using namespace std;

class QuickFind{
    vector<int> A;
    public:
        QuickFind(int n);
        bool connected(int p, int q);
        void unionIt(int p, int q);
        void show();
};

QuickFind::QuickFind(int n){
    // initially we are initialising it with the same value as its index
    // if the A[p] == A[q] where p and q are two different numbers, it suggest they are connected
    // if not we have to perform the union so that they get connected
    // so if we called union(p, q) we have to change all the indices that have value of A[p] to A[q]
    for(int i = 0; i < n; ++i){
        A.push_back(i);
    }
}

bool QuickFind::connected(int p, int q){
    if(A[p] == A[q]){
        return true;
    }
    return false;
}

void QuickFind::unionIt(int p, int q){
    // we reached here only if p and q are not connected
    int tmp = A[p]; // we've to replace all the elements with value tmp -> A[q]
    for(int i = 0; i < A.size(); ++i){
        if(A[i] == tmp){
            A[i] = A[q];
        }
    }
}

void QuickFind::show(){
    cout<<endl;
    for(int i = 0; i < A.size(); ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    QuickFind Q(n);

    int queries; // queries
    cin>>queries;
    int p, q; // elements
    while(queries){
        cin>>p>>q;
        if(!Q.connected(p, q)){
            Q.unionIt(p, q);
        }
        --queries;
    }

    Q.show();
    return 0;
}
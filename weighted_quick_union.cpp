#include<iostream>
#include<vector>
using namespace std;

class WeightedQuickUnion{
     vector<int> A;
     vector<int> S; // to count the total elements present in the tree (root)
     vector<int> F; // to store the largest element
     public:
        WeightedQuickUnion(int n);
        bool connected(int p, int q);
        void unionIt(int p, int q);
        int root(int p);
        void show();
        int find(int p); // to find the largest element in the component
};

WeightedQuickUnion::WeightedQuickUnion(int n){
    // initalising the S to 1, because we only have one element connected i.e. it itself
    for(int i = 0; i < n; ++i){
        A.push_back(i);
        S.push_back(1); 
        F.push_back(0);
    }
}

int WeightedQuickUnion::root(int p){
    int tmp = A[p];
    while(tmp != A[tmp]){
        tmp = A[tmp];
    }
    return tmp;
}

bool WeightedQuickUnion::connected(int p, int q){
    return root(p) == root(q);
}

void WeightedQuickUnion::unionIt(int p, int q){
    int i = root(p);
    int j = root(q);
    if(S[i] > S[j]){
        // i is the bigger tree
        A[j] = i;
        S[i] += S[j];
        F[i] = max(F[i], max(p, q));
    }else{
        // j is the bigger tree
        A[i] = j;
        S[j] += S[i];
        F[j] = max(F[j], max(p, q));
    }
    
}

void WeightedQuickUnion::show(){
    cout<<endl;
    for(int i = 0; i < A.size(); ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int WeightedQuickUnion::find(int p){
    return F[root(p)];
}

int main(){
    int n;
    cin>>n;
    WeightedQuickUnion Q(n);
    int qry, p, q;
    cin>>qry;
    while(qry){
        cin>>p>>q;
        if(!Q.connected(p, q)){
            Q.unionIt(p, q);
        }
        --qry;
    }
    Q.show();
    cout<<endl;
    cout<<Q.find(1)<<endl;
    cout<<Q.find(3)<<endl;
    cout<<Q.find(9)<<endl;

    return 0;
}
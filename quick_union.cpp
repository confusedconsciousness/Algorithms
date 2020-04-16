#include<iostream>
#include<vector>
using namespace std;

class QuickUnion{
    vector<int> A;
    public:
        QuickUnion(int n);
        bool connected(int p, int q);
        void unionIt(int p, int q);
        int root(int p);
        void show();
};

QuickUnion::QuickUnion(int n){
    // each element is created and are parent of themselves
    for(int i = 0; i < n; ++i){
        A.push_back(i);
    }
}
int QuickUnion::root(int p){
    // this function will return the root of element at index p
    int tmp = A[p];
    while(tmp != A[tmp]){
        tmp = A[tmp];
    }
    return tmp;
}

bool QuickUnion::connected(int p, int q){
    // we need to find the root of p and root of q
    // if both roots are same then they are connected otherwise they are not
    if(root(p) == root(q)){
        return true;
    }
    return false;
}

void QuickUnion::unionIt(int p, int q){
    // if we are here it means they are not connected so let's connect it
    // we've to set the root(p) to point to the root of q
    int t1 = root(p);
    int t2 = root(q);
    A[t1] = t2;
    //show();
}

void QuickUnion::show(){
    cout<<endl;
    for(int i = 0; i < A.size(); ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    QuickUnion Q(n);
    int qry;
    int p, q;
    cin>>qry;
    while(qry){
        cin>>p>>q;
        if(!Q.connected(p, q)){
            Q.unionIt(p, q);
        }
        --qry;
    }
    Q.show();
    return 0;

}
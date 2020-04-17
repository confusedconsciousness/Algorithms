#include<iostream>
#include<vector>
#define ONLINE_JUDGE freopen("input","r",stdin); freopen("output","w",stdout);
using namespace std;

class Percolation{
    vector<int> A; // containing n ^ 2 element, basically flattening the grid
    vector<int> S; // will contain the total element associated with the current root, to make a balanced tree
    vector<vector<int> > G; // n-by-n grid
    int O; // will take into account the number open sites
    public:
        Percolation(int n); //creates n-by-n grid, with all sites initially blocked
        void open(int row, int col); // open the site if it is not open already
        bool isOpen(int row, int col); // is the site open?
        bool isFull(int row, int col); // is the site full, A full site is an open site that can be connected to an open site in the top row via a chain of neighboring (left, right, up, down) open sites
        int numberOfOpenSites(); // returns the number of open sites
        bool percolates(); // does the system percolates

        void unionIt(int p, int q); // connect p and q
        int root(int p); // to find the root of the p
        void show();

};

Percolation::Percolation(int n){
    O = 0; // nothing open
    int t = n * n;
    for(int i = 0; i < t; ++i){
        A.push_back(i); // every element is root of itself
        S.push_back(1); // each contain 1 element
    }
    // in additional to the n * n elements, we'll create 2 more elements
    // we'll call them outliers, first outlier will connect to all the element present at the top
    // second outlier will connect to all the element present at the bottom
    A.push_back(t);
    A.push_back(t + 1); 
    S.push_back(1); S.push_back(1);
    // there are indexed at n2 and n2 + 1
    // now connect them
    // all the first row parent should be the t
    // all the last row parent should be t + 1

    for(int i = 0; i < n; ++i){
        A[i] = t;
    }
    for(int i = 0; i < n; ++i){
        A[n * n - i - 1] = t + 1;
    }

    S[t] += n;
    S[t + 1] += n;

    for(int i = 0; i < n; ++i){
        vector<int> tmp;
        for(int j = 0; j < n; ++j){
            tmp.push_back(0); // every thing is considered closed
        }
        G.push_back(tmp);
    }
    cout<<"constructor called : all parameters were initialised properly"<<endl;
    //show();
}

// ************************************ UNION FIND BASIC OPERATIONS ************************************
int Percolation::root(int p){
    int tmp = A[p];
    while(tmp != A[tmp]){
        tmp = A[tmp];
    }
    return tmp;
}

void Percolation::unionIt(int p, int q){

    int i = root(p);
    int j = root(q);
    if(i == j){
        return;
    }
    if(S[i] > S[j]){
        // i is the bigger tree
        A[j] = i;
        S[i] += S[j];
    }else{
        // j is the bigger tree
        A[i] = j;
        S[j] += S[i];
    }
}
// ******************************************************************************************************

bool Percolation::isOpen(int row, int col){
    return G[row][col] == 1;
}

void Percolation::open(int row, int col){
    //show();
    ++O; // increment the total open site
    int m = G.size();
    int n = G[0].size();
    // we've to open this cell and also check if any other adjacent is open, if it is then union them
    G[row][col] = 1; // 1 means it is open
    int p = row * m + col;
    int q;
    // now we need to search in all the direction
    // top
    if(row - 1 > -1 && G[row - 1][col] == 1){
        // figure out the number from row and col
        q = (row - 1) * m + col;
        unionIt(p, q);
    }
    // bottom
    if(row + 1 < G.size() && G[row + 1][col] == 1){
        q = (row + 1) * m + col;
        unionIt(p, q);
    }
    // left
    if(col - 1 > -1 && G[row][col - 1] == 1){
        q = row * m + col - 1;
        unionIt(p, q);
    }
    // right
    if(col + 1 <  G[0].size() && G[row][col + 1] == 1){
        q = row * m + col + 1;
        unionIt(p, q);
    }

}

bool Percolation::isFull(int row, int col){
    int m = G.size();
    int n = G[0].size();
    // just need to check whether this cell is connected to the top most outlier
    int p = row * m + col;
    return root(p) == root(A[O]);
}

int Percolation::numberOfOpenSites(){
    return O;
}

bool Percolation::percolates(){
    int n = G.size();
    return root(A[n * n]) == root(A[n * n + 1]);
}

void Percolation::show(){
    int n = G.size();
    cout<<endl;
    for(int i = 0; i < n * n + 2; ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    Percolation P(n);
    int q;
    cin>>q;
    int a, b;
    while(q){
        cin>>a>>b;
        if(!P.isOpen(a - 1, b - 1))
            P.open(a - 1, b - 1);
        --q;
    }
    cout<<endl;
    cout<<"this system percolates ? "<<P.percolates();
    return 0;
}
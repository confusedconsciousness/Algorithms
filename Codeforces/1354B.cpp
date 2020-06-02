#include<iostream>
#include<string>
#include<vector>
using namespace std;

int parse(string s) {
    // base case whether the string contains 1, 2, or 3 if not return 0
    vector<int> map(3, 0);
    int n = s.size();
    string t = "123";
    for(int i  = 0; i < n; ++i) {
        map[s[i] - '1']++;
    }
    if(map[0] == 0 || map[1] == 0 || map[2] == 0)  {
        return 0;
    }
    // reset it
    map[0] = 1, map[1] = 1, map[2] = 1;
    // a way to create t basically (minimum window substring approach)
    int counter = 3;
    int begin = 0, end = 0, d = n;
    while(end < n) {
        if(map[s[end++] - '1']-- > 0) counter--;
        while(counter == 0) {
            if(end - begin < d) {
                d = end - begin;
            }
            if(map[s[begin++] - '1']++ == 0) {
                counter++;
            }
        }
    
    return d;
}

int main() {
    int t;
    cin>>t;
    while(t) {
        string s;
        cin>>s;
        cout<<parse(s)<<endl;
        --t;
    }
}
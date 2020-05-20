//https://codeforces.com/problemset/problem/1335/B
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string tutorial(int n, int a, int b) {
    int l = 0;
    string s = ""; 
    while(l < n) {
        s.push_back('a' + l % b) ;
        ++l;
    }
    return s;
}

string mySolution(int n, int a, int b) {
    string alphas = "abcdefghijklmnopqrstuvwxyz";
    string s = ""; // start with an empty string
    vector<int> M(26, 0); // create a map
    int left = 0, right = 0; // pointer
    int unique = 0;
    int i = 0; // idx
    while(right < n) {
        if(unique < b) {
            s += alphas[i];
            M[alphas[i] - 'a']++; // take it into account that it has been considered
            ++i; // to consider next unique character
            ++unique; // increment the unique counter
            ++right; 
        }else {
            // it means we've all the unique characters that were needed in the substring
            // fill the remaining one with the last occurrence, till we get the desired length of substring
            while(right - left < a) {
                s += s.back();
                ++right;
            }
            // if we got the satisfied substring, we need to increment the left counter and remove the character from map
            if(M[s[left] - 'a'] == 1) {
                i = s[left] - 'a'; // move the pointer to that
                M[s[left] - 'a']--; // update the map
                ++left;
                --unique;
            }
        }
    }
    return s;
}

int main() {
    int t;
    
    cin>>t;
    while(t) {
        int n,a,b;
        cin>>n>>a>>b;
        cout<<tutorial(n, a, b)<<endl;    
        --t;
    }
}
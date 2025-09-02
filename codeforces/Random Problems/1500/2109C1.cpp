// https://codeforces.com/problemset/problem/2109/C1

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n;
    cin >> n;
    int input;
    cout << "digit" << endl << flush;
    cin >> input;
    cout << "digit" << endl << flush;
    cin >> input;
    for (int i = 8; i >= 1; i/=2) {
        cout << "add " << -i << endl << flush;
        cin >> input;
    }
    cout << "add " << n - 1 << endl << flush;
    cin >> input;
    cout << "!" << endl << flush;
    cin >> input;
}

int main() {    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
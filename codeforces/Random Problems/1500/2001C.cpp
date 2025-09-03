// https://codeforces.com/problemset/problem/2001/C

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
    vector<vector<int>> adj(n + 1);
    for (int node = 2; node <= n; node++) {
        int checking = 1;
        while (true) {
            cout << "?" << " " << checking << " " << node << endl << flush;
            int got;
            cin >> got;
            if (got == checking) {
                adj[got].push_back(node);
                break;
            }
            checking = got;
        }
    }

    cout << "!" << " ";
    for (int node = 1; node <= n; node++) {
        for (int child : adj[node]) {
            cout << node << " " << child << " ";
        }
    }
    cout << endl;
}

int main() {    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
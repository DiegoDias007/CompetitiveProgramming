// https://codeforces.com/contest/2131/problem/D

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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int n_leaf = 0;
    for (int u = 0; u < n; u++) {
        n_leaf += adj[u].size() == 1;
    }

    int ans = n_leaf;
    for (int u = 0; u < n; u++) {
        int cur_leaf = adj[u].size() == 1;
        for (auto v : adj[u]) {
            cur_leaf += adj[v].size() == 1;
        }
        ans = min(ans, n_leaf - cur_leaf);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
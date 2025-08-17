// https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int v) {
    if (vis[v]) return;
    vis[v] = true;
    for (auto u : adj[v]) {
        dfs(adj, vis, u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int n_components = 0;
    vector<int> components;
    vector<bool> vis(n, false);
    for (int v = 0; v < n; v++) {
        if (!vis[v]) {
            n_components++;
            components.push_back(v + 1);
            dfs(adj, vis, v);
        }
    }
    cout << n_components - 1 << endl;
    for (int i = 0; i < n_components - 1; i++) {
        cout << components[i] << " " << components[i + 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
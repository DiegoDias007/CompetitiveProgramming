// https://cses.fi/problemset/task/1669/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, int node, int parent, int n) {
    path.push_back(node);
    vis[node] = true;
    for (auto child : adj[node]) {
        if (!vis[child]) dfs(adj, vis, path, child, node, n);
        else if (child != parent) {
            path.push_back(child);
            reverse(path.begin(), path.end());
            while (path.back() != path[0]) path.pop_back();
            cout << (int)path.size() << endl;
            for (int i = 0; i < (int)path.size(); i++) cout << path[i] + 1 << " ";
            cout << endl;
            exit(0);
        }
    }
    path.pop_back();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n), path;
    for (int node = 0; node < n; node++) {
        if (!vis[node]) dfs(adj, vis, path, node, node, n);

    }
    cout << "IMPOSSIBLE" << endl;
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
#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int n;
vector<vector<int>> adj;
vector<int> dp, sz, vis;

void dfs(int node) {
    vis[node] = true;
    vector<int> a;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child);
            sz[node] += sz[child];
            a.push_back(child);
        }
    }
    
    if (a.size() == 1) {
        int child = a[0];
        dp[node] = sz[child] - 1;
    } else if (a.size() == 2) {
        int u1 = a[0];
        int u2 = a[1];
        int v1 = sz[u1] - 1 + dp[u2];
        int v2 = sz[u2] - 1 + dp[u1];
        dp[node] = max(v1, v2);
    }
}

void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.assign(n, 0), sz.assign(n, 1), vis.assign(n, 0);
    dfs(0);
    cout << dp[0] << endl;
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
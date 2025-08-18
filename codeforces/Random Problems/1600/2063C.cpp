// https://codeforces.com/contest/2063/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

pair<int, int> max_edges_child(vector<set<int>>& adj, int node) {
    int mx =  0, cnt = 0;
    for (auto child : adj[node]) {
        int sz = adj[child].size();
        if (sz > mx) {
            mx = sz;
            cnt = 1;
        } else if (sz == mx) cnt++;
    }
    return {mx, cnt};
}

int find_mx(vector<set<int>>& adj, int n, int removed=-1) {
    int node = -1, mx = -1;
    for (int i = 0; i < n; i++) {
        if (i == removed) continue;
        int cur = adj[i].size();
        if (cur > mx) {
            node = i;
            mx = cur;
        } else if (cur == mx) {
            if (max_edges_child(adj, node) > max_edges_child(adj, i)) {
                node = i;
                mx = cur;
            }
        }
    }
    return node;
}

void remove_node(vector<set<int>>& adj, int n, int node) {
    for (int i = 0; i < n; i++) {
        if (adj[i].find(node) != adj[i].end()) {
            adj[i].erase(node);
        } else if (i == node) {
            adj[i].clear();
        }
    }
}

void dfs(vector<set<int>>& adj, vector<int>& vis, int node) {
    if (vis[node]) return;
    vis[node] = true;
    for (auto child : adj[node]) {
        dfs(adj, vis, child);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<set<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int n1 = find_mx(adj, n);
    remove_node(adj, n, n1);
    int n2 = find_mx(adj, n, n1);
    remove_node(adj, n, n2);
    assert(n1 != n2);

    int ans = 0;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i] && i != n1 && i != n2) {
            ans++;
            dfs(adj, vis, i);
        }
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
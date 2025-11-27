#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cnt(n, 1);
    function<void(int, int)> dfs_cnt = [&](int node, int parent) {
        for (auto child : adj[node]) {
            if (child == parent) continue;
            dfs_cnt(child, node);
            cnt[node] += cnt[child];
        }
    };

    dfs_cnt(0, -1);

    ll ans = n;
    function<void(int, int)> dfs_ans = [&](int node, int parent) {
        if (parent != -1) cnt[parent] = n - cnt[node];

        for (auto child : adj[node]) {
            int rem = n - cnt[child];
            if (rem >= k) ans += cnt[child];
        }

        for (auto child : adj[node]) {
            if (child == parent) continue;
            dfs_ans(child, node);
        }
    };

    dfs_ans(0, -1);

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
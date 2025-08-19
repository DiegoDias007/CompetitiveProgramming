// https://codeforces.com/problemset/problem/2070/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll MOD = 998244353;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    vector<ll> parent(n);
    for (ll i = 1; i < n; i++) {
        ll u;
        cin >> u;
        u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
        parent[i] = u;
    }

    map<ll, vector<ll>> levels;
    vector<ll> vis(n);
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    vis[0] = true;
    while (!q.empty()) {
        ll node = q.front().first;
        ll level = q.front().second;
        q.pop();
        levels[level].push_back(node);
        for (auto child : adj[node]) {
            if (!vis[child]) {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }

    vector<ll> ways_node(n);
    ways_node[0] = 1;
    for (auto node : levels[1]) ways_node[node] = 1;
    map<ll, ll> ways_depth;
    ways_depth[0] = 1;
    ways_depth[1] = levels[1].size();
    for (auto [level, a] : levels) {
        if (level == 0 || level == 1) continue;
        for (auto node : a) {
            ll pnode = parent[node];
            ways_node[node] = (ways_depth[level - 1] - ways_node[pnode] + MOD) % MOD;
            ways_node[node] %= MOD;
            ways_depth[level] += ways_node[node];
            ways_depth[level] %= MOD;
        }
    }

    ll ans = 0;
    for (auto ways : ways_node) {
        ans += ways;
        ans %= MOD;
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
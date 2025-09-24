// https://codeforces.com/problemset/problem/2114/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll INF = 1e18;

void dfs(vector<vector<ll>>& adj, vector<ll>& a, vector<pair<ll, ll>>& dp, vector<ll>& vis, ll node, ll n) {
    vis[node] = true;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dp[child].first = min(a[child], a[child] - dp[node].second);
            dp[child].second = max(a[child], a[child] - dp[node].first);
            dfs(adj, a, dp, vis, child, n);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> vis(n);
    vector<pair<ll, ll>> dp(n, {INF, 0});
    dp[0] = {a[0], a[0]};
    dfs(adj, a, dp, vis, 0, n);
    for (ll i = 0; i < n; i++) {
        cout << dp[i].second << " ";
    }
    cout << endl;
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
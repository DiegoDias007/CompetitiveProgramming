#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
    }

    sort(edges.begin(), edges.end(), [&](auto e1, auto e2) {
        auto [u1, u2] = e1;
        auto [v1, v2] = e2;
        ll x1 = a[u1], x2 = a[u2];
        ll y1 = a[v1], y2 = a[v2];
        if (x2 != y2) return x2 < y2;
        return x1 < y1;
    });

    vector<map<int, ll>> dp(n);
    for (auto [u, v] : edges) {
        ll k = a[v] - a[u];
        dp[v][a[u]] += 1 + dp[u][k];
        dp[v][a[u]] %= MOD;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto [_, c] : dp[i]) {
            ans += c;
            ans %= MOD;
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
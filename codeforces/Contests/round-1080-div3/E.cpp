#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> parent(n + 1);
    adj[0] = {1};
    for (ll i = 1; i <= n; i++) {
        ll l, r;
        cin >> l >> r;
        if (l == 0) continue;
        adj[i] = {l, r};
        parent[l] = i;
        parent[r] = i;
    }

    // dp[i]: tempo para percorrer a subtree comecando em i
    vector<ll> dp(n + 1);

    // calcular dp
    auto dfs = [&](auto dfs, ll i) -> void {
        if (adj[i].size() == 0) return;
        for (auto child : adj[i]) {
            dfs(dfs, child);
            dp[i] += dp[child] + 2;
            dp[i] %= MOD;
        }
    };

    dfs(dfs, 0);

    vector<ll> ans(n + 1);
    
    // calcular ans
    auto dfs2 = [&](auto dfs2, ll i) -> void {
        ll p = parent[i];
        ll cur_ans = dp[i] + (1 + ans[p]);
        cur_ans %= MOD;
        ans[i] = cur_ans;
        for (auto child : adj[i]) dfs2(dfs2, child);
    };
    
    dfs2(dfs2, 1);
    for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
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
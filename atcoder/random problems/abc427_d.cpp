#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    string s;
    cin >> s;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    // dp[i][j]: se estivermos em V(i) e ja foram feitas
    // j jogadas, o jogador atual ira ganhar?
    vector<vector<int>> dp(n, vector<int>(2*k, -1));
    auto dfs = [&](auto dfs, int u, int moves) -> void {
        if (dp[u][moves] != -1) return;

        if (moves == 2*k - 1) {
            bool bob_wins = false;
            for (auto child : adj[u]) bob_wins |= s[child] == 'B';
            dp[u][moves] = bob_wins;
            return;
        }
        
        bool player_wins = false;
        for (auto child : adj[u]) {
            dfs(dfs, child, moves + 1);
            player_wins |= !dp[child][moves + 1];
        }
        dp[u][moves] = player_wins;
    };

    dfs(dfs, 0, 0);
    
    bool alice_wins = dp[0][0];

    if (alice_wins) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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
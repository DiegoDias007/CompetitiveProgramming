// https://cses.fi/problemset/task/1672/

#include <bits/stdc++.h>
 
#define endl '\n'
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
 
const ll INF = 2e18;
 
void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[u][v], w);
    }
 
    for (int i = 0; i < n; i++) dist[i][i] = 0;
 
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (dist[u][v] == INF) cout << -1 << endl;
        else cout << dist[u][v] << endl;
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

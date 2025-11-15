#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll INF = 1e18;

int n, m;
vector<vector<pair<int, int>>> adj;

void solve() {
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    priority_queue<pair<pair<ll, int>, int>, vector<pair<pair<ll, int>, int>>, greater<pair<pair<ll, int>, int>>> pq;
    dist[0][0] = 0;
    dist[0][1] = 0;
    pq.push({{0, 0}, 0});
    pq.push({{0, 1}, 0});
    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();

        ll d = p.first;
        int used = p.second;
        if (dist[u][used] < d) continue;

        for (auto [c, dc] : adj[u]) {
            if (dist[c][used] > d + dc) {
                dist[c][used] = d + dc;
                pq.push({{dist[c][used], used}, c});
            }

            if (!used && dist[c][1] > d + (dc / 2)) {
                dist[c][1] = d + (dc / 2);
                pq.push({{dist[c][1], 1}, c});
            }
        }
    }
    cout << dist[n-1][1] << endl;
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
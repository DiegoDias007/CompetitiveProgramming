// https://cses.fi/problemset/task/1671/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll INF = 1e15;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }

    vector<ll> dist(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll weight = pq.top().first;
        pq.pop();

        if (weight > dist[node]) continue;
        
        for (auto [child, cweight] : adj[node]) {
            ll new_dist = weight + cweight;
            if (new_dist < dist[child]) {
                pq.push({new_dist, child});
                dist[child] = new_dist;
            }
        }
    }
    print_vec(dist);
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
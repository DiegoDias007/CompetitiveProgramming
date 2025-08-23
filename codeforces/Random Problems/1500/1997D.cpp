// https://codeforces.com/contest/1997/problem/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll want;
ll mx;

void dfs(vector<vector<ll>>& adj, vector<ll>& a, ll node, ll sum, bool& ok) {
    if (!ok) return;
    ll cur = a[node] - sum;
    ll need = max(0ll, want - cur);
    if (need > mx) {
        ok = false;
        return;
    }
    if (adj[node].size() == 0) {
        ok &= need == 0;
        return;
    }
    ll new_sum = sum + need;
    for (auto child : adj[node]) {
        dfs(adj, a, child, new_sum, ok);
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> adj(n);
    mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;
        adj[u].push_back(i);
    }

    ll best = 0;
    ll l = 1, r = mx;
    while (l <= r) {
        want = (l + r) / 2;
        bool ok = true;
        for (auto child : adj[0]) {
            dfs(adj, a, child, 0, ok);
            if (ok == false) break;
        }

        if (ok) {
            best = want;
            l = want + 1;
        } else {
            r = want - 1;
        }
    }
    cout << a[0] + best << endl;
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
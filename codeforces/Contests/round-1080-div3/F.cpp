#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

struct Q {
    ll a; ll b; ll c;
};

// f1(x) < f2(x)
bool h(Q& f1, Q& f2) {
    Q f3 = {f1.a - f2.a, f1.b - f2.b, f1.c - f2.c};
    if (f3.a == 0) return f3.b == 0 && f1.c < f2.c;
    ll delta = f3.b * f3.b - 4*f3.a*f3.c;
    return f3.a < 0 && delta < 0;
}

void solve() {
    ll n;
    cin >> n;
    vector<Q> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }

    vector<vector<ll>> adj(n), rev(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (h(a[i], a[j])) {
                adj[i].push_back(j);
                rev[j].push_back(i);
            }
        }
    }

    vector<ll> order(n);
    queue<ll> q;

    vector<ll> n_child(n);
    for (ll i = 0; i < n; i++) {
        n_child[i] = adj[i].size();
        if (n_child[i] == 0) q.push(i);
    }


    for (int i = 0; i < n; i++) {
        ll node = q.front();
        q.pop();
        order[i] = node;
        for (auto child : rev[node]) {
            n_child[child]--;
            if (n_child[child] == 0) q.push(child);
        }
    }

    // dp1[i]: caminho mais longo comecando em i
    vector<ll> dp1(n, 1);
    for (auto node : order) {
        for (auto child : adj[node]) dp1[node] = max(dp1[node], dp1[child] + 1);
    }

    // dp2[i]: caminho mais longo terminando em i
    vector<ll> dp2(n, 1);
    reverse(order.begin(), order.end());
    for (auto node : order) {
        for (auto child : rev[node]) dp2[node] = max(dp2[node], dp2[child] + 1);
    }

    for (ll i = 0; i < n; i++) cout << dp1[i] + dp2[i] - 1 << " ";
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
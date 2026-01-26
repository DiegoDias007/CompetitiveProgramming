#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }

    a.back() = max(a.back(), b.back());
    for (ll i = n - 2; i >= 0; i--) {
        a[i] = max(a[i], max(a[i + 1], b[i]));
    }

    vector<ll> ps(n + 1);
    for (ll i = 1; i <= n; i++) {
        ps[i] = ps[i-1] + a[i-1];
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << ps[r] - ps[l-1] << " ";
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
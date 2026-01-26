#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    ll need = 0;
    for (ll i = 0; i < n; i++) {
        need += b[i];
        if (need > n) break;
        ll x = a[n - need];
        ans = max(ans, x * (i+1));
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
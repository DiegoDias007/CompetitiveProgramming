#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll s, m;
    cin >> s >> m;

    vector<ll> bits;
    for (int i = 0; i < 63; i++) {
        ll bit = 1ll << i;
        if (m & bit) bits.push_back(i);
    }

    ll x = 1ll << bits.front();
    bool impossible = s % x != 0;
    if (impossible) {
        cout << -1 << endl;
        return;
    }

    auto ok = [&](ll n) -> bool {
        ll cur_s = s;
        for (int i = bits.size() - 1; i >= 0; i--) {
            ll x = 1ll << bits[i];
            ll need = cur_s / x;
            ll can_use = min(n, need);
            cur_s -= x * can_use;    
        }
        return cur_s == 0;
    };

    ll ans;
    ll l = 0, r = s;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
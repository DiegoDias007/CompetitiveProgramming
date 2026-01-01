#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

ll ceil_sqrt(ll x) {
    ll l = 1, r = 2e9;
    ll s = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * mid >= x) {
            s = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return s;
}

void solve() {
    ll C, D;
    cin >> C >> D;

    ll ans = 0;
    ll pw = 1;
    for (ll k = 1; k <= 10; k++) {
        pw *= 10;
        ll L = max(1 + C, pw / 10);
        ll R = min(D + C, pw - 1);
        ll mn = C * pw + L;
        ll mx = C * pw + R;
        if (L > R) continue;
        ans += (ll)sqrtl(mx) - ceil_sqrt(mn) + 1;
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
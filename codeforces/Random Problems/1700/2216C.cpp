#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (p > q) swap(p, q);

    vector<ll> ps1(n + 1), ps2(n + 1), ps3(n + 1);
    for (int i = 1; i <= n; i++) ps1[i] = ps1[i-1] + min(a[i] % p, (a[i] % q) % p);
    for (int i = 1; i <= n; i++) ps2[i] = ps2[i-1] + a[i] % p;
    for (int i = 1; i <= n; i++) ps3[i] = ps3[i-1] + (a[i] % q) % p;

    ll ans = 1e18;
    for (int r = k; r <= n; r++) {
        int l = r - k + 1;
        ll cur_ans = (ps1[l-1]) + (min(ps2[r] - ps2[l-1], ps3[r] - ps3[l-1])) + (ps1[n] - ps1[r]);
        ans = min(ans, cur_ans);
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
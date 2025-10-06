#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, y;
    cin >> n >> y;
    vector<ll> a(n);
    ll mx = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }

    vector<ll> pcnt(mx + 1);
    for (ll i = 0; i < n; i++) pcnt[a[i]]++;
    for (ll i = 1; i <= mx; i++) pcnt[i] += pcnt[i - 1];

    ll ans = -1e18;
    for (ll x = 2; x <= mx + 1; x++) {
        ll sum = 0;
        for (ll p = 1; p <= (mx + x - 1) / x; p++) {
            // de onde veio p
            ll l = (p - 1) * x + 1;
            ll r = min(mx, p * x);

            ll cnt = pcnt[r] - pcnt[l - 1];
            ll cnt_p = pcnt[p] - pcnt[p - 1];
            sum += p * cnt - y * max(0ll, (cnt - cnt_p));
        }
        ans = max(ans, sum);
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
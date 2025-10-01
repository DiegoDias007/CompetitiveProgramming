#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> cnt(n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    bool ok = true;
    for (auto v : cnt) ok &= v % k == 0;

    if (!ok) {
        cout << 0 << endl;
        return;
    }

    ll ans = 0;
    vector<ll> window_cnt(n + 1);
    ll l = 0;
    for (ll r = 0; r < n; r++) {
        window_cnt[a[r]]++;
        while (window_cnt[a[r]] > (cnt[a[r]] / k)) {
            window_cnt[a[l]]--;
            l++;
        }
        ans += r - l + 1;
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
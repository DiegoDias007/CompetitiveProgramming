// https://atcoder.jp/contests/abc418/tasks/abc418_c

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<ll> ps(n + 1);
    for (ll i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i - 1];
    }

    while (q--) {
        ll b;
        cin >> b;
        if (b == 1) {
            cout << 1 << endl;
            continue;
        }

        ll idx = lower_bound(a.begin(), a.end(), b) - a.begin();
        ll take_right = (b - 1) * (n - idx);
        ll take_left = ps[idx] - ps[0];
        ll cur = take_left + take_right + 1;
        if (ps[n] - ps[0] < cur) cout << -1 << endl;
        else cout << cur << endl;
    }
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
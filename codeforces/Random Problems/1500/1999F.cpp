// https://codeforces.com/problemset/problem/1999/F

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

ll binpow(ll x, ll y) {
    if (y == 0) return 1;
    ll p = binpow(x, y / 2);
    ll pp = (p * p) % MOD;
    if (y % 2 == 1) pp = (pp * x) % MOD;
    return pp;
}

ll mod_inv(ll x) {
    return binpow(x, MOD - 2);
}

ll comb(ll x, ll y, vector<ll>& fact) {
    if (y < 0 || y > x) return 0;
    ll num = fact[x];
    ll den = (fact[x - y] * fact[y]) % MOD;
    return (num * mod_inv(den)) % MOD;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll cnt_1s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt_1s += a[i] == 1;
    }

    vector<ll> fact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll ans = 0;
    for (int i = (k + 1) / 2; i <= cnt_1s; i++) {
        ll c1 = comb(cnt_1s, i, fact);
        ll c2 = comb(n - cnt_1s, k - i, fact);
        ans += (c1 * c2) % MOD;
        ans %= MOD;
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
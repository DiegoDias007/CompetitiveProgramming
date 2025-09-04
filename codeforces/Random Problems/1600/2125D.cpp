// https://codeforces.com/problemset/problem/2125/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll MOD = 998244353;

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll x = binpow(a, b / 2);
    ll xx = (x * x) % MOD;
    if (b % 2 == 1) xx = (xx * a) % MOD;
    return xx;
}

ll mod_inv(ll a) {
    return binpow(a, MOD - 2);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> a(n);
    vector<ll> pp(m + 2, 1);
    for (ll i = 0; i < n; i++) {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        ll pr = (p * mod_inv(q)) % MOD;
        a[i].first = pr;
        a[i].second.first = l;
        a[i].second.second = r;
        ll one_m_prob = (1 - pr + MOD) % MOD;
        pp[l] = (pp[l] * one_m_prob) % MOD;
    }

    for (ll i = 1; i <= m; i++) {
        pp[i] *= pp[i - 1];
        pp[i] %= MOD;
    }

    sort(a.begin(), a.end(), [&](auto& pair1, auto& pair2) {
        if (pair1.second.second != pair2.second.second) {
            return pair1.second.second < pair2.second.second;
        }
        return pair1.second.first < pair2.second.first;
    });

    vector<ll> dp(m + 1);
    dp[0] = 1;
    for (ll i = 0; i < n; i++) {
        ll p = a[i].first;
        ll l = a[i].second.first, r = a[i].second.second;

        ll prob_one_m_p = (1 - p + MOD) % MOD;
        ll prob_no_cell_lr = (pp[r] * mod_inv(pp[l - 1])) % MOD;
        ll prob_only_i = (prob_no_cell_lr * mod_inv(prob_one_m_p)) % MOD;
        prob_only_i = (prob_only_i * p) % MOD;
        
        dp[r] += (dp[l - 1] * prob_only_i) % MOD;
        dp[r] %= MOD;        
    }
    cout << dp[m] << endl;
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
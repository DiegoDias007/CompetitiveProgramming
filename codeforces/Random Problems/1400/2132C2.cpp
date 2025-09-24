// https://codeforces.com/contest/2132/problem/C2

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll N = 22;
vector<pair<ll, ll>> a(N);

vector<ll> get_deals(ll n, ll k) {
    vector<ll> cnt(N);
    ll deals = 0;
    for (int i = N - 1; i >= 0; i--) {
        ll times = n / a[i].first;
        deals += times;
        n -= times * a[i].first;
        cnt[i] = times;
    }
    return cnt;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> deals = get_deals(n, k);
    ll n_deals = 0;
    int last = -1;
    for (int i = 0; i < N; i++) {
        n_deals += deals[i];
        if (deals[i] != 0) last = i;
    }

    bool ok = n_deals <= k;

    k = k - n_deals;
    
    if (!ok) {
        cout << -1 << endl;
        return;
    }

    for (int i = last; i >= 1; i--) {
        if (k < 2) break;
        ll can_take = min(deals[i], k / 2);
        k -= 2*can_take;
        deals[i-1] += 3*can_take;
        deals[i] -= can_take;  
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) ans += deals[i] * a[i].second;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (ll x = 0; x < N; x++) {
        ll tx = 1;
        for (ll j = 0; j < x; j++) tx *= 3;

        ll first = tx, second = 3*tx + x*(tx/3);
        a[x] = {first, second};
    }

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
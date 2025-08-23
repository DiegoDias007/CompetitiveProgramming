// https://codeforces.com/problemset/problem/2028/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, m, v;
    cin >> n >> m >> v;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> pref(n + 1), suf(n + 2);
    ll cur_sum = 0;
    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        cur_sum += a[i];
        if (cur_sum >= v) {
            pref[i]++;
            cur_sum = 0;
        }
    }

    cur_sum = 0;
    for (ll i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        cur_sum += a[i];
        if (cur_sum >= v) {
            suf[i]++;
            cur_sum = 0;
        }
    }

    vector<ll> ps(n + 1);
    for (ll i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i];
    }

    ll ans = -1;
    for (ll i = 1; i <= n; i++) {
        ll have_left = pref[i - 1];
        ll need_right = m - have_left;
        ll l = i, r = n + 1;
        ll best = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (suf[mid] >= need_right) {
                l = mid + 1;
                best = mid;
            } else {
                r = mid - 1;
            }
        }
        if (best != -1) {
            ans = max(ans, ps[best - 1] - ps[i - 1]);
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
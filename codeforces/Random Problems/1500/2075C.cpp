// https://codeforces.com/contest/2075/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    ll ans = 0;
    for (ll cnt = 1; cnt <= n - 1; cnt++) {
        ll valid_left = m - (lower_bound(a.begin(), a.end(), cnt) - a.begin());
        ll need_right = n - cnt;
        ll valid_right = m - (lower_bound(a.begin(), a.end(), need_right) - a.begin());

        ll both_count = m - (lower_bound(a.begin(), a.end(), max(cnt, need_right)) - a.begin());

        ans += valid_left * valid_right;
        ans -= both_count;
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
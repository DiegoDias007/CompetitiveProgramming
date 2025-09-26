// https://codeforces.com/problemset/problem/1883/F

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<ll, ll> mp_first, mp_last;
    for (ll i = 0; i < n; i++) {
        mp_last[a[i]] = i;
        if (mp_first.find(a[i]) == mp_first.end()) mp_first[a[i]] = i;
    }

    ll cnt_right = 0;
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--) {
        cnt_right += mp_last[a[i]] == i;
        if (mp_first[a[i]] == i) ans += cnt_right;
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
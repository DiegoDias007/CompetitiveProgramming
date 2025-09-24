// https://codeforces.com/contest/2126/problem/E

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
    vector<ll> p(n), s(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        a[i] = lcm(p[i], s[i]);
    }

    vector<ll> np = a, ns = a;
    for (ll i = 1; i < n; i++) np[i] = gcd(np[i - 1], np[i]);
    for (ll i = n - 2; i >= 0; i--) ns[i] = gcd(ns[i + 1], ns[i]);

    bool ok = np == p && ns == s;
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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
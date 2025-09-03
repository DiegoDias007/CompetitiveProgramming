// https://codeforces.com/problemset/problem/2003/D1

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll g(set<ll> a) {
    vector<ll> empty;
    for (ll want = 0; want <= 1e9; want++) {
        if (a.find(want) == a.end()) {
            empty.push_back(want);
        }
        if (empty.size() == 2) break;
    }
    return empty[1];
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll mx = 0;
    for (ll i = 0; i < n; i++) {
        ll l;
        cin >> l;
        set<ll> st;
        for (ll j = 0; j < l; j++) {
            ll cur;
            cin >> cur;
            st.insert(cur);
        }
        mx = max(mx, g(st));
    }
    ll ans = (min(mx, m) + 1) * mx;
    ll remaining = m - min(mx, m);
    ans += (mx + 1 + m) * remaining / 2;
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
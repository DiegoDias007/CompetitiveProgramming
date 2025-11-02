#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll get_msb(ll x) {
    for (ll i = 60; i >= 0; i--) {
        ll mask = 1ll << i; 
        if (x & mask) return i;
    }
    return -1;
}

void solve() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1) {
        cout << l << endl;
        return;
    }

    if (n == 2 || (get_msb(l) == get_msb(r))) {
        cout << -1 << endl;
        return;
    }

    if (k >= n - 1) cout << (1ll << (get_msb(l) + 1)) << endl;
    else cout << l << endl;
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
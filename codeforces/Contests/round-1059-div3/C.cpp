#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll msb(ll x) {
    for (ll i = 30; i >= 0; i--) {
        ll mask = 1 << i;
        if (x & mask) {
            return i;
        }
    }
    assert(false);
}

void solve() {
    ll a, b;
    cin >> a >> b;

    if (msb(b) > msb(a)) {
        cout << -1 << endl;
        return;
    }
    
    vector<ll> ops;
    while (a != b) {
        ll x = 0;
        for (ll i = 0; i <= 30; i++) {
            ll mask = 1ll << i;
            bool a_has = a & mask;
            bool b_has = b & mask;
            if (a_has != b_has) {
                if ((x | mask) <= a) x |= mask;
            }
        }
        assert(x <= a);
        a = a ^ x;
        ops.push_back(x);
    }
    cout << ops.size() << endl;
    print_vec(ops);
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
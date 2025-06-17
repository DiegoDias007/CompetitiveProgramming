// https://codeforces.com/contest/1985/problem/G

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }

    ll half = b / 2;
    ll pow_half = binpow(a, half);
    ll ans = (pow_half * pow_half) % MOD;
    if (b % 2) {
        ans = (ans * a) % MOD;
    }

    return ans;
}

ll mod_inv(ll a) {
    return binpow(a, MOD - 2);
}

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;
    if (k >= 10) {
        cout << 0 << endl;
        return;
    }

    r--;
    ll mx_int = min(10 / k, 9ll);
    if (k == 2 || k == 5) mx_int--;
    ll ans = (binpow(mx_int + 1, l) * (binpow(mx_int + 1, r - l + 1) - 1)) % MOD;
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
// https://codeforces.com/problemset/problem/1971/F

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll calc_cur(ll x, ll r) {
    ll left = 0, right = 1e6;
    ll best_y = -1;
    while (left <= right) {
        ll y = (left + right) / 2;
        bool ok = x * x < r * r - (y * y);
        if (ok) {
            left = y + 1;
            best_y = y;
        }  else {
            right = y - 1;
        }
    }
    if (best_y == -1) return 0;
    return 2*best_y + 1;
}

void solve() {
    ll r;
    cin >> r;
    ll ans = 0;
    for (ll x = -r; x <= r; x++) {
        ans += calc_cur(x, r + 1);
        ans -= calc_cur(x, r);
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
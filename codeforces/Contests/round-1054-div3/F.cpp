#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll f(ll n) {
    return n*(n + 1) / 2;
}

void solve() {
    ll h, d;
    cin >> h >> d;
    ll l = 0, r = 2*d;
    ll rest = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll steps = mid + 1;
        ll n = d / steps;
        ll cnt_n = steps;
        ll cnt_np1 = d % steps;
        ll req_health = cnt_n * f(n) + cnt_np1 * (n + 1);
        bool ok = req_health < h + mid;
        if (ok) {
            rest = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << d + rest << endl;
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
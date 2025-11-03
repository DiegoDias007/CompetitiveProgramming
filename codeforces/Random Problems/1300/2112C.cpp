#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

/*
    (a, b, c) ok <=>
        a + b > c && a + b + c > mx
        a + b > c && a + b - mx > -c
        c < a + b && c > -a + -b + mx
*/

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    ll mx = a.back();
    sort(a.begin(), a.end());
    for (ll i = 0; i < n - 2; i++) {
        for (ll j = i + 1; j < n - 1; j++) {
            ll L = mx - a[i] - a[j];
            ll R = a[i] + a[j];
            ll lower = upper_bound(a.begin() + j + 1, a.end(), L) - a.begin();
            ll upper = lower_bound(a.begin() + j + 1, a.end(), R) - a.begin();
            if (lower >= upper) continue;
            ans += upper - lower;
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
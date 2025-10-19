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

    ll mx = 0;
    for (ll i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (i % 2 == 1) a[i] = mx;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i+=2) {
        if (i && a[i] >= a[i - 1]) {
            ll dif = a[i] - a[i - 1];
            a[i] -= dif + 1;
            ans += dif + 1;
        }

        if (i < n - 1 && a[i] >= a[i + 1]) {
            ll dif = a[i] - a[i + 1];
            a[i] -= dif + 1;
            ans += dif + 1;
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
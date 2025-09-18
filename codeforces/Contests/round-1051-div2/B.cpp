#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(k);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < k; i++) {
        cin >> b[i];
    }


    ll ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (ll i = 0; i < k; i++) {
        if (a.size() < b[i]) break;
        for (ll j = 0; j < b[i] - 1; j++) {
            ans += a.back();
            a.pop_back();
        }
        a.pop_back();
    }

    for (auto v : a) {
        ans += v;
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
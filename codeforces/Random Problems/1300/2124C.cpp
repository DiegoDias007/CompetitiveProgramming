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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }
    
    for (int i = 0; i < n; i++) a[i] /= g;

    ll x = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] % a[i - 1] != 0) {
            ll gc = gcd(a[i], a[i - 1]);
            ll y = a[i - 1] / gc;
            x = lcm(x, y);
        }
    } 
    cout << x << endl;
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
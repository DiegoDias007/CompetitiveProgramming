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
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll best_dif = 0;
    ll dif = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (dif + 2*i - a[i] >= 0) {
            dif += 2*i - a[i];
        } else {
            dif = 0;
        }
        best_dif = max(dif, best_dif);
    }
    cout << sum + best_dif << endl;
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
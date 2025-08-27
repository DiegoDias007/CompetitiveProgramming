// https://codeforces.com/contest/1862/problem/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<ll> mx;
    mx.insert(2e18);
    ll ans = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll cur_score = a[i] + sum - d*(i+1);
        ans = max(ans, cur_score);
        if (a[i] > 0) {
            if (mx.size() < m) {
                mx.insert(a[i]);
                sum += a[i];
            } else if (a[i] > *mx.begin()) {
                sum -= *mx.begin();
                mx.erase(mx.begin());
                mx.insert(a[i]);
                sum += a[i];
            }
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
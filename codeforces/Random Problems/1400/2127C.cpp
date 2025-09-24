// https://codeforces.com/contest/2127/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll INF = 2e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        ans += a[i].second - a[i].first;
    }

    ll add = INF;
    sort(a.begin(), a.end());
    ll mx = a[0].second;
    for (int i = 1; i < n; i++) {
        if (mx >= a[i].first) {
            cout << ans << endl;
            return;
        }

        add = min(add, 2*(a[i].first - mx));
        mx = max(mx, a[i].second);
    }
    ans += add;
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
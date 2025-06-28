// https://codeforces.com/problemset/problem/2051/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll calc_earnings(vector<ll>& a, vector<ll>& b, ll k, ll price) {
    ll x1 = lower_bound(a.begin(), a.end(), price) - a.begin();
    ll x2 = lower_bound(b.begin(), b.end(), price) - b.begin();
    ll neg_reviews = x1 - x2;
    if (neg_reviews > k) {
        return 0;
    }
    
    ll n = a.size();
    ll n_bought = n - x2;
    return price * n_bought;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, calc_earnings(a, b, k, a[i]));
        ans = max(ans, calc_earnings(a, b, k, b[i]));
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
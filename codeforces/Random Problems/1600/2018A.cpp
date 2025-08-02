// https://codeforces.com/problemset/problem/2018/A

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
    vector<ll> a(n);
    ll sum = 0, mx = 0;;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    int ans = 1;
    if (k == 0) {
        for (int i = 2; i <= n; i++) {
            bool cond1 = sum % i == 0;
            bool cond2 = mx <= sum / i;
            if (cond1 && cond2) ans = i;
        }
        cout << ans << endl;
        return;
    }

    for (int i = 2; i <= n; i++) {
        ll need = i - (sum % i);
        need %= i;
        if (need > k) continue;
        ll cur_k = k - need;
        ll cur_sum = sum + need + (i * (cur_k / i));
        bool ok = mx <= cur_sum / i;
        if (ok) ans = i;
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
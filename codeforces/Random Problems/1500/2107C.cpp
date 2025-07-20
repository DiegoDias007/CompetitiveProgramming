// https://codeforces.com/problemset/problem/2107/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll calc_mx_sum(vector<ll>& a, ll n) {
    ll cur_sum = 0;
    ll mx_sum = 0;
    for (ll i = 0; i < n; i++) {
        cur_sum += a[i];
        cur_sum = max(cur_sum, 0ll);
        mx_sum = max(mx_sum, cur_sum);
    }
    return mx_sum;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = false;
    ll mx_sum = 0;
    ll cur_sum = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur_sum = 0;
            flag = true;
            continue;
        }
        cur_sum += a[i];
        cur_sum = max(cur_sum, 0ll);
        mx_sum = max(mx_sum, cur_sum);
    }

    bool ok = mx_sum <= k;
    if (!flag) ok &= mx_sum == k;
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            a[i] = -1e7;
        }
    }

    for (ll idx = 0; idx < n; idx++) {
        if (s[idx] == '1') continue;
        ll l = -1e18, r = 1e18;
        while (l <= r) {
            ll mid = (l + r) / 2;
            a[idx] = mid;
            ll cur = calc_mx_sum(a,n);
            if (cur == k) {
                break;
            } else if (cur > k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        break;
    }
    
    cout << "YES" << endl;
    print_vec(a);
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
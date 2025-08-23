// https://codeforces.com/problemset/problem/1978/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> suf(n);
    suf[n - 1] = 0;
    for (ll i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], a[i + 1]);
    }

    ll sum = 0;
    ll mx_left = -1e9;
    for (ll i = 0; i < n; i++) {
        ll cur = a[i] + (i == 0 ? c : 0);
        ll mx_right = suf[i];
        if (cur > mx_left && cur >= mx_right) {
            cout << 0 << " ";   
        } else {
            ll cur_after_ops = cur + sum;
            cout << i + (cur_after_ops < mx_right) << " ";
        }
        mx_left = max(mx_left, cur);
        sum += cur;
    }
    cout << endl;
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
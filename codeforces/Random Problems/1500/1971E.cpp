// https://codeforces.com/problemset/problem/1971/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k), b(k);
    for (ll i = 0; i < k; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < k; i++) {
        cin >> b[i];
    }

    while (q--) {
        ll query;
        cin >> query;

        ll idx = -1;
        ll l = 0, r = k - 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll cur_dist = a[mid];
            if (cur_dist < query) {
                idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ll dist = a[idx + 1], time = b[idx + 1];
        ll dist_before = 0, time_before = 0;
        if (idx != -1) {
            dist_before = a[idx];
            time_before = b[idx];
        }
        
        dist -= dist_before;
        time -= time_before;


        ll ans = time_before;
        ans += time * (query - dist_before) / dist;
        cout << ans << " ";
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
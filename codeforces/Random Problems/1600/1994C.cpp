// https://codeforces.com/contest/1994/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> ps(n + 1);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i];
    }

    // dp[i]: number of subarrays ending at index i
    // such that their score is 0.
    vector<ll> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        int l = i + 1, r = n;
        int idx = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll cur_sum = ps[mid] - ps[i];
            if (cur_sum > x) {
                idx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (idx != -1) {
            dp[idx] += dp[i] + 1;
        }
    }
    
    ll ans = n * (n + 1) / 2;
    for (int i = 0; i <= n; i++) {
        ans -= dp[i];
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
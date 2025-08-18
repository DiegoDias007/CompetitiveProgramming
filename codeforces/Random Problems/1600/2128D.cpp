// https://codeforces.com/problemset/problem/2128/D

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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // dp[i]: sum of the longest decreasing subsequence
    // of all subarrays ending at index i.
    vector<ll> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2 + (a[2] < a[1]);
    for (int i = 3; i <= n; i++) {
        if (a[i] < a[i - 1]) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 2];
        dp[i] += i;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
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
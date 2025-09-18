#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll MOD = 998244353;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;
    for (ll i = 1; i < n; i++) {
        // dont make swap
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) dp[i][0] += dp[i - 1][0];
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) dp[i][0] += dp[i - 1][1];
        // make swap
        if (b[i] >= a[i - 1] && a[i] >= b[i - 1]) dp[i][1] += dp[i - 1][0];
        if (b[i] >= b[i - 1] && a[i] >= a[i - 1]) dp[i][1] += dp[i - 1][1];
        
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    ll ans = dp[n - 1][0] + dp[n - 1][1];
    ans %= MOD;
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
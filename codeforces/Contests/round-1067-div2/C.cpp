#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
   
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = a[0];
    dp[0][1] = a[0] + b[0];
    for (ll i = 1; i < n; i++) {
        dp[i][0] = max(a[i], dp[i-1][0] + a[i]);
        dp[i][1] = max(a[i] + b[i], dp[i-1][0] + a[i] + b[i]);
        dp[i][1] = max(dp[i][1], dp[i-1][1] + a[i]);
    }

    ll ans = -1e18;
    for (ll i = 0; i < n; i++) {
        ll cur = (k % 2 == 0) ? dp[i][0] : dp[i][1];
        ans = max(ans, cur);
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
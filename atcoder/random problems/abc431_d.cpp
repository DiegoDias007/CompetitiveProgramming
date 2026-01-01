#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

const ll MINF = -1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n), h(n), b(n);
    ll w_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i] >> b[i];
        w_sum += w[i];
    }

    vector<ll> dp(w_sum + 1, MINF), dp0;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp0 = dp;
        for (int w_used = 0; w_used <= w_sum; w_used++) {
            // head
            if (w_used >= w[i]) {
                dp[w_used] = max(dp[w_used], dp0[w_used - w[i]] + h[i]); 
            }
            
            // body
            dp[w_used] = max(dp[w_used], dp0[w_used] + b[i]);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= w_sum / 2; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
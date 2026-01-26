#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll n, sx, sy, ex, ey;
    cin >> n >> sx >> sy >> ex >> ey;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        ll yi;
        cin >> yi;
        mp[a[i]].push_back(yi);
    }

    ll ans = ex - sx;
    mp[ex].push_back(ey);

    map<ll, ll> dp;
    dp[sy] = 0;
    vector<ll> prev = {sy};
    for (auto& [_, a] : mp) {
        map<ll, ll> dp0;
        sort(a.begin(), a.end());
        ll first = a.front(), second = a.back();
        dp0[first] = dp0[second] = 1e18;
        for (auto y : prev) {
            dp0[first] = min(dp0[first], dp[y] + abs(second - y) + abs(second - first));
            dp0[second] = min(dp0[second], dp[y] + abs(first - y) + abs(second - first));
        }

        dp = dp0;
        prev = {first, second};
    }
    
    ans += dp[ey];
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
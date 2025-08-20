// https://codeforces.com/contest/2061/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<map<int, pair<int, int>>> dp(n + 3);
    dp[1][1].second = 1;
    if (a[1] == 0) dp[1][0].first = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][a[i]].first = (dp[i - 1][a[i]].first + dp[i - 1][a[i]].second) % MOD;
        dp[i][a[i - 1] + 1].second = dp[i - 1][a[i - 1]].first;
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[n][i].first;
        ans += dp[n][i].second;
        ans %= MOD;
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
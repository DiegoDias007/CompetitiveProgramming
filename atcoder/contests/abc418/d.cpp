// https://atcoder.jp/contests/abc418/tasks/abc418_d

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
    string s;
    cin >> s;
    s = " " + s;

    // dp[i][j]: number of substrings ending
    // at index i where cnt[0] % 2 == j
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    ll ans = n * (n + 1) / 2;
    for (ll i = 1; i <= n; i++) {
        if (s[i] == '1') {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
        } else {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }
        ans -= dp[i][1];
    }

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
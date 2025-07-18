// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
 
#define endl '\n'
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
 
const int MOD = 1e9 + 7;
 
void init_dp(vector<int>& a, vector<vector<int>>& dp, int m) {
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<vector<int>> dp(n, vector<int>(m + 1));
    init_dp(a, dp, m);
    for (int i = 1; i < n; i++) {
        if (a[i] != 0) {
            for (int j = -1; j <= 1; j++) {
                if (a[i] + j > m) break;
                dp[i][a[i]] += dp[i - 1][a[i] + j];
                dp[i][a[i]] %= MOD;
            }
            continue;
        }
 
        for (int k = 1; k <= m; k++) {
            for (int j = -1; j <= 1; j++) {
                if (k + j > m) break;
                dp[i][k] += dp[i - 1][k + j];
                dp[i][k] %= MOD;
            }
        }
    }
 
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= MOD;
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
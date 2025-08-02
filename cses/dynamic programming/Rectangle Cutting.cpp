// https://cses.fi/problemset/task/1744

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int a, b;
    cin >> a >> b;
    
    // dp[n][m]: min number of cuts necessary to break
    // a rectangle into squares
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    for (int i = 0; i <= min(a, b); i++) dp[i][i] = 0;
    for (int n = 1; n <= a; n++) {
        for (int m = 1; m <= b; m++) {
            // row cuts
            for (int i = 1; i <= n - 1; i++) {
                dp[n][m] = min(dp[n][m], dp[i][m] + dp[n - i][m] + 1);
            }

            // column cuts
            for (int i = 1; i <= m - 1; i++) {
                dp[n][m] = min(dp[n][m], dp[n][i] + dp[n][m - i] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
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
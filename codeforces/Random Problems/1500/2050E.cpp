// https://codeforces.com/problemset/problem/2050/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size();
    a = " " + a; b = " " + b; c = " " + c; 

    // dp[i][j]: maximum number of characters we can match in c
    // using the first i characters from a and the first j
    // characters from b.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + (a[i] == c[i]);
    for (int i = 1; i <= m; i++) dp[0][i] = dp[0][i - 1] + (b[i] == c[i]);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // take char from a
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == c[i + j]));
            // take char from b
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + (b[j] == c[i + j]));
        }
    }

    int ans = n + m - dp[n][m];
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
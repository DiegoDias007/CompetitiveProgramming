// https://codeforces.com/problemset/problem/1513/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;
const int N = 2*1e5;
vector<vector<int>> dp(N + 5, vector<int>(10));

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(10);
    int ans = 0;
    while (n) {
        int d = n % 10;
        ans += dp[m][d];
        ans %= MOD;
        n /= 10;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int d = 0; d <= 9; d++) {
        dp[0][d] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int d = 0; d <= 8; d++) {
            dp[k][d] = dp[k - 1][d + 1];
        }
        dp[k][9] = dp[k - 1][0] + dp[k - 1][1];
        dp[k][9] %= MOD;
    }

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
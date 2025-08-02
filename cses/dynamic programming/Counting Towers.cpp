// https://cses.fi/problemset/task/2413/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;
const int N = 1e6;

// dp[i][0]: number of cases where two vertical extending
// dp[i][1]: number of cases where one horizontal extending
vector<vector<ll>> dp(N + 1, vector<ll>(2));

void solve() {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = 4 * dp[i - 1][0] + dp[i - 1][1];
        dp[i][0] %= MOD;
        
        dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];
        dp[i][1] %= MOD;
    }

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
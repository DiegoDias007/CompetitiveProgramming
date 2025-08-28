// https://codeforces.com/problemset/problem/1957/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int remaining = n;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        remaining -= 1 + (r != c);
    }

    // dp[i]: number of possible configurations given
    // a board of size (i x i)
    vector<ll> dp(remaining + 3);
    dp[0] = 1;
    dp[1] = 1; 
    for (int i = 2; i <= remaining; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * (i - 1 + i - 1); 
        dp[i] %= MOD;
    }
    cout << dp[remaining] << endl;
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
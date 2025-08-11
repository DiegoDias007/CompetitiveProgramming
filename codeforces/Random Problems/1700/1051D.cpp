// https://codeforces.com/contest/1051/problem/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 998244353;

void solve() {
    ll n, k;
    cin >> n >> k;

    // dp[i][mask][j] : ways to construct a (2 x i) matrix
    // where col(i) = mask and number of components = k 
    ll mx_mask = (1 << 2) - 1;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(mx_mask + 1, vector<ll>(k + 1)));
    dp[1][0][1] = 1; // all white
    dp[1][1][2] = 1; // black white
    dp[1][2][2] = 1; // white black
    dp[1][3][1] = 1; // all black 
    for (ll i = 2; i <= n; i++) {
        for (ll my_mask = 0; my_mask <= mx_mask; my_mask++) {
            for (ll prev_mask = 0; prev_mask <= mx_mask; prev_mask++) {
                ll new_components = __builtin_popcount(my_mask ^ prev_mask);
                if ((my_mask == 0 && prev_mask == 3) || (my_mask == 3 && prev_mask == 0)) new_components = 1;
                if ((prev_mask == 1 || prev_mask == 2) && (my_mask == 0 || my_mask == 3)) new_components = 0;
                for (ll prev_k = 0; prev_k <= k; prev_k++) {
                    ll new_k = prev_k + new_components;
                    if (dp[i - 1][prev_mask][prev_k] == 0 || new_k > k) continue;
                    dp[i][my_mask][new_k] += dp[i - 1][prev_mask][prev_k];
                    dp[i][my_mask][new_k] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (int mask = 0; mask <= mx_mask; mask++) {
        ans += dp[n][mask][k];
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
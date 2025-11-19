#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

int n, m, mx_mask;

vector<vector<int>> dp;

void recur(int orig_mask, int cur_mask, int r, int c) {
    if (r == n) {
        dp[c + 1][cur_mask] = (dp[c + 1][cur_mask] + dp[c][orig_mask]) % MOD;
        return;
    }

    // ja tem um tile expandindo de c - 1, nao fazer nada
    bool bit_set = orig_mask & (1 << r);
    if (bit_set) {
        recur(orig_mask, cur_mask, r + 1, c);
        return;
    }

    // tile horizontal
    int hor_mask = cur_mask | (1 << r);
    recur(orig_mask, hor_mask, r + 1, c);

    // tile vertical
    if (r < n - 1) {
        bool bit_below_set = orig_mask & (1 << (r + 1));
        if (bit_below_set) return;
        recur(orig_mask, cur_mask, r + 2, c);
    }
}

void solve() {
    cin >> n >> m;
    mx_mask = 1 << (n + 1) - 1;
    dp.resize(m + 1, vector<int>(mx_mask + 1));

    dp[0][0] = 1;
    for (int j = 0; j < m; j++) {
        for (int mask = 0; mask <= mx_mask; mask++) {
            if (dp[j][mask] > 0) {
                recur(mask, 0, 0, j);
            }
        }
    }
    cout << dp[m][0] << endl;
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
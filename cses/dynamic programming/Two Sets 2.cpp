// https://cses.fi/problemset/task/1093/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int mx_sum = (n + 1) * n / 2;
    if (mx_sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    // dp[i][s]: number of subsets with sum = s using
    // integers from 1 to i.
    vector<vector<int>> dp(n + 1, vector<int>(mx_sum + 1));
    dp[1][1] = 1; dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int s = 1; s <= mx_sum; s++) {
            if (s + i <= mx_sum) {
                dp[i][s + i] += dp[i - 1][s];
                dp[i][s + i] %= MOD;
            }
        }
    }
    cout << dp[n][mx_sum / 2] << endl;
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
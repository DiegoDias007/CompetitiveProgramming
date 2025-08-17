// https://cses.fi/problemset/task/1653/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int INF = 2e9;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx_mask = (1 << n) - 1;
    // dp[mask]: min {rides, wei_left} if we only consider
    // people in the mask 
    vector<pair<int, int>> dp(mx_mask + 1, {INF, INF});
    dp[0] = {1, 0};
    for (int mask = 0; mask <= mx_mask; mask++) {
        for (int i = 0; i < n; i++) {
            int rides = dp[mask].first;
            int wei = dp[mask].second + a[i];
            if (wei > x) {
                rides++;
                wei = a[i];
            }
            int new_mask = mask | (1 << i);
            dp[new_mask] = min(dp[new_mask], {rides, wei});
        }
    }
    cout << dp[mx_mask].first << endl;
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
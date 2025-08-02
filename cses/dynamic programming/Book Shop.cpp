// https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
 
#define endl '\n'
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
 
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
 
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 0; i < n; i++) {
        for (int p = 0; p <= x; p++) {
            int skip = dp[i][p];
            int pick = 0;
            if (p - prices[i] >= 0) {
                pick = dp[i][p - prices[i]] + pages[i];
            }
            dp[i + 1][p] = max(skip, pick);
        }
    }
    cout << dp[n][x] << endl;
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
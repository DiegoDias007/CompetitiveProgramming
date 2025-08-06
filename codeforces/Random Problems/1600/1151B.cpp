// https://codeforces.com/problemset/problem/1151/B

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j =  1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int mx_mask = (1 << 10) - 1;
    // dp[i][m]: possible to get mask = m if we take one item
    // from each row from 1, ..., i
    vector<vector<bool>> dp(n + 1, vector<bool>(mx_mask + 1));
    vector<vector<int>> path(n + 1, vector<int>(mx_mask + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int mask = 0; mask <= mx_mask; mask++) {
                if (dp[i - 1][mask]) {
                    dp[i][mask ^ a[i][j]] = true;
                    path[i][mask ^ a[i][j]] = j;
                }
            }
        }
    }

    for (int mask = 1; mask <= mx_mask; mask++) {
        if (dp[n][mask]) {
            vector<int> ans;
            int cur_mask = mask;
            for (int i = n; i >= 1; i--) {
                int cur_idx = path[i][cur_mask];
                ans.push_back(cur_idx);
                int came_from = cur_mask ^ a[i][cur_idx];
                cur_mask = came_from;
            }
            reverse(ans.begin(), ans.end());
            cout << "TAK" << endl;
            print_vec(ans);
            return;
        }
    }
    
    cout << "NIE" << endl;
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
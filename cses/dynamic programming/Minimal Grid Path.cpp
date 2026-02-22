#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n + 1, string(n + 1, 'Z'));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s = s + 'Z';
        a[i] = s;
    }
    
    string ans = "";
    ans += a[0][0];
    int mx_size = 2*n - 1;
    
    vector<pair<int, int>> dp = {{0, 0}};
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    while (ans.size() != mx_size) {
        vector<pair<int, int>> close;
        for (auto [i, j] : dp) {
            if (!vis[i+1][j]) {
                close.push_back({i + 1, j});
                vis[i+1][j] = true;
            }

            if (!vis[i][j+1]) {
                close.push_back({i, j + 1});
                vis[i][j+1] = true;
            }
        }
        
        char mn = 'Z';
        for (auto [i, j] : close) mn = min(mn, a[i][j]);

        vector<pair<int, int>> dp0;
        for (auto [i, j] : close) {
            if (a[i][j] == mn && i < n && j < n) dp0.push_back({i, j});
        }
        dp = dp0;
        ans += mn;
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
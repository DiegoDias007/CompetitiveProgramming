// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool out_of_bounds(int i, int j, int n, int m) {
    return i < 0 || j < 0 || i >= n || j >= m;
}

void dfs(int i, int j, vector<string>& a, vector<vector<bool>>& vis) {
    int n = a.size(), m = a[0].size();
    
    if (out_of_bounds(i, j, n, m) || a[i][j] == '#') return;
    
    vis[i][j] = true;
    vector<pair<int, int>> move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (auto [move_x, move_y] : move) {
        int x = i + move_x, y = j + move_y;
        if (!out_of_bounds(x, y, n, m) && vis[x][y] == false) {
            dfs(x, y, a, vis);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || a[i][j] == '#') continue;
            dfs(i, j, a, vis);
            ans++;
        }
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
#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> dxdy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> cnt(n, vector<int>(m));
    auto get_set = [&](vector<pair<int, int>> prev_set) -> vector<pair<int, int>> {
        vector<pair<int, int>> check;
        for (auto [px, py] : prev_set) {
             for (auto [dx, dy] : dxdy) {
                int x = px + dx, y = py + dy;
                if (x >= 0 && y >= 0 && x < n && y < m && a[x][y] == '.') {
                    cnt[x][y]++;
                    check.push_back({x, y});
                }
             }
        }

        vector<pair<int, int>> new_set;
        for (auto [x, y] : check) {
            if (cnt[x][y] == 1) {
                a[x][y] = '#';
                new_set.push_back({x, y});
            }
        }
        return new_set;
    };

    vector<pair<int, int>> my_set;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') my_set.push_back({i, j});
        }
    }

    while (my_set.size() > 0) {
        my_set = get_set(my_set);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += a[i][j] == '#';
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
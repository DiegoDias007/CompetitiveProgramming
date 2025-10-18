#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i]; if(i != vec.size() - 1) cout << " ";} cout << endl;}

int n, m, s;
int ans;
vector<string> a;
vector<vector<int>> vis;
vector<vector<int>> good;

void min_self(int& x, int y) {
    x = min(x, y);
}

void get_good() {
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                q.push({0, {i, j}});
                vis[i][j] = true;
            }
        }
    }


    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue;
                int nx = p.second.first + dx;
                int ny = p.second.second + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    int nd = p.first + 1;
                    q.push({nd, {nx, ny}});
                    if (a[nx][ny] == '.') {
                        min_self(dist[nx][ny], nd);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]== '.') {
                min_self(dist[i][j], i + 1);
                min_self(dist[i][j], j + 1);
                min_self(dist[i][j], n - i);
                min_self(dist[i][j], m - j);
                good[i][j] = dist[i][j] > s;
            }
        }
    }
}

void get_largest_component() {
    vis.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && good[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                int component_size = 1;
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (abs(dx) + abs(dy) != 1) continue;
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && good[nx][ny]) {
                                vis[nx][ny] = true;
                                component_size++;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                ans = max(ans, component_size);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> s;
    ans = 0;
    vis.assign(n, vector<int>(m, 0));
    good.assign(n, vector<int>(m, 0));
    a.assign(n, "");
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    get_good();    
    get_largest_component();

    cout << ans << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int cs = 1;
    while (t--) {
        cout << "Case #" << cs++ << ": ";
        solve();
    }

    return 0;
}
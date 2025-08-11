// https://cses.fi/problemset/task/1193/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool is_out_of_bounds(int i, int j, int n, int m) {
    return i < 0 || j < 0 || i >= n || j >= m;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    pair<int, int> A, B;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                A.first = i, A.second = j;
            } else if (a[i][j] == 'B') {
                B.first = i, B.second = j;
            }
        }
    }

    bool found  = false;
    vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<char> move_type = {'U', 'L', 'D', 'R'};

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    queue<pair<int, int>> q;
    q.push({A.first, A.second});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int i = cur.first, j = cur.second;
        
        if (cur == B) {
            found = true;
            break;
        }
        
        for (int idx = 0; idx < 4; idx++) {
            int dx = moves[idx].first, dy = moves[idx].second;
            int x = i + dx, y = j + dy;
            if (!is_out_of_bounds(x, y, n, m) && a[x][y] != '#' && !vis[x][y]) {
                vis[x][y] = true;
                parent[x][y] = {i, j};
                q.push({x, y});
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
        return;
    }

    string path = "";
    pair<int, int> cur = B;
    while (cur != A) {
        pair<int, int> next = parent[cur.first][cur.second];
        int dx = cur.first - next.first, dy = cur.second - next.second;
        for (int idx = 0; idx < 4; idx++) {
            if (moves[idx] == make_pair(dx, dy)) {
                path += move_type[idx];
                break;
            }
        }
        cur = next; 
    }

    reverse(path.begin(), path.end());
    
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
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
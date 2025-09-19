#include <bits/stdc++.h>
 
#define endl '\n'
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
 
const int INF = 1e9;
 
struct Point {
    int x;
    int y;
    int depth;
    string path = "";
};
 
bool out_of_bounds(int x, int y, int n, int m) {
    if (x < 0 || y < 0 || x >= n || y >= m) return true;
    return false;
}
 
void get_distances(vector<string>& a, queue<Point>& q, vector<vector<pair<int, char>>>& dist, int n, int m) {
    while (!q.empty()) {
        Point player = q.front();
        q.pop();
        for (int mov_x = -1; mov_x <= 1; mov_x++) {
            for (int mov_y = -1; mov_y <= 1; mov_y++) {
                if (abs(mov_x) + abs(mov_y) != 1) continue;
                int new_x = player.x + mov_x, new_y = player.y + mov_y;
                if (out_of_bounds(new_x, new_y, n, m) || a[new_x][new_y] == '#' || dist[new_x][new_y].first != INF) continue;
                char came_from;
                if (mov_x == 1) came_from = 'U';
                if (mov_x == -1) came_from = 'D';
                if (mov_y == 1) came_from = 'L';
                if (mov_y == -1) came_from = 'R';
                dist[new_x][new_y].first = player.depth + 1;
                dist[new_x][new_y].second = came_from;
                q.push(Point{new_x, new_y, player.depth + 1});
            }
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
 
    vector<vector<pair<int, char>>> dist_player(n, vector<pair<int, char>>(m, {INF, 'x'}));
    vector<vector<pair<int, char>>> dist_monster(n, vector<pair<int, char>>(m, {INF, 'x'}));
 
    queue<Point> qp, qm;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'M') {
                qm.push(Point{i, j, 0});
                dist_monster[i][j].first = 0;
            } else if (a[i][j] == 'A') {
                qp.push(Point{i, j, 0});
                dist_player[i][j].first = 0;
            }
        }
    }
 
    get_distances(a, qp, dist_player, n, m);
    get_distances(a, qm, dist_monster, n, m);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(i == 0 || j == 0 || i == n - 1 || j == m - 1)) continue;
            if (a[i][j] == '#') continue;
 
            if (dist_player[i][j].first < dist_monster[i][j].first) {
                cout << "YES" << endl;
                string path = "";
                int ii = i, jj = j;
                char current = dist_player[ii][jj].second;
                while (current != 'x') {
                    path += current;
                    int dx = 0, dy = 0;
                    if (current == 'U') dx = -1;
                    if (current == 'D') dx = 1;
                    if (current == 'R') dy = 1;
                    if (current == 'L') dy = -1;
                    ii += dx; jj += dy;
                    current = dist_player[ii][jj].second;
                }
                cout << path.size() << endl;
                reverse(path.begin(), path.end());
                for (int i = 0; i < path.size(); i++) {
                    if (path[i] == 'U') path[i] = 'D';
                    else if (path[i] == 'D') path[i] = 'U';
                    else if (path[i] == 'R') path[i] = 'L';
                    else if (path[i] == 'L') path[i] = 'R';
                }
                cout << path << endl;
                return;
            }
        }
    }
 
    cout << "NO" << endl;
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
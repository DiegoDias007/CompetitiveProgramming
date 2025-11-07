#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int x = n / 2, y = n / 2;
    x -= n % 2 == 0;
    y -= n % 2 == 0;

    vector<vector<int>> ans(n, vector<int>(n));
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    ans[x][y] = 0;
    int cur = 1;
    int size = 0;

    while (true) {
        for (int i = 0; i < 4; i++) {
            size += i % 2 == 0;
            for (int j = 0; j < size; j++) {
                auto [dx, dy] = d[i];
                x += dx;
                y += dy;
                assert(x >= 0 && y >= 0 && x < n && y < n);
                ans[x][y] = cur;
                cur++;
                if (cur == n * n) {
                    for (int k = 0; k < n; k++) print_vec(ans[k]);
                    return;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    int cnt_gold = 0;
    vector<vector<int>> ps(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ps[i][j] = (a[i][j] == 'g') + ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1];
            cnt_gold += a[i][j] == 'g';
        }
    }

    k--;
    int mn_gold_square = cnt_gold;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'g' || a[i][j] == '#') continue;
            int r1 = i - k, c1 = j - k;
            int r2 = i + k, c2 = j + k;
            r1 = max(r1, 1), c1 = max(c1, 1);
            r2 = min(r2, n), c2 = min(c2, m);
            int gold_square = ps[r2][c2] - ps[r2][c1 - 1] - ps[r1 - 1][c2] + ps[r1 - 1][c1 - 1];
            mn_gold_square = min(mn_gold_square, gold_square);
        }
    }
    int ans = cnt_gold - mn_gold_square;
    cout << ans << endl;
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
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
    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;
    int cnt_mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    
    vector<int> cnt_row(n), cnt_col(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == mx) {
                cnt_mx++;
                cnt_row[i]++;
                cnt_col[j]++;
            }
        }
    }

    bool possible = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur_cnt = cnt_row[i] + cnt_col[j] - (a[i][j] == mx);
            if (cur_cnt > 0) {
                possible |= cur_cnt == cnt_mx;
            }
        }
    }

    if (possible) {
        cout << mx -1 << endl;
    } else {
        cout << mx << endl;
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
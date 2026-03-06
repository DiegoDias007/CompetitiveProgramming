#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

int calc_time(int c, int s) {
    if (c == 0) return 0;
    int t_gen = max(0, c - s - 1);
    int t_move = c;
    return t_gen + t_move;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int c1 = k - 1;
    int c2 = n - k;

    int ans = 1;
    auto solve_side = [&](int c1, int c2) {
        for (int i = 0; i <= c1; i++) {
            int t1 = calc_time(i, 0);
            if (t1 > m) break;
            int t_rem = m - t1;
            int j = 0;
            int l = 0, r = c2;
            while (l <= r) {
                int mid = (l + r) / 2;
                int t2 = calc_time(mid, max(0, i-1));
                bool ok = t2 <= t_rem;
                if (ok) {
                    j = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, i + j + 1);
        }
    };

    solve_side(c1, c2);
    solve_side(c2, c1);
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